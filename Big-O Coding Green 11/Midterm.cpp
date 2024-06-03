#include <iostream>
#include <string.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    double tien;
    if (n <= 1){
        tien = 15000;
    } else if (n >= 2 && n <= 5){
        tien = 15000 + 13500*(n-1);
    } else if (n >= 6 && n <= 11){
        tien = 15000 + 13500*4 + 11000*(n-5);
    } else {
        tien = 9.0/10.0*(15000 + 13500*4 + 11000*7 + 11000*(n-12));
    }
    cout << tien;
}

int main(){
    int n;
    cin >> n;
    int space = n-1;
    int sao = 1;
    for(int i = 0; i < n; i++){
        for(int i = 0; i < space; i++){
            cout << " ";
        }
        for(int i = 0; i < sao; i++){
            cout << "*";
        }
        space--;
        sao=sao+2;
        if(i != n-1){
            cout << endl;
        }
    }
}

int main(){
    int sudoku[9][9];
    for(int i = 0; i < 9; i++){
        for(int j = 0; j<9; j++){
            cin >> sudoku[i][j];
        }
    }
    bool flag = true;
    int check[9] = {1,2,3,4,5,6,7,8,9};
    //Check hang
    for(int i = 0; i < 9; i++){
        int check[9] = {1,2,3,4,5,6,7,8,9};
        for(int j = 0; j < 9; j++){
            check[sudoku[i][j]-1] = 0;
        }
        for(int k = 0; k < 9; k++){
            if(check[k]!=0){
                flag = false;
                break;
            }
        }
    }

    // Check cot
    for(int j = 0; j < 9; j++){
        int check[9] = {1,2,3,4,5,6,7,8,9};
        for(int i = 0; i < 9; i++){
            check[sudoku[i][j]-1] = 0;
        }
        for(int k = 0; k < 9; k++){

            if(check[k]!=0){
                flag = false;
                break;
            }
        }
    }

    // Check 3x3 block
    for(int i = 0; i < 9; i = i + 3){
        int check[9] = {1,2,3,4,5,6,7,8,9};
        for(int m=i; m <= i+2; m++){
            for(int j = 0; j < 3; j++){
                check[sudoku[m][j]-1] = 0;
            }
        }
        for(int k = 0; k < 9; k++){
            if(check[k]!=0){
                flag = false;
                break;
            }
        }
    }

    for(int i = 0; i < 9; i = i + 3){
        int check[9] = {1,2,3,4,5,6,7,8,9};
        for(int m = i; m <= i+2; m++){
            for(int j = 3; j < 6; j++){
                check[sudoku[m][j]-1] = 0;
            }
        }
        for(int k = 0; k < 9; k++){
            if(check[k]!=0){
                flag = false;
                break;
            }
        }
    }

    for(int i = 0; i < 9; i = i + 3){
        int check[9] = {1,2,3,4,5,6,7,8,9};
        for(int m=i; m <= i+2; m++){
            for(int j = 6; j < 9; j++){
                check[sudoku[m][j]-1] = 0;
            }
        }
        for(int k = 0; k < 9; k++){
            if(check[k]!=0){
                flag = false;
                break;
            }
        }
    }

    if(flag == true){
        cout << "YES";
    } else {
        cout << "NO";
    }
}

int main(){
    char s[1001];
    cin.getline(s, 1001);
    int count_a_moc = 0;
    int index_a_moc = 0;
    char local[1001];
    char domain[1001];

    bool valid = true;

    for(int i = 0; i < strlen(s); i++){
        if(s[i]=='@'){
            if(count_a_moc == 0){
                count_a_moc++;
                index_a_moc = i;
            } else {
                valid = false;
                break;
            }
        }
    }

    if(index_a_moc == 0 || index_a_moc == strlen(s)){
        valid = false;
    }

    for(int i = 0; i < index_a_moc; i++){
        local[i] = s[i];
    }

    for(int i = index_a_moc+1; i < strlen(s); i++){
        domain[i-index_a_moc-1] = s[i];
    }

    for(int i = 0; i < strlen(local);i++){
        if((s[i] < 'A' || s[i] > 'Z') && (s[i] < 'a' || s[i] > 'z') && (s[i] < '0' || s[i] > '9') && s[i]!='.' && s[i]!='_'){
            valid=false;
            break;
        }
    }

    int count_cham = 0;
    for(int i = 0; i < strlen(domain); i++){
        if((domain[i] < 'A' || domain[i] > 'Z') && (domain[i] < 'a' || domain[i] > 'z') && domain[i]!='.'){
            valid=false;
            break;
        }
        if(domain[i] == '.'){
            count_cham++;
            if(domain[i+1] == '.'){
                valid=false;
                break;
            }
        }
    }

    if(count_cham == 0){
        valid = false;
    }

    if(valid == true){
        cout << "VALID";
    } else {
        cout << "INVALID";
    }
}