#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 2005

int main(){
    int n;
    cin >> n;
    pair<int, int> task[MAX];
    for(int i = 0; i < n; i++){
        task[i].second = i+1;
        cin >> task[i].first;
    }
    sort(task, task+n);
    int countSame = 0;
    int result = 0;
    for(int i = 1; i < n; i++){
        if(task[i].first == task[i-1].first){
            countSame++;
            if(countSame == 2){
                result = 3;
                break;
            }
        }

        if(countSame == 1){
            result += 2;
        }
        countSame = 0;
    }
    if(result >= 3){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << task[i].second << " ";
        }
        cout << endl;
        int curIndex;
        for(curIndex = 0; curIndex < n-1; curIndex++){
            if(task[curIndex].first == task[curIndex+1].first){
                swap(task[curIndex], task[curIndex+1]);
                break;
            }
        }
        for(int i = 0; i < n; i++){
            cout << task[i].second << " ";
        }
        cout << endl;
        for(curIndex = curIndex + 1; curIndex < n-1; curIndex++){
            if(task[curIndex].first == task[curIndex+1].first){
                swap(task[curIndex], task[curIndex+1]);
                break;
            }
        }
        for(int i = 0; i < n; i++){
            cout << task[i].second << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}