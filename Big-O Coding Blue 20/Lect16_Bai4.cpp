#include <iostream>
#include <cstring>

using namespace std;

#define MAX 20010
int n;
int parents[MAX];
int ranks[MAX];

int enemy(int x){
    return x+n;
}

void makeSet(int n){
    for(int i = 0; i < MAX; i++){
        parents[i] = i;
        ranks[i] = 1;   
    }
}

int findSet(int u){
    if(parents[u] != u){
        parents[u] = findSet(parents[u]);
    }
    return parents[u];
}

int unionSet(int u, int v){
    int up = parents[u];
    int vp = parents[v];
    if(up == vp){
        return 0;
    }
    if(ranks[up] < ranks[vp]){
        parents[up] = vp;
        ranks[vp] += ranks[up];
    } else if (ranks[up] > ranks[vp]){
        parents[vp] = up;
        ranks[up] += ranks[vp];
    }
    return 1;
}

void setFriends(int u, int v){
    if(findSet(u) == findSet(enemy(v)) || findSet(v) == findSet(enemy(u))){
        cout << -1 << endl;
    } else {
        unionSet(u,v);
        unionSet(enemy(u), enemy(v));
    }
}

void setEnemies(int u, int v){
    if(findSet(u) == findSet(v)){
        cout << -1 << endl;
    } else {
        unionSet(u, enemy(v));
        unionSet(v, enemy(u));
    }
}

bool areFriends(int u, int v){
    return (findSet(u) == findSet(v));
}

bool areEnemies(int u, int v){
    return (findSet(u) == findSet(enemy(v)) || findSet(v) == findSet(enemy(u)));
}

int main(){
    cin >> n;
    makeSet(n);
    int c, x, y;
    cin >> c >> x >> y;
    while(c!=0 || x!=0 || y!=0){
        if(c==1){
            setFriends(x, y);
        } else if(c==2){
            setEnemies(x, y);
        } else if(c==3){
            cout << areFriends(findSet(x),findSet(y)) << endl;
        } else {
            cout << areEnemies(findSet(x),findSet(y)) << endl;
        }
        cin >> c >> x >> y;
    }
}