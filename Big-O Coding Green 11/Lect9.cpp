#include <iostream>
using namespace std;

long long oddFactor(int n){
    if(n%2!=0){
        return n;
    } else {
        return oddFactor(n/2);
    }
}

int main(){
    int n;
    cin >> n;
    cout << oddFactor(n);
}