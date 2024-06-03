#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int c;
    cin >> c;
    for(int i = 0; i < c; i++){
        int n, t, m;
        cin >> n >> t >> m;
        queue<int> L;
        queue<int> R;
        queue<int> ferry;
        for(int i = 0; i < m; i++){
            int minute;
            cin >> minute;
            string bank;
            cin >> bank;
            if(bank == "left"){
                L.push(minute);
            } else {
                R.push(minute);
            }
        }

        int time = 0;
        int load = 0;
        bool posLeft = true; // true if ferry is on the left bank and false otherwise
        queue<int> result;

        if(L.front() < R.front()){
            time = L.front();
        } else {
            time = R.front()+t;
            posLeft = false;
        }
        while(!L.empty() && !R.empty()){
            if(posLeft && L.front() <= time){
                while(L.front() <= time && load <= n){
                    ferry.push(L.front());
                    L.pop();
                }
                while(!ferry.empty()){
                    result.push(ferry.front()+t);
                    ferry.pop();
                }
                posLeft = false;
            }
        }

        while(!result.empty()){
            cout << result.front() << endl;
            result.pop();
        }
    }
}