#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<int> distStart;
vector<int> distEnd;

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void DijkstraStart(int s){
    distStart = vector<int> (MAX+5, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, option > pq;
    pq.push(make_pair(s, 0));
    distStart[s] = 0;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;

        for(int i = 0; i < graph[u].size(); ++i){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < distStart[neighbor.first]){
                distStart[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, distStart[neighbor.first]));
            }
        }
    }
}

void DijkstraEnd(int s){
    distEnd = vector<int> (MAX+5, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, option > pq;
    pq.push(make_pair(s, 0));
    distEnd[s] = 0;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;

        for(int i = 0; i < graph[u].size(); ++i){
            pair<int, int> neighbor = graph[u][i];
            if (w + neighbor.second < distEnd[neighbor.first]){
                distEnd[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, distEnd[neighbor.first]));
            }
        }
    }
}

int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        distStart = vector<int> (MAX+5, INF);
        distEnd = vector<int> (MAX+5, INF);
        graph = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
        int n, r;
        cin >> n >> r;
        int u, v, s, d;
        for(int j = 0; j < r; j++){
            cin >> u >> v;
            graph[u].push_back(pair<int, int> (v,1));
            graph[v].push_back(pair<int, int> (u,1));
        }
        cin >> s >> d;
        DijkstraStart(s);
        DijkstraEnd(d);
        int result = 0;
        for(int j = 0; j < n; j++){
            result = max(result, distStart[j] + distEnd[j]);
        }
        cout << "Case " << i << ": " << result << endl;
    }
}