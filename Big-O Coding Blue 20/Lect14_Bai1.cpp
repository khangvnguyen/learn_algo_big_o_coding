#include <iostream>
#include <string>

using namespace std;

#define MAX 26

struct Node{
    struct Node *child[MAX];
    int countWord;
    int maxValue;
};

struct Node *newNode(){
    struct Node *node = new Node;
    node->countWord = 0;
    node->maxValue = 0;
    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node *root, string s, int w){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        temp->maxValue = max(temp->maxValue, w);
    }
}

int findWord(Node *root, string s){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            return -1;
        }
        temp = temp->child[ch];
    }
    return temp->maxValue;
}

int main(){
    int n, q;
    cin >> n >> q;
    string word;
    int w;
    struct Node *root = newNode();
    for(int i = 0; i < n; i++){
        cin >> word >> w;
        addWord(root, word, w);
    }
    for(int i = 0; i < q; i++){
        cin >> word;
        cout << findWord(root, word) << endl;
    }
}