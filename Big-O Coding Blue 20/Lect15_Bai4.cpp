#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <map>
using namespace std;

#define MAX 10005

const int INF = 1e9;

vector<pair<int, int> > graph[MAX];
vector<int> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int N, M;

void printMST(int cityNum){
    long long ans = 0;
    for(int i = 0; i < cityNum; i++){
        if(visited[i] == false){
            cout << "Impossible" << endl;
            return;
        }
        if(path[i] == -1){
            continue;
        }
        ans += dist[i];
    }
    cout << ans << endl;
}

struct option{
    bool operator() (const pair<int, int> &a, const pair<int, int> &b) const{
        return a.second > b.second;
    }
};

void prims(int src){
    priority_queue<pair<int, int>, vector<pair<int, int> >, option > pq;
    pq.push(make_pair(src, 0));
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
                pq.push(make_pair(v, w));
                path[v] = u;
            }
        }
    }
}

int main(){
    string city1, city2;
    int u, v, w;
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        map<string,int> cities;
        int cityNum = 0;
        cin >> M;
        memset(path, -1, sizeof(path));
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < MAX; i++){
            dist[i] = INF;
        }
        for(int i = 0; i < M; i++){
            cin >> city1 >> city2 >> w;
            if(cities.find(city1) == cities.end()){
                cities.insert(make_pair(city1, cityNum));
                cityNum++;
            }
            if(cities.find(city2) == cities.end()){
                cities.insert(make_pair(city2, cityNum));
                cityNum++;
            }
            u = cities[city1];
            v = cities[city2];
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, w));
        }
        int s = 1;
        prims(1);
        cout << "Case " << i << ": ";
        printMST(cityNum);
        for(int i = 0; i < cityNum; ++i){
            graph[i].clear();
        }
        cities.clear();
    }
}