
#include "includes/polynomial.h"
int main(){

	Var * b3 = new Var("b3",8);
	Var * b2 = new Var("b2",7);
	Var * b1 = new Var("b1",6);
	Var * b0 = new Var("b0",5);
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
	add_to_vstack(a0);
	add_to_vstack(b2);
	Term * t_6117133888823689886 = build_term_from_stack();

	mpz_set_si(coeff,-4);
	Monomial * m_7855802229597246021 = new Monomial (coeff,t_6117133888823689886);

	add_to_vstack(a3);
	add_to_vstack(b1);
	Term * t_1563330330818004960 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_6388979807050616147 = new Monomial (coeff,t_1563330330818004960);

	push_mstack(m_7855802229597246021->copy());
	Polynomial * p_0 = build_poly();

	fprintf(stdout, "Multiplying mul_0 and p_0 yields:\n");
	Polynomial * mul_1 = multiply_poly(mul_0,p_0);
	mul_1->print(stdout);fprintf(stdout,"\n");
	delete(mul_0);delete(p_0);

	push_mstack(m_7855802229597246021->copy());
	push_mstack(m_6388979807050616147->copy());
	Polynomial * p_1 = build_poly();

	fprintf(stdout, "Multiplying mul_1 and p_1 yields:\n");
	Polynomial * mul_2 = multiply_poly(mul_1,p_1);
	mul_2->print(stdout);fprintf(stdout,"\n");
	delete(mul_1);delete(p_1);

	Polynomial * p_2 = build_poly();

	fprintf(stdout, "Multiplying mul_2 and p_2 yields:\n");
	Polynomial * mul_3 = multiply_poly(mul_2,p_2);
	mul_3->print(stdout);fprintf(stdout,"\n");
	delete(mul_2);delete(p_2);

	push_mstack(m_7855802229597246021->copy());
	Polynomial * p_3 = build_poly();

	fprintf(stdout, "Multiplying mul_3 and p_3 yields:\n");
	Polynomial * mul_4 = multiply_poly(mul_3,p_3);
	mul_4->print(stdout);fprintf(stdout,"\n");
	delete(mul_3);delete(p_3);

	if(mul_4 && !mul_4->is_constant_zero_poly())
		fprintf(stdout,"Non-zero remainder ! Rectification not possible !!\n");
	else
		fprintf(stdout,"Zero remainder ! Rectification possible !!\n");

	delete(mul_4);
	delete(m_7855802229597246021);
	delete(m_6388979807050616147);
	deallocate_terms();deallocate_mstack();mpz_clear(coeff);
	delete(b3);delete(a3);
	delete(b2);delete(a2);
	delete(b1);delete(a1);
	delete(b0);delete(a0);
	return 0;
}