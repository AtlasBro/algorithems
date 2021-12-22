#include<stdio.h>
#include<malloc.h>

typedef struct BNode{
    int data;
    struct BNode * lchild,* rchild;
}BTNode;

BTNode * CreateBTree(int a[],int b[],int n){
    int k;
    if(n<=0) return NULL;
    int root=a[0];
    BTNode *bt=(BTNode *)malloc(sizeof(BTNode));
    bt->data=root;
    for(k=0;k<n;k++)
        if(b[k]==root)
            break;
    bt->lchild=CreateBTree(a+1,b,k);
    bt->rchild=CreateBTree(a+k+1,b+k+1,n-k-1);
    return bt;
}
void DestroyBtree(BTNode * &bt,int x){
    if(bt!=NULL){
        if(bt->data==x)
        {
            DestroyBtree(bt->lchild,x);
            DestroyBtree(bt->rchild,x);
            free(bt);
        }
    }
}
int main(){
    int a[9];
    int b[9];
    for(int i=0;i<9;i++){
        a[i]=i;
        b[i]=i;
    }
    BTNode *bt=CreateBTree(a,b,9);
    DestroyBtree(bt,3);
    printf("1");
}