#include <iostream>
#include <cmath>
using namespace std;

int gcf(int a, int b){
    if(a == b){
        return a;
    } else {
        if(a > b){
            return gcf(a-b, b);
        } else {
            return gcf(a, b-a);
        }
    }
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << gcf(a,b);
}