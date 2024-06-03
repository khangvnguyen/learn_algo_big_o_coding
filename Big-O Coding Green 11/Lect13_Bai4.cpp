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
    int n;
    cin >> n;

    LinkedList lst;
    init(lst);
    int y;

    for(int i = 0; i < n; i++){
        cin >> y;
        insertTail(lst, y);
    }

    LinkedList result;
    init(result);
    insertTail(result, lst.head->data);

    Node *cur = lst.head;
    for(int i = 1; i < n; i++){
        insertTail(result, cur->data + cur->next->data);
        cur = cur->next;
    }
    
    cur = result.head;
    for(int i = 0; i < n; i++){
        cout << cur->data << " ";
        cur = cur->next;
    }
}