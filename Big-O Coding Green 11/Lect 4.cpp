#include <iostream>
#include <cmath>
using namespace std;

int square(a){
    return a*a;
}

int main(){
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i < n; i++){
        sum += square(i);
    }
    cout << sum;
}