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

int degree(int M[][1001], int n, int X){
    int degree;
    for(int i = 0; i < n; i++){
        if(M[X][i]==1){
            degree++;
        }
    }
    return degree;
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
    for(int i = 0; i < n; i++){
        if(degree(M, n, i)%2 != 0){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}