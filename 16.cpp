/*
    已知由 n (n≥2) 个正整数构成的集合 A={a_k|0≤k<n}，
    将其划分为两个不相交的子集 A₁和 A₂，元素个数分别是 n₁和 n₂，A₁和 A₂中元素之和分别为 S₁和 S₂。
    设计一个尽可能高效的划分算法，满足 | n₁−n₂| 最小且 | S₁−S₂| 最大。
*/

#include<iostream>
using namespace std;

int partition(int A[], int low, int high)
{
    int l = low;
    int r = high;
    int pivot = A[l];
    while(l < r){
        while(l < r && A[r] >= pivot){
            r--;
        }
        A[l] = A[r];
        while(l < r && A[l] <= pivot){
            l++;
        }
        A[r] = A[l];
    }
    A[l] = pivot;
    return l;
}

void quick_select(int A[],int low,int high,int k)
{
    if(low < high){
        int pivot = partition(A,low,high);
        if(pivot == k){
            return;
        }else if(pivot < k){
            quick_select(A,pivot+1,high,k);
        }else{
            quick_select(A,low,pivot-1,k);
        }
    }
}

int solve(int A[], int n){
    quick_select(A,0,n-1,n/2);
    int S1=0;
    int S2=0;
    for(int i=0;i<n/2;i++){
        S1 += A[i];
    }
    for(int i=n/2;i<n;i++){
        S2 += A[i];
    }
    return S2-S1;
}

int main()
{
    int A[] = {3,7,2,6,1,5,4};
    int n = sizeof(A)/sizeof(A[0]);
    cout<<solve(A,n);
    return 0;
}