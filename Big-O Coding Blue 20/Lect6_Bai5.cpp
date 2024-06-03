#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 10001
vector<int> graph[MAX];
bool visited[MAX] = {false};


void DFS(int src, int &count){
    bool currentVisit[MAX] = {false};
    stack<int> s;
    s.push(src);
    count++;
    visited[src] = true;
    currentVisit[src] = true;

    while(!s.empty()){
        int u = s.top();
        s.pop();
        
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!currentVisit[v]){
                visited[v] = true;
                currentVisit[v] = true;
                s.push(v);
                count++;
            }
        }
    }
}

int main(){
    int n, m, a, b;
    int count = 0;
    int maxCount = 0;
    cin >> n >> m;
    for(int i = 0; i < m ; i++){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int bombNum = 1;
    while(bombNum <= n){
        if(visited[bombNum] == false){
            DFS(bombNum, count);
        }
        bombNum++;
        maxCount = max(count, maxCount);
        count = 0;
    }
    cout << maxCount;
}
