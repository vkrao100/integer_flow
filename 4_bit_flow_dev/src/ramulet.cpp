/*------------------------------------------------------------------------*/
/*! \file amulet.cpp
    \brief main file of our tool AMulet2

  Part of AMulet2.1 : AIG Multiplier Verification Tool.
  Copyright(C) 2020 Daniela Kaufmann, Johannes Kepler University Linz
*/
/*------------------------------------------------------------------------*/
#define VERSION "2.1"
/*------------------------------------------------------------------------*/
// / Manual of AMulet2, will be printed with command line '-h'
static const char * USAGE =
"\n"
"### USAGE ###\n"
"usage : amulet2 <mode> <input.aig> <output files> [<option> ...] \n"
"\n"
"Depending on the <mode> the <output files> and <options> have to be set:"
"\n"
"\n"
"<mode> = -substitute:\n"
"    <output files> =  2 output files passed in the following order \n"
"      <out.cnf>:        CNF miter for correctness of adder substitution \n"
"      <out.aig>:        rewritten aiger is stored in this file \n"
"\n"
"    <option> = the following options are available \n"
"      -h | --help       print this command line summary \n"
"      -v<1,2,3,4>       different levels of verbosity(see below) \n"
"      -signed           option for non-negative integer multipliers \n"
"\n"
"\n"
"<mode> = -verify:\n"
"    <output files> =  no output files are required \n"
"     \n "
"    <option> = the following options are available \n"
"       -h | --help           print this command line summary \n"
"       -v<1,2,3,4>           different levels of verbosity(default -v1) \n"
"       -signed               option for non-negative integer multipliers \n"
"       -no-counter-examples  do not generate and write counter examples\n"
"     \n"
"     \n"
"<mode> = -rectify:\n"
"    <output files> =  1 \n"
"       <out.cofac>:      generated remainders for each cofactor assignment \n"
"     \n "
"    <option> = the following options are available \n"
"       -T                    Number of targets to perform rectification in (yet to implement)\n"
"       -h | --help           print this command line summary \n"
"       -v<1,2,3,4>           different levels of verbosity(default -v1) \n"
"     \n"
"     \n"
"<mode> = -certify:\n"
"    <output files> =  3 output files passed in the following order\n"
"      <out.polys>:      initial polynomial set \n"
"      <out.proof>:      proof rules \n"
"      <out.spec> :      spec which should be checked \n"
"     \n "
"    <option> = the following options are available \n"
"       -h | --help      print this command line summary \n"
"       -v<1,2,3,4>      different levels of verbosity(default -v1) \n"
"       -signed          option for non-negative integer multipliers \n"
"       -no-counter-examples  do not generate and write counter examples\n"
"\n"
"       -p1          expanded proof \n"
"       -p2          middle condensed proof(some linear combinations occur, default)\n"
"       -p3          condensed proof(one single linear combination)\n";
/*------------------------------------------------------------------------*/
#include "parser.h"
#include "substitution_engine.h"
#include "polynomial_solver.h"
/*------------------------------------------------------------------------*/
// / Name of the input file
static const char * input_name = 0;

// / \brief
// / Name of first output file, which stores the CNF miter in '-substitute', 
// / the gate constraints in '-certify'.
// / the remainders generated in '-rectify'
static const char * output_name1 = 0;

// / \brief
// / Name of second output file, storing the rewritten AIG in '-substitute',
// / and the core proof in '-certify'.
static const char * output_name2 = 0;

// / Name of third output file. Stores the specification in '-certify'.
static const char * output_name3 = 0;

// / Selected mode, '-substitute' = 1, '-verify' = 2, '-certify' = 3
static int mode;
/*------------------------------------------------------------------------*/
/**
    Calls the deallocaters of the involved data types
    @see reset_all_signal_handlers()
    @see delete_gates()
    @see deallocate_terms()
    @see deallocate_mstack()
    @see clear_mpz()
*/
static void reset_all() {
  reset_all_signal_handlers();
  delete_gates();
  deallocate_terms();
  deallocate_mstack();
  clear_mpz();
}
/*------------------------------------------------------------------------*/
/**
    Main Function of AMulet2.
    Reads the given AIG and depending on the selected mode, either
    calls the substution engine or the polynomial solver.

    Prints statistics to stdout after finishing.
*/
int main(int argc, char ** argv) {
  msg("AMulet Version " VERSION);
  msg("Aiger multiplier examination tool");
  msg("Copyright(C) 2020, Daniela Kaufmann, Johannes Kepler University Linz");

  for (int i = 1; i < argc; i++) {
    if (!strcmp(argv[i], "-h") ||
    !strcmp(argv[i], "--help")) {
      fputs(USAGE, stdout);
      fflush(stdout);
      exit(0);
    } else if (!strcmp(argv[i], "-v0")) { verbose = 0;
    } else if (!strcmp(argv[i], "-v1")) { verbose = 1;
    } else if (!strcmp(argv[i], "-v2")) { verbose = 2;
    } else if (!strcmp(argv[i], "-v3")) { verbose = 3;
    } else if (!strcmp(argv[i], "-v4")) { verbose = 4;
    } else if (!strcmp(argv[i], "-substitute")) {
      if (!mode) {
        msg("selected mode: adder substitution");
        mode = 1;
      } else {
        die("mode has alreday been selected(try '-h')");
      }
    } else if (!strcmp(argv[i], "-verify")) {
      if (!mode) {
        msg("selected mode: verification");
        mode = 2;
      } else {
        die("mode has alreday been selected(try '-h')");
      }
    } else if (!strcmp(argv[i], "-certify")) {
      if (!mode) {
        msg("selected mode: verification + certificates");
        mode = 3;
      } else {
        die("mode has alreday been selected(try '-h')");
      }
    } else if (!strcmp(argv[i], "-rectify")) {
      if (!mode) {
        msg("selected mode: rectification check");
        mode = 4;
      } else {
        die("mode has alreday been selected(try '-h')");
      }
    } else if (!strcmp(argv[i], "-p1")) {
      if (proof) die("too many proof formats selected(try '-h')");
      proof = 1;
    } else if (!strcmp(argv[i], "-p2")) {
      if (proof) die("too many proof formats selected(try '-h')");
      proof = 2;
    } else if (!strcmp(argv[i], "-p3")) {
      if (proof) die("too many proof formats selected(try '-h')");
      proof = 3;
    } else if (!strcmp(argv[i], "-signed")) {
      signed_mult = 1;
    } else if (!strcmp(argv[i], "-no-counter-examples")) {
      gen_witness = 0;
    } else if (output_name3) {
      die("too many arguments '%s', '%s', '%s', '%s' and '%s'(try '-h')",
        input_name, output_name1, output_name2, output_name3, argv[i]);
    } else if (output_name2) { output_name3 = argv[i];
    } else if (output_name1) { output_name2 = argv[i];
    } else if (input_name) { output_name1 = argv[i];
    } else {
      input_name = argv[i];
    }
  }

  if (!mode) die("select mode(try -h for more information)");
  if (!input_name)  die("no input file given(try '-h')");
  if (mode == 1) {
    if (output_name3)
      die("too many arguments '%s', '%s', '%s' and '%s'(try '-h')",
    input_name, output_name1, output_name2, output_name3);
    if (!output_name2) die("too few arguments(try '-h')");
    if (proof) {
      msg("option -p1, -p2 or -p3 are only possible in -certify");
      msg("and will be ignored");
    }
    proof = 0;
  } else if (mode == 2) {
    if (output_name1) die("too many arguments(try '-h')");
    if (proof) {
      msg("option -p1, -p2 or -p3 are only possible in -certify");
      msg("and will be ignored");
    }
    proof = 0;
  } else if (mode == 3) {
    if (!output_name3) die("too few arguments(try '-h')");
    if (!proof) proof = 2;
    if (proof == 3) msg("proof condensed level: high");
    else if (proof == 2) msg("proof condensed level: medium");
    else
      msg("proof condensed level: expanded");
  } else if (mode == 4) {
    if (!output_name1) die("too few arguments(try '-h')");
    if (proof) {
      msg("option -p1, -p2 or -p3 are only possible in -certify");
      msg("and will be ignored");
    }
    proof = 0;
  }

  init_all_signal_handers();
  init_nonces();

  parse_aig(input_name);

  if (mode == 1) {
    init_gate_substitution();
    substitution(output_name1, output_name2);
  } else if (mode == 4) {
    init_gates_verify();
    verify(input_name, output_name1, output_name2, output_name3, mode == 3, mode == 4);
  } else {
    init_gates_verify();
    verify(input_name, output_name1, output_name2, output_name3, mode == 3, mode == 4);
  }

  reset_aig_parsing();
  reset_all();

  reset_time = process_time();
  print_statistics(mode);

  return 0;
}
