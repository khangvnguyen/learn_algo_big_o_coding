#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    long long n, w;
    cin >> n >> w;
    vector<long long> A(2*n);
    for(int i = 0; i < 2*n; i++){
        cin >> A[i];
    }

    sort(A.begin(), A.end(), greater<long long>());

    long long maxGirl = A[2*n-1]*n;
    long long maxBoy = A[n-1]*n;

    float result;

    if(maxBoy >= 2*maxGirl){
        cout << w;
    } else {
        result = (float)maxBoy*1.5;
        if(result > w){
            cout << w;
        } else {
            cout << result;
        }
    }
}