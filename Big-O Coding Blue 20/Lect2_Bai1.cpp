#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; 
    int k;
    cin >> n >> k;

    vector<int> A(n);

    for(int i = 0; i < n; i++){
        cin >> A[i];
        cout << A[i];
    }

    int firstIndex = 1;
    for(int i = 1; i < n; i++){
        if(A[i+1] != A[i]){
            firstIndex = i;
            break;
        }
    }
    cout << firstIndex;

    vector<int> res;
    vector<int>::iterator it;
    res.push_back(A[firstIndex]);
    int toCheck = firstIndex + 1;

    while(res.size()!=k){
        for(it = res.begin(); it!=res.end(); it++){
            if(A[toCheck] == *it){
                break;
            }
            if(it==res.end()){
                res.push_back(A[toCheck]);
            }
        }
    }

    cout << firstIndex+1 << " " << toCheck; 
}