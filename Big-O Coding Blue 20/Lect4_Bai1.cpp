#include <iostream>
#include <string>
#include <stack>

using namespace std;

void transform(string expression){
    stack<char> s;
    for(int i = 0; i < expression.size(); i++){
        if(expression[i] >= 'a' && expression[i] <= 'z'){
            cout << expression[i];
        } else if(expression[i] == ')'){
            cout << s.top();
            s.pop();
        } else if(expression[i] != '('){
            s.push(expression[i]);
        }
    }
    cout << endl;
}
int main(){
    int t;
    string expression;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> expression;
        transform(expression);
    }
    return 0;
}