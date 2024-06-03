#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100000 + 5
int n;
int dist[MAX];
int keys[MAX];

int BFS(int s, int f){
    for(int i = 0; i < MAX; i++){
        dist[i] = -1;
    }
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < n; i++){
            int v = (1LL*u*keys[i])%100000;

            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);

                if(v == f){
                    return dist[v];
                }
            }
        }
    }
    return -1;
}

int main(){
    int sam, lock;
    cin >> sam >> lock;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> keys[i];
    }
    cout << BFS(sam, lock);
}