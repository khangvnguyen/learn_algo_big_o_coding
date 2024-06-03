#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>

#define MAX 31
const int INF = 1e9;

using namespace std;

vector<vector<float> > graph;
vector<vector<float> > dist;
int n, m;
string currency[MAX];

bool FloydWarshall(vector<vector<float> > &graph, vector<vector<float> > &dist){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] < dist[i][k] * dist[k][j]){
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(dist[i][i] > 1){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    int casenum = 0;
    while(n != 0){
        casenum++;
        graph = vector<vector<float> >(n, vector<float>(n));
        dist = vector<vector<float> >(n, vector<float>(n));
        for(int i = 0; i < n; i++){
            cin >> currency[i];
        }
        cin >> m;
        string source, destination;
        float rate;
        int indexSource, indexDestination;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    graph[i][j] = 1;
                } else {
                    graph[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            cin >> source >> rate >> destination;
            for(int j = 0; j < n; j++){
                if(source == currency[j]){
                    indexSource = j;
                }
                if(destination == currency[j]){
                    indexDestination = j;
                }
            }
            graph[indexSource][indexDestination] = rate;
        }
        cout << "Case " << casenum << ": ";
        cout << (FloydWarshall(graph, dist) ? "Yes" : "No") << endl;
        cin >> n;
    }
}