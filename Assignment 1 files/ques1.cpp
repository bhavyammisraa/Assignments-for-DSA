// Develop a Menu driven program to demonstrate the following operations of Arrays
// ——MENU——- 
// 1. CREATE
// 2. DISPLAY
// 3. INSERT
// 4. DELETE
// 5. LINEAR SEARCH
// 6. EXIT
#include <bits/stdc++.h>
using namespace std;
int arr[100];
int n;
void create() {
 cout << "Enter number of elements: ";
 cin >> n;
 if (n > 100) {
 cout << "please try smaller number of elements \n";
 n = 0;
 return;
 }
 cout << "Enter " << n << " elements: ";
 for (int i = 0; i<n; i++) {
 cin >> arr[i];
 }
 cout << "Creted the array. \n";
}
void display() {
 if (n == 0) {
 cout << "Array is empty \n";
 return;
 }
 cout << "Array : ";
 for (int i = 0; i < n; i++) {
 cout << arr[i] << " ";
 }
 cout << "\n";
}
void insert() {
 if (n == 100) {
 cout << "Array is full. Cannot insert.\n";
 return;
 }
 int pos, val;
 cout << "Enter position of element (1-based index): ";
 cin >> pos;
 if (pos < 1 || pos > n + 1) {
 cout << "wrong position element cannot be inserted.\n";
 return;
 }
 cout << "Enter value: ";
 cin >> val;
 for (int i=n; i>=pos; i--) { // shift elements to the right
    arr[i] = arr[i-1];
 }
 arr[pos - 1] = val;
 n++;
}
void deleteEle() {
 if (n == 0) {
 cout << "Array is empty \n";
 return;
 }
 int pos;
 cout << "Enter position to delete (1-based index): ";
 cin >> pos;
 if (pos < 1 || pos > n){
    cout << "Invalid position.\n";
 return;
 }
 int r = arr[pos-1];
 for (int i=pos-1; i<n-1; i++) { // shift elements to the left
 arr[i] = arr[i + 1];
 }
 n--;
 cout << "Element " << r << " deleted successfully.\n";
}
void linearSearch() {
 if (n == 0) {
 cout << "Array not found \n";
 return;
 }
 int val;
 cout << "Enter search element ";
 cin >> val;
 for (int i = 0; i < n; i++) {
 if (arr[i] == val) {
 cout << "Element found at position " << i + 1 << "\n";
 return;
 }
 }
 cout << "Element not found.\n";
}
int main() {
 int ch;
 while (true) {
 cout << " MENU \n";
 cout << "1. CREATE\n";
 cout << "2. DISPLAY\n";
 cout << "3. INSERT\n";
 cout << "4. DELETE\n";
 cout << "5. LINEAR SEARCH\n";
 cout << "6. EXIT\n";
 cout << "Enter your choice: ";
 cin >> ch;
 switch (ch) {
 case 1: create(); break;
 case 2: display(); break;
 case 3: insert(); break;
 case 4: deleteEle(); break;
 case 5: linearSearch(); break;
 case 6: cout << "Exiting program.\n"; return 0;
 default: cout << "Invalid choice \n";
 }
 }
}