#include <iostream>
#include <cmath>
using namespace std;

void mergeDesc(double L[], int nL, double R[], int nR, double result[], long long L2[], long long R2[], long long secondary[]){
    int i, j, k;
    i = 0;
    j = 0;
    for(k = 0; i < nL && j < nR; k++){
        if(L[i] > R[j]){
            result[k] = L[i];
            secondary[k] = L2[i];
            i++;
        } else if(L[i] == R[j]){
            if(L2[i] < R2[j]){
                result[k] = L[i];
                secondary[k] = L2[i];
                i++;
            } else {
                result[k] = R[j];
                secondary[k] = R2[j];
                j++;
            }
        } else {
            result[k] = R[j];
            secondary[k] = R2[j];
            j++;
        }
    }
    while(i < nL){
        result[k] = L[i];
        secondary[k] = L2[i];
        i++;
        k++;
    }
    while(j < nR){
        result[k] = R[j];
        secondary[k] = R2[j];
        j++;
        k++;
    }
}

void mergeSortDesc(double array[], int n, long long secondary[]){
    if(n <= 1){
        return;
    }
    int nL = n/2;
    int nR = n-nL;
    double left[n/2+1];
    double right[n/2+1];

    long long left2[n/2+1];
    long long right2[n/2+1];

    for(int i = 0; i < nL; i++){
        left[i] = array[i];
        left2[i] = secondary[i];
    }
    for(int i = nL; i < n; i++){
        right[i-nL] = array[i];
        right2[i-nL] = secondary[i];
    }

    mergeSortDesc(left, nL, left2);
    mergeSortDesc(right, nR, right2);
    mergeDesc(left, nL, right, nR, array, left2, right2, secondary);
}

int main(){
    int n, k;
    cin >> n >> k;
    double sinhvien[n+1][2];
    long long id[n+1];
    double grade[n+1];
    for(int i = 0; i < n; i++){
        cin >> sinhvien[i][0];
        id[i] = sinhvien[i][0];
        cin >> sinhvien[i][1];
        grade[i] = sinhvien[i][1];
    }
    mergeSortDesc(grade, n, id);
    for(int i = 0; i < k; i++){
        cout << id[i] << endl;
    }
}