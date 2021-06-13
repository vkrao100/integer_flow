
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
	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2611624328016273833 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_9104664561816002391 = new Monomial (coeff,t_2611624328016273833);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_681049529973207495 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_1568957090038920995 = new Monomial (coeff,t_681049529973207495);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8768428740761439507 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_9214303397039452427 = new Monomial (coeff,t_8768428740761439507);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_6089807796527444597 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_6586757166925088833 = new Monomial (coeff,t_6089807796527444597);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_456533563257397795 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_50311341388553175 = new Monomial (coeff,t_456533563257397795);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_4829257969957936094 = build_term_from_stack();

	mpz_set_ui(coeff,24576);
	Monomial * m_5625928222391316353 = new Monomial (coeff,t_4829257969957936094);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_6541345456603303725 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3488540307060008778 = new Monomial (coeff,t_6541345456603303725);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2681052928177050821 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_7417194704702560909 = new Monomial (coeff,t_2681052928177050821);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3071830257606997755 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_8396024892905481551 = new Monomial (coeff,t_3071830257606997755);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_3045953079325152721 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_4666853960958055022 = new Monomial (coeff,t_3045953079325152721);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3236074715482054879 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_3140360740260629205 = new Monomial (coeff,t_3236074715482054879);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2754558199448891186 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_2650580220032812225 = new Monomial (coeff,t_2754558199448891186);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_6541345456603303728 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_5489281966339621713 = new Monomial (coeff,t_6541345456603303728);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_107741999155978047 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_4155826145754657936 = new Monomial (coeff,t_107741999155978047);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_71787257553997839 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_739472552794898846 = new Monomial (coeff,t_71787257553997839);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_4469670043089720508 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_7462373664099153630 = new Monomial (coeff,t_4469670043089720508);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_2759165082044667638 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_7825371027181840881 = new Monomial (coeff,t_2759165082044667638);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_8541351456645303856 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_1083044369228433508 = new Monomial (coeff,t_8541351456645303856);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_1681054529976207536 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_5739981342729944954 = new Monomial (coeff,t_1681054529976207536);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5089782796528444750 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_7408912328830731 = new Monomial (coeff,t_5089782796528444750);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_318959470049792457 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_1861935524217380098 = new Monomial (coeff,t_318959470049792457);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7761360115504651052 = build_term_from_stack();

	mpz_set_si(coeff,-24576);
	Monomial * m_8909805348912853595 = new Monomial (coeff,t_7761360115504651052);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2866077312521016635 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_3870552654796361874 = new Monomial (coeff,t_2866077312521016635);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_611618328222274370 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_2741047417897221736 = new Monomial (coeff,t_611618328222274370);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5279134829206275679 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_7163678312255027900 = new Monomial (coeff,t_5279134829206275679);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1693442393873651182 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_6992774097515625429 = new Monomial (coeff,t_1693442393873651182);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7632211146072868209 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_2670866737757992469 = new Monomial (coeff,t_7632211146072868209);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_611618328222274369 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7937048880004429718 = new Monomial (coeff,t_611618328222274369);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_5059554921032815778 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_6743573970143616533 = new Monomial (coeff,t_5059554921032815778);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_6386052088407562569 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_6883336518534669728 = new Monomial (coeff,t_6386052088407562569);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_3759170082047667618 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_1752332034185600136 = new Monomial (coeff,t_3759170082047667618);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_9060648985256989218 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_116726481530330107 = new Monomial (coeff,t_9060648985256989218);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_7916449626220234863 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_4193699172766922093 = new Monomial (coeff,t_7916449626220234863);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_2635270704345542041 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_1580496222781227278 = new Monomial (coeff,t_2635270704345542041);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_2866077312521016636 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_1140914777391298966 = new Monomial (coeff,t_2866077312521016636);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_5059554921032815779 = build_term_from_stack();

	mpz_set_si(coeff,-61440);
	Monomial * m_8377361506281704071 = new Monomial (coeff,t_5059554921032815779);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_4252842553780650251 = build_term_from_stack();

	mpz_set_si(coeff,-40960);
	Monomial * m_572882281871596335 = new Monomial (coeff,t_4252842553780650251);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_693449393874651014 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_5990615793266922572 = new Monomial (coeff,t_693449393874651014);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_2754558199448891185 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_2334894414316945515 = new Monomial (coeff,t_2754558199448891185);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_388386671780725612 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_1935060568134522444 = new Monomial (coeff,t_388386671780725612);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_6386052088407562568 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_3276538441069737238 = new Monomial (coeff,t_6386052088407562568);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_6386052088407562570 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_6883336518534669725 = new Monomial (coeff,t_6386052088407562570);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_8386090088449562473 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_883286518456669768 = new Monomial (coeff,t_8386090088449562473);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_611618328222274371 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_8878684525911869203 = new Monomial (coeff,t_611618328222274371);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	Term * t_8386090088449562472 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_2059620518000915593 = new Monomial (coeff,t_8386090088449562472);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_6010199710189351794 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_8753504022126224320 = new Monomial (coeff,t_6010199710189351794);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2543573437307603057 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_4417424195299696389 = new Monomial (coeff,t_2543573437307603057);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_133933687467983321 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_3532315163485605168 = new Monomial (coeff,t_133933687467983321);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_3178894039424600433 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_6878098574075051597 = new Monomial (coeff,t_3178894039424600433);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3059524921030815951 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_7190082918267157529 = new Monomial (coeff,t_3059524921030815951);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_466280008278543046 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_5452550683656795250 = new Monomial (coeff,t_466280008278543046);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_1289254650531850432 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_6450754892630604493 = new Monomial (coeff,t_1289254650531850432);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_1071792257556997824 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_260540447448101793 = new Monomial (coeff,t_1071792257556997824);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_1370199905199536656 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3927319967144557343 = new Monomial (coeff,t_1370199905199536656);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_318959470049792459 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_1861935524217380096 = new Monomial (coeff,t_318959470049792459);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3466291008267543001 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_6452559683687795307 = new Monomial (coeff,t_3466291008267543001);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_4059549921029815800 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_535652293032991979 = new Monomial (coeff,t_4059549921029815800);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_6994595977746891905 = build_term_from_stack();

	mpz_set_ui(coeff,53248);
	Monomial * m_1589022010305071550 = new Monomial (coeff,t_6994595977746891905);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_9082079359442843095 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7562234897842223108 = new Monomial (coeff,t_9082079359442843095);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_4289297650840851124 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_5685959495889184258 = new Monomial (coeff,t_4289297650840851124);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2372184181075076458 = build_term_from_stack();

	mpz_set_ui(coeff,40960);
	Monomial * m_5493587513535795526 = new Monomial (coeff,t_2372184181075076458);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_3635235704044541548 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_8977416623760607542 = new Monomial (coeff,t_3635235704044541548);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_388386671780725611 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_8937053880007429666 = new Monomial (coeff,t_388386671780725611);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2846092426516889542 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_402363273204887410 = new Monomial (coeff,t_2846092426516889542);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_7541354456626303743 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_6489290966298621602 = new Monomial (coeff,t_7541354456626303743);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_2635270704345542042 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_7973192114357579702 = new Monomial (coeff,t_2635270704345542042);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_543479436985602848 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_225667655814964405 = new Monomial (coeff,t_543479436985602848);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_6187003121582297284 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_891254232242817161 = new Monomial (coeff,t_6187003121582297284);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_681049529973207494 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_2861944524240380115 = new Monomial (coeff,t_681049529973207494);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_660959728771807864 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_599412949207405853 = new Monomial (coeff,t_660959728771807864);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5694483653357011742 = build_term_from_stack();

	mpz_set_ui(coeff,53248);
	Monomial * m_1093555934268442245 = new Monomial (coeff,t_5694483653357011742);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_318959470049792460 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_4056325404925559158 = new Monomial (coeff,t_318959470049792460);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_6916452626457235519 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_1224550214727448670 = new Monomial (coeff,t_6916452626457235519);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_466280008278543045 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_6417740282678023986 = new Monomial (coeff,t_466280008278543045);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2314734745300005152 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7319616456320007435 = new Monomial (coeff,t_2314734745300005152);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b5);
	Term * t_1660920728514807472 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_4918716186160845573 = new Monomial (coeff,t_1660920728514807472);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_9060648985256989217 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_1059615517997915616 = new Monomial (coeff,t_9060648985256989217);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1892264000822021891 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_1844159854003341578 = new Monomial (coeff,t_1892264000822021891);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_8541351456645303855 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7489287966317621650 = new Monomial (coeff,t_8541351456645303855);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3314823745811005896 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_6366604841396425560 = new Monomial (coeff,t_3314823745811005896);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8366472730359676608 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_8153864921644340982 = new Monomial (coeff,t_8366472730359676608);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3371003392810932310 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_1127757844635480951 = new Monomial (coeff,t_3371003392810932310);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8232124745548492030 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_6142923651108595564 = new Monomial (coeff,t_8232124745548492030);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_129530511877267514 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7100692068131394299 = new Monomial (coeff,t_129530511877267514);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_6371014392607931754 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_347731813756299781 = new Monomial (coeff,t_6371014392607931754);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7707724548072529286 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_3205615482296837930 = new Monomial (coeff,t_7707724548072529286);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_4707713548019529210 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_4931829372832396455 = new Monomial (coeff,t_4707713548019529210);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_1926395264841173534 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_5318467113261106043 = new Monomial (coeff,t_1926395264841173534);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7265285772711338870 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_5977655840781114254 = new Monomial (coeff,t_7265285772711338870);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_6482719227796732235 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4934179971783772946 = new Monomial (coeff,t_6482719227796732235);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_304906389435672994 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_464208403945311855 = new Monomial (coeff,t_304906389435672994);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2923234991114553072 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4205794560872338757 = new Monomial (coeff,t_2923234991114553072);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_8964013845923819438 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7934158971516772419 = new Monomial (coeff,t_8964013845923819438);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8620188831993563447 = build_term_from_stack();

	mpz_set_si(coeff,-256);
	Monomial * m_371391210835972229 = new Monomial (coeff,t_8620188831993563447);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_1493350322507606324 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_477932723891432870 = new Monomial (coeff,t_1493350322507606324);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_5385742027194771562 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_6998966950683614089 = new Monomial (coeff,t_5385742027194771562);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2356616159307131802 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4822478912074424257 = new Monomial (coeff,t_2356616159307131802);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_30107949926964783 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_5486436016943975781 = new Monomial (coeff,t_30107949926964783);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6341726928903719036 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_7976338658889874130 = new Monomial (coeff,t_6341726928903719036);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_76776008938447068 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7205837560925338665 = new Monomial (coeff,t_76776008938447068);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_4998648586607407508 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_5560852074695054177 = new Monomial (coeff,t_4998648586607407508);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_2790426954053954291 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_3343657216887153682 = new Monomial (coeff,t_2790426954053954291);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_4525116919213147589 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2328689697472814017 = new Monomial (coeff,t_4525116919213147589);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_638510783380778711 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3173051697569003901 = new Monomial (coeff,t_638510783380778711);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_1493350322507606325 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_1753543314265943773 = new Monomial (coeff,t_1493350322507606325);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_6705172365350803656 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_7699326369260505364 = new Monomial (coeff,t_6705172365350803656);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_6942478116495498510 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_7400973548215009750 = new Monomial (coeff,t_6942478116495498510);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_4484476222046087543 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_7754315062558928136 = new Monomial (coeff,t_4484476222046087543);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_4718789042317580291 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_7752626047462534669 = new Monomial (coeff,t_4718789042317580291);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_4636266504073349358 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1030730963040328462 = new Monomial (coeff,t_4636266504073349358);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_7729547518900561764 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2620594034141876992 = new Monomial (coeff,t_7729547518900561764);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_7329123895943991064 = build_term_from_stack();

	mpz_set_si(coeff,-96);
	Monomial * m_2171338909067427793 = new Monomial (coeff,t_7329123895943991064);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6448264611932649709 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_1901315615640712045 = new Monomial (coeff,t_6448264611932649709);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_3636257504042349253 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_30721963009328407 = new Monomial (coeff,t_3636257504042349253);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_1080645762859102765 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_5363432685012506514 = new Monomial (coeff,t_1080645762859102765);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_4484476222046087542 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_2104891121306794951 = new Monomial (coeff,t_4484476222046087542);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_3815113466142166857 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_4225676670239869874 = new Monomial (coeff,t_3815113466142166857);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2356616159307131805 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4822478912074424262 = new Monomial (coeff,t_2356616159307131805);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8602795560333161092 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3590211135183224228 = new Monomial (coeff,t_8602795560333161092);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6329094895668990475 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_1470871668911071868 = new Monomial (coeff,t_6329094895668990475);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6237373554010895294 = build_term_from_stack();

	mpz_set_si(coeff,-128);
	Monomial * m_3035915008923412146 = new Monomial (coeff,t_6237373554010895294);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_3106396165937709866 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_3881813962401041272 = new Monomial (coeff,t_3106396165937709866);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_3350540472070681070 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_6496169184221624797 = new Monomial (coeff,t_3350540472070681070);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_304906389435672997 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_464208403945311850 = new Monomial (coeff,t_304906389435672997);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_7329123895943991071 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_2470876668914071852 = new Monomial (coeff,t_7329123895943991071);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_8303778308962333307 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_16509678909703728 = new Monomial (coeff,t_8303778308962333307);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_2911489830793612289 = build_term_from_stack();

	mpz_set_ui(coeff,384);
	Monomial * m_4251682165596160941 = new Monomial (coeff,t_2911489830793612289);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_4636266504073349355 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1030730963040328457 = new Monomial (coeff,t_4636266504073349355);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_6891386501307099725 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_4464819975819065452 = new Monomial (coeff,t_6891386501307099725);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_26537238763687074 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2334232078436734022 = new Monomial (coeff,t_26537238763687074);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_176799468383171751 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_5225269439360978410 = new Monomial (coeff,t_176799468383171751);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_2627338361197615039 = build_term_from_stack();

	mpz_set_si(coeff,-192);
	Monomial * m_905533869647441518 = new Monomial (coeff,t_2627338361197615039);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_361482216618221313 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2173058697570003733 = new Monomial (coeff,t_361482216618221313);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_8925989568491694849 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_200093757314409955 = new Monomial (coeff,t_8925989568491694849);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_6887314098037458387 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_5382767869282026966 = new Monomial (coeff,t_6887314098037458387);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_5356723160064133193 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7822585912639425130 = new Monomial (coeff,t_5356723160064133193);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_6642604989271813601 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_1987124822629572196 = new Monomial (coeff,t_6642604989271813601);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_638510783380778706 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3173051697569003898 = new Monomial (coeff,t_638510783380778706);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_8520729504962856128 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1200086757313409996 = new Monomial (coeff,t_8520729504962856128);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_5356723160064133192 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_396770683821442427 = new Monomial (coeff,t_5356723160064133192);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1715642086439979896 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_5432742146448060376 = new Monomial (coeff,t_1715642086439979896);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_3030150949979964548 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_2603484945221435914 = new Monomial (coeff,t_3030150949979964548);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_30107949926964778 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_5486436016943975780 = new Monomial (coeff,t_30107949926964778);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_8391649909707896758 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_311676794170477967 = new Monomial (coeff,t_8391649909707896758);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_5356723160064133199 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7822585912639425132 = new Monomial (coeff,t_5356723160064133199);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_8964013845923819433 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7934158971516772422 = new Monomial (coeff,t_8964013845923819433);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_3030150949979964550 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_4486427016912975692 = new Monomial (coeff,t_3030150949979964550);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_6705172365350803663 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_7699326369260505365 = new Monomial (coeff,t_6705172365350803663);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2633705293802725648 = build_term_from_stack();

	mpz_set_ui(coeff,192);
	Monomial * m_43402624862056869 = new Monomial (coeff,t_2633705293802725648);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_8520729504962856134 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_8957097349070363275 = new Monomial (coeff,t_8520729504962856134);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_178378817991456776 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_7365713230790137202 = new Monomial (coeff,t_178378817991456776);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_7729547518900561765 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_1242819830394550836 = new Monomial (coeff,t_7729547518900561765);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1479278771248836234 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_2143557286725240548 = new Monomial (coeff,t_1479278771248836234);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_4385733027227771666 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_5998877950172613329 = new Monomial (coeff,t_4385733027227771666);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_8925989568491694856 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_200093757314409956 = new Monomial (coeff,t_8925989568491694856);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8060632361913174131 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_5881790229396670029 = new Monomial (coeff,t_8060632361913174131);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_5248788502526065925 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_1649104658764171754 = new Monomial (coeff,t_5248788502526065925);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_8126360630374960011 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_5925722517070317099 = new Monomial (coeff,t_8126360630374960011);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2816834776594083490 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8377602168878100806 = new Monomial (coeff,t_2816834776594083490);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_2219781390702705328 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_7334255759241454497 = new Monomial (coeff,t_2219781390702705328);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_3636257504042349251 = build_term_from_stack();

	mpz_set_si(coeff,-96);
	Monomial * m_1449207827196456628 = new Monomial (coeff,t_3636257504042349251);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_7712317790627983610 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_1575574815346588533 = new Monomial (coeff,t_7712317790627983610);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1204818462006113460 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_5072723386389917858 = new Monomial (coeff,t_1204818462006113460);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_7027618706318072171 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_981012423617767708 = new Monomial (coeff,t_7027618706318072171);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7804494701147900150 = build_term_from_stack();

	mpz_set_si(coeff,-384);
	Monomial * m_2311349967957247894 = new Monomial (coeff,t_7804494701147900150);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_4763872975733434447 = build_term_from_stack();

	mpz_set_si(coeff,-128);
	Monomial * m_6191607442297259293 = new Monomial (coeff,t_4763872975733434447);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_5055334614520655842 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_2379738321323192777 = new Monomial (coeff,t_5055334614520655842);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2816834776594083495 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_2116551473607222838 = new Monomial (coeff,t_2816834776594083495);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_1176892468850172308 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_3694328430213376973 = new Monomial (coeff,t_1176892468850172308);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1220134653708905313 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_6117044945679642377 = new Monomial (coeff,t_1220134653708905313);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_8126360630374960012 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_5925722517070317102 = new Monomial (coeff,t_8126360630374960012);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_5248788502526065922 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_1649104658764171759 = new Monomial (coeff,t_5248788502526065922);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_9208444510773049883 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_4915329906849667949 = new Monomial (coeff,t_9208444510773049883);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_7027618706318072174 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_6745559714126192867 = new Monomial (coeff,t_7027618706318072174);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_304709132318259185 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_3245448943457158228 = new Monomial (coeff,t_304709132318259185);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_3877976651338503975 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_1786643601732435348 = new Monomial (coeff,t_3877976651338503975);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b3);
	Term * t_5526754089670188571 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1338207728603571583 = new Monomial (coeff,t_5526754089670188571);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b3);
	Term * t_5198697446013646198 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_563636931765380511 = new Monomial (coeff,t_5198697446013646198);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8729560518951561825 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1620589034138876977 = new Monomial (coeff,t_8729560518951561825);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_3055320614486655746 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8959305845634514310 = new Monomial (coeff,t_3055320614486655746);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b3);
	Term * t_2268458575837366886 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_4499432735928770657 = new Monomial (coeff,t_2268458575837366886);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1115787963440409311 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7537107713678495408 = new Monomial (coeff,t_1115787963440409311);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_2147512648146346180 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_4738917069187657563 = new Monomial (coeff,t_2147512648146346180);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_6711558412874839058 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8900277346504847330 = new Monomial (coeff,t_6711558412874839058);

	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_3485344240293081962 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_4717028345938854011 = new Monomial (coeff,t_3485344240293081962);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_6206931839173351134 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4941938168396622119 = new Monomial (coeff,t_6206931839173351134);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_5126818702173739686 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_735496825519608002 = new Monomial (coeff,t_5126818702173739686);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_361482216618221319 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2173058697570003731 = new Monomial (coeff,t_361482216618221319);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2874255449901271640 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_2101812929882703473 = new Monomial (coeff,t_2874255449901271640);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2247839409505979910 = build_term_from_stack();

	mpz_set_si(coeff,-320);
	Monomial * m_5261433641576388828 = new Monomial (coeff,t_2247839409505979910);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_4055325614489655805 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_2926168603715265150 = new Monomial (coeff,t_4055325614489655805);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_1219820390959705720 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_749337028767712466 = new Monomial (coeff,t_1219820390959705720);

	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_4576121756171741530 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_812982770049516399 = new Monomial (coeff,t_4576121756171741530);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_493345322440606085 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_522064276127567241 = new Monomial (coeff,t_493345322440606085);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b3);
	Term * t_8086814365189874175 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_5062323297018154286 = new Monomial (coeff,t_8086814365189874175);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_1219820390959705713 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8462847543120272133 = new Monomial (coeff,t_1219820390959705713);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_361482216618221312 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2173058697570003732 = new Monomial (coeff,t_361482216618221312);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_6482719227796732237 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4934179971783772952 = new Monomial (coeff,t_6482719227796732237);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_846211128377603040 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1748318697048299860 = new Monomial (coeff,t_846211128377603040);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_4055325614489655802 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_2467619909639068829 = new Monomial (coeff,t_4055325614489655802);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_8520729504962856129 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1200086757313409997 = new Monomial (coeff,t_8520729504962856129);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_7252980033692690098 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_5178499688477657887 = new Monomial (coeff,t_7252980033692690098);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_5861107002941555973 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3617082479859627715 = new Monomial (coeff,t_5861107002941555973);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_6482719227796732236 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4934179971783772945 = new Monomial (coeff,t_6482719227796732236);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1415051105974731660 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_5478925382798364034 = new Monomial (coeff,t_1415051105974731660);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_3030150949979964549 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_4486427016912975691 = new Monomial (coeff,t_3030150949979964549);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1247842409486979794 = build_term_from_stack();

	mpz_set_si(coeff,-256);
	Monomial * m_1142000726707459426 = new Monomial (coeff,t_1247842409486979794);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2247839409505979907 = build_term_from_stack();

	mpz_set_si(coeff,-128);
	Monomial * m_8834360734452785007 = new Monomial (coeff,t_2247839409505979907);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2415056105785731132 = build_term_from_stack();

	mpz_set_ui(coeff,160);
	Monomial * m_4732070845762564222 = new Monomial (coeff,t_2415056105785731132);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_3003968898590479524 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_3239347140091240266 = new Monomial (coeff,t_3003968898590479524);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2415056105785731131 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_4298630350691455223 = new Monomial (coeff,t_2415056105785731131);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_219807390972705844 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_9209079552018663298 = new Monomial (coeff,t_219807390972705844);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6957543795474287948 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_4858950541422649192 = new Monomial (coeff,t_6957543795474287948);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7705185365337803532 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8699331369263505348 = new Monomial (coeff,t_7705185365337803532);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_3636257504042349252 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_5656216784134219477 = new Monomial (coeff,t_3636257504042349252);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_1176892468850172309 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7333813913282261756 = new Monomial (coeff,t_1176892468850172309);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_76776008938447067 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7205837560925338666 = new Monomial (coeff,t_76776008938447067);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_3633710293805725663 = build_term_from_stack();

	mpz_set_ui(coeff,192);
	Monomial * m_956610375380943770 = new Monomial (coeff,t_3633710293805725663);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_3926823968520693954 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_421166355302543915 = new Monomial (coeff,t_3926823968520693954);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_7391644909704896746 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_1311681794173477979 = new Monomial (coeff,t_7391644909704896746);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_5828030773480377989 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_3871247453558570634 = new Monomial (coeff,t_5828030773480377989);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2633705293802725655 = build_term_from_stack();

	mpz_set_ui(coeff,192);
	Monomial * m_43402624862056866 = new Monomial (coeff,t_2633705293802725655);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_7957572795493287768 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_5858979541697649780 = new Monomial (coeff,t_7957572795493287768);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_289247677706026184 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_8461780441329158119 = new Monomial (coeff,t_289247677706026184);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_695283867680740967 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_4898015980873404350 = new Monomial (coeff,t_695283867680740967);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6465475102993302825 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_7390454751578054618 = new Monomial (coeff,t_6465475102993302825);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_905485317355171542 = build_term_from_stack();

	mpz_set_ui(coeff,64);
	Monomial * m_4233915781373148944 = new Monomial (coeff,t_905485317355171542);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_7734415283284568658 = build_term_from_stack();

	mpz_set_ui(coeff,16);
	Monomial * m_1882489298383564529 = new Monomial (coeff,t_7734415283284568658);

	add_to_vstack(a0);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b4);
	Term * t_8178103815374251522 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7474725586076520841 = new Monomial (coeff,t_8178103815374251522);

	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_2092017513567676730 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_6663352449510349703 = new Monomial (coeff,t_2092017513567676730);

	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b3);
	Term * t_8644279441379365090 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_6986529327288256427 = new Monomial (coeff,t_8644279441379365090);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1695296867731741027 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1366742895759609365 = new Monomial (coeff,t_1695296867731741027);

	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_6429391040156293203 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_7656044241527513323 = new Monomial (coeff,t_6429391040156293203);

	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	Term * t_5464423556349171202 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7167179949122172133 = new Monomial (coeff,t_5464423556349171202);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8734412283047568038 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_8084373974548539773 = new Monomial (coeff,t_8734412283047568038);

	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_2485339240226081758 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_6442357874616488137 = new Monomial (coeff,t_2485339240226081758);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8042908113614733043 = build_term_from_stack();

	mpz_set_si(coeff,-61440);
	Monomial * m_2995010194876047225 = new Monomial (coeff,t_8042908113614733043);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8457978484168448930 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_758747740127234674 = new Monomial (coeff,t_8457978484168448930);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_1218627982329201228 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_4056643640803622465 = new Monomial (coeff,t_1218627982329201228);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8239403025806860185 = build_term_from_stack();

	mpz_set_ui(coeff,49152);
	Monomial * m_4355637910608313171 = new Monomial (coeff,t_8239403025806860185);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_4631853798732102899 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_4598797409255693507 = new Monomial (coeff,t_4631853798732102899);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6235049139719267780 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_4723315782937944117 = new Monomial (coeff,t_6235049139719267780);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2826322258019490520 = build_term_from_stack();

	mpz_set_si(coeff,-24576);
	Monomial * m_6313001481874397073 = new Monomial (coeff,t_2826322258019490520);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5491607670655190026 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_485476964015219842 = new Monomial (coeff,t_5491607670655190026);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8272094581075409115 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_3590379310813611451 = new Monomial (coeff,t_8272094581075409115);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_1289711365811051105 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_8033879726777958681 = new Monomial (coeff,t_1289711365811051105);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1311484933051599652 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_2731178923567975874 = new Monomial (coeff,t_1311484933051599652);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_9042847431667800696 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_8316629107280183066 = new Monomial (coeff,t_9042847431667800696);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_6131144355605429882 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_1280884035939336679 = new Monomial (coeff,t_6131144355605429882);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_3272049581000409166 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_1488733645688234253 = new Monomial (coeff,t_3272049581000409166);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_859744224223194722 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_527854901861121239 = new Monomial (coeff,t_859744224223194722);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_2289724365862051171 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_9033884726780958663 = new Monomial (coeff,t_2289724365862051171);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7794210043041939838 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_5883254106001268248 = new Monomial (coeff,t_7794210043041939838);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_218630982310201115 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3056638640800622478 = new Monomial (coeff,t_218630982310201115);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_7289769366129051701 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_426259780836339564 = new Monomial (coeff,t_7289769366129051701);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1289711365811051106 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_5573862219737661281 = new Monomial (coeff,t_1289711365811051106);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_8403883642054751045 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_8545304186433760408 = new Monomial (coeff,t_8403883642054751045);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3082292550503658597 = build_term_from_stack();

	mpz_set_ui(coeff,40960);
	Monomial * m_7562863417656141067 = new Monomial (coeff,t_3082292550503658597);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_3901238198959868258 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_2886281120807349621 = new Monomial (coeff,t_3901238198959868258);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5313256032848156508 = build_term_from_stack();

	mpz_set_ui(coeff,40960);
	Monomial * m_3941282247590541616 = new Monomial (coeff,t_5313256032848156508);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_5457871483667448310 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7794776927830501077 = new Monomial (coeff,t_5457871483667448310);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_1311484933051599651 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_1343714956541313049 = new Monomial (coeff,t_1311484933051599651);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_7403856960361819098 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_8651055530903330312 = new Monomial (coeff,t_7403856960361819098);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_6421815866146993689 = build_term_from_stack();

	mpz_set_ui(coeff,40960);
	Monomial * m_6725071862179236589 = new Monomial (coeff,t_6421815866146993689);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_7123429679769334356 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_641856374763918884 = new Monomial (coeff,t_7123429679769334356);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_2289724365862051170 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_5084297121785526274 = new Monomial (coeff,t_2289724365862051170);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_6992286249988597030 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_7009243800786145683 = new Monomial (coeff,t_6992286249988597030);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_6131144355605429883 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_953170167230579589 = new Monomial (coeff,t_6131144355605429883);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_3272049581000409167 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_2590370310790611435 = new Monomial (coeff,t_3272049581000409167);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_218630982310201113 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3056638640800622480 = new Monomial (coeff,t_218630982310201113);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_6421815866146993688 = build_term_from_stack();

	mpz_set_si(coeff,-20480);
	Monomial * m_4358135557096748419 = new Monomial (coeff,t_6421815866146993688);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_9042847431667800697 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_3809451655005510490 = new Monomial (coeff,t_9042847431667800697);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_9024917207573557907 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_7512279328594876714 = new Monomial (coeff,t_9024917207573557907);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_7403856960361819097 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_5686462650203935320 = new Monomial (coeff,t_7403856960361819097);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_8860987071811708945 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_9019836137997592563 = new Monomial (coeff,t_8860987071811708945);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_2289724365862051172 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_407789557108378257 = new Monomial (coeff,t_2289724365862051172);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_5794116042719939604 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_666384376438064180 = new Monomial (coeff,t_5794116042719939604);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_4631853798732102898 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_5105307656166880431 = new Monomial (coeff,t_4631853798732102898);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_8403883642054751048 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_2809446655002510487 = new Monomial (coeff,t_8403883642054751048);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_7123429679769334359 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_4459868808903505240 = new Monomial (coeff,t_7123429679769334359);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b5);
	Term * t_1218627982329201227 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_4056643640803622466 = new Monomial (coeff,t_1218627982329201227);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_8403883642054751046 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_9130101966442368676 = new Monomial (coeff,t_8403883642054751046);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5795851301190763327 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_3652072716935742915 = new Monomial (coeff,t_5795851301190763327);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_6123424679702334243 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_5459873808906505220 = new Monomial (coeff,t_6123424679702334243);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_3050532533966311350 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_6581946279281973484 = new Monomial (coeff,t_3050532533966311350);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2311493933018599452 = build_term_from_stack();

	mpz_set_ui(coeff,24576);
	Monomial * m_3726541056031414407 = new Monomial (coeff,t_2311493933018599452);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_5794116042719939602 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_5974194503831482063 = new Monomial (coeff,t_5794116042719939602);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_4794103042476938962 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3929886663582776301 = new Monomial (coeff,t_4794103042476938962);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_9123403679499333839 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_523860526803434323 = new Monomial (coeff,t_9123403679499333839);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_6131144355605429881 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_1280884035939336678 = new Monomial (coeff,t_6131144355605429881);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_5457871483667448309 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_241277260127765941 = new Monomial (coeff,t_5457871483667448309);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7290807992122448375 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_6847482718273797474 = new Monomial (coeff,t_7290807992122448375);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7289769366129051702 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_4084288121826526514 = new Monomial (coeff,t_7289769366129051702);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_6235049139719267782 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_8611463540396697901 = new Monomial (coeff,t_6235049139719267782);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_7123429679769334357 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_2523866526789434361 = new Monomial (coeff,t_7123429679769334357);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7770267780843668474 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_6102943812502559784 = new Monomial (coeff,t_7770267780843668474);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_7670873510464292056 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_1077230879831828653 = new Monomial (coeff,t_7670873510464292056);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_2200104071768025413 = build_term_from_stack();

	mpz_set_ui(coeff,53248);
	Monomial * m_2776483492595528168 = new Monomial (coeff,t_2200104071768025413);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2200104071768025414 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_4911026331875338683 = new Monomial (coeff,t_2200104071768025414);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_548675096155306217 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_2336287172823628130 = new Monomial (coeff,t_548675096155306217);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5603873531670202154 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_8360743579447237928 = new Monomial (coeff,t_5603873531670202154);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_1548688096398306856 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_5839300414498035306 = new Monomial (coeff,t_1548688096398306856);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_4062165172757011710 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_2971226292125787357 = new Monomial (coeff,t_4062165172757011710);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1548688096398306857 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_1336282172820628142 = new Monomial (coeff,t_1548688096398306857);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_8667630516245884259 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_623679056201082277 = new Monomial (coeff,t_8667630516245884259);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7704499797320024827 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_2218914560917117555 = new Monomial (coeff,t_7704499797320024827);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_1231238279965100962 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_3609346366227766686 = new Monomial (coeff,t_1231238279965100962);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_7414583396432243655 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3610084534774146608 = new Monomial (coeff,t_7414583396432243655);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_4088579735435426241 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_1343570593513387178 = new Monomial (coeff,t_4088579735435426241);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_4532672813018841213 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_652032035251726845 = new Monomial (coeff,t_4532672813018841213);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_4272977646562159810 = build_term_from_stack();

	mpz_set_si(coeff,-40960);
	Monomial * m_186831208245796056 = new Monomial (coeff,t_4272977646562159810);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_3957917671016668555 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_3003749035656713478 = new Monomial (coeff,t_3957917671016668555);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_3957917671016668552 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_8636399747670185850 = new Monomial (coeff,t_3957917671016668552);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_412004674476456953 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_1191788078799326332 = new Monomial (coeff,t_412004674476456953);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_746882936527676858 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_261423801441340710 = new Monomial (coeff,t_746882936527676858);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_3746893936580676934 = build_term_from_stack();

	mpz_set_ui(coeff,24576);
	Monomial * m_7576532465437046509 = new Monomial (coeff,t_3746893936580676934);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_5056245973459394534 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_6858905369771695849 = new Monomial (coeff,t_5056245973459394534);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8440903644596040690 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_7376025075910789066 = new Monomial (coeff,t_8440903644596040690);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_2393539069874916740 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_3989343550719309565 = new Monomial (coeff,t_2393539069874916740);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_7414583396432243654 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_4360413814298484464 = new Monomial (coeff,t_7414583396432243654);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7646254988697818826 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_28002237277353859 = new Monomial (coeff,t_7646254988697818826);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8565460351545342667 = build_term_from_stack();

	mpz_set_ui(coeff,53248);
	Monomial * m_4158661918438585010 = new Monomial (coeff,t_8565460351545342667);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_8798241896690088000 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_3159045680408643120 = new Monomial (coeff,t_8798241896690088000);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_295770072342092864 = build_term_from_stack();

	mpz_set_si(coeff,-40960);
	Monomial * m_2626146739751707886 = new Monomial (coeff,t_295770072342092864);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_3088566735384426177 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_343565593510387190 = new Monomial (coeff,t_3088566735384426177);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_8798241896690088001 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_66837305206115519 = new Monomial (coeff,t_8798241896690088001);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_231273280266101460 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_1176517264308775012 = new Monomial (coeff,t_231273280266101460);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_231273280266101459 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_4609351366230766675 = new Monomial (coeff,t_231273280266101459);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_115157608573545833 = build_term_from_stack();

	mpz_set_si(coeff,-40960);
	Monomial * m_6000261645082650055 = new Monomial (coeff,t_115157608573545833);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5597901313660328127 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_4928950368014939813 = new Monomial (coeff,t_5597901313660328127);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2115187345293203111 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_8968701746786384363 = new Monomial (coeff,t_2115187345293203111);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_1231238279965100961 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_4144448824867690316 = new Monomial (coeff,t_1231238279965100961);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_7566968726350454119 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_2859335675727020038 = new Monomial (coeff,t_7566968726350454119);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_239287390252410651 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_7786325143369653037 = new Monomial (coeff,t_239287390252410651);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_6290876309023062562 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_6466328402296013741 = new Monomial (coeff,t_6290876309023062562);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_6281848143355236425 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_994849265555663460 = new Monomial (coeff,t_6281848143355236425);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_1281867143600236928 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_1860211652271857134 = new Monomial (coeff,t_1281867143600236928);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_6281848143355236426 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_5920488614448205112 = new Monomial (coeff,t_6281848143355236426);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_9174973585909628981 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_4504082291607180987 = new Monomial (coeff,t_9174973585909628981);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_3393552069925916806 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_7434875251915168979 = new Monomial (coeff,t_3393552069925916806);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_6580866424285971963 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_4492301638475801389 = new Monomial (coeff,t_6580866424285971963);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_2606505930392083759 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_7457401523181242492 = new Monomial (coeff,t_2606505930392083759);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1923445041817759835 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_7880336951422196750 = new Monomial (coeff,t_1923445041817759835);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_1923445041817759834 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_2597755969548019900 = new Monomial (coeff,t_1923445041817759834);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_3062168172738011533 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_7474061816560383756 = new Monomial (coeff,t_3062168172738011533);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5667523515680883407 = build_term_from_stack();

	mpz_set_ui(coeff,49152);
	Monomial * m_1905350990981416657 = new Monomial (coeff,t_5667523515680883407);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_5532765813741842509 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_3949140426726856288 = new Monomial (coeff,t_5532765813741842509);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_6062179172791011674 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_2695008185264906918 = new Monomial (coeff,t_6062179172791011674);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_3800362084434732030 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_2939050201926891213 = new Monomial (coeff,t_3800362084434732030);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b6);
	Term * t_1281867143600236926 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_7994912265876664043 = new Monomial (coeff,t_1281867143600236926);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	Term * t_584186533560832860 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_1759723462604230186 = new Monomial (coeff,t_584186533560832860);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_8667630516245884258 = build_term_from_stack();

	mpz_set_si(coeff,-36864);
	Monomial * m_852046345057861068 = new Monomial (coeff,t_8667630516245884258);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_633937487654717522 = build_term_from_stack();

	mpz_set_ui(coeff,32768);
	Monomial * m_3221596997705106633 = new Monomial (coeff,t_633937487654717522);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b7);
	Term * t_4062165172757011712 = build_term_from_stack();

	mpz_set_si(coeff,-24576);
	Monomial * m_5140350782166877393 = new Monomial (coeff,t_4062165172757011712);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_4062165172757011711 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_6474056816557383774 = new Monomial (coeff,t_4062165172757011711);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_8498971914901286643 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_328984661118683985 = new Monomial (coeff,t_8498971914901286643);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2393582120737067007 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_3167758002048266762 = new Monomial (coeff,t_2393582120737067007);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b2);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_2393582120737067006 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_3163066226733968390 = new Monomial (coeff,t_2393582120737067006);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_2519631175109331703 = build_term_from_stack();

	mpz_set_si(coeff,-53248);
	Monomial * m_4431467888095329658 = new Monomial (coeff,t_2519631175109331703);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_884919655207797517 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_6910156277733807192 = new Monomial (coeff,t_884919655207797517);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_3746893936580676935 = build_term_from_stack();

	mpz_set_si(coeff,-45056);
	Monomial * m_8162829400629799386 = new Monomial (coeff,t_3746893936580676935);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b3);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_1231238279965100963 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_176512264305775033 = new Monomial (coeff,t_1231238279965100963);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2889196084302885632 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_5085990302980576350 = new Monomial (coeff,t_2889196084302885632);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_834709770654866688 = build_term_from_stack();

	mpz_set_ui(coeff,40960);
	Monomial * m_4812277256842588324 = new Monomial (coeff,t_834709770654866688);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_3231305961945033446 = build_term_from_stack();

	mpz_set_si(coeff,-24576);
	Monomial * m_2499217561209765629 = new Monomial (coeff,t_3231305961945033446);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_2606505930392083758 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_2166787368828103436 = new Monomial (coeff,t_2606505930392083758);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_5528238376360915498 = build_term_from_stack();

	mpz_set_ui(coeff,57344);
	Monomial * m_5779185176275639718 = new Monomial (coeff,t_5528238376360915498);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_2231312961946033293 = build_term_from_stack();

	mpz_set_si(coeff,-28672);
	Monomial * m_1053382630316773487 = new Monomial (coeff,t_2231312961946033293);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	Term * t_5005795429038511002 = build_term_from_stack();

	mpz_set_ui(coeff,8192);
	Monomial * m_7542878567241862360 = new Monomial (coeff,t_5005795429038511002);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_1533696352162629449 = build_term_from_stack();

	mpz_set_si(coeff,-16384);
	Monomial * m_917703764001064036 = new Monomial (coeff,t_1533696352162629449);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_110846916006114892 = build_term_from_stack();

	mpz_set_ui(coeff,12288);
	Monomial * m_1457844783818249690 = new Monomial (coeff,t_110846916006114892);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_2231312961946033294 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_3293630974170423782 = new Monomial (coeff,t_2231312961946033294);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b4);
	add_to_vstack(b6);
	Term * t_1616657206608245844 = build_term_from_stack();

	mpz_set_si(coeff,-4096);
	Monomial * m_2567261625782152345 = new Monomial (coeff,t_1616657206608245844);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_7290881309026062582 = build_term_from_stack();

	mpz_set_ui(coeff,4096);
	Monomial * m_8354240807563036439 = new Monomial (coeff,t_7290881309026062582);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_9080831284849184410 = build_term_from_stack();

	mpz_set_si(coeff,-12288);
	Monomial * m_8674999814359297498 = new Monomial (coeff,t_9080831284849184410);

	add_to_vstack(a4);
	add_to_vstack(b0);
	Term * t_1522240348685160891 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_8094385925689820550 = new Monomial (coeff,t_1522240348685160891);

	add_to_vstack(a7);
	add_to_vstack(b5);
	Term * t_522231348654160791 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_966007501449357727 = new Monomial (coeff,t_522231348654160791);

	add_to_vstack(a1);
	add_to_vstack(b3);
	Term * t_1477870652091840525 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_3094328925354820022 = new Monomial (coeff,t_1477870652091840525);

	add_to_vstack(a2);
	add_to_vstack(b2);
	Term * t_4477881651888839985 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_6094371925663820546 = new Monomial (coeff,t_4477881651888839985);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b5);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_7657706858150124951 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_5264173279922970255 = new Monomial (coeff,t_7657706858150124951);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(b6);
	add_to_vstack(b7);
	Term * t_4290838308717061914 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_4702096393951890739 = new Monomial (coeff,t_4290838308717061914);

	add_to_vstack(a3);
	add_to_vstack(b1);
	Term * t_3477868651837839921 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_5094342925388819986 = new Monomial (coeff,t_3477868651837839921);

	add_to_vstack(a0);
	add_to_vstack(b4);
	Term * t_2477875652094840541 = build_term_from_stack();

	mpz_set_si(coeff,-16);
	Monomial * m_4094333925357820030 = new Monomial (coeff,t_2477875652094840541);

	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_4005790429035510998 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_1446530740612615085 = new Monomial (coeff,t_4005790429035510998);

	add_to_vstack(a5);
	add_to_vstack(a6);
	add_to_vstack(a7);
	add_to_vstack(b5);
	add_to_vstack(b6);
	Term * t_3606510930395083763 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_8682948485887848569 = new Monomial (coeff,t_3606510930395083763);

	add_to_vstack(a6);
	add_to_vstack(b6);
	Term * t_477861652068840537 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_1966012501452357739 = new Monomial (coeff,t_477861652068840537);

	mpz_set_ui(coeff,4112);
	Monomial * m_1794728972600554170 = new Monomial (coeff,0);

	add_to_vstack(a5);
	add_to_vstack(b7);
	Term * t_2522245348688160883 = build_term_from_stack();

	mpz_set_si(coeff,-8192);
	Monomial * m_1033998498536642185 = new Monomial (coeff,t_2522245348688160883);

	add_to_vstack(a5);
	add_to_vstack(a7);
	add_to_vstack(b5);
	add_to_vstack(b7);
	Term * t_2616670206595245718 = build_term_from_stack();

	mpz_set_ui(coeff,16384);
	Monomial * m_2876489379407643613 = new Monomial (coeff,t_2616670206595245718);

	mpz_set_si(coeff,-12288);
	Monomial * m_7334591819367846785 = new Monomial (coeff,t_6994595977746891905->copy());

	mpz_set_si(coeff,-12288);
	Monomial * m_4394200827290693302 = new Monomial (coeff,t_5694483653357011742->copy());

	mpz_set_ui(coeff,53248);
	Monomial * m_2627919318376789148 = new Monomial (coeff,t_2681052928177050821->copy());

	mpz_set_ui(coeff,53248);
	Monomial * m_3190408477757770872 = new Monomial (coeff,t_3236074715482054879->copy());

	mpz_set_ui(coeff,12288);
	Monomial * m_6878678526117869817 = new Monomial (coeff,t_2611624328016273833->copy());

	mpz_set_ui(coeff,53248);
	Monomial * m_2991217137048741202 = new Monomial (coeff,t_7632211146072868209->copy());

	mpz_set_ui(coeff,4096);
	Monomial * m_8649549020671362514 = new Monomial (coeff,t_5059554921032815779->copy());

	mpz_set_ui(coeff,12288);
	Monomial * m_1715706449042189973 = new Monomial (coeff,t_5279134829206275679->copy());

	mpz_set_si(coeff,-24576);
	Monomial * m_9034446518438222646 = new Monomial (coeff,t_3082292550503658597->copy());

	mpz_set_si(coeff,-24576);
	Monomial * m_4031586764294785437 = new Monomial (coeff,t_5313256032848156508->copy());

	mpz_set_si(coeff,-53248);
	Monomial * m_4825123762069048326 = new Monomial (coeff,t_5795851301190763327->copy());

	mpz_set_ui(coeff,12288);
	Monomial * m_8161048427101358398 = new Monomial (coeff,t_8403883642054751048->copy());

	mpz_set_si(coeff,-16384);
	Monomial * m_5586792342688796886 = new Monomial (coeff,t_8239403025806860185->copy());

	mpz_set_si(coeff,-57344);
	Monomial * m_6214211996395277894 = new Monomial (coeff,t_9042847431667800696->copy());

	mpz_set_ui(coeff,12288);
	Monomial * m_1586400041365173292 = new Monomial (coeff,t_6992286249988597030->copy());

	mpz_set_ui(coeff,61440);
	Monomial * m_3099195120562490879 = new Monomial (coeff,t_6123424679702334243->copy());

	mpz_set_ui(coeff,53248);
	Monomial * m_7881749990431030641 = new Monomial (coeff,t_5491607670655190026->copy());

	mpz_set_si(coeff,-40960);
	Monomial * m_3536522532045199336 = new Monomial (coeff,t_3746893936580676934->copy());

	mpz_set_ui(coeff,24576);
	Monomial * m_2580744792151990986 = new Monomial (coeff,t_115157608573545833->copy());

	mpz_set_si(coeff,-57344);
	Monomial * m_3790835143076745575 = new Monomial (coeff,t_9174973585909628981->copy());

	mpz_set_ui(coeff,12288);
	Monomial * m_4154748002733677099 = new Monomial (coeff,t_2519631175109331703->copy());

	mpz_set_ui(coeff,61440);
	Monomial * m_884093968343609859 = new Monomial (coeff,t_884919655207797517->copy());

	mpz_set_si(coeff,-8192);
	Monomial * m_4325737353110787362 = new Monomial (coeff,t_5528238376360915498->copy());

	mpz_set_ui(coeff,4096);
	Monomial * m_1794727972604554129 = new Monomial (coeff,0);

	mpz_set_ui(coeff,64);
	Monomial * m_3354942891277150561 = new Monomial (coeff,t_361482216618221319->copy());

	mpz_set_ui(coeff,128);
	Monomial * m_6204133634428750110 = new Monomial (coeff,t_846211128377603040->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_6368059386699143323 = new Monomial (coeff,t_2923234991114553072->copy());

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_973455761235313079 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_665746921296265455 = new Monomial (coeff,t_973455761235313079);

	mpz_set_si(coeff,-64);
	Monomial * m_7218243394070108475 = new Monomial (coeff,t_2633705293802725655->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_3657085054435518210 = new Monomial (coeff,t_6642604989271813601->copy());

	mpz_set_ui(coeff,32);
	Monomial * m_8838771963228301332 = new Monomial (coeff,t_3636257504042349251->copy());

	mpz_set_si(coeff,-128);
	Monomial * m_3550832419410389738 = new Monomial (coeff,t_30107949926964778->copy());

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_1846236128632603544 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_9204112634161749578 = new Monomial (coeff,t_1846236128632603544);

	mpz_set_si(coeff,-32);
	Monomial * m_5368050386668143347 = new Monomial (coeff,t_76776008938447068->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_354835890712149708 = new Monomial (coeff,t_638510783380778706->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_4343940313494534420 = new Monomial (coeff,t_4636266504073349358->copy());

	mpz_set_si(coeff,-128);
	Monomial * m_2701209500423349094 = new Monomial (coeff,t_7804494701147900150->copy());

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_7861145003247556664 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1617068479825627748 = new Monomial (coeff,t_7861145003247556664);

	mpz_set_ui(coeff,192);
	Monomial * m_5625703614027699405 = new Monomial (coeff,t_2247839409505979910->copy());

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_4126809702142739646 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3735507825572608150 = new Monomial (coeff,t_4126809702142739646);

	mpz_set_si(coeff,-64);
	Monomial * m_217798296920821504 = new Monomial (coeff,t_8126360630374960012->copy());

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_4126809702142739645 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3735507825572608151 = new Monomial (coeff,t_4126809702142739645);

	mpz_set_ui(coeff,128);
	Monomial * m_3844741115169213591 = new Monomial (coeff,t_4636266504073349355->copy());

	mpz_set_ui(coeff,128);
	Monomial * m_7317309123658704563 = new Monomial (coeff,t_2911489830793612289->copy());

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2923234991114553079 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_6712557632947960431 = new Monomial (coeff,t_2923234991114553079);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_26537238763687073 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2334232078436734021 = new Monomial (coeff,t_26537238763687073);

	mpz_set_si(coeff,-64);
	Monomial * m_7358463134481671731 = new Monomial (coeff,t_3030150949979964549->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_6257757314711793888 = new Monomial (coeff,t_6942478116495498510->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_3354942891277150567 = new Monomial (coeff,t_361482216618221313->copy());

	mpz_set_si(coeff,-256);
	Monomial * m_7089784316161139696 = new Monomial (coeff,t_3003968898590479524->copy());

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_2219781390702705327 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_7237658521640888081 = new Monomial (coeff,t_2219781390702705327);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2296203965943183262 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_5148280202213665408 = new Monomial (coeff,t_2296203965943183262);

	mpz_set_si(coeff,-128);
	Monomial * m_7834395734753785502 = new Monomial (coeff,t_1247842409486979794->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_1913580401558424442 = new Monomial (coeff,t_2633705293802725648->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_8369545503465652962 = new Monomial (coeff,t_8303778308962333307->copy());

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_3289780576334657275 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_1403480262524941117 = new Monomial (coeff,t_3289780576334657275);

	mpz_set_ui(coeff,64);
	Monomial * m_8480140563928409269 = new Monomial (coeff,t_6705172365350803663->copy());

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_846211128377603041 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_6204133634428750109 = new Monomial (coeff,t_846211128377603041);

	mpz_set_si(coeff,-128);
	Monomial * m_4510192633336180012 = new Monomial (coeff,t_178378817991456776->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_2953151084345095209 = new Monomial (coeff,t_8060632361913174131->copy());

	mpz_set_si(coeff,-64);
	Monomial * m_7358463134481671730 = new Monomial (coeff,t_3030150949979964550->copy());

	mpz_set_ui(coeff,192);
	Monomial * m_6748489754500791014 = new Monomial (coeff,t_8126360630374960011->copy());

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_7861145003247556671 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1617068479825627749 = new Monomial (coeff,t_7861145003247556671);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7126355630371960028 = build_term_from_stack();

	mpz_set_si(coeff,-128);
	Monomial * m_8128169875449950544 = new Monomial (coeff,t_7126355630371960028);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2195064182015140201 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_1166617696393131217 = new Monomial (coeff,t_2195064182015140201);

	mpz_set_si(coeff,-128);
	Monomial * m_5749332006385821920 = new Monomial (coeff,t_1493350322507606324->copy());

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(a4);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_3815113466142166860 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8077381121717118352 = new Monomial (coeff,t_3815113466142166860);

	mpz_set_si(coeff,-32);
	Monomial * m_4148678599404324827 = new Monomial (coeff,t_4576121756171741530->copy());

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_7957572795493287775 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_5858979541697649781 = new Monomial (coeff,t_7957572795493287775);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	Term * t_1080645762859102766 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_475130908459448193 = new Monomial (coeff,t_1080645762859102766);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2887225619669229068 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1944881053438915480 = new Monomial (coeff,t_2887225619669229068);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7004160233580215329 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_8852439562138811031 = new Monomial (coeff,t_7004160233580215329);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_9078397758456249442 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_5926931997564326356 = new Monomial (coeff,t_9078397758456249442);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_2042003044784207082 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_6021211737656574566 = new Monomial (coeff,t_2042003044784207082);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_2887225619669229069 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1944881053438915487 = new Monomial (coeff,t_2887225619669229069);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_710777322292973510 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_9173074425123117687 = new Monomial (coeff,t_710777322292973510);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_4828025773413377909 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4871252453561570626 = new Monomial (coeff,t_4828025773413377909);

	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_8218552151357014973 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_3666029044569158000 = new Monomial (coeff,t_8218552151357014973);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_6252971033725690186 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_8866221924196606726 = new Monomial (coeff,t_6252971033725690186);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_1823214531650828352 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_2288052971796078493 = new Monomial (coeff,t_1823214531650828352);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_8055088164015654946 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7859976973350993559 = new Monomial (coeff,t_8055088164015654946);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b4);
	Term * t_1268429575818367090 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_8615406171821724939 = new Monomial (coeff,t_1268429575818367090);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_6248793502529065978 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_1326257017649359052 = new Monomial (coeff,t_6248793502529065978);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_5055334614520655843 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_7487400228025037381 = new Monomial (coeff,t_5055334614520655843);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_5874266449954271756 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_5101855929935703261 = new Monomial (coeff,t_5874266449954271756);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b4);
	Term * t_395613785879840176 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3891906619641533444 = new Monomial (coeff,t_395613785879840176);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_3115801963474409408 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_8909638360029056137 = new Monomial (coeff,t_3115801963474409408);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_7887327098024458257 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_7569735997779609128 = new Monomial (coeff,t_7887327098024458257);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7389318481235874168 = build_term_from_stack();

	mpz_set_si(coeff,-256);
	Monomial * m_6844757273811952164 = new Monomial (coeff,t_7389318481235874168);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_7252980033692690099 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_6580415148947944021 = new Monomial (coeff,t_7252980033692690099);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_1147515648127346162 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_6991273492231054889 = new Monomial (coeff,t_1147515648127346162);

	add_to_vstack(a0);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_7166012597572536643 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_912989145902306795 = new Monomial (coeff,t_7166012597572536643);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_5998653586610407499 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_2538368198676650686 = new Monomial (coeff,t_5998653586610407499);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_9078397758456249445 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_5926931997564326355 = new Monomial (coeff,t_9078397758456249445);

	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b0);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_2774773976076822592 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_1975190577039325928 = new Monomial (coeff,t_2774773976076822592);

	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_80640762856102753 = build_term_from_stack();

	mpz_set_si(coeff,-32);
	Monomial * m_2184866596717380790 = new Monomial (coeff,t_80640762856102753);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	Term * t_7086809365186874161 = build_term_from_stack();

	mpz_set_ui(coeff,32);
	Monomial * m_4062318297015154296 = new Monomial (coeff,t_7086809365186874161);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8840325294369496442 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_3051657303276706316 = new Monomial (coeff,t_8840325294369496442);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_8078392758453249453 = build_term_from_stack();

	mpz_set_ui(coeff,128);
	Monomial * m_4926902997545326535 = new Monomial (coeff,t_8078392758453249453);

	add_to_vstack(a0);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_3887238619656228944 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_2944894053489915548 = new Monomial (coeff,t_3887238619656228944);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a2);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b3);
	Term * t_5998653586610407498 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_4382352007286362734 = new Monomial (coeff,t_5998653586610407498);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b2);
	add_to_vstack(b3);
	Term * t_395613785879840169 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_3891906619641533445 = new Monomial (coeff,t_395613785879840169);

	add_to_vstack(a0);
	add_to_vstack(a1);
	add_to_vstack(a3);
	add_to_vstack(b1);
	add_to_vstack(b3);
	add_to_vstack(b4);
	Term * t_604399214107159699 = build_term_from_stack();

	mpz_set_si(coeff,-64);
	Monomial * m_4891919619692533505 = new Monomial (coeff,t_604399214107159699);

	mpz_set_si(coeff,-32);
	Monomial * m_8193611561415102671 = new Monomial (coeff,t_8964013845923819438->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_7193650561672103056 = new Monomial (coeff,t_6482719227796732235->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_3394415405119110063 = new Monomial (coeff,t_304906389435672994->copy());

	mpz_set_ui(coeff,16);
	Monomial * m_7699994247206697647 = new Monomial (coeff,t_5385742027194771562->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_922229117511063727 = new Monomial (coeff,t_2356616159307131802->copy());

	mpz_set_ui(coeff,128);
	Monomial * m_173993486860062566 = new Monomial (coeff,t_7729547518900561764->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_1538339198401650093 = new Monomial (coeff,t_4998648586607407508->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_1435577580228956652 = new Monomial (coeff,t_2790426954053954291->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_3862447550529416939 = new Monomial (coeff,t_4525116919213147589->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_3874487349509702166 = new Monomial (coeff,t_8520729504962856128->copy());

	mpz_set_ui(coeff,16);
	Monomial * m_4694333430216376964 = new Monomial (coeff,t_176799468383171751->copy());

	mpz_set_ui(coeff,192);
	Monomial * m_5113542098380201892 = new Monomial (coeff,t_2627338361197615039->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_922229117511063720 = new Monomial (coeff,t_2356616159307131805->copy());

	mpz_set_si(coeff,-64);
	Monomial * m_6798918866474894686 = new Monomial (coeff,t_3106396165937709866->copy());

	mpz_set_ui(coeff,32);
	Monomial * m_4925343521602038233 = new Monomial (coeff,t_7329123895943991064->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_6496900620290989447 = new Monomial (coeff,t_7329123895943991071->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_3394415405119110056 = new Monomial (coeff,t_304906389435672997->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_77859882999937040 = new Monomial (coeff,t_5356723160064133193->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_6874594350266703554 = new Monomial (coeff,t_8925989568491694856->copy());

	mpz_set_si(coeff,-128);
	Monomial * m_3126174397139736358 = new Monomial (coeff,t_1479278771248836234->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_2770262008012331175 = new Monomial (coeff,t_7729547518900561765->copy());

	mpz_set_ui(coeff,16);
	Monomial * m_7774349493623007772 = new Monomial (coeff,t_6887314098037458387->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_5577494030930978634 = new Monomial (coeff,t_8602795560333161092->copy());

	mpz_set_ui(coeff,16);
	Monomial * m_7746738826449853829 = new Monomial (coeff,t_4385733027227771666->copy());

	mpz_set_ui(coeff,96);
	Monomial * m_1621876161099543777 = new Monomial (coeff,t_5248788502526065922->copy());

	mpz_set_ui(coeff,128);
	Monomial * m_3514469416139695799 = new Monomial (coeff,t_9208444510773049883->copy());

	mpz_set_si(coeff,-16);
	Monomial * m_9128716848140444191 = new Monomial (coeff,t_5055334614520655842->copy());

	mpz_set_si(coeff,-64);
	Monomial * m_1181144228284354623 = new Monomial (coeff,t_1220134653708905313->copy());

	mpz_set_ui(coeff,128);
	Monomial * m_8774832241746803268 = new Monomial (coeff,t_6711558412874839058->copy());

	mpz_set_ui(coeff,64);
	Monomial * m_1770265007993331059 = new Monomial (coeff,t_8729560518951561825->copy());

	mpz_set_ui(coeff,96);
	Monomial * m_7700301881869411458 = new Monomial (coeff,t_8520729504962856129->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_5906567993981626299 = new Monomial (coeff,t_7252980033692690098->copy());

	mpz_set_si(coeff,-64);
	Monomial * m_7587417285397521096 = new Monomial (coeff,t_1415051105974731660->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_7193650561672103057 = new Monomial (coeff,t_6482719227796732236->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_7193650561672103062 = new Monomial (coeff,t_6482719227796732237->copy());

	mpz_set_ui(coeff,16);
	Monomial * m_7138646306155558637 = new Monomial (coeff,t_3485344240293081962->copy());

	mpz_set_si(coeff,-224);
	Monomial * m_4153909473486796003 = new Monomial (coeff,t_2415056105785731132->copy());

	mpz_set_si(coeff,-64);
	Monomial * m_8587422285208520561 = new Monomial (coeff,t_2415056105785731131->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_479808370493456149 = new Monomial (coeff,t_7957572795493287768->copy());

	mpz_set_si(coeff,-32);
	Monomial * m_4725447860428984017 = new Monomial (coeff,t_3926823968520693954->copy());

	mpz_set_ui(coeff,16);
	Monomial * m_7653691274469346189 = new Monomial (coeff,t_7391644909704896746->copy());

	push_mstack(m_9104664561816002391->copy());
	push_mstack(m_1568957090038920995->copy());
	push_mstack(m_9214303397039452427->copy());
	push_mstack(m_6586757166925088833->copy());
	push_mstack(m_50311341388553175->copy());
	push_mstack(m_5625928222391316353->copy());
	push_mstack(m_3488540307060008778->copy());
	push_mstack(m_7417194704702560909->copy());
	push_mstack(m_8396024892905481551->copy());
	push_mstack(m_4666853960958055022->copy());
	push_mstack(m_3140360740260629205->copy());
	push_mstack(m_2650580220032812225->copy());
	push_mstack(m_5489281966339621713->copy());
	push_mstack(m_4155826145754657936->copy());
	push_mstack(m_739472552794898846->copy());
	push_mstack(m_7462373664099153630->copy());
	push_mstack(m_7825371027181840881->copy());
	push_mstack(m_1083044369228433508->copy());
	push_mstack(m_5739981342729944954->copy());
	push_mstack(m_7408912328830731->copy());
	push_mstack(m_1861935524217380098->copy());
	push_mstack(m_8909805348912853595->copy());
	push_mstack(m_3870552654796361874->copy());
	push_mstack(m_2741047417897221736->copy());
	push_mstack(m_7163678312255027900->copy());
	push_mstack(m_6992774097515625429->copy());
	push_mstack(m_2670866737757992469->copy());
	push_mstack(m_7937048880004429718->copy());
	push_mstack(m_6743573970143616533->copy());
	push_mstack(m_6883336518534669728->copy());
	push_mstack(m_1752332034185600136->copy());
	push_mstack(m_116726481530330107->copy());
	push_mstack(m_4193699172766922093->copy());
	push_mstack(m_1580496222781227278->copy());
	push_mstack(m_1140914777391298966->copy());
	push_mstack(m_8377361506281704071->copy());
	push_mstack(m_572882281871596335->copy());
	push_mstack(m_5990615793266922572->copy());
	push_mstack(m_2334894414316945515->copy());
	push_mstack(m_1935060568134522444->copy());
	push_mstack(m_3276538441069737238->copy());
	push_mstack(m_6883336518534669725->copy());
	push_mstack(m_883286518456669768->copy());
	push_mstack(m_8878684525911869203->copy());
	push_mstack(m_2059620518000915593->copy());
	push_mstack(m_8753504022126224320->copy());
	push_mstack(m_4417424195299696389->copy());
	push_mstack(m_3532315163485605168->copy());
	push_mstack(m_6878098574075051597->copy());
	push_mstack(m_7190082918267157529->copy());
	push_mstack(m_5452550683656795250->copy());
	push_mstack(m_6450754892630604493->copy());
	push_mstack(m_260540447448101793->copy());
	push_mstack(m_3927319967144557343->copy());
	push_mstack(m_1861935524217380096->copy());
	push_mstack(m_6452559683687795307->copy());
	push_mstack(m_535652293032991979->copy());
	push_mstack(m_1589022010305071550->copy());
	push_mstack(m_7562234897842223108->copy());
	push_mstack(m_5685959495889184258->copy());
	push_mstack(m_5493587513535795526->copy());
	push_mstack(m_8977416623760607542->copy());
	push_mstack(m_8937053880007429666->copy());
	push_mstack(m_402363273204887410->copy());
	push_mstack(m_6489290966298621602->copy());
	push_mstack(m_7973192114357579702->copy());
	push_mstack(m_225667655814964405->copy());
	push_mstack(m_891254232242817161->copy());
	push_mstack(m_2861944524240380115->copy());
	push_mstack(m_599412949207405853->copy());
	push_mstack(m_1093555934268442245->copy());
	push_mstack(m_4056325404925559158->copy());
	push_mstack(m_1224550214727448670->copy());
	push_mstack(m_6417740282678023986->copy());
	push_mstack(m_7319616456320007435->copy());
	push_mstack(m_4918716186160845573->copy());
	push_mstack(m_1059615517997915616->copy());
	push_mstack(m_1844159854003341578->copy());
	push_mstack(m_7489287966317621650->copy());
	push_mstack(m_6366604841396425560->copy());
	push_mstack(m_8153864921644340982->copy());
	push_mstack(m_1127757844635480951->copy());
	push_mstack(m_6142923651108595564->copy());
	push_mstack(m_7100692068131394299->copy());
	push_mstack(m_347731813756299781->copy());
	push_mstack(m_3205615482296837930->copy());
	push_mstack(m_4931829372832396455->copy());
	push_mstack(m_5318467113261106043->copy());
	push_mstack(m_5977655840781114254->copy());
	push_mstack(m_4934179971783772946->copy());
	push_mstack(m_464208403945311855->copy());
	push_mstack(m_4205794560872338757->copy());
	push_mstack(m_7934158971516772419->copy());
	push_mstack(m_371391210835972229->copy());
	push_mstack(m_477932723891432870->copy());
	push_mstack(m_6998966950683614089->copy());
	push_mstack(m_4822478912074424257->copy());
	push_mstack(m_5486436016943975781->copy());
	push_mstack(m_7976338658889874130->copy());
	push_mstack(m_7205837560925338665->copy());
	push_mstack(m_5560852074695054177->copy());
	push_mstack(m_3343657216887153682->copy());
	push_mstack(m_2328689697472814017->copy());
	push_mstack(m_3173051697569003901->copy());
	push_mstack(m_1753543314265943773->copy());
	push_mstack(m_7699326369260505364->copy());
	push_mstack(m_7400973548215009750->copy());
	push_mstack(m_7754315062558928136->copy());
	push_mstack(m_7752626047462534669->copy());
	push_mstack(m_1030730963040328462->copy());
	push_mstack(m_2620594034141876992->copy());
	push_mstack(m_2171338909067427793->copy());
	push_mstack(m_1901315615640712045->copy());
	push_mstack(m_30721963009328407->copy());
	push_mstack(m_5363432685012506514->copy());
	push_mstack(m_2104891121306794951->copy());
	push_mstack(m_4225676670239869874->copy());
	push_mstack(m_4822478912074424262->copy());
	push_mstack(m_3590211135183224228->copy());
	push_mstack(m_1470871668911071868->copy());
	push_mstack(m_3035915008923412146->copy());
	push_mstack(m_3881813962401041272->copy());
	push_mstack(m_6496169184221624797->copy());
	push_mstack(m_464208403945311850->copy());
	push_mstack(m_2470876668914071852->copy());
	push_mstack(m_16509678909703728->copy());
	push_mstack(m_4251682165596160941->copy());
	push_mstack(m_1030730963040328457->copy());
	push_mstack(m_4464819975819065452->copy());
	push_mstack(m_2334232078436734022->copy());
	push_mstack(m_5225269439360978410->copy());
	push_mstack(m_905533869647441518->copy());
	push_mstack(m_2173058697570003733->copy());
	push_mstack(m_200093757314409955->copy());
	push_mstack(m_5382767869282026966->copy());
	push_mstack(m_7822585912639425130->copy());
	push_mstack(m_1987124822629572196->copy());
	push_mstack(m_3173051697569003898->copy());
	push_mstack(m_1200086757313409996->copy());
	push_mstack(m_396770683821442427->copy());
	push_mstack(m_5432742146448060376->copy());
	push_mstack(m_2603484945221435914->copy());
	push_mstack(m_5486436016943975780->copy());
	push_mstack(m_311676794170477967->copy());
	push_mstack(m_7822585912639425132->copy());
	push_mstack(m_7934158971516772422->copy());
	push_mstack(m_4486427016912975692->copy());
	push_mstack(m_7699326369260505365->copy());
	push_mstack(m_43402624862056869->copy());
	push_mstack(m_8957097349070363275->copy());
	push_mstack(m_7365713230790137202->copy());
	push_mstack(m_1242819830394550836->copy());
	push_mstack(m_2143557286725240548->copy());
	push_mstack(m_5998877950172613329->copy());
	push_mstack(m_200093757314409956->copy());
	push_mstack(m_5881790229396670029->copy());
	push_mstack(m_1649104658764171754->copy());
	push_mstack(m_5925722517070317099->copy());
	push_mstack(m_8377602168878100806->copy());
	push_mstack(m_7334255759241454497->copy());
	push_mstack(m_1449207827196456628->copy());
	push_mstack(m_1575574815346588533->copy());
	push_mstack(m_5072723386389917858->copy());
	push_mstack(m_981012423617767708->copy());
	push_mstack(m_2311349967957247894->copy());
	push_mstack(m_6191607442297259293->copy());
	push_mstack(m_2379738321323192777->copy());
	push_mstack(m_2116551473607222838->copy());
	push_mstack(m_3694328430213376973->copy());
	push_mstack(m_6117044945679642377->copy());
	push_mstack(m_5925722517070317102->copy());
	push_mstack(m_1649104658764171759->copy());
	push_mstack(m_4915329906849667949->copy());
	push_mstack(m_6745559714126192867->copy());
	push_mstack(m_3245448943457158228->copy());
	push_mstack(m_1786643601732435348->copy());
	push_mstack(m_1338207728603571583->copy());
	push_mstack(m_563636931765380511->copy());
	push_mstack(m_1620589034138876977->copy());
	push_mstack(m_8959305845634514310->copy());
	push_mstack(m_4499432735928770657->copy());
	push_mstack(m_7537107713678495408->copy());
	push_mstack(m_4738917069187657563->copy());
	push_mstack(m_8900277346504847330->copy());
	push_mstack(m_4717028345938854011->copy());
	push_mstack(m_4941938168396622119->copy());
	push_mstack(m_735496825519608002->copy());
	push_mstack(m_2173058697570003731->copy());
	push_mstack(m_2101812929882703473->copy());
	push_mstack(m_5261433641576388828->copy());
	push_mstack(m_2926168603715265150->copy());
	push_mstack(m_749337028767712466->copy());
	push_mstack(m_812982770049516399->copy());
	push_mstack(m_522064276127567241->copy());
	push_mstack(m_5062323297018154286->copy());
	push_mstack(m_8462847543120272133->copy());
	push_mstack(m_2173058697570003732->copy());
	push_mstack(m_4934179971783772952->copy());
	push_mstack(m_1748318697048299860->copy());
	push_mstack(m_2467619909639068829->copy());
	push_mstack(m_1200086757313409997->copy());
	push_mstack(m_5178499688477657887->copy());
	push_mstack(m_3617082479859627715->copy());
	push_mstack(m_4934179971783772945->copy());
	push_mstack(m_5478925382798364034->copy());
	push_mstack(m_4486427016912975691->copy());
	push_mstack(m_1142000726707459426->copy());
	push_mstack(m_8834360734452785007->copy());
	push_mstack(m_4732070845762564222->copy());
	push_mstack(m_3239347140091240266->copy());
	push_mstack(m_4298630350691455223->copy());
	push_mstack(m_9209079552018663298->copy());
	push_mstack(m_4858950541422649192->copy());
	push_mstack(m_8699331369263505348->copy());
	push_mstack(m_5656216784134219477->copy());
	push_mstack(m_7333813913282261756->copy());
	push_mstack(m_7205837560925338666->copy());
	push_mstack(m_956610375380943770->copy());
	push_mstack(m_421166355302543915->copy());
	push_mstack(m_1311681794173477979->copy());
	push_mstack(m_3871247453558570634->copy());
	push_mstack(m_43402624862056866->copy());
	push_mstack(m_5858979541697649780->copy());
	push_mstack(m_8461780441329158119->copy());
	push_mstack(m_4898015980873404350->copy());
	push_mstack(m_7390454751578054618->copy());
	push_mstack(m_4233915781373148944->copy());
	push_mstack(m_1882489298383564529->copy());
	push_mstack(m_7474725586076520841->copy());
	push_mstack(m_6663352449510349703->copy());
	push_mstack(m_6986529327288256427->copy());
	push_mstack(m_1366742895759609365->copy());
	push_mstack(m_7656044241527513323->copy());
	push_mstack(m_7167179949122172133->copy());
	push_mstack(m_8084373974548539773->copy());
	push_mstack(m_6442357874616488137->copy());
	push_mstack(m_2995010194876047225->copy());
	push_mstack(m_758747740127234674->copy());
	push_mstack(m_4056643640803622465->copy());
	push_mstack(m_4355637910608313171->copy());
	push_mstack(m_4598797409255693507->copy());
	push_mstack(m_4723315782937944117->copy());
	push_mstack(m_6313001481874397073->copy());
	push_mstack(m_485476964015219842->copy());
	push_mstack(m_3590379310813611451->copy());
	push_mstack(m_8033879726777958681->copy());
	push_mstack(m_2731178923567975874->copy());
	push_mstack(m_8316629107280183066->copy());
	push_mstack(m_1280884035939336679->copy());
	push_mstack(m_1488733645688234253->copy());
	push_mstack(m_527854901861121239->copy());
	push_mstack(m_9033884726780958663->copy());
	push_mstack(m_5883254106001268248->copy());
	push_mstack(m_3056638640800622478->copy());
	push_mstack(m_426259780836339564->copy());
	push_mstack(m_5573862219737661281->copy());
	push_mstack(m_8545304186433760408->copy());
	push_mstack(m_7562863417656141067->copy());
	push_mstack(m_2886281120807349621->copy());
	push_mstack(m_3941282247590541616->copy());
	push_mstack(m_7794776927830501077->copy());
	push_mstack(m_1343714956541313049->copy());
	push_mstack(m_8651055530903330312->copy());
	push_mstack(m_6725071862179236589->copy());
	push_mstack(m_641856374763918884->copy());
	push_mstack(m_5084297121785526274->copy());
	push_mstack(m_7009243800786145683->copy());
	push_mstack(m_953170167230579589->copy());
	push_mstack(m_2590370310790611435->copy());
	push_mstack(m_3056638640800622480->copy());
	push_mstack(m_4358135557096748419->copy());
	push_mstack(m_3809451655005510490->copy());
	push_mstack(m_7512279328594876714->copy());
	push_mstack(m_5686462650203935320->copy());
	push_mstack(m_9019836137997592563->copy());
	push_mstack(m_407789557108378257->copy());
	push_mstack(m_666384376438064180->copy());
	push_mstack(m_5105307656166880431->copy());
	push_mstack(m_2809446655002510487->copy());
	push_mstack(m_4459868808903505240->copy());
	push_mstack(m_4056643640803622466->copy());
	push_mstack(m_9130101966442368676->copy());
	push_mstack(m_3652072716935742915->copy());
	push_mstack(m_5459873808906505220->copy());
	push_mstack(m_6581946279281973484->copy());
	push_mstack(m_3726541056031414407->copy());
	push_mstack(m_5974194503831482063->copy());
	push_mstack(m_3929886663582776301->copy());
	push_mstack(m_523860526803434323->copy());
	push_mstack(m_1280884035939336678->copy());
	push_mstack(m_241277260127765941->copy());
	push_mstack(m_6847482718273797474->copy());
	push_mstack(m_4084288121826526514->copy());
	push_mstack(m_8611463540396697901->copy());
	push_mstack(m_2523866526789434361->copy());
	push_mstack(m_6102943812502559784->copy());
	push_mstack(m_1077230879831828653->copy());
	push_mstack(m_2776483492595528168->copy());
	push_mstack(m_4911026331875338683->copy());
	push_mstack(m_2336287172823628130->copy());
	push_mstack(m_8360743579447237928->copy());
	push_mstack(m_5839300414498035306->copy());
	push_mstack(m_2971226292125787357->copy());
	push_mstack(m_1336282172820628142->copy());
	push_mstack(m_623679056201082277->copy());
	push_mstack(m_2218914560917117555->copy());
	push_mstack(m_3609346366227766686->copy());
	push_mstack(m_3610084534774146608->copy());
	push_mstack(m_1343570593513387178->copy());
	push_mstack(m_652032035251726845->copy());
	push_mstack(m_186831208245796056->copy());
	push_mstack(m_3003749035656713478->copy());
	push_mstack(m_8636399747670185850->copy());
	push_mstack(m_1191788078799326332->copy());
	push_mstack(m_261423801441340710->copy());
	push_mstack(m_7576532465437046509->copy());
	push_mstack(m_6858905369771695849->copy());
	push_mstack(m_7376025075910789066->copy());
	push_mstack(m_3989343550719309565->copy());
	push_mstack(m_4360413814298484464->copy());
	push_mstack(m_28002237277353859->copy());
	push_mstack(m_4158661918438585010->copy());
	push_mstack(m_3159045680408643120->copy());
	push_mstack(m_2626146739751707886->copy());
	push_mstack(m_343565593510387190->copy());
	push_mstack(m_66837305206115519->copy());
	push_mstack(m_1176517264308775012->copy());
	push_mstack(m_4609351366230766675->copy());
	push_mstack(m_6000261645082650055->copy());
	push_mstack(m_4928950368014939813->copy());
	push_mstack(m_8968701746786384363->copy());
	push_mstack(m_4144448824867690316->copy());
	push_mstack(m_2859335675727020038->copy());
	push_mstack(m_7786325143369653037->copy());
	push_mstack(m_6466328402296013741->copy());
	push_mstack(m_994849265555663460->copy());
	push_mstack(m_1860211652271857134->copy());
	push_mstack(m_5920488614448205112->copy());
	push_mstack(m_4504082291607180987->copy());
	push_mstack(m_7434875251915168979->copy());
	push_mstack(m_4492301638475801389->copy());
	push_mstack(m_7457401523181242492->copy());
	push_mstack(m_7880336951422196750->copy());
	push_mstack(m_2597755969548019900->copy());
	push_mstack(m_7474061816560383756->copy());
	push_mstack(m_1905350990981416657->copy());
	push_mstack(m_3949140426726856288->copy());
	push_mstack(m_2695008185264906918->copy());
	push_mstack(m_2939050201926891213->copy());
	push_mstack(m_7994912265876664043->copy());
	push_mstack(m_1759723462604230186->copy());
	push_mstack(m_852046345057861068->copy());
	push_mstack(m_3221596997705106633->copy());
	push_mstack(m_5140350782166877393->copy());
	push_mstack(m_6474056816557383774->copy());
	push_mstack(m_328984661118683985->copy());
	push_mstack(m_3167758002048266762->copy());
	push_mstack(m_3163066226733968390->copy());
	push_mstack(m_4431467888095329658->copy());
	push_mstack(m_6910156277733807192->copy());
	push_mstack(m_8162829400629799386->copy());
	push_mstack(m_176512264305775033->copy());
	push_mstack(m_5085990302980576350->copy());
	push_mstack(m_4812277256842588324->copy());
	push_mstack(m_2499217561209765629->copy());
	push_mstack(m_2166787368828103436->copy());
	push_mstack(m_5779185176275639718->copy());
	push_mstack(m_1053382630316773487->copy());
	push_mstack(m_7542878567241862360->copy());
	push_mstack(m_917703764001064036->copy());
	push_mstack(m_1457844783818249690->copy());
	push_mstack(m_3293630974170423782->copy());
	push_mstack(m_2567261625782152345->copy());
	push_mstack(m_8354240807563036439->copy());
	push_mstack(m_8674999814359297498->copy());
	push_mstack(m_8094385925689820550->copy());
	push_mstack(m_966007501449357727->copy());
	push_mstack(m_3094328925354820022->copy());
	push_mstack(m_6094371925663820546->copy());
	push_mstack(m_5264173279922970255->copy());
	push_mstack(m_4702096393951890739->copy());
	push_mstack(m_5094342925388819986->copy());
	push_mstack(m_4094333925357820030->copy());
	push_mstack(m_1446530740612615085->copy());
	push_mstack(m_8682948485887848569->copy());
	push_mstack(m_1966012501452357739->copy());
	push_mstack(m_1794728972600554170->copy());
	push_mstack(m_1033998498536642185->copy());
	push_mstack(m_2876489379407643613->copy());
	Polynomial * p_0 = build_poly();

	fprintf(stdout, "Multiplying mul_0 and p_0 yields:\n");
	Polynomial * mul_1 = multiply_poly(mul_0,p_0);
	mul_1->print(stdout);fprintf(stdout,"\n");
	delete(mul_0);delete(p_0);

	push_mstack(m_7562234897842223108->copy());
	push_mstack(m_7334591819367846785->copy());
	push_mstack(m_8909805348912853595->copy());
	push_mstack(m_1861935524217380098->copy());
	push_mstack(m_7408912328830731->copy());
	push_mstack(m_4155826145754657936->copy());
	push_mstack(m_5625928222391316353->copy());
	push_mstack(m_7462373664099153630->copy());
	push_mstack(m_1083044369228433508->copy());
	push_mstack(m_7825371027181840881->copy());
	push_mstack(m_6586757166925088833->copy());
	push_mstack(m_4394200827290693302->copy());
	push_mstack(m_599412949207405853->copy());
	push_mstack(m_5739981342729944954->copy());
	push_mstack(m_2627919318376789148->copy());
	push_mstack(m_3190408477757770872->copy());
	push_mstack(m_2650580220032812225->copy());
	push_mstack(m_1844159854003341578->copy());
	push_mstack(m_225667655814964405->copy());
	push_mstack(m_891254232242817161->copy());
	push_mstack(m_2861944524240380115->copy());
	push_mstack(m_1861935524217380096->copy());
	push_mstack(m_1935060568134522444->copy());
	push_mstack(m_2334894414316945515->copy());
	push_mstack(m_3870552654796361874->copy());
	push_mstack(m_7319616456320007435->copy());
	push_mstack(m_9214303397039452427->copy());
	push_mstack(m_1568957090038920995->copy());
	push_mstack(m_6878678526117869817->copy());
	push_mstack(m_1224550214727448670->copy());
	push_mstack(m_4056325404925559158->copy());
	push_mstack(m_6417740282678023986->copy());
	push_mstack(m_6452559683687795307->copy());
	push_mstack(m_3276538441069737238->copy());
	push_mstack(m_4193699172766922093->copy());
	push_mstack(m_7489287966317621650->copy());
	push_mstack(m_7937048880004429718->copy());
	push_mstack(m_6992774097515625429->copy());
	push_mstack(m_2991217137048741202->copy());
	push_mstack(m_6743573970143616533->copy());
	push_mstack(m_1580496222781227278->copy());
	push_mstack(m_1140914777391298966->copy());
	push_mstack(m_8649549020671362514->copy());
	push_mstack(m_7973192114357579702->copy());
	push_mstack(m_1715706449042189973->copy());
	push_mstack(m_6489290966298621602->copy());
	push_mstack(m_6878098574075051597->copy());
	push_mstack(m_6450754892630604493->copy());
	push_mstack(m_3927319967144557343->copy());
	push_mstack(m_6883336518534669728->copy());
	push_mstack(m_116726481530330107->copy());
	push_mstack(m_572882281871596335->copy());
	push_mstack(m_5990615793266922572->copy());
	push_mstack(m_4666853960958055022->copy());
	push_mstack(m_8396024892905481551->copy());
	push_mstack(m_5493587513535795526->copy());
	push_mstack(m_883286518456669768->copy());
	push_mstack(m_6883336518534669725->copy());
	push_mstack(m_8977416623760607542->copy());
	push_mstack(m_8878684525911869203->copy());
	push_mstack(m_7190082918267157529->copy());
	push_mstack(m_4417424195299696389->copy());
	push_mstack(m_8753504022126224320->copy());
	push_mstack(m_5452550683656795250->copy());
	push_mstack(m_2059620518000915593->copy());
	push_mstack(m_3532315163485605168->copy());
	push_mstack(m_1752332034185600136->copy());
	push_mstack(m_1059615517997915616->copy());
	push_mstack(m_4918716186160845573->copy());
	push_mstack(m_2741047417897221736->copy());
	push_mstack(m_402363273204887410->copy());
	push_mstack(m_8937053880007429666->copy());
	push_mstack(m_50311341388553175->copy());
	push_mstack(m_6366604841396425560->copy());
	push_mstack(m_260540447448101793->copy());
	push_mstack(m_535652293032991979->copy());
	push_mstack(m_5685959495889184258->copy());
	push_mstack(m_739472552794898846->copy());
	push_mstack(m_8153864921644340982->copy());
	push_mstack(m_5489281966339621713->copy());
	push_mstack(m_3488540307060008778->copy());
	push_mstack(m_5977655840781114254->copy());
	push_mstack(m_1127757844635480951->copy());
	push_mstack(m_6142923651108595564->copy());
	push_mstack(m_3205615482296837930->copy());
	push_mstack(m_5318467113261106043->copy());
	push_mstack(m_347731813756299781->copy());
	push_mstack(m_4931829372832396455->copy());
	push_mstack(m_7100692068131394299->copy());
	push_mstack(m_4934179971783772946->copy());
	push_mstack(m_464208403945311855->copy());
	push_mstack(m_4205794560872338757->copy());
	push_mstack(m_7934158971516772419->copy());
	push_mstack(m_371391210835972229->copy());
	push_mstack(m_477932723891432870->copy());
	push_mstack(m_6998966950683614089->copy());
	push_mstack(m_4822478912074424257->copy());
	push_mstack(m_5486436016943975781->copy());
	push_mstack(m_7976338658889874130->copy());
	push_mstack(m_7205837560925338665->copy());
	push_mstack(m_5560852074695054177->copy());
	push_mstack(m_3343657216887153682->copy());
	push_mstack(m_2328689697472814017->copy());
	push_mstack(m_3173051697569003901->copy());
	push_mstack(m_1753543314265943773->copy());
	push_mstack(m_7699326369260505364->copy());
	push_mstack(m_7400973548215009750->copy());
	push_mstack(m_7754315062558928136->copy());
	push_mstack(m_7752626047462534669->copy());
	push_mstack(m_1030730963040328462->copy());
	push_mstack(m_2620594034141876992->copy());
	push_mstack(m_2171338909067427793->copy());
	push_mstack(m_1901315615640712045->copy());
	push_mstack(m_30721963009328407->copy());
	push_mstack(m_5363432685012506514->copy());
	push_mstack(m_2104891121306794951->copy());
	push_mstack(m_4225676670239869874->copy());
	push_mstack(m_4822478912074424262->copy());
	push_mstack(m_3590211135183224228->copy());
	push_mstack(m_1470871668911071868->copy());
	push_mstack(m_3035915008923412146->copy());
	push_mstack(m_3881813962401041272->copy());
	push_mstack(m_6496169184221624797->copy());
	push_mstack(m_464208403945311850->copy());
	push_mstack(m_2470876668914071852->copy());
	push_mstack(m_16509678909703728->copy());
	push_mstack(m_4251682165596160941->copy());
	push_mstack(m_1030730963040328457->copy());
	push_mstack(m_4464819975819065452->copy());
	push_mstack(m_2334232078436734022->copy());
	push_mstack(m_5225269439360978410->copy());
	push_mstack(m_905533869647441518->copy());
	push_mstack(m_2173058697570003733->copy());
	push_mstack(m_200093757314409955->copy());
	push_mstack(m_5382767869282026966->copy());
	push_mstack(m_7822585912639425130->copy());
	push_mstack(m_1987124822629572196->copy());
	push_mstack(m_3173051697569003898->copy());
	push_mstack(m_1200086757313409996->copy());
	push_mstack(m_396770683821442427->copy());
	push_mstack(m_5432742146448060376->copy());
	push_mstack(m_2603484945221435914->copy());
	push_mstack(m_5486436016943975780->copy());
	push_mstack(m_311676794170477967->copy());
	push_mstack(m_7822585912639425132->copy());
	push_mstack(m_7934158971516772422->copy());
	push_mstack(m_4486427016912975692->copy());
	push_mstack(m_7699326369260505365->copy());
	push_mstack(m_43402624862056869->copy());
	push_mstack(m_8957097349070363275->copy());
	push_mstack(m_7365713230790137202->copy());
	push_mstack(m_1242819830394550836->copy());
	push_mstack(m_2143557286725240548->copy());
	push_mstack(m_5998877950172613329->copy());
	push_mstack(m_200093757314409956->copy());
	push_mstack(m_5881790229396670029->copy());
	push_mstack(m_1649104658764171754->copy());
	push_mstack(m_5925722517070317099->copy());
	push_mstack(m_8377602168878100806->copy());
	push_mstack(m_7334255759241454497->copy());
	push_mstack(m_1449207827196456628->copy());
	push_mstack(m_1575574815346588533->copy());
	push_mstack(m_5072723386389917858->copy());
	push_mstack(m_981012423617767708->copy());
	push_mstack(m_2311349967957247894->copy());
	push_mstack(m_6191607442297259293->copy());
	push_mstack(m_2379738321323192777->copy());
	push_mstack(m_2116551473607222838->copy());
	push_mstack(m_3694328430213376973->copy());
	push_mstack(m_6117044945679642377->copy());
	push_mstack(m_5925722517070317102->copy());
	push_mstack(m_1649104658764171759->copy());
	push_mstack(m_4915329906849667949->copy());
	push_mstack(m_6745559714126192867->copy());
	push_mstack(m_3245448943457158228->copy());
	push_mstack(m_1786643601732435348->copy());
	push_mstack(m_1338207728603571583->copy());
	push_mstack(m_563636931765380511->copy());
	push_mstack(m_1620589034138876977->copy());
	push_mstack(m_8959305845634514310->copy());
	push_mstack(m_4499432735928770657->copy());
	push_mstack(m_7537107713678495408->copy());
	push_mstack(m_4738917069187657563->copy());
	push_mstack(m_8900277346504847330->copy());
	push_mstack(m_4717028345938854011->copy());
	push_mstack(m_4941938168396622119->copy());
	push_mstack(m_735496825519608002->copy());
	push_mstack(m_2173058697570003731->copy());
	push_mstack(m_2101812929882703473->copy());
	push_mstack(m_5261433641576388828->copy());
	push_mstack(m_2926168603715265150->copy());
	push_mstack(m_749337028767712466->copy());
	push_mstack(m_812982770049516399->copy());
	push_mstack(m_522064276127567241->copy());
	push_mstack(m_5062323297018154286->copy());
	push_mstack(m_8462847543120272133->copy());
	push_mstack(m_2173058697570003732->copy());
	push_mstack(m_4934179971783772952->copy());
	push_mstack(m_1748318697048299860->copy());
	push_mstack(m_2467619909639068829->copy());
	push_mstack(m_1200086757313409997->copy());
	push_mstack(m_5178499688477657887->copy());
	push_mstack(m_3617082479859627715->copy());
	push_mstack(m_4934179971783772945->copy());
	push_mstack(m_5478925382798364034->copy());
	push_mstack(m_4486427016912975691->copy());
	push_mstack(m_1142000726707459426->copy());
	push_mstack(m_8834360734452785007->copy());
	push_mstack(m_4732070845762564222->copy());
	push_mstack(m_3239347140091240266->copy());
	push_mstack(m_4298630350691455223->copy());
	push_mstack(m_9209079552018663298->copy());
	push_mstack(m_4858950541422649192->copy());
	push_mstack(m_8699331369263505348->copy());
	push_mstack(m_5656216784134219477->copy());
	push_mstack(m_7333813913282261756->copy());
	push_mstack(m_7205837560925338666->copy());
	push_mstack(m_956610375380943770->copy());
	push_mstack(m_421166355302543915->copy());
	push_mstack(m_1311681794173477979->copy());
	push_mstack(m_3871247453558570634->copy());
	push_mstack(m_43402624862056866->copy());
	push_mstack(m_5858979541697649780->copy());
	push_mstack(m_8461780441329158119->copy());
	push_mstack(m_4898015980873404350->copy());
	push_mstack(m_7390454751578054618->copy());
	push_mstack(m_4233915781373148944->copy());
	push_mstack(m_1882489298383564529->copy());
	push_mstack(m_7474725586076520841->copy());
	push_mstack(m_6663352449510349703->copy());
	push_mstack(m_6986529327288256427->copy());
	push_mstack(m_1366742895759609365->copy());
	push_mstack(m_7656044241527513323->copy());
	push_mstack(m_7167179949122172133->copy());
	push_mstack(m_8084373974548539773->copy());
	push_mstack(m_6442357874616488137->copy());
	push_mstack(m_2995010194876047225->copy());
	push_mstack(m_9034446518438222646->copy());
	push_mstack(m_8033879726777958681->copy());
	push_mstack(m_2731178923567975874->copy());
	push_mstack(m_1488733645688234253->copy());
	push_mstack(m_4056643640803622465->copy());
	push_mstack(m_4031586764294785437->copy());
	push_mstack(m_9019836137997592563->copy());
	push_mstack(m_1343714956541313049->copy());
	push_mstack(m_407789557108378257->copy());
	push_mstack(m_3726541056031414407->copy());
	push_mstack(m_1280884035939336679->copy());
	push_mstack(m_6313001481874397073->copy());
	push_mstack(m_4084288121826526514->copy());
	push_mstack(m_953170167230579589->copy());
	push_mstack(m_3929886663582776301->copy());
	push_mstack(m_5686462650203935320->copy());
	push_mstack(m_9033884726780958663->copy());
	push_mstack(m_8611463540396697901->copy());
	push_mstack(m_5084297121785526274->copy());
	push_mstack(m_7512279328594876714->copy());
	push_mstack(m_9130101966442368676->copy());
	push_mstack(m_4825123762069048326->copy());
	push_mstack(m_527854901861121239->copy());
	push_mstack(m_2886281120807349621->copy());
	push_mstack(m_6725071862179236589->copy());
	push_mstack(m_6847482718273797474->copy());
	push_mstack(m_641856374763918884->copy());
	push_mstack(m_5974194503831482063->copy());
	push_mstack(m_2590370310790611435->copy());
	push_mstack(m_523860526803434323->copy());
	push_mstack(m_3590379310813611451->copy());
	push_mstack(m_8161048427101358398->copy());
	push_mstack(m_5105307656166880431->copy());
	push_mstack(m_8651055530903330312->copy());
	push_mstack(m_5586792342688796886->copy());
	push_mstack(m_4598797409255693507->copy());
	push_mstack(m_5573862219737661281->copy());
	push_mstack(m_6214211996395277894->copy());
	push_mstack(m_4056643640803622466->copy());
	push_mstack(m_1280884035939336678->copy());
	push_mstack(m_1586400041365173292->copy());
	push_mstack(m_2523866526789434361->copy());
	push_mstack(m_4358135557096748419->copy());
	push_mstack(m_6102943812502559784->copy());
	push_mstack(m_3809451655005510490->copy());
	push_mstack(m_426259780836339564->copy());
	push_mstack(m_8545304186433760408->copy());
	push_mstack(m_4459868808903505240->copy());
	push_mstack(m_3099195120562490879->copy());
	push_mstack(m_7881749990431030641->copy());
	push_mstack(m_5883254106001268248->copy());
	push_mstack(m_6581946279281973484->copy());
	push_mstack(m_3056638640800622478->copy());
	push_mstack(m_4723315782937944117->copy());
	push_mstack(m_666384376438064180->copy());
	push_mstack(m_241277260127765941->copy());
	push_mstack(m_758747740127234674->copy());
	push_mstack(m_3056638640800622480->copy());
	push_mstack(m_7794776927830501077->copy());
	push_mstack(m_1336282172820628142->copy());
	push_mstack(m_623679056201082277->copy());
	push_mstack(m_2336287172823628130->copy());
	push_mstack(m_2971226292125787357->copy());
	push_mstack(m_2218914560917117555->copy());
	push_mstack(m_1077230879831828653->copy());
	push_mstack(m_5839300414498035306->copy());
	push_mstack(m_8360743579447237928->copy());
	push_mstack(m_4911026331875338683->copy());
	push_mstack(m_2776483492595528168->copy());
	push_mstack(m_7376025075910789066->copy());
	push_mstack(m_28002237277353859->copy());
	push_mstack(m_652032035251726845->copy());
	push_mstack(m_1343570593513387178->copy());
	push_mstack(m_4360413814298484464->copy());
	push_mstack(m_343565593510387190->copy());
	push_mstack(m_186831208245796056->copy());
	push_mstack(m_2626146739751707886->copy());
	push_mstack(m_1191788078799326332->copy());
	push_mstack(m_6858905369771695849->copy());
	push_mstack(m_261423801441340710->copy());
	push_mstack(m_8636399747670185850->copy());
	push_mstack(m_3609346366227766686->copy());
	push_mstack(m_3536522532045199336->copy());
	push_mstack(m_3003749035656713478->copy());
	push_mstack(m_1176517264308775012->copy());
	push_mstack(m_2580744792151990986->copy());
	push_mstack(m_3610084534774146608->copy());
	push_mstack(m_4158661918438585010->copy());
	push_mstack(m_3159045680408643120->copy());
	push_mstack(m_66837305206115519->copy());
	push_mstack(m_4609351366230766675->copy());
	push_mstack(m_3989343550719309565->copy());
	push_mstack(m_4928950368014939813->copy());
	push_mstack(m_3790835143076745575->copy());
	push_mstack(m_4144448824867690316->copy());
	push_mstack(m_8968701746786384363->copy());
	push_mstack(m_7786325143369653037->copy());
	push_mstack(m_1860211652271857134->copy());
	push_mstack(m_994849265555663460->copy());
	push_mstack(m_2859335675727020038->copy());
	push_mstack(m_7434875251915168979->copy());
	push_mstack(m_6466328402296013741->copy());
	push_mstack(m_5920488614448205112->copy());
	push_mstack(m_7880336951422196750->copy());
	push_mstack(m_7457401523181242492->copy());
	push_mstack(m_4492301638475801389->copy());
	push_mstack(m_2597755969548019900->copy());
	push_mstack(m_1905350990981416657->copy());
	push_mstack(m_5140350782166877393->copy());
	push_mstack(m_2695008185264906918->copy());
	push_mstack(m_6474056816557383774->copy());
	push_mstack(m_1759723462604230186->copy());
	push_mstack(m_852046345057861068->copy());
	push_mstack(m_3949140426726856288->copy());
	push_mstack(m_7474061816560383756->copy());
	push_mstack(m_7994912265876664043->copy());
	push_mstack(m_3221596997705106633->copy());
	push_mstack(m_2939050201926891213->copy());
	push_mstack(m_3163066226733968390->copy());
	push_mstack(m_3167758002048266762->copy());
	push_mstack(m_328984661118683985->copy());
	push_mstack(m_4154748002733677099->copy());
	push_mstack(m_884093968343609859->copy());
	push_mstack(m_8162829400629799386->copy());
	push_mstack(m_176512264305775033->copy());
	push_mstack(m_5085990302980576350->copy());
	push_mstack(m_4812277256842588324->copy());
	push_mstack(m_917703764001064036->copy());
	push_mstack(m_3293630974170423782->copy());
	push_mstack(m_4325737353110787362->copy());
	push_mstack(m_7542878567241862360->copy());
	push_mstack(m_1053382630316773487->copy());
	push_mstack(m_1457844783818249690->copy());
	push_mstack(m_2499217561209765629->copy());
	push_mstack(m_2567261625782152345->copy());
	push_mstack(m_2166787368828103436->copy());
	push_mstack(m_8354240807563036439->copy());
	push_mstack(m_8674999814359297498->copy());
	push_mstack(m_8682948485887848569->copy());
	push_mstack(m_5264173279922970255->copy());
	push_mstack(m_1446530740612615085->copy());
	push_mstack(m_2876489379407643613->copy());
	push_mstack(m_4702096393951890739->copy());
	push_mstack(m_5094342925388819986->copy());
	push_mstack(m_8094385925689820550->copy());
	push_mstack(m_6094371925663820546->copy());
	push_mstack(m_4094333925357820030->copy());
	push_mstack(m_1966012501452357739->copy());
	push_mstack(m_1033998498536642185->copy());
	push_mstack(m_1794727972604554129->copy());
	push_mstack(m_966007501449357727->copy());
	push_mstack(m_3094328925354820022->copy());
	Polynomial * p_1 = build_poly();

	fprintf(stdout, "Multiplying mul_1 and p_1 yields:\n");
	Polynomial * mul_2 = multiply_poly(mul_1,p_1);
	mul_2->print(stdout);fprintf(stdout,"\n");
	delete(mul_1);delete(p_1);

	push_mstack(m_1861935524217380098->copy());
	push_mstack(m_8909805348912853595->copy());
	push_mstack(m_5625928222391316353->copy());
	push_mstack(m_50311341388553175->copy());
	push_mstack(m_1844159854003341578->copy());
	push_mstack(m_8396024892905481551->copy());
	push_mstack(m_4666853960958055022->copy());
	push_mstack(m_7462373664099153630->copy());
	push_mstack(m_1083044369228433508->copy());
	push_mstack(m_7825371027181840881->copy());
	push_mstack(m_7408912328830731->copy());
	push_mstack(m_5489281966339621713->copy());
	push_mstack(m_3140360740260629205->copy());
	push_mstack(m_2650580220032812225->copy());
	push_mstack(m_6878678526117869817->copy());
	push_mstack(m_1568957090038920995->copy());
	push_mstack(m_9214303397039452427->copy());
	push_mstack(m_5739981342729944954->copy());
	push_mstack(m_1093555934268442245->copy());
	push_mstack(m_599412949207405853->copy());
	push_mstack(m_6586757166925088833->copy());
	push_mstack(m_3488540307060008778->copy());
	push_mstack(m_1059615517997915616->copy());
	push_mstack(m_2741047417897221736->copy());
	push_mstack(m_4056325404925559158->copy());
	push_mstack(m_1224550214727448670->copy());
	push_mstack(m_6417740282678023986->copy());
	push_mstack(m_260540447448101793->copy());
	push_mstack(m_6450754892630604493->copy());
	push_mstack(m_3927319967144557343->copy());
	push_mstack(m_4193699172766922093->copy());
	push_mstack(m_7163678312255027900->copy());
	push_mstack(m_6992774097515625429->copy());
	push_mstack(m_7937048880004429718->copy());
	push_mstack(m_2670866737757992469->copy());
	push_mstack(m_6743573970143616533->copy());
	push_mstack(m_7973192114357579702->copy());
	push_mstack(m_6489290966298621602->copy());
	push_mstack(m_6883336518534669728->copy());
	push_mstack(m_572882281871596335->copy());
	push_mstack(m_5990615793266922572->copy());
	push_mstack(m_6878098574075051597->copy());
	push_mstack(m_8937053880007429666->copy());
	push_mstack(m_402363273204887410->copy());
	push_mstack(m_7489287966317621650->copy());
	push_mstack(m_1752332034185600136->copy());
	push_mstack(m_1580496222781227278->copy());
	push_mstack(m_1140914777391298966->copy());
	push_mstack(m_8377361506281704071->copy());
	push_mstack(m_1861935524217380096->copy());
	push_mstack(m_883286518456669768->copy());
	push_mstack(m_6883336518534669725->copy());
	push_mstack(m_8977416623760607542->copy());
	push_mstack(m_5493587513535795526->copy());
	push_mstack(m_535652293032991979->copy());
	push_mstack(m_1589022010305071550->copy());
	push_mstack(m_7562234897842223108->copy());
	push_mstack(m_891254232242817161->copy());
	push_mstack(m_225667655814964405->copy());
	push_mstack(m_3276538441069737238->copy());
	push_mstack(m_6452559683687795307->copy());
	push_mstack(m_3870552654796361874->copy());
	push_mstack(m_2334894414316945515->copy());
	push_mstack(m_1935060568134522444->copy());
	push_mstack(m_8878684525911869203->copy());
	push_mstack(m_116726481530330107->copy());
	push_mstack(m_2059620518000915593->copy());
	push_mstack(m_3532315163485605168->copy());
	push_mstack(m_8753504022126224320->copy());
	push_mstack(m_4417424195299696389->copy());
	push_mstack(m_2861944524240380115->copy());
	push_mstack(m_5452550683656795250->copy());
	push_mstack(m_6366604841396425560->copy());
	push_mstack(m_4155826145754657936->copy());
	push_mstack(m_5685959495889184258->copy());
	push_mstack(m_4918716186160845573->copy());
	push_mstack(m_7417194704702560909->copy());
	push_mstack(m_7319616456320007435->copy());
	push_mstack(m_7190082918267157529->copy());
	push_mstack(m_739472552794898846->copy());
	push_mstack(m_8153864921644340982->copy());
	push_mstack(m_6142923651108595564->copy());
	push_mstack(m_5318467113261106043->copy());
	push_mstack(m_1127757844635480951->copy());
	push_mstack(m_3205615482296837930->copy());
	push_mstack(m_7100692068131394299->copy());
	push_mstack(m_4931829372832396455->copy());
	push_mstack(m_347731813756299781->copy());
	push_mstack(m_5977655840781114254->copy());
	push_mstack(m_749337028767712466->copy());
	push_mstack(m_3354942891277150561->copy());
	push_mstack(m_7205837560925338666->copy());
	push_mstack(m_6663352449510349703->copy());
	push_mstack(m_6204133634428750110->copy());
	push_mstack(m_1338207728603571583->copy());
	push_mstack(m_563636931765380511->copy());
	push_mstack(m_956610375380943770->copy());
	push_mstack(m_6368059386699143323->copy());
	push_mstack(m_2116551473607222838->copy());
	push_mstack(m_665746921296265455->copy());
	push_mstack(m_9209079552018663298->copy());
	push_mstack(m_7218243394070108475->copy());
	push_mstack(m_3617082479859627715->copy());
	push_mstack(m_1366742895759609365->copy());
	push_mstack(m_4225676670239869874->copy());
	push_mstack(m_3657085054435518210->copy());
	push_mstack(m_8838771963228301332->copy());
	push_mstack(m_5656216784134219477->copy());
	push_mstack(m_6496169184221624797->copy());
	push_mstack(m_3550832419410389738->copy());
	push_mstack(m_8699331369263505348->copy());
	push_mstack(m_4233915781373148944->copy());
	push_mstack(m_3245448943457158228->copy());
	push_mstack(m_9204112634161749578->copy());
	push_mstack(m_5368050386668143347->copy());
	push_mstack(m_354835890712149708->copy());
	push_mstack(m_4343940313494534420->copy());
	push_mstack(m_8377602168878100806->copy());
	push_mstack(m_2701209500423349094->copy());
	push_mstack(m_8462847543120272133->copy());
	push_mstack(m_30721963009328407->copy());
	push_mstack(m_1617068479825627748->copy());
	push_mstack(m_7474725586076520841->copy());
	push_mstack(m_2334232078436734022->copy());
	push_mstack(m_5625703614027699405->copy());
	push_mstack(m_3735507825572608150->copy());
	push_mstack(m_7167179949122172133->copy());
	push_mstack(m_217798296920821504->copy());
	push_mstack(m_8834360734452785007->copy());
	push_mstack(m_3735507825572608151->copy());
	push_mstack(m_6191607442297259293->copy());
	push_mstack(m_3844741115169213591->copy());
	push_mstack(m_7317309123658704563->copy());
	push_mstack(m_6712557632947960431->copy());
	push_mstack(m_2334232078436734021->copy());
	push_mstack(m_7358463134481671731->copy());
	push_mstack(m_6257757314711793888->copy());
	push_mstack(m_6986529327288256427->copy());
	push_mstack(m_3354942891277150567->copy());
	push_mstack(m_7089784316161139696->copy());
	push_mstack(m_7237658521640888081->copy());
	push_mstack(m_5148280202213665408->copy());
	push_mstack(m_7834395734753785502->copy());
	push_mstack(m_1913580401558424442->copy());
	push_mstack(m_8369545503465652962->copy());
	push_mstack(m_7334255759241454497->copy());
	push_mstack(m_1403480262524941117->copy());
	push_mstack(m_8480140563928409269->copy());
	push_mstack(m_6204133634428750109->copy());
	push_mstack(m_4510192633336180012->copy());
	push_mstack(m_2953151084345095209->copy());
	push_mstack(m_5072723386389917858->copy());
	push_mstack(m_2603484945221435914->copy());
	push_mstack(m_7358463134481671730->copy());
	push_mstack(m_6748489754500791014->copy());
	push_mstack(m_1617068479825627749->copy());
	push_mstack(m_8128169875449950544->copy());
	push_mstack(m_1166617696393131217->copy());
	push_mstack(m_5749332006385821920->copy());
	push_mstack(m_8077381121717118352->copy());
	push_mstack(m_4941938168396622119->copy());
	push_mstack(m_4148678599404324827->copy());
	push_mstack(m_735496825519608002->copy());
	push_mstack(m_4898015980873404350->copy());
	push_mstack(m_5858979541697649781->copy());
	push_mstack(m_475130908459448193->copy());
	push_mstack(m_1944881053438915480->copy());
	push_mstack(m_8852439562138811031->copy());
	push_mstack(m_6442357874616488137->copy());
	push_mstack(m_5926931997564326356->copy());
	push_mstack(m_6021211737656574566->copy());
	push_mstack(m_1944881053438915487->copy());
	push_mstack(m_9173074425123117687->copy());
	push_mstack(m_4871252453561570626->copy());
	push_mstack(m_3666029044569158000->copy());
	push_mstack(m_8866221924196606726->copy());
	push_mstack(m_2288052971796078493->copy());
	push_mstack(m_7859976973350993559->copy());
	push_mstack(m_8615406171821724939->copy());
	push_mstack(m_1326257017649359052->copy());
	push_mstack(m_7487400228025037381->copy());
	push_mstack(m_5101855929935703261->copy());
	push_mstack(m_3891906619641533444->copy());
	push_mstack(m_8909638360029056137->copy());
	push_mstack(m_7569735997779609128->copy());
	push_mstack(m_6844757273811952164->copy());
	push_mstack(m_6580415148947944021->copy());
	push_mstack(m_6991273492231054889->copy());
	push_mstack(m_912989145902306795->copy());
	push_mstack(m_2538368198676650686->copy());
	push_mstack(m_5926931997564326355->copy());
	push_mstack(m_1975190577039325928->copy());
	push_mstack(m_2184866596717380790->copy());
	push_mstack(m_4062318297015154296->copy());
	push_mstack(m_3051657303276706316->copy());
	push_mstack(m_4926902997545326535->copy());
	push_mstack(m_2944894053489915548->copy());
	push_mstack(m_4382352007286362734->copy());
	push_mstack(m_3891906619641533445->copy());
	push_mstack(m_4891919619692533505->copy());
	push_mstack(m_8193611561415102671->copy());
	push_mstack(m_7193650561672103056->copy());
	push_mstack(m_3394415405119110063->copy());
	push_mstack(m_7699994247206697647->copy());
	push_mstack(m_922229117511063727->copy());
	push_mstack(m_173993486860062566->copy());
	push_mstack(m_1538339198401650093->copy());
	push_mstack(m_1435577580228956652->copy());
	push_mstack(m_3862447550529416939->copy());
	push_mstack(m_4464819975819065452->copy());
	push_mstack(m_2104891121306794951->copy());
	push_mstack(m_5363432685012506514->copy());
	push_mstack(m_3874487349509702166->copy());
	push_mstack(m_1470871668911071868->copy());
	push_mstack(m_7754315062558928136->copy());
	push_mstack(m_4694333430216376964->copy());
	push_mstack(m_5113542098380201892->copy());
	push_mstack(m_8957097349070363275->copy());
	push_mstack(m_922229117511063720->copy());
	push_mstack(m_396770683821442427->copy());
	push_mstack(m_6798918866474894686->copy());
	push_mstack(m_4925343521602038233->copy());
	push_mstack(m_6496900620290989447->copy());
	push_mstack(m_3394415405119110056->copy());
	push_mstack(m_77859882999937040->copy());
	push_mstack(m_311676794170477967->copy());
	push_mstack(m_7822585912639425132->copy());
	push_mstack(m_6874594350266703554->copy());
	push_mstack(m_3126174397139736358->copy());
	push_mstack(m_2770262008012331175->copy());
	push_mstack(m_7774349493623007772->copy());
	push_mstack(m_5577494030930978634->copy());
	push_mstack(m_7746738826449853829->copy());
	push_mstack(m_1786643601732435348->copy());
	push_mstack(m_1621876161099543777->copy());
	push_mstack(m_3514469416139695799->copy());
	push_mstack(m_9128716848140444191->copy());
	push_mstack(m_1575574815346588533->copy());
	push_mstack(m_1181144228284354623->copy());
	push_mstack(m_981012423617767708->copy());
	push_mstack(m_1649104658764171754->copy());
	push_mstack(m_6745559714126192867->copy());
	push_mstack(m_3694328430213376973->copy());
	push_mstack(m_8959305845634514310->copy());
	push_mstack(m_4499432735928770657->copy());
	push_mstack(m_8774832241746803268->copy());
	push_mstack(m_5062323297018154286->copy());
	push_mstack(m_1770265007993331059->copy());
	push_mstack(m_4738917069187657563->copy());
	push_mstack(m_2101812929882703473->copy());
	push_mstack(m_2467619909639068829->copy());
	push_mstack(m_7700301881869411458->copy());
	push_mstack(m_5906567993981626299->copy());
	push_mstack(m_7537107713678495408->copy());
	push_mstack(m_7587417285397521096->copy());
	push_mstack(m_7193650561672103057->copy());
	push_mstack(m_7193650561672103062->copy());
	push_mstack(m_7138646306155558637->copy());
	push_mstack(m_4153909473486796003->copy());
	push_mstack(m_2926168603715265150->copy());
	push_mstack(m_8587422285208520561->copy());
	push_mstack(m_4858950541422649192->copy());
	push_mstack(m_7333813913282261756->copy());
	push_mstack(m_8461780441329158119->copy());
	push_mstack(m_479808370493456149->copy());
	push_mstack(m_3871247453558570634->copy());
	push_mstack(m_4725447860428984017->copy());
	push_mstack(m_7653691274469346189->copy());
	push_mstack(m_1882489298383564529->copy());
	push_mstack(m_7390454751578054618->copy());
	push_mstack(m_8084373974548539773->copy());
	push_mstack(m_2731178923567975874->copy());
	push_mstack(m_4459868808903505240->copy());
	push_mstack(m_4056643640803622465->copy());
	push_mstack(m_7009243800786145683->copy());
	push_mstack(m_2523866526789434361->copy());
	push_mstack(m_7512279328594876714->copy());
	push_mstack(m_4056643640803622466->copy());
	push_mstack(m_5573862219737661281->copy());
	push_mstack(m_426259780836339564->copy());
	push_mstack(m_3056638640800622478->copy());
	push_mstack(m_5084297121785526274->copy());
	push_mstack(m_527854901861121239->copy());
	push_mstack(m_2995010194876047225->copy());
	push_mstack(m_3652072716935742915->copy());
	push_mstack(m_5686462650203935320->copy());
	push_mstack(m_5883254106001268248->copy());
	push_mstack(m_407789557108378257->copy());
	push_mstack(m_6581946279281973484->copy());
	push_mstack(m_5105307656166880431->copy());
	push_mstack(m_4084288121826526514->copy());
	push_mstack(m_641856374763918884->copy());
	push_mstack(m_3726541056031414407->copy());
	push_mstack(m_6313001481874397073->copy());
	push_mstack(m_8651055530903330312->copy());
	push_mstack(m_4598797409255693507->copy());
	push_mstack(m_2809446655002510487->copy());
	push_mstack(m_3590379310813611451->copy());
	push_mstack(m_3941282247590541616->copy());
	push_mstack(m_6847482718273797474->copy());
	push_mstack(m_1488733645688234253->copy());
	push_mstack(m_2590370310790611435->copy());
	push_mstack(m_8316629107280183066->copy());
	push_mstack(m_9019836137997592563->copy());
	push_mstack(m_8033879726777958681->copy());
	push_mstack(m_8545304186433760408->copy());
	push_mstack(m_953170167230579589->copy());
	push_mstack(m_3056638640800622480->copy());
	push_mstack(m_4355637910608313171->copy());
	push_mstack(m_1343714956541313049->copy());
	push_mstack(m_6725071862179236589->copy());
	push_mstack(m_9033884726780958663->copy());
	push_mstack(m_2886281120807349621->copy());
	push_mstack(m_7562863417656141067->copy());
	push_mstack(m_3809451655005510490->copy());
	push_mstack(m_4358135557096748419->copy());
	push_mstack(m_5459873808906505220->copy());
	push_mstack(m_241277260127765941->copy());
	push_mstack(m_3929886663582776301->copy());
	push_mstack(m_666384376438064180->copy());
	push_mstack(m_485476964015219842->copy());
	push_mstack(m_8611463540396697901->copy());
	push_mstack(m_4723315782937944117->copy());
	push_mstack(m_523860526803434323->copy());
	push_mstack(m_5974194503831482063->copy());
	push_mstack(m_758747740127234674->copy());
	push_mstack(m_9130101966442368676->copy());
	push_mstack(m_7794776927830501077->copy());
	push_mstack(m_1280884035939336679->copy());
	push_mstack(m_6102943812502559784->copy());
	push_mstack(m_1280884035939336678->copy());
	push_mstack(m_2218914560917117555->copy());
	push_mstack(m_8360743579447237928->copy());
	push_mstack(m_2336287172823628130->copy());
	push_mstack(m_4911026331875338683->copy());
	push_mstack(m_5839300414498035306->copy());
	push_mstack(m_1336282172820628142->copy());
	push_mstack(m_623679056201082277->copy());
	push_mstack(m_2971226292125787357->copy());
	push_mstack(m_2776483492595528168->copy());
	push_mstack(m_1077230879831828653->copy());
	push_mstack(m_186831208245796056->copy());
	push_mstack(m_343565593510387190->copy());
	push_mstack(m_6858905369771695849->copy());
	push_mstack(m_3003749035656713478->copy());
	push_mstack(m_2626146739751707886->copy());
	push_mstack(m_8636399747670185850->copy());
	push_mstack(m_7576532465437046509->copy());
	push_mstack(m_66837305206115519->copy());
	push_mstack(m_7376025075910789066->copy());
	push_mstack(m_3989343550719309565->copy());
	push_mstack(m_652032035251726845->copy());
	push_mstack(m_1191788078799326332->copy());
	push_mstack(m_4360413814298484464->copy());
	push_mstack(m_261423801441340710->copy());
	push_mstack(m_3609346366227766686->copy());
	push_mstack(m_4609351366230766675->copy());
	push_mstack(m_4158661918438585010->copy());
	push_mstack(m_28002237277353859->copy());
	push_mstack(m_3610084534774146608->copy());
	push_mstack(m_3159045680408643120->copy());
	push_mstack(m_1176517264308775012->copy());
	push_mstack(m_6000261645082650055->copy());
	push_mstack(m_1343570593513387178->copy());
	push_mstack(m_4928950368014939813->copy());
	push_mstack(m_1860211652271857134->copy());
	push_mstack(m_4144448824867690316->copy());
	push_mstack(m_2859335675727020038->copy());
	push_mstack(m_7880336951422196750->copy());
	push_mstack(m_8968701746786384363->copy());
	push_mstack(m_2597755969548019900->copy());
	push_mstack(m_5920488614448205112->copy());
	push_mstack(m_7434875251915168979->copy());
	push_mstack(m_7786325143369653037->copy());
	push_mstack(m_4504082291607180987->copy());
	push_mstack(m_994849265555663460->copy());
	push_mstack(m_4492301638475801389->copy());
	push_mstack(m_7457401523181242492->copy());
	push_mstack(m_6466328402296013741->copy());
	push_mstack(m_7994912265876664043->copy());
	push_mstack(m_2695008185264906918->copy());
	push_mstack(m_6474056816557383774->copy());
	push_mstack(m_1905350990981416657->copy());
	push_mstack(m_7474061816560383756->copy());
	push_mstack(m_852046345057861068->copy());
	push_mstack(m_5140350782166877393->copy());
	push_mstack(m_1759723462604230186->copy());
	push_mstack(m_3221596997705106633->copy());
	push_mstack(m_3949140426726856288->copy());
	push_mstack(m_3167758002048266762->copy());
	push_mstack(m_2939050201926891213->copy());
	push_mstack(m_328984661118683985->copy());
	push_mstack(m_3163066226733968390->copy());
	push_mstack(m_176512264305775033->copy());
	push_mstack(m_4431467888095329658->copy());
	push_mstack(m_6910156277733807192->copy());
	push_mstack(m_8162829400629799386->copy());
	push_mstack(m_5085990302980576350->copy());
	push_mstack(m_4812277256842588324->copy());
	push_mstack(m_917703764001064036->copy());
	push_mstack(m_7542878567241862360->copy());
	push_mstack(m_1053382630316773487->copy());
	push_mstack(m_1457844783818249690->copy());
	push_mstack(m_2499217561209765629->copy());
	push_mstack(m_5779185176275639718->copy());
	push_mstack(m_2166787368828103436->copy());
	push_mstack(m_3293630974170423782->copy());
	push_mstack(m_8674999814359297498->copy());
	push_mstack(m_2567261625782152345->copy());
	push_mstack(m_8354240807563036439->copy());
	push_mstack(m_6094371925663820546->copy());
	push_mstack(m_966007501449357727->copy());
	push_mstack(m_5264173279922970255->copy());
	push_mstack(m_2876489379407643613->copy());
	push_mstack(m_4094333925357820030->copy());
	push_mstack(m_5094342925388819986->copy());
	push_mstack(m_8094385925689820550->copy());
	push_mstack(m_1966012501452357739->copy());
	push_mstack(m_1446530740612615085->copy());
	push_mstack(m_4702096393951890739->copy());
	push_mstack(m_1794728972600554170->copy());
	push_mstack(m_3094328925354820022->copy());
	push_mstack(m_8682948485887848569->copy());
	push_mstack(m_1033998498536642185->copy());
	Polynomial * p_2 = build_poly();

	fprintf(stdout, "Multiplying mul_2 and p_2 yields:\n");
	Polynomial * mul_3 = multiply_poly(mul_2,p_2);
	mul_3->print(stdout);fprintf(stdout,"\n");
	delete(mul_2);delete(p_2);

	push_mstack(m_6586757166925088833->copy());
	push_mstack(m_5739981342729944954->copy());
	push_mstack(m_7562234897842223108->copy());
	push_mstack(m_7334591819367846785->copy());
	push_mstack(m_7462373664099153630->copy());
	push_mstack(m_1083044369228433508->copy());
	push_mstack(m_7825371027181840881->copy());
	push_mstack(m_8909805348912853595->copy());
	push_mstack(m_1861935524217380098->copy());
	push_mstack(m_8396024892905481551->copy());
	push_mstack(m_4666853960958055022->copy());
	push_mstack(m_1844159854003341578->copy());
	push_mstack(m_50311341388553175->copy());
	push_mstack(m_6366604841396425560->copy());
	push_mstack(m_4394200827290693302->copy());
	push_mstack(m_599412949207405853->copy());
	push_mstack(m_6878678526117869817->copy());
	push_mstack(m_1568957090038920995->copy());
	push_mstack(m_9214303397039452427->copy());
	push_mstack(m_3488540307060008778->copy());
	push_mstack(m_5489281966339621713->copy());
	push_mstack(m_3870552654796361874->copy());
	push_mstack(m_1715706449042189973->copy());
	push_mstack(m_6992774097515625429->copy());
	push_mstack(m_7937048880004429718->copy());
	push_mstack(m_2991217137048741202->copy());
	push_mstack(m_6743573970143616533->copy());
	push_mstack(m_1935060568134522444->copy());
	push_mstack(m_2334894414316945515->copy());
	push_mstack(m_1861935524217380096->copy());
	push_mstack(m_6883336518534669728->copy());
	push_mstack(m_5685959495889184258->copy());
	push_mstack(m_1752332034185600136->copy());
	push_mstack(m_4193699172766922093->copy());
	push_mstack(m_1580496222781227278->copy());
	push_mstack(m_1140914777391298966->copy());
	push_mstack(m_8649549020671362514->copy());
	push_mstack(m_6417740282678023986->copy());
	push_mstack(m_7319616456320007435->copy());
	push_mstack(m_1224550214727448670->copy());
	push_mstack(m_4056325404925559158->copy());
	push_mstack(m_2650580220032812225->copy());
	push_mstack(m_3190408477757770872->copy());
	push_mstack(m_7973192114357579702->copy());
	push_mstack(m_6489290966298621602->copy());
	push_mstack(m_6878098574075051597->copy());
	push_mstack(m_5990615793266922572->copy());
	push_mstack(m_535652293032991979->copy());
	push_mstack(m_891254232242817161->copy());
	push_mstack(m_225667655814964405->copy());
	push_mstack(m_6452559683687795307->copy());
	push_mstack(m_3276538441069737238->copy());
	push_mstack(m_7489287966317621650->copy());
	push_mstack(m_260540447448101793->copy());
	push_mstack(m_6450754892630604493->copy());
	push_mstack(m_3927319967144557343->copy());
	push_mstack(m_2861944524240380115->copy());
	push_mstack(m_2741047417897221736->copy());
	push_mstack(m_6883336518534669725->copy());
	push_mstack(m_883286518456669768->copy());
	push_mstack(m_8878684525911869203->copy());
	push_mstack(m_5493587513535795526->copy());
	push_mstack(m_8977416623760607542->copy());
	push_mstack(m_1059615517997915616->copy());
	push_mstack(m_2059620518000915593->copy());
	push_mstack(m_3532315163485605168->copy());
	push_mstack(m_8753504022126224320->copy());
	push_mstack(m_4417424195299696389->copy());
	push_mstack(m_116726481530330107->copy());
	push_mstack(m_8937053880007429666->copy());
	push_mstack(m_402363273204887410->copy());
	push_mstack(m_5452550683656795250->copy());
	push_mstack(m_4155826145754657936->copy());
	push_mstack(m_7190082918267157529->copy());
	push_mstack(m_4918716186160845573->copy());
	push_mstack(m_5625928222391316353->copy());
	push_mstack(m_572882281871596335->copy());
	push_mstack(m_739472552794898846->copy());
	push_mstack(m_8153864921644340982->copy());
	push_mstack(m_7408912328830731->copy());
	push_mstack(m_2627919318376789148->copy());
	push_mstack(m_3205615482296837930->copy());
	push_mstack(m_6142923651108595564->copy());
	push_mstack(m_5318467113261106043->copy());
	push_mstack(m_4931829372832396455->copy());
	push_mstack(m_347731813756299781->copy());
	push_mstack(m_5977655840781114254->copy());
	push_mstack(m_7100692068131394299->copy());
	push_mstack(m_1127757844635480951->copy());
	push_mstack(m_749337028767712466->copy());
	push_mstack(m_3354942891277150561->copy());
	push_mstack(m_7205837560925338666->copy());
	push_mstack(m_6663352449510349703->copy());
	push_mstack(m_6204133634428750110->copy());
	push_mstack(m_1338207728603571583->copy());
	push_mstack(m_563636931765380511->copy());
	push_mstack(m_956610375380943770->copy());
	push_mstack(m_6368059386699143323->copy());
	push_mstack(m_2116551473607222838->copy());
	push_mstack(m_665746921296265455->copy());
	push_mstack(m_9209079552018663298->copy());
	push_mstack(m_7218243394070108475->copy());
	push_mstack(m_3617082479859627715->copy());
	push_mstack(m_1366742895759609365->copy());
	push_mstack(m_4225676670239869874->copy());
	push_mstack(m_3657085054435518210->copy());
	push_mstack(m_8838771963228301332->copy());
	push_mstack(m_5656216784134219477->copy());
	push_mstack(m_6496169184221624797->copy());
	push_mstack(m_3550832419410389738->copy());
	push_mstack(m_8699331369263505348->copy());
	push_mstack(m_4233915781373148944->copy());
	push_mstack(m_3245448943457158228->copy());
	push_mstack(m_9204112634161749578->copy());
	push_mstack(m_5368050386668143347->copy());
	push_mstack(m_354835890712149708->copy());
	push_mstack(m_4343940313494534420->copy());
	push_mstack(m_8377602168878100806->copy());
	push_mstack(m_2701209500423349094->copy());
	push_mstack(m_8462847543120272133->copy());
	push_mstack(m_30721963009328407->copy());
	push_mstack(m_1617068479825627748->copy());
	push_mstack(m_7474725586076520841->copy());
	push_mstack(m_2334232078436734022->copy());
	push_mstack(m_5625703614027699405->copy());
	push_mstack(m_3735507825572608150->copy());
	push_mstack(m_7167179949122172133->copy());
	push_mstack(m_217798296920821504->copy());
	push_mstack(m_8834360734452785007->copy());
	push_mstack(m_3735507825572608151->copy());
	push_mstack(m_6191607442297259293->copy());
	push_mstack(m_3844741115169213591->copy());
	push_mstack(m_7317309123658704563->copy());
	push_mstack(m_6712557632947960431->copy());
	push_mstack(m_2334232078436734021->copy());
	push_mstack(m_7358463134481671731->copy());
	push_mstack(m_6257757314711793888->copy());
	push_mstack(m_6986529327288256427->copy());
	push_mstack(m_3354942891277150567->copy());
	push_mstack(m_7089784316161139696->copy());
	push_mstack(m_7237658521640888081->copy());
	push_mstack(m_5148280202213665408->copy());
	push_mstack(m_7834395734753785502->copy());
	push_mstack(m_1913580401558424442->copy());
	push_mstack(m_8369545503465652962->copy());
	push_mstack(m_7334255759241454497->copy());
	push_mstack(m_1403480262524941117->copy());
	push_mstack(m_8480140563928409269->copy());
	push_mstack(m_6204133634428750109->copy());
	push_mstack(m_4510192633336180012->copy());
	push_mstack(m_2953151084345095209->copy());
	push_mstack(m_5072723386389917858->copy());
	push_mstack(m_2603484945221435914->copy());
	push_mstack(m_7358463134481671730->copy());
	push_mstack(m_6748489754500791014->copy());
	push_mstack(m_1617068479825627749->copy());
	push_mstack(m_8128169875449950544->copy());
	push_mstack(m_1166617696393131217->copy());
	push_mstack(m_5749332006385821920->copy());
	push_mstack(m_8077381121717118352->copy());
	push_mstack(m_4941938168396622119->copy());
	push_mstack(m_4148678599404324827->copy());
	push_mstack(m_735496825519608002->copy());
	push_mstack(m_4898015980873404350->copy());
	push_mstack(m_5858979541697649781->copy());
	push_mstack(m_475130908459448193->copy());
	push_mstack(m_1944881053438915480->copy());
	push_mstack(m_8852439562138811031->copy());
	push_mstack(m_6442357874616488137->copy());
	push_mstack(m_5926931997564326356->copy());
	push_mstack(m_6021211737656574566->copy());
	push_mstack(m_1944881053438915487->copy());
	push_mstack(m_9173074425123117687->copy());
	push_mstack(m_4871252453561570626->copy());
	push_mstack(m_3666029044569158000->copy());
	push_mstack(m_8866221924196606726->copy());
	push_mstack(m_2288052971796078493->copy());
	push_mstack(m_7859976973350993559->copy());
	push_mstack(m_8615406171821724939->copy());
	push_mstack(m_1326257017649359052->copy());
	push_mstack(m_7487400228025037381->copy());
	push_mstack(m_5101855929935703261->copy());
	push_mstack(m_3891906619641533444->copy());
	push_mstack(m_8909638360029056137->copy());
	push_mstack(m_7569735997779609128->copy());
	push_mstack(m_6844757273811952164->copy());
	push_mstack(m_6580415148947944021->copy());
	push_mstack(m_6991273492231054889->copy());
	push_mstack(m_912989145902306795->copy());
	push_mstack(m_2538368198676650686->copy());
	push_mstack(m_5926931997564326355->copy());
	push_mstack(m_1975190577039325928->copy());
	push_mstack(m_2184866596717380790->copy());
	push_mstack(m_4062318297015154296->copy());
	push_mstack(m_3051657303276706316->copy());
	push_mstack(m_4926902997545326535->copy());
	push_mstack(m_2944894053489915548->copy());
	push_mstack(m_4382352007286362734->copy());
	push_mstack(m_3891906619641533445->copy());
	push_mstack(m_4891919619692533505->copy());
	push_mstack(m_8193611561415102671->copy());
	push_mstack(m_7193650561672103056->copy());
	push_mstack(m_3394415405119110063->copy());
	push_mstack(m_7699994247206697647->copy());
	push_mstack(m_922229117511063727->copy());
	push_mstack(m_173993486860062566->copy());
	push_mstack(m_1538339198401650093->copy());
	push_mstack(m_1435577580228956652->copy());
	push_mstack(m_3862447550529416939->copy());
	push_mstack(m_4464819975819065452->copy());
	push_mstack(m_2104891121306794951->copy());
	push_mstack(m_5363432685012506514->copy());
	push_mstack(m_3874487349509702166->copy());
	push_mstack(m_1470871668911071868->copy());
	push_mstack(m_7754315062558928136->copy());
	push_mstack(m_4694333430216376964->copy());
	push_mstack(m_5113542098380201892->copy());
	push_mstack(m_8957097349070363275->copy());
	push_mstack(m_922229117511063720->copy());
	push_mstack(m_396770683821442427->copy());
	push_mstack(m_6798918866474894686->copy());
	push_mstack(m_4925343521602038233->copy());
	push_mstack(m_6496900620290989447->copy());
	push_mstack(m_3394415405119110056->copy());
	push_mstack(m_77859882999937040->copy());
	push_mstack(m_311676794170477967->copy());
	push_mstack(m_7822585912639425132->copy());
	push_mstack(m_6874594350266703554->copy());
	push_mstack(m_3126174397139736358->copy());
	push_mstack(m_2770262008012331175->copy());
	push_mstack(m_7774349493623007772->copy());
	push_mstack(m_5577494030930978634->copy());
	push_mstack(m_7746738826449853829->copy());
	push_mstack(m_1786643601732435348->copy());
	push_mstack(m_1621876161099543777->copy());
	push_mstack(m_3514469416139695799->copy());
	push_mstack(m_9128716848140444191->copy());
	push_mstack(m_1575574815346588533->copy());
	push_mstack(m_1181144228284354623->copy());
	push_mstack(m_981012423617767708->copy());
	push_mstack(m_1649104658764171754->copy());
	push_mstack(m_6745559714126192867->copy());
	push_mstack(m_3694328430213376973->copy());
	push_mstack(m_8959305845634514310->copy());
	push_mstack(m_4499432735928770657->copy());
	push_mstack(m_8774832241746803268->copy());
	push_mstack(m_5062323297018154286->copy());
	push_mstack(m_1770265007993331059->copy());
	push_mstack(m_4738917069187657563->copy());
	push_mstack(m_2101812929882703473->copy());
	push_mstack(m_2467619909639068829->copy());
	push_mstack(m_7700301881869411458->copy());
	push_mstack(m_5906567993981626299->copy());
	push_mstack(m_7537107713678495408->copy());
	push_mstack(m_7587417285397521096->copy());
	push_mstack(m_7193650561672103057->copy());
	push_mstack(m_7193650561672103062->copy());
	push_mstack(m_7138646306155558637->copy());
	push_mstack(m_4153909473486796003->copy());
	push_mstack(m_2926168603715265150->copy());
	push_mstack(m_8587422285208520561->copy());
	push_mstack(m_4858950541422649192->copy());
	push_mstack(m_7333813913282261756->copy());
	push_mstack(m_8461780441329158119->copy());
	push_mstack(m_479808370493456149->copy());
	push_mstack(m_3871247453558570634->copy());
	push_mstack(m_4725447860428984017->copy());
	push_mstack(m_7653691274469346189->copy());
	push_mstack(m_1882489298383564529->copy());
	push_mstack(m_7390454751578054618->copy());
	push_mstack(m_8084373974548539773->copy());
	push_mstack(m_7794776927830501077->copy());
	push_mstack(m_4723315782937944117->copy());
	push_mstack(m_953170167230579589->copy());
	push_mstack(m_407789557108378257->copy());
	push_mstack(m_5084297121785526274->copy());
	push_mstack(m_1488733645688234253->copy());
	push_mstack(m_1280884035939336679->copy());
	push_mstack(m_7881749990431030641->copy());
	push_mstack(m_5883254106001268248->copy());
	push_mstack(m_9034446518438222646->copy());
	push_mstack(m_5573862219737661281->copy());
	push_mstack(m_641856374763918884->copy());
	push_mstack(m_2590370310790611435->copy());
	push_mstack(m_8033879726777958681->copy());
	push_mstack(m_8651055530903330312->copy());
	push_mstack(m_6581946279281973484->copy());
	push_mstack(m_4598797409255693507->copy());
	push_mstack(m_8545304186433760408->copy());
	push_mstack(m_1280884035939336678->copy());
	push_mstack(m_5586792342688796886->copy());
	push_mstack(m_6725071862179236589->copy());
	push_mstack(m_4358135557096748419->copy());
	push_mstack(m_6102943812502559784->copy());
	push_mstack(m_3809451655005510490->copy());
	push_mstack(m_8161048427101358398->copy());
	push_mstack(m_3590379310813611451->copy());
	push_mstack(m_4056643640803622466->copy());
	push_mstack(m_2995010194876047225->copy());
	push_mstack(m_3056638640800622478->copy());
	push_mstack(m_9019836137997592563->copy());
	push_mstack(m_527854901861121239->copy());
	push_mstack(m_426259780836339564->copy());
	push_mstack(m_6313001481874397073->copy());
	push_mstack(m_241277260127765941->copy());
	push_mstack(m_3056638640800622480->copy());
	push_mstack(m_5105307656166880431->copy());
	push_mstack(m_4084288121826526514->copy());
	push_mstack(m_2886281120807349621->copy());
	push_mstack(m_5686462650203935320->copy());
	push_mstack(m_1586400041365173292->copy());
	push_mstack(m_523860526803434323->copy());
	push_mstack(m_666384376438064180->copy());
	push_mstack(m_6214211996395277894->copy());
	push_mstack(m_7512279328594876714->copy());
	push_mstack(m_5974194503831482063->copy());
	push_mstack(m_4056643640803622465->copy());
	push_mstack(m_9033884726780958663->copy());
	push_mstack(m_2731178923567975874->copy());
	push_mstack(m_4031586764294785437->copy());
	push_mstack(m_4459868808903505240->copy());
	push_mstack(m_4825123762069048326->copy());
	push_mstack(m_3099195120562490879->copy());
	push_mstack(m_3726541056031414407->copy());
	push_mstack(m_1343714956541313049->copy());
	push_mstack(m_3929886663582776301->copy());
	push_mstack(m_8611463540396697901->copy());
	push_mstack(m_758747740127234674->copy());
	push_mstack(m_2523866526789434361->copy());
	push_mstack(m_9130101966442368676->copy());
	push_mstack(m_6847482718273797474->copy());
	push_mstack(m_2971226292125787357->copy());
	push_mstack(m_1336282172820628142->copy());
	push_mstack(m_4911026331875338683->copy());
	push_mstack(m_2776483492595528168->copy());
	push_mstack(m_8360743579447237928->copy());
	push_mstack(m_623679056201082277->copy());
	push_mstack(m_1077230879831828653->copy());
	push_mstack(m_5839300414498035306->copy());
	push_mstack(m_2218914560917117555->copy());
	push_mstack(m_2336287172823628130->copy());
	push_mstack(m_8636399747670185850->copy());
	push_mstack(m_6858905369771695849->copy());
	push_mstack(m_3159045680408643120->copy());
	push_mstack(m_66837305206115519->copy());
	push_mstack(m_3989343550719309565->copy());
	push_mstack(m_28002237277353859->copy());
	push_mstack(m_3536522532045199336->copy());
	push_mstack(m_261423801441340710->copy());
	push_mstack(m_3003749035656713478->copy());
	push_mstack(m_7376025075910789066->copy());
	push_mstack(m_3609346366227766686->copy());
	push_mstack(m_4158661918438585010->copy());
	push_mstack(m_4609351366230766675->copy());
	push_mstack(m_1191788078799326332->copy());
	push_mstack(m_186831208245796056->copy());
	push_mstack(m_652032035251726845->copy());
	push_mstack(m_4360413814298484464->copy());
	push_mstack(m_3610084534774146608->copy());
	push_mstack(m_2626146739751707886->copy());
	push_mstack(m_343565593510387190->copy());
	push_mstack(m_2580744792151990986->copy());
	push_mstack(m_1176517264308775012->copy());
	push_mstack(m_4928950368014939813->copy());
	push_mstack(m_1343570593513387178->copy());
	push_mstack(m_5920488614448205112->copy());
	push_mstack(m_2859335675727020038->copy());
	push_mstack(m_3790835143076745575->copy());
	push_mstack(m_7457401523181242492->copy());
	push_mstack(m_8968701746786384363->copy());
	push_mstack(m_4144448824867690316->copy());
	push_mstack(m_994849265555663460->copy());
	push_mstack(m_1860211652271857134->copy());
	push_mstack(m_7434875251915168979->copy());
	push_mstack(m_2597755969548019900->copy());
	push_mstack(m_7786325143369653037->copy());
	push_mstack(m_7880336951422196750->copy());
	push_mstack(m_6466328402296013741->copy());
	push_mstack(m_4492301638475801389->copy());
	push_mstack(m_1759723462604230186->copy());
	push_mstack(m_2695008185264906918->copy());
	push_mstack(m_3221596997705106633->copy());
	push_mstack(m_7474061816560383756->copy());
	push_mstack(m_6474056816557383774->copy());
	push_mstack(m_1905350990981416657->copy());
	push_mstack(m_3167758002048266762->copy());
	push_mstack(m_3949140426726856288->copy());
	push_mstack(m_852046345057861068->copy());
	push_mstack(m_7994912265876664043->copy());
	push_mstack(m_5140350782166877393->copy());
	push_mstack(m_328984661118683985->copy());
	push_mstack(m_3163066226733968390->copy());
	push_mstack(m_2939050201926891213->copy());
	push_mstack(m_176512264305775033->copy());
	push_mstack(m_8162829400629799386->copy());
	push_mstack(m_884093968343609859->copy());
	push_mstack(m_4154748002733677099->copy());
	push_mstack(m_4812277256842588324->copy());
	push_mstack(m_5085990302980576350->copy());
	push_mstack(m_1457844783818249690->copy());
	push_mstack(m_4325737353110787362->copy());
	push_mstack(m_917703764001064036->copy());
	push_mstack(m_1053382630316773487->copy());
	push_mstack(m_7542878567241862360->copy());
	push_mstack(m_2166787368828103436->copy());
	push_mstack(m_2499217561209765629->copy());
	push_mstack(m_3293630974170423782->copy());
	push_mstack(m_2567261625782152345->copy());
	push_mstack(m_8674999814359297498->copy());
	push_mstack(m_8354240807563036439->copy());
	push_mstack(m_8682948485887848569->copy());
	push_mstack(m_1446530740612615085->copy());
	push_mstack(m_5264173279922970255->copy());
	push_mstack(m_2876489379407643613->copy());
	push_mstack(m_4702096393951890739->copy());
	push_mstack(m_1033998498536642185->copy());
	push_mstack(m_6094371925663820546->copy());
	push_mstack(m_4094333925357820030->copy());
	push_mstack(m_1966012501452357739->copy());
	push_mstack(m_966007501449357727->copy());
	push_mstack(m_1794727972604554129->copy());
	push_mstack(m_5094342925388819986->copy());
	push_mstack(m_8094385925689820550->copy());
	push_mstack(m_3094328925354820022->copy());
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
	delete(m_9104664561816002391);
	delete(m_1568957090038920995);
	delete(m_9214303397039452427);
	delete(m_6586757166925088833);
	delete(m_50311341388553175);
	delete(m_5625928222391316353);
	delete(m_3488540307060008778);
	delete(m_7417194704702560909);
	delete(m_8396024892905481551);
	delete(m_4666853960958055022);
	delete(m_3140360740260629205);
	delete(m_2650580220032812225);
	delete(m_5489281966339621713);
	delete(m_4155826145754657936);
	delete(m_739472552794898846);
	delete(m_7462373664099153630);
	delete(m_7825371027181840881);
	delete(m_1083044369228433508);
	delete(m_5739981342729944954);
	delete(m_7408912328830731);
	delete(m_1861935524217380098);
	delete(m_8909805348912853595);
	delete(m_3870552654796361874);
	delete(m_2741047417897221736);
	delete(m_7163678312255027900);
	delete(m_6992774097515625429);
	delete(m_2670866737757992469);
	delete(m_7937048880004429718);
	delete(m_6743573970143616533);
	delete(m_6883336518534669728);
	delete(m_1752332034185600136);
	delete(m_116726481530330107);
	delete(m_4193699172766922093);
	delete(m_1580496222781227278);
	delete(m_1140914777391298966);
	delete(m_8377361506281704071);
	delete(m_572882281871596335);
	delete(m_5990615793266922572);
	delete(m_2334894414316945515);
	delete(m_1935060568134522444);
	delete(m_3276538441069737238);
	delete(m_6883336518534669725);
	delete(m_883286518456669768);
	delete(m_8878684525911869203);
	delete(m_2059620518000915593);
	delete(m_8753504022126224320);
	delete(m_4417424195299696389);
	delete(m_3532315163485605168);
	delete(m_6878098574075051597);
	delete(m_7190082918267157529);
	delete(m_5452550683656795250);
	delete(m_6450754892630604493);
	delete(m_260540447448101793);
	delete(m_3927319967144557343);
	delete(m_1861935524217380096);
	delete(m_6452559683687795307);
	delete(m_535652293032991979);
	delete(m_1589022010305071550);
	delete(m_7562234897842223108);
	delete(m_5685959495889184258);
	delete(m_5493587513535795526);
	delete(m_8977416623760607542);
	delete(m_8937053880007429666);
	delete(m_402363273204887410);
	delete(m_6489290966298621602);
	delete(m_7973192114357579702);
	delete(m_225667655814964405);
	delete(m_891254232242817161);
	delete(m_2861944524240380115);
	delete(m_599412949207405853);
	delete(m_1093555934268442245);
	delete(m_4056325404925559158);
	delete(m_1224550214727448670);
	delete(m_6417740282678023986);
	delete(m_7319616456320007435);
	delete(m_4918716186160845573);
	delete(m_1059615517997915616);
	delete(m_1844159854003341578);
	delete(m_7489287966317621650);
	delete(m_6366604841396425560);
	delete(m_8153864921644340982);
	delete(m_1127757844635480951);
	delete(m_6142923651108595564);
	delete(m_7100692068131394299);
	delete(m_347731813756299781);
	delete(m_3205615482296837930);
	delete(m_4931829372832396455);
	delete(m_5318467113261106043);
	delete(m_5977655840781114254);
	delete(m_4934179971783772946);
	delete(m_464208403945311855);
	delete(m_4205794560872338757);
	delete(m_7934158971516772419);
	delete(m_371391210835972229);
	delete(m_477932723891432870);
	delete(m_6998966950683614089);
	delete(m_4822478912074424257);
	delete(m_5486436016943975781);
	delete(m_7976338658889874130);
	delete(m_7205837560925338665);
	delete(m_5560852074695054177);
	delete(m_3343657216887153682);
	delete(m_2328689697472814017);
	delete(m_3173051697569003901);
	delete(m_1753543314265943773);
	delete(m_7699326369260505364);
	delete(m_7400973548215009750);
	delete(m_7754315062558928136);
	delete(m_7752626047462534669);
	delete(m_1030730963040328462);
	delete(m_2620594034141876992);
	delete(m_2171338909067427793);
	delete(m_1901315615640712045);
	delete(m_30721963009328407);
	delete(m_5363432685012506514);
	delete(m_2104891121306794951);
	delete(m_4225676670239869874);
	delete(m_4822478912074424262);
	delete(m_3590211135183224228);
	delete(m_1470871668911071868);
	delete(m_3035915008923412146);
	delete(m_3881813962401041272);
	delete(m_6496169184221624797);
	delete(m_464208403945311850);
	delete(m_2470876668914071852);
	delete(m_16509678909703728);
	delete(m_4251682165596160941);
	delete(m_1030730963040328457);
	delete(m_4464819975819065452);
	delete(m_2334232078436734022);
	delete(m_5225269439360978410);
	delete(m_905533869647441518);
	delete(m_2173058697570003733);
	delete(m_200093757314409955);
	delete(m_5382767869282026966);
	delete(m_7822585912639425130);
	delete(m_1987124822629572196);
	delete(m_3173051697569003898);
	delete(m_1200086757313409996);
	delete(m_396770683821442427);
	delete(m_5432742146448060376);
	delete(m_2603484945221435914);
	delete(m_5486436016943975780);
	delete(m_311676794170477967);
	delete(m_7822585912639425132);
	delete(m_7934158971516772422);
	delete(m_4486427016912975692);
	delete(m_7699326369260505365);
	delete(m_43402624862056869);
	delete(m_8957097349070363275);
	delete(m_7365713230790137202);
	delete(m_1242819830394550836);
	delete(m_2143557286725240548);
	delete(m_5998877950172613329);
	delete(m_200093757314409956);
	delete(m_5881790229396670029);
	delete(m_1649104658764171754);
	delete(m_5925722517070317099);
	delete(m_8377602168878100806);
	delete(m_7334255759241454497);
	delete(m_1449207827196456628);
	delete(m_1575574815346588533);
	delete(m_5072723386389917858);
	delete(m_981012423617767708);
	delete(m_2311349967957247894);
	delete(m_6191607442297259293);
	delete(m_2379738321323192777);
	delete(m_2116551473607222838);
	delete(m_3694328430213376973);
	delete(m_6117044945679642377);
	delete(m_5925722517070317102);
	delete(m_1649104658764171759);
	delete(m_4915329906849667949);
	delete(m_6745559714126192867);
	delete(m_3245448943457158228);
	delete(m_1786643601732435348);
	delete(m_1338207728603571583);
	delete(m_563636931765380511);
	delete(m_1620589034138876977);
	delete(m_8959305845634514310);
	delete(m_4499432735928770657);
	delete(m_7537107713678495408);
	delete(m_4738917069187657563);
	delete(m_8900277346504847330);
	delete(m_4717028345938854011);
	delete(m_4941938168396622119);
	delete(m_735496825519608002);
	delete(m_2173058697570003731);
	delete(m_2101812929882703473);
	delete(m_5261433641576388828);
	delete(m_2926168603715265150);
	delete(m_749337028767712466);
	delete(m_812982770049516399);
	delete(m_522064276127567241);
	delete(m_5062323297018154286);
	delete(m_8462847543120272133);
	delete(m_2173058697570003732);
	delete(m_4934179971783772952);
	delete(m_1748318697048299860);
	delete(m_2467619909639068829);
	delete(m_1200086757313409997);
	delete(m_5178499688477657887);
	delete(m_3617082479859627715);
	delete(m_4934179971783772945);
	delete(m_5478925382798364034);
	delete(m_4486427016912975691);
	delete(m_1142000726707459426);
	delete(m_8834360734452785007);
	delete(m_4732070845762564222);
	delete(m_3239347140091240266);
	delete(m_4298630350691455223);
	delete(m_9209079552018663298);
	delete(m_4858950541422649192);
	delete(m_8699331369263505348);
	delete(m_5656216784134219477);
	delete(m_7333813913282261756);
	delete(m_7205837560925338666);
	delete(m_956610375380943770);
	delete(m_421166355302543915);
	delete(m_1311681794173477979);
	delete(m_3871247453558570634);
	delete(m_43402624862056866);
	delete(m_5858979541697649780);
	delete(m_8461780441329158119);
	delete(m_4898015980873404350);
	delete(m_7390454751578054618);
	delete(m_4233915781373148944);
	delete(m_1882489298383564529);
	delete(m_7474725586076520841);
	delete(m_6663352449510349703);
	delete(m_6986529327288256427);
	delete(m_1366742895759609365);
	delete(m_7656044241527513323);
	delete(m_7167179949122172133);
	delete(m_8084373974548539773);
	delete(m_6442357874616488137);
	delete(m_2995010194876047225);
	delete(m_758747740127234674);
	delete(m_4056643640803622465);
	delete(m_4355637910608313171);
	delete(m_4598797409255693507);
	delete(m_4723315782937944117);
	delete(m_6313001481874397073);
	delete(m_485476964015219842);
	delete(m_3590379310813611451);
	delete(m_8033879726777958681);
	delete(m_2731178923567975874);
	delete(m_8316629107280183066);
	delete(m_1280884035939336679);
	delete(m_1488733645688234253);
	delete(m_527854901861121239);
	delete(m_9033884726780958663);
	delete(m_5883254106001268248);
	delete(m_3056638640800622478);
	delete(m_426259780836339564);
	delete(m_5573862219737661281);
	delete(m_8545304186433760408);
	delete(m_7562863417656141067);
	delete(m_2886281120807349621);
	delete(m_3941282247590541616);
	delete(m_7794776927830501077);
	delete(m_1343714956541313049);
	delete(m_8651055530903330312);
	delete(m_6725071862179236589);
	delete(m_641856374763918884);
	delete(m_5084297121785526274);
	delete(m_7009243800786145683);
	delete(m_953170167230579589);
	delete(m_2590370310790611435);
	delete(m_3056638640800622480);
	delete(m_4358135557096748419);
	delete(m_3809451655005510490);
	delete(m_7512279328594876714);
	delete(m_5686462650203935320);
	delete(m_9019836137997592563);
	delete(m_407789557108378257);
	delete(m_666384376438064180);
	delete(m_5105307656166880431);
	delete(m_2809446655002510487);
	delete(m_4459868808903505240);
	delete(m_4056643640803622466);
	delete(m_9130101966442368676);
	delete(m_3652072716935742915);
	delete(m_5459873808906505220);
	delete(m_6581946279281973484);
	delete(m_3726541056031414407);
	delete(m_5974194503831482063);
	delete(m_3929886663582776301);
	delete(m_523860526803434323);
	delete(m_1280884035939336678);
	delete(m_241277260127765941);
	delete(m_6847482718273797474);
	delete(m_4084288121826526514);
	delete(m_8611463540396697901);
	delete(m_2523866526789434361);
	delete(m_6102943812502559784);
	delete(m_1077230879831828653);
	delete(m_2776483492595528168);
	delete(m_4911026331875338683);
	delete(m_2336287172823628130);
	delete(m_8360743579447237928);
	delete(m_5839300414498035306);
	delete(m_2971226292125787357);
	delete(m_1336282172820628142);
	delete(m_623679056201082277);
	delete(m_2218914560917117555);
	delete(m_3609346366227766686);
	delete(m_3610084534774146608);
	delete(m_1343570593513387178);
	delete(m_652032035251726845);
	delete(m_186831208245796056);
	delete(m_3003749035656713478);
	delete(m_8636399747670185850);
	delete(m_1191788078799326332);
	delete(m_261423801441340710);
	delete(m_7576532465437046509);
	delete(m_6858905369771695849);
	delete(m_7376025075910789066);
	delete(m_3989343550719309565);
	delete(m_4360413814298484464);
	delete(m_28002237277353859);
	delete(m_4158661918438585010);
	delete(m_3159045680408643120);
	delete(m_2626146739751707886);
	delete(m_343565593510387190);
	delete(m_66837305206115519);
	delete(m_1176517264308775012);
	delete(m_4609351366230766675);
	delete(m_6000261645082650055);
	delete(m_4928950368014939813);
	delete(m_8968701746786384363);
	delete(m_4144448824867690316);
	delete(m_2859335675727020038);
	delete(m_7786325143369653037);
	delete(m_6466328402296013741);
	delete(m_994849265555663460);
	delete(m_1860211652271857134);
	delete(m_5920488614448205112);
	delete(m_4504082291607180987);
	delete(m_7434875251915168979);
	delete(m_4492301638475801389);
	delete(m_7457401523181242492);
	delete(m_7880336951422196750);
	delete(m_2597755969548019900);
	delete(m_7474061816560383756);
	delete(m_1905350990981416657);
	delete(m_3949140426726856288);
	delete(m_2695008185264906918);
	delete(m_2939050201926891213);
	delete(m_7994912265876664043);
	delete(m_1759723462604230186);
	delete(m_852046345057861068);
	delete(m_3221596997705106633);
	delete(m_5140350782166877393);
	delete(m_6474056816557383774);
	delete(m_328984661118683985);
	delete(m_3167758002048266762);
	delete(m_3163066226733968390);
	delete(m_4431467888095329658);
	delete(m_6910156277733807192);
	delete(m_8162829400629799386);
	delete(m_176512264305775033);
	delete(m_5085990302980576350);
	delete(m_4812277256842588324);
	delete(m_2499217561209765629);
	delete(m_2166787368828103436);
	delete(m_5779185176275639718);
	delete(m_1053382630316773487);
	delete(m_7542878567241862360);
	delete(m_917703764001064036);
	delete(m_1457844783818249690);
	delete(m_3293630974170423782);
	delete(m_2567261625782152345);
	delete(m_8354240807563036439);
	delete(m_8674999814359297498);
	delete(m_8094385925689820550);
	delete(m_966007501449357727);
	delete(m_3094328925354820022);
	delete(m_6094371925663820546);
	delete(m_5264173279922970255);
	delete(m_4702096393951890739);
	delete(m_5094342925388819986);
	delete(m_4094333925357820030);
	delete(m_1446530740612615085);
	delete(m_8682948485887848569);
	delete(m_1966012501452357739);
	delete(m_1794728972600554170);
	delete(m_1033998498536642185);
	delete(m_2876489379407643613);
	delete(m_7334591819367846785);
	delete(m_4394200827290693302);
	delete(m_2627919318376789148);
	delete(m_3190408477757770872);
	delete(m_6878678526117869817);
	delete(m_2991217137048741202);
	delete(m_8649549020671362514);
	delete(m_1715706449042189973);
	delete(m_9034446518438222646);
	delete(m_4031586764294785437);
	delete(m_4825123762069048326);
	delete(m_8161048427101358398);
	delete(m_5586792342688796886);
	delete(m_6214211996395277894);
	delete(m_1586400041365173292);
	delete(m_3099195120562490879);
	delete(m_7881749990431030641);
	delete(m_3536522532045199336);
	delete(m_2580744792151990986);
	delete(m_3790835143076745575);
	delete(m_4154748002733677099);
	delete(m_884093968343609859);
	delete(m_4325737353110787362);
	delete(m_1794727972604554129);
	delete(m_3354942891277150561);
	delete(m_6204133634428750110);
	delete(m_6368059386699143323);
	delete(m_665746921296265455);
	delete(m_7218243394070108475);
	delete(m_3657085054435518210);
	delete(m_8838771963228301332);
	delete(m_3550832419410389738);
	delete(m_9204112634161749578);
	delete(m_5368050386668143347);
	delete(m_354835890712149708);
	delete(m_4343940313494534420);
	delete(m_2701209500423349094);
	delete(m_1617068479825627748);
	delete(m_5625703614027699405);
	delete(m_3735507825572608150);
	delete(m_217798296920821504);
	delete(m_3735507825572608151);
	delete(m_3844741115169213591);
	delete(m_7317309123658704563);
	delete(m_6712557632947960431);
	delete(m_2334232078436734021);
	delete(m_7358463134481671731);
	delete(m_6257757314711793888);
	delete(m_3354942891277150567);
	delete(m_7089784316161139696);
	delete(m_7237658521640888081);
	delete(m_5148280202213665408);
	delete(m_7834395734753785502);
	delete(m_1913580401558424442);
	delete(m_8369545503465652962);
	delete(m_1403480262524941117);
	delete(m_8480140563928409269);
	delete(m_6204133634428750109);
	delete(m_4510192633336180012);
	delete(m_2953151084345095209);
	delete(m_7358463134481671730);
	delete(m_6748489754500791014);
	delete(m_1617068479825627749);
	delete(m_8128169875449950544);
	delete(m_1166617696393131217);
	delete(m_5749332006385821920);
	delete(m_8077381121717118352);
	delete(m_4148678599404324827);
	delete(m_5858979541697649781);
	delete(m_475130908459448193);
	delete(m_1944881053438915480);
	delete(m_8852439562138811031);
	delete(m_5926931997564326356);
	delete(m_6021211737656574566);
	delete(m_1944881053438915487);
	delete(m_9173074425123117687);
	delete(m_4871252453561570626);
	delete(m_3666029044569158000);
	delete(m_8866221924196606726);
	delete(m_2288052971796078493);
	delete(m_7859976973350993559);
	delete(m_8615406171821724939);
	delete(m_1326257017649359052);
	delete(m_7487400228025037381);
	delete(m_5101855929935703261);
	delete(m_3891906619641533444);
	delete(m_8909638360029056137);
	delete(m_7569735997779609128);
	delete(m_6844757273811952164);
	delete(m_6580415148947944021);
	delete(m_6991273492231054889);
	delete(m_912989145902306795);
	delete(m_2538368198676650686);
	delete(m_5926931997564326355);
	delete(m_1975190577039325928);
	delete(m_2184866596717380790);
	delete(m_4062318297015154296);
	delete(m_3051657303276706316);
	delete(m_4926902997545326535);
	delete(m_2944894053489915548);
	delete(m_4382352007286362734);
	delete(m_3891906619641533445);
	delete(m_4891919619692533505);
	delete(m_8193611561415102671);
	delete(m_7193650561672103056);
	delete(m_3394415405119110063);
	delete(m_7699994247206697647);
	delete(m_922229117511063727);
	delete(m_173993486860062566);
	delete(m_1538339198401650093);
	delete(m_1435577580228956652);
	delete(m_3862447550529416939);
	delete(m_3874487349509702166);
	delete(m_4694333430216376964);
	delete(m_5113542098380201892);
	delete(m_922229117511063720);
	delete(m_6798918866474894686);
	delete(m_4925343521602038233);
	delete(m_6496900620290989447);
	delete(m_3394415405119110056);
	delete(m_77859882999937040);
	delete(m_6874594350266703554);
	delete(m_3126174397139736358);
	delete(m_2770262008012331175);
	delete(m_7774349493623007772);
	delete(m_5577494030930978634);
	delete(m_7746738826449853829);
	delete(m_1621876161099543777);
	delete(m_3514469416139695799);
	delete(m_9128716848140444191);
	delete(m_1181144228284354623);
	delete(m_8774832241746803268);
	delete(m_1770265007993331059);
	delete(m_7700301881869411458);
	delete(m_5906567993981626299);
	delete(m_7587417285397521096);
	delete(m_7193650561672103057);
	delete(m_7193650561672103062);
	delete(m_7138646306155558637);
	delete(m_4153909473486796003);
	delete(m_8587422285208520561);
	delete(m_479808370493456149);
	delete(m_4725447860428984017);
	delete(m_7653691274469346189);
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