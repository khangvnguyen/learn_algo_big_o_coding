#include <iostream>
#include <string>
#include <vector>

using namespace std;
  
bool checkPangram (string &str) { 
    vector<bool> check(26, false); 
    for(int i=0; i<str.length(); i++){
        if ('A' <= str[i] && str[i] <= 'Z'){
            check[str[i]-'A'] = true;
        }
        else if('a' <= str[i] && str[i] <= 'z'){ 
            check[str[i]-'a'] = true;
        }
    } 
    for (int i=0; i<=25; i++){
        if(check[i] == false){
            return false;
        }
    }
    return (true);
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << (checkPangram(s) ? "YES" : "NO");
} 