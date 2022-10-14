#include<iostream>

using namespace std;

int  isArraySortedOrder(int A[], int n){
    if(n == 1){
        return 1;
    }
    return (A[n-1]<A[n-2]? 0 :isArraySortedOrder(A,n-1));
}

int main(){
    int arr[]= {7 ,8 , 3, 5 ,2 ,6};
    int arr1[] = {1,2,3,4,5,6};
    cout<<isArraySortedOrder(arr,6)<<endl;
    cout<<isArraySortedOrder(arr1,6);
    return 0;
}