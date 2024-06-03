#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    // Doc mang 2D thuong (Nho thay doi so phan tu)
    int a[1000][1000];
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    int largest_number[1000];
    int largest_index[1000];
    int largest = 0;

    // Luu gia tri phan tu lon nhat cua tung dong vao array largest_number 
    for(int i = 0; i <= m-1; i++){
        for(int j = 0; j <= n-1; j++){
            if(a[i][j] > largest){
                largest_number[i] = a[i][j];
                largest_index[i] = j;
                largest = a[i][j];
            }
        }
        largest = 0;
    }

    int count = 0;
    bool flag = true;

    // Search tung dong lai, neu dung phan tu co gia tri bang gia tri lon nhat thi search cot
    for(int i = 0; i <= m-1; i++){
        for(int j = 0; j <= n-1; j++){
            if(a[i][j] == largest_number[i]){
                for(int k = 0; k <= m-1; k++){
                    if(a[i][j] > a[k][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag == true){
                    count++;
                } else {
                    flag = true;
                }
            }
        }
    }
    cout << count;
}