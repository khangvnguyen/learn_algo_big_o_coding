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

bool isUndirected(int n, int M[][1001]){
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(M[i][j] != M[j][i]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    int M[1001][1001];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> M[i][j];
        }
    }
    if(isUndirected(n, M)){
        cout << "YES";
    } else {
        cout << "NO";
    }
}