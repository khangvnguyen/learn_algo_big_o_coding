#include <iostream>
#include <cmath>
using namespace std;

struct Student{
    char name[101];
    float math;
    float literature;
};

double average(float math, float literature);

double average(float math, float literature){
    return (math+literature)/2;
}

int main(){
    int n;
    cin >> n;

    Student S[n+1];

    for(int i = 0; i < n; i++){
        cin.getline(S[i].name, 101);
        cin.getline(S[i].name, 101);
        cin >> S[i].math;
        cin >> S[i].literature;
    }

    int count = 0;
    for(int i = 0; i < n; i++){
        if(average(S[i].math, S[i].literature) >= 9.0){
            count++;
        }
    }

    cout << count;
}