#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 1005
int V;
int E;
vector<int> graph[MAX];
bool visited[MAX];
int path[MAX];

void DFS(int src){
    for(int i = 0; i < V; i++){
        visited[i] = false;
        path[i] = -1;
    }
    stack<int> s;
    visited[src] = true;
    s.push(src);
    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                s.push(v);
                path[v] = u;
            }
        }
    }
}

int countDistance(int s, int f){
    int distance = 1;
    while(path[f] != s){
        distance++;
        f = path[f];
    }
    return distance;
}

int main(){
    int V;
    cin >> V;
    E = V-1;
    int u, v;
    for(int i = 1; i <= E; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s = 1;
    DFS(s);
    int n;
    cin >> n;
    int f;
    int girlfriend[V+1];
    int minDistance = V+1;
    int minGF = V;
    int dist;
    for(int i = 0; i < n; i++){
        cin >> f;
        girlfriend[i] = f;
        dist = countDistance(s,f);
        if(dist < minDistance){
            minDistance = dist;
            minGF = f;
        } else if (dist == minDistance && f < minGF){
            minGF = f;
        }
    }
    cout << minGF;
    return 0;
}