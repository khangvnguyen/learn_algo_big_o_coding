#include <iostream>
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

void insertTail(LinkedList &lst, int x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

Node* min(LinkedList lst){
    if(lst.head == NULL){
        return NULL;
    }
    Node *ans = lst.head;
    Node *cur = lst.head;
    while(cur != NULL){
        if(cur->data < ans->data){
            ans = cur;
        }
        cur = cur->next;
    }
    return ans;
}

int main(){
    LinkedList lst1, lst2;
    init(lst1);
    init(lst2);
    int value;
    cin >> value;
    while(value != -1){
        insertTail(lst, value);
        cin >> value;
    }
    cout << min(lst)->data;
}