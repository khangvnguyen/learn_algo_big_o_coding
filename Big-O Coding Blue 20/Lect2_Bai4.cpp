#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> A(n);
    vector<int> B(m);

    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    for(int i = 0; i < m; i++){
        cin >> B[i];
    }

    int pointerA = 0;
    int pointerB = 0;
    int count = 0;

    vector<int> result;

    while(pointerA < n && pointerB < m){
        if(B[pointerB] >= A[pointerA] - x && B[pointerB] <= A[pointerA] + y){
            count++;
            result.push_back(pointerA+1);
            result.push_back(pointerB+1);
            pointerA++;
            pointerB++;
        } else if(B[pointerB] < A[pointerA]){
            pointerB++;
        } else {
            pointerA++;
        }
    }
    cout << count << endl;
    for(int i = 0; i < count; i++){
        cout << result[2*i] << " " << result[2*i+1] << endl;
    }
}