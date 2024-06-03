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

void merge(Edge L[], int nL, Edge R[], int nR, Edge result[]){
    int i, j, k;
    i = 0;
    j = 0;
    for(k = 0; i < nL && j < nR; k++){
        if(L[i].w < R[j].w){
            result[k] = L[i];
            i++;
        } else {
            result[k] = R[j];
            j++;
        }
    }
    while(i < nL){
        result[k] = L[i];
        i++;
        k++;
    }
    while(j < nR){
        result[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(Edge array[], int n){
    if(n <= 1){
        return;
    }
    int nL = n/2;
    int nR = n-nL;
    Edge left[n/2+1];
    Edge right[n/2+1];
    int result[n];

    for(int i = 0; i < nL; i++){
        left[i] = array[i];
    }
    for(int i = nL; i < n; i++){
        right[i-nL] = array[i];
    }

    mergeSort(left, nL);
    mergeSort(right, nR);
    merge(left, nL, right, nR, array);
}

void smallestEdges(int k, int m, Edge edgeList[]){
    mergeSort(edgeList, m);
    for(int i = k-1; i >= 0; i--){
        cout << edgeList[i].u << " " << edgeList[i].v << endl;
    }
}

int main(){
    int m, k;
    cin >> m >> k;
    Edge edgeList[m];
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        edgeList[i] = createEdge(u, v, w);
    }
    smallestEdges(k, m, edgeList);
}