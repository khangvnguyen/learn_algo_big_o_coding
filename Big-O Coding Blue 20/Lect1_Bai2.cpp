#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int rotationCount(char a, char b){
    int result = 0;
    if(a - b <= 13 && a - b >= -13){
        result += abs(a-b);
    } else {
        result += 26 - abs(a-b);
    }
    return result;
}

int main(){
    string s;
    cin >> s;
    int result = 0;
    result += rotationCount(s[0], 'a');
    for(int i = 0; i < s.size()-1; i++){
        result += rotationCount(s[i], s[i+1]);
    }
    cout << result;
    return 0;
}