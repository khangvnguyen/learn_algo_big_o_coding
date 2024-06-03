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
    stack<int> massGroup;
    string group;
    for(int i = 0; i < formula.size(); i++){
        if(formula[i] == '('){
            int len = 0;
            int pos = i+1;
            while(formula[i]!= ')'){
                i++;
                len++;
            }
            group = formula.substr(pos, len-1);
            massGroup.push(calculate(group));
            if(formula[i+1] >= '2' && formula[i+1] <= '9'){
                molarMass += massGroup.top()*((int)formula[i+1]-48);
                i += 2;
            } else {
                molarMass += massGroup.top();
            }
        }
        if(formula[i] == 'C' || formula[i] == 'H' || formula[i] == 'O'){
            molarMass += transform(formula[i]);
        } else if(formula[i] >= '2' && formula[i] <= '9'){
            molarMass += transform(formula[i-1]) * ((int)formula[i]-49);
        }
    }
    return molarMass;
}

int main(){
    string molecule;
    cin >> molecule;
    cout << calculate(molecule);
}