#include <iostream>
using namespace std;

int main() {
    //(a) Concatenate one string to another string

    // char str1[100], str2[50];
    // cout << "Enter first string: ";
    // cin.getline(str1, 100);
    // cout << "Enter second string: ";
    // cin.getline(str2, 50);

    // int i = 0;
    // while (str1[i] != '\0'){
    //      i++;
    // } 

    // int j = 0;
    // while (str2[j] != '\0') {
    //     str1[i] = str2[j];
    //     i++;
    //     j++;
    // }
    // str1[i] = '\0'; 

    // cout << "Concatenated string: " << str1 << endl;

    //(b) Reverse a string

    // char str[100];
    // cout << "Enter a string: ";
    // cin.getline(str, 100);

    // int i = 0;
    // while (str[i] != '\0') {
    //     i++;
    // }
    // i--;

    // cout << "Reversed string is: " << endl;

    // while ( i != - 1 ){
    //     cout << str[i];
    //     i--;
    // }

    //(c) Delete all vowels from string

    // char str[100];
    // cout << "Enter a string: ";
    // cin.getline(str, 100);

    // int i = 0, j = 0;
    // while (str[i] != '\0') {
    //     if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
    //         str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
    //         i++;
    //     } 
    //     else {
    //         str[j] = str[i];
    //         i++;
    //         j++;
    //     }
    // }
    // str[j] = '\0'; 

    // cout << "String without vowels: " << str << endl;
    
    //(d) Sorting the string in alphabetical order

    // int n;
    // cout << "Enter the number of strings: ";
    // cin >> n;

    // char str[50][100];
    // cin.ignore();

    // cout << "Enter " << n << " strings:\n";
    // for (int i = 0; i < n; i++){
    //     cin.getline(str[i], 100);
    // }



    //(e) Converting a character from uppercase to lowercase

    char ch;
    cout << "Enter a character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        ch = ch + 32;
    }

    cout << "Lowercase character: " << ch << endl;
    return 0;
}