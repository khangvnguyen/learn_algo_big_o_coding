#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// Complete the staircase function below.
char[] staircase(int n) {
    if(n <= 0){
        return ' ';
    } else {
        return '#' + staircase(n-1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);

    return 0;
}

