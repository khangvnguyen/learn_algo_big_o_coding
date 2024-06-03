#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1005

int V, E;
bool visited[MAX];
int dist[MAX];
vector<int> graph[MAX];

void BFS(int s){
    queue<int> q;
    for(int i = 1; i <= V; i++){
        visited[i] = false;
        dist[i] = 0;
    }
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }
}

int main(){
    int q;
    cin >> q;
    int u, v;
    
    for(int i = 0 ; i < q ; i++){
        cin >> V >> E;

        for(int j = 0; j < E; j++){
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int s;
        cin >> s;
        BFS(s);

        for(int k = 1; k <= V; k++){
            if(k == s){
                continue;
            }
            if(visited[k]){
                cout << dist[k] * 6 << " ";
            } else {
                cout << -1 << " ";
            }
        }
        cout << endl;
        for(int i = 1; i <= V; i++){
            graph[i].clear();
        }
    }
}