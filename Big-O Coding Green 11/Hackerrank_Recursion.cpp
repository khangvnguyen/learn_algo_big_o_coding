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

void printSpace(int n){
    if(n <= 0){
        return;
    }
    cout << "%";
    printSpace(n-1);
    printRow(n);
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    printSpace(n);
}