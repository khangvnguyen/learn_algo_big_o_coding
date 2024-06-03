#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100
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
    int count;
    int n, e, t, m;
    cin >> n >> e >> t >> m;
    int a, b, w;
    graph = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
    for(int i = 0; i < m; i++){
        cin >> a >> b >> w;
        graph[a].push_back(pair<int, int> (b,w));
    }
    for(int i = 1; i <= n; i++){
        Dijkstra(i);
        if(dist[e] <= t){
            count++;
        }
    }
    cout << count;
}