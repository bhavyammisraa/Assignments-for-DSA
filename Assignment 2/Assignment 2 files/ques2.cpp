// Bubble Sort is the simplest sorting algorithm that works
// by repeatedly swapping the adjacent elements 
// if they are in wrong order. 
// Code the Bubble sort with the following elements:
// 64 34 25 12 22 11 90
//
#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
            swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main() {
    int arr[] = {64,34,25,12,22,11,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    BubbleSort(arr,n);
    cout<<"The sorted array is: ";
    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}