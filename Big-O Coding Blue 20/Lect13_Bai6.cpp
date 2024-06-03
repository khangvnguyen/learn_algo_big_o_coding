#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main(){
    int n;
    long long p;
    set<long long> s;
    set<long long>::iterator it;
    long long minDiff = 1e16;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p;
        s.insert(p);
        it = s.upper_bound(p);
        if(it != s.end()){
            minDiff = min(minDiff, abs(p-*it));
        }
    }
    cout << minDiff;
}