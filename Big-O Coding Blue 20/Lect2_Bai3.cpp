#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    long long t;
    cin >> n;
    cin >> t;

    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    long long sum = 0;
    int count = 0;
    int maxCount = 0;
    int left = 0;
    int right = 0;
    sum += A[right];
    count++;
    maxCount = max(count, maxCount);

    while(left < n){
        while(sum < t && right < n){
            right++;
            sum += A[right];
            count++;
            maxCount = max(count, maxCount);
        }
        left++;
        sum = sum - A[left-1];
        count--;
    }
    cout << maxCount-1;
}