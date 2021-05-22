
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
	add_to_vstack(b2);
	add_to_vstack(b1);
	add_to_vstack(b0);
	add_to_vstack(a2);
	add_to_vstack(a1);
	add_to_vstack(a0);
	Term * t_6469530634474749333 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_5233698020995952808 = new Monomial (coeff,t_6469530634474749333);

	add_to_vstack(b2);
	add_to_vstack(b1);
	add_to_vstack(a1);
	add_to_vstack(a0);
	Term * t_5932943219776413326 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_4058318797790044269 = new Monomial (coeff,t_5932943219776413326);

	add_to_vstack(b2);
	add_to_vstack(b0);
	add_to_vstack(a2);
	add_to_vstack(a0);
	Term * t_3990810492335340354 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_8511275704929516323 = new Monomial (coeff,t_3990810492335340354);

	add_to_vstack(b2);
	add_to_vstack(a1);
	Term * t_640136816885747316 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_4994155804219063187 = new Monomial (coeff,t_640136816885747316);

	add_to_vstack(b1);
	add_to_vstack(b0);
	add_to_vstack(a2);
	add_to_vstack(a1);
	Term * t_8023267112098009398 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_6242360946813005123 = new Monomial (coeff,t_8023267112098009398);

	add_to_vstack(b1);
	add_to_vstack(a2);
	Term * t_1640161816882747010 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_7994198804266063101 = new Monomial (coeff,t_1640161816882747010);

	mpz_set_ui(coeff,8);
	Monomial * m_5504033067049723 = new Monomial (coeff,0);

	mpz_set_ui(coeff,16);
	Monomial * m_6919845183466767589 = new Monomial (coeff,0);

	mpz_set_ui(coeff,24);
	Monomial * m_6919845183469767598 = new Monomial (coeff,0);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_0 = build_poly();

	fprintf(stdout, "Multiplying mul_0 and p_0 yields:\n");
	Polynomial * mul_1 = multiply_poly(mul_0,p_0);
	mul_1->print(stdout);fprintf(stdout,"\n");
	delete(mul_0);delete(p_0);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_1 = build_poly();

	fprintf(stdout, "Multiplying mul_1 and p_1 yields:\n");
	Polynomial * mul_2 = multiply_poly(mul_1,p_1);
	mul_2->print(stdout);fprintf(stdout,"\n");
	delete(mul_1);delete(p_1);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_2 = build_poly();

	fprintf(stdout, "Multiplying mul_2 and p_2 yields:\n");
	Polynomial * mul_3 = multiply_poly(mul_2,p_2);
	mul_3->print(stdout);fprintf(stdout,"\n");
	delete(mul_2);delete(p_2);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_3 = build_poly();

	fprintf(stdout, "Multiplying mul_3 and p_3 yields:\n");
	Polynomial * mul_4 = multiply_poly(mul_3,p_3);
	mul_4->print(stdout);fprintf(stdout,"\n");
	delete(mul_3);delete(p_3);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_4 = build_poly();

	fprintf(stdout, "Multiplying mul_4 and p_4 yields:\n");
	Polynomial * mul_5 = multiply_poly(mul_4,p_4);
	mul_5->print(stdout);fprintf(stdout,"\n");
	delete(mul_4);delete(p_4);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183469767598->copy());
	Polynomial * p_5 = build_poly();

	fprintf(stdout, "Multiplying mul_5 and p_5 yields:\n");
	Polynomial * mul_6 = multiply_poly(mul_5,p_5);
	mul_6->print(stdout);fprintf(stdout,"\n");
	delete(mul_5);delete(p_5);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_6 = build_poly();

	fprintf(stdout, "Multiplying mul_6 and p_6 yields:\n");
	Polynomial * mul_7 = multiply_poly(mul_6,p_6);
	mul_7->print(stdout);fprintf(stdout,"\n");
	delete(mul_6);delete(p_6);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183469767598->copy());
	Polynomial * p_7 = build_poly();

	fprintf(stdout, "Multiplying mul_7 and p_7 yields:\n");
	Polynomial * mul_8 = multiply_poly(mul_7,p_7);
	mul_8->print(stdout);fprintf(stdout,"\n");
	delete(mul_7);delete(p_7);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_8 = build_poly();

	fprintf(stdout, "Multiplying mul_8 and p_8 yields:\n");
	Polynomial * mul_9 = multiply_poly(mul_8,p_8);
	mul_9->print(stdout);fprintf(stdout,"\n");
	delete(mul_8);delete(p_8);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_9 = build_poly();

	fprintf(stdout, "Multiplying mul_9 and p_9 yields:\n");
	Polynomial * mul_10 = multiply_poly(mul_9,p_9);
	mul_10->print(stdout);fprintf(stdout,"\n");
	delete(mul_9);delete(p_9);

	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_7994198804266063101->copy());
	Polynomial * p_10 = build_poly();

	fprintf(stdout, "Multiplying mul_10 and p_10 yields:\n");
	Polynomial * mul_11 = multiply_poly(mul_10,p_10);
	mul_11->print(stdout);fprintf(stdout,"\n");
	delete(mul_10);delete(p_10);

	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_11 = build_poly();

	fprintf(stdout, "Multiplying mul_11 and p_11 yields:\n");
	Polynomial * mul_12 = multiply_poly(mul_11,p_11);
	mul_12->print(stdout);fprintf(stdout,"\n");
	delete(mul_11);delete(p_11);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_12 = build_poly();

	fprintf(stdout, "Multiplying mul_12 and p_12 yields:\n");
	Polynomial * mul_13 = multiply_poly(mul_12,p_12);
	mul_13->print(stdout);fprintf(stdout,"\n");
	delete(mul_12);delete(p_12);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183469767598->copy());
	Polynomial * p_13 = build_poly();

	fprintf(stdout, "Multiplying mul_13 and p_13 yields:\n");
	Polynomial * mul_14 = multiply_poly(mul_13,p_13);
	mul_14->print(stdout);fprintf(stdout,"\n");
	delete(mul_13);delete(p_13);

	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_14 = build_poly();

	fprintf(stdout, "Multiplying mul_14 and p_14 yields:\n");
	Polynomial * mul_15 = multiply_poly(mul_14,p_14);
	mul_15->print(stdout);fprintf(stdout,"\n");
	delete(mul_14);delete(p_14);

	push_mstack(m_4994155804219063187->copy());
	push_mstack(m_7994198804266063101->copy());
	push_mstack(m_6919845183466767589->copy());
	Polynomial * p_15 = build_poly();

	fprintf(stdout, "Multiplying mul_15 and p_15 yields:\n");
	Polynomial * mul_16 = multiply_poly(mul_15,p_15);
	mul_16->print(stdout);fprintf(stdout,"\n");
	delete(mul_15);delete(p_15);

	if(mul_16 && !mul_16->is_constant_zero_poly())
		fprintf(stdout,"Non-zero remainder ! Rectification not possible !!\n");
	else
		fprintf(stdout,"Zero remainder ! Rectification possible !!\n");

	delete(mul_16);
	delete(m_5233698020995952808);
	delete(m_4058318797790044269);
	delete(m_8511275704929516323);
	delete(m_4994155804219063187);
	delete(m_6242360946813005123);
	delete(m_7994198804266063101);
	delete(m_5504033067049723);
	delete(m_6919845183466767589);
	delete(m_6919845183469767598);
	deallocate_terms();deallocate_mstack();mpz_clear(coeff);
	delete(b3);delete(a3);
	delete(b2);delete(a2);
	delete(b1);delete(a1);
	delete(b0);delete(a0);
	return 0;
}