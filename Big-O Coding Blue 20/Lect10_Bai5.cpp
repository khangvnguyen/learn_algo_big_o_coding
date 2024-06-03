#include <iostream>
#include <vector>

using namespace std;

struct Edge{
    int source;
    int target;
    int weight;
};

#define MAX_N 1005
#define MAX_M 5005
const int INF = 1e9;
int dist[MAX_N];
Edge graph[MAX_M];
int n, m, q, s;
int u, v, w;
int node;

void BellmanFord(int s){
    for(int i = 0; i < MAX_N; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;

            if(dist[u] != INF && dist[u] + w < dist[v]){
                dist[v] = -INF;
            }
        }
    }
}

int main(){
    cin >> n >> m >> q >> s;
    while(n != 0){
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph[i] = (Edge){u,v,w};
        }
        BellmanFord(s);
        for(int i = 0; i < q; i++){
            cin >> node;
            if(dist[node] == INF){
                cout << "Impossible" << endl;
            } else if(dist[node] == -INF){
                cout << "-Infinity" << endl;
            } else {
                cout << dist[node] << endl;
            }
        }
        cout << endl;
        cin >> n >> m >> q >> s;
    }
}