#include <iostream>
#include <cmath>
using namespace std;

void merge(int L[], int nL, int R[], int nR, int result[]){
    int i, j, k;
    i = 0;
    j = 0;
    for(k = 0; i < nL && j < nR; k++){
        if(L[i] > R[j]){
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

void mergeSort(int array[], int n){
    if(n <= 1){
        return;
    }
    int nL = n/2;
    int nR = n-nL;
    int left[n/2+1];
    int right[n/2+1];
    int result[n];

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
    int m, n, k;
    cin >> m >> n >> k;
    int A[m+1];
    int B[n+1];

    for(int i = 0; i < m; i++){
        cin >> A[i];
    }
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }

    int result[m+n+1];
    merge(A, m, B, n, result);

    cout << result[m+n-k-1];
}