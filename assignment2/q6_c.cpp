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

void multiply_Sparse(int A[][3], int B_T[][3], int C[][3]) {
    if (A[0][1] != B_T[0][1]) {  
        cout << "Multiplication not possible" << endl;
        C[0][2] = 0;
        return;
    }

    int temp[200][3];
    int k = 1;

    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B_T[0][2]; j++) {
            if (A[i][1] == B_T[j][1]) {  
                temp[k][0] = A[i][0];     // row from A
                temp[k][1] = B_T[j][0];   // col from B (row of B_T)
                temp[k][2] = A[i][2] * B_T[j][2];
                k++;
            }
        }
    }

    int l = 1;
    for (int i = 1; i < k; i++) {
        if (temp[i][2] == 0) continue;
        int r = temp[i][0], c = temp[i][1], sum = temp[i][2];
        for (int j = i + 1; j < k; j++) {
            if (temp[j][0] == r && temp[j][1] == c) {
                sum += temp[j][2];
                temp[j][2] = 0;
            }
        }
        if (sum != 0) {
            C[l][0] = r;
            C[l][1] = c;
            C[l][2] = sum;
            l++;
        }
    }

    C[0][0] = A[0][0];
    C[0][1] = B_T[0][0];  
    C[0][2] = l - 1;
}

int main() {
    int rows1, cols1, nonZero1;
    cout << "Enter rows, cols and nonZero for first matrix: ";
    cin >> rows1 >> cols1 >> nonZero1;

    int A[100][3];
    A[0][0] = rows1;
    A[0][1] = cols1;
    A[0][2] = nonZero1;

    cout << "Enter elements (row col value): ";
    for (int i = 1; i <= nonZero1; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    int rows2, cols2, nonZero2;
    cout << "Enter rows, cols and nonZero for second matrix: ";
    cin >> rows2 >> cols2 >> nonZero2;

    int B[100][3], B_T[100][3];
    B[0][0] = rows2;
    B[0][1] = cols2;
    B[0][2] = nonZero2;

    cout << "Enter elements (row col value): ";
    for (int i = 1; i <= nonZero2; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    sparse_transpose(B, B_T);  

    int C[200][3];
    
    multiply_Sparse(A, B_T, C);

    cout << "Resultant triplet matrix:\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " "
             << C[i][1] << " "
             << C[i][2] << endl;
    }

    return 0;
}