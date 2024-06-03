#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct BangGiayMau{
    int maMau;
    int doDai;
};

int main(){
    int n;
    cin >> n;

    BangGiayMau B[n+1];

    for(int i = 0; i < n; i++){
        cin >> B[i].maMau;
        cin >> B[i].doDai;
    }

    int k = 0;
    int Mau[101][3];

    for(int i = 0; i < n; i++){
        if(k == 0){
            Mau[0][0] = B[i].maMau;
            Mau[0][1] += B[i].doDai;
            Mau[0][2] = 1;
            k++;
        } else {
            for(int j=0; j < k; j++){
                if(B[i].maMau == Mau[j][0]){
                    Mau[j][1] += B[i].doDai;
                    Mau[j][2]++;
                } else {
                    Mau[k][0] = B[i].maMau;
                    Mau[k][1] += B[i].doDai;
                    Mau[k][2] = 1;
                    k++;
                    break;
                }
            }
        }
    }
    cout << k << endl;
    for(int i = 0; i < k; i++){
        for(int j = 0; j < 3; j++){
            cout << Mau[i][j] << " ";
        }
        cout << endl;
    }
}