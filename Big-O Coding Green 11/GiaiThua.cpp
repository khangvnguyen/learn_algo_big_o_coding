#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if (i == 1 || i == n){
            for(int j = 1; j <= n; j++){
                cout << "*";
            }
        } else {
            cout << "*";
            for (int j = 2; j <= n-1; j++){
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
}