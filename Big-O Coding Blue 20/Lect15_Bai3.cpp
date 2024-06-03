#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX 300005

const int INF = 1e9;

int t, p, n, m;
vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
bool visited[MAX];
int path[MAX];

void printMST(){
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        if(path[i] == -1){
            continue;
        }
        ans += dist[i];
    }
    cout << ans*p << endl;
}

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

void prims(int src){
    priority_queue<pair<int, int>, vector<pair<int, int> >, option> pq;
    pq.push(make_pair(src,0));
    dist[src] = 0;
    while(!pq.empty()){
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if(!visited[v] && dist[v] > w){
                dist[v] = w;
                pq.push(make_pair(v,w));
                path[v] = u;
            }
        }
    }
}

int main(){
    cin >> t;
    int u, v, w;
    while(t--){
        cin >> p >> n >> m;
        for(int i = 1; i <= n; i++){
            graph[i].clear();
        }
        memset(path, -1, sizeof(path));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < MAX; i++){
            dist[i] = INF;
        }
        for(int i = 0; i < m; i++){
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(v,w));
            graph[v].push_back(make_pair(u,w));
        }
        int s = 1;
        prims(s);
        printMST();
    }
}