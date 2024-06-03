#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(){
    int a, b;
    int caseNumber = 1;
    while(true){
        cin >> a >> b;
        if(a == 0 && b == 0){
            break;
        }
        int p = a;
        int c = b;

        queue<int> citizens;
        for(int i = 1; i <= min(p,c); i++){
            citizens.push(i);
        }
        
        cout << "Case " << caseNumber << ":" << endl;
        string command;
        int expeditedCitizen;
        for(int i = 0; i < c; i++){
            cin >> command;
            if(command == "N"){
                cout << citizens.front() << endl;
                citizens.push(citizens.front());
                citizens.pop();
            } else {
                cin >> expeditedCitizen;
                int n = citizens.size();
                citizens.push(expeditedCitizen);
                for(int j = 0; j < n; j++){
                    if(citizens.front() != expeditedCitizen){
                        citizens.push(citizens.front());
                        citizens.pop();
                    } else {
                        citizens.pop();
                    }
                }
            }
        }
        while(!citizens.empty()){
            citizens.pop();
        }
        caseNumber++;
    }
}