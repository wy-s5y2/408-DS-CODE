#include<iostream>
using namespace std;
typedef int ElemType;

void InsertSort(ElemType A[], int n)
{
    int i,j;
    for(i=2;i<=n;i++){
        if(A[i] < A[i-1]){
            A[0] = A[i];
            for(j=i-1;A[0]<A[j];j--){
                A[j+1] = A[j];
            }
            A[j+1] = A[0];
        }
    }
}

int main()
{
    int A[] = {0,49,38,65,97,76,13,27,49};
    // A[0]作为哨兵，有效数据为n-1
    int n = sizeof(A)/sizeof(A[0])-1;
    InsertSort(A,n);

    for(int i=1;i<=n;i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}