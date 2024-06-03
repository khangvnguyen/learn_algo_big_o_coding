#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 100005
vector<int> graph[MAX];
int n, m;
int a[MAX];
int catCount[MAX];
bool visited[MAX];

int BFS(int s){
    queue<int> q;
    q.push(s);
    visited[s] = true;
    if(a[s] == 1){
        catCount[s] = 1;
    }
    int resCount = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                if(a[v] == 1){
                    catCount[v] = catCount[u] + 1;
                }
                if(catCount[v] <= m){
                    if(graph[v].size() == 1){
                        resCount++;
                    } else {
                        q.push(v);
                    }
                }
            }
        }
    }
    return resCount;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int x, y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    cout << BFS(1);
}