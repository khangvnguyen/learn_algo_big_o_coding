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
    int n, x;
    cin >> n >> x;

    LinkedList lst;
    init(lst);
    int y;
    for(int i = 0; i < n; i++){
        cin >> y;
        insertTail(lst, y);
    }
    Node *cur = lst.head;
    for(int i = 1; i < n+1; i++){
        if(cur->data == x){
            cout << i;
            return 0;
        }
        cur = cur->next;
    }
    cout << -1;
}