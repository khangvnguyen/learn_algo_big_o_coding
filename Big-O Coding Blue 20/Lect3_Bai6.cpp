#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A, A+n);
    int count = n;
    int currentHeight = 1;
    int maxHeight = 1;
    for(int i = 0; i < n-1; i++){
        if(A[i+1] == A[i]){
            currentHeight++;
            maxHeight = max(currentHeight, maxHeight);
            count--;
        } else {
            currentHeight = 1;
        }
    }
    cout << maxHeight << " " << count;
}