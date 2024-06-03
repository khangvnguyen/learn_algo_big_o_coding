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

LinkedList intersect(LinkedList lst1, LinkedList lst2){
    LinkedList result;
    init(result);
    Node* curr1 = lst1.head;
    Node* curr2 = lst2.head;
    Node* curr_result = result.head;
    while(curr1 != NULL && curr2 != NULL){
        if(curr1->data > curr2->data){
            curr2 = curr2->next;
        } else if (curr1->data < curr2->data){
            curr1 = curr1->next;
        } else if(curr1->data == curr2->data){
            if(curr_result == NULL){
                insertTail(result, curr1->data);
                curr_result = result.head;
                curr1 = curr1->next;
                curr2 = curr2->next;
            } else if(curr1->data == curr_result->data){
                curr1 = curr1->next;
                curr2 = curr2->next;
            } else {
                insertTail(result, curr1->data);
                curr_result = result.tail;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }
    }
    return result;
}

int main(){
    LinkedList lst1, lst2;
    init(lst1);
    init(lst2);
    int value;
    cin >> value;
    while(value != -1){
        insertTail(lst1, value);
        cin >> value;
    }
    cin >> value;
    while(value != -1){
        insertTail(lst2, value);
        cin >> value;
    }
    LinkedList result;
    result = intersect(lst1, lst2);
    if(result.head == NULL){
        cout << "NO INTERSECTION";
        return 0;
    }
    Node *curr_result = result.head;
    while(curr_result != NULL){
        cout << curr_result->data << " ";
        curr_result = curr_result->next;
    }
}