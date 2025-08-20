// Design the Logic to Find a Missing Number in a Sorted Array.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n-1; i++){
        if(arr[i]+1 != arr[i+1]){
            cout<<"The missing number in the array is: "<<arr[i]+1;
        }
    }
    return 0;
}