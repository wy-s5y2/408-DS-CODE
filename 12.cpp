/*
假定采用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可共享相同的后缀存储空间
设 str1 和 str2 分别指向两个单词所在单链表的头结点，链表结点结构为 | data | next |，
请设计一个时间上尽可能高效的算法，找出由 str1 和 str2 所指向两个链表共同后缀的起始位置
*/

#include<iostream>
using namespace std;

typedef struct Node{
    char data;
    struct Node *next;
} Node;

Node *createlink(string s)
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    Node *tail = head;
    for(int i=0;i<s.length();i++)
    {
        Node *p = (Node *)malloc(sizeof(Node));
        p->data = s[i];
        p->next = NULL;

        tail->next = p;
        tail = p;
    }
    return head;
}

int getlength(Node *h)
{
    int length = 0;
    Node *p = h->next;
    while(p != NULL){
        length++;
        p = p->next;
    }
    return length;
}

// 关键函数
Node *findCommonSuffix(Node *h1, Node *h2)
{
    Node *s1 = h1->next;
    Node *s2 = h2->next;
    int m = getlength(h1);
    int n = getlength(h2);

    if(m>n){
        for(int i=0;i<m-n;i++){
            s1 = s1->next;
        }
    } 
    else{
        for(int i=0;i<n-m;i++){
            s2 = s2->next;
        }
    }

    /*
    两个链表相等的条件：
        结点数量必须完全相同,并且直到尾结点，依次每个结点的data值相同
    */ 
    while(s1 != s2){
        s1 = s1->next;
        s2 = s2->next;
    }

    return s1;
}

void display(Node *s)
{
    if(s == NULL)
    {
        cout<<"无公共后缀"<<endl;
        return;
    }
    while(s != NULL)
    {
        cout<<s->data;
        s = s->next;
    }
    cout<<endl;
}

int main()
{
    string str1 = "load";
    string str2 = "be";
    string com = "ing";
    Node *h1 = createlink(str1);
    Node *h2 = createlink(str2);
    Node *common = createlink(com)->next;

    // 把两个链表尾部接上公共后缀
    Node* p = h1; while(p->next) p=p->next; p->next = common;
    Node* q = h2; while(q->next) q=q->next; q->next = common;

    Node *res = findCommonSuffix(p,q);

    display(res);
    return 0;
}