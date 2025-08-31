#include <iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of the array:";
    cin >> n;

    int arr[(3*n)-2];

    cout << "Enter the non zero elements of the array (diagonally)(main,lower,upper) :";
    for(int i = 0; i < (3*n)-2; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j){
                cout << arr[i] << " ";
            }
            else if(i == j + 1){
                cout << arr[n + (i-1)] << " ";
            }
            else if(i == j - 1){
                cout << arr[(2*n - 1) + i] << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}