#include <iostream>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
};

Edge createEdge(int u, int v, int w){
    Edge e;
    e.u = u;
    e.v = v;
    e.w = w;
    return e;
}

void calculateLoop(int m, Edge edgeList[]){
    int count = 0;
    int product = 1;
    for(int i = 0; i < m; i++){
        if(edgeList[i].u == edgeList[i].v){
            count++;
            product = (product * edgeList[i].w)%1000007;
        }
    }
    if(count == 0){
        cout << -1;
    } else {
        cout << count << " " << product;
    }
}

int main(){
    int m;
    cin >> m;
    Edge edgeList[m];
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edgeList[i] = createEdge(u, v, w);
    }
    calculateLoop(m, edgeList);
}