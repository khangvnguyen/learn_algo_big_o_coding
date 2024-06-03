#include <iostream>
#include <string.h>
using namespace std;

char firstRepeating(char str[]){
    int countChar[52];
    for(int i = 0; i < 52; i++){
        countChar[i] = 0;
    }

    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            if(countChar[int(str[i])-65] < 1){
                countChar[int(str[i])-65]++;
            } else {
                return str[i];
            }
        } else {
            if(countChar[int(str[i])-71] < 1){
                countChar[int(str[i])-71]++;
            } else {
                return str[i];
            }
        }
    }
    return '!';
}

int main(){
    char str[1001];
    cin.getline(str, 1001);
    if(firstRepeating(str) == '!'){
        cout << "null";
    } else {
        cout << firstRepeating(str);
    }
}