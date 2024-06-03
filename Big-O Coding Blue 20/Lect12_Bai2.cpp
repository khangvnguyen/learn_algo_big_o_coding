#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001

int n, m;
vector<int> friends;

int binarySearch(vector<int> &a, int left, int right, int m){
    int count = 0;
    for(int i = 0; i < n; i++){
        int x = m - a[i];
        if(x < a[i]+1){
            break;
        }
        left = 0;
        right = n;
        while(left <= right){
            int mid = (left+right)/2;
            if(a[mid] == x){
                count++;
                break;
            } else if(x > a[mid]){
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
    }
    return count;
}

int main(){
    int t, money;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> money;
            friends.push_back(money);
        }
        sort(friends.begin(), friends.end());
        cout << binarySearch(friends, 0, n-1, m) << endl;
        friends.clear();
    }
}