#include <iostream>
#include <algorithm>

using namespace std;

int ladderRungs[100005];
int n, T;

bool checkClimb(int n, int k, int ladderRungs[]){
    for(int i = 1; i <= n; i++){
        if(ladderRungs[i] - ladderRungs[i-1] > k){
            return false;
        } else {
            if(ladderRungs[i] - ladderRungs[i-1] == k){
                k--;
            }
        }
    }
    return true;
}

int main(){
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> ladderRungs[j];
        }
        int small = 1;
        int large = ladderRungs[n]+1;
        int mid = (small+large)/2;
        int result;
        while(small <= large){
            mid = (small+large)/2;
            if(checkClimb(n, mid, ladderRungs) == true){
                result = mid;
                large = mid - 1;
            } else {
                small = mid + 1;
            }
        }
        cout << "Case " << i << ": " << result << endl;
    }
}