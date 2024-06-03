#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 100001
int V;
int E;
vector<int> graph[MAX];
bool visited[MAX] = {false};

void DFS(int src){
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
            }
        }
    }
}

int main(){
    int T;
    int a, b;
    cin >> T;
    int result = 0;
    for(int i = 0; i < T; i++){
        cin >> V >> E;
        for(int j = 0; j < E; j++){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        DFS(0);
        result++;
        for(int j = 1; j < V; j++){
            if(visited[j] == false){
                DFS(j);
                result++;
            }
        }
        cout << result << endl;
        result = 0;
        for(int k = 0; k < V; k++){
            graph[k].clear();
            visited[k] = false;
        }
    }
}
