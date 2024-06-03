#include <iostream>

using namespace std;

bool isPalindrome(char str[], int start, int end){
    if(start >= end){
        return true;
    }
    if(str[start] != str[end]){
        return false;
    }
    start++;
    end--;
    return isPalindrome(str, start, end);
}

int main(){
    int n;
    cin >> n;
    char str[n+1];
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    if(isPalindrome(str, 0, n-1)){
        cout << "YES";
    } else {
        cout << "NO";
    }
}