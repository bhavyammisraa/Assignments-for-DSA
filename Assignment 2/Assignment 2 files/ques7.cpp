//Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to
//be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ].
// Write a program to count the number of inversions in an array.
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int inversionCount = 0;

    // Check all pairs (i, j)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inversionCount++;
                cout << "Inversion: (" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }

    cout << "Total number of inversions: " << inversionCount << endl;

    return 0;
}
