#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    int start = 0;
    int stop = 0;

    for(int i = 0; i < n-1; i++){ // move start and stop up to when it starts to decrease
        if(A[i+1] > A[i]){
            start++;
            stop++;
        } else {
            break;
        }
    }

    for(int i = start; i < n-1; i++){ // move stop up to when it starts to increase
        if(A[i+1] > A[i]){
            break;
        } else {
            stop++;
        }
    }

    if(start == stop){
        cout << "yes" << endl;
        cout << "1 1";
        return 0;
    }
    sort(A+start, A+stop+1);

    for(int i = 0; i < n-1; i++){
        if(A[i+1] < A[i]){
            cout << "no";
            return 0;
        }
    }
    cout << "yes" << endl;
    cout << start + 1 << " " << stop+1;
    return 0;
}