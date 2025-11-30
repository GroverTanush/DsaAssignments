#include <iostream>
using namespace std;

int getMax(int a[], int n){
    int m = a[0];
    for(int i=1;i<n;i++)
        if(a[i] > m) m = a[i];
    return m;
}

void countSort(int a[], int n, int exp){
    int output[1000];
    int count[10];
    for(int i=0;i<10;i++) count[i] = 0;

    for(int i=0;i<n;i++)
        count[(a[i]/exp)%10]++;

    for(int i=1;i<10;i++)
        count[i] += count[i-1];

    for(int i=n-1;i>=0;i--){
        int digit = (a[i]/exp)%10;
        output[count[digit]-1] = a[i];
        count[digit]--;
    }

    for(int i=0;i<n;i++)
        a[i] = output[i];
}

void radixSort(int a[], int n){
    int m = getMax(a,n);
    for(int exp=1; m/exp>0; exp*=10)
        countSort(a,n,exp);
}

int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++) cin>>a[i];

    radixSort(a,n);

    for(int i=0;i<n;i++) cout<<a[i]<<" ";
}
