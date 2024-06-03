#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 50000
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist;
int path[MAX];

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void Dijkstra(int s){
    dist = vector<int> (MAX, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, option > pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;

        for(int i = 0; i < graph[u].size(); ++i){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < dist[neighbor.first]){
                dist[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, dist[neighbor.first]));
                path[neighbor.first] = u;
            }
        }
    }
}

int main(){
    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i++){
        graph = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
        dist = vector<int> (MAX, INF);
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        int u, v, w;
        for(int j = 0; j < m; j++){
            cin >> u >> v >> w;
            graph[u].push_back(pair<int, int>(v,w));
            graph[v].push_back(pair<int, int>(u,w));
        }
        Dijkstra(s);
        if(dist[t] == INF){
            cout << "Case #" << i << ": " << "unreachable" << endl;
        } else {
            cout << "Case #" << i << ": " << dist[t] << endl;
        }
    }
}