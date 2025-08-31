#include <iostream>
using namespace std;

int main(){
    
    int n;
    cout << "Enter the size of the matrix: ";
    cin >> n;

    int arr[n*(n+1) / 2];

    cout << "Enter the elements of the lower triangular matrix in row major order: ";
    for(int i = 0; i < n*(n+1) / 2; i ++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                cout << arr[(i*(i+1) / 2) + i] << " ";
            }
            else if(i > j){
                cout << arr[(i*(i+1) / 2) + j] << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}