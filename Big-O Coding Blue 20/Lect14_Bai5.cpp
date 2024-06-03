#include <iostream>
#include <map>
#include <string>
/* B1: doc input
B2: xay dung prefix
B3: xay dung suffix dao nguoc Spanish
B4: xay dung mang count

suffixTraversal(root, level)
    if root == null:
        return
    for ch in root.child
        if level > 0:
            cnt[ch] += 1
        siffixTraversal(root.child[ch], level+1)

B5: Ta thay 
res + suffix.size() - duplicate

prefixTraversal(root, level, suffixSize, cnt)
    if root == null
        return 0
    ans = 0
    if level > 0:
        ans += suffixSize
    for ch in root.child:
        ans -= cnt[ch]
        ans += prefixTraversal(root, level+1, suffixSize, cnt)
    return ans
*/
using namespace std;

#define MAX 26
int res = 0;

struct Node{
    struct Node *child[MAX];
    int countWord;
    bool bottomNode;
};

struct Node *newNode(){
    struct Node node = new Node;
    node->countWord = 0;
    node->bottomNode = false;
    for(int i = 0; i < MAX; i++){
        node->child[i] = NULL;
    }
    return node;
};

void addWord(struct Node *root, string s){
    int ch;
    struct Node *temp = root;
    for(int i = 0; i < s.size(); i++){
        ch = s[i] - 'a';
        if(temp->child[ch] == NULL){
            temp->child[ch] = newNode();   
        }
        temp = temp->child[ch];
    }
    temp->countWord += 1;
    res++;
    temp->bottomNode = true;
}

void addSuffix(struct Node *root, string s){
    int ch;
    int index;
    string smallString;
    struct Node *temp = root;
    while(!temp->bottomNode){
        for(int i = 0; i < s.size(); i++){
            smallString = 
            ch = s[i] - 'a';
            if(temp->child[ch] == NULL){
                temp->child[ch] = newNode();   
            }
            temp = temp->child[ch];
        }
    }
}

int main(){
    int p, s;
    cin >> p >> s;
    string word;
    struct Node *root = newNode();
    while(p!= 0 && s != 0){
        for(int i = 0; i < p; i++){
            cin >> word;
            addWord(root, word);
        }
        for(int i = 0; i < s; i++){
            cin >> word;
            addSuffix(root, word);
        }
    }
}