#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 105
const int INF = 1e9;
vector<int> dist(MAX, -INF);
vector<int> energy(MAX);
vector<pair<int, int> > graph;
bool visited[MAX];
int n, m;

bool hasPathBFS(int s, int f) {
    for(int i = 0; i <= n; i++){
        visited[i] = false;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 1; i <= graph.size(); i++) {
            if (graph[i].first == u) {
                int v = graph[i].second;

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);

                    if (v == f) {
                        return true;
                    }
                }
            }
        }        
    }
    return false;
}

bool BellmanFord(int s){
    int u, v;
    for(int i = 1; i <= n; i++){
        dist[i] = -INF;
    }
    dist[s] = 100;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < graph.size(); j++){
            u = graph[j].first;
            v = graph[j].second;
            if(dist[u] > 0 && (dist[u] + energy[v] > dist[v])){
                dist[v] = dist[u] + energy[v];
            }
        }
    }
    for(int i = 0; i < graph.size(); i++){
        u = graph[i].first;
        v = graph[i].second;
        if(dist[u] > 0 && hasPathBFS(u,n) && (dist[u] + energy[v] > dist[v])){
            return true;
        }
    }
    return dist[n] > 0;
}

int main(){
    cin >> n;
    while(n!=-1){
        graph.clear();
        int m, v;
        for(int u = 1; u <= n; u++){
            cin >> energy[u] >> m;
            if(m!=0){
                for(int j = 0; j < m; j++){
                    cin >> v;
                    graph.push_back(make_pair(u,v));
                }
            }
        }
        bool canGo = BellmanFord(1);
        cout << (canGo ? "winnable" : "hopeless") << endl;
        cin >> n;
    }
    return 0;
}