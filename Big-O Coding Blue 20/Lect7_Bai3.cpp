#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    long long n = 1;
    long long total = 0;
    while(true){
        cin >> n;
        if(n == 0){
            break;
        }
        int num;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(long long i = 0; i < n; i++){
            cin >> num;
            pq.push(num);
        }
        while(pq.size()>1){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            total = total + a + b;
            pq.push(a+b);
        }
        cout << total << endl;
        total = 0;
    }
}