
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

	mpz_set_ui(coeff,8);
	Monomial * m_4293277043957353726 = new Monomial (coeff,t_6469530634474749333);

	add_to_vstack(b2);
	add_to_vstack(b1);
	add_to_vstack(a3);
	add_to_vstack(a2);
	Term * t_7932949219566412674 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_3636849635939613949 = new Monomial (coeff,t_7932949219566412674);

	add_to_vstack(b2);
	add_to_vstack(b1);
	add_to_vstack(a1);
	add_to_vstack(a0);
	Term * t_5932943219776413326 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_4058318797790044269 = new Monomial (coeff,t_5932943219776413326);

	add_to_vstack(b2);
	add_to_vstack(a2);
	Term * t_640136816885747313 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_976337456665232868 = new Monomial (coeff,t_640136816885747313);

	add_to_vstack(b1);
	add_to_vstack(a3);
	Term * t_1640161816882747009 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_23671543363767228 = new Monomial (coeff,t_1640161816882747009);

	mpz_set_ui(coeff,16);
	Monomial * m_5233698020995952808 = new Monomial (coeff,t_6469530634474749333->copy());

	add_to_vstack(b2);
	add_to_vstack(b0);
	add_to_vstack(a2);
	add_to_vstack(a0);
	Term * t_3990810492335340354 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_8511275704929516323 = new Monomial (coeff,t_3990810492335340354);

	add_to_vstack(b1);
	add_to_vstack(b0);
	add_to_vstack(a2);
	add_to_vstack(a1);
	Term * t_8023267112098009398 = build_term_from_stack();

	mpz_set_si(coeff,-8);
	Monomial * m_6242360946813005123 = new Monomial (coeff,t_8023267112098009398);

	mpz_set_ui(coeff,8);
	Monomial * m_5504033067049723 = new Monomial (coeff,0);

	push_mstack(m_4293277043957353726->copy());
	push_mstack(m_3636849635939613949->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_976337456665232868->copy());
	push_mstack(m_23671543363767228->copy());
	Polynomial * p_0 = build_poly();

	fprintf(stdout, "Multiplying mul_0 and p_0 yields:\n");
	Polynomial * mul_1 = multiply_poly(mul_0,p_0);
	mul_1->print(stdout);fprintf(stdout,"\n");
	delete(mul_0);delete(p_0);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_3636849635939613949->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_976337456665232868->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_23671543363767228->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_1 = build_poly();

	fprintf(stdout, "Multiplying mul_1 and p_1 yields:\n");
	Polynomial * mul_2 = multiply_poly(mul_1,p_1);
	mul_2->print(stdout);fprintf(stdout,"\n");
	delete(mul_1);delete(p_1);

	push_mstack(m_4293277043957353726->copy());
	push_mstack(m_4058318797790044269->copy());
	Polynomial * p_2 = build_poly();

	fprintf(stdout, "Multiplying mul_2 and p_2 yields:\n");
	Polynomial * mul_3 = multiply_poly(mul_2,p_2);
	mul_3->print(stdout);fprintf(stdout,"\n");
	delete(mul_2);delete(p_2);

	push_mstack(m_5233698020995952808->copy());
	push_mstack(m_4058318797790044269->copy());
	push_mstack(m_8511275704929516323->copy());
	push_mstack(m_6242360946813005123->copy());
	push_mstack(m_5504033067049723->copy());
	Polynomial * p_3 = build_poly();

	fprintf(stdout, "Multiplying mul_3 and p_3 yields:\n");
	Polynomial * mul_4 = multiply_poly(mul_3,p_3);
	mul_4->print(stdout);fprintf(stdout,"\n");
	delete(mul_3);delete(p_3);

	fprintf(stdout,"Final rectification check mul done !! \n");

	delete(mul_4);
	delete(m_4293277043957353726);
	delete(m_3636849635939613949);
	delete(m_4058318797790044269);
	delete(m_976337456665232868);
	delete(m_23671543363767228);
	delete(m_5233698020995952808);
	delete(m_8511275704929516323);
	delete(m_6242360946813005123);
	delete(m_5504033067049723);
	deallocate_terms();deallocate_mstack();mpz_clear(coeff);
	delete(b3);delete(a3);
	delete(b2);delete(a2);
	delete(b1);delete(a1);
	delete(b0);delete(a0);
	return 0;
}