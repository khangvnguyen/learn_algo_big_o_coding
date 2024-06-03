#include <iostream>
#include <cmath>
using namespace std;

struct Point{
    int x;
    int y;
};

double distance(Point p1, Point p2);

double distance(Point p1, Point p2){
    return sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
}

int main(){
    Point M;
    cin >> M.x >> M.y;

    int n;
    cin >> n;

    Point P[1001];

    for(int i = 0; i < n; i++){
        cin >> P[i].x >> P[i].y;
    }

    double distance_list[1001];
    for(int i = 0; i < n; i++){
        distance_list[i] = distance(M, P[i]);
    }

    double maxDistance = 0.0;
    int indexOfMaxDistance;
    for(int i = 0; i < n; i++){
        if(maxDistance < distance_list[i]){
            maxDistance = distance_list[i];
            indexOfMaxDistance = i;
        }
    }

    cout << P[indexOfMaxDistance].x << " " << P[indexOfMaxDistance].y;
}