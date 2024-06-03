    #include <iostream>
    #include <vector>
    #include <queue>

    using namespace std;

    int main(){
        long long n, k, v;
        cin >> n;
        priority_queue<long long> maxPQ;
        priority_queue<long long, vector<long long>, greater<long long> > minPQ;
        long long total;
        for(long long i = 0; i < n; i++){
            cin >> k;
            for(long long j = 0; j < k; j++){
                cin >> v;
                maxPQ.push(v);
                minPQ.push(v);
            }
            total = total + maxPQ.top() - minPQ.top();
            maxPQ.pop();
            minPQ.pop();
        }
        cout << total;
    }