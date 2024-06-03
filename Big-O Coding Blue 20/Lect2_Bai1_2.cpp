#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A(n);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    
    int L = 0;
    int R = 0;
    vector<int> cnt(100001);
    int count = 0;

    while(R <= n){
        cnt[A[R]]++;
        if(cnt[A[R]] == 1){
            count++;
        }
        if(count == k){
            while(L <= R){
                cnt[A[L]]--;
                if(cnt[A[L]] == 0){
                    cout << L+1 << " " << R+1;
                    return 0;
                }
                L++;
            }
        }
        R++;
    }
    cout << -1 << " " << -1;
    return 0;
}