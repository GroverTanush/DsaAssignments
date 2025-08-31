#include <iostream>
using namespace std;

int main(){
    int n;
    int temp = 0;
    
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        int temp = 1;
        for(int j = 0; j < i; j++){
            if(arr[j] == arr[i]){
                temp = 0;
                break;
            }
        }
        if (temp == 1){
            count++;
        }
    }
    
    cout << "Number of distinct elements in the array is: " << count;

    return 0;
}