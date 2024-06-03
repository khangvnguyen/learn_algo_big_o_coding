#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    int minL = 1000000001;
    int maxR = 1;
    for(int i = 0; i < n; i++){
        cin >> L[i] >> R[i];
        minL = min(minL, L[i]);
        maxR = max(maxR, R[i]);
    }
    for(int i = 0; i < n; i++){
        if(L[i] == minL && R[i] == maxR){
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
}