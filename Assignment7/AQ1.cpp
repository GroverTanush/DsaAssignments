#include <iostream>
using namespace std;

void countingSort(int a[], int n){
    int max = a[0];
    for(int i=1;i<n;i++)
        if(a[i] > max) max = a[i];

    int count[10000];
    for(int i=0;i<=max;i++) count[i] = 0;

    for(int i=0;i<n;i++) count[a[i]]++;

    int k = 0;
    for(int i=0;i<=max;i++){
        while(count[i] > 0){
            a[k++] = i;
            count[i]--;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];

    countingSort(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
