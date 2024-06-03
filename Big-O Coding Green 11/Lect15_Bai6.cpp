#include <iostream>
using namespace std;

struct Edge{
    int u;
    int v;
};

Edge createEdge(int first, int second){
    Edge e;
    e.u = first;
    e.v = second;
    return e;
}

void convertAdjToEdgeList(int n, int Adjacent[][1001], Edge edgeList[]){
    int countEdge = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(Adjacent[i][j] == 1){
                edgeList[countEdge] = createEdge(i, j);
                countEdge++;
            }
        }
    }
    cout << countEdge << endl;
    for(int i = 0; i < countEdge; i++){
        cout << edgeList[i].u << " " << edgeList[i].v << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int Adjacent[1001][1001];
    Edge edgeList[n*n+1];
    int countEdge = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> Adjacent[i][j];
            if(Adjacent[i][j] == 1){
                edgeList[countEdge] = createEdge(i, j);
                countEdge++;
            }
        }
    }
    cout << countEdge << endl;
    for(int i = 0; i < countEdge; i++){
        cout << edgeList[i].u << " " << edgeList[i].v << endl;
    }
}