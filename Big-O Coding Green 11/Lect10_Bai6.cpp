#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Color{
    int sum_length;
    int count;
};

void update(Color &color, int length);

void update(Color &color, int length){
    color.sum_length += length;
    color.count++;
}

int main(){
    int n;
    cin >> n;

    Color ListColor[1001];
    for(int i = 0; i <= 1000; i++){
        ListColor[i].sum_length = 0;
        ListColor[i].count = 0;
    }

    int maMau;
    int length;

    for(int i = 0; i < n; i++){
        cin >> maMau;
        cin >> length;
        update(ListColor[maMau], length);
    }

    int k = 0;

    for(int i = 1; i <= 1000; i++){
        if(ListColor[i].count > 0){
            k++;
        }
    }
    cout << k << endl;

    for(int i = 1; i <= 1000; i++){
        if(ListColor[i].count > 0){
            cout << i << " " << ListColor[i].sum_length << " " << ListColor[i].count << endl;
        }
    }
}