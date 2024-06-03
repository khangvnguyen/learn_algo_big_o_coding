#include <iostream>
#include <queue>

using namespace std;

struct Job{
    int id;
    int priority;
};

priority_queue<int> pq;
queue<Job> q;

int main(){
    int testCase;
    cin >> testCase;
    int n, m, u;
    int time = 0;

    while(testCase--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> u;
            pq.push(u);
            q.push((Job){i,u});
        }
        while(true){
            if(q.front().priority == pq.top()){
                if(q.front().id == m){
                    q.pop();
                    pq.pop();
                    time++;
                    break;
                } else {
                    q.pop();
                    pq.pop();
                    time++;
                }
            } else {
                q.push(q.front());
                q.pop();
            }
        }
        cout << time << endl;
        while(!pq.empty()){
            pq.pop();
        }
        while(!q.empty()){
            q.pop();
        }
        time = 0;
    }
}