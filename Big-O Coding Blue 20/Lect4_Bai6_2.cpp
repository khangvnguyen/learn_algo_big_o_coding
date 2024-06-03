#include <iostream>
#include <queue>

using namespace std;

struct Car{
    int id;
    int arrivalTime;
};

int main(){
    int c;
    cin >> c;
    int result[10005] = {0};
    while(c--){
        int n, t, m, arrivalTime;
        string side;
        cin >> n >> t >> m;
        queue<Car> leftBank;
        queue<Car> rightBank;
        for(int i = 0; i < m; i++){
            cin >> arrivalTime >> side;
            if(side == "left"){
                leftBank.push((Car){i, arrivalTime});
            } else {
                rightBank.push((Car){i, arrivalTime});
            }
        }
        int currentTime = 0;
        int carOnFerry = 0;
        bool onLeft = true;
        while(carOnFerry != 0 || !leftBank.empty() || !rightBank.empty()){

            if(carOnFerry == 0 && (!leftBank.empty() && leftBank.front().arrivalTime > currentTime && !rightBank.empty() && rightBank.front().arrivalTime > currentTime)){
                currentTime = max(currentTime, min(leftBank.front().arrivalTime, rightBank.front().arrivalTime));
            } else if(carOnFerry == 0 && !leftBank.empty() && leftBank.front().arrivalTime > currentTime && rightBank.empty()){
                currentTime = max(currentTime, leftBank.front().arrivalTime);
            } else if(carOnFerry == 0 && !rightBank.empty() && rightBank.front().arrivalTime > currentTime && leftBank.empty()){
                currentTime = max(currentTime, rightBank.front().arrivalTime);
            }

            if(carOnFerry == n || (onLeft && !leftBank.empty() && leftBank.front().arrivalTime > currentTime) || (onLeft && leftBank.empty()) || (!onLeft && rightBank.empty()) || (!onLeft && !rightBank.empty() && rightBank.front().arrivalTime > currentTime)){
                onLeft = !onLeft;
                currentTime += t;
                carOnFerry = 0;
            } else if(onLeft && !leftBank.empty() && leftBank.front().arrivalTime <= currentTime){
                carOnFerry++;
                result[leftBank.front().id] = currentTime + t;
                leftBank.pop();
            } else if(!onLeft && !rightBank.empty() && rightBank.front().arrivalTime <= currentTime){
                carOnFerry++;
                result[rightBank.front().id] = currentTime + t;
                rightBank.pop();
            }
            
        }
        for(int i = 0; i < m; i++){
            cout << result[i] << endl;
        }
        if(c > 0){
            cout << endl;
        }
    }
}