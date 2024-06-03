#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
using namespace std;

struct Square{
    int x;
    int y;
    int value;
};

int main(){
    int m, n;
    cin >> m >> n;
    int k;
    cin >> k;
    Square ListSquare[k+1];
    for(int i = 0; i < k; i++){
        cin >> ListSquare[i].x;
        cin >> ListSquare[i].y;
        cin >> ListSquare[i].value;
    }

    int indicesToPrint[k+1];
    int count = 0;
    for(int i = 0; i < k; i++){
        if(ListSquare[i].value > 0){
            indicesToPrint[count] = i;
            count++;
        }
    }

    cout << count << endl;
    for(int i = 0; i < count; i++){
        cout << ListSquare[indicesToPrint[i]].x << " " << ListSquare[indicesToPrint[i]].y;
        if(i != count-1){
            cout << endl;
        }
    }
}