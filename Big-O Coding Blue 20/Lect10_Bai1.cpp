#include <iostream>
#include <vector>

using namespace std;

#define MAX 1005
const int INF = 1e9;
struct Edge{
    int source;
    int target;
    int weight;
};
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
    while(c--){
        int s, u, v, w;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph.push_back((Edge){u,v,w});
        }
        s = 0;
        bool res = BellmanFord(s);
        if(res == false){
            cout << "possible" << endl;
        } else {
            cout << "not possible" << endl;
        }
        graph.clear();
    }
}