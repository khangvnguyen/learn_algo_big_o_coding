#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 10005

vector<int> marbles;

int binarySearch(const vector<int> &a, int left, int right, int x){
    if(left == right){
        int mid = left + (right - left)/2;
        if(a[mid] == x){
            return mid;
        }
        if(a[mid] > x){
            return binarySearch(a, left, mid-1, x);
        }
        return binarySearch(a, mid+1, right, x);
    }
    return -1;
}

int bsFirst(const vector<int> &a, int left, int right, int x){
    if(left <= right){
        int mid = left + (right - left)/2;
        if((mid == left || x > a[mid-1]) && a[mid] == x){
            return mid;
        } else if(x > a[mid]){
            return bsFirst(a, mid+1, right, x);
        } else {
            return bsFirst(a, left, mid-1, x);
        }
    }
    return -1;
}

int main(){
    int n, q, marble, result, query, casenum = 0;
    cin >> n >> q;
    while(n!=0){
        casenum++;
        cout << "CASE# " << casenum << ":" << endl;
        for(int i = 0; i < n; i++){
            cin >> marble;
            marbles.push_back(marble);
        }
        sort(marbles.begin(), marbles.end());
        for(int i = 0; i < q; i++){
            cin >> query;
            cout << query << " ";
            result = bsFirst(marbles, 0, n-1, query);
            if(result == -1){
                cout << "not found" << endl;
            } else {
                cout << "found at " << result+1 << endl;
            }
        }
        marbles.clear();
        cin >> n >> q;
    }
}