#include <iostream>
using namespace std;

struct Student{
    char id[7];
    char name[51];
    double score;
};

struct Node{
    Student data;
    Node* left;
    Node* right;
};

Node* createNode(Student x){
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

void add(Node *&root, Student x){
    if(x.score < root->data.score){
        if(root->left == NULL){
            Node *p = createNode(x);
            root->left = p;
        } else {
            add(root->left, x);
        }
    } else if (x.score > root->data.score){
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

void add(BST &t, Student x){
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

Student highestGrade(Node *curr){
    if(curr->right==NULL){
        return curr->data;
    } else {
        return highestGrade(curr->right);
    }
}

Student highestGrade(BST t){
    return highestGrade(t.root);
}

int main(){
    int n;
    cin >> n;
    BST t;
    init(t);
    for(int i = 0; i < n; i++){
        Student s;
        cin >> s.id;
        cin >> s.name;
        cin >> s.score;
        add(t, s);
    }
    cout << highestGrade(t).id << " " << highestGrade(t).name << " " << highestGrade(t).score;
}