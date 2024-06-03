#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    vector<int> result(100001);
    int left = 0;
    int right = 1;
    result[A[left]]++;
    result[A[right]]++;

    int currentAmount;
    if(A[left] == A[right]){
        currentAmount = 1;
    } else {
        currentAmount = 2;
    }

    int count = 2;
    int maxCount = 2;

    while(left < n){
        while(currentAmount <= 2 && right < n-1){
            right++;
            if(currentAmount == 2 && result[A[right]] != 0){
                result[A[right]]++;
                count++;
                maxCount = max(count, maxCount);
            } else if (currentAmount == 1 && result[A[right]] == 0){
                currentAmount++;
                result[A[right]]++;
                count++;
                maxCount = max(count, maxCount);
            } else if (currentAmount == 1 && result[A[right]] != 0){
                result[A[right]]++;
                count++;
                maxCount = max(count, maxCount);
            } else {
                currentAmount++;
                result[A[right]]++;
                count++;
            }
        }
        result[A[left]]--;
        if(result[A[left]] == 0){
            currentAmount--;
        }
        left++;
        count--;
    }
    cout << maxCount;
}