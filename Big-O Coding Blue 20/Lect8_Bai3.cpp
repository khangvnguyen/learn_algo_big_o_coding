#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define MAX 10000
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
    int s;
    cin >> s;
    while(s--){
        
        dist = vector<int> (MAX,INF);
        graph = vector<vector<pair<int, int> > > (MAX+5, vector<pair<int, int> >());
        
        int n;
        cin >> n;
        string name[MAX];
        int p, nr, cost;

        for(int i = 1; i <= n; i++){
            
            cin >> name[i] >> p;
            for(int j = 0; j < p; j++){
                cin >> nr >> cost;
                graph[i].push_back(pair<int, int> (nr, cost));
            }
        }
        
        int r;
        cin >> r;
        string pathStart, pathEnd;
        int pathStartNum, pathEndNum = 0;
        for(int i = 0; i < r; i++){
            cin >> pathStart >> pathEnd;
            for(int j = 1; j <= n; j++){
                if(name[j] == pathStart){
                    pathStartNum = j;
                } else if(name[j] == pathEnd){
                    pathEndNum = j;
                }
                if(pathStartNum != 0 && pathEndNum != 0){
                    break;
                }
            }
            Dijkstra(pathStartNum);
            cout << dist[pathEndNum] << endl;
            pathStartNum = 0;
            pathEndNum = 0;

        }
    }
}