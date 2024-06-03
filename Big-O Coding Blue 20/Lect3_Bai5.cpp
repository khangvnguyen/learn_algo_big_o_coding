#include <iostream>
using namespace std;

void merge(long long int L[], long long int nL, long long int R[], long long int nR, long long int result[]){
    long long int i, j, k;
    i = 0;
    j = 0;
    for(k = 0; i < nL && j < nR; k++){
        if(L[i] < R[j]){
            result[k] = L[i];
            i++;
        } else {
            result[k] = R[j];
            j++;
        }
    }
    while(i < nL){
        result[k] = L[i];
        i++;
        k++;
    }
    while(j < nR){
        result[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long long int array[], long long int n){
    if(n <= 1){
        return;
    }
    long long int nL = n/2;
    long long int nR = n-nL;
    long long int left[n/2+1];
    long long int right[n/2+1];
    long long int result[n];

    for(int i = 0; i < nL; i++){
        left[i] = array[i];
    }
    for(int i = nL; i < n; i++){
        right[i-nL] = array[i];
    }

    mergeSort(left, nL);
    mergeSort(right, nR);
    merge(left, nL, right, nR, array);
}

int main(){
    long long int n, x;
    cin >> n >> x;
    long long int A[n];
    
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    mergeSort(A, n);

    long long int sum = 0;
    for(int i = 0; i < n; i++){
        sum += A[i]*x;
        if(x > 1){
            x--;
        }
    }
    cout << sum;
}