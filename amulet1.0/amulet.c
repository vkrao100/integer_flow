/*------------------------------------------------------------------------*/
/* Copyright (C) 2019, Daniela Kaufmann, Johannes Kepler University Linz */
/*------------------------------------------------------------------------*/
// TODO verbose

#define VERSION "000"

static const char * USAGE =
"\n"
"### USAGE ###\n"
"usage : amulet <modus> <input.aig> <output files> [<option> ...] \n"
"\n"
"Depending on the <modus> the <output files> and <options> have to be set accordingly:"
"\n"
"\n"
"<modus> = -substitute:\n"
"    <output files> =  2 output files need to be passed in the following order \n"
"      <out.cnf>:        miter for checking the equivalence of the substituted adder \n"
"      <out.aig>:        rewritten aiger is stored in this file \n"
"\n"
"    <option> = the following options are available \n"
"      -h | --help       print this command line summary \n"
"      -v<1,2,3,4>       different levels of verbosity (see below) \n"
"      -2comp            option for non-negative integer multipliers \n"
"\n"
"\n"
"<modus> = -verify:\n"
"    <output files> =  no output files are required \n"
"     \n "
"    <option> = the following options are available \n"
"       -h | --help      print this command line summary \n"
"       -v<1,2,3,4>      different levels of verbosity (see below) \n"
"       -2comp           option for non-negative integer multipliers \n"
"       -no-mod          use ring Z[X] instead of Z_m[X] \n"
"       -no-elim         turn off variable elimination \n"
"       -non-inc         use non-incremental specification \n"
"     \n"
"     \n"
"<modus> = -certify:\n"
"    <output files> =  3 output files need to be passed in the following order\n"
"      <out.polys>:      initial polynomial set \n"
"      <out.pac>  :      proof rules \n"
"      <out.spec> :      spec which should be checked \n"
"     \n "
"    <option> = the following options are available \n"
"       -h | --help      print this command line summary \n"
"       -v<1,2,3,4>      different levels of verbosity (see below) \n"
"       -2comp           option for non-negative integer multipliers \n"
"       -no-mod          use ring Z[X] instead of Z_m[X] \n"
"       -no-elim         turn off variable elimination \n"
"       -non-inc         use non-incremental specification \n"
"     \n"
"     \n"

"### Verbosity ###\n"
"AMulet has 4 different verbosity levels, which can be activated as <option> \n"
"     -v1, -v2, -v3 or -v4 \n"
"      \n"
"      \n"
"For modus -substitute the verbosity output is the following:\n"
"  -v1                     verbose level 1: \n"
"                            * identified propagate and generate nodes\n"
"                            * identified carry in and carry out\n"
"                            * listing adder miter generation steps\n"
"  -v2                     verbose level 2 (incl. verbose level 1):\n"
"                            * followed paths for marking\n"
"                            * header of cnf miter\n"
"  -v3                     verbose level 3 (incl. verbose level 2):\n"
"                            * monitoring adder miter generation\n"
"  -v4                     verbose level 4 (incl. verbose level 3):\n"
"                            * list of input variables  and their parents \n"
"                            * level of variables  \n"
"      \n"

"For modus -verify and -certify the verbosity output is the following:\n"
"  -v1                     verbose level 1: \n"
"                            * input order\n"
"                            * maximum level\n"
"                            * partial products\n"
"                            * reduction result after reducing a slice\n"
"  -v2                     verbose level 2 (incl. verbose level 1):\n"
"                            * list merged and promoted gates\n"
"                            * list of decomposed and eliminated variables\n"
"                            * list of polynomials after decomposing and elimination\n"
"  -v3                     verbose level 3 (incl. verbose level 2):\n"
"                            * monitoring the reduction process\n"
"  -v4                     verbose level 4 (incl. verbose level 3):\n"
"                            * list of variables  and their parents \n"
"                            * level of variables  \n"
"                            * list of found booth pattern\n"

;
/*------------------------------------------------------------------------*/
#define _GNU_SOURCE

#include "includes/aiger.h"
#include <gmp.h>

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
#include <math.h>

/*------------------------------------------------------------------------*/
// internal variables
static unsigned M, NN, N; //max variable in aiger / #inputs / n
static int a0, al, ainc;  // smallest / largest / distance between A
static int b0, bl, binc;  // smallest / largest / distance between B
static int s0, sl, sinc;  // smallest / largest / distance between S

static int maxlevel;      // maximum level of slice
static int truncated = 0; // did we find truncated multiplier
static int booth;         // do we expect multiplier to be booth
static int ha_num = 0;
static unsigned pp;       //number of pp in aig
static unsigned max_count = 0;
static unsigned max_idx = 0;
static int restart = 0;
static int tc = 0;
mpz_t mod_coeff;
/*------------------------------------------------------------------------*/
// standard options
static int modus = 0;
static int incremental = 1;     // incremental specification
static int modulo = 1;
static int elim = 1;
static int elim_print = 0;
static int pac = 0;
static int verbose = 0;         // the outputlevel of verbose

static const char * input_name = 0;
static const char * output_name = 0;
static const char * output_name2 = 0;
static const char * output_name3 = 0;


static FILE * output_file; // either .cnf in -substitute   or .polys in -certify
static FILE * output_file2; //aither .aig in -substitute   or .pac in -certify
static FILE * output_file3; //.spec in -certify

/*------------------------------------------------------------------------*/

// error message to stderr
static void die (const char *fmt, ...) {
  fflush (stdout);
  va_list ap;
  fputs_unlocked("*** [amulet] ", stderr);
  va_start (ap, fmt);
  vfprintf (stderr, fmt, ap);
  va_end (ap);
  fputc ('\n', stderr);
  fflush (stderr);
  exit (1);
}

// standard message to stdout
static void msg (const char *fmt, ...) {
  va_list ap;
  fputs_unlocked ("[amulet] ", stdout);
  va_start (ap, fmt);
  vfprintf (stdout, fmt, ap);
  va_end (ap);
  fputc_unlocked ('\n', stdout);
  fflush (stdout);
}

// standard message to stdout without starting a new line
static void msg_no_nl (const char *fmt, ...) {
  va_list ap;
  fputs_unlocked ("[amulet] ", stdout);
  va_start (ap, fmt);
  vfprintf (stdout, fmt, ap);
  va_end (ap);
  fflush (stdout);
}

// banner at begining of stdout
static void banner () {
  msg ("AMulet Version " VERSION);
  msg ("Aiger multiplier examination tool");
  msg ("Copyright (C) 2019, Daniela Kaufmann, Johannes Kepler University Linz");
}

/*------------------------------------------------------------------------*/

// Random odd 64 numbers for constructing hash functions.
static uint64_t nonces[32];
static const size_t num_nonces = sizeof nonces / sizeof nonces[0];

// generate 16 bit random number
static uint16_t rand16 () {
  int tmp = rand ();
  assert (tmp >= 0);
  uint16_t res = tmp ^ (tmp >> 16);
  return res;
}

// generate 64 bit random number
static uint64_t rand64 () {
  uint64_t res = 0;
  for (unsigned i = 0; i < 64; i += 16)
    res |= rand16 () << i;
  return res;
}

// generate 32 bit array filled with 64 bit numbers
static void init_nonces () {
  srand (42);
  for (size_t i = 0; i < num_nonces; i++)
    nonces[i] = rand64 () | 1;
}

// compute hash value for string
static uint64_t hash_string (char * str) {
  uint64_t res = 0;
  size_t i = 0;
  for (char * p = str; *p; p++) {
    res += *p;
    res *= nonces[i++];
    if (i == num_nonces) i = 0;
  }
  return res;
}

/*------------------------------------------------------------------------*/

// memory management routines maintaining a count of allocated memory

static size_t current_allocated_bytes;
static size_t max_allocated_bytes;

// increase variable which stores allocated bytes
static void inc_allocated_bytes (size_t bytes) {
  current_allocated_bytes += bytes;
  if (current_allocated_bytes > max_allocated_bytes)
    max_allocated_bytes = current_allocated_bytes;
}

// decrease the number of current allocated bytes
static void dec_allocated_bytes (size_t bytes) {
  assert (current_allocated_bytes >= bytes);
  current_allocated_bytes -= bytes;
}

// allocate memory block
static void * allocate_block (size_t times, size_t bytes) {
  if (!bytes) return 0;
  void * res = calloc (times, bytes);
  if (bytes) {
    if (res) memset (res, 0, bytes);
    else die ("out-of-memory allocating %zu bytes", bytes);
  }
  inc_allocated_bytes (times*bytes);
  return res;
}

// allocate memory
static void * allocate (size_t bytes) {
  if (!bytes) return 0;
  void * res = malloc (bytes);
  if (bytes) {
    if (res) memset (res, 0, bytes);
    else die ("out-of-memory allocating %zu bytes", bytes);
  }
  inc_allocated_bytes (bytes);
  return res;
}

// deallocate memory
static void deallocate (void * ptr, size_t bytes) {
  dec_allocated_bytes (bytes);
  free (ptr);
}

static void * reallocate (void * ptr, size_t old_bytes, size_t new_bytes) {
  dec_allocated_bytes (old_bytes);
  void * res = realloc (ptr, new_bytes);
  if (res) {
    if (new_bytes > old_bytes)
      memset (res + old_bytes, 0, new_bytes - old_bytes);
  } else die ("out-of-memory reallocating %zu bytes", new_bytes);
  inc_allocated_bytes (new_bytes);
  return res;
}
/*------------------------------------------------------------------------*/

// 'polymorphic' array management routine maintain a count of allocated memory

#define ALLOCATE(P,N) \
do { \
  size_t BYTES = (N) * sizeof *(P); \
  (P) = allocate (BYTES); \
} while (0)

#define DEALLOCATE(P,N) \
do { \
  size_t BYTES = (N) * sizeof *(P); \
  deallocate ((P), BYTES); \
} while (0)

#define REALLOCATE(P,O,N) \
do { \
  size_t OLD_BYTES = (O) * sizeof *(P); \
  size_t NEW_BYTES = (N) * sizeof *(P); \
  (P) = reallocate ((P), OLD_BYTES, NEW_BYTES); \
} while (0)
/*------------------------------------------------------------------------*/
// Statistics for max used memory and used process time

// determine max used memory
static size_t maximum_resident_set_size () {
  struct rusage u;
  if (getrusage (RUSAGE_SELF, &u)) return 0;
  return ((size_t) u.ru_maxrss) << 10;
}

// get process time
static double process_time () {
  struct rusage u;
  if (getrusage (RUSAGE_SELF, &u)) return 0;
  double res = u.ru_utime.tv_sec + 1e-6 * u.ru_utime.tv_usec;
  res += u.ru_stime.tv_sec + 1e-6 * u.ru_stime.tv_usec;
  return res;
}

// print statistics of maximum memory and used process time
// print used memory and time
static void print_statistics (double slicing, double decomp, double elimt, double red) {
  msg ("");

  msg ("maximum polynomial size is:               %12i monomials", max_count);
  msg ("maximum resident set size:                %12.2f MB",
    maximum_resident_set_size () / (double)(1<<20));
  msg ("used time for reading/slicing/ordering:   %12.2f seconds",
    slicing);
  if(elim) msg ("used time for decomposition:              %12.2f seconds",
    decomp);
  if(elim) msg ("used time for elimination:                %12.2f seconds",
    elimt);
  msg ("used time for reduction:                  %12.2f seconds",
    red);
  msg ("used process time:                        %12.2f seconds",
    process_time ());
}
/*------------------------------------------------------------------------*/
// Signal handlers

// define error signals
static const char * signal_name (int sig) {
  switch (sig) {
    case SIGINT: return "SIGINT";
    case SIGSEGV: return "SIGSEGV";
    case SIGABRT: return "SIGABRT";
    case SIGTERM: return "SIGTERM";
    default: return "SIGUNKNOWN";
  }
}

static void (*original_SIGINT_handler)(int);
static void (*original_SIGSEGV_handler)(int);
static void (*original_SIGABRT_handler)(int);
static void (*original_SIGTERM_handler)(int);

// reset all signal handlers
void reset_all_signal_handlers () {
  (void) signal (SIGINT, original_SIGINT_handler);
  (void) signal (SIGSEGV, original_SIGSEGV_handler);
  (void) signal (SIGABRT, original_SIGABRT_handler);
  (void) signal (SIGTERM, original_SIGTERM_handler);
}

// catch signal and print message
static void catch_signal (int sig) {
  printf ("c\nc caught signal '%s' (%d)\nc\n", signal_name (sig), sig);
  printf ("c\nc raising signal '%s' (%d) again\n", signal_name (sig), sig);
  reset_all_signal_handlers ();
  fflush (stdout);
  raise (sig);
}

// Initialize all signal handlers
void init_all_signal_handers () {
  original_SIGINT_handler = signal (SIGINT, catch_signal);
  original_SIGSEGV_handler = signal (SIGSEGV, catch_signal);
  original_SIGABRT_handler = signal (SIGABRT, catch_signal);
  original_SIGTERM_handler = signal (SIGTERM, catch_signal);
}
/*------------------------------------------------------------------------*/
// AIGER methods
static aiger * model, * rewritten, * miter;   // aiger model - calls aiger.h

static unsigned not (unsigned a) { return a^1; }

static unsigned and (unsigned a, unsigned b) {
  unsigned res;
  if (!a || !b || a == not (b)) return 0;
  if (a == 1 || a == b) return b;
  if (b == 1) return a;
  res = 2*(miter->maxvar + 1);
  assert (a < res), assert (b < res);
  aiger_add_and (miter, res, a, b);
  return res;
}

static unsigned implies (unsigned a, unsigned b) {
  return not (and (a, not (b)));
}
static unsigned xnor (unsigned a, unsigned b) {
  return and (implies (a, b), implies (b, a));
}
/*------------------------------------------------------------------------*/
static void read_aiger(const char * input_name){
  model = aiger_init ();

  msg ("reading '%s'", input_name);
  const char * err = aiger_open_and_read_from_file (model, input_name);
  if (err) die ("error parsing '%s': %s", input_name, err);
}

// check if aiger model fits our purpose
static void init_aiger_with_checks(){
  if (model->num_latches) die ("can not handle latches");
  if (!model->num_inputs) die ("no inputs");
  if ((model->num_inputs & 1)) die ("odd number of inputs");
  if (!model->num_outputs) die ("no outputs");
  if (2*model->num_outputs == model->num_inputs){
    if(tc) die("truncated and two's complement does not work");

    msg("found truncated multiplier: N * N = N");
    M = model->maxvar + 1;
    NN = model->num_outputs;
    N = NN;
    truncated = 1;
  }
  else if (model->num_outputs == model->num_inputs){
    msg("found regular multiplier: N * N = 2N");
    M = model->maxvar + 1;
    NN = model->num_outputs;
    N = NN/2;
  }
  else  die ("expected %u but got %u outputs",
      model->num_inputs, model->num_outputs);


  for (unsigned i = 0; i < M; i++) {
    aiger_and * and = aiger_is_and (model, 2*i);
    if (!and) continue;
    if (aiger_lit2var (and->rhs0) >= i || aiger_lit2var (and->rhs1) >= i)
      die ("only binary or sorted AIGER models supported");
  }

  msg ("MILOA %u %u %u %u %u",
    model->maxvar,
    model->num_inputs,
    model->num_latches,
    model->num_outputs,
    model->num_ands);

  max_idx = 2*model->maxvar+2;
}

static void init_mod_coeff(){
  unsigned exp = NN;
  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base, 2);
  mpz_pow_ui(mod_coeff, base, exp);
  mpz_clear(base);
}

// check if lhs is conjunction of rhs0 and rhs1
static int match_and (unsigned lhs, unsigned rhs0, unsigned rhs1) {
  if (lhs == aiger_false) return 0;
  if (aiger_sign (lhs)) return 0;
  assert (lhs != aiger_true);
  aiger_and * and = aiger_is_and (model, lhs);
  if (!and) return 0;
  if (and->rhs0 == rhs0 && and->rhs1 == rhs1) return 1;
  if (and->rhs0 == rhs1 && and->rhs1 == rhs0) return 1;
  return 0;
}



// returns input number of a
static unsigned alit (unsigned i) {
  assert (i < N);
  return model->inputs[a0 + i*ainc].lit;
}

// returns input number of b
static unsigned blit (unsigned i) {
  assert (i < N);
  return model->inputs[b0 + i*binc].lit;
}

// returns output number of s
static unsigned slit (unsigned i) {
  assert (i < NN);
  return model->outputs[s0 + i*sinc].lit;
}

//returns if variable is output
static int is_output(unsigned lit){
  for(unsigned i = 0; i<NN; i++){
    unsigned comp = aiger_strip(model->outputs[s0 + i*sinc].lit);
    if (comp == lit) return i;
  }
  return -1;
}


// according to input order we define if btor or aiko ordering is used
static void determine_input_order(){
  if (match_and (
        model->outputs[0].lit,
        model->inputs[0].lit,
        model->inputs[1].lit)) {
    a0 = 0, al = 2*N-2, ainc = 2;
    b0 = 1, bl = 2*N-1, binc = 2;
    s0 = 0, sl = NN-1,   sinc = 1;
    msg ("assuming ordering as in BTOR generated benchmarks");
  } else {
    a0 = 0, al = N-1,   ainc = 1;
    b0 = N, bl = 2*N-1, binc = 1;
    s0 = 0, sl = NN-1,   sinc = 1;
    msg ("assuming ordering as in the ABC generated or AOKI benchmarks");
  }
  if (verbose >= 1){
    if (N == 1) {
      msg ("a[0] = input[%d]", a0);
      msg ("b[0] = input[%d]", b0);
      msg ("s[0] = output[%d]", s0);
    } else if (N == 2) {
      msg ("(a[0], a[1]) = (input[%d], input[%d])", a0, al);
      msg ("(b[0], b[1]) = (input[%d], input[%d])", b0, bl);
      msg ("(s[0], ..., s[3]) = (output[%d], ..., output[%d])", s0, sl);
    } else if (N == 3) {
      msg ("(a[0], a[1], a[2]) = (input[%d], input[%d], input[%d])",
        a0, a0 + ainc, al);
      msg ("(b[0], b[1], b[2]) = (input[%d], input[%d], input[%d])",
        b0, b0 + binc, bl);
      msg ("(s[0], ..., s[5]) = (output[%d], ..., output[%d])", s0, sl);
    } else {
      msg ("(a[0], a[1], ..., a[%d]) = (input[%d], input[%d], ..., input[%d])",
        N-1, a0, a0 + ainc, al);
      msg ("(b[0], b[1], ..., b[%d]) = (input[%d], input[%d], ..., input[%d])",
        N-1, b0, b0 + binc, bl);
      msg ("(s[0], ..., s[%d]) = (output[%d], ..., output[%d])",
        NN-1, s0, sl);
    }
  }
}

/*------------------------------------------------------------------------*/
// For each variable, the corresponding parents in the AIG are stored
typedef struct Parent Parent;
struct Parent{
  int pval;
  Parent * rest;
};

//init parent
static Parent * new_parent (int i, Parent * rest){
  Parent * p = allocate(sizeof * p);
  p->pval = i;
  p->rest = rest;
  return p;
}

// deallocate parent
static void deallocate_parent (Parent * p) {
  while (p){
    Parent * rest = p->rest;
    deallocate (p, sizeof *p);
    p = rest;
  }
}


//add parent
static Parent * add_parent(Parent * p, int i){
  Parent * tmp = p;
  while (tmp){
    if (tmp->pval == i) return p;
    tmp = tmp->rest;
  }

  return new_parent(i, p);
}


static int is_parent(int lit, Parent * p){
  Parent * tmp = p;
  while (tmp){
    if (lit == tmp->pval) return 1;
    tmp = tmp->rest;
  }
  return 0;
}

//print parent list
static void print_parent (Parent * p){
  while(p){
    fprintf(stdout, "%i ", p->pval);
    p = p->rest;
  }
}

//add parent
static Parent * remove_parent(Parent * p, int i){
  Parent * tmp = p;
  Parent * res = 0;
  while (tmp){
    if (tmp->pval != i) res = add_parent(res, tmp->pval);

    tmp = tmp->rest;
  }

  deallocate_parent(p);

  return res;
}


/*------------------------------------------------------------------------*/
typedef struct Var Var;
struct Var {
  int aiger;  // consecutive number as in aig
  char * name;     // either a%i, b%i or l%i
  uint64_t hash;   // saved hash value
  Parent * parent; // define parents

  int slice;       // defines the slice where belongs to
  int occs;        // counts the number of parents
  int level;       // defines distance to input

  int input;       // 1 if belongs to input A, 2 if belongs to input B
  int output;      // 1 if is output
  int carry;       // 1 if it is a carry

  int xor;         // 1 if head of xor, 2 if xor child
  int haxor;
  int haand;
  int hainp;

  int bo;	   // 1 if it was eliminated during booth recoding
  int cl;	   // 1 if it seems to be cl adder
  int pp;          // determines if pp
  int neg;         // determines if Var is negation

  int elim;        // define if it is already considered to be eliminated
  int rewrite;        // define if it is already considered to be rewriteinated
};

static Var * vars;
static int num_vars;

//allocate variables
static void allocate_variables(){
  num_vars = M + NN;
  vars = allocate_block (2*M, sizeof *vars);
  if (!vars) die ("failed to allocate vars");

  for(unsigned i = 1; i < 2*M; i++){
    Var * v = vars + i;
    v->aiger = 2*i;
    v->name  = "0";
    v->parent = 0;

    v->slice = -1;
    v->occs  = 0;
    v->level = -1;

    v->input = 0;
    v->output = 0;
    v->carry = 0;

    v->xor = 0;
    v->bo = 0;
    v->cl = 0;
    v->pp = 0;
    v->neg = 0;

    v->elim = 0;

    v->haxor = 0;
    v->haand = 0;
    v->hainp = 0;

    v->rewrite = 0;
  }
}


//return pointer to variable
Var * var(int lit){
  assert (lit < 2*(int)M);
  if(lit > 0) return vars + lit/2;
  else return vars + M - lit;
}


//name all variables
// inputvector 1: a0, a1,...
// inputvector 2: b0, b1,...
// remaining variables: l4, l6, etc.


static void set_name_input_and_output(){
  char buffer[80];
  for (unsigned i = 0; i < N; i++) {
    Var * v = var (alit(i));
    assert (aiger_is_input (model, v->aiger));
    sprintf (buffer, "a%d", i);
    v->name = strdup (buffer);
    v->input = 1;
    v->output = is_output(2*i);
    v->hash = hash_string (v->name);
  }

  for (unsigned i = 0; i < N; i++) {
    Var * v = var (blit(i));
    assert (aiger_is_input (model, v->aiger));
    sprintf (buffer, "b%d", i);
    v->name = strdup (buffer);
    v->input = 2;
    v->output = is_output(2*i);
    v->hash = hash_string (v->name);
  }

  for (unsigned i = 1; i < M; i++) {
    Var * v = var (2*i);
    if (v->input > 0) continue;
    assert (aiger_is_and (model, v->aiger));
    sprintf (buffer, "l%d", 2*i);
    v->name = strdup (buffer);
    v->output = is_output(2*i);
    v->hash = hash_string (v->name);

  }

  for (unsigned i = 0; i < NN; i++){
    Var * v = vars + M + i;
    sprintf (buffer, "s%d", i);
    v->aiger = -i;
    v->name = strdup (buffer);
    v->output = NN + 1;
    v->slice = i;
    v->level = INT_MAX;
    v->occs = 1;
    v->hash = hash_string (v->name);
  }

}


// for each variable set the corresponding parents and
// adapt occs
static void set_parents(){
  for (unsigned i = 1; i < M; i++) {
    Var * v = var (2*i);

    if (v->input > 0) continue;
    assert (aiger_is_and (model, v->aiger));
    aiger_and * and = aiger_is_and (model, v->aiger);
    unsigned rhs0 = and->rhs0;
    unsigned rhs1 = and->rhs1;
    Var * v0 = var (rhs0);
    Var * v1 = var (rhs1);
    v0->parent = add_parent(v0->parent, v->aiger);
    v0->occs++;
    v1->parent = add_parent(v1->parent, v->aiger);
    v1->occs++;
    if (v0->input && v1->input) {
      v->pp = 1;
      pp++;
    }
  }

  for (unsigned i = 0; i < NN; i++) {
    unsigned u = aiger_strip(slit(i));
    Var * v = var (u);
    v->occs++;
    v->parent = add_parent(v->parent, -i);
  }

  if(verbose >= 4){
    for (unsigned i = 1; i < M; i++) {
      Var * v = var (2*i);
      msg_no_nl("variable %s occurs %i and has parents: ", v->name, v->occs);
      print_parent(v->parent);
      fprintf(stdout, "\n");
    }
  }
}


// set if node is an xor gate
static void set_xor () {
  for (unsigned i = 1; i < M; i++) {
    Var * v = var (2*i);
    if (v->input > 0) continue;
    if (v->xor > 0) continue;

    aiger_and * and = aiger_is_and(model, v->aiger);
    if(!and) continue;
    unsigned l = and->rhs0, r = and->rhs1;
    if (!aiger_sign (l)) continue;
    if (!aiger_sign (r)) continue;
    l = aiger_strip (l);
    r = aiger_strip (r);
    if (l == r || l == aiger_not (r)) continue;
    aiger_and * land = aiger_is_and (model, l);
    if (!land) continue;
    aiger_and * rand = aiger_is_and (model, r);
    if (!rand) continue;

    unsigned ll = land->rhs0, lr = land->rhs1;
    unsigned rl = rand->rhs0, rr = rand->rhs1;
    if (ll == aiger_not (rl) && lr == aiger_not(rr)) {
      var(l)->xor = 2;
      var(r)->xor = 2;
      v->xor = 1;
    } else if (ll == aiger_not (rr) && lr == aiger_not(rl)) {
      var(l)->xor = 2;
      var(r)->xor = 2;
      v->xor = 1;
    } else continue;
  }
}


// set if node is an xor gate
static Var * xor_left_child (Var * v) {
  if (!v->xor ) return 0;

  aiger_and * and = aiger_is_and(model, v->aiger);
  if(!and) return 0;
  unsigned l = and->rhs0;
  if (!aiger_sign (l)) return 0;
  l = aiger_strip (l);

  aiger_and * land = aiger_is_and (model, l);
  if (!land) return 0;

  unsigned ll = land->rhs0;
  return var(ll);
}


// set if node is an xor gate
static Var * xor_right_child (Var * v) {
  if (!v->xor ) return 0;

  aiger_and * and = aiger_is_and(model, v->aiger);
  if(!and) return 0;
  unsigned l = and->rhs0;
  if (!aiger_sign (l)) return 0;
  l = aiger_strip (l);

  aiger_and * land = aiger_is_and (model, l);
  if (!land) return 0;

  unsigned lr = land->rhs1;
  return var(lr);
}

static void set_ha(){
  for (unsigned i = 1; i < M; i++) {
    Var * v = vars + i;
    if(v->xor != 1) continue;

    Var * l = xor_left_child(v);
    Var * r = xor_right_child(v);
    if(l->occs < 3 || r->occs < 3) continue;

    if(l->occs != 3 && r->occs != 3) continue;
    Parent * p;
    if(l->occs == 3){
      int found = 0;
      p = l->parent;
      while(var(p->pval)->xor == 2){
        p = p->rest;
      }
      assert(p);

      Parent * q = r->parent;
      while(q){
        if(p->pval == q->pval) found = 1;
        q = q->rest;
      }
      if(!found) continue;
    } else if (r->occs == 3){
      int found = 0;
      p = r->parent;
      while(var(p->pval)->xor == 2){
        p = p->rest;
      }
      assert(p);

      Parent * q = l->parent;
      while(q){
        if(p->pval == q->pval) found = 1;
        q = q->rest;
      }
      if(!found) continue;
    }

    v->haxor = ++ha_num;
    var(p->pval)->haand = ha_num;
    l->hainp = ha_num;
    r->hainp = ha_num;
    //msg("found ha%i %s %s with children %s %s", ha_num, var(p->pval)->name, v->name, l->name, r->name);


  }
}


// set the level of each node
static void set_level(){
  for (unsigned i = 0; i < N; i++) {
    Var * v = var (alit(i));
    assert (aiger_is_input (model, v->aiger));
    v->level = 0;
  }

  for (unsigned i = 0; i < N; i++) {
    Var * v = var (blit(i));
    assert (aiger_is_input (model, v->aiger));
    v->level = 0;
  }

  int change = 1;

  while(change){
    change = 0;

    for (unsigned i = 1; i < M; i++) {
      Var * v = var (2*i);
      if (v->level > -1) continue;
      assert (aiger_is_and (model, v->aiger));
      aiger_and * and = aiger_is_and (model, v->aiger);
      unsigned rhs0 = and->rhs0;
      unsigned rhs1 = and->rhs1;
      Var * v0 = var (rhs0);
      Var * v1 = var (rhs1);
      if (v0->level == -1 || v1->level == -1) continue;

      v->level =  v0->level > v1->level ? v0->level+1 : v1->level+1;
      maxlevel =  v->level > maxlevel ? v->level : maxlevel;
      change = 1;

    }
  }

  if(verbose >=4){
    for (unsigned i = 1; i < M; i++) {
      Var * v = var (2*i);
      msg("variable %s has level %i", v->name, v->level);
    }
  }
  if(verbose >= 1) msg("maximum level of variables is %i", maxlevel);
}


// allocate variables and do the following things:
// * naming
// * check if gate is an xor gate
// * set the parents
// * set the input distance
static void init_variables(unsigned init){
  allocate_variables();

  set_name_input_and_output();
  set_xor();
  set_parents();
  if(init) set_ha();
  set_level();

  if(verbose >= 1) msg("found %i partial products", pp);
  if (pp == N*N || (pp == (1+N)*N/2 && truncated)){
    msg("assuming simple pp generator");
  } else {
    msg("assuming booth recoding");
    booth = 1;
  }
}


// print a variable
static void print_variable (Var * v, FILE * file) {
  fputs_unlocked(v->name, file);
}

static int no_of_parents(Var * v){
 int num = 0;
 Parent * p = v->parent;

 while(p){
  num++;
  p = p->rest;
 }

 return num;
}

static void deallocate_vars(){
  for (int i = 0; i < num_vars; i++) {
    Var * v = vars + i;
    if (v->name) free (v->name);
    deallocate_parent(v->parent);
  }
  deallocate(vars, (2*M) * (sizeof *vars));
}
/*------------------------------------------------------------------------*/
// define output cones
static void input_cone(unsigned lit, int num){
    assert(num >= 0);
    if (lit == aiger_false) return;
    if (lit == aiger_true) return;

    lit = aiger_strip (lit);
    Var * v = var(lit);

    if (v->input > 0) return;
    if (v->slice >= 0) return;

    assert (v->slice < 0);
    assert (aiger_is_and (model, lit));

    v->slice = num;

    aiger_and * and = aiger_is_and (model, lit);

    unsigned rhs0 = and->rhs0;
    unsigned rhs1 = and->rhs1;

    input_cone (rhs1, num);
    input_cone (rhs0, num);
}

/*****************************************************************************/
static Var * adder_carry_out;
//TODO: dynamically enlarge these
//static unsigned seen[1000];
//static unsigned seen_num = 0;
static unsigned size_pg;
static unsigned pg_num = 0;
static unsigned * pg;

static unsigned size_cin;
static unsigned cin_num = 0;
static unsigned * cin;

static unsigned size_inputs;
static unsigned inputs_num = 0;
static unsigned * inputs;

static unsigned size_seen;
static unsigned seen_num = 0;
static unsigned * seen;

static unsigned size_o1;
static unsigned o1_count = 0;
static unsigned * o1;

static unsigned size_o2;
static unsigned o2_count = 0;
static unsigned * o2;


static unsigned c_in;


static void enlarge_o1 () {
  size_t new_size_o1 = size_o1 ? 2*size_o1 : 1;
  REALLOCATE (o1, size_o1, new_size_o1);
  size_o1 = new_size_o1;
}
static void deallocate_o1 () { DEALLOCATE (o1, size_o1); }

static void enlarge_o2 () {
  size_t new_size_o2 = size_o2 ? 2*size_o2 : 1;
  REALLOCATE (o2, size_o2, new_size_o2);
  size_o2 = new_size_o2;
}
static void deallocate_o2 () { DEALLOCATE (o2, size_o2); }

// make buffer bigger
static void enlarge_seen () {
  size_t new_size_seen = size_seen ? 2*size_seen : 1;
  REALLOCATE (seen, size_seen, new_size_seen);
  size_seen = new_size_seen;
}
static void deallocate_seen () { DEALLOCATE (seen, size_seen); }

static void enlarge_inputs () {
  size_t new_size_inputs = size_inputs ? 2*size_inputs : 1;
  REALLOCATE (inputs, size_inputs, new_size_inputs);
  size_inputs = new_size_inputs;
}
static void deallocate_inputs () { DEALLOCATE (inputs, size_inputs); }

static void enlarge_cin () {
  size_t new_size_cin = size_cin ? 2*size_cin : 1;
  REALLOCATE (cin, size_cin, new_size_cin);
  size_cin = new_size_cin;
}
static void deallocate_cin () { DEALLOCATE (cin, size_cin); }



static void enlarge_pg () {
  size_t new_size_pg = size_pg ? 2*size_pg : 1;
  REALLOCATE (pg, size_pg, new_size_pg);
  size_pg = new_size_pg;
}

static void deallocate_pg () { DEALLOCATE (pg, size_pg); }


static void declare_carry_out_of_adder(){
  for (unsigned i = 1; i < M; i++){
    Var * v = vars + i;
    int cmp = 2*N-1;
    if( v->output !=  cmp) continue;
    if(v->xor){
      Var * l = xor_left_child(v);
      Var * r = xor_right_child(v);
      if(l->xor || l->haand) adder_carry_out = r;
      else adder_carry_out = l;
    }
    else adder_carry_out = v;
    if(verbose >= 1)  msg("found adder carry out %s", adder_carry_out->name);
    break;
  }
}

static int declare_possible_P_and_cin(){
  for (unsigned i = M-1; i > 0; i--){
    Var * v = vars + i;
    int cmp = 2*N-1;
    if(v->output >  cmp || v->output <  0) continue;
    if(!v->xor) continue;
    Var * l = xor_left_child(v);
    Var * r = xor_right_child(v);
    Var * xor = l->xor ? l : r;
    if(v->output ==  cmp-1 && xor->haxor == -1) return 0;
    //if(xor->haxor < 1) continue;
    if(xor->occs < 4 && v->slice < cmp-1) continue;
    if(xor->occs < 3) continue;
    if (size_pg == pg_num) enlarge_pg ();
    pg[pg_num++] = xor->aiger;
    if(verbose >= 1)  msg("found propagate node %i", pg[pg_num-1]);

    for(unsigned j = M-1; j>0; j--){
      Var * w = vars + j;
      if(w->haand == xor->haxor){
        if (size_pg == pg_num) enlarge_pg ();
        pg[pg_num++] = w->aiger;
        if(verbose >= 1) msg("found generate node %i", pg[pg_num-1]);

        aiger_and * par = aiger_is_and(model, w->aiger);
        Var * g_0 = var(par->rhs0);
        Var * g_1 = var(par->rhs1);


        g_0->neg = aiger_sign(par->rhs0);
        g_1->neg = aiger_sign(par->rhs1);
        //msg("%s has sign %i and slice %i", g_0->name, g_0->neg, g_0->slice);
        //msg("%s has sign %i and slice %i", g_1->name, g_1->neg, g_1->slice);
        if (size_inputs == inputs_num) enlarge_inputs ();
        inputs[inputs_num++] = g_0->aiger;
        if (size_inputs == inputs_num) enlarge_inputs ();
        inputs[inputs_num++] = g_1->aiger;

        break;
      }
    }
    c_in = l->xor ? r->aiger : l->aiger;
    if(var(c_in)->slice < cmp) {
      if (size_cin == cin_num) enlarge_cin ();
      cin[cin_num++] = c_in;

       if(verbose >= 1)  msg("found cin of slice %s", var(c_in)->name);
    }

    aiger_and * and = aiger_is_and(model, v->aiger);
    var(aiger_strip(and->rhs0))->cl = 1;
    var(aiger_strip(and->rhs1))->cl = 1;
    v->cl = 1;

  }
  return 1;
}

static int is_in_pg(unsigned val){
  for(unsigned i=0; i < pg_num; i++){
    if (pg[i] == val) return 1;
  }
  return 0;
}

static int is_in_cin(unsigned val){
  for(unsigned i=0; i < cin_num; i++){
    if (cin[i] == val) return 1;
  }
  return 0;
}

static int is_in_seen(unsigned val){
  for(unsigned i=0; i < seen_num; i++){
    if (seen[i] == val) return 1;
  }
  return 0;
}



static int follow_path(unsigned val){
  if(verbose >= 2)  msg("follow path starting with %i", val);
  if (size_seen == seen_num) enlarge_seen ();
  seen[seen_num++] = val;
  unsigned i = 0;
  while(i != seen_num){
    Var * v = var(seen[i]);
    if((v->input || v->hainp > 0) && !is_in_cin(v->aiger)) return 0;


    aiger_and * and = aiger_is_and(model, v->aiger);
    unsigned l = aiger_strip(and->rhs0), r = aiger_strip(and->rhs1);

    if(!is_in_pg(l) && !is_in_seen(l)){
        if(c_in == l){
          var(l)->neg = aiger_sign(and->rhs0);
        }
        else {
          if (size_seen == seen_num) enlarge_seen ();
          seen[seen_num++] =l;
        }
    }
    if(!is_in_pg(r) && !is_in_seen(r)){
      if(c_in == r){
        var(r)->neg = aiger_sign(and->rhs1);

      }
      else {
        if (size_seen == seen_num) enlarge_seen ();
        seen[seen_num++] =r;
      }
    }
    i++;
  }

  for(unsigned i=0; i < seen_num; i++){
    Var * v = var(seen[i]);
    v-> cl = 1;
  }
  seen_num = 0;
  return 1;
}

static int follow_all_carry_paths(){
  msg("checking last stage adder");
  int ret = follow_path(adder_carry_out->aiger);
  if(!ret) return 0;
  for (unsigned i = 0; i< cin_num-1; i++){
    ret = follow_path(cin[i]);
    if(!ret) return 0;
  }
  return 1;
}


static void mark_adder(){
  msg("marking adder");
  for(unsigned i = 0; i < pg_num; i++){
    Var * v = var(pg[i]);
    v->cl = 1;
    if(verbose >=4) msg ("marked %s with 1", v->name);
    int val = 1;
    if(v->haand) val = 2;
    aiger_and * and = aiger_is_and(model, v->aiger);
    unsigned l = aiger_strip(and->rhs0), r = aiger_strip(and->rhs1);
    var(l)->cl = val;
    if(verbose >=4) msg ("marked %s with %i", var(l)->name, val);
    var(r)->cl = val;
    if(verbose >=4) msg ("marked %s with %i", var(r)->name, val);
  }
  var(c_in)->cl = 2;
  if(verbose >=4) msg ("marked %s with 2", var(c_in)->name);
}


static int find_adder(){
  declare_carry_out_of_adder();

  int ret = declare_possible_P_and_cin();

  if(!ret) return 0;
  ret = follow_all_carry_paths();
  if(!ret) return 0;
  mark_adder();
  return 1;
}

/*------------------------------------------------------------------------*/

static void add_adder_input(){
  if (verbose >= 1) msg ("declare input nodes for adder miter");
  for(unsigned i = 1; i < M; i++){
    Var * v = vars +i;
    if(v->cl != 2) continue;
    unsigned lit = v->aiger;
    const char * n1 = v->name;
    aiger_add_input (miter, lit, n1);
    if(verbose >= 3) msg("node %s is adder input", v->name);
  }
}

static void add_adder_ands(){
  if (verbose >= 1) msg ("declare and nodes for adder miter");
  for(unsigned i = 1; i < M; i++){
    Var * v = vars +i;
    if(!v->cl) continue;
    if(v->cl == 2) continue;
    unsigned lit = v->aiger;
    aiger_and * and = aiger_is_and (model, lit);
    aiger_add_and (miter, and->lhs, and->rhs0, and->rhs1);
    if(verbose >= 3) msg("and %i %i %i", and->lhs, and->rhs0, and->rhs1);
  }
}

static void declare_adder_output(){
  if (verbose >= 1) msg ("declare output nodes for adder miter");
  for(unsigned i = 1; i < M; i++){
    Var * v = vars +i;
    if(!v->cl) continue;
    if (v->output != -1){
      unsigned lit = v->aiger;
      if (size_o1 == o1_count) enlarge_o1 ();
      if((int)lit == adder_carry_out->aiger && tc){
        if (aiger_sign (lit)) o1[o1_count++] = not(lit);
        else o1[o1_count++] = lit;
      } else {
        if (aiger_sign (lit)) o1[o1_count++] = lit;
        else o1[o1_count++] = not(lit);
      }
      v->rewrite = v->output;
      if(verbose >= 3) msg("%s is output %i", v->name, v->rewrite);
    }
  }
  if (adder_carry_out->output == -1){
    unsigned lit = adder_carry_out->aiger;
    if (size_o1 == o1_count) enlarge_o1 ();
    if (aiger_sign (lit)) o1[o1_count++] = lit;
    else o1[o1_count++] = not(lit);
    adder_carry_out->rewrite = 2*N-1;
    if(verbose >= 3)  msg("%s is output %i", adder_carry_out->name, adder_carry_out->rewrite);
  }
}

static unsigned btor_ha(unsigned i1, unsigned i2){
  unsigned one, two, three;
  one = max_idx + 2;
  two = one + 2;
  three = two + 2;

  aiger_add_and(miter, one, not(i1), not(i2));
  aiger_add_and(miter, two, i1, i2);
  aiger_add_and(miter, three, not(one), not(two));

  aiger_add_and(rewritten, one, not(i1), not(i2));
  aiger_add_and(rewritten, two, i1, i2);
  aiger_add_and(rewritten, three, not(one), not(two));

  max_idx = max_idx + 6;
  if (size_o2 == o2_count) enlarge_o2 ();
  o2[o2_count++] = three;
  //msg("found ha %i, %i and s %i and c %i", i1, i2, three, two);
  return two;
}


static unsigned btor_fa(unsigned i1, unsigned i2, unsigned i3){
  unsigned one, two, three, four, five, six ,seven;
  one = max_idx + 2;
  two = one + 2;
  three = two + 2;
  four = three + 2;
  five = four + 2;
  six = five +2;
  seven = six + 2;

  aiger_add_and(miter, one, not(i1), not(i2));
  aiger_add_and(miter, two, i1, i2);
  aiger_add_and(miter, three, not(one), not(two));
  aiger_add_and(miter, four, not(i3), not(three));
  aiger_add_and(miter, five, i3, three);
  aiger_add_and(miter, six, not(four), not(five));
  aiger_add_and(miter, seven, not(two), not(five));

  aiger_add_and(rewritten, one, not(i1), not(i2));
  aiger_add_and(rewritten, two, i1, i2);
  aiger_add_and(rewritten, three, not(one), not(two));
  aiger_add_and(rewritten, four, not(i3), not(three));
  aiger_add_and(rewritten, five, i3, three);
  aiger_add_and(rewritten, six, not(four), not(five));
  aiger_add_and(rewritten, seven, not(two), not(five));

  max_idx = max_idx + 14;
  if (size_o2 == o2_count) enlarge_o2 ();
  o2[o2_count++] = six;
  //msg("found fa %i, %i, %i and s %i and c %i", i1, i2, i3, six, seven);
  return seven;
}

static void build_btor_adder(){
  unsigned i2 = 0, i3 = 0;
  unsigned c = c_in;
  if(var(c_in)->neg) c = not(c);

  for(int i = inputs_num-1; i>=0; i--){
    Var * v = var(inputs[i--]);
    Var * w = var(inputs[i]);
    assert(v->slice == w->slice);
    i2 = v->aiger;
    if (v->neg) i2 = not(i2);
    i3 = w->aiger;
    if (w->neg) i3 = not(i3);

    if(v->cl != 2)       c = btor_ha(c, i3);
    else if (w->cl != 2) c = btor_ha(c, v->aiger);
    else                 c = not(btor_fa(c, i2, i3));
  }
  if(tc && adder_carry_out->output != -1) c = not(c);
  if (size_o2 == o2_count) enlarge_o2 ();
  o2[o2_count++] = c;
}

static void build_miter(){
  if(o1_count != o2_count) die("missmatch in outputs");
  unsigned out = 1;
  for (unsigned i = 0; i < o1_count; i++)
    out = and (out, xnor (o1[i], o2[i]));
  aiger_add_output (miter, not (out), "miter");
}

static void build_adder_miter(){
  msg("build adder miter");
  add_adder_input();
  add_adder_ands();
  declare_adder_output();
  build_btor_adder();
  build_miter();
}

/*------------------------------------------------------------------------*/

static void generate_rewritten_aig(){
  msg("generate rewritten aig");
  unsigned btor_carry = o2[o2_count-1];

  unsigned out;
  for (unsigned i = 0; i < model->num_inputs; i++) {
    unsigned lit = model->inputs[i].lit;
    char * n1 = model->inputs[i].name;
    aiger_add_input (rewritten, lit, n1);
  }

  for(unsigned i = 1; i < M; i++){
    Var * v = vars +i;
    if(v->input) continue;
    if(!v->cl || v->cl == 2){
      aiger_and * and = aiger_is_and(model, v->aiger);
      if(!v->cl && adder_carry_out){
        if((int) aiger_strip(and->rhs0) == adder_carry_out->aiger){
          if (!aiger_sign(and->rhs0)) out = not(btor_carry);
          else out = btor_carry;
          aiger_add_and (rewritten, and->lhs, out, and->rhs1);
        }
        else if ((int) aiger_strip(and->rhs1) == adder_carry_out->aiger){
          if (!aiger_sign(and->rhs1)) out = not(btor_carry);
          else out = btor_carry;
          aiger_add_and (rewritten, and->lhs, out, and->rhs0);
        } else aiger_add_and (rewritten, and->lhs, and->rhs0, and->rhs1);

      }
      else aiger_add_and (rewritten, and->lhs, and->rhs0, and->rhs1);
    }
  }
  unsigned out_idx = 0;
  char buf[80];
  for(unsigned i = 0; i<NN; i++){
    unsigned res = model->outputs[s0 + i*sinc].lit;
    Var * v = var(res);

    if(!v->rewrite) {
      sprintf(buf, "O%d", i);
      aiger_add_output(rewritten, res, buf);
    }
    else {
      if(!out_idx) out_idx = v->output;
      sprintf(buf, "O%d", i);
      aiger_add_output(rewritten, o2[(v->output)-out_idx], buf);
    }
  }
}

static void empty_miter_to_cnf(FILE* file){
  if (!file) die ("failed to write '%s'", output_name);
  fprintf (file, "p cnf 1 2 \n");
  fprintf (file, "1 0\n");
  fprintf (file, "-1 0\n");
}



static void miter_to_cnf(FILE* file){
  msg("transform aiger miter to cnf miter");
  int * map, m, n;
  unsigned i, * refs, lit;

  if (miter->num_outputs > 1) die ("more than one output");

  if (!file) die ("failed to write '%s'", output_name);

  aiger_reencode (miter);

  refs = calloc (2*(miter->maxvar+1), sizeof *refs);
  assert(refs);
  lit = miter->outputs[0].lit;
  refs[lit]++;

  i = miter->num_ands;
  while (i--){
    lit = miter->ands[i].lhs;
    if (refs[lit])  {
      refs[miter->ands[i].rhs0]++;
      refs[miter->ands[i].rhs1]++;
    }
    if (refs[aiger_not (lit)]) {
      refs[aiger_not (miter->ands[i].rhs0)]++;
      refs[aiger_not (miter->ands[i].rhs1)]++;
    }
  }

  map = calloc (2*(miter->maxvar+1), sizeof *map);
  m = 0;
  n = 1;
  if (refs[0] || refs[1]) {
    map[0] = -1;
    map[1] = 1;
    m++;
    n++;
  }
  for (lit = 2; lit <= 2*miter->maxvar; lit += 2){
    if (!refs[lit] && !refs[lit+1]) continue;
    map[lit] = ++m;
    map[lit+1] = -m;

    if (lit <= 2*miter->num_inputs+1) continue;
    if (refs[lit]) n += 2;
    if (refs[lit+1]) n += 1;
  }

  fprintf (file, "p cnf %u %u\n", m, n);
  if(verbose>=2) msg ("p cnf %u %u", m, n);

  if (refs[0] || refs[1]) fprintf (file, "%d 0\n", map[1]);

  for (i = 0; i < miter->num_ands; i++){
    lit = miter->ands[i].lhs;
    if (refs[lit]) {
      fprintf (file, "%d %d 0\n",
      map[aiger_not (lit)], map[miter->ands[i].rhs1]);
      fprintf (file, "%d %d 0\n",
      map[aiger_not (lit)], map[miter->ands[i].rhs0]);
    }
    if (refs[lit+1]) {
      fprintf (file, "%d %d %d 0\n", map[lit],
      map[aiger_not (miter->ands[i].rhs1)],
      map[aiger_not (miter->ands[i].rhs0)]);
    }
  }

  fprintf (file, "%d 0\n", map[miter->outputs[0].lit]);

  free (refs);
  free (map);
}

/******************************************************************************/

//check if parent of var is in bigger slice
static void find_carries(){
  for(int i = M-1; i > 0; i--){
    Var * v = vars + i;
    if(aiger_is_input(model, v->aiger)) continue;

    Parent * p = v->parent;
    while(p){
      Var * parent_var = var(p->pval);
      if(parent_var->slice > v->slice) v->carry++;
      p = p->rest;
    }
    if(v->output > v->slice) v->carry++;

    //msg("var %s is carry of size %i", v->name, v->carry);
  }
}


// merges gate
static void merge_all(){
  int total_merge = 0;
  int merged = 1;
  while(merged){
    merged = 0;
    for(int i = M-1; i > 0; i--){
      Var * v = vars + i;

      if(aiger_is_input(model, v->aiger)) continue;
      if(v->xor == 2 ) continue;
      if(v->slice < 0) continue;

      if(v->xor == 1 && v->occs > 1 ) continue;

      if(v->xor == 1 && v->output != -1) continue;


      assert(aiger_is_and (model, v->aiger));
      aiger_and * and = aiger_is_and (model, v->aiger);
      unsigned rhs0 = and->rhs0;
      unsigned rhs1 = and->rhs1;
      Var * v0 = var (rhs0);
      Var * v1 = var (rhs1);
      int flag = 0;


      //merge complete XOR which occurs only once
     if(v->xor == 1 && v->occs ==1 && v0->occs == 1 && v1->occs == 1){
         aiger_and * land = aiger_is_and(model, v0->aiger);
         unsigned lrhs0 = land->rhs0;
         unsigned lrhs1 = land->rhs1;
         Var * lv0 = var (lrhs0);
         Var * lv1 = var (lrhs1);

         if(lv1->slice == v0->slice || lv0->slice == v0->slice) continue;
         if(lv1->slice == v1->slice || lv0->slice == v1->slice) continue;
         if(lv0->input && lv1->input) continue;

         v->slice--;
         v0->slice--;
         v1->slice--;

         if(lv0->slice == v0->slice) lv0->carry--;
         if(lv1->slice == v0->slice) lv1->carry--;
         if(lv0->slice == v1->slice) lv0->carry--;
         if(lv1->slice == v1->slice) lv1->carry--;
         v->carry = v->occs; //carry cannot occur in same slice
         if(verbose >= 2){
           msg("merged gate %s to slice %i", v0->name, v0->slice);
           msg("merged gate %s to slice %i", v1->name, v1->slice);
           msg("merged gate %s to slice %i", v->name, v->slice);
         }
         total_merge = total_merge +3;
      }
      if(flag) continue;
      assert(!flag);


      //both children are inputs
      if(v0->input > 0 && v1->input > 0) continue;

      //children are in booth pattern
      if(v0->bo || v1->bo) continue;

      // check for topological violence
      if(v1->slice == v->slice || v0->slice == v->slice) continue;
      assert(v0->slice < v->slice);
      assert(v1->slice < v->slice);

      v->slice--;

      if(v0->slice == v->slice) v0->carry--;
      if(v1->slice == v->slice) v1->carry--;
      v->carry = v->occs; //carry cannot occur in same slice

      merged = 1;
      if(verbose >= 2)
        msg("merged gate %s to slice %i", v->name, v->slice);
      total_merge = total_merge +1;
    }
  }
  msg("totally merged %i variable(s)", total_merge);

}


// promotes gate back
static void promote_all(){
  int total_promote = 0;
  int promoted = 1;
  while(promoted){
    promoted = 0;
    for(unsigned i = 1; i < M; i++){
      Var * v = vars + i;

      if(!v->carry) continue;
      if(v->occs != v->carry) continue;

      if(aiger_is_input(model, v->aiger)) continue;
      assert(aiger_is_and (model, v->aiger));
      aiger_and * and = aiger_is_and (model, v->aiger);
      unsigned rhs0 = and->rhs0;
      unsigned rhs1 = and->rhs1;
      Var * v0 = var (rhs0);
      Var * v1 = var (rhs1);


      if(v0->input && v1->input) continue;
      if((!v0->carry || !v1->carry) &&
         (!v0->carry || !v1->input) &&
         (!v1->carry || !v0->input))  continue;  //for last two could add v->occs1

      v->slice++;

      v0->carry++;
      v1->carry++;
      v->carry = 0;

      Parent * p = v->parent;
      while(p){
        Var * pv = var(p->pval);
        if(pv->slice > v->slice) v->carry++;
        p=p->rest;
      }

      promoted = 1;
      if(verbose >= 2) msg("promoted gate %s to slice %i", v->name, v->slice);
      total_promote++;
    }
  }
  msg("totally promoted %i variable(s)", total_promote);
}


/*static void mark_var_with_two_pos_children(){
  for(unsigned i = 0; i < M; i++){
    Var * v = vars + i;
    if(v->elim) continue;
    if(!v->pp) continue;
    aiger_and * and = aiger_is_and (model, v->aiger);
    unsigned l = and->rhs0, r = and->rhs1;
    if (!aiger_sign (l) && !aiger_sign(r)) {
      msg("found var %s", v->name);
      v->bo=1;
    }

  }

}*/


static void search_for_booth_pattern(){

  for(unsigned i = 0; i < M; i++){
    Var * v = vars + i;
    if(v->elim) continue;

    //Special treatment for slice 1
    if(v->slice == 1){
      if(!v->pp) continue;

      aiger_and * and = aiger_is_and (model, v->aiger);
      unsigned l = aiger_strip(and->rhs0), r = aiger_strip(and->rhs1);
      if (!var(l)->input || !var(r)->input) continue;

      if(l-r != 2) continue;
      if(verbose >= 4) msg("found booth pattern %s", v->name);
      msg("found booth pattern %s", v->name);
      v->bo = 1;

    //all other slices
    } else {

      if(v->pp) continue;
      if(!v->xor) continue;
      if (v->occs != 1) continue;

      aiger_and * and = aiger_is_and (model, v->aiger);

      unsigned l = and->rhs0;
      if (!aiger_sign (l)) continue;

      aiger_and * land = aiger_is_and (model, l);
      unsigned ll = aiger_strip(land->rhs0), lr = aiger_strip(land->rhs1);
      if (!var(ll)->input || !var(lr)->input) continue;


      Var * xor1 = v;
      aiger_and * and1 = aiger_is_and (model, xor1->aiger);


      unsigned p = xor1->parent->pval;
      Var * vp = var(p);
      aiger_and * parent = aiger_is_and(model, p);
      unsigned pl = parent->rhs0, pr = parent->rhs1;
      Var * xor2 = ((int)pl == xor1->aiger) ? var(pl) : var(pr);

      if(xor2->occs < (int) N+1) continue;

      if(xor2->slice >= xor1->slice) continue;

      aiger_and * and2 = aiger_is_and (model, xor2->aiger);
      if(!xor2->xor) continue;

      unsigned l2 = and2->rhs0;
      if (!aiger_sign (l2)) continue;
      aiger_and * land2 = aiger_is_and (model, l2);
      unsigned ll2 = aiger_strip(land2->rhs0), lr2 = aiger_strip(land2->rhs1);
      if (!var(ll2)->input || !var(lr2)->input) continue;
      if(ll != ll2 && ll != lr2 && lr != ll2 && lr != lr2) continue;
      if (verbose >=2)
      msg("found booth pattern %s, %s, %s", xor1->name, xor2->name, vp->name);


      xor1->bo = 1;
      var(and1->rhs0)->bo = 1;
      var(and1->rhs1)->bo = 1;
      xor2->bo = 1;
      var(and2->rhs0)->bo = 1;
      var(and2->rhs1)->bo = 1;
      vp->bo = 1;
    }
  }
}


static void substitute(){
  msg("assigning slices to variables");
  for (unsigned i = 0; i < NN; i++)
    input_cone(aiger_strip(slit(i)), i);

  if(!truncated) restart = find_adder();

  if(restart){
    msg("generate-propagate adder found - rewriting necessary");
    build_adder_miter();
    miter_to_cnf(output_file);
    msg("writing miter to %s", output_name);
    generate_rewritten_aig();

    msg ("writing rewritten aig to '%s'", output_name2);
    if (!aiger_write_to_file (rewritten, aiger_binary_mode, output_file2))
      die ("failed to write rewritten '%s'", output_name2);

  } else {
    msg("no generate-propagate adder found");
    empty_miter_to_cnf(output_file);
    msg("writing trivial miter to %s", output_name);
    msg ("writing original aig to '%s'",output_name2);
    if (!aiger_write_to_file (model, aiger_binary_mode, output_file2))
      die ("failed to write rewritten '%s'", output_name2);
  }
}




// incrementally define input cone
static void assign_slices_to_var(){
  msg("assigning slices to variables");
  for (unsigned i = 0; i < NN; i++)
    input_cone(aiger_strip(slit(i)), i);

  if(booth) search_for_booth_pattern();
//  mark_var_with_two_pos_children();
  find_carries();
  merge_all();
  promote_all();



}

/*------------------------------------------------------------------------*/
typedef struct Term Term;

struct Term {
  Var * variable;  // variable name
  Term * rest;     // single linked list
  uint64_t ref;	   // reference counter
  uint64_t hash;   // saved hash value
  Term * next;	   // hash collision chain link
};

// Hash table to canonical store terms.
static uint64_t size_terms;
static uint64_t current_terms;
static Term ** term_table;


// compute hashvalues for terms
static uint64_t
compute_hash_term (Var * variable, Term * rest) {
  assert (variable);
  uint64_t res = rest ? rest->hash : 0;
  res *= nonces[0];
  res += variable->hash;
  res *= nonces[1];
  return res;
}


// enlarge hash table
static void enlarge_terms () {
  uint64_t new_size_terms = size_terms ? 2*size_terms : 1;
  Term ** new_term_table;
  ALLOCATE (new_term_table, new_size_terms);
  for (uint64_t i = 0; i < size_terms; i++) {
    for (Term * m = term_table[i], * n; m; m = n) {
      uint64_t h = m->hash & (new_size_terms - 1);
      n = m->next;
      m->next = new_term_table[h];
      new_term_table[h] = m;
    }
  }
  DEALLOCATE (term_table, size_terms);
  term_table = new_term_table;
  size_terms = new_size_terms;
}


// copy a term
static Term * copy_term (Term * m) {
  if (!m) return m;
  assert(m);
  assert (m->ref > 0);

  m->ref++;
  assert (m->ref);
  return m;
}


// Then searching and adding a term extended by one power.
static Term *
new_term (Var * variable, Term * rest) {
  if (rest) assert (variable->level < rest->variable->level);
  if (current_terms == size_terms) enlarge_terms ();
  const uint64_t hash = compute_hash_term (variable, rest);
  const uint64_t h = hash & (size_terms - 1);

  Term * res;
  for (res = term_table[h];
       res && (res->variable != variable || res->rest != rest);
       res = res->next)
       ;

  if (res) {
    res->ref++; //here we extend that we found monomomial once more
  } else {
    res = allocate (sizeof *res);
    res->variable = variable;
    res->rest = copy_term (rest);
    res->ref = 1;
    res->hash = hash;
    res->next = term_table[h];
    term_table[h] = res;
    current_terms++;

  }
  return res;
}

// Decrements the reference count of a term, and actually deletes a
// term if its reference count goes to zero.  In this case it also
// removes it from the hash table and applies the same procedure to the
// suffix 'rest'.
static void deallocate_term (Term * m) {
  while (m) {
    assert (m->ref > 0);
    if (--m->ref > 0) break; //we still need m
    Term * rest = m->rest;
    const uint64_t h = m->hash & (size_terms - 1);
    Term ** p = term_table + h, * n;
    while ((n = *p) != m) assert (n), p = &n->next;
    *p = n->next;
    assert (current_terms);
    current_terms--;
    deallocate (m, sizeof *m);
    m = rest;
  }
}

// deallocate all terms
static void deallocate_terms () {
  for (uint64_t i = 0; i < size_terms; i++) {
    for (Term * m = term_table[i], *n; m; m = n) {
      n = m->next;
      assert (current_terms);
      current_terms--;
      deallocate (m, sizeof *m);
    }
  }
  DEALLOCATE (term_table, size_terms);
}

// print term
static void print_term (Term * m, FILE * file) {
  Term * tmp = m;
  while(tmp){
    print_variable(tmp->variable, file);
    tmp = tmp->rest;
    if(tmp) fputc_unlocked('*', file);
  }
}

// compare terms
static int cmp_terms(Term * t1, Term * t2){

  Term * tmp1 = t1;
  Term * tmp2 = t2;

  while(tmp1 && tmp2){
    if (tmp1->variable->level < tmp2->variable->level) return 1;
    else if (tmp1->variable->level > tmp2->variable->level) return -1;

    tmp1= tmp1->rest;
    tmp2= tmp2->rest;
  }
  if(tmp1) return 1;
  else if(tmp2) return -1;

  return 0;
}

/*------------------------------------------------------------------------*/
// Define a stack for sorting variables in terms
static size_t size_vstack;
static size_t num_vstack = 0;
static Var ** vstack;

// make buffer bigger
static void enlarge_vstack () {
  size_t new_size_vstack = size_vstack ? 2*size_vstack : 1;
  REALLOCATE (vstack, size_vstack, new_size_vstack);
  size_vstack = new_size_vstack;
}

// push char on buffer
/*static void push_vstack (Var *v) {
  if (size_vstack == num_vstack) enlarge_vstack ();
  //vstack[num_vstack++] = v;

  if (num_vstack==0) vstack[num_vstack++] = v;
  else
  {
     unsigned i = 0;
     Var * tmp;
     while (i < num_vstack) {
       tmp = vstack[i];
       if (tmp->level == v->level) return;
       if (tmp->level > v->level) break;
       i++;
     }

     for(unsigned j = num_vstack; j>i; j--)
       vstack[j] = vstack[j-1];

     vstack[i] = v;
     num_vstack++;
  }
}*/

// push char on buffer
static void push_vstack_sorted (Var *v) {
  if (size_vstack == num_vstack) enlarge_vstack ();
  vstack[num_vstack++] = v;
}


// set size of buffer to zero
static void clear_vstack () { num_vstack = 0; }

// deallocate whole buffer
static void deallocate_vstack () { DEALLOCATE (vstack, size_vstack); }



// Generate a term from the variables on the stack
static Term * build_term_from_stack () {
  Term * res = 0;

  for(int j = num_vstack-1; j>=0; j--){
    Term * t = new_term(vstack[j], res);
    deallocate_term(res);
    res = t;
  }

  clear_vstack();
  return res;
}



/*------------------------------------------------------------------------*/

typedef struct Monomial Monomial;

struct Monomial {
  mpz_t coeff;
  Term * term;
};

// generate new monomial
static Monomial * new_monomial (mpz_t c, Term * m) {
 Monomial * res = allocate (sizeof *res);
 mpz_init(res->coeff);
 mpz_set(res->coeff, c);

 if (mpz_cmp_si(c, 0) == 0) res->term = 0;
 else  res->term = m;

 return res;
}


// copy a monomial
static Monomial * copy_monomial (Monomial * a) {
  assert(a);
  Monomial * t = new_monomial(a->coeff, copy_term(a->term));
  assert(t);
  return t;
}

// deallocate a monomial
static void deallocate_monomial(Monomial * t){
  mpz_clear(t->coeff);
  deallocate_term(t->term);
  deallocate(t, sizeof *t);
}

// print a monomial
static void print_monomial (Monomial * t, FILE * file, int lm){
  int sign = mpz_cmp_si(t->coeff, 0);
  if (!sign) return;
  else if (!lm && sign > 0) fputc_unlocked('+',file);


  if(!t->term)  mpz_out_str(file, 10, t->coeff);
  else if (mpz_cmp_si(t->coeff, -1) == 0) fputc_unlocked('-',file);
  else if (mpz_cmp_si(t->coeff, 1) != 0) mpz_out_str(file, 10, t->coeff);

  if (t->term) {
    if(mpz_cmp_ui(t->coeff, 1) != 0 && mpz_cmp_si(t->coeff, -1) != 0) fputc_unlocked('*',file);
    print_term(t->term, file);
  }

}

// compare two monomials
static int cmp_monomials(Monomial * t1, Monomial * t2){
  //if (mpz_cmp_ui(t1->coeff, 0) == 0) return 1;
  //if (mpz_cmp_ui(t1->coeff, 0) == 0) return -1;

  return cmp_terms(t1->term, t2->term);
}


/*------------------------------------------------------------------------*/
typedef struct Polynomial Polynomial;

struct Polynomial {
  Monomial * lm;
  Polynomial * rest; //single linked list
};


// generate new polynomial
static Polynomial *
new_polynomial (Monomial * lm, Polynomial * rest) {
  if (rest) assert (cmp_monomials(lm, rest->lm) >= 0);

  Polynomial * res = allocate (sizeof *res);
  res->lm = lm;
  res->rest = rest;


  return res;
}

static int is_one_poly(Polynomial* p){
  if(!p) return 0;
  if(p->rest) return 0;
  if(p->lm->term) return 0;

  if(mpz_cmp_si(p->lm->coeff, 1) != 0) return 0;
  return 1;
}

// copy a poly
// static Polynomial * copy_poly(Polynomial*p){
//   if(!p) return 0;
//   Polynomial * p1 =new_polynomial(copy_monomial(p->lm), copy_poly(p->rest));
//   assert(p1);
//   return p1;
// }

// copy a poly
static Polynomial * copy_poly(Polynomial*p){
  if(!p) return 0;
  Polynomial * tmp = p;
  Polynomial * p1 = new_polynomial(copy_monomial(tmp->lm), 0);
  Polynomial * out = p1;
  tmp = tmp->rest;

  while(tmp){
    Polynomial * res = new_polynomial(copy_monomial(tmp->lm), 0);
    p1->rest = res;
    tmp = tmp->rest;
    p1 = p1->rest;
  }
  assert(out);
  return out;
}

// deallocate a term
static void deallocate_polynomial (Polynomial * p) {
  while (p){
    deallocate_monomial(p->lm);
    Polynomial * rest = p->rest;
    deallocate (p, sizeof *p);
    p = rest;
  }
}

// print a polynomial
static void print_polynomial (Polynomial * p, FILE * file){
  if(!p) fputs_unlocked("0",file);
  else if(mpz_cmp_si(p->lm->coeff, 0) == 0) fputs_unlocked("0", file);
  else {
    Polynomial * tmp = p;
    int lm = 1;
    while(tmp){
      print_monomial(tmp->lm, file, lm);
      lm = 0;
      tmp=tmp->rest;
    }
  }
}



/*------------------------------------------------------------------------*/
static size_t size_mstack;
static size_t num_mstack = 0;
static Monomial ** mstack;

// make buffer bigger
static void enlarge_mstack () {
  size_t new_size_mstack = size_mstack ? 2*size_mstack : 1;
  REALLOCATE (mstack, size_mstack, new_size_mstack);
  size_mstack = new_size_mstack;
}


// push char on buffer
static void push_mstack (Monomial * t) {
  assert(t);
  if (mpz_cmp_si(t->coeff, 0) == 0) {
    deallocate_monomial(t);
    return;
  }
  if (size_mstack == num_mstack) enlarge_mstack ();

  if (num_mstack==0) mstack[num_mstack++] = t;

  else
  {
    assert(num_mstack>0);
    int i = num_mstack-1;
    int cmp = -1;
    Monomial * tmp = 0;

    while (i >= 0) {
      tmp = mstack[i];
      cmp = cmp_monomials(tmp, t);
      if (cmp >= 0) break;
      i--;
    }

    assert(i >= 0);

    if(cmp == 0){

      mpz_add(tmp->coeff, tmp->coeff, t->coeff);
      deallocate_monomial(t);

      if(mpz_cmp_si(tmp->coeff, 0) == 0){
        for(unsigned j = i; j < num_mstack-1; j++)
        mstack[j] = mstack[j+1];

        num_mstack--;
        deallocate_monomial(tmp);
      }
    }
    else{
      for(int j = num_mstack; j>i+1; j--)
        mstack[j] = mstack[j-1];


      mstack[i+1] = t;
      num_mstack++;
    }

  }
}

static void push_mstack_sorted(Monomial * t){
  assert(t);
  if (mpz_cmp_si(t->coeff, 0) == 0) {
    deallocate_monomial(t);
    return;
  }
  if (size_mstack == num_mstack) enlarge_mstack ();

  mstack[num_mstack++] = t;
}


// set size of buffer to zero
static void clear_mstack () { num_mstack = 0; }

// deallocate whole buffer
static void deallocate_mstack () { DEALLOCATE (mstack, size_mstack); }



// build a polynomial from stack
static Polynomial * build_polynomial_from_stack () {
  Polynomial * res = 0;

  for(int i = num_mstack-1; i>=0; i--) {
    Polynomial * tmp = new_polynomial (mstack[i], res);
    res = tmp;
  }
  if(num_mstack > max_count) max_count = num_mstack;


  clear_mstack();
  return res;
}





// Define a stack for sorting monomials in polynomials
/*static unsigned num_mstack = 0;
static Polynomial * mstack = 0;


// push char on buffer
static void push_mstack (Monomial * t) {
  assert(t);

  if (mpz_cmp_si(t->coeff, 0) == 0) {
    deallocate_monomial(t);
    return;
  }

  if(!mstack) {
    mstack = new_polynomial(t, 0);
  }
  else
  {
    Polynomial * tmp = mstack;
    Polynomial * prev = 0;

    while(tmp){
      if (cmp_monomials(tmp->lm, t) <= 0) break;
      prev = tmp;
      tmp = tmp->rest;
    }
    if(!tmp){
      prev->rest = new_polynomial(t, 0);
    } else {
      if(cmp_terms(tmp->lm->term, t->term) == 0){

        mpz_add(tmp->lm->coeff, tmp->lm->coeff, t->coeff);
        deallocate_monomial(t);

        if(mpz_cmp_si(tmp->lm->coeff,0) == 0){
          if(!prev) mstack = mstack->rest;
          else prev->rest = tmp->rest;

          deallocate_monomial(tmp->lm);
          Polynomial * rest = tmp->rest;
          deallocate (tmp, sizeof *tmp);
          tmp = rest;
        }
      }
      else {
        Polynomial * insert = new_polynomial(t, tmp);
        num_mstack++;
        if(!prev) mstack = insert;
        else prev->rest = insert;
      }
    }
  }

}

// build a polynomial from stack
static Polynomial * build_polynomial_from_stack () {
  Polynomial * res = mstack;
  mstack = 0;
  if(num_mstack > max_count) max_count = num_mstack;
  num_mstack = 0;

  return res;
}*/




/*------------------------------------------------------------------------*/
static int contained(Term * m1, Term * m2){
  int found = 0;
  Term * tmp1 = m1;

  while(tmp1){
    Term * tmp2 = m2;
    while(tmp2){
      if(tmp1->variable == tmp2->variable) found = 1;
      tmp2 = tmp2->rest;
    }
    if(!found) return 0;
    found = 0;
    tmp1 = tmp1->rest;
  }
  return 1;
}




// if term m2 is contained in m1 it calculates the remainder.
static Term * term_remainder(Term * m1, Term * m2){
  assert(!num_vstack);
  Term * dividend = m1;
  Term * divisor = m2;
  assert(contained(m2, m1));

  if(m1 == m2) return 0;

  while(divisor){
    Var * v1 = dividend->variable;
    Var * v2 = divisor->variable;

    if(v1->level == v2->level){
      divisor = divisor->rest;
      dividend = dividend->rest;
    }

    if(v1->level < v2->level){
      push_vstack_sorted(v1);
      dividend = dividend->rest;
    }
  }

  while(dividend){
    push_vstack_sorted(dividend->variable);
    dividend = dividend->rest;
  }

  Term * m = build_term_from_stack();
  return m;
}

// we divide polynomial p1 by the lm of p2
static Polynomial * divide_lm(Polynomial * p1, Polynomial * p2){
  assert(!num_mstack);
  Term * lm = p2->lm->term;

  Polynomial * tmp = p1;

  while(tmp){
    Monomial * lm_tmp = tmp->lm;
    if(contained(lm, lm_tmp->term)){
      Term * m = term_remainder(lm_tmp->term, lm);

      mpz_t ctmp;
      mpz_init(ctmp);
      mpz_cdiv_q(ctmp, lm_tmp->coeff, p2->lm->coeff);

      push_mstack_sorted(new_monomial(ctmp, copy_term(m)));
      mpz_clear(ctmp);
    }
    tmp = tmp->rest;
  }
  Polynomial * p = build_polynomial_from_stack();
  return p;
}

/*------------------------------------------------------------------------*/

//add one polynomial p2 to p1
static Polynomial * add_poly(Polynomial *p1, Polynomial *p2){
  assert(!num_mstack);

  while(p1 && p2){
    if(cmp_terms(p1->lm->term, p2->lm->term) == 1){
      push_mstack_sorted(copy_monomial(p1->lm));
      p1 = p1->rest;
    }
    else if(cmp_terms(p1->lm->term, p2->lm->term) == -1){
      push_mstack_sorted(copy_monomial(p2->lm));
      p2 = p2->rest;
    }
    else{
      Monomial * m = copy_monomial(p1->lm);
      mpz_add(m->coeff, m->coeff, p2->lm->coeff);

      if(mpz_cmp_si(m->coeff, 0) == 0){
        deallocate_monomial(m);
      } else push_mstack_sorted(m);
      p1 = p1->rest;
      p2 = p2->rest;
    }


  }



  while(p1){
    push_mstack_sorted(copy_monomial(p1->lm));
    p1 = p1->rest;
  }
  while(p2){
    push_mstack_sorted(copy_monomial(p2->lm));
    p2 = p2->rest;
  }

  Polynomial * p = build_polynomial_from_stack();
  assert(!num_mstack);
  return p;
}

// multiply two monomials
static Monomial * multiply_monomial(Monomial * t1, Monomial * t2){
  mpz_t ctmp;
  mpz_init(ctmp);
  mpz_mul(ctmp, t1->coeff, t2->coeff);

  Term * tmp1 = t1->term;
  Term * tmp2 = t2->term;

  while(tmp1 && tmp2){
    if(tmp1->variable->level < tmp2->variable->level){
      push_vstack_sorted(tmp1->variable);
      tmp1 = tmp1->rest;
    } else if (tmp1->variable->level > tmp2->variable->level){
      push_vstack_sorted(tmp2->variable);
      tmp2 = tmp2->rest;
    } else {
      push_vstack_sorted(tmp1->variable);
      tmp1 = tmp1->rest;
      tmp2 = tmp2->rest;

    }
  }

  while(tmp1){
    push_vstack_sorted(tmp1->variable);
    tmp1 = tmp1->rest;
  }

  while(tmp2){
    push_vstack_sorted(tmp2->variable);
    tmp2 = tmp2->rest;
  }

  Term * m = build_term_from_stack();
  Monomial * mon = new_monomial(ctmp, copy_term(m));
  mpz_clear(ctmp);
  return mon;

}

// multiply two polynomials
static Polynomial * multiply_poly(Polynomial *p1, Polynomial *p2){
  assert(!num_mstack);

  Polynomial * tmp1, * start_over;
  if(cmp_terms(p1->lm->term, p2->lm->term)==1){
    tmp1 = p1;
    start_over = p2;
  } else {
    tmp1 = p2;
    start_over = p1;
  }

  while(tmp1){
    Polynomial * tmp2 = start_over;
    while(tmp2){
      push_mstack(multiply_monomial(tmp1->lm, tmp2->lm));
      tmp2=tmp2->rest;
    }
    tmp1=tmp1->rest;
  }

  Polynomial * p = build_polynomial_from_stack();

  return p;
}


// multiply Poly with constant
static Polynomial * multiply_poly_with_constant(Polynomial *p1, mpz_t coeff){
  assert(!num_mstack);
  Polynomial * tmp1 = p1;

  while(tmp1){
    mpz_mul(tmp1->lm->coeff, tmp1->lm->coeff, coeff);
    tmp1 = tmp1->rest;
  }

  return p1;
}

// negate all monomials in a polynomial
static Polynomial * negate_poly(Polynomial * p1){
  Polynomial * res = p1;

  while(res){
    mpz_mul_si(res->lm->coeff, res->lm->coeff, -1);
    res = res->rest;
  }
  return p1;
}


static Polynomial * mod_poly(Polynomial *p1, int elim){
  assert(!num_mstack);
  int exp = NN;
  mpz_t coeff;
  mpz_init(coeff);

  Polynomial * old_p1 = copy_poly(p1);

  Polynomial * tmp = p1;
  Polynomial * prev = 0;
  int found_mod = 0;

  while(tmp){
      if(pac && elim){
        mpz_tdiv_q_2exp(coeff, tmp->lm->coeff, exp);
        if (mpz_cmp_si(coeff, 0) != 0){
          push_mstack_sorted(new_monomial(coeff, copy_term(tmp->lm->term)));
          found_mod = 1;
        }
      }
      mpz_tdiv_r_2exp(tmp->lm->coeff, tmp->lm->coeff, exp);
      if(mpz_cmp_si(tmp->lm->coeff, 0) == 0){
         if(!prev) p1 = p1->rest;
         else {
           prev->rest = tmp->rest;

         }
         deallocate_monomial(tmp->lm);
         Polynomial * rest = tmp->rest;
         deallocate (tmp, sizeof *tmp);
         tmp = rest;

      } else{
        prev = tmp;
        tmp = tmp->rest;
      }
  }


  if(pac && elim && found_mod){
      Polynomial * res = build_polynomial_from_stack();
      fprintf(output_file2, "*: ");
      mpz_out_str(output_file2, 10, mod_coeff);  fprintf(output_file2, ", ");
      res = negate_poly(res);
      print_polynomial(res, output_file2); fprintf(output_file2, ", ");

      res = multiply_poly_with_constant(res, mod_coeff);
      print_polynomial(res, output_file2);
      fprintf(output_file2, ";\n");

      if(elim < 2) fprintf(output_file2, "d ");
      fprintf(output_file2, "+: ");
      print_polynomial(old_p1, output_file2);     fprintf(output_file2, ", ");
      print_polynomial(res, output_file2);   fprintf(output_file2, ", ");
      print_polynomial(p1, output_file2);
      fprintf(output_file2, ";\n");

      deallocate_polynomial(res);
  }

  mpz_clear(coeff);
  deallocate_polynomial(old_p1);

  return p1;
}


/*------------------------------------------------------------------------*/

static Polynomial * define_pos_poly_onstack (Var * v){
  mpz_t one;
  mpz_init(one);
  mpz_set_ui(one, 1);

  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(one, t1);
  Polynomial * p = new_polynomial(m1, 0);

  mpz_clear(one);

  return p;
}


static Polynomial * define_neg_poly_onstack (Var * v){
  assert(!num_mstack);
  mpz_t pm_one;
  mpz_init(pm_one);
  mpz_set_si(pm_one, -1);


  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(pm_one, t1);
  push_mstack_sorted(m1);

  mpz_set_ui(pm_one, 1);
  Monomial * m2 = new_monomial(pm_one, 0);
  push_mstack_sorted(m2);

  Polynomial * p = build_polynomial_from_stack();

  assert(!num_mstack);
  mpz_clear(pm_one);
  return p;
}


static Polynomial * output_poly (Var * v){
  mpz_t one;
  mpz_init(one);
  mpz_set_si(one, -1);

  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(one, t1);
  Polynomial * p = new_polynomial(m1, 0);
  mpz_clear(one);


  unsigned lit = slit(v->slice);

  Var * v1 = var(lit);
  unsigned sign1 = aiger_sign (lit);

  Polynomial * p1;
  if (sign1) p1 = define_neg_poly_onstack(v1);
  else p1 = define_pos_poly_onstack(v1);

  Polynomial * res = add_poly(p, p1);

  deallocate_polynomial(p);
  deallocate_polynomial(p1);

  return res;
}


static Polynomial * negativ_poly(Var * v){
  mpz_t one;
  mpz_init(one);
  mpz_set_si(one, -1);

  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(one, t1);
  Polynomial * p = new_polynomial(m1, 0);
  mpz_clear(one);

  unsigned lit = v->aiger-1;

  Var * v1 = var(lit);

  Polynomial * p1 = define_neg_poly_onstack(v1);
  Polynomial * res = add_poly(p, p1);

  deallocate_polynomial(p);
  deallocate_polynomial(p1);
  return res;
}



static Polynomial * define_circuit_poly(Var * v){
  assert(!num_mstack);
  assert(!v->input);
  mpz_t one;
  mpz_init(one);
  mpz_set_si(one, -1);

  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(one, t1);
  Polynomial * p = new_polynomial(m1, 0);


  aiger_and * and = aiger_is_and (model, v->aiger);
  unsigned rhs0 = and->rhs0;
  unsigned rhs1 = and->rhs1;


  Var * v1 = var (rhs0);
  Var * v2 = var (rhs1);
  unsigned sign1 = aiger_sign (rhs0);
  unsigned sign2 = aiger_sign (rhs1);

  Polynomial * p1;
  Polynomial * p2;

  if (sign1) p1 = define_neg_poly_onstack(v1);
  else p1 = define_pos_poly_onstack(v1);

  if (sign2) p2 = define_neg_poly_onstack(v2);
  else p2 = define_pos_poly_onstack(v2);

  Polynomial * tail = multiply_poly(p1, p2);
  Polynomial * res = add_poly(p, tail);

  deallocate_polynomial(p);
  deallocate_polynomial(p1);
  deallocate_polynomial(p2);
  deallocate_polynomial(tail);

  mpz_clear(one);
  assert(!num_mstack);

  return res;

}
/*------------------------------------------------------------------------*/


static Polynomial ** slice_rem;
static unsigned slice_rem_count = 0;

//allocate variables
static void allocate_slicerem(){
  slice_rem = allocate_block (NN, sizeof *slice_rem);
  if (!slice_rem) die ("failed to allocate slice_rem");
}

static void deallocate_slicerem(){
  assert(slice_rem_count == 1);
  deallocate_polynomial(slice_rem[0]);
  deallocate(slice_rem, (NN) * (sizeof *slice_rem));
}

//allocate variables
static void add_up_slicerem(){
  unsigned current_count = 0;
  while(slice_rem_count > 1){
    for(unsigned i = 0; i < slice_rem_count/2; i++){
      Polynomial * p = slice_rem[2*i];
      Polynomial * q = slice_rem[2*i+1];

      assert(p);
      assert(q);
      Polynomial * add = add_poly(p,q);

      fprintf(output_file2, "\n");
      fprintf(output_file2, "d ");
      fprintf(output_file2, "+: ");
      print_polynomial(p, output_file2);   fprintf(output_file2, ", ");
      print_polynomial(q, output_file2);   fprintf(output_file2, ", ");
      print_polynomial(add, output_file2);
      fprintf(output_file2, ";\n");

      if(modulo) add  = mod_poly(add, 1);

      deallocate_polynomial(p);
      deallocate_polynomial(q);

      slice_rem[current_count++] = add;

    }

    if(slice_rem_count % 2 ==1){
      slice_rem[current_count++] = slice_rem[slice_rem_count-1];
    }

    slice_rem_count=current_count;
    current_count = 0;

  }
  assert(slice_rem_count == 1);


}



/*----------------------------------------------------------------------------*/

static Polynomial ** pacrem;
static unsigned pacrem_count = 0;

//allocate variables
static void allocate_pacrem(){
  pacrem = allocate_block (M, sizeof *pacrem);
  if (!pacrem) die ("failed to allocate slice_rem");
}

static void deallocate_pacrem(){
  assert(pacrem_count == 0);
  deallocate(pacrem, (M) * (sizeof *pacrem));
}

//allocate variables
static void add_up_pacrem(){
  unsigned current_count = 0;
  while(pacrem_count > 1){
    for(unsigned i = 0; i < pacrem_count/2; i++){
      Polynomial * p = pacrem[2*i];
      Polynomial * q = pacrem[2*i+1];

      assert(p);
      assert(q);
      Polynomial * add = add_poly(p,q);

      fprintf(output_file2, "\n");
      fprintf(output_file2, "d ");
      fprintf(output_file2, "+: ");
      print_polynomial(p, output_file2);   fprintf(output_file2, ", ");
      print_polynomial(q, output_file2);   fprintf(output_file2, ", ");
      print_polynomial(add, output_file2);
      fprintf(output_file2, ";\n");

      if(modulo) add  = mod_poly(add, 1);
      deallocate_polynomial(p);
      deallocate_polynomial(q);

      pacrem[current_count++] = add;
    }

    if(pacrem_count % 2 ==1){
      pacrem[current_count++] = pacrem[pacrem_count-1];
    }

    pacrem_count = current_count;
    current_count = 0;


  }

  assert(pacrem_count == 1);
  slice_rem[slice_rem_count++] = copy_poly(pacrem[0]);
  deallocate_polynomial(pacrem[0]);
  pacrem_count = 0;


}
/*------------------------------------------------------------------------*/

typedef struct Slice Slice;

struct Slice {
  unsigned size;    // no of variables assigned to slice
  Var ** vars;      // vars assigned to slice
  Polynomial ** poly;
  int maxlevel;

};

static Slice * slices;

// allocate slices
static void allocate_slices(){
  slices = allocate_block (NN, sizeof *slices);
  if (!slices) die ("failed to allocate slices");

  for (unsigned i = 0; i < NN; i++) {
    Slice * S = slices + i;
    S->size = 1;
    S->vars = allocate_block(M, sizeof *S->vars);
    S->vars[0] = vars + M + i;
    S->poly = allocate_block(M, sizeof *S->poly);
  }
}


static void push_vars (Slice * S, Var * v) {
  unsigned i = 0;
  Var * tmp;
  while (i < S->size) {
    tmp = S->vars[i];
    if (v->level >= tmp->level) break;
    i++;
  }

  if(i < S->size){
    for(unsigned j = S->size; j > i; j--)
       S->vars[j] = S->vars[j-1];
  }
  S->vars[i] = v;
  S->size++;
}


static void level_to_order(){
  if(verbose >=4) msg("ordering variables");
  unsigned order = 0;
  for (int i = NN-1; i >= 0; i--) {
    Slice * S = slices + i;
    for (unsigned j = 0; j < S->size; j++){
      Var * v = S->vars[j];
      v->level = order++;
      if(verbose >=4) msg("variable %s has level %i", v->name, v->level);
    }
  }

  //b is bigger than a

    for (int i = N-1; i >= 0; i--){
      Var * v = var (blit (i));
      v->level = order++;
      if(verbose >=4) msg("variable %s has level %i", v->name, v->level);

    }


  for (int i = N-1; i >= 0; i--){
    Var * v = var (alit (i));
    v->level = order++;
    if(verbose >=4) msg("variable %s has level %i", v->name, v->level);

  }


  msg("ordered %i variables", order);
}


static void push_poly(){
  for (int i = NN - 1; i >= 0; i--) {
    Slice * S = slices + i;
    S->poly[0] = output_poly(vars + M + i);
    for (unsigned j = 1; j < S->size; j++){
      Var * v = S->vars[j];
      if(v->neg) S->poly[j] = negativ_poly(v);
      else S->poly[j] = define_circuit_poly(v);
    }
  }
}

static void print_circuit_poly(){
  for (int i = NN-1; i >= 0; i--) {
    msg("slice %i", i);
    Slice * S = slices + i;
    for (unsigned j = 0; j < S->size; j++){
       msg_no_nl("");
       print_polynomial( S->poly[j],stdout);
       fprintf(stdout, ";\n");
    }
    msg("");
  }
  msg("");
}





static void init_slices(){
  allocate_slices();
  for (int i = 0; i < (int) NN; i++) {
    Slice * S = slices + i;

    for(int j = 1; j < (int) M; j++){
      Var * v = vars + j;
      if(v->slice == i) {
        push_vars(S, v);
      }
    }
  }
  msg("filled %i slices", NN);
  level_to_order();

  push_poly();
}



static void multiply_slices(){
  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base,2);

  mpz_t mod;
  mpz_init(mod);


  for (int i = NN - 1; i > 0; i--) {
    mpz_pow_ui(mod, base, i);
    Slice * S = slices + i;

    for (unsigned j = 0; j < S->size; j++){
      Polynomial * p = S->poly[j];
      if(pac) {
        fprintf(output_file2, "d ");
        fprintf(output_file2, "*:");
        print_polynomial(p, output_file2);
        fprintf(output_file2, ", ");
        mpz_out_str(output_file2, 10, mod);
        fprintf(output_file2, ", ");
      }
      p = multiply_poly_with_constant(p, mod);
      if(pac){
        print_polynomial(p, output_file2);
        fprintf(output_file2, ";\n");
      }
    }
  }
  mpz_clear(base);
  mpz_clear(mod);
}

static void deallocate_slices(){
  for(unsigned i = 0; i < NN; i++){
    Slice * S = slices + i;

    for(unsigned j = 0; j < S->size; j++){
      deallocate_polynomial(S->poly[j]);
    }
    deallocate (slices[i].poly, M *(sizeof *slices[i].poly) );
    if (slices[i].vars) deallocate (slices[i].vars, M *(sizeof *slices[i].vars) );
  }

  deallocate (slices, NN * (sizeof *slices));
}
/*------------------------------------------------------------------------*/
Polynomial * pac_rem = 0;

static void update_size_of_rem(Polynomial * p){
  Polynomial * tmp = p;
  unsigned count = 0;
  while(tmp){
    if(mpz_cmp_si(tmp->lm->coeff, 0) != 0 || tmp->lm->term) count++;
    tmp = tmp->rest;

  }
  msg("current spec size is %i", count);
}

static int var_in_term(Var * v, Term * t){
  while(t){
    if(t->variable->level > v->level) return 0;
    if(t->variable == v) return 1;
    t = t->rest;
  }
  return 0;
}


static int var_in_poly(Var * v, Polynomial * p){
  Polynomial * p1 = p->rest;
  while(p1){
    Term * tmp = p1->lm->term;
    int found = var_in_term(v, tmp);
    if(found) return 1;
    p1 = p1->rest;
  }
  return 0;
}

// int elim: 0 for reduction
// 1 for decompose
// 2 for eliminate

static Polynomial * reduce_by_one_poly(Polynomial * p1, Polynomial * p2, int elim){
  Polynomial * negfactor = divide_lm(p1, p2);
  negfactor = negate_poly(negfactor);
  Polynomial * mult   = multiply_poly(negfactor, p2);
  Polynomial * rem    = add_poly(p1, mult);

  //eg in decomposing
  if(pac && elim > 0){
    if(!is_one_poly(negfactor)){
      if(elim < 2) fprintf(output_file2, "d ");

      fprintf(output_file2, "*: ");
      print_polynomial(p2, output_file2);        fprintf(output_file2, ", ");
      print_polynomial(negfactor, output_file2); fprintf(output_file2, ", ");
      print_polynomial(mult, output_file2);
      fprintf(output_file2, ";\n");
    }

    if(elim < 2) fprintf(output_file2, "d ");
    fprintf(output_file2, "+: ");
    print_polynomial(p1, output_file2);     fprintf(output_file2, ", ");
    print_polynomial(mult, output_file2);   fprintf(output_file2, ", ");
    print_polynomial(rem, output_file2);
    fprintf(output_file2, ";\n");
  }
  else if(pac){

    if(!is_one_poly(negfactor)){
      fprintf(output_file2, "d ");
      fprintf(output_file2, "*: ");
      print_polynomial(p2, output_file2);        fprintf(output_file2, ", ");
      print_polynomial(negfactor, output_file2); fprintf(output_file2, ", ");
      print_polynomial(mult, output_file2);
      fprintf(output_file2, ";\n");
    }
     if(mult) pacrem[pacrem_count++] = copy_poly(mult);
    /*if(pac_rem){
      Polynomial * tmp_rem    = add_poly(pac_rem, mult);

      fprintf(output_file2, "+: ");
      print_polynomial(pac_rem, output_file2); fprintf(output_file2, ", ");
      print_polynomial(mult, output_file2);    fprintf(output_file2, ", ");
      print_polynomial(tmp_rem, output_file2);
      fprintf(output_file2, ";\n");

      if(modulo)  tmp_rem  = mod_poly(tmp_rem, 1);

      deallocate_polynomial(pac_rem);
      pac_rem = tmp_rem;
    } else  pac_rem = copy_poly(mult);*/

  }
  if(modulo) rem  = mod_poly(rem, elim);

  deallocate_polynomial(negfactor);
  deallocate_polynomial(mult);

  return rem;
}


static void decompose_var_in_slice(Slice * S, Var * v, unsigned index){
  for(unsigned j = 0; j < index; j++){
    Polynomial * p = S->poly[j];
    if(var_in_poly(v, p)){
      Polynomial * tmp = p;
      S->poly[j] = reduce_by_one_poly(p, S->poly[index], 1);

      assert(S->poly[j]);
      deallocate_polynomial(tmp);
      return;
    }
  }
}


static void eliminate_var_in_multiple_slices(Var * v, Polynomial * p, unsigned sliceindex){
  for(unsigned i = sliceindex; i < NN; i++){
    Slice * S = slices + i;
    for(unsigned j = 0; j < S->size; j++){

      Polynomial * res = S->poly[j];
      if(var_in_poly(v, res)){
        S->poly[j] = reduce_by_one_poly(res, p, 2);
        assert(S->poly[j]);
        deallocate_polynomial(res);
        if(pac) fprintf(output_file2, "\n");

      }
    }
  }
}


static void delete_var_from_slice(Slice * S, unsigned index){
  for(unsigned j = index; j < S->size -1; j++){
    S->poly[j] = S->poly[j+1];
    S->vars[j] = S->vars[j+1];
  }
  S->size--;
}

static void correct_parents(Slice * S, Var * v){
  Parent * p = v->parent;

  for (unsigned i = 0; i < S->size; i++){
    Var * tmp = S->vars[i];

    if( is_parent(v->aiger, tmp->parent)){
      tmp->parent = remove_parent(tmp->parent, v->aiger);
      tmp->parent = add_parent(tmp->parent, p->pval);
      tmp->occs = no_of_parents(tmp);
    }
  }
}
/*------------------------------------------------------------------------*/

static void decomposing(){
  unsigned decomp_count = 0;
  for (int i = NN-1; i >= 0; i--) {
    Slice * S = slices + i;
    unsigned change = 1;
    while (change){
      change = 0;
      for (unsigned j = 0; j < S->size; j++){
        Var * v = S->vars[j];
        if(v->occs == 1 && !v->carry && v->aiger > 0) {
          Polynomial * p = S->poly[j];
          if(verbose>=2) msg("decomposing %s", v->name);
          correct_parents(S, v);
          decompose_var_in_slice(S, v, j);
          delete_var_from_slice(S, j);
          deallocate_polynomial(p);
          change = 1;
          decomp_count++;
        }
      }
    }
  }
  msg("decomposed %i variables", decomp_count);

  if(verbose >= 2 && decomp_count) {
    msg("after decomposing we received: ");
    print_circuit_poly();
  }
}



// repeated
static void eliminating(){
  unsigned elim_count = 0;
  for (int i = NN-1; i >= 0; i--) {
    Slice * S = slices + i;
    unsigned change = 1;
    while (change){
      change = 0;
      for (unsigned j = 0; j < S->size; j++){
        Var * v = S->vars[j];
        if(v->bo){
          if(verbose>=2) msg("eliminating %s", v->name);
          Polynomial * p = S->poly[j];
          eliminate_var_in_multiple_slices(v, p, i);
          delete_var_from_slice(S, j);
          deallocate_polynomial(p);
          change = 1;
          elim_count++;

        }
      }
    }
  }
  msg("eliminated %i variables", elim_count);

  if(verbose >= 2 && elim_count) {
    msg("after eliminating we received: ");
    print_circuit_poly();
  }
}
/*------------------------------------------------------------------------*/
static Polynomial * non_inc_spec(){
  mpz_t coeff;
  mpz_init(coeff);

  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base, 2);

  for (int i = NN-1; i >= 0; i--) {
    mpz_pow_ui(coeff, base, i);
    mpz_mul_si(coeff, coeff, -1);

    Var * v = vars + M + i;
    Term * t1 = new_term(v, 0);
    Monomial * m1 = new_monomial(coeff, t1);
    push_mstack_sorted(m1);

  }

  for (int i = N-1; i >= 0; i--){
    Var * v = var (blit (i));
    for (int j = N-1; j >= 0; j--){
      if(truncated &&  i+j > (int) N-1) continue;
      Var * w = var (alit (j));
      mpz_pow_ui(coeff, base, i+j);

      push_vstack_sorted(v);
      push_vstack_sorted(w);
      Term * t1 = build_term_from_stack();
      Monomial * m1 = new_monomial(coeff, t1);

      push_mstack_sorted(m1);
    }
  }

  mpz_clear(coeff);
  mpz_clear(base);

  Polynomial * res = build_polynomial_from_stack();

  return res;

}


static Polynomial * non_inc_twos_comp_spec(){
  mpz_t coeff;
  mpz_init(coeff);

  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base, 2);



  for (int i = NN-1; i >= 0; i--) {
    mpz_pow_ui(coeff, base, i);
    if(i != (int)NN-1) mpz_mul_si(coeff, coeff, -1);

    Var * v = vars + M + i;
    Term * t1 = new_term(v, 0);
    Monomial * m1 = new_monomial(coeff, t1);
    push_mstack_sorted(m1);

  }

  for (int i = N-1; i >= 0; i--){
    Var * v = var (blit (i));
    for (int j = N-1; j >= 0; j--){
      if(truncated &&  i+j > (int) N-1) continue;
      Var * w = var (alit (j));
      mpz_pow_ui(coeff, base, i+j);
      if(i == (int)N-1) mpz_mul_si(coeff, coeff, -1);
      if(j == (int)N-1) mpz_mul_si(coeff, coeff, -1);

      push_vstack_sorted(v);
      push_vstack_sorted(w);
      Term * t1 = build_term_from_stack();
      Monomial * m1 = new_monomial(coeff, t1);
      push_mstack_sorted(m1);

    }
  }

  mpz_clear(coeff);
  mpz_clear(base);

  Polynomial * res = build_polynomial_from_stack();
  return res;

}

static Polynomial * generate_non_inc_spec(){
  if (tc) return non_inc_twos_comp_spec();
  else return non_inc_spec();
}

static void reducing_non_inc(){
  msg("final reduction started");
  Polynomial * spec = generate_non_inc_spec();

  for(int i = NN-1; i >= 0; i--){
    Slice * S = slices +i;

    for(unsigned j = 0; j < S->size; j++){
      Polynomial * tmp = reduce_by_one_poly(spec, S->poly[j], 0);
      deallocate_polynomial(spec);
      spec = tmp;
    }
    msg("reduced by slice %i", i);
    if(verbose >= 1){
      msg("after reducing by slice %i", i);
      msg_no_nl("the remainder is ");
      print_polynomial(spec, stdout);
      fputs_unlocked(";\n", stdout);
      msg(" ");
    }
  }

  msg(" ");
  msg_no_nl("final remainder is ");
  print_polynomial(spec, stdout);
  fputs_unlocked(";\n", stdout);
  msg(" ");

  if(spec) die ("incorrect multiplier");
  msg("CORRECT MULTIPLIER");

  deallocate_polynomial(spec);
}
/*------------------------------------------------------------------------*/
static Polynomial * inc_spec(int index){
  mpz_t coeff;
  mpz_init(coeff);

  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base, 2);

  mpz_pow_ui(coeff, base, index);

  Var * v = vars + M + index;
  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(coeff, t1);
  push_mstack_sorted(m1);



  for (int i = N-1; i >= 0; i--){
    Var * v = var (blit (i));
    for (int j = N-1; j >= 0; j--){
      if(i+j != index) continue;
      if(truncated &&  i+j > (int) N-1) continue;

      Var * w = var (alit (j));
      mpz_pow_ui(coeff, base, i+j);
      mpz_mul_si(coeff, coeff, -1);

      push_vstack_sorted(v);
      push_vstack_sorted(w);
      Term * t1 = build_term_from_stack();
      Monomial * m1 = new_monomial(coeff, t1);
      push_mstack_sorted(m1);

    }
  }

  mpz_clear(coeff);
  mpz_clear(base);

  Polynomial * res = build_polynomial_from_stack();
  return res;
}


static Polynomial * inc_twos_comp_spec(int index){
  mpz_t coeff;
  mpz_init(coeff);

  mpz_t base;
  mpz_init(base);
  mpz_set_ui(base, 2);

  mpz_pow_ui(coeff, base, index);
  if(index == (int)NN-1) mpz_mul_si(coeff, coeff, -1);

  Var * v = vars + M + index;
  Term * t1 = new_term(v, 0);
  Monomial * m1 = new_monomial(coeff, t1);
  push_mstack_sorted(m1);



  for (int i = N-1; i >= 0; i--){
    Var * v = var (blit (i));
    for (int j = N-1; j >= 0; j--){
      if(i+j != index) continue;
      if(truncated &&  i+j > (int) N-1) continue;

      Var * w = var (alit (j));
      mpz_pow_ui(coeff, base, i+j);
      mpz_mul_si(coeff, coeff, -1);
      if(i == (int)N-1) mpz_mul_si(coeff, coeff, -1);
      if(j == (int)N-1) mpz_mul_si(coeff, coeff, -1);

      push_vstack_sorted(v);
      push_vstack_sorted(w);
      Term * t1 = build_term_from_stack();
      Monomial * m1 = new_monomial(coeff, t1);

      push_mstack_sorted(m1);

    }
  }

  mpz_clear(coeff);
  mpz_clear(base);

  Polynomial * res = build_polynomial_from_stack();
  return res;
}


static Polynomial * generate_inc_spec(int index){
  if (tc) return inc_twos_comp_spec(index);
  else return inc_spec(index);
}


static void reducing_inc(){
  msg("final reduction started");
  Polynomial * spec = 0;

  for(int i = NN-1; i >= 0; i--){
    Polynomial * inc_spec = generate_inc_spec(i);

    Polynomial * add_spec = add_poly(spec, inc_spec);
    deallocate_polynomial(inc_spec);
    deallocate_polynomial(spec);
    spec = add_spec;


    Slice * S = slices +i;
    for(unsigned j = 0; j < S->size; j++){
      if(verbose >= 3){
        msg_no_nl("current spec is ");
        print_polynomial(spec, stdout);
        fputs_unlocked(";\n", stdout);

        msg_no_nl("reducing by ");
        print_polynomial(S->poly[j], stdout);
        fputs_unlocked(";\n", stdout);
      }

      Polynomial * tmp = reduce_by_one_poly(spec, S->poly[j], 0);

      deallocate_polynomial(spec);
      spec = tmp;
      if(elim_print) update_size_of_rem(spec);

      if(verbose >= 3){
        msg_no_nl("the remainder is ");
        print_polynomial(spec, stdout);
        fputs_unlocked(";\n", stdout);
        msg(" ");
      }

    }
    msg("reduced by slice %i", i);
    if(verbose >= 1){
      msg("after reducing by slice %i", i);
      msg_no_nl("remainder is ");
      print_polynomial(spec, stdout);
      fputs_unlocked(";\n", stdout);
      msg(" ");
    }

     if(pac){
      assert(!slice_rem[slice_rem_count]);
      add_up_pacrem();
      assert(pacrem_count == 0);

      //slice_rem[slice_rem_count++] = pac_rem;
      //pac_rem = 0;
    }
  }

  msg(" ");
  msg_no_nl("final remainder is ");
  print_polynomial(spec, stdout);
  fputs_unlocked(";\n", stdout);
  msg(" ");

  if(spec) die ("incorrect multiplier");
  msg("CORRECT MULTIPLIER");

  deallocate_polynomial(spec);
}
/*------------------------------------------------------------------------*/

static void correct_pp_unsigned(){
  //fprintf(output_file2, "correct pp\n\n");
  Polynomial * p;
  p = slice_rem[0];
  assert(p);
  Polynomial *pp = p;

  mpz_t minus_one;
  mpz_init(minus_one);
  mpz_set_si(minus_one, -1);

  mpz_t one;
  mpz_init(one);
  mpz_set_si(one, 1);

  while(p){
    Monomial * m = p->lm;
    Term * t = m->term;

    if((incremental && mpz_cmp_si(m->coeff, 0)<0) ||
       (!incremental && mpz_cmp_si(m->coeff, 0)>0)){
      int flag = 0;
      while(t && !flag){
        Var * v = t->variable;
        if(!v->input) flag = 1;
        t = t->rest;
      }

      if(!flag){
        Monomial * tmp;
        if(incremental) tmp = new_monomial(one, copy_term(m->term));
        else tmp = new_monomial(minus_one, copy_term(m->term));
        push_mstack_sorted(tmp);
      }
    }
    p = p->rest;
  }

  mpz_clear(minus_one);
  mpz_clear(one);

  Polynomial * factor = build_polynomial_from_stack();
  if(!factor) return;
  fprintf(output_file2, "d ");
  fprintf(output_file2, "*: ");
  mpz_out_str(output_file2, 10, mod_coeff);   fprintf(output_file2, ", ");
  print_polynomial(factor, output_file2);     fprintf(output_file2, ", ");
  factor = multiply_poly_with_constant(factor, mod_coeff);
  print_polynomial(factor, output_file2);
  fprintf(output_file2, ";\n");

  Polynomial * add = add_poly(factor, pp);

  fprintf(output_file2, "d ");
  fprintf(output_file2, "+: ");
  print_polynomial(factor, output_file2);    fprintf(output_file2, ", ");
  print_polynomial(pp, output_file2);        fprintf(output_file2, ", ");
  print_polynomial(add, output_file2);
  fprintf(output_file2, ";\n");

  deallocate_polynomial(factor);
  deallocate_polynomial(add);

}


static void correct_pp_signed(){
  //fprintf(output_file2, "correct pp\n\n");
  Polynomial * p;
  p = slice_rem[0];
  assert(p);
  Polynomial *pp = p;

  mpz_t minus_one;
  mpz_init(minus_one);
  mpz_set_si(minus_one, -1);

  mpz_t one;
  mpz_init(one);
  mpz_set_si(one, 1);

  mpz_t half_mod;
  mpz_init(half_mod);
  mpz_tdiv_q_ui(half_mod, mod_coeff, 2);

  mpz_t half_mod_neg;
  mpz_init(half_mod_neg);
  mpz_mul_si(half_mod_neg, half_mod, -1);

  while(p){
    Monomial * m = p->lm;

    if((incremental && mpz_cmp(m->coeff, half_mod)>0) ){
      Monomial * tmp = new_monomial(minus_one, copy_term(m->term));
      push_mstack_sorted(tmp);
    }
    else if((incremental && mpz_cmp(m->coeff, half_mod_neg)<0) ){
      Monomial * tmp = new_monomial(one, copy_term(m->term));
      push_mstack_sorted(tmp);
    }
    p = p->rest;
  }

  mpz_clear(minus_one);
  mpz_clear(one);
  mpz_clear(half_mod);
  mpz_clear(half_mod_neg);

  Polynomial * factor = build_polynomial_from_stack();
  if(!factor) return;
  fprintf(output_file2, "d ");
  fprintf(output_file2, "*: ");
  mpz_out_str(output_file2, 10, mod_coeff);   fprintf(output_file2, ", ");
  print_polynomial(factor, output_file2);     fprintf(output_file2, ", ");
  factor = multiply_poly_with_constant(factor, mod_coeff);
  print_polynomial(factor, output_file2);
  fprintf(output_file2, ";\n");

  Polynomial * add = add_poly(factor, pp);

  fprintf(output_file2, "d ");
  fprintf(output_file2, "+: ");
  print_polynomial(factor, output_file2);    fprintf(output_file2, ", ");
  print_polynomial(pp, output_file2);        fprintf(output_file2, ", ");
  print_polynomial(add, output_file2);
  fprintf(output_file2, ";\n");

  deallocate_polynomial(factor);
  deallocate_polynomial(add);

}

static void correct_pp(){
  if(tc) correct_pp_signed();
  else correct_pp_unsigned();
}





/*------------------------------------------------------------------------*/
static void print_circuit_poly_to_file(){
  for (int i = NN-1; i >= 0; i--) {
    Slice * S = slices + i;
    for (unsigned j = 0; j < S->size; j++){
      print_polynomial( S->poly[j], output_file);
      fprintf(output_file, ";\n");
    }
  }
  if(modulo && !elim_print){
    mpz_out_str(output_file, 10, mod_coeff);
    fprintf(output_file, ";\n");
  }
}



static void print_var_to_file(){
  for (int i = NN-1; i >= 0; i--) {
    Slice * S = slices + i;
    for (unsigned j = 0; j < S->size; j++){
      print_variable( S->poly[j]->lm->term->variable, output_file2);
      fprintf(output_file2, ";\n");
    }
  }

  for (int i = N-1; i >= 0; i--){
    Var * v = var (blit (i));
    print_variable( v, output_file2);
    fprintf(output_file2, ";\n");

    v = var (alit (i));
    print_variable( v, output_file2);
    fprintf(output_file2, ";\n");
  }

}




static void print_spec_to_file(){
  Polynomial * p  = generate_non_inc_spec();
  if(!incremental) p = negate_poly(p);

  print_polynomial(p, output_file3);
  fprintf(output_file3, ";\n");
  deallocate_polynomial(p);
}
/*------------------------------------------------------------------------*/
// init hashfunction
static void init() {
  init_nonces ();
  if(modus == 1) miter = aiger_init ();
  if(modus == 1) rewritten = aiger_init ();
}


static void reset_substitute(){
  deallocate_vars();
  deallocate_vstack ();
  deallocate_mstack ();
  deallocate_seen ();
  deallocate_pg ();
  deallocate_cin ();
  deallocate_inputs ();
  deallocate_o1 ();
  deallocate_o2 ();
  aiger_reset (model);
  aiger_reset (miter);
  aiger_reset (rewritten);
  mpz_clear(mod_coeff);

  reset_all_signal_handlers ();
  assert (!current_allocated_bytes);
}

static void reset_all(){
  if(pac) {
    deallocate_pacrem();
    deallocate_slicerem();
  }
  deallocate_slices();
  deallocate_vars();


  deallocate_polynomial(pac_rem);

  deallocate_vstack ();
  deallocate_mstack ();
  deallocate_terms  ();

  aiger_reset (model);
  mpz_clear(mod_coeff);

  reset_all_signal_handlers ();
  assert (!current_allocated_bytes);
}
/*------------------------------------------------------------------------*/
int main (int argc, char ** argv) {
  mpz_init(mod_coeff);

  for (int i = 1; i < argc; i++) {
    if (!strcmp (argv[i], "-h") ||
        !strcmp (argv[i], "--help")) {
      fputs (USAGE, stdout);
      fflush (stdout);
      exit (0);
    } else if (!strcmp (argv[i], "-substitute")) {
      modus = 1;
    } else if (!strcmp (argv[i], "-verify")) {
      modus = 2;
    } else if (!strcmp (argv[i], "-certify")) {
      modus = 3;
    } else if (!strcmp (argv[i], "-2comp")) {
      tc = 1;
    } else if (!strcmp (argv[i], "-non-inc")) {
      incremental = 0;
    } else if (!strcmp (argv[i], "-no-mod")) {
      modulo = 0;
    } else if (!strcmp (argv[i], "-no-elim")) {
      elim = 0;
    }else if (!strcmp (argv[i], "-elim-print")) {
      elim_print = 1;
    } else if (!strcmp (argv[i], "-v1")) {
      verbose = 1;
    } else if (!strcmp (argv[i], "-v2")) {
      verbose = 2;
    } else if (!strcmp (argv[i], "-v3")) {
      verbose = 3;
    } else if (!strcmp (argv[i], "-v4")) {
      verbose = 4;
    } else if (argv[i][0] == '-')
      die ("invalid command line option '%s' (try '-h')", argv[i]);
    else if (output_name3)
      die ("too many arguments '%s', '%s', '%s', '%s' and '%s' (try '-h')",
        input_name, output_name, output_name2, output_name3, argv[i]);
    else if (output_name2) output_name3 = argv[i];
    else if (output_name) output_name2 = argv[i];
    else if (input_name) output_name = argv[i];
    else input_name = argv[i];
  }

  if(elim_print && modus!=2){
    die("option elim-print is only supported in modus -verify");
  }

  if (!modus) die("select modus (try -h for more information)");
  if (!input_name)  die("no input file given");
  if (modus == 1){
    if (output_name3) die ("too many arguments '%s', '%s', '%s' and '%s' (try '-h')",
      input_name, output_name, output_name2, output_name3);
    if (!output_name2) die ("too few arguments (try '-h')");
    if (!modulo) msg ("Warning: Option '-no-mod' is needless in modus '-substitute' ");
    if (!incremental) msg ("Warning: Option '-non-inc' is needless in modus '-substitute' ");
  } else if (modus == 2) {
    if (output_name && !elim_print) die ("too many arguments (try '-h')");
    if (!output_name3 && elim_print) die ("too few arguments (try '-h')");
  } else if (modus == 3){
    if (!output_name3) die ("too few arguments (try '-h')");
    pac = 1;
  }

  if(!elim && elim_print) msg("Warning: Option 'elim_print' is needless with option '-no-elim' ");


  if (output_name) {
    if (!(output_file = fopen (output_name, "w")))
      die ("can not write output to '%s'", output_name);
  }
  if (output_name2) {
    if (!(output_file2 = fopen (output_name2, "w")))
      die ("can not write output to '%s'", output_name2);
  }
  if (output_name3) {
    if (!(output_file3 = fopen (output_name3, "w")))
      die ("can not write output to '%s'", output_name3);
  }



  init();
  init_all_signal_handers ();

  // print banner
  banner();

  // initialize aiger file
  read_aiger(input_name);
  init_aiger_with_checks();
  if(modus >1) init_mod_coeff();

  // check if sorted according to aoki or btor ordering
  determine_input_order();

  // allocate variables and slices

  if (modus == 1){
    init_variables(1);
    substitute();

    msg("");
    msg("SUBSTITUTION FINISHED");
    msg("");
    msg ("maximum resident set size:                %12.2f MB",
      maximum_resident_set_size () / (double)(1<<20));
    msg ("used time for substitution:               %12.2f seconds",
      process_time());

    reset_substitute();

  } else {
    init_variables(0);
    assign_slices_to_var();
    init_slices();

    double slice_time = process_time();

    if (pac) {
      allocate_slicerem();
      allocate_pacrem();
      print_circuit_poly_to_file();
      print_spec_to_file();
    }



    multiply_slices();

    if(verbose >= 3) {
      msg("after sorting we received: ");
      print_circuit_poly();
    }



    if(elim) decomposing();

    double decomp_time = process_time() -  slice_time;

    if (elim) eliminating();
    double elim_time = process_time() - decomp_time  - slice_time;

    if(elim_print) {
      print_var_to_file();
      print_circuit_poly_to_file();
      print_spec_to_file();
    }

    // reduction
    if(incremental) reducing_inc();
    else reducing_non_inc();




    if(pac) add_up_slicerem();

    if(pac && modulo) correct_pp();
    double red_time = process_time() - elim_time - decomp_time  - slice_time;


    print_statistics (slice_time, decomp_time, elim_time, red_time);
    reset_all();
  }

  if (output_name) fclose(output_file);
  if (output_name2) fclose(output_file2);
  if (output_name3) fclose(output_file3);


  return 0;
}
