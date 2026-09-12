/*
    用单链表保存m个整数，结点的结构为，且∣data∣≤n (n为正整数)
    现要求设计一个时间复杂度尽可能高效的算法，
    对于链表中 data 的绝对值相等的结点，仅保留第一次出现的结点而删除其余绝对值相等的结点。
*/

#include<iostream>
#include<cmath>
using namespace std;

#define MAXN 1001
int d[MAXN];

typedef struct ListNode{
    int data;
    struct ListNode *next; 
} ListNode;

ListNode *createlink(int a[], int m)
{
    ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    head->next = NULL;
    ListNode *tail = head;

    for(int i=0;i<m;i++){
        ListNode *p = (ListNode *)malloc(sizeof(ListNode));
        p->data = a[i];

        tail->next = p;
        p->next = NULL;
        tail = p;
    }
    return head;
}

// 关键函数
void deletenode(ListNode *h)
{
    for(int i=0;i<MAXN;i++){
        d[i] = 0;
    }
    while(h->next != NULL){
        if(d[abs(h->next->data)] == 1){
            h->next = h->next->next;
        }
        else{
            d[abs(h->next->data)] = 1;
            h = h->next; 
        }
    }
}

void display(ListNode *h)
{
    h = h->next;
    while(h != NULL){
        cout<<h->data;
        if(h->next != NULL) cout<<"->";
        h = h->next;
    }
    cout<<endl;
    return;
}

int main()
{
    int a[] = {21,-15,-15,-7,15};
    int m = sizeof(a)/sizeof(a[0]);
    ListNode *h = createlink(a,m);
    
    deletenode(h);
    display(h);
    return 0;
}