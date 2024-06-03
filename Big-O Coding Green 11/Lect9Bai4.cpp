#include <iostream>
using namespace std;

int firstDigit(int n){
    if(n < 10 && n >= 0){
        return n;
    } else if (n > -10 && n < 0) {
        return n*(-1);
    } else {
        return firstDigit(n/10);
    }
}

int main(){
    int n;
    cin >> n;
    cout << firstDigit(n);
}