#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

#define MAX 501
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> dist(MAX, INF);
int path[MAX];

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void Dijkstra(int s){
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
    for(int i = 0; i < MAX; i++){
        dist[i] = INF;
        path[i] = -1;
    }
    int n;
    cin >> n;
    graph = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
    for(int i = 0; i < n; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back(pair<int, int>(b,w));
        graph[b].push_back(pair<int, int>(a,w));
    }
    int u, q, v;
    cin >> u >> q;
    Dijkstra(u);
    for(int j = 0; j < q; j++){
        cin >> v;
        if(dist[v] == INF){
            cout << "NO PATH" << endl;
        } else {
            cout << dist[v] << endl;
        }
    }
}