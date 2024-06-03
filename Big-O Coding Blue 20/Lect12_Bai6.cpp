#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000
int n, k;
int A[MAX];
double sumEnergy = 0, sumTransfer = 0, L, R, mid;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        sumEnergy += A[i];
    }

    L = 0;
    R = 1000;

    while(R - L > 1e-7){
        mid = (L + R) / 2;
        sumTransfer = 0;
        for (int i = 0; i < n; i++){
            if(A[i] > mid){
                sumTransfer += A[i] - mid;
            }
        }
        if (mid * n < sumEnergy - sumTransfer*k/100) {
        	L = mid;
        }
        else {
        	R = mid;
        }
    }
    printf("%.9f", L);
    return 0;
}