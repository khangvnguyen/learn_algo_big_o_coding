#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int a[1001];
    int n;
    cin >> n;
    int countNeg = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] <0){
            countNeg++;
        }
    }

    int set1[1001], set2[1001], set3[1001];
    int set1_index = 0;
    int set2_index = 0;
    int set3_index = 0;

    if(countNeg == 1){
        for(int i = 0; i < n; i++){
            if(a[i] < 0){
                set1[set1_index] = a[i];
                set1_index++;
            } else if(a[i] == 0) {
                set3[set3_index] = a[i];
                set3_index++;
            } else {
                set2[set2_index] = a[i];
                set2_index++;
            }
        }
    } else if(countNeg == 2){
        for(int i = 0; i < n; i++){
            if(a[i] < 0 && set1_index == 0){
                set1[set1_index] = a[i];
                set1_index++;
            } else if(a[i] < 0 && set1_index != 0) {
                set3[set3_index] = a[i];
                set3_index++;
            } else if (a[i] == 0){
                set3[set3_index] = a[i];
                set3_index++;
            } else {
                set2[set2_index] = a[i];
                set2_index++;
            }
        }
    } else {
        for(int i = 0; i < n; i++){
            if(a[i] < 0 && set1_index == 0){
                set1[set1_index] = a[i];
                set1_index++;
            } else if(a[i] < 0 && set1_index == 1 && set2_index <= 1) {
                set2[set2_index] = a[i];
                set2_index++;
            } else {
                set3[set3_index] = a[i];
                set3_index++;
            }   
        }
    }

    cout << set1_index;
    for(int i = 0; i < set1_index; i++){
        cout << " " << set1[i];
    }
    cout << endl;

    cout << set2_index;
    for(int i = 0; i < set2_index; i++){
        cout << " " << set2[i];
    }
    cout << endl;

    cout << set3_index;
    for(int i = 0; i < set3_index; i++){
        cout << " " << set3[i];
    }
    cout << endl;
}