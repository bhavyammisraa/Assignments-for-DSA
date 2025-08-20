#include <iostream>
using namespace std;

/* (a) Diagonal Matrix */
class DiagonalMatrix {
    int n;
    int *arr;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if(i==j) arr[i-1] = val;
    }
    int get(int i, int j) {
        return (i==j) ? arr[i-1] : 0;
    }
    void display() {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~DiagonalMatrix() { delete[] arr; }
};

/* (b) Tri-diagonal Matrix */
class TriDiagonalMatrix {
    int n;
    int *arr; // size = 3n-2
public:
    TriDiagonalMatrix(int n) {
        this->n = n;
        arr = new int[3*n-2];
        for(int i=0; i<3*n-2; i++) arr[i] = 0;
    }
    void set(int i, int j, int val) {
        if(i-j==1) arr[i-2] = val;              // lower diag
        else if(i==j) arr[n+i-2] = val;        // main diag
        else if(j-i==1) arr[2*n+i-2] = val;    // upper diag
    }
    int get(int i, int j) {
        if(i-j==1) return arr[i-2];
        else if(i==j) return arr[n+i-2];
        else if(j-i==1) return arr[2*n+i-2];
        else return 0;
    }
    void display() {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~TriDiagonalMatrix() { delete[] arr; }
};

/* (c) Lower Triangular Matrix */
class LowerTriangularMatrix {
    int n;
    int *arr; // size = n(n+1)/2
public:
    LowerTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for(int i=0; i<n*(n+1)/2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        return (i*(i-1))/2 + (j-1);
    }
    void set(int i, int j, int val) {
        if(i>=j) arr[index(i,j)] = val;
    }
    int get(int i, int j) {
        return (i>=j) ? arr[index(i,j)] : 0;
    }
    void display() {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~LowerTriangularMatrix() { delete[] arr; }
};

/* (d) Upper Triangular Matrix */
class UpperTriangularMatrix {
    int n;
    int *arr; // size = n(n+1)/2
public:
    UpperTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for(int i=0; i<n*(n+1)/2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        return (i-1)*n - (i-2)*(i-1)/2 + (j-i);
    }
    void set(int i, int j, int val) {
        if(i<=j) arr[index(i,j)] = val;
    }
    int get(int i, int j) {
        return (i<=j) ? arr[index(i,j)] : 0;
    }
    void display() {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~UpperTriangularMatrix() { delete[] arr; }
};

/* (e) Symmetric Matrix */
class SymmetricMatrix {
    int n;
    int *arr; // size = n(n+1)/2
public:
    SymmetricMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for(int i=0; i<n*(n+1)/2; i++) arr[i] = 0;
    }
    int index(int i, int j) {
        if(i>=j) return (i*(i-1))/2 + (j-1);
        else     return (j*(j-1))/2 + (i-1);
    }
    void set(int i, int j, int val) {
        arr[index(i,j)] = val;
    }
    int get(int i, int j) {
        return arr[index(i,j)];
    }
    void display() {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
    ~SymmetricMatrix() { delete[] arr; }
};

/* Menu-driven program */
int main() {
    int choice, n;
    do {
        cout << "\n--- Special Matrix Storage Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice >= 1 && choice <= 5) {
            cout << "Enter size (n for n x n matrix): ";
            cin >> n;
        }

        switch(choice) {
            case 1: {
                DiagonalMatrix m(n);
                cout << "Enter diagonal elements:\n";
                for(int i=1;i<=n;i++) {
                    int val; cin >> val;
                    m.set(i,i,val);
                }
                m.display();
                break;
            }
            case 2: {
                TriDiagonalMatrix m(n);
                cout << "Enter matrix elements (row by row):\n";
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=n;j++) {
                        int val; cin >> val;
                        if(val!=0) m.set(i,j,val);
                    }
                }
                m.display();
                break;
            }
            case 3: {
                LowerTriangularMatrix m(n);
                cout << "Enter lower triangular elements:\n";
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=i;j++) {
                        int val; cin >> val;
                        m.set(i,j,val);
                    }
                }
                m.display();
                break;
            }
            case 4: {
                UpperTriangularMatrix m(n);
                cout << "Enter upper triangular elements:\n";
                for(int i=1;i<=n;i++) {
                    for(int j=i;j<=n;j++) {
                        int val; cin >> val;
                        m.set(i,j,val);
                    }
                }
                m.display();
                break;
            }
            case 5: {
                SymmetricMatrix m(n);
                cout << "Enter lower triangular elements (including diagonal):\n";
                for(int i=1;i<=n;i++) {
                    for(int j=1;j<=i;j++) {
                        int val; cin >> val;
                        m.set(i,j,val);
                    }
                }
                m.display();
                break;
            }
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 6);

    return 0;
}
