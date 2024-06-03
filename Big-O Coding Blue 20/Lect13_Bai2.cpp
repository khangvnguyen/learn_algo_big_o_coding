#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;
#define MAX 303

map<string, int> contestants;
vector<int> graph[MAX];
bool visited[MAX];
int dist[MAX];

void BFS(int id, int s){
    queue<int> q;
    for(int i = 1; i <= id; i++){
        visited[i] = false;
        dist[i] = 0;
    }
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u] + 1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
    string name1, name2, name3;
    int id = 1;
    for(int i = 0; i < n; i++){
        cin >> name1 >> name2 >> name3;
        if(contestants.find(name1) == contestants.end()){
            contestants[name1] = id;
            id++;
        }
        if(contestants.find(name2) == contestants.end()){
            contestants[name2] = id;
            id++;
        }
        if(contestants.find(name3) == contestants.end()){
            contestants[name3] = id;
            id++;
        }
        graph[contestants[name1]].push_back(contestants[name2]);
        graph[contestants[name1]].push_back(contestants[name3]);
        graph[contestants[name2]].push_back(contestants[name1]);
        graph[contestants[name2]].push_back(contestants[name3]);
        graph[contestants[name3]].push_back(contestants[name1]);
        graph[contestants[name3]].push_back(contestants[name2]);
    }
    BFS(id, contestants["Isenbaev"]);
    map<string, int>:: iterator it;
    for(it=contestants.begin(); it!= contestants.end(); it++){
        if(it->first == "Isenbaev"){
            cout << "Isenbaev 0" << endl;
        } else if(dist[it->second] == 0){  
            cout << it->first << " undefined" << endl;
        } else {
            cout << it->first << " " << dist[it->second] << endl;
        }
    }
}

/* map<string, int> contestants;
id = 1;
adj = [];

cin >> a >> b >> c;

if(!contestants[a]){
    contestants[a] = id;
    id++;
}
b___
c___

adj[contestants[a]].push_back(contestants[b]);
adj[contestants[a]].push_back(contestants[c]);
...

dist = BFS(contestants["Isenbaev"]);
for(i = 0; i < id; i++){
    if(contestants[i].value != 0){ // for the case when contestant value is 0
        cout << contestants[i] << " " << dist[contestants];
    }
}*/