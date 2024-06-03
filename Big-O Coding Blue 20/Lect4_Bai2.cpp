#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int a;
    while(true){
        cin >> a;
        if(a==0){
            break;
        }
        int n = a;
        int parkingLot[n+1];
        for(int i = 0; i < n; i++){
            cin >> parkingLot[i];
        }

        stack<int> side;
        int street = 1;
        bool possible = true;

        for(int i = 0; i < n; i++){
            while(!side.empty() && side.top() == street){
                street++;
                side.pop();
            }
            if(parkingLot[i] == street){
                street++;
            } else if (!side.empty() && side.top() < parkingLot[i]){
                possible = false;
                break;
            } else {
                side.push(parkingLot[i]);
            }
        }

        if(possible){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

}