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

void insertTail(LinkedList &lst, int x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

void removeAfter(Node *prev, Node *cur){
    prev->next = cur->next;
    delete cur;
    cur = prev->next;
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
    int x;
    for(int i = 0; i < n; i++){
        cin >> x;
        insertTail(lst, x);
    }

    Node *prev = NULL;
    Node *cur = lst.head;

    while(cur->data%10 == 5 || cur->data%10 == -5){
        lst.head = cur->next;
        delete cur;
        cur = lst.head;
    }
    prev = cur;
    cur = cur->next;
    while(cur != NULL){
        if(cur->data%10 == 5 || cur->data%10 == -5){
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }

    cur = lst.head;
    while(cur != NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    removeAll(lst);
}