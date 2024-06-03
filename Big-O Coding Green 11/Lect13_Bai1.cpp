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

int main(){
    int x, y, n;
    cin >> x >> y >> n;

    LinkedList lst;
    init(lst);

    lst.head = createNode(x);
    lst.head->next = createNode(y);

    Node *cur = lst.head;
    for(int i = 0; i < n-2; i++){
        Node *nextNum = createNode((cur->data + cur->next->data)%1000007);
        cur->next->next = nextNum; 
        cur = cur->next;
    }

    cur = lst.head;
    for(int i = 0; i < n; i++){
        cout << cur->data << " ";
        cur = cur->next;
    }
}