#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int T, n, m;
    long long value;
    cin >> T;
    while(T--){
        set<long long> s;
        set<long long>::iterator it;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> value;
            it = s.find(value);
            if(it != s.end()){
                continue;
            } else {
                s.insert(value);
            }
        }
        for(int i = 0; i < m; i++){
            cin >> value;
            it = s.find(value);
            if(it != s.end()){
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
                s.insert(value);
            }
        }
    }
}