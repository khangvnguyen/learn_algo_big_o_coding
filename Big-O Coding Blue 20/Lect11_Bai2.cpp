#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#define MAX 28
const int INF = 1e9;
int N;
int distS[MAX][MAX], distM[MAX][MAX];

struct Place {
    int cost, id;

    bool operator<(const Place &other) const {
        return cost < other.cost || (cost == other.cost && id < other.id);
    }
};

vector<Place> res;

void FloydWarshall(int dist[MAX][MAX]) {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    char age, dir, x, y;
    int energy;
    while(cin >> N && N != 0){
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                distS[i][j] = (i == j ? 0 : INF);
                distM[i][j] = (i == j ? 0 : INF);
            }
        }
        for(int i = 0; i < N; i++){
            cin >> age >> dir >> x >> y >> energy;
            int u = x - 'A';
            int v = y - 'A';

            if(age == 'Y'){
                distS[u][v] = min(distS[u][v], energy);
                if(dir == 'B'){
                    distS[v][u] = min(distS[v][u], energy);
                }
            } else {
                distM[u][v] = min(distM[u][v], energy);
                if(dir == 'B'){
                    distM[v][u] = min(distM[v][u], energy);
                }
            }
        }
        cin >> x >> y;
        int s = x - 'A';
        int m = y - 'A';
        FloydWarshall(distS);
        FloydWarshall(distM);

        res.clear();
        int minDist = INF;

        for (int i = 0; i < MAX; i++) {
            int dist1 = distS[s][i];
            int dist2 = distM[m][i];

            if (dist1 != INF && dist2 != INF && dist1 + dist2 <= minDist) {
                res.push_back((Place){dist1 + dist2, i});
                minDist = dist1 + dist2;
            }
        }

        if (res.empty()) {
            cout << "You will never meet.";
        }
        else {
            sort(res.begin(), res.end());
            cout << minDist;

            for (int i = 0; i < res.size(); i++) {
                if (res[i].cost != minDist) {
                    break;
                }
                cout << " " << char(res[i].id + 'A');
            }
        }
        cout << endl;
    }
}