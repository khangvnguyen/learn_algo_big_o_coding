#include <iostream>
#include <cmath>
using namespace std;

int solve(int a, int b, int c, int d){
    int i;
    int j;
    bool flag = false;
    for(i = 0; i <= 100; i++){
        for (j = 0; j <= 100; j++){
            if(b+i*a == d+j*c){
                flag = true;
                break;
            }
        }
        if(flag == true){
            break;
        }
    }
    if(flag == true){
        return (b+i*a);
    } else {
        return -1;
    }
}

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << solve(a,b,c,d);
}

    // Doc mang vuong (Nho thay doi so phan tu)
    int a[1000][1000];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // Doc mang thuong (Nho thay doi so phan tu)
    int a[1000][1000];
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }