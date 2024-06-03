#include <iostream>
using namespace std;

struct Date{
    int ngay;
    int thang;
    int nam;
};

struct Node{
    Date data;
    Node *next;
};

struct LinkedList{
    Node *head;
    Node *tail;
};

Node* createNode(Date x);
Date ngayMoiNhat(LinkedList lst);

Node* createNode(Date x){
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

void init(LinkedList &lst){
    lst.head = NULL;
    lst.tail = NULL;
}

void insertTail(LinkedList &lst, Date x){
    Node *p = createNode(x);
    if(lst.head == NULL){
        lst.head = lst.tail = p;
    } else {
        lst.tail->next = p;
        lst.tail = p;
    }
}

Date ngayMoiNhat(LinkedList lst){
    Node *cur = lst.head;
    Date currentDate = cur->data;
    Date newest = lst.head->data;
    while(cur->next != NULL){
        if(currentDate.nam > newest.nam){
            newest = currentDate;
        } else if(currentDate.nam == newest.nam){
            if(currentDate.thang > newest.thang){
                newest = currentDate;
            } else if (currentDate.thang == newest.thang){
                if(currentDate.ngay > newest.ngay){
                    newest = currentDate;
                }
            }
        }
        cur = cur->next;
        currentDate = cur->data;
    }

    return newest;
}

int main(){
    LinkedList lst;
    init(lst);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        Date x;
        cin >> x.ngay;
        cin >> x.thang;
        cin >> x.nam;
        insertTail(lst, x);
    }
    Date result = ngayMoiNhat(lst);
    cout << result.ngay << " " << result.thang << " " << result.nam;
}