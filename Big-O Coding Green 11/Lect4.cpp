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

int main(){
    int a;
    cin >> a;
    int solonhon = a;
    int sobehon = a;

    if(isPrime(a)){
        cout << a;
        return 0;
    } else {
        while(isPrime(solonhon) == false){
            solonhon += 1;
        }
        while(isPrime(sobehon) == false){
            sobehon -= 1;
        }
    }

    if ((a - sobehon) <= (solonhon - a)){
        cout << sobehon;
    } else {
        cout << solonhon;
    }
    return 0;
}

int power(int a, int b){
    int c = a;
    if(b==0){
        return 1;
    } else if (b==1){
        return a;
    } else {
        for(int i = 2; i <= b; i++){
            c = c*a;
        }
    }
    return c;
}