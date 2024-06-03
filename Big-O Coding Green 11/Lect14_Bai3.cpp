#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int x){
    Node *p = new Node;
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct BST{
    Node * root;
};

void init(BST &t){
    t.root = NULL;
}

void add(Node *&root, int x){
    if(x < root->data){
        if(root->left == NULL){
            Node *p = createNode(x);
            root->left = p;
        } else {
            add(root->left, x);
        }
    } else if (x > root->data){
        if(root->right == NULL){
            Node *p = createNode(x);
            root->right = p;
        } else {
            add(root->right, x);
        }
    } else {
        // Do nothing
    }
}

void add(BST &t, int x){
    if(t.root == NULL){
        Node *p = createNode(x);
        t.root = p;
    } else {
        add(t.root, x);
    }
}

int max(int left, int right){
    if(left > right){
        return left;
    } else {
        return right;
    }
}

int getHeight(Node* root){
    int hL = 0;
    int hR = 0;
    if(root->left != NULL){
        hL = getHeight(root->left);
    }
    if(root->right != NULL){
        hR = getHeight(root->right);
    }
    return 1+max(hL, hR);
}

int getHeight(BST t){
    return getHeight(t.root);
}

int main(){
    int n;
    cin >> n;
    BST t;
    init(t);
    int value;
    for(int i = 0; i < n; i++){
        cin >> value;
        add(t, value);
    }
    cout << getHeight(t);
}