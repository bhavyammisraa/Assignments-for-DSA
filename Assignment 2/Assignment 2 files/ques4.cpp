// String Related Programs 
// (a) Write a program to concatenate one string to another string. 
// (b) Write a program to reverse a string. 
// (c) Write a program to delete all the vowels from the string. 
// (d) Write a program to sort the strings in alphabetical order. 
// (e) Write a program to convert a character from uppercase to lowercase.
#include <bits/stdc++.h>
using namespace std;

// (a) Concatenate one string to another
void concatenateStrings() {
    string str1, str2;
    cin.ignore();
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    cout << "Concatenated String: " << str1 + str2 << endl;
}

// (b) Reverse a string
void reverseString() {
    string str;
    cin.ignore();
    cout << "Enter a string: ";
    getline(cin, str);
    reverse(str.begin(), str.end());
    cout << "Reversed String: " << str << endl;
}

// Helper for (c)
bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
}

// (c) Delete all vowels from a string
void deleteVowels() {
    string str, result="";
    cin.ignore();
    cout << "Enter a string: ";
    getline(cin, str);
    for(char c : str) {
        if(!isVowel(c)) result += c;
    }
    cout << "String without vowels: " << result << endl;
}

// (d) Sort strings in alphabetical order
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();
    vector<string> arr(n);
    cout << "Enter " << n << " strings:\n";
    for(int i=0; i<n; i++) getline(cin, arr[i]);
    sort(arr.begin(), arr.end());
    cout << "Strings in alphabetical order:\n";
    for(string s : arr) cout << s << endl;
}

// (e) Convert uppercase to lowercase
void toLowercase() {
    char c;
    cout << "Enter an uppercase character: ";
    cin >> c;
    cout << "Lowercase: " << char(tolower(c)) << endl;
}

// Menu
int main() {
    int choice;
    do {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate two strings\n";
        cout << "2. Reverse a string\n";
        cout << "3. Delete vowels from a string\n";
        cout << "4. Sort strings alphabetically\n";
        cout << "5. Convert uppercase to lowercase\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: concatenateStrings(); break;
            case 2: reverseString(); break;
            case 3: deleteVowels(); break;
            case 4: sortStrings(); break;
            case 5: toLowercase(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while(choice != 6);

    return 0;
}
