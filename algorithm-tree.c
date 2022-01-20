#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
struct avl{
	int data;
	struct avl* l;
	struct avl* r;
};
struct avl* insert(struct avl *r, int v);
void pre_order(struct avl *T);
void in_order(struct avl *T);
void post_order(struct avl *T);
int LeftMostValue( struct avl * root );
int RightMostValue( struct avl * root );
bool Search( struct avl * root, int value );
int Count(struct avl * t);
int countLeafNode(struct avl * root, int count );
int main(){
	struct node*a,*t;
    t=NULL;	
    a=NULL;
	int x,value,count=0;
	char k;
	while(k=='n'){
		printf("NHAP PHAN TU");scanf("%d",&x);
		t=insert(a , x);
		printf("TIEP TUC ? Y/N"); scanf("%c",&k);
	}
	printf("pre_order\n");
	pre_order(t);
	printf("in_order\n");
	in_order(t);
	printf("post_order\n");
	post_order(t);
	printf("MIN",LeftMostValue(t));
	printf("MAX",RightMostValue(t));
	printf("value");scanf("%d",&value);
	if(Search(t,value)==true){
		printf("TIM THAY %d",value);
	}
	else{
		printf("KHONG TIM THAY");
	}
	printf("COUNT",Count(t));
	printf("countLeaf",countLeafNode(t,count));
}
struct avl* insert(struct avl *r, int v) {
   if (r == NULL) {
      r = (struct avl*)malloc(sizeof(struct avl));
      r->data = v;
      r->l = NULL;
      r->r = NULL;
      return r;
   } else if (v< r->data) {
      r->l = insert(r->l, v);
   } else if (v >= r->data) {
      r->r = insert(r->r, v);
   } return r;
}
void pre_order(struct avl *T){
	if (T!=NULL) {
		printf("%d", T->data);
		pre_order(T->l);
		pre_order(T->r);
	}	
}
void in_order(struct avl *T){
	if (T!=NULL) {
		pre_order(T->l);
		printf("%d", T->data); // duyet goc o giua
		pre_order(T->r);
	}	
}

void post_order(struct avl *T){
	if (T!=NULL) {
		post_order(T->l);
		post_order(T->r);
		printf("%d", T->data); // duyet goc o cuoi
	}	
}
int LeftMostValue( struct avl * root )// Min
{
    while ( root->l != NULL )
        root = root->l;
    return root->data;
}
int RightMostValue( struct avl * root )// Max
{
    while ( root->r != NULL )
        root = root->r;
    return root->data;
}
bool Search( struct avl * root, int value )//Sreach a value
{
    if (root == NULL )
        return false;
    if(root->data == value){
        return true;
    }
	else
	{
        Search( root->l, value );
        Search( root->r, value );
    }
}
int Count(struct avl * t) { // Count
   if( t == NULL)
      return 0;
   else
      return 1 + Count(t->l) + Count(t->r);
}
int countLeafNode(struct avl * root, int count ){ //Dem  la
	
	if(root!=NULL){
		countLeafNode(root->l, count);
		if(root->r == NULL && root->r == NULL ) count++;
		countLeafNode(root->r, count);
	}
	return count;
}
