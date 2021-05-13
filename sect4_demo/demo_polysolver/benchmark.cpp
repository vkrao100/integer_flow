#include "includes/utilities.h"
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
    Hard code connections in the graph.
*/
void set_parents_and_children_demo () {
  // First the internal gates
  push_parents_and_children(gates[4], gates[0], gates[2]);
  push_parents_and_children(gates[5], gates[1], gates[2]);//2
  push_parents_and_children(gates[6], gates[0], gates[3]);
  push_parents_and_children(gates[7], gates[1], gates[3]);
  push_parents_and_children(gates[8], gates[5], gates[6]);//6
  push_parents_and_children(gates[9], gates[5], gates[6]);
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
    We initialize all gate constraints for our example.
*/
void init_gate_constraints_demo(){

  for(unsigned i = 0; i < num_gates; i++){
    std::cout << gates[i]->get_var_name() << std::endl;
    if(gates[i]->get_input()) continue;
    if(gates[i]->get_output()) set_output_poly(gates[i]);
    else if(gates[i]->get_xor_gate()) set_xor_poly(gates[i]);
    else set_and_poly(gates[i]);
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
