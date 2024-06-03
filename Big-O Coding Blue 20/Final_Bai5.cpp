#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
using namespace std;
#define MAX 105
const int INF = 1e9;
vector<pair<int, float> > graph[MAX];
vector<float> dist(MAX, INF);
int path[MAX];
bool visited[MAX];
int n, freNum;

struct Point{
    float x;
    float y;
};

vector<Point> freckles;

float calcDistance(Point a, Point b){
    return sqrt((a.y-b.y)*(a.y-b.y)+(a.x-b.x)*(a.x-b.x));
}

void printMST(){
    long long ans = 0;
    for(int i = 1; i <= freNum; i++){
        if(path[i] == -1){
            continue;
        }
        ans += dist[i];
    }
    cout << ans << endl;
}

struct option{
    bool operator() (const pair<int, float> &a, const pair<int, float> &b) const{
        return a.second > b.second;
    }
};

void prims(int src){
    priority_queue<pair<int, float>, vector<pair<int, float> >, option > pq;
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
    float x, y;
    cin >> n;
    float dist1;
    while(n--){
        cin >> freNum;
        for(int i = 0; i < freNum; i++){
            cin >> x >> y;
            Point p = new Point;
            p.x = x;
            p.y = y;
            freckles.push_back(p);
            for(int j = 0; j < i; j++){
                dist1 = calcDistance(freckles[i], freckles[j]);
                graph[j].push_back(make_pair(i, dist1));
                graph[i].push_back(make_pair(j, dist1));
                cout << i << " " << j << " " << dist1;
            }
        }
        prims(0);
    }
}