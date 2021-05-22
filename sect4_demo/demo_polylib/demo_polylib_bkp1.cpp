/*------------------------------------------------------------------------*/
/*! \file demo_polylib.cpp
    \brief Demonstrantes the standalone usage of the polynomial library
    of AMulet2

  Copyright (C) 2020 Daniela Kaufmann, Johannes Kepler University Linz
*/
/*------------------------------------------------------------------------*/

/*------------------------------------------------------------------------*/
#include "includes/polynomial.h"
/**
    Main Function.
    We generate some polynomials to demonstrate the use case of
    the polynomial library.
*/
int main () {
// First we allocate variables and assign the order,
  Var * x = new Var("b1", 2);
  Var * y = new Var("a0", 1);

// Then we start to build some terms.
  //x
  add_to_vstack(x);
  Term * t_x = build_term_from_stack();

  //x*y
  add_to_vstack(x);
  add_to_vstack(y);
  Term * t_xy = build_term_from_stack();

// From terms we generate Monomials
  mpz_t coeff;

  mpz_init_set_ui(coeff, 1);

  mpz_set_si(coeff, -2);
  Monomial * m1 = new Monomial (coeff, t_xy);

  mpz_set_si(coeff, -2);
  Monomial * m2 = new Monomial (coeff, t_xy->copy());
  // Here we need a copy of the term, because we used it a second time

  mpz_set_ui(coeff, 2);
  Monomial * m3 = new Monomial (coeff, 0);

// Let us start to generate polynomials
  push_mstack(m1->copy());
  Polynomial * p = build_poly();

  push_mstack(m2->copy());
  push_mstack(m3->copy());
  Polynomial * q = build_poly();

  fprintf(stdout, "Following polynomials are generated:\n");
  fprintf(stdout, "p: "); p->print(stdout);
  fprintf(stdout, "q: "); q->print(stdout);
  fprintf(stdout, "\n");

  fprintf(stdout, "Adding p and q yields:\n");
  Polynomial * add = add_poly(p, q);
  fprintf(stdout, "p+q: "); add->print(stdout);
  fprintf(stdout, "\n");
  delete(add);

  fprintf(stdout, "Multiplying p and q yields:\n");
  Polynomial * mul = multiply_poly(p, q);
  fprintf(stdout, "p*q: "); mul->print(stdout);
  fprintf(stdout, "\n");
  delete(mul);

  fprintf(stdout, "Multiplying q by 6 yields:\n");
  mpz_set_ui(coeff, 6);
  Polynomial * mulc = multiply_poly_with_constant(q, coeff);
  fprintf(stdout, "6*q: "); mulc->print(stdout);
  fprintf(stdout, "\n");
  delete(mulc);

  fprintf(stdout, "Dividing p by x yields:\n");
  Polynomial * div = divide_by_term(p, t_x);
  fprintf(stdout, "p/x: "); div->print(stdout);
  fprintf(stdout, "\n");
  delete(p);
  delete(div);

  // Deletion of objects
  delete(q);

  delete(m1);
  delete(m2);
  delete(m3);

  deallocate_terms();
  deallocate_mstack ();
  mpz_clear(coeff);

  delete(x);
  delete(y);


  return 0;
}
