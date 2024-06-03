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
    Node *root;
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

int sumSmallerThan(Node *curr, int x){
    int sum = 0;
    if(curr->left != NULL && curr->right != NULL){
        sum = sum + sumSmallerThan(curr->left, x) + sumSmallerThan(curr->right, x);
    } else if(curr->left != NULL){
        sum = sum + sumSmallerThan(curr->left, x);
    } else if(curr->right != NULL){
        sum = sum + sumSmallerThan(curr->right, x);
    }
    if(curr->data < x){
        sum = sum + curr->data;
    }
    return sum;
}

int sumSmallerThan(BST t, int x){
    return sumSmallerThan(t.root, x);
}

int main(){
    int n, x;
    cin >> n >> x;
    BST t;
    init(t);
    int value;
    for(int i = 0; i < n; i++){
        cin >> value;
        add(t, value);
    }
    cout << sumSmallerThan(t,x);
}