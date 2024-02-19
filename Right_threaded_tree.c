#include<stdio.h>
void main()
{
inorder();
}
void inorder()
{
struct node *p=root;
struct node *q;
do
{
q=NULL;
while(p!=NULL)
{
q=p;
p=p->left;
}
if(q!=NULL)
{
printf("\t %d",q->data);
p=q->right;
while(q->rthread&&p!=NULL)
{

printf("\t %d",p->data);
q=p;
p=p->right;
}
}
}while(q!=NULL);
}
