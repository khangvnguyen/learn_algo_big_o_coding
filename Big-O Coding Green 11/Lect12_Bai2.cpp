#include <iostream>
using namespace std;

struct Node{
    double data;
    Node *next;
};

struct LinkedList{
    Node *head;
    Node *tail;
};

Node* createNode(double x);
Node* min(LinkedList lst);

Node* createNode(double x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void init(LinkedList &lst){
    lst.head = NULL;
    lst.tail = NULL;
}

void insertTail(LinkedList &lst, double x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

void printgradelessthan(LinkedList lst, double num){
    Node *cur = lst.head;
    while(cur != NULL){
        if(cur->data < num){
            cout << cur->data << endl;
        }
        cur = cur->next;
    }
}

int main(){
    LinkedList lst;
    init(lst);
    double x;
    cin >> x;
    while(x != -1){
        insertTail(lst, x);
        cin >> x;
    }
    printgradelessthan(lst, 5.0);
}