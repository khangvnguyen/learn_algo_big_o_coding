#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int findHeight(int max, int n, int m, int a[]){
    int left = 0;
    int right = max;
    int mid;
    int result = 0;
    while(left <= right){
        mid = (left+right)/2;
        int tempCut = 0;
        for(int i = 0; i < n; i++){
            if(a[i]-mid > 0){
                tempCut += a[i] - mid;
            }
            if(tempCut > m){
                break;
            }
        }
        if(tempCut > m){
            left = mid+1;
            if(mid > result){
                result = mid;
            }
        } else if(tempCut < m){
            right = mid-1;
        } else {
            result = mid;
            break;
        }
    }
    return result;
}

int main(){
    int n, m;
    int a[1000005];
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a+n, greater<int>());
    cout << findHeight(a[0], n, m, a);
}