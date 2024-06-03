#include <iostream>
#include <stack>
#include <vector>

using namespace std;
#define MAX 101
const string sentence = "ALLIZZWELL";
const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[MAX][MAX];
string matrix[MAX];
int R, C;
bool found;

bool isValid(int r, int c){
    return r >= 0 && c >= 0 && r < R && c < C;
}

void DFS(int cr, int cc, int count){
    if(count == sentence.size()){
        found = true;
        return;
    }

    for(int i = 0; i < 8; i++){
        int row = cr + dr[i];
        int column = cc + dc[i];

        if(isValid(row, column) && matrix[row][column] == sentence[count] && !visited[row][column]){
            visited[row][column] = true;
            DFS(row, column, count+1);
            visited[row][column] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> R >> C;
        for(int i = 0; i < R; i++){
            cin >> matrix[i];
        }
        found = false;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(matrix[i][j] == 'A' && !found){
                    DFS(i, j, 1);
                }
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }
}