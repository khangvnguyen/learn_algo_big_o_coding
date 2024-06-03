#include <iostream>
#include <cstring>


using namespace std;
#define MAX 105

int parents[MAX];
int ranks[MAX];

void makeSet(int n){
    for(int i = 0; i <= n; i++){
        parents[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int u){
    if(parents[u] != u)
        parents[u] = findSet(parents[u]);
    return parents[u];
}

int unionSet(int u , int v){
    int up = findSet(u);
    int vp = findSet(v);
    if(up == vp)
        return 0;
    if(ranks[up] > ranks[vp]){
        parents[vp] = up;
    } else if(ranks[up] < ranks[vp]){
        parents[up] = vp;
    } else {
        parents[up] = vp;
        ranks[vp]++;
    }
    return 1;
}

int main(){
    string str;
    int T;
    cin >> T;
    int countLoop = 0;
    int ans;
    getline(cin,str);

    while(getline(cin,str)){
        if(str.size()==0){
            if(countLoop > 0){
                cout << ans << endl;
                cout << endl;
            }
            countLoop++;
        } else if(str.size()==1){
            ans = str[0] - 'A' + 1;
            biggest = str[0]-'A';
            makeSet(biggest);
        } else {
            int u, v;
            u = str[0] - 'A';
            v = str[1] - 'A';
            ans -= unionSet(u,v);
        }
    }
    cout << ans << endl;
}