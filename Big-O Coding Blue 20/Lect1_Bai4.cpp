#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    string t;
    cin >> s;
    cin >> t;

    int n = s.size();
    string next_s = s;

    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'z'){
            s[i] = 'a';
        } else {
            s[i] = s[i] + 1;
            break;
        }
    }

    if(s == t){
        cout << "No such string";
    } else {
        cout << s;
    }

    return 0;
}

