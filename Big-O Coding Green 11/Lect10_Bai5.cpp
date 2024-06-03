#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Student{
    int id;
    double math;
    double literature;
};

int main(){
    int n, q;
    cin >> n >> q;

    Student S[n+1];

    for(int i = 0; i < n; i++){
        cin >> S[i].id;
        cin >> S[i].math;
        cin >> S[i].literature;
    }

    int id_to_find[q+1];

    for(int i = 0; i < q; i++){
        cin >> id_to_find[i];
    }

    for(int i = 0; i < q; i++){
        for(int j = 0; j < n; j++){
            if(id_to_find[i] == S[j].id){
                cout << S[j].math << " " << S[j].literature;
                if(i < q-1){
                    cout << endl;
                }
            }
        }
    }
}