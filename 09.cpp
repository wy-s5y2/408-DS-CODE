/*
  假设该链表只给出了头指针 list。
  在不改变链表的前提下，请设计一个尽可能高效的算法，查找链表中倒数第 k 个位置上的结点（k 为正整数）。
  若查找成功，算法输出该结点的 data 域的值，并返回 1；否则，只返回 0。
*/

#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *link;
} Node;

Node* createlink(int a[], int n){
    Node* head = (Node*)malloc(sizeof(Node));
    head->link = NULL;
    Node* tail = head;
    
    for(int i=0;i<n;i++)
    {
      Node *p = (Node *)malloc(sizeof(Node));
      p->data = a[i];
      p->link = NULL;

      tail->link = p;
      tail = p;
    }

    return head;
}

// 查找倒数第k个结点
int FindElement(Node *head, int k) {
  Node *p1 = head;
  Node *p2 = head;
  for (int i = 0; i < k; i++) {
    p1 = p1->link;
    if (p1 == NULL) {
      return 0;
    }
  }
  // p1 != NULL
  while (p1 != NULL) {
    p1 = p1->link;
    p2 = p2->link;
  }
  printf("当前指针执行结点的值：%d\n", p2->data);
  return 1;
}

int main()
{
    // 从数组中构建链表
    int a[]={1,2,3,4,5};
    int n = sizeof(a)/sizeof(a[0]);
    
    Node *head = createlink(a,n);

    FindElement(head,3); // 输出4，倒数第2个
    
    return 0;
}