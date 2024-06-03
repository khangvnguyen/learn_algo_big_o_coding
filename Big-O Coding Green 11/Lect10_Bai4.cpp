#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point{
    int x;
    int y;
};

struct Triangle{
    Point p1;
    Point p2;
    Point p3;
};

double distance(Point p1, Point p2);
double halfPerimeter(Triangle t);
double area(Triangle t);

double distance(Point p1, Point p2){
    return sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2));
}

double halfPerimeter(Triangle t){
    return (distance(t.p1,t.p2)+distance(t.p1,t.p3)+distance(t.p2,t.p3))/2;
}

double area(Triangle t){
    return sqrt(halfPerimeter(t)*(halfPerimeter(t)-distance(t.p1,t.p2))*(halfPerimeter(t)-distance(t.p1,t.p3))*(halfPerimeter(t)-distance(t.p2,t.p3)));
}


int main(){
    int n;
    cin >> n;

    Triangle T[n+1];

    for(int i = 0; i < n; i++){
        cin >> T[i].p1.x >> T[i].p1.y;
        cin >> T[i].p2.x >> T[i].p2.y;
        cin >> T[i].p3.x >> T[i].p3.y;
    }

    double sumArea = 0;
    for(int i = 0; i < n; i++){
        sumArea += area(T[i]);
    }
    cout << fixed;
    cout << setprecision(2) << sumArea;
}