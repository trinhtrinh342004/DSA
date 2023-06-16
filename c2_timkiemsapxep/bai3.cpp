#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct Point {
    float x,y;
};

float calDistance(Point Q, Point P){
    float distance = sqrt((P.x-Q.x)*(P.x-Q.x) + (P.y-Q.y)*(P.y-Q.y));
    return distance;
}

void inputPoint(Point & P){
    cin >> P.x;
    cin >> P.y;
}

void inputPointArr(vector<Point> & pointArr, int n){
    pointArr.resize(n);
    for (auto ptr = pointArr.begin(); ptr < pointArr.end(); ptr++){
        inputPoint(*ptr);
    }
}

int getNearestPoint(vector <Point> & pointArr, Point & Q ){
    float minDistance = calDistance(pointArr[0], Q);
    vector<Point>::iterator pointPtr = pointArr.begin();
    for ( auto ptr = pointArr.begin() + 1; ptr < pointArr.end(); ptr ++){
        float distance = calDistance(*ptr, Q);
        if (distance < minDistance){
            minDistance = distance;
            pointPtr = ptr;
        }
    }
    auto vitri = pointPtr - pointArr.begin();
    return int(vitri);
}

int main(){
    int n;
    cin >> n;
    Point P;
    vector<Point> pointArr;
    inputPointArr(pointArr, n);
    auto nearestPoint = getNearestPoint(pointArr, P);
    cout << "The nearest point is at index " << nearestPoint << endl;
    return 0;
}
