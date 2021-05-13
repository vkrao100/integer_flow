#include<stdio.h>
#include<stdlib.h>
#include<cudd.h>
#include<cuddInt.h>
#include<util.h>
#include<time.h>
//#include<cuddZddFuncs.c>

//Helper Functions
DdNode	*zddUnateProduct(DdManager * dd,DdNode * f,DdNode * g);
DdNode	*ZddProduct(DdManager * dd,DdNode * f,DdNode * g);
DdNode* zddUnion(DdManager* manager,DdNode* zdd,DdNode* zdd1);
struct Node* Insert(DdManager* manager,DdNode* zdd,struct Node* head,int n);
struct Node* Delete(struct Node* head,int n);
void Print(DdManager* manager,struct Node* head);
DdNode* getNode(DdManager* manager,struct Node* head,int k);
int size_list(struct Node* head);
DdNode* leadingTerm(DdManager* manager, DdNode* zdd,DdNode *x[10],DdNode* one);
DdNode* MultiVariate(DdManager* manager, DdNode* f,struct Node* head,DdNode *x[3],DdNode* one);
DdNode* spoly(DdManager* manager, DdNode* f,DdNode* g,DdNode *x[3],DdNode* one);
//

//Linked list Node
struct Node
{
	DdNode* node;
    	struct Node* next;
};
//Gives the Unate Product of two zdds iteratively.This code was taken from the file cuddZddFuncs.c.

DdNode	*zddUnateProduct(DdManager * dd,DdNode * f,DdNode * g)
{
    DdNode	*res;

    do {
	dd->reordered = 0;
	res = ZddProduct(dd, f, g);
    } while (dd->reordered == 1);
    return(res);

} /* end of zddUnateProduct */

//Computes the Unate product of two zdds.This code was taken from the file cuddZddFuncs.c.The new zddUnion is added to this code to facilate boolean addition while doing product.
DdNode	*ZddProduct(DdManager * dd,DdNode * f,DdNode * g)
{
    int		v, top_f, top_g;
    DdNode	*term1, *term2, *term3, *term4;
    DdNode	*sum1, *sum2;
    DdNode	*f0, *f1, *g0, *g1;
    DdNode	*r;
    DdNode	*one = DD_ONE(dd);
    DdNode	*zero = DD_ZERO(dd);
    int		flag;

    statLine(dd);
    if (f == zero || g == zero)
        return(zero);
    if (f == one)
        return(g);
    if (g == one)
        return(f);

    top_f = dd->permZ[f->index];
    top_g = dd->permZ[g->index];

    if (top_f > top_g)
	return(ZddProduct(dd, g, f));

    /* Check cache */
    r = cuddCacheLookup2Zdd(dd, ZddProduct, f, g);
    if (r)
	return(r);

    v = f->index;	/* either yi or zi */
    flag = cuddZddGetCofactors2(dd, f, v, &f1, &f0);
    if (flag == 1)
	return(NULL);
    Cudd_Ref(f1);
    Cudd_Ref(f0);
    flag = cuddZddGetCofactors2(dd, g, v, &g1, &g0);
    if (flag == 1) {
	Cudd_RecursiveDerefZdd(dd, f1);
	Cudd_RecursiveDerefZdd(dd, f0);
	return(NULL);
    }
    Cudd_Ref(g1);
    Cudd_Ref(g0);

    term1 = ZddProduct(dd, f1, g1);
    if (term1 == NULL) {
	Cudd_RecursiveDerefZdd(dd, f1);
	Cudd_RecursiveDerefZdd(dd, f0);
	Cudd_RecursiveDerefZdd(dd, g1);
	Cudd_RecursiveDerefZdd(dd, g0);
	return(NULL);
    }
    Cudd_Ref(term1);
    term2 = ZddProduct(dd, f1, g0);
    if (term2 == NULL) {
	Cudd_RecursiveDerefZdd(dd, f1);
	Cudd_RecursiveDerefZdd(dd, f0);
	Cudd_RecursiveDerefZdd(dd, g1);
	Cudd_RecursiveDerefZdd(dd, g0);
	Cudd_RecursiveDerefZdd(dd, term1);
	return(NULL);
    }
    Cudd_Ref(term2);
    term3 = ZddProduct(dd, f0, g1);
    if (term3 == NULL) {
	Cudd_RecursiveDerefZdd(dd, f1);
	Cudd_RecursiveDerefZdd(dd, f0);
	Cudd_RecursiveDerefZdd(dd, g1);
	Cudd_RecursiveDerefZdd(dd, g0);
	Cudd_RecursiveDerefZdd(dd, term1);
	Cudd_RecursiveDerefZdd(dd, term2);
	return(NULL);
    }
    Cudd_Ref(term3);
    term4 = ZddProduct(dd, f0, g0);
    if (term4 == NULL) {
	Cudd_RecursiveDerefZdd(dd, f1);
	Cudd_RecursiveDerefZdd(dd, f0);
	Cudd_RecursiveDerefZdd(dd, g1);
	Cudd_RecursiveDerefZdd(dd, g0);
	Cudd_RecursiveDerefZdd(dd, term1);
	Cudd_RecursiveDerefZdd(dd, term2);
	Cudd_RecursiveDerefZdd(dd, term3);
	return(NULL);
    }
    Cudd_Ref(term4);
    Cudd_RecursiveDerefZdd(dd, f1);
    Cudd_RecursiveDerefZdd(dd, f0);
    Cudd_RecursiveDerefZdd(dd, g1);
    Cudd_RecursiveDerefZdd(dd, g0);
    sum1 = zddUnion(dd, term1, term2);//changed Cudd_ZddUnion to zddUnion.
    if (sum1 == NULL) {
	Cudd_RecursiveDerefZdd(dd, term1);
	Cudd_RecursiveDerefZdd(dd, term2);
	Cudd_RecursiveDerefZdd(dd, term3);
	Cudd_RecursiveDerefZdd(dd, term4);
	return(NULL);
    }
    Cudd_Ref(sum1);
    Cudd_RecursiveDerefZdd(dd, term1);
    Cudd_RecursiveDerefZdd(dd, term2);
    sum2 = zddUnion(dd, sum1, term3);//changed Cudd_ZddUnion to zddUnion.
    if (sum2 == NULL) {
	Cudd_RecursiveDerefZdd(dd, term3);
	Cudd_RecursiveDerefZdd(dd, term4);
	Cudd_RecursiveDerefZdd(dd, sum1);
	return(NULL);
    }
    Cudd_Ref(sum2);
    Cudd_RecursiveDerefZdd(dd, sum1);
    Cudd_RecursiveDerefZdd(dd, term3);
    r = cuddZddGetNode(dd, v, sum2, term4);
    if (r == NULL) {
	Cudd_RecursiveDerefZdd(dd, term4);
	Cudd_RecursiveDerefZdd(dd, sum2);
	return(NULL);
    }
    Cudd_Ref(r);
    Cudd_RecursiveDerefZdd(dd, sum2);
    Cudd_RecursiveDerefZdd(dd, term4);

    cuddCacheInsert2(dd, ZddProduct, f, g, r);
    Cudd_Deref(r);
    return(r);

}

//Computes the boolean addition of zdds.It does addition by A+B=AUB-AnB;
DdNode* zddUnion(DdManager* manager,DdNode* zdd,DdNode* zdd1)
{
	DdNode* u,*u1,*add;
 u=Cudd_zddUnion(manager,zdd,zdd1);//u=AUB;
 if(u!=NULL)
 {
 Cudd_Ref(u);
 }
 u1=Cudd_zddIntersect(manager,zdd,zdd1);//AnB
 if(u1!=NULL)
 {
 Cudd_Ref(u1);
 }
 add=Cudd_zddDiff(manager,u,u1);//A+B=AUB-AnB
 if(add!=NULL)
 {
 Cudd_Ref(add);
 }
  if(u!=NULL) Cudd_RecursiveDerefZdd(manager,u);
  if(u1!=NULL) Cudd_RecursiveDerefZdd(manager,u1);
 return add;
}

//This function takes in a zdd and adds it to the linked list at the position specified by the int n.

struct Node* Insert(DdManager* manager,DdNode* zdd,struct Node* head,int n)
{
	int i;
	struct Node*temp1,*temp2;
	temp1=(struct Node*)malloc(sizeof(struct Node*));//allocating memory to the node temp1
	temp1->node=zdd;
	temp1->next=NULL;
	if(n==1)//if the node to be inserted is first node,then enter this condition and create the first node in the list.
	{
		temp1->next=head;
		head=temp1;
		return head;
		
	}
	temp2=head;
	for (i=0;i<n-2;i++)//traversing the linked list to n-1 node,so we can insert the new node at the nth position.
	{
		temp2=temp2->next;
		
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
	return head;
}

//This function deletes the node specified by the int n.

struct Node* Delete(struct Node* head,int n)
{
	struct Node*temp1,*temp2;
	int i;
	temp1=head;
	if(n==1)//if we want to delete the first node
	{
		head=temp1->next;
		return head;
		
	}
	for (i=0;i<n-2;i++)//traversing the list to n-1th node so we can delete the nth node. 
	{
		temp1=temp1->next;	
	}
	temp2=temp1->next;
	temp1->next=temp2->next;
	return head;
}

//This function prints the minterms of all the nodes int the linked list.

void Print(DdManager* manager,struct Node* head)
{
	struct Node* temp3=head;
	while(temp3!=NULL)//traversing the linked list till we reach the NULL node.
	{	
		Cudd_zddPrintMinterm(manager,temp3->node);
		temp3=temp3->next;
		printf("\n");
	}
	printf("\n");
}

//This function takes the linked list and returns the node at the position specified by int k.
DdNode* getNode(DdManager* manager,struct Node* head,int k)
{
	DdNode* zdd;
	struct Node* temp3=head;
	int i=1;
	if(head==NULL)//if the list is an empty list,then return null.
	{
		return zdd=NULL;
	}
		
	while(temp3!=NULL)//traversing the list and retriving the ith node form the list.
	{	
		if(i==k)
		{
		zdd=temp3->node;
		Cudd_Ref(zdd);
		break;
		}
		temp3=temp3->next;
		i=i+1;
	}
	
	return zdd;
}

//This function takes the linked list and returns  the size of the list.
int size_list(struct Node* head)
{
	struct Node* temp3=head;
	int count=0;
	while(temp3!=NULL)//traversing the list till it reaches the end of the list.
	{	
		temp3=temp3->next;
		count=count+1;//counter to count the number of nodes.
		
	}
	return count;
	
}
//This function takes in the ZDD and returns the leading term of the zdd.In a zdd,we can get the leading term by traversing from the top node of zdd to the constant 1 node.
//It is theproduct of all nodes from root node to the terminal constant node 1.
DdNode* leadingTerm(DdManager* manager, DdNode* zdd,DdNode *x[10],DdNode* one)
{
   DdNode* temp =one;
   Cudd_Ref(temp);
   DdNode *zero=Cudd_zddComplement(manager,one);
   Cudd_Ref(zero);
   DdNode* temp1;
   int i,flag; 
   while(1)
   {
	   if(zdd==one)//checking if the zdd to which the leading term is to be computed is one or zero or NULL.
	   {
		   Cudd_RecursiveDerefZdd(manager, temp); 
		   return one;
	   }
	   if(zdd==zero)
	   {
		   Cudd_RecursiveDerefZdd(manager, temp);
		   return zero;
	   }
	   if(zdd==NULL)
	   {
		   return 0;
	   }

    	 i=zdd->index;//getting the index of the input zdd
	 temp=zddUnateProduct(manager,x[i],temp);//product of the nodes.
	 temp1=Cudd_T(zdd);
	 if(temp1!=NULL)
	 {
		Cudd_Ref(temp1);
	 }
     flag=Cudd_IsConstant(temp1);
     if(flag==1)//checking if the node is a constant node.
      {
         break;
      }
  
     zdd=temp1;
   }
   Cudd_RecursiveDerefZdd(manager, temp1); 
   Cudd_RecursiveDerefZdd(manager, zero); 
   return temp;   
}

//This function performs the multivariate division of a ZDD with a list of ZDDs.It returns the remainder of the division
 DdNode* MultiVariate(DdManager* manager, DdNode* f,struct Node* head,DdNode *x[3],DdNode* one)
  {

  DdNode* quot,*prod,*rem,*leadf,*leadg,*divide,*test,*test2,*g,*zero;
  int i,count;
  zero=Cudd_zddComplement(manager,one);
  Cudd_Ref(zero);
  quot =zero;
  rem=zero;
  i=1;
  g=getNode(manager,head,i);//getting the node from the linked list.
  if(g!=NULL)
  {
	Cudd_Ref(g);
  }
  leadf=leadingTerm(manager, f,x, one);//calculating the leading term of the zdd f
  if(leadf!=NULL)
  {
	Cudd_Ref(leadf);
  }
  leadg=leadingTerm(manager, g,x, one);//calculating the leading term of the zdd g
  if (leadg!=NULL)
  {
	Cudd_Ref(leadg);
  }
 if(g==NULL)
  {
	  return f;
  }

while(f!=zero)
{
	count=0;
	
	for(i=1;i<=size_list(head);i++)
	{
		g=getNode(manager,head,i);
		leadf=leadingTerm(manager, f,x, one);
		leadg=leadingTerm(manager, g,x, one);
		divide=Cudd_zddDivide(manager,leadf,leadg);//leadf/leadg
		if(divide!=NULL)
		{
			Cudd_Ref(divide);
		}
		if (divide!=zero)//checking if the (leadterm(f)/leadterm(z))!=0
		{	
			quot=zddUnion(manager,quot,divide);//quot = quot + (lead(h)/lead(l[i]))
			Cudd_Ref(quot);
			prod=zddUnateProduct(manager,divide,g);
			Cudd_Ref(prod);
			if(Cudd_zddCount(manager,f)>=Cudd_zddCount(manager,g))//
			{
				test=Cudd_zddIntersect(manager,f,prod);
				Cudd_Ref(test);
				test2=Cudd_zddDiff(manager,prod,test);
				Cudd_Ref(test2);
				f=Cudd_zddDiff(manager,f,prod);//h = h - ((lead(h)/lead(l[i]))*l[i]);
				
				f=zddUnion(manager,f,test2);
			
			}
			else if(Cudd_zddCount(manager,f)<Cudd_zddCount(manager,g))
			{
				test=Cudd_zddIntersect(manager,f,prod);
				Cudd_Ref(test);
				test2=Cudd_zddDiff(manager,f,test);
				Cudd_Ref(test2);
				f=Cudd_zddDiff(manager,prod,f);//h = h - ((lead(h)/lead(l[i]))*l[i]);
				f=zddUnion(manager,f,test2);
			
			}
			break;
		 }
		else
		 {
			count =count+1;
		 }
	}
	if(count==size_list(head))
	{		
		rem=zddUnion(manager,rem,leadf);//r = r+lead(h);
		Cudd_Ref(rem);
		f=Cudd_zddDiff(manager,f,leadf);//h=h-lead(h);	

	}
} 
  if(leadf!=NULL)
  {
	Cudd_RecursiveDerefZdd(manager,leadf);
  }
  if(leadg!=NULL)
  {
	Cudd_RecursiveDerefZdd(manager,leadg);
  }
  if(g!=NULL)
  {
	 Cudd_RecursiveDerefZdd(manager,g);
  }
  if(divide!=NULL)
  {
	  Cudd_RecursiveDerefZdd(manager,divide);
  }
return rem;
  }
 //This Function returns the spolynomial of the two zdds 
 DdNode* spoly(DdManager* manager, DdNode* f,DdNode* g,DdNode *x[3],DdNode* one)
 {
  DdNode *leadf,*leadg,*lcm,*divide1,*divide2,*prod1,*prod2,*prod3,*prod4,*sply,*diff,*node8,*node9,*rem;
  leadf=leadingTerm(manager, f,x, one);
  if(leadf!=NULL)
  {
	Cudd_Ref(leadf);
  }
  leadg=leadingTerm(manager, g,x, one);
  if(leadg!=NULL)
  {
	Cudd_Ref(leadg);
  }
  lcm=zddUnateProduct(manager,leadf,leadg);//LCM=leadf*leadg
  Cudd_Ref(lcm);
  divide1=Cudd_zddDivide(manager,lcm,leadf);//(LCM/Lead(f))
  Cudd_Ref(divide1);
  divide2=Cudd_zddDivide(manager,lcm,leadg);//(LCM/Lead(g))
  Cudd_Ref(divide2);
  prod1=zddUnateProduct(manager,divide1,f);
  Cudd_Ref(prod1);
  prod2=zddUnateProduct(manager,divide2,g);
  Cudd_Ref(prod2);
  if(Cudd_zddCount(manager,prod1)>=Cudd_zddCount(manager,prod2))
  {
	prod3=Cudd_zddIntersect(manager,prod1,prod2);
	Cudd_Ref(prod3);
	diff=Cudd_zddDiff(manager,prod2,prod3);
	Cudd_Ref(diff);
	sply=Cudd_zddDiff(manager,prod1,prod2);
	sply=zddUnion(manager,sply,diff);
	Cudd_Ref(sply);
  }
  else if(Cudd_zddCount(manager,prod1)<Cudd_zddCount(manager,prod2))
  {
	prod3=Cudd_zddIntersect(manager,prod1,prod2);
	Cudd_Ref(prod3);
	diff=Cudd_zddDiff(manager,prod1,prod3);
	Cudd_Ref(diff);
	sply=Cudd_zddDiff(manager,prod2,prod1);
	sply=zddUnion(manager,sply,diff);
	Cudd_Ref(sply);
  }
  if(leadf!=NULL)
  {
	Cudd_RecursiveDerefZdd(manager,leadf);
  }
  if(leadg!=NULL)
  {
	Cudd_RecursiveDerefZdd(manager,leadg);
  }
  Cudd_RecursiveDerefZdd(manager,lcm);
  Cudd_RecursiveDerefZdd(manager,divide1);
  Cudd_RecursiveDerefZdd(manager,divide2);
  Cudd_RecursiveDerefZdd(manager,prod1);
  Cudd_RecursiveDerefZdd(manager,prod2);
  Cudd_RecursiveDerefZdd(manager,prod3);
  Cudd_RecursiveDerefZdd(manager,diff);
 return sply;
 }


int main() 
{
   DdNode* one,*zero,*s1_poly,*node1,*node2,*node3,*node4,*node5,*leadp,*leadq,*divide2,*divide3,*remen,*node8,*node9,*rem;
   int i,j,m,length,con,n,cmt;
   struct Node* head,*head2,*head3;
   head =NULL;
   head2 =NULL;  
   head3 =NULL;

   DdManager* manager=Cudd_Init(0, 0, CUDD_UNIQUE_SLOTS, CUDD_CACHE_SLOTS, 0);
   if(manager == NULL) 
   {
      printf("Error while initalizing CUDD.\n");
      return 1;
   }
 
   one=Cudd_ReadZddOne(manager,0);
   Cudd_Ref(one);
   zero=Cudd_zddComplement(manager,one);
   Cudd_Ref(zero);

  //Case1:Cyclic Polynomials
   // for graphs of the result of cyclic polynomials uncomment the code at the bottom
  DdNode* x[4];//variables list
   x[0]=Cudd_zddChange(manager,one,0);
   Cudd_Ref(x[0]);

   x[1]=Cudd_zddChange(manager,one,1);
   Cudd_Ref(x[1]);

   x[2]=Cudd_zddChange(manager,one,2);
   Cudd_Ref(x[2]);

   x[3]=Cudd_zddChange(manager,one,3);
  Cudd_Ref(x[3]);

  
  DdNode* f12=zddUnion(manager,x[0],x[1]);
  Cudd_Ref(f12);
  DdNode* f13=zddUnion(manager,x[2],x[3]);
  Cudd_Ref(f13);
  DdNode* f1=zddUnion(manager,f12,f13);
  Cudd_Ref(f1);
  DdNode* xy=zddUnateProduct(manager,x[0],x[1]);
  Cudd_Ref(xy);
  DdNode* yz=zddUnateProduct(manager,x[1],x[2]);
  Cudd_Ref(yz);
  DdNode* za=zddUnateProduct(manager,x[2],x[3]);
  Cudd_Ref(za);
  DdNode* ax=zddUnateProduct(manager,x[3],x[0]);
  Cudd_Ref(ax);
  DdNode* f21=zddUnion(manager,xy,yz);
  Cudd_Ref(f21);
  DdNode* f22=zddUnion(manager,za,ax);
  Cudd_Ref(f22);
  DdNode* f2=zddUnion(manager,f21,f22);
  Cudd_Ref(f2);
  DdNode* xyz=zddUnateProduct(manager,xy,x[2]);
  Cudd_Ref(xyz);
  DdNode* yza=zddUnateProduct(manager,yz,x[3]);
  Cudd_Ref(yza);
  DdNode* zax=zddUnateProduct(manager,za,x[0]);
  Cudd_Ref(zax);
  DdNode* axy=zddUnateProduct(manager,ax,x[1]);
  Cudd_Ref(axy);
  DdNode* f31=zddUnion(manager,xyz,yza);
  Cudd_Ref(f31);
  DdNode* f32=zddUnion(manager,zax,axy);
  Cudd_Ref(f32);
  DdNode* f3=zddUnion(manager,f31,f32);
  Cudd_Ref(f3);
  DdNode* f41=zddUnateProduct(manager,xy,za);
  Cudd_Ref(f41);
  DdNode* f4=zddUnion(manager,f41,one);
  Cudd_Ref(f4);
  printf("f1\n");
  Cudd_zddPrintMinterm(manager,f1);
  printf("f2\n");
  Cudd_zddPrintMinterm(manager,f2);
  printf("f3\n");
  Cudd_zddPrintMinterm(manager,f3);
  printf("f4\n");
  Cudd_zddPrintMinterm(manager,f4);

 DdNode* z[4];
 z[0]=f1;
 Cudd_Ref(z[0]);
 z[1]=f2;
 Cudd_Ref(z[1]);
 z[2]=f3;
 Cudd_Ref(z[2]);
 z[3]=f4;
 Cudd_Ref(z[3]);
 char* inputNames[4];
   inputNames[0] = "x1";
   inputNames[1] = "x2";
   inputNames[2] = "x3";
   inputNames[3] = "x4";
   char* outputNames[1];
   outputNames[0] = "Reduced Groebner Basis";


   //Case2:
 /*  DdNode* x[5];//variables list
   x[0]=Cudd_zddChange(manager,one,0);
   Cudd_Ref(x[0]);

   x[1]=Cudd_zddChange(manager,one,1);
   Cudd_Ref(x[1]);

   x[2]=Cudd_zddChange(manager,one,2);
   Cudd_Ref(x[2]);

   x[3]=Cudd_zddChange(manager,one,3);
   Cudd_Ref(x[3]);

   x[4]=Cudd_zddChange(manager,one,4);
   Cudd_Ref(x[4]);

   DdNode* xy=zddUnateProduct(manager,x[0],x[1]);
   Cudd_Ref(xy);
   DdNode* yz=zddUnateProduct(manager,x[1],x[2]);
   Cudd_Ref(yz);
   DdNode* xz=zddUnateProduct(manager,x[0],x[2]);
   Cudd_Ref(xz);
   DdNode* ab=zddUnateProduct(manager,x[3],x[4]);
   Cudd_Ref(ab);
   DdNode* f1=zddUnion(manager,ab,one);
   Cudd_Ref(f1);
   DdNode* f2=zddUnion(manager,f1,x[3]);
   Cudd_Ref(f2);
   DdNode* f3=zddUnion(manager,f1,x[4]);
   Cudd_Ref(f3);
   DdNode* f41=zddUnion(manager,ab,x[3]);
   Cudd_Ref(f41);
   DdNode* f4=zddUnion(manager,f41,x[4]);
   Cudd_Ref(f4);
   DdNode* f51=zddUnion(manager,xy,x[0]);
   Cudd_Ref(f51);
   DdNode* f5=zddUnion(manager,f51,x[1]);
   Cudd_Ref(f5);
   DdNode* f61=zddUnion(manager,yz,x[1]);
   Cudd_Ref(f61);
   DdNode* f6=zddUnion(manager,f61,x[2]);
   Cudd_Ref(f6);
   printf("f1\n");
   Cudd_zddPrintMinterm(manager,f1);
   printf("f2\n");
   Cudd_zddPrintMinterm(manager,f2);
   printf("f3\n");
   Cudd_zddPrintMinterm(manager,f3);
   printf("f4\n");
   Cudd_zddPrintMinterm(manager,f4);
   printf("f5\n");
   Cudd_zddPrintMinterm(manager,f5);
   printf("f6\n");
   Cudd_zddPrintMinterm(manager,f6);
   char* inputNames[5];
   inputNames[0] = "x";
   inputNames[1] = "y";
   inputNames[2] = "z";
   inputNames[3] = "a";
   inputNames[4] = "b";
   char* outputNames[1];
   outputNames[0] = "Reduced Groebner Basis";

   DdNode* z[6];
   z[0]=f1;
   Cudd_Ref(z[0]);
   z[1]=f2;
   Cudd_Ref(z[1]);
   z[2]=f3;
   Cudd_Ref(z[2]);
   z[3]=f4;
   Cudd_Ref(z[3]);
   z[4]=f5;
   Cudd_Ref(z[4]);
   z[5]=f6;
   Cudd_Ref(z[5]);*/
 
   //Case #:Chain of OR gates reduction
   //For this case comment out the grobner basis,miinimal and reduced grobner basis code and uncomment the multivaraite division code at the bottom.
   
  /* DdNode* x[9];//variables list
   x[0]=Cudd_zddChange(manager,one,0);
   Cudd_Ref(x[0]);

   x[1]=Cudd_zddChange(manager,one,1);
   Cudd_Ref(x[1]);

   x[2]=Cudd_zddChange(manager,one,2);
   Cudd_Ref(x[2]);

   x[3]=Cudd_zddChange(manager,one,3);
   Cudd_Ref(x[3]);

   x[4]=Cudd_zddChange(manager,one,4);
   Cudd_Ref(x[4]);

   x[5]=Cudd_zddChange(manager,one,5);
   Cudd_Ref(x[5]);

   x[6]=Cudd_zddChange(manager,one,6);
   Cudd_Ref(x[6]);

   x[7]=Cudd_zddChange(manager,one,7);
   Cudd_Ref(x[7]);

   x[8]=Cudd_zddChange(manager,one,8);
  Cudd_Ref(x[8]);

  DdNode* f11=zddUnion(manager,x[0],x[1]);//z+h
  Cudd_Ref(f11);
  DdNode* f12=zddUnateProduct(manager,x[1],x[2]);//he
  Cudd_Ref(f12);
  DdNode* f13=zddUnion(manager,f12,f11);
  Cudd_Ref(f13);
  DdNode* f1=zddUnion(manager,f13,x[2]);//z+h+he+e
  Cudd_Ref(f1);
  DdNode* f21=zddUnion(manager,x[3],x[1]);//g+h
  Cudd_Ref(f21);
  DdNode* f22=zddUnateProduct(manager,x[3],x[4]);//d.g
  Cudd_Ref(f22);
  DdNode* f23=zddUnion(manager,f22,f21);
  Cudd_Ref(f23);
  DdNode* f2=zddUnion(manager,f23,x[4]);//g+h+d.g+d
  Cudd_Ref(f2);
  DdNode* f31=zddUnion(manager,x[3],x[5]);//g+f
  Cudd_Ref(f31);
  DdNode* f32=zddUnateProduct(manager,x[6],x[5]);//f.c
  Cudd_Ref(f32);
  DdNode* f33=zddUnion(manager,f32,f31);
  Cudd_Ref(f33);
  DdNode* f3=zddUnion(manager,f33,x[6]);//c+f.c+g+f
  Cudd_Ref(f3);
  DdNode* f41=zddUnion(manager,x[5],x[7]);//f+a
  Cudd_Ref(f41);
  DdNode* f42=zddUnateProduct(manager,x[7],x[8]);//a.b
  Cudd_Ref(f42);
  DdNode* f43=zddUnion(manager,f42,f41);
  Cudd_Ref(f43);
  DdNode* f4=zddUnion(manager,f43,x[8]);//b+a.b+f+a
  Cudd_Ref(f4);
  printf("f1\n");
  Cudd_zddPrintMinterm(manager,f1);
  printf("f2\n");
  Cudd_zddPrintMinterm(manager,f2);
  printf("f3\n");
  Cudd_zddPrintMinterm(manager,f3);
  printf("f4\n");
  Cudd_zddPrintMinterm(manager,f4);
  DdNode* z[4];
  z[0]=f1;
  Cudd_Ref(z[0]);
  z[1]=f2;
  Cudd_Ref(z[1]);
  z[2]=f3;
  Cudd_Ref(z[2]);
  z[3]=f4;
  Cudd_Ref(z[3]);
  char* inputNames[9];
   inputNames[0] = "z";
   inputNames[1] = "h";
   inputNames[2] = "e";
   inputNames[3] = "g";
   inputNames[4] = "d";
   inputNames[5] = "f";
   inputNames[6] = "c";
   inputNames[7] = "a";
   inputNames[8] = "b";
   char* outputNames[1];
   outputNames[0] = "Remainder";*/

//comment till here for excluding third case

	 

 length=sizeof(z)/sizeof(DdNode*);
  for(m=0;m<length;m++)//grobner basis list creation
  {
	head2=Insert(manager,z[m],head2,m+1);
  }

  con=0;
  n=1;

//start commenting from here for case 3

  for(i=0;i<length;i++)
  {
		for(j=i+1;j<length;j++)//Creating pairs into the list
		{
			
			head=Insert(manager,z[i],head,n);
			head=Insert(manager,z[j],head,n+1);
			n=n+2;
		}
	}
   while(size_list(head)!=0)
	{
		node1=getNode(manager,head,1);
		if(node1!=NULL)
		{
			Cudd_Ref(node1);
		}
		node2=getNode(manager,head,2);
		if(node2!=NULL)
		{
			Cudd_Ref(node2);
		}		
		s1_poly = spoly(manager,node1,node2,x,one);
		if(s1_poly!=NULL)
		{
			Cudd_Ref(s1_poly);
		}
		con=con+1;
		if(s1_poly == zero)
		{
			head=Delete(head,1);
			head=Delete(head,1);
			continue;
		}
		else
		{	
		
		remen  = MultiVariate(manager, s1_poly,head2,x,one);//Calculating the remainder
		if(remen!=NULL)
		{
			Cudd_Ref(remen);
		}
		if(remen == zero)
		{
			head=Delete(head,1);
			head=Delete(head,1);
			continue;
		}
		else
		{
			head2=Insert(manager,remen,head2,(size_list(head2)+1));//adding the new remainder to the grobner basis list.
		        cmt = size_list(head)+1;
			for(int cnt =1;cnt<size_list(head2);cnt++)//recreating the pairs with the grobner basis
				{
					node3=getNode(manager,head2,cnt);
					if(node3!=NULL)
					{
						Cudd_Ref(node3);
					}
					head=Insert(manager,node3,head,cmt);
					head=Insert(manager,remen,head,cmt+1);
					
					cmt=cmt+2;
					

				}
				
				head=Delete(head,1);
				head=Delete(head,1);

			}
			}
	}
 printf("\n");
printf("Grobner Basis\n");
Print(manager,head2);
for(i=1;i<=size_list(head2);i=i+1)//minimal grobner basis
   {
     for(j=i+1;j<=size_list(head2);j=j+1)
       {
	     node4=getNode(manager,head2,i);
	     if(node4!=NULL)
	       {
		   Cudd_Ref(node4);
	       }
	      node5=getNode(manager,head2,j);
	     if(node5!=NULL)
	      {
	           Cudd_Ref(node5);
	      }
	      leadp=leadingTerm(manager,node4,x,one);
	     if(leadp!=NULL)
	      {
		   Cudd_Ref(leadp);
	      }
	      leadq=leadingTerm(manager,node5,x,one);
	     if(leadq!=NULL)
	      {
	           Cudd_Ref(leadq);
	      }
	     divide2=Cudd_zddDivide(manager,leadp,leadq);
	     Cudd_Ref(divide2);
	     divide3=Cudd_zddDivide(manager,leadq,leadp);
	     Cudd_Ref(divide3);
	     if(divide2!=zero)//leadmonom(head[i]))/(leadmonom(head[j])!=0
             {		 
                  head2=Delete(head2,i);
		  i=i-1;
                  break;
            }
           if(divide3!=zero)//leadmonom(head2[j]))/(leadmonom(head2[i])
               {
				  
	         head2=Delete(head2,j);
		 i=i-1;
                 break;
               }
           
        }
        
      }


printf("Minimal Basis\n");
Print(manager,head2);

for(m=1;m<=size_list(head2);m++)//reduced grobner basis
 {
	 node8=getNode(manager,head2,m);
	 if(node8!=NULL)
	 {
		 Cudd_Ref(node8);
	 }
	 head3=Insert(manager,node8,head3,m);
 }

 for(i=1;i<size_list(head2)+1;i++)
{
	node9=getNode(manager,head2,i);
	if(node9!=NULL)
	{
		Cudd_Ref(node9);
	}
	head3=Delete(head3,i);
	rem=MultiVariate(manager,node9,head3,x,one);
	if(rem!=NULL)
	{
		Cudd_Ref(rem);
	}
        if(rem != zero) 
        {
	   head2=Insert(manager,rem,head3,i);
       
        }
       else
        {
	   head2=Delete(head2,i);
        }
        head3=head2;
}
 printf("Reduced Grobner\n");
 Print(manager,head2);
printf("Number of s_polynomials=%d\n",con);

/*clock_t t = clock();
 DdNode*remend=MultiVariate(manager,x[0],head2,x,one);
 t = clock() - t;
 printf ("It took %f seconds.\n",((float)t)/CLOCKS_PER_SEC);
 Cudd_Ref(remend);
 printf("Rememainder\n");
 Cudd_zddPrintMinterm(manager,remend);*/

//for cyclic polynomials if the graph is to be viewed un comment the following code and change the term inside getnode from 1-4 and change the term inside
//dumpdot form f1 to viewnode.
//DdNode* viewnode=getNode(manager,head2,1);
//Cudd_Ref(viewnode);

   FILE* fp = fopen("cyclic_polynomials.dot", "w");
//add remainder for case3 insead of f1 to look at the remainder
   Cudd_zddDumpDot(manager, 1, &f1, inputNames, outputNames, fp);
   fclose(fp); 
   Cudd_Quit(manager);
   return 0;
} 






