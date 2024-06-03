#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int L = 0;
    int R = n-1;
    int result[2];
    result[0] = 0;
    result[1] = 0;
    int i = 0;
    while(R >= L){
        if(A[R]>A[L]){
            result[i%2] += A[R];
            R--;
            i++;
        } else {
            result[i%2] += A[L];
            L++;
            i++;
        }
    }
    cout << result[0] << " " << result[1];
}