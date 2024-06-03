#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int command;
    int value;
    int quantity = 0;
    priority_queue<int> smallest;
    priority_queue<int, vector<int>, greater<int> > biggest;
    
    for(int i = 0; i < n; i++){
        cin >> command;
        if(command == 1){
            cin >> value;
            quantity++;
            if(quantity <= 2){
                smallest.push(value);
            } else if(quantity == 3){
                if(value <= smallest.top()){
                    biggest.push(smallest.top());
                    smallest.pop();
                    smallest.push(value);
                } else {
                    biggest.push(value);
                }
            } else if(quantity % 3 != 0){
                if(value <= biggest.top()){
                    smallest.push(value);
                } else {
                    smallest.push(biggest.top());
                    biggest.pop();
                    biggest.push(value);
                }
            } else {
                if(value >= smallest.top()){
                    biggest.push(value);
                } else {
                    biggest.push(smallest.top());
                    smallest.pop();
                    smallest.push(value);
                }
            }
        } else if(command == 2){
            if(biggest.size() == 0){
                cout << "No reviews yet" << endl;
            } else {
                cout << biggest.top() << endl;
            }
        }
    }
}