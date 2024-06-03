#include <iostream>
#include <string.h>
using namespace std;


int main(){
    char s1[201];
    char s2[201];
    cin.getline(s1, 201);
    cin.getline(s2, 201);
    int letter_s1[53];
    int letter_s2[53];
    char letter[53];

    for(int i = 0; i < strlen(s1); i++){
        if(s1[i] >= 'A' && s1[i] <= 'Z'){
            letter_s1[(int)s1[i]-65]++;
        } else if (s1[i] >= 'a' && s1[i] <= 'z'){
            letter_s1[(int)s1[i]-97+26]++;
        }
    }

    for(int i = 0; i < strlen(s2); i++){
        if(s2[i] >= 'A' && s2[i] <= 'Z'){
            letter_s2[(int)s2[i]-65]++;
        } else if (s2[i] >= 'a' && s2[i] <= 'z'){
            letter_s2[(int)s2[i]-97+26]++;
        }
    }

    bool possible = true;
    for(int i = 0; i < 52; i++){
        if(letter_s2[i] > letter_s1[i]){
            possible = false;
            break;
        }
    }

    if(possible){
        cout << "YES";
    } else {
        cout << "NO";
    }
}