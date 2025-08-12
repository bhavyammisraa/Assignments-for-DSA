// Implement the logic to
// a. Reverse the elements of an array
// b. Find the matrix multiplication
// c. Find the Transpose of a Matrix
#include <bits/stdc++.h>
using namespace std;
void reverseArray(int arr[], int n){
    cout << "Original Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    for (int i = 0; i < n / 2; i++){
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void multiplyMatrices(){
    int r1, r2, c1, c2;
    cout << "Enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2){
        cout << "Matrix multiplication not possible" << endl;
        return;
    }
    int A[10][10], B[10][10], C[10][10] = {0};
    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];
    cout << "Enter elements of second matrix:\n";
 for (int i = 0; i < r2; i++)
    for (int j = 0; j < c2; j++)
        cin >> B[i][j];
 for (int i = 0; i < r1; i++)
    for (int j = 0; j < c2; j++)
        for (int k = 0; k < c1; k++)
            C[i][j] += A[i][k] * B[k][j];
 cout << " Matrix after multiplication:\n";
 for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << C[i][j] << " ";
        cout << endl;
 }
}
void transposeMatrix(){
    int row, col;
    cout << "Enter rows and columns of the matrix: ";
    cin >> row >> col;
    int mat[10][10], trans[10][10];
    cout << "Enter matrix elements:\n";
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin >> mat[i][j];
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            trans[j][i] = mat[i][j];
    cout << "Transpose of the Matrix:\n";
    for (int i = 0; i < col; i++){
        for (int j = 0; j < row; j++)
            cout << trans[i][j] << " ";
        cout << endl;
    }
}
int main(){
    int ch;
    do{
        cout << " MENU \n";
        cout << "1. Reverse Array\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Matrix Transpose\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch){
        case 1:{int n;
                cout << "Enter size of array: ";
                cin >> n;
                int arr[100];
                cout << "Enter array elements: ";
                for (int i = 0; i < n; i++)
                    cin >> arr[i];
                reverseArray(arr, n);
                break;
            }
        case 2: multiplyMatrices();
                break;
        case 3: transposeMatrix();
                break;
        case 4: cout << "Exiting program.\n";
                break;
        default:cout << "Invalid choice.\n";
        }
    } while (ch != 4);
return 0; 
}