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

void insertTail(LinkedList &lst, int x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

bool isPrime(int n){
    if (n < 2) {
        return false;
    }
    for (int i = 2; i < int(sqrt((double)n) + 1); i++){
        if (n%i == 0) {
            return false;   
        }
    }
    return true;
}

int countPrime(LinkedList lst){
    int count = 0;
    Node *cur = lst.head;
    while(cur != NULL){
        if(isPrime(cur->data)){
            count++;
        }
        cur = cur->next;
    }
    return count;
}

int main(){
    LinkedList lst;
    init(lst);
    int x;
    cin >> x;
    while(x != -1){
        insertTail(lst, x);
        cin >> x;
    }
    cout << countPrime(lst);
}