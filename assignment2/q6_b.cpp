#include <iostream>
using namespace std;

void add_Sparse(int A[][3], int B[][3], int C[][3]) {
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Addition not possible" << endl;
        C[0][2] = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= A[0][2] && j <= B[0][2]) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else {
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while (i <= A[0][2]) {
        C[k][0] = A[i][0];
        C[k][1] = A[i][1];
        C[k][2] = A[i][2];
        i++; k++;
    }

    while (j <= B[0][2]) {
        C[k][0] = B[j][0];
        C[k][1] = B[j][1];
        C[k][2] = B[j][2];
        j++; k++;
    }

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];
    C[0][2] = k - 1;
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

    int B[100][3];
    B[0][0] = rows2;
    B[0][1] = cols2;
    B[0][2] = nonZero2;

    cout << "Enter elements (row col value): ";
    for (int i = 1; i <= nonZero2; i++) {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    int C[200][3];
    add_Sparse(A, B, C);

    cout << "Resultant triplet matrix:\n";
    for (int i = 0; i <= C[0][2]; i++) {
        cout << C[i][0] << " "
             << C[i][1] << " "
             << C[i][2] << endl;
    }

    return 0;
}