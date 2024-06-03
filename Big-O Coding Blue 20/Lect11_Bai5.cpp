#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 85
const int INF = 1e9;

vector<vector<int> > graph;
vector<vector<int> > dist;
int cityFeast[MAX];
int c,r,q;
int c1, c2, d;


void FloydWarshall(vector<vector<int> > &graph, vector<vector<int> > &dist){
    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            dist[i][j] = graph[i][j] + max(cityFeast[i], cityFeast[j]);
        }
    }
    // Run the following twice
    for(int k = 0; k < c; k++){
        for(int i = 0; i < c; i++){
            for(int j = 0; j < c; j++){
                /*  if dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + max(maxCost[i][k], maxCost[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    maxCost[i][j] = max(maxCost[i][k], maxCost[k][j]);
                }*/
                if(dist[i][j] > dist[i][k] + dist[k][j] + max(cityFeast[i], cityFeast[j], cityFeast[k])){
                    dist[i][j] = dist[i][k] - max(cityFeast[i], cityFeast[k]) + dist[k][j] - max(cityFeast[k], cityFeast[j]) + max(cityFeast[i], cityFeast[j], cityFeast[k]);
                }
            }
        }
    }
}

int main(){
    cin >> c >> r >> q;
    while(c != 0){
        graph = vector<vector<int> >(c, vector<int>(c));
        dist = vector<vector<int> >(c, vector<int>(c));
        for(int i = 0; i < c; i++){
            cin >> cityFeast[i];
        }
        for(int i = 0; i < c; i++){
            for(int j = 0; j < c; j++){
                if(i != j){
                    graph[i][j] = INF;
                } else {
                    graph[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < r; i++){
            cin >> c1 >> c2 >> d;
            graph[c1-1][c2-1] = d;
            graph[c2-1][c1-1] = d;
        }
        FloydWarshall(graph, dist);
        for(int i = 0; i < q; i++){
            cin >> c1 >> c2;
            cout << dist[c1][c2] << endl;
        }
        cout << endl;
        cin >> c >> r >> q;
    }
}