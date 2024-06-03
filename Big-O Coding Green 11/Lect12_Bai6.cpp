#include <iostream>
#include <cmath>
using namespace std;

struct Node{
    int data;
    Node *next;
};

struct LinkedList{
    Node *head;
    Node *tail;
};

Node* createNode(int x);

Node* createNode(int x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void init(LinkedList &lst){
    lst.head = NULL;
    lst.tail = NULL;
}

void insertHead(LinkedList &lst, int x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        p->next = lst.head;
        lst.head = p;
    }
}

void insertAfter(Node *x, int y){
    Node *p = createNode(y);
    p->next = x->next;
    x->next = p;
}

void insertTail(LinkedList &lst, int x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

void removeHead(LinkedList &lst){
    Node *cur = lst.head;
    if(cur != NULL){
        lst.head = lst.head->next;
        delete cur;
    }
}

void removeAfter(Node *prev, Node *cur){
    prev->next = cur->next;
    delete cur;
}

void removeAll(LinkedList &lst){
    while(lst.head != NULL){
        Node *cur = lst.head;
        lst.head = lst.head->next;
        delete cur;
    }
    lst.tail = NULL;
}

int main(){
    LinkedList lst;
    init(lst);
    int n;
    cin >> n;
    int x1, x2;
    for(int i = 0; i < n; i++){
        cin >> x1;
        if(x1 == 1){
            cin >> x2;
            insertTail(lst, x2);
        } else {
            removeHead(lst);
        }
    }
    Node *cur = lst.head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    removeAll(lst);
}