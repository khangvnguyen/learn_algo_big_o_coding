#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i < n+1; i++){
        ans = ans + i;
    }
    cout << ans;
}