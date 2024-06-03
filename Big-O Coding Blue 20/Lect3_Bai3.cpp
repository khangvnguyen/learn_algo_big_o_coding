#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool option(int a, int b){
    return a > b;
}

int main(){
    int n;
    cin >> n;
    int A[n];
    int B[n];
    int C[2001]={0}; // array containing rank of score that's equal to index
    for(int i = 0; i < n; i++){
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B, B+n, option);
    
    int currentScore = B[0];
    C[currentScore] = 1;
    int pastRank = 1;
    int count = 1;

    for(int i = 1; i < n; i++){
        if(B[i] == currentScore){
            count++;
        } else {
            currentScore = B[i];
            C[currentScore] = pastRank+count;
            pastRank = C[currentScore];
            count = 1;
        }
    }

    for(int i = 0; i < n; i++){
        cout << C[A[i]] << " ";
    }
}