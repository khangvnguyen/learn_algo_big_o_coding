#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define MAX 205
const int INF = 1e9;
struct Edge{
    int source;
    int target;
    int weight;
};
vector<int> busyness(MAX, 0);
vector<int> dist(MAX, INF);
vector<Edge> graph;
int n, m;

bool BellmanFord(int s){
    int u, v, w;
    dist[s] = 0;
    for(int i = 1; i <= n-1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if(dist[u] != INF && (dist[u] + w < dist[v])){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i = 0; i < m ; i++){
        u = graph[i].source;
        v = graph[i].target;
        w = graph[i].weight;
        if(dist[u] != INF && (dist[u] + w < dist[v])){
            return false;
        }
    }
    return true;
}

int main(){
    int c;
    cin >> c;
    for(int i = 1; i <= c; i++){
        cout << "Case " << i << ":" << endl; 
        int s, t, u, v, q;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> busyness[i];
        }
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            graph.push_back((Edge){u,v,pow(busyness[v]-busyness[u], 3)});
        }
        s = 1;
        bool res = BellmanFord(s);
        cin >> q;
        while(q--){
            cin >> t;
            if(dist[t] < 3 || dist[t] == INF){
                cout << "?" << endl;
            } else {
                cout << dist[t] << endl;
            }
        }
        for(int i = 0; i < MAX; i++){
            busyness[i] = 0;
            dist[i] = INF;
        }
        graph.clear();
    }
}