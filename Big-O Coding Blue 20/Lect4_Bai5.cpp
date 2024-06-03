#include <iostream>
#include <string>
#include <stack>

using namespace std;
int transform(char A){
    if(A == 'C'){
        return 12;
    } else if(A == 'H'){
        return 1;
    } else {
        return 16;
    }
}

int calculate(string formula){
    int molarMass = 0;
    stack<int> result;
    int factor;
    for(int i = 0; i < formula.size(); i++){
        if(formula[i] == '('){
            result.push(0);
        } else if(formula[i] == ')'){
            int thisGroup = 0;
            if(formula[i+1] >= '2' && formula[i+1] <= '9'){
                factor = (int)formula[i+1] - 48;
                i++;
            } else {
                factor = 1;
            }
            while(result.top()!=0){
                thisGroup += result.top()*factor;
                result.pop();
            }
            result.pop();
            result.push(thisGroup);
        } else if(formula[i] == 'C' || formula[i] == 'H' || formula[i] == 'O'){
            result.push(transform(formula[i]));
        } else if(formula[i] >= '2' && formula[i] <= '9'){
            int temp = result.top();
            temp = temp*((int)formula[i]-48);
            result.pop();
            result.push(temp);
        }
    }
    while(!result.empty()){
        molarMass += result.top();
        result.pop();
    }
    return molarMass;
}

int main(){
    string molecule;
    cin >> molecule;
    cout << calculate(molecule);
}