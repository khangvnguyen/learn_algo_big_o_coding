#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

#define MAX 105
const int INF = 1e9;
struct Edge{
    int source;
    int target;
    double weight;
};
double prob[MAX];
Edge graph[5005];
int n, m;
int u, v;
double w;

void BellmanFord(){
    for(int i = 0; i < MAX; i++){
        prob[i] = -1.0;
    }
    prob[1] = 1.0;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m; j++){
            u = graph[j].source;
            v = graph[j].target;
            w = graph[j].weight;
            if(prob[u] != -1.0 && prob[u]*w > prob[v]){
                prob[v] = prob[u]*w;
            }
            if(prob[v] != -1.0 && prob[v]*w > prob[u]){
                prob[u] = prob[v]*w;
            }
        }
    }
}

int main(){
    cin >> n;
    while(n != 0){
        cin >> m;
        for(int i = 0; i < m ; i++){
            int a, b;
            double p;
            cin >> a >> b >> p;
            p = p/100.0;
            graph[i] = (Edge) {a, b, p};
        }
        BellmanFord();
        cout << fixed << setprecision(6) << prob[n]*100 << " percent" << endl;
        cin >> n;
    }

}