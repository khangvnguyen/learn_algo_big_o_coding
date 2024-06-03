    #include <iostream>
    #include <cstring>
    #include <algorithm>

    using namespace std;

    #define MAX 50005

    int parents[MAX];
    int ranks[MAX];
    int result;

    void makeSet(int n){
        for(int i = 1; i <= n; i++){
            parents[i] = i;
            ranks[i] = 0;
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
        result--;
        if(ranks[up] > ranks[vp]){
            parents[vp] = up;
        } else if(ranks[up] < ranks[vp]){
            parents[up] = vp;
        } else {
            parents[up] = vp;
            ranks[vp]++;
        }
    }


    int main(){
        int n, m, u, v, T = 1;
        cin >> n >> m;
        while(n != 0 && m != 0){
            result = n;
            makeSet(n);
            for(int i = 0; i < m; i++){
                cin >> u >> v;
                unionSet(u, v);
            }
            cout << "Case " << T << ": " << result << endl;
            cin >> n >> m;
            T++;
        }
    }