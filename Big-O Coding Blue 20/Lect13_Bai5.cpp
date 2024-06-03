#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    string name;
    cin.ignore();
    int max = 0;
    string nameMax;
    map<string, int> m;
    pair<string, int> p;
    for(int i = 0; i < n; i++){
        getline(cin, name);
        if(m.find(name) == m.end()){
            p = make_pair(name, 1);
            m.insert(p);
        } else {
            m[name] += 1;
        }
    }
    for(map<string,int>::iterator it = m.begin(); it != m.end(); it++){
        if(it->second > max){
            max = it->second;
            nameMax = it->first;
        }
    }
    cout << nameMax;
}