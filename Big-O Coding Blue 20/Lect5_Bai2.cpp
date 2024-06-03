#include <iostream>
#include <queue>

using namespace std;

#define MAX 21
int M, N;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
string maze[MAX];
bool visited[MAX][MAX];

struct Cell{
    int r;
    int c;
};

bool isValid(int r, int c){
    return r >= 0 && c >= 0 && r < M && c < N;
}

bool BFS(Cell s, Cell f){
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    while(!q.empty()){
        Cell u = q.front();
        q.pop();
        if(u.r == f.r && u.c == f.c){
            return true;
        }
        for(int i = 0; i < 4; i++){
            if(isValid(u.r+dr[i], u.c+dc[i]) && maze[u.r+dr[i]][u.c+dc[i]]=='.'){
                Cell neighbor = (Cell){u.r+dr[i], u.c+dc[i]};
                if(!visited[neighbor.r][neighbor.c]){
                    visited[neighbor.r][neighbor.c] = true;
                    q.push(neighbor);
                }
            }
        }
    }
    return false;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> M >> N;
        for(int i = 0; i < M; i++){
            cin >> maze[i];
        }
        vector<Cell> entrance;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                visited[i][j] = false;
                if(maze[i][j] == '.' && (i == 0 || j == 0 || i == M-1 || j == N-1)){
                    entrance.push_back((Cell){i,j});
                }
            }
        }
        if(entrance.size() != 2){
            cout << "invalid" << endl;
        } else {
            if(BFS(entrance[0], entrance[1])){
                cout << "valid" << endl;
            } else {
                cout << "invalid" << endl;
            }
        }
    }

}