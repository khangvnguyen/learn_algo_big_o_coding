#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAX 51
#define INF 1e9
vector<vector<int> > graph;
vector<vector<int> > dist;
vector<vector<int> > path;
string matrix[MAX];
int V;

bool FloydWarshall(vector<vector<int> > &graph, vector<vector<int> > &dist){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            dist[i][j] = graph[i][j];
            if(graph[i][j] != INF && i != j){
                path[i][j] = i;
            } else {
                path[i][j] = -1;
            }
        }
    }
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    for(int i = 0; i < V; i++){
        if(dist[i][i] < 0){
            return false;
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    string current;
    int n;
    while(T--){
        int count = 0;
        int ans = 0;
        int index = 0;
        cin >> current;
        matrix[0] = current;
        int m = current.size();
        for(int i = 1; i < m; i++){
            cin >> current;
            matrix[i] = current;
        }
        V = m;
        graph = vector<vector<int> >(V, vector<int> (V));
        dist = vector<vector<int> >(V, vector<int> (V));
        path = vector<vector<int> >(V, vector<int> (V));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(i == j){
                    graph[i][j] = 0;
                } else if(matrix[i][j] == 'Y'){
                    graph[i][j] = 1;
                } else {
                    graph[i][j] = INF;
                }
            }
        }
        FloydWarshall(graph, dist);
        for(int i = 0; i < m ; i++){
            count = 0;
            for(int j = 0; j < m; j++){
                if(dist[i][j] == 2){
                    count++;
                }
            }
            if(ans < count){
                ans = count;
                index = i;
            }
        }
        cout << index << " " << ans << endl;
    }
}