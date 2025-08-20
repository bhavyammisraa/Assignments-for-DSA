//Implement the Binary search algorithm regarded as a fast search algorithm
//with run-time complexity of Ο(log n) in comparison to the Linear Search.

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int n,int arr[],int target){
    int start=0; 
    int end=n-1;
    while(start<=end){
        int mid = start + (end - start)/2;
        if(arr[mid] == target){
        return mid;
        }
        else if(arr[mid] < target){
            start = mid+1;
        }
        else
            end = mid-1;
    }   
    return -1; //in case the target is not present in the array.
}
int main() {
        int arr[100];
        int n;
        cout<<"Enter the number of elements of the array: ";
        cin>>n;
        cout<<"Enter the elements of the array: ";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<endl;
        sort(arr,arr+n);
        for(int j=0;j<n;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
        int target;
        cout<<"Enter the element to find: ";
        cin>>target;
        int result = BinarySearch(n,arr,target);
        if(result != -1){
            cout<<"Element found at the index: "<<result; 
        }
        else
            cout<<"Element not found.";
}