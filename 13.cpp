/*
    已知一个整数序列 A = (a0, a1, …, a (n−1))，其中 0 ≤ ai < n (0 ≤ i < n)。
    若存在 a (p1) = a (p2) = … = a (pm) = x 且 m > n/2 (0 ≤ pk < n, 1 ≤ k ≤ m)，则称 x 为 A 的主元素。
    假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A的主元素。
*/

#include<iostream>
using namespace std;

int majority(int a[], int n)
{
    if(n==0){
        return -1;
    }
    // num用于表示当前所选择的主元素(初始时选第一个元素)
    int num = a[0];
    // cnt记录当前主元素与其他元素的差值
    int cnt = 1;

    for(int i=1;i<n;i++){
        if(a[i] == num){
            cnt++;
        }
        else{
            cnt--;
            // 如果差值小于等于0，就更换主元素为当前遍历的元素
            if(cnt == 0){
                num = a[i];
                cnt = 1;
            }
        }
    }
    // m用于记录主元素出现的个数
    int m = 0;
    for(int i=0;i<n;i++){
        if(a[i] == num){
            m++;
        }
    }
    if(m > n/2){
        return num;
    }
    return -1;
}

int main()
{
    int A[]={0,5,5,3,5,7,5,5};
    int n = sizeof(A)/sizeof(A[0]);

    int result = majority(A,n);
    cout<<"主元素为:"<<result;
    return 0;
}