#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 21
const int INF = 1e9+7;
const int SIZE = 20;
vector<vector<int> > graph;
int dist[MAX][MAX];
int n, a, b;

string formatted(int n) {
    return (n >= 10 ? to_string(n) : " " + to_string(n));
}

void FloydWarshall(){
    for(int k = 1; k <= SIZE; k++){
        for(int i = 1; i <= SIZE; i++){
            for(int j = 1; j <= SIZE; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main(){
    int linecount, borderWith, t=1;
    while(true){
        for (int i = 1; i <= SIZE; i++) {
            for (int j = 1; j <= SIZE; j++) {
                dist[i][j] = INF;
            }
        }
        for(int i = 1; i < 20; i++){
            if (!(cin >> linecount)) {
                return 0;
            }

            for(int j = 1; j <= linecount; j++){
                cin >> borderWith;
                dist[i][borderWith] = 1;
                dist[borderWith][i] = 1;
            }
        }
        FloydWarshall();
        cin >> n;
        cout << "Test Set #" << t++ << endl;
        for(int i = 0; i < n; i++){
            cin >> a >> b;
            cout << formatted(a) << " to " << formatted(b) << ": " << dist[a][b] << endl;
        }
        cout << endl;
    }
}