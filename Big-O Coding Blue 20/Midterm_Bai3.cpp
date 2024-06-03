#include <iostream>
using namespace std;

int main(){
    int k, w;
    long long n;
    cin >> k >> n >> w;
    long long cost = 0;
    long long result = 0;
    for(int i = 1; i <= w; i++){
        cost = cost + (k*i);
    }
    if(cost <= n){
        result = 0;
    } else {
        result = cost - n;
    }
    cout << result;
    return 0;
}