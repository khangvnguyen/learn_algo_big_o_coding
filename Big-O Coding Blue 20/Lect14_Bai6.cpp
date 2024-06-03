#include <iostream>
#include <map>
#include <string>

using namespace std;
#define MAX 10

struct Node{
    struct Node *child[MAX];
    int countWord;
};

bool flag = true;
string result;

struct Node *newNode(){
    struct Node *node = new Node;
    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    node->countWord = 0;
    return node;
}

void addWord(struct Node *root, string s){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->countWord > 0){
            flag = false;
            result = s;
        }
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
    }
    temp->countWord += 1;
    if(temp->countWord > 1){
        flag = false;
        result = s;
    }
    for(int i = 0; i < MAX; i++){
        if(temp->child[i] != NULL){
            flag = false;
            result = s;
        }
    }
}

int main(){
    int n;
    cin >> n;
    string s[100005];
    struct Node *root = newNode();
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        addWord(root, s[i]);
        if(!flag){
            break;
        }
    }
    if(flag == true){
        cout << "GOOD SET";
    } else {
        cout << "BAD SET" << endl;
        cout << result;
    }
}