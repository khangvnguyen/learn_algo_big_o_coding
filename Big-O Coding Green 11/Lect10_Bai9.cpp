#include <iostream>
#include <cmath>
using namespace std;

struct Apple{
    int w;
    int p;
};

int main(){
    int n;
    cin >> n;
    Apple ListApple[n+1];
    for(int i = 0; i < n; i++){
        cin >> ListApple[i].w;
        cin >> ListApple[i].p;
    }

    int indexToBuy = 0;
    int maxW = 0;
    int PofMaxW = 0;
    for(int i = 0; i < n; i++){
        if(maxW < ListApple[i].w){
            maxW = ListApple[i].w;
            PofMaxW = ListApple[i].p;
            indexToBuy = i;
        } else if (maxW == ListApple[i].w){
            if(PofMaxW < ListApple[i].p){
                PofMaxW = ListApple[i].p;
                indexToBuy = i;
            }
        }
    }

    cout << indexToBuy;
}