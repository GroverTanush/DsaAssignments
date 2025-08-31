#include <iostream>
using namespace std;

void sparse_transpose(int arr[][3], int transpose[][3]) {
    int rows = arr[0][0];
    int cols = arr[0][1];
    int nonZero = arr[0][2];

    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonZero;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= nonZero; j++) {
            if (arr[j][1] == i) {
                transpose[k][0] = arr[j][1];
                transpose[k][1] = arr[j][0];
                transpose[k][2] = arr[j][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols, nonZero;
    cout << "Enter the number of rows, columns and non zero values for the triplet array: ";
    cin >> rows >> cols >> nonZero;

    int arr[nonZero+1][3];
    int transpose[nonZero+1][3];

    arr[0][0] = rows;
    arr[0][1] = cols;
    arr[0][2] = nonZero;

    cout << "Enter the elements of the triplet array (row col value): ";
    for (int i = 1; i <= nonZero; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    sparse_transpose(arr, transpose);

    for (int i = 0; i <= nonZero; i++) {
        cout << transpose[i][0] << " "
             << transpose[i][1] << " "
             << transpose[i][2] << endl;
    }

    return 0;
}