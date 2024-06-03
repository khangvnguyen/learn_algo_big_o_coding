#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    int u;
    float median;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        cin >> u;
        pq.push(u);
    }
    if(n%2 == 1){
        for(int i = 0; i < n/2; i++){
            pq.pop();
        }
        median = pq.top();
    } else {
        for(int i = 0; i < n/2-1; i++){
            pq.pop();
        }
        int num1 = pq.top();
        pq.pop();
        int num2 = pq.top();
        median = (float)(num1+num2)/2;
    }
    cout << median;
}