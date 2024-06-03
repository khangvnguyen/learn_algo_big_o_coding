#include <iostream>
#include <queue>

using namespace std;

int main(){
    long long n;
    cin >> n;
    long long A[n+1];
    for(long long i = 0 ; i < n; i++){
        cin >> A[i];
    }

    priority_queue<long long> pq;

    for(long long i = 0; i < n; i++){
        pq.push(A[i]);
        if(pq.size() < 3){
            cout << "-1" << endl;
        } else {
            long long temp1 = pq.top();
            pq.pop();
            long long temp2 = pq.top();
            pq.pop();
            cout << pq.top()*temp1*temp2 << endl;
            pq.push(temp2);
            pq.push(temp1);
        }
    }
}