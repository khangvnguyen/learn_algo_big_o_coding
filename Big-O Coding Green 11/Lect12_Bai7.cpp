#include <iostream>
#include <cmath>
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

Node* secondMax(LinkedList lst){
    Node *null_result = createNode(-1);
    if(lst.head == NULL){
        return null_result;
    }
    if(lst.head->next == NULL){
        return null_result;
    }
    
    Node *cur = lst.head->next;
    Node *max;
    Node *secondmax = createNode(-1);

    if(lst.head->data > lst.head->next->data){
        max = createNode(lst.head->data);
        secondmax = createNode(lst.head->next->data);
    } else if(lst.head->data < lst.head->next->data){
        secondmax = createNode(lst.head->data);
        max = createNode(lst.head->next->data);
    } else {
        max = createNode(lst.head->data);
    }
    cur = cur->next;
    while(cur != NULL){
        if(cur->data != max->data){
            if(cur->data > max->data){
                secondmax = max;
                max = cur;
            } else {
                if(cur->data > secondmax->data){
                    secondmax = cur;
                }
            }
        }
        cur = cur->next;
    }
    return secondmax;
}

int main(){
    LinkedList lst;
    init(lst);
    double x1;
    cin >> x1;
    while(x1 != -1){
        insertTail(lst, x1);
        cin >> x1;
    }

    cout << secondMax(lst)->data;

    removeAll(lst);
}