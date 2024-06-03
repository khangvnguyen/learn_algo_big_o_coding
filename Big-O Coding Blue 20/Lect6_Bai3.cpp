#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 51
int n, m, k;
string map[MAX];
bool visited[MAX][MAX];
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell{
    int r, c;
};

vector<vector<Cell> > lakes;

bool isValid(int r, int c){
    return r >= 0 && c >= 0 && r < n && c < m;
}
bool isOcean(int r, int c){
    return r == 0 || c == 0 || r == n-1 || c == m-1;
}
bool sortBySize(vector<Cell> &a, vector<Cell> &b){
    return a.size() < b.size();
}
void DFS(Cell src){
    stack<Cell> s;
    visited[src.r][src.c] = true;
    s.push(src);
    vector<Cell> currentLake;
    bool flagOcean = false;
    while(!s.empty()){
        Cell u = s.top();
        s.pop();
        if(isOcean(u.r, u.c)){
            flagOcean = true;
        }
        currentLake.push_back(u);
        for(int i = 0; i < 4; i++){
            Cell neighbor = (Cell){u.r+dr[i], u.c+dc[i]};
            if(!visited[neighbor.r][neighbor.c] && isValid(neighbor.r, neighbor.c) && map[neighbor.r][neighbor.c] == '.'){
                visited[neighbor.r][neighbor.c] = true;
                s.push(neighbor);
            }
        }
    }
    if(!flagOcean){
        lakes.push_back(currentLake);
    }
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> map[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && map[i][j] == '.'){
                DFS((Cell){i,j});
            }
        }
    }
    sort(lakes.begin(), lakes.end(), sortBySize);
    int cellsTransformed = 0;
    for(int i = 0; i < lakes.size()-k; i++){
        cellsTransformed += lakes[i].size();
        for(int j = 0; j < lakes[i].size(); j++){
            Cell u = lakes[i][j];
            map[u.r][u.c] = '*';
        }
    }

    cout << cellsTransformed << endl;
    for(int i = 0; i < n; i++){
        cout << map[i] << endl;
    }
}