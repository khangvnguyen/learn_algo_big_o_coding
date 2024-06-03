#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAX 26

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
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();
            temp->child[ch]->countWord++;
        } else if(temp->child[ch] != NULL){
            temp->child[ch]->countWord++;
        }
        temp = temp->child[ch];
    }
}

int findWord(struct Node *root, string s){
    int res;
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            return 0;
        } else if(temp->child[ch] != NULL){
            res = temp->child[ch]->countWord;
        }
        temp = temp->child[ch];
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    string command; string name;
    struct Node *root = newNode();
    while(n--){
        cin >> command >> name;
        if(command == "add"){
            addWord(root, name);
        } else {
            cout << findWord(root, name) << endl;
        }
    }
}