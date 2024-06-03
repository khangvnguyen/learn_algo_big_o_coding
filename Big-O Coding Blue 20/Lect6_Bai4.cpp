#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#define MAX 30001
vector<int> graph[MAX];
int path[MAX];
bool loopExists = false;

void DFS(int src){
    stack<int> s;
    stack<int> currentLoop;

    path[src] = 0;
    if(loopExists){
        return;
    }

    for(int i = 0; i < graph[src].size(); i++){
        if(path[graph[src][i]] == 0){
            loopExists = true;
            return;
        } else if(path[graph[src][i]] == -1){
            DFS(graph[src][i]);
        }
    }
    path[src] = 2;
}

int main(){
    int t, n, m, a, b;
    cin >> t;
    
    for(int testCase = 0; testCase < t; testCase++){
        cin >> n >> m;

        for(int i = 1; i <= n; i++){
            path[i] = -1;
        }

        for(int i = 0; i < m; i++){
            cin >> a >> b;
            int tobeAdded = true;
            for(int j = 0; j < graph[a].size(); j++){ // only add the connection if b is not yet connected with a (avoid redundencies)
                if(b == graph[a][j]){
                    tobeAdded = false;
                    break;
                }
            }
            if(tobeAdded){
                graph[a].push_back(b);
            }
        }

        int currentCase = 1;
        while(currentCase <= n && !loopExists){
            if(path[currentCase] == -1){
                DFS(currentCase);
            }
            currentCase++;
        }

        if(loopExists){
            cout << "YES" << endl;
            loopExists = false;
        } else {
            cout << "NO" << endl;
        }

        currentCase = 1;
        for(int k = 0; k < m; k++){
            graph[k].clear();
        }

    }

}