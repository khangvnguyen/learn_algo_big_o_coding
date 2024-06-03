#include <iostream>
#include <queue>

using namespace std;

#define MAX 21
int M, N;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
string land[MAX];
bool visited[MAX][MAX];

struct Cell{
    int r;
    int c;
};

bool isValid(int r, int c){
    return r >= 0 && c >= 0 && r < M && c < N;
}

int BFS(Cell s){
    int count = 0;
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    count++;
    while(!q.empty()){
        Cell u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            if(isValid(u.r+dr[i], u.c+dc[i]) && land[u.r+dr[i]][u.c+dc[i]]=='.'){
                Cell neighbor = (Cell){u.r+dr[i], u.c+dc[i]};
                if(!visited[neighbor.r][neighbor.c]){
                    visited[neighbor.r][neighbor.c] = true;
                    q.push(neighbor);
                    count++;
                }
            }
        }
    }
    return count;
}

int main(){
    int T;
    cin >> T;
    Cell start;
    for(int i = 1; i <= T; i++){
        cin >> N >> M;
        for(int i = 0; i < M; i++){
            cin >> land[i];
        }
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(land[i][j] == '@'){
                    start = (Cell){i,j};
                    visited[i][j] = false;
                } else {
                    visited[i][j] = false;
                }
            }
        }
        cout << "Case " << i << ": " << BFS(start) << endl;
    }
}