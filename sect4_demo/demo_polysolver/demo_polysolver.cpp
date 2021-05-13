/*------------------------------------------------------------------------*/
/*! \file demo_polysolver.cpp
    \brief Demonstrantes the standalone usage of the polynomial solver
    of AMulet2 for a multiplier, which is not given as an AIG, but as a
    gate netlist

  Copyright (C) 2020 Daniela Kaufmann, Johannes Kepler University Linz
*/
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
#include "includes/polynomial_solver.h"


/**
    We define the number of input bits, outputs and maximum variables
*/
void set_constants_demo(){
  a0 = 0;
  al = 1;
  ainc = 1;

  b0 = 2;
  bl = 3;
  binc = 1;

  int internal = 8;         // number of internal gates
  NN = 4;                   // outputs num
  M = NN + internal + 1;    // maxvar +1
}

/*------------------------------------------------------------------------*/
/**
    Hard code the XOR gates.
*/
void set_xor_demo(){
  gates[8]->set_xor_gate(1);
  gates[9]->set_xor_gate(1);
  gates[10]->set_xor_gate(1);
};

/*------------------------------------------------------------------------*/
/**
    Hard code the outputs.
*/
void mark_aig_outputs_demo(){
  gates[4]->mark_aig_output();
  gates[8]->mark_aig_output();
  gates[10]->mark_aig_output();
  gates[11]->mark_aig_output();
}

/*------------------------------------------------------------------------*/

/**
    We include 'lchild' and 'rchild' as children of 'parent' and
    include 'parent' as a parent of 'lchild' and 'rchild'.
    Furthermore we adjust the level of the children
    and mark the partial products.
    Used for all internal gates of the circuit.
*/
void push_parents_and_children(Gate * parent, Gate * lchild, Gate * rchild){

  parent->children_push_back(lchild);
  parent->children_push_back(rchild);
  lchild->parents_push_back(parent);
  rchild->parents_push_back(parent);

  parent->set_level(lchild->get_level() > rchild->get_level() ?
               lchild->get_level()+1 : rchild->get_level()+1);

  if(lchild->get_input() && rchild->get_input()) {
     parent->mark_pp();
     if (verbose >= 4) msg("partial product %s", parent->get_var_name());
  }
}

/**
    We include 'child' and 'rchild' as child of 'parent' and
    include 'parent' as a parent of 'child'.
    Used for extra added output bits s_i
*/
/*------------------------------------------------------------------------*/
void push_parents_and_children_output(Gate * parent, Gate * child){
  parent->children_push_back(child);
  child->parents_push_back(parent);
}

/*------------------------------------------------------------------------*/
/**
    Hard code connections in the graph.
*/
void set_parents_and_children_demo () {
  // First the internal gates
  push_parents_and_children(gates[4], gates[0], gates[2]);
  push_parents_and_children(gates[5], gates[1], gates[2]);
  push_parents_and_children(gates[6], gates[0], gates[3]);
  push_parents_and_children(gates[7], gates[1], gates[3]);
  push_parents_and_children(gates[8], gates[5], gates[6]);
  push_parents_and_children(gates[9], gates[5], gates[7]);//6
  push_parents_and_children(gates[10], gates[7], gates[9]);
  push_parents_and_children(gates[11], gates[7], gates[9]);

  // Add outputs
  push_parents_and_children_output(gates[12], gates[4]);
  push_parents_and_children_output(gates[13], gates[8]);
  push_parents_and_children_output(gates[14], gates[10]);
  push_parents_and_children_output(gates[15], gates[11]);
}

/*------------------------------------------------------------------------*/
/**
    Sets the output poly "-n + x"
*/
void set_output_poly(Gate *n){
  Gate * child = n->children_front();

  const Var * v = n->get_var();
  Term * t1 = new_term(v, 0);
  Monomial * m1 = new Monomial(minus_one, t1);

  Polynomial * p  = positive_poly(child->get_var());

  p->mon_push_front(m1);
  n->set_gate_constraint(p);
}

/*------------------------------------------------------------------------*/
/**
    Sets the  xor poly "-n - 2xy +x +y"
*/
void set_xor_poly (Gate *n){
  Gate * lchild = n->children_front();
  Gate * rchild = n->children_back();

  const Var * v = n->get_var();
  Term * t1 = new_term(v, 0);
  Monomial * m1 = new Monomial(minus_one, t1);
  push_mstack_end(m1);

  mpz_t minus_two;
  add_to_vstack(rchild->get_var());
  add_to_vstack(lchild->get_var());
  Term * t2 = build_term_from_stack();
  mpz_init_set_si(minus_two, -2);
  Monomial * m2 = new Monomial(minus_two, t2);
  push_mstack_end(m2);
  mpz_clear(minus_two);

  Term * t3 = new_term(rchild->get_var(), 0);
  Monomial * m3 = new Monomial(one, t3);
  push_mstack_end(m3);

  Term * t4 = new_term(lchild->get_var(), 0);
  Monomial * m4 = new Monomial(one, t4);
  push_mstack_end(m4);

  Polynomial * p  = build_poly();
  n->set_gate_constraint(p);
}

/*------------------------------------------------------------------------*/
/**
    Sets the and poly "-n + xy"
*/
void set_and_poly (Gate *n){
  Gate * lchild = n->children_front();
  Gate * rchild = n->children_back();

  const Var * v = n->get_var();
  Term * t1 = new_term(v, 0);
  Monomial * m1 = new Monomial(minus_one, t1);
  push_mstack_end(m1);

  add_to_vstack(rchild->get_var());
  add_to_vstack(lchild->get_var());

  Term * t2 = build_term_from_stack();
  Monomial * m2 = new Monomial(one, t2);
  push_mstack_end(m2);

  Polynomial * p  = build_poly();
  n->set_gate_constraint(p);

}

/*------------------------------------------------------------------------*/
/**
    We initialize all gate constraints for our example.
*/
void init_gate_constraints_demo(){

  for(unsigned i = 0; i < num_gates; i++){
    if(gates[i]->get_input()) continue;
    if(gates[i]->get_output()) set_output_poly(gates[i]);
    else if(gates[i]->get_xor_gate()) set_xor_poly(gates[i]);
    else set_and_poly(gates[i]);
    //gates[i]->print_gate_constraint(stdout);
  }
}
/*------------------------------------------------------------------------*/

/**
    Main Function.
    In this demo we want to demonstrate how the polynomial solver can be used
    to verify a multiplier given as a gate netlist.

    We hard coded the gate netlist in the demo.
*/
int main (int argc, char ** argv) {
  for (int i = 1; i < argc; i++) {
    if (!strcmp (argv[i], "-v0")) verbose = 0;
    else if (!strcmp (argv[i], "-v1")) verbose = 1;
    else if (!strcmp (argv[i], "-v2")) verbose = 2;
    else if (!strcmp (argv[i], "-v3")) verbose = 3;
    else if (!strcmp (argv[i], "-v4")) verbose = 4;
  }

  /*
  Before we can use the function verify() of the polynomial_solver, we
  have to provide the necessary information to the gate library.

  Functions with suffic '_demo' are implemented in this file and
  mimic functions implemented in the gate library.
  We cannot directly use the functions of the gate library, as these functions
  rely on the input being an AIG and our example works on a gate netlist.

  Functions without suffix '_demo' are taken from the gate library.
  */
  set_constants_demo();
  init_mpz(NN);
  allocate_gates(0);
  set_xor_demo();
  mark_aig_outputs_demo();
  set_parents_and_children_demo();
  init_gate_constraints_demo();


  // After the gates are allocated we call the main function 'verify()' of
  // the polynomial solver.
  verify();

  // Reset functions are taken from the library.
  delete_gates();
  deallocate_terms();
  deallocate_mstack ();
  clear_mpz();

  return 0;
}
