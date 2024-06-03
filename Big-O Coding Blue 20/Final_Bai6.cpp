#include <iostream>
#include <string>

using namespace std;

#define MAX 10
bool flag = true;

struct Node{
    struct Node *child[MAX];
    int countWord;
};

struct Node *newNode(){
    struct Node *node = new Node;
    node->countWord = 0;
    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node *root, string s){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - '0';
        if(temp->countWord > 0){
            flag = false;
        }
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();   
        }
        // cout << ch << " " << s[i] << " " << temp->child[ch]->countWord << " " << flag << endl; // test
        temp = temp->child[ch];
    }
    temp->countWord += 1;
    for(int i = 0; i < MAX; i++){
        if(temp->child[i] != NULL){
            flag = false;
        }
    }
}

int main(){
    int T, n;
    string phoneNum;
    
    cin >> T;
    struct Node *root = newNode();
    for(int i = 1; i <= T; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> phoneNum;
            addWord(root, phoneNum);
        }
        cout << (flag ? "YES" : "NO") << endl;
        flag = true;
        delete root;
        struct Node *root = newNode();
    }
}