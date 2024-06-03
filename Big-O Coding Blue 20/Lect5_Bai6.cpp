#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define MAX 251
bool visited[MAX][MAX];
bool image[MAX][MAX];
int N, M;
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int sizes[MAX*MAX];
int numberOfSlick;


struct Cell{
    int r;
    int c;
};

bool isValid(int r, int c){
    return r >= 0 && c >= 0 && r < N && c < M;
}

void BFS(Cell s){
    int count = 0;
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);
    count++;
    while(!q.empty()){
        Cell u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            Cell neighbor = (Cell){u.r+dr[i], u.c+dc[i]};
            if(isValid(neighbor.r, neighbor.c) && image[neighbor.r][neighbor.c] == 1){
                if(!visited[neighbor.r][neighbor.c]){
                    visited[neighbor.r][neighbor.c] = true;
                    q.push(neighbor);
                    count++;
                }
            }
        }
    }
    sizes[count]++;
    numberOfSlick++;
}

int main(){
    cin >> N >> M;
    while(N != 0 && M != 0){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> image[i][j];
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(image[i][j] == 1 && visited[i][j] == false){
                    BFS((Cell){i,j});
                }
            }
        }
        cout << numberOfSlick << endl;
        for(int i = 1; i < MAX*MAX; i++){
            if(sizes[i] != 0){
                cout << i << " " << sizes[i] << endl;
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                image[i][j] = false;
                visited[i][j] = false;
            }
        }
        for(int i = 0; i < MAX*MAX;i++){
            sizes[i] = 0;
        }
        numberOfSlick = 0;
        cin >> N >> M;
    }
}