#include <iostream>
using namespace std;

struct Room{
    char id[7];
    int price;
    bool available;
};

struct Node{
    Room data;
    Node *next;
};

struct LinkedList{
    Node *head;
    Node *tail;
};

Node* createNode(Room x);

Node* createNode(Room x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void init(LinkedList &lst){
    lst.head = NULL;
    lst.tail = NULL;
}

void insertTail(LinkedList &lst, Room x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

int main(){
    LinkedList lst;
    init(lst);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        Room x;
        cin >> x.id;
        cin >> x.price;
        cin >> x.available;
        insertTail(lst, x);
    }
    
    Node *cur = lst.head;
    while(cur != NULL){
        if(cur->data.available == 0){
            cout << cur->data.id << " " << cur->data.price << endl;
        }
        cur = cur->next;
    }
}