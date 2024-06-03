#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long long T, s;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> s;
        long long sq = ceil(sqrt(s));
        long long max = sq*sq - (sq-1);
        long long x, y;
        long long diff;
        if(sq%2 == 0){
            diff = s - max;
            if(diff < 0){
                y = sq;
                x = sq + diff;
            } else {
                x = sq;
                y = sq - diff;
            }
        } else {
            diff = s-max;
            if(diff < 0){
                x = sq;
                y = sq + diff;
            } else {
                y = sq;
                x = sq - diff;
            }
        }
        cout << "Case " << i << ": " << x << " " << y << endl;
    }
}