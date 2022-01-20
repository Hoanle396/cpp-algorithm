#include <conio.h>
#include <stdio.h>

struct NODE
{
    int data;
    NODE* pLeft;
    NODE* pRight;
};

NODE* CreateNode(int x)
{
    NODE* p = new NODE();
    p->data = x;
    p->pLeft = p->pRight = NULL;
    return p;
}
NODE* FindInsert(NODE* root, int x)
{
    if (root == NULL)
    {
        return NULL;
    }
    NODE* p = root;
    NODE* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->data > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }        
    return f;
}
void InsertNode(NODE* &root, int x)
{
    NODE* n = CreateNode(x);
    if (root == NULL)
    {
        root = n;
        return;
    }
    else
    {
        NODE* f = FindInsert(root, x);
        if (f != NULL)
        {
            if (f->data > x)
            {
                f->pLeft = n;
            }
            else
            {
                f->pRight = n;
            }
        }
    }
}
void CreateTree(NODE* &root, int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        InsertNode(root, a[i]);
    }

}
void LNR(NODE* root)
{
	if (root != NULL)
	{   
		LNR(root->pLeft);
		printf("%d \t", root->data);
		LNR(root->pRight);
	}
}

int isBST(NODE* root, int min, int max) {

	if (root==NULL)
		return 1;

	if (root->data < min || root->data > max)
		return 0;

	return
	    isBST(root->pLeft, min, root->data-1) && isBST(root->pRight,root->data+1, max);
}
int main()
{
	NODE* root = NULL;
	int n,i;
	int a[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		}
	CreateTree(root, a, n);
	LNR(root);
	if(isBST(root,0,100)){
		printf("\n IS BST");
	}
	else{
		printf("\n ISN'T BST");
	}
	return 0;
}
