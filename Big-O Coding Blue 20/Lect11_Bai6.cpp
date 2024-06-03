#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point{
    int x;
    int y;
};

#define MAX 1024*1024 + 5
const int INF = 1e9;

using namespace std;

Point towns[MAX];
vector<vector<float> > graph;
vector<vector<float> > dist;
int n;

float calculateDistance(Point a, Point b){
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

bool BellmanFord(vector<vector<float> > &graph, vector<vector<float> > &dist){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = graph[i][j];
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return true;
}

int main(){
    int testcase;
    cin >> testcase;
    for(int a = 1; a <= testcase; a++){
        cin >> n;
        int xtown, ytown;
        for(int i = 0; i < n; i++){
            cin >> xtown >> ytown;
            towns[i] = (Point){xtown, ytown};
        }
        graph = vector<vector<float> >(n, vector<float>(n));
        dist = vector<vector<float> >(n, vector<float>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                float distance = calculateDistance(towns[i], towns[j]);
                if(distance > 10.0){
                    graph[i][j] = INF;
                } else {
                    graph[i][j] = distance;
                }
            }
        }
        BellmanFord(graph, dist);
        cout << "Case #" << a << ":" << endl;
        bool flag = true;
        float maxDist = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dist[i][j] == INF){
                    flag = false;
                    break;
                } else if(dist[i][j] > maxDist){
                    maxDist = dist[i][j];
                }
            }
        }
        if(flag){
            cout << fixed << setprecision(4) << maxDist << endl;
        } else {
            cout << "Send Kurdy" << endl;
        }
        cout << endl;
    }
}