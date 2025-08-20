#include <iostream>
using namespace std;

#define MAX 100   // max non-zero elements

// Function to read a sparse matrix in triplet form
void readSparse(int mat[MAX][3]) {
    int rows, cols, n;
    cout << "Enter rows, cols and number of non-zero elements: ";
    cin >> rows >> cols >> n;
    mat[0][0] = rows;
    mat[0][1] = cols;
    mat[0][2] = n;
    cout << "Enter row, column and value for each non-zero element:\n";
    for(int i=1; i<=n; i++) {
        cin >> mat[i][0] >> mat[i][1] >> mat[i][2];
    }
}

// Function to display a sparse matrix in triplet form
void displaySparse(int mat[MAX][3]) {
    int n = mat[0][2];
    cout << "Row Col Val\n";
    for(int i=0; i<=n; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

// (a) Transpose of Sparse Matrix
void transposeSparse(int mat[MAX][3], int result[MAX][3]) {
    int rows = mat[0][0], cols = mat[0][1], n = mat[0][2];
    result[0][0] = cols;
    result[0][1] = rows;
    result[0][2] = n;

    int k = 1;
    for(int j=0; j<cols; j++) {
        for(int i=1; i<=n; i++) {
            if(mat[i][1] == j) {
                result[k][0] = mat[i][1];
                result[k][1] = mat[i][0];
                result[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

// (b) Addition of two Sparse Matrices
void addSparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if(a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible, dimensions differ!\n";
        return;
    }

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    int n1 = a[0][2], n2 = b[0][2];
    int i=1, j=1, k=1;

    while(i<=n1 && j<=n2) {
        if(a[i][0] < b[j][0] || (a[i][0]==b[j][0] && a[i][1]<b[j][1])) {
            c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2];
            i++; k++;
        }
        else if(b[j][0] < a[i][0] || (b[j][0]==a[i][0] && b[j][1]<a[i][1])) {
            c[k][0]=b[j][0]; c[k][1]=b[j][1]; c[k][2]=b[j][2];
            j++; k++;
        }
        else { // same row & col
            int sum = a[i][2] + b[j][2];
            if(sum!=0) {
                c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=sum;
                k++;
            }
            i++; j++;
        }
    }
    while(i<=n1) {
        c[k][0]=a[i][0]; c[k][1]=a[i][1]; c[k][2]=a[i][2]; i++; k++;
    }
    while(j<=n2) {
        c[k][0]=b[j][0]; c[k][1]=b[j][1]; c[k][2]=b[j][2]; j++; k++;
    }
    c[0][2] = k-1;
}

// (c) Multiplication of two Sparse Matrices
void multiplySparse(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if(a[0][1] != b[0][0]) {
        cout << "Multiplication not possible, dimensions mismatch!\n";
        return;
    }

    int rows = a[0][0], cols = b[0][1];
    int n1 = a[0][2], n2 = b[0][2];

    // Transpose b for faster access
    int bt[MAX][3];
    transposeSparse(b, bt);

    c[0][0] = rows;
    c[0][1] = cols;
    int k=1;

    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            int sum=0;
            for(int p=1; p<=n1; p++) {
                if(a[p][0] == i) {
                    for(int q=1; q<=n2; q++) {
                        if(bt[q][0]==j && a[p][1]==bt[q][1]) {
                            sum += a[p][2] * bt[q][2];
                        }
                    }
                }
            }
            if(sum!=0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = sum;
                k++;
            }
        }
    }
    c[0][2] = k-1;
}

/* ---------------- MENU ---------------- */
int main() {
    int choice;
    int A[MAX][3], B[MAX][3], C[MAX][3];

    do {
        cout << "\n--- Sparse Matrix Menu ---\n";
        cout << "1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                readSparse(A);
                transposeSparse(A, C);
                cout << "Transpose:\n";
                displaySparse(C);
                break;
            }
            case 2: {
                cout << "Matrix A:\n"; readSparse(A);
                cout << "Matrix B:\n"; readSparse(B);
                addSparse(A,B,C);
                cout << "Result of Addition:\n";
                displaySparse(C);
                break;
            }
            case 3: {
                cout << "Matrix A:\n"; readSparse(A);
                cout << "Matrix B:\n"; readSparse(B);
                multiplySparse(A,B,C);
                cout << "Result of Multiplication:\n";
                displaySparse(C);
                break;
            }
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice!=4);

    return 0;
}
