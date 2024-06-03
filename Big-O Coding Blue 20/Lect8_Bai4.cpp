#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 100005
const int INF = 1e9;
vector<vector<pair<int, int> > > graph;
vector<vector<pair<int, int> > > graphReverse;
vector<int> distStart;
vector<int> distEnd;

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const
    {
        return a.second > b.second;
    }
};

void DijkstraStart(int s){
    distStart = vector<int> (MAX, INF);
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
    distEnd = vector<int> (MAX, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, option > pq;
    pq.push(make_pair(s, 0));
    distEnd[s] = 0;
    while(!pq.empty()){
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.first;
        int w = top.second;

        for(int i = 0; i < graphReverse[u].size(); ++i){
            pair<int, int> neighbor = graphReverse[u][i];
            if (w + neighbor.second < distEnd[neighbor.first]){
                distEnd[neighbor.first] = w + neighbor.second;
                pq.push(pair<int, int>(neighbor.first, distEnd[neighbor.first]));
            }
        }
    }
}

int main(){
    int dataSet;
    cin >> dataSet;
    while(dataSet--){
        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;
        int result = INF;
        graph = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
        graphReverse = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
        distStart = vector<int> (MAX, INF);
        distEnd = vector<int>(MAX, INF);
        int d, c, l;
        int u, v, q;
        for(int i = 0; i < m; i++){
            cin >> d >> c >> l;
            graph[d].push_back(pair<int, int>(c,l));
            graphReverse[c].push_back(pair<int, int>(d,l));
        }
        DijkstraStart(s);
        DijkstraEnd(t);
        int bestDistance = distStart[t];
        for(int i = 0; i < k; i++){
            cin >> u >> v >> q;
            int distStoU = distStart[u];
            int distTtoV = distEnd[v];
            int newDistance1 = distStoU + q + distTtoV;

            int distStoV = distStart[v];
            int distTtoU = distEnd[u];
            int newDistance2 = distStoV + q + distTtoU;
            
            bestDistance = min(bestDistance, newDistance1);
            bestDistance = min(bestDistance, newDistance2);
        }
        if(bestDistance == INF){
            cout << -1 << endl;
        } else {
            cout << bestDistance << endl;
        }
    }
}