#include <iostream>
#include <cmath>
using namespace std;

struct Student{
    int id;
    double grade;
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
    int n, k;
    cin >> n >> k;
    int id[1001];
    int grade[1001];

    for(int i = 0; i < n; i++){
        cin >> id[i];
        cin >> grade[i];
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