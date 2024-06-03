#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < int(sqrt((double)n) + 1); i++){
        if (n%i == 0) {
            return false;   
        }
    }
    return true;
}

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

void insertionSortAsc(int listnum[], int n){
    int x;
    for(int i = 1; i <= n-1; i++){
        x = listnum[i];
        insertAsc(listnum, i, x);
    }
}

void insertDesc(int listnum[], int n, int x){ // Insert number x into sorted listnum with n numbers
    int j;
    for(j = n; j > 0; j--){
        if(j == 0){
            break;
        }
        if (listnum[j-1] >= x){
            break;
        } else {
            listnum[j] = listnum[j-1];
        }
    }
    listnum[j] = x;
}

void insertionSortDesc(int listnum[], int n){
    int x;
    for(int i = 1; i <= n-1; i++){
        x = listnum[i];
        insertDesc(listnum, i, x);
    }
}

int main(){
    int n;
    cin >> n;
    int DaySo[n+1];

    int Even[n+1];
    int indexEven = 0;

    int Odd[n+1];
    int indexOdd;

    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        DaySo[i] = temp;
        if(temp%2==0){
            Even[indexEven] = temp;
            indexEven++;
        } else {
            Odd[indexOdd] = temp;
            indexOdd++;
        }
    }
    insertionSortAsc(Even, indexEven);
    insertionSortDesc(Odd, indexOdd);
    
    indexEven = 0;
    indexOdd = 0;

    for(int i = 0; i < n; i++){
        if(DaySo[i]%2==0){
            cout << Even[indexEven] << " ";
            indexEven++;
        } else {
            cout << Odd[indexOdd] << " ";
            indexOdd++;
        }
    }
}