#include <iostream>
#include <string>
#include <map>

using namespace std;

#define MAX 4
map<char,int> nu;

int res = 0;

struct Node{
    struct Node *child[MAX];
    int numWord;
};

struct Node *newNode(){
    struct Node *node = new Node;
    node->numWord = 0;
    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
}

void addWord(struct Node *root, string s){
    int ch;
    struct Node *temp = root;
    int curLevel = 0;
    for(int i = 0; i < s.size(); i++){
        ch = nu[s[i]];
        curLevel++;
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();
            temp->child[ch]->numWord += 1;
        } else if(temp->child[ch] != NULL){
            temp->child[ch]->numWord += 1;
        }
        res = max(res, curLevel*temp->child[ch]->numWord);
        temp = temp->child[ch];
    }
}

void deleteTrie(struct Node *root){
    for(int i = 0; i < MAX; i++){
        if(root->child[i] != NULL){
            deleteTrie(root->child[i]);
        }
    }
    delete (root);
}

int main(){
    int T, n;
    nu['A'] = 0;
    nu['C'] = 1;
    nu['G'] = 2;
    nu['T'] = 3;
    string DNA;
    cin >> T;
    struct Node *root = newNode();
    for(int i = 1; i <= T; i++){
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> DNA;
            addWord(root, DNA);
        }
        cout << "Case " << i << ": " << res << endl;
        res = 0;
        delete root;
        struct Node *root = newNode();
    }
}