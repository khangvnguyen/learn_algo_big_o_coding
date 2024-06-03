#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

using namespace std;
#define MAX 1002

int R, C;
bool map[MAX][MAX];
bool visited[MAX][MAX];
int dist[MAX][MAX];
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};

struct Cell{
    int r;
    int c;
};

bool isValid(int r, int c){
    return r >= 0 && c >= 0 && r < R && c < C;
}

void BFS(Cell src){
    visited[src.r][src.c] = true;
    queue<Cell> q;
    q.push(src);
    dist[src.r][src.c] = 0;
    while(!q.empty()){
        Cell u = q.front();
        for(int i = 0; i < 4; i++){
            Cell neighbor = (Cell){u.r+dr[i], u.c+dc[i]};
            if(isValid(neighbor.r, neighbor.c) && map[neighbor.r][neighbor.c] == 0){
                if(!visited[neighbor.r][neighbor.c]){
                    visited[neighbor.r][neighbor.c] = true;
                    q.push(neighbor);
                    dist[neighbor.r][neighbor.c] = dist[u.r][u.c]+1;
                }
            }
        }
        q.pop();
    }
}

int main(){
    cin >> R >> C;
    while(R != 0 && C != 0){
        for(int i = 0; i < MAX; i++){
            for(int j = 0; j < MAX; j++){
                map[i][j] = false;
                visited[i][j] = false;
                dist[i][j] = 0;
            }
        }
        int rowWBomb;
        cin >> rowWBomb;
        int row, numbomb, bomb;
        for(int i = 0; i < rowWBomb; i++){
            cin >> row >> numbomb;
            for(int j = 0; j < numbomb; j++){
                cin >> bomb;
                map[row][bomb] = true;
            }
        }
        Cell start, fin;
        int r1, c1;
        cin >> r1 >> c1;
        start = (Cell){r1,c1};
        cin >> r1 >> c1;
        fin = (Cell){r1, c1};

        BFS(start);
        cout << dist[fin.r][fin.c] << endl;
        cin >> R >> C;
    }
}