#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int T, x, n, value;
    cin >> T;
    while(T--){
        set<int> s;
        set<int>::iterator it;
        cin >> n >> x;
        for(int i = 0; i < n; i++){
            cin >> value;
            it = s.find(value);
            if(it != s.end()){
                continue;
            } else {
                s.insert(value);
            }
        }
        if(s.size() > x){
            cout << "Average" << endl;
        } else if(s.size() == x){
            cout << "Good" << endl;
        } else {
            cout << "Bad" << endl;
        }
    }
    

}