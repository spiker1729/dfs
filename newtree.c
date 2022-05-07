#include<stdio.h>
#include<stdlib.h>
struct node
{
    
    int data;
    struct node *lchild,* rchild;
};

struct node *create(){
    int x;
    struct node *newnode;
            newnode=(struct node *) malloc(sizeof(struct node));
        printf("enter the data");
        scanf("%d",&x);
if (x==-1){
       return 0;
}

newnode->data=x;
printf("\nenter the left child of%d (enter -1 for no node) \n",x);
newnode->lchild=create();
printf("\n enter the value of right child of %d (enter -1 for no node)\n ",x);
newnode->rchild=create();
return newnode;
}

void preorder(struct node *root){

  if(root==NULL)
{
    return ;
}
     printf(" %d ,",root->data);

    preorder(root->lchild);
   
   preorder(root->rchild);
  


}
void postorder(struct node *root){

  if(root==NULL)
{
    return ;
}
     postorder(root->lchild);
     postorder(root->rchild);
     printf(" %d ,",root->data);
  


}
void inorder(struct node *root){

  if(root==NULL)
{
    return ;
}
     inorder(root->lchild);
     printf(" %d ,",root->data);
     inorder(root->rchild);
  


}



    void  main(){
    struct node *root;
    root=NULL;
    root= create();
    printf("the pre order of given BINARY TREE traversal is =");
    preorder(root);
    printf("\nthe given BINARY TREE in-order traversal is =");
    inorder(root);
    printf("\nthe post-order traversal is =");
    postorder(root);

}
