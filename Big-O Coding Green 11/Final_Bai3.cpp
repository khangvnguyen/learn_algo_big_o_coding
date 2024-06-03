#include <iostream>
using namespace std;

struct Light{
    bool l;
    bool s;
    bool r;
    bool p;
};

int main(){
    Light l1, l2, l3, l4;
    cin >> l1.l >> l1.s >> l1.r >> l1.p;
    cin >> l2.l >> l2.s >> l2.r >> l2.p;
    cin >> l3.l >> l3.s >> l3.r >> l3.p;
    cin >> l4.l >> l4.s >> l4.r >> l4.p;

    if(l1.p){
        if(l1.l || l1.s || l1.r || l2.l || l3.s || l4.r){
            cout << "YES";
            return 0;
        }
    }
    if(l2.p){
        if(l2.l || l2.s || l2.r || l1.r || l3.l || l4.s){
            cout << "YES";
            return 0;
        }
    }
    if(l3.p){
        if(l3.l || l3.s || l3.r || l1.s || l2.r || l4.l){
            cout << "YES";
            return 0;
        }
    }
    if(l4.p){
        if(l4.l || l4.s || l4.r || l1.l || l2.s || l3.r){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}