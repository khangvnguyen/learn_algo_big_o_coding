#include <iostream>
#include <queue>
#include <vector>

using namespace std;
vector<int> h;

void minHeapify(int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if(left < h.size() && h[left] < h[smallest]){
        smallest = left;
    }
    if(right < h.size() && h[right] < h[smallest]){
        smallest = right;
    }
    if(smallest != i){
        swap(h[i], h[smallest]);
        minHeapify(smallest);
    }
}

void push(int value){
    h.push_back(value);
    int i = h.size() - 1;
    while(i != 0 && h[(i-1)/2] > h[i]){
        swap(h[i], h[(i-1)/2]);
        i = (i-1)/2;
    }
}

void deleteNum(int s){
    int i = 0;
    int leafIndex = 0;
    for(i = 0; i < h.size(); i++){
        if(s == h[i]){
            break;
        }
    }
    h[i] = h[h.size()-1];
    h.pop_back();

    while(h[(i-1)/2] > h[i]){
        swap(h[i], h[(i-1)/2]);
        i = (i-1)/2;
    }
    minHeapify(i);
}

int main(){
    int q;
    cin >> q;
    int command;
    int v;
    for(int i = 0; i < q; i++){
        cin >> command;
        if(command == 1){
            cin >> v;
            push(v);
        } else if(command == 2){
            cin >> v;
            deleteNum(v);
        } else {
            cout << h[0] << endl;
        }
    }
}