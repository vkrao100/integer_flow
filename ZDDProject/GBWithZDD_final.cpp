// GBWithZDD_final.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include "cuddObj.hh"
#include <math.h>
#include "util.h"
#include "cudd.h"
#include <map>
using namespace std;

DdManager *dd = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0);
map<int, DdNode *> dict;

vector<int> FindIndex(DdNode* node)
{
	vector<int> terms;
	while(node->type.value != 1.0)
	{
		terms.push_back(node->index);
		node = node->type.kids.T;
	}
	return terms;
}

DdNode* CreateMinterms(vector<int> indices)
{
	if(indices.size() == 1)
	{
		return dict[indices[0]];
	}
	DdNode* temp = Cudd_zddUnateProduct(dd, dict[indices[0]], dict[indices[1]]);
	for(int i = 2; i < indices.size(); i++)
	{
		temp = Cudd_zddUnateProduct(dd, temp, dict[indices[i]]);
	}
	return temp;
}

DdNode* FindLeadingTerm(DdNode* node)
{
	if(node->type.value == 1.0)
	{
		return node;
	}
	vector<int> terms = FindIndex(node);	
	//DdNode *temp = Cudd_ReadZddOne(dd,0);
	DdNode* temp = CreateMinterms(terms);
	return temp;
}

DdNode* FindLCM(DdNode* a, DdNode* b)
{
	DdNode* temp = Cudd_zddUnateProduct(dd, a, b);
	return temp;
}

DdNode* ZddDiff(DdNode* a, DdNode* b)
{
	DdNode* tmp1 = Cudd_zddIntersect(dd, a, b);
	DdNode* tmp2 = Cudd_zddUnion(dd, a, b);
	DdNode* diff = Cudd_zddDiff(dd, tmp2, tmp1);
	return diff;
}

DdNode* ZddMultivarDivide(DdNode* h, vector<DdNode*> v)
{
	int flag;
	DdNode *r = Cudd_ReadZero(dd);
	while(h->type.value != 0.0)
	{
		flag = 0;
		for(int i = 0; i < v.size(); i++)
		{
			DdNode* q = Cudd_zddDivide(dd, FindLeadingTerm(h), FindLeadingTerm(v[i]));
			if(q->type.value != 0.0)
			{
				DdNode* tmp = Cudd_zddUnateProduct(dd, q, v[i]);
				h = ZddDiff(h, tmp);
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			r = Cudd_zddUnion(dd, r, FindLeadingTerm(h));
			h = Cudd_zddDiff(dd, h, FindLeadingTerm(h));
		}
	}
	return r;
}

DdNode* SPoly(DdNode* a, DdNode* b)
{
	DdNode* lcm = Cudd_zddUnateProduct(dd, FindLeadingTerm(a), FindLeadingTerm(b));
	DdNode* tmp1 = Cudd_zddDivide(dd, lcm, FindLeadingTerm(a));
	DdNode* tmp2 = Cudd_zddUnateProduct(dd, tmp1, a);
	DdNode* tmp3 = Cudd_zddDivide(dd, lcm, FindLeadingTerm(b));
	DdNode* tmp4 = Cudd_zddUnateProduct(dd, tmp3, b);
	DdNode* o = ZddDiff(tmp2, tmp4);
	return o;
}

void DisplayZdd(vector<DdNode*> G)
{
	int size = G.size();
	DdNode** output = new DdNode*[size];
	for(int i = 0; i < size; i++)
	{
		output[i] = G[i];
	}
	FILE* outFile = fopen("zdd_graph.dot", "w");
	Cudd_zddDumpDot(dd, size, output, NULL, NULL, outFile);
	fclose(outFile);
}

vector<DdNode*> Grobner(vector<DdNode*> G)
{
	vector<DdNode*> b(2);
	vector<vector<DdNode*> > g;
	int i, j;
	//Form the pairs
	for( i = 0; i < G.size()-1; i = i+1)
	{
		for(j = i+1; j < G.size();j = j+1)
		{
			b[0] = G[i];
			b[1] = G[j];
			g.insert(g.begin(),b);
		}
	}
	DdNode* S;
	DdNode* r;
	int count = 0;
	int count1 = 0;
	vector<DdNode*> temp(2);
	while ( g.size() != 0)
	{
		S = SPoly(g[0][0],g[0][1]);
		count = count + 1;
		g.erase(g.begin());
		r = ZddMultivarDivide(S,G);
		if( r->type.value != 0.0)
		{
			count1 = count1 +1;
			for ( j = 0; j < G.size(); j = j+1)
			{
				temp[0] = G[j];
				temp[1] = r;
				g.push_back(temp);
			}
			G.push_back(r);
		}
	}
	return G;
}

vector<DdNode*> ReducedGrobner(vector<DdNode*> G)
{
	vector<DdNode*> B = Grobner(G);
	// Find Minimal Basis
	for(int i = 0; i<B.size(); i = i+1)
	{
		for(int j = 0; j<B.size(); j=j+1)
		{
			DdNode* temp = Cudd_zddDivide(dd, FindLeadingTerm(B[j]), FindLeadingTerm(B[i]));
			if(i!=j && temp->type.value !=0.0)
			{
				B.erase(B.begin()+j);
				j=j-1;
				if(i>j)
				{
					i = i-1;
				}
			}
		}
	}
	//Find Reduced Basis
	DdNode* p, *r;
	vector<DdNode*> H = B;
	for(int i = 0; i<B.size(); i = i+1)
	{
		p = B[i];
		H.erase(H.begin()+i);
		r = ZddMultivarDivide(p,H);
		H.insert(H.begin()+i, r);
	}
	return H;
}

int main(int argc, char* argv[])
{
	DdNode *w, *x, *y, *z, *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l, *temp1, *temp2, *temp3, *temp4, *z_bar, *zero, *one;
	one = Cudd_ReadZddOne(dd, 0);
	//TA's first example : ab+1, ab+a+1, ab+b+1, ab+a+b, xy+x+y, yz+y+z
	x = Cudd_zddChange(dd, one, 0);
	y = Cudd_zddChange(dd, one, 1);
	z = Cudd_zddChange(dd, one, 2);
	a = Cudd_zddChange(dd, one, 3);
	b = Cudd_zddChange(dd, one, 4);
	temp1 = Cudd_zddUnateProduct(dd, a, b);
	c = Cudd_zddUnion(dd, temp1, one);
	d = Cudd_zddUnion(dd, c, a);
	e = Cudd_zddUnion(dd, c, b);
	f = Cudd_zddUnion(dd, temp1, a);
	g = Cudd_zddUnion(dd, f, b);
	temp2 = Cudd_zddUnateProduct(dd, x, y);
	h = Cudd_zddUnion(dd, temp2, x);
	i = Cudd_zddUnion(dd, h, y);
	temp3 = Cudd_zddUnateProduct(dd, z, y);
	temp4 = Cudd_zddUnion(dd, temp3, y);
	j = Cudd_zddUnion(dd, temp4, z);
	dict[0] = x;
	dict[1] = y;
	dict[2] = z;
	dict[3] = a;
	dict[4] = b;
	vector<DdNode*> v;
	v.push_back(c);
	v.push_back(d);
	v.push_back(e);
	v.push_back(g);
	v.push_back(i);
	v.push_back(j);
	vector<DdNode*> grob = Grobner(v);
	vector<DdNode*> red = ReducedGrobner(v);
	DisplayZdd(red);
        //To display a single pointer to zdd
        //vector<DdNode*> zdd;
        //zdd.push_back(c);
        //DisplayZdd(c);
}
