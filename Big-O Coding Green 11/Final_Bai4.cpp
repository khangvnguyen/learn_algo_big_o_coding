#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    int result;
    cin >> a >> b >> c;
    if(a != 1 && b != 1 && c != 1){
        result = a*b*c;
    } else if (a == 1 && b == 1 && c == 1){
        result = a+b+c;
    } else if (a == 1 && b == 1 && c != 1){
        result = (a+b)*c;
    } else if (a == 1 && b != 1 && c == 1){
        result = a+b+c;
    } else if (a != 1 && b == 1 && c == 1){
        result = a*(b+c);
    } else if (a == 1 && b != 1 && c != 1){
        result = (a+b)*c;
    } else if (a != 1 && b == 1 && c != 1){
        if(a <= c){
            result = (a+b)*c;
        } else {
            result = a*(b+c);
        }
    } else if (a != 1 && b != 1 && c == 1){
        result = a*(b+c);
    }

    cout << result;
}