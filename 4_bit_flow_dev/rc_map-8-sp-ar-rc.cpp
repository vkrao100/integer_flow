
#include "includes/polynomial.h"
int main(){

	Var * b7 = new Var("b7",16);
	Var * b6 = new Var("b6",15);
	Var * b5 = new Var("b5",14);
	Var * b4 = new Var("b4",13);
	Var * b3 = new Var("b3",12);
	Var * b2 = new Var("b2",11);
	Var * b1 = new Var("b1",10);
	Var * b0 = new Var("b0",9);
	Var * a7 = new Var("a7",8);
	Var * a6 = new Var("a6",7);
	Var * a5 = new Var("a5",6);
	Var * a4 = new Var("a4",5);
	Var * a3 = new Var("a3",4);
	Var * a2 = new Var("a2",3);
	Var * a1 = new Var("a1",2);
	Var * a0 = new Var("a0",1);
	mpz_t coeff;
	mpz_init_set_ui(coeff,1);

	mpz_set_ui(coeff,1);
	Monomial * m_6272018864 = new Monomial (coeff,0);

	push_mstack(m_6272018864->copy());
	Polynomial * mul_0 = build_poly();
	Polynomial * p_0 = build_poly();

	fprintf(stdout, "Multiplying mul_0 and p_0 yields:\n");
	Polynomial * mul_1 = multiply_poly(mul_0,p_0);
	mul_1->print(stdout);fprintf(stdout,"\n");
	delete(mul_0);delete(p_0);

	Polynomial * p_1 = build_poly();

	fprintf(stdout, "Multiplying mul_1 and p_1 yields:\n");
	Polynomial * mul_2 = multiply_poly(mul_1,p_1);
	mul_2->print(stdout);fprintf(stdout,"\n");
	delete(mul_1);delete(p_1);

	if(mul_2 && !mul_2->is_constant_zero_poly())
		fprintf(stdout,"Non-zero remainder ! Rectification not possible !!\n");
	else
		fprintf(stdout,"Zero remainder ! Rectification possible !!\n");

	delete(mul_2);
	deallocate_terms();deallocate_mstack();mpz_clear(coeff);
	delete(b7);delete(a7);
	delete(b6);delete(a6);
	delete(b5);delete(a5);
	delete(b4);delete(a4);
	delete(b3);delete(a3);
	delete(b2);delete(a2);
	delete(b1);delete(a1);
	delete(b0);delete(a0);
	return 0;
}