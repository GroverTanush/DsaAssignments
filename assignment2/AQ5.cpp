
#include <iostream>
using namespace std;

void duplicateTwos(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            i++; // skip over duplicated 2
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 2, 5};
    int n = 6;

    duplicateTwos(arr, n);

    cout << "Modified Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}