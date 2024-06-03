#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Topic{
    int id;
    long long oldScore;
    long long newScore;
    long long diff;
};

struct compare{
bool operator()(const Topic &t1, const Topic &t2){
    if(t1.diff == t2.diff){
        return t1.id < t2.id;
    } else {
        return t1.diff < t2.diff;
    }
}
};

int main(){
    int n;
    cin >> n;
    Topic t;
    int p, l, c, s;
    priority_queue<Topic, vector<Topic>, compare> pq;
    for(int i = 0; i < n; i++){
        cin >> t.id >> t.oldScore;
        cin >> p >> l >> c >> s;
        t.newScore = 50*p + 5*l + 10*c + 20*s;
        t.diff = t.newScore - t.oldScore;
        pq.push(t);
    }
    for(int i = 0; i < 5; i++){
        cout << pq.top().id << " " << pq.top().newScore;
        pq.pop();
        cout << endl;
    }
}