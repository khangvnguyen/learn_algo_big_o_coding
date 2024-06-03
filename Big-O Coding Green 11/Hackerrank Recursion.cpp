#include <iostream>
#include <string>
using namespace std;

void printRow(int n){
    if(n <= 0){
        return;
    }
    cout << "#";
    printRow(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << printRow(n);
}