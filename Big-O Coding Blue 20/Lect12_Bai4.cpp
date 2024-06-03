#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    int ladyChimps[50001];
    for(int i = 0; i < n; i++){
        cin >> ladyChimps[i];
    }
    vector<int> v(ladyChimps, ladyChimps+n);
    int m, value;
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> value;
        vector<int>::iterator low_value;
        vector<int>::iterator upp_value;
        low_value = lower_bound(v.begin(), v.end(), value);
        upp_value = upper_bound(v.begin(), v.end(), value);
        int index1 = low_value - v.begin();
        if(ladyChimps[index1] >= value){
            index1 = index1 - 1;
        }
        int index2 = upp_value - v.begin();
        if(index1 == -1){
            cout << "X ";
        } else if(index1 == n){
            cout << ladyChimps[n-1] << " ";
        } else {
            cout << ladyChimps[index1] << " ";
        }
        if(index2 == n){
            cout << "X" << endl;
        } else if(index2 == 0){
            cout << ladyChimps[0] << endl;
        } else {
            cout << ladyChimps[index2] << endl;
        }
        
    }
}