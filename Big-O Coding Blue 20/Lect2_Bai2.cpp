#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    vector<int> B(m);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    for(int i = 0; i < m; i++){
        cin >> B[i];
    }

    int LA = 0;
    int LB = 0;
    int count = 0;
    while(LA < n && LB < m){
        if(B[LB] >= A[LA]){
            LB++;
            LA++;
        } else {
            LB++;
        }
    }
    cout << n - LA;
    return 0;
}