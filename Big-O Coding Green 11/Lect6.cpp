#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int m, n, a, b, p;
    cin >> m >> n >> a >> b >> p;

    int k = m*n;
    int matrix[m][n];
    int calc[k];

    // Tao array
    calc[0] = a;
    calc[1] = b;
    for(k = 2; k <= m*n-1; k++){
        calc[k] = (calc[k-2]+calc[k-1])%p;
    }

    // Tao matrix
    int index = 0;
    for(int i = 0; i <= m-1; i++){
        for(int j = 0; j <= n-1; j++){
            matrix[i][j] = calc[index];
            index++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}