#include <iostream>
#include <cstring>

using namespace std;

#define MAX 30005

int parents[MAX];
int ranks[MAX];
int cnt[MAX];

void makeSet(int n){
    for(int i = 1; i <= n; i++){
        parents[i] = i;
        ranks[i] = 0;
        cnt[i] = 1;
    }
}

int findSet(int u){
    if(parents[u] != u)
        parents[u] = findSet(parents[u]);
    return parents[u];
}

void unionSet(int u , int v){
    int up = findSet(u);
    int vp = findSet(v);
    if(up == vp)
        return;
    if(ranks[up] > ranks[vp]){
        parents[vp] = up;
        cnt[up] += cnt[vp];
    } else if(ranks[up] < ranks[vp]){
        parents[up] = vp;
        cnt[vp] += cnt[up];
    } else {
        parents[up] = vp;
        ranks[vp]++;
        cnt[vp] += cnt[up];
    }
}


int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m, u, v;
        cin >> n >> m;
        int result = 0;
        makeSet(n);
        for(int i = 0; i < m; i++){
            cin >> u >> v;
            unionSet(u,v);
        }
        for(int i = 1; i <= n; i++){
            result = max(result, cnt[i]);
        }
        cout << result << endl;
    }
}