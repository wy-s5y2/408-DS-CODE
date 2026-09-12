/*
    设将 n (n> 1) 个整数存放到一维数组 R 中。
    试设计一个在时间和空间两方面都尽可能高效的算法。
    将 R 中保存的序列循环左移 p (0 < p < N) 个位置，
    即将 R 中的数据由 < x0, x1, …, x (n−1) > 变换为 < xp, xp+1, …, xn−1, x0, x1, …, xp−1 >。
*/
#include<iostream>
using namespace std;

void reverse(int a[], int l, int r)
{
    while(l<r){
        int temp = a[l];
        a[l] = a[r];
        a[r] = temp;
        l++;
        r--;
    }
}

void loopmove(int a[], int n, int p)
{
    if(p<0){
        return;
    }
    p = p%n;
    reverse(a,0,p-1);
    reverse(a,p,n-1);
    reverse(a,0,n-1);
}

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(a)/sizeof(a[0]);

    int p=4;

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    loopmove(a,n,p);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}