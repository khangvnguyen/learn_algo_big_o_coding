#include <iostream>
#include <queue>

using namespace std;

int main(){
    int a;
    while(true){
        cin >> a;
        if(a == 0){
            break;
        }
        int n = a;
        queue<int> deck;
        queue<int> discarded;

        for(int i = 1; i <= n; i++){
            deck.push(i);
        }
        while(deck.size() > 1){
            discarded.push(deck.front());
            deck.pop();
            deck.push(deck.front());
            deck.pop();
        }
        
        if(discarded.empty()){
            cout << "Discarded cards:";
            cout << endl;
        } else {
            cout << "Discarded cards: ";
            for(int i = 0; i < n-2; i++){
                cout << discarded.front() << ", ";
                discarded.pop();
            }
            cout << discarded.front();
            cout << endl;
        }
        cout << "Remaining card: " << deck.front() << endl;
    }
}