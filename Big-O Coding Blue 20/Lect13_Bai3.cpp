#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

float calculateDistance(int x, int y){
    return sqrt((float)x*x + (float)y*y);
}

int main(){
    int n, s;
    cin >> n >> s;
    int x, y, pop;
    float dist;
    int currPop = s;
    float currDist = -1;
    map<float, int> m;
    for(int i = 0; i < n; i++){
        cin >> x >> y >> pop;
        dist = calculateDistance(x, y);
        pair<float, int> p(dist, pop);
        if(m.find(dist) != m.end()){
            m[dist] += pop;
        } else {
            m.insert(p);
        }
    }
    map<float, int>::iterator it2;
    for(it2=m.begin(); it2 != m.end(); it2++){
        s += it2->second;
        if(s >= 1000000){
            break;
        }
    }
    if(it2 != m.end()){
        cout << setprecision(8) << it2->first;
    } else {
        cout << -1;
    }
    
}