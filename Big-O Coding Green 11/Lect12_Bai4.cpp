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
Node* min(LinkedList lst);

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

void insertOrderNumber(LinkedList &lst){
    int order = 1;
    insertHead(lst, order);
    Node *cur = lst.head->next;
    order++;
    while(cur->next != NULL){
        insertAfter(cur, order);
        cur = cur->next->next;
        order++;
    }
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
    int x;
    cin >> x;
    while(x != 0){
        insertTail(lst, x);
        cin >> x;
    }
    insertOrderNumber(lst);
    Node *cur = lst.head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    removeAll(lst);
}