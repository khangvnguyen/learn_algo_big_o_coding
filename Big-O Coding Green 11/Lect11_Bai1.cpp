#include <iostream>
using namespace std;

void insertAsc(int listnum[], int n, int x){ // Insert number x into sorted listnum with n numbers
    int j;
    for(j = n; j > 0; j--){
        if(j == 0){
            break;
        }
        if (listnum[j-1] <= x){
            break;
        } else {
            listnum[j] = listnum[j-1];
        }
    }
    listnum[j] = x;
}

void insertionSort(int listnum[], int n){
    int x;
    for(int i = 1; i <= n-1; i++){
        x = listnum[i];
        insertAsc(listnum, i, x);
    }
}

int main(){
    int n;
    cin >> n;
    int DaySo[n+1];
    for(int i = 0; i < n; i++){
        cin >> DaySo[i];
    }
    insertionSort(DaySo, n);
    for(int i = 0; i < n; i++){
        cout << DaySo[i] << " ";
    }
}