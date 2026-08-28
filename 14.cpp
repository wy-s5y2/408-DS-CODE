#include<iostream>
using namespace std;

typedef struct BiTNode
{
    int weight;
    struct BiTNode *lchild,*rchild;
}BitNode, *BiTree;

BiTree create_Tree()
{
    /*         
                root (0)
                /      \
            N1 (0)    N2 (5)
            /    \
        N3 (1)  N4 (2)

        wpl = (1*2 + 2*2) + (0*1 + 5*1) = 11
    */

    BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *n1 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *n2 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *n3 = (BiTNode *)malloc(sizeof(BiTNode));
    BiTNode *n4 = (BiTNode *)malloc(sizeof(BiTNode));

    root->weight = 0;
    n1->weight = 0;
    n2->weight = 5;
    n3->weight = 1;
    n4->weight = 2;

    root->lchild = n1;
    root->rchild = n2;
    n1->lchild = n3;
    n1->rchild = n4;

    n2->lchild = NULL;
    n2->rchild = NULL;
    n3->lchild = NULL;
    n3->rchild = NULL;
    n4->lchild = NULL;
    n4->rchild = NULL;

    return root;
}

int _wpl(BiTNode *root,int depth)
{
    if(root == NULL){
        return 0;
    }
    int sum = 0;
    if(root->lchild == NULL && root->rchild == NULL){
        sum += (depth * (root->weight));
    }
    sum += _wpl(root->lchild, depth+1);
    sum += _wpl(root->rchild, depth+1);
    return sum;
}

int main()
{
    BiTree root = create_Tree();

    int result = _wpl(root,0);

    cout<<result<<endl;
    return 0;
}