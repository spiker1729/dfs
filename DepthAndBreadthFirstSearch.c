#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct node *next;

};struct Node *front=NULL,*rear=NULL;
void enqueue(int x)
{       
 // struct Node *rear=NULL;
        struct Node *t;
        t=(struct Node*)malloc(sizeof(struct Node));
        if(t==NULL){
            printf("Queue is full\n");
        }
        else{
            t->data=x;
            t->next=NULL;
            if(front==NULL)
            {
                front=rear=t;
            }
            else{
                rear->next=t;
                rear=t;
            }
        }
 }

int  dequeue(){
    int x=-1;
    struct Node* t;
        if(front==NULL){
            printf("queue is full");

        }
        else{
            x=front->data;
            t=front;
            front=front->next;
            free(t);
        }
        return x;
}
int isEmpty()
{
    return front==NULL;
}
void DFS(int G[][8],int start,int n){
    int j;
  static  int visited[8]={0};
    if(visited[start]==0){
        printf("%d",start);
        visited[start]=1;
        for(j=1;j<n;j++){
            if(G[start][j]==1&&visited[j]==0){
                DFS(G,j,n);
            }
        }
    }
}
void BFS(int G[][8],int start,int n)
{
    int i=start;
    int visited[8]={0};
    printf("%d",i);
    visited[i]=1;
    enqueue(i);
    while(!isEmpty()){
       i=dequeue();
        for(int j=1;j<n;j++){
            if(G[i][j]==1&&visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }
}

int main(){
    int n1,n2;
  /*  int G[n1][n2];
    printf("enter the values 0 for no edges and 1 for an edge");
    
    for(int i=0;i<n1;i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%d",&G[i][j]);
        }
        
    }*/
           int G[8][8]={{0,0,0,0,0,0,0,0,},
                          {0,0,0,1,1,0,0,0,},
                          {0,0,1,0,0,1,0,0,},
                          {0,0,1,0,0,1,0,0,},
                          {0,0,0,1,1,0,1,1,},
                          {0,0,0,0,0,1,0,0,},
                          {0,0,0,0,0,1,0,0,},
                          {0,0,0,0,0,1,0,0,}};
            printf("The BREADTH first traversal is =\n ");                     
            BFS(G,4,8);
            printf("The DEPTH first traversal is = \n");      
            DFS(G,4,8);

    return 0;
}

