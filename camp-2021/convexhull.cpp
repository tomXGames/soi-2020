#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

struct point{
    int x;
    int y;
};

int n;
point origin;

long long crossproduct(point a, point b){
  return a.x * b.y - a.y * b.x;
}

bool convex (point a, point b, point c){
  point vA = {b.x - a.x, b.y - a.y};
  point vB = {c.x - b.x, c.y - b.y};

  return crossproduct(vA, vB) > 0;
}

bool compareAngles(const point &a, const point &b){
    if(convex(origin, a, b)){
        return true;
    }                               // I don't know vector geometry, so I don't really know how this works :(
    if(convex(origin, b, a)){
        return false;
    }
    int distToA = abs(a.x - origin.x) + abs(a.y - origin.y);
    int distToB = abs(b.x - origin.x) + abs(b.y - origin.y);
    return distToA < distToB;
}

vector<point> convexhull(vector<point> points){
    if(n < 3){     //return the points if the size <= 3, because then all the points are part of the hull 
        return points;
    }
    
    // find the one most to the bottom left (smallest x and y)
    int index = 0;

    for(int i = 1; i < n; i++){
        if(make_pair(points[i].x, points[i].y)< make_pair(points[index].x, points[index].y)){
            index = i;
        }
    }
    // We now have the index of the point on the bottom left in the variable index
    swap(points[0], points[index]);     //Put the one on the lower left as the first index in the points vector
    origin = points[0];
    sort(points.begin(), points.end(), compareAngles);
    vector<point> stack;
    stack.push_back(points[0]);
    stack.push_back(points[1]);

    int pointer = 2;    //start the search at 2

    while (pointer < n){
        point a = stack[stack.size()-1];
        point b = stack[stack.size()-2];
        point c = points[pointer];

        if(convex(a, b, c)){    //Checking if the points are convex (knick nach aussen)
            stack.push_back(c);
            ++pointer;
        }
        else{
            //The middle point (b) is not part of the hull
            stack.pop_back();
            if(stack.size()< 2){
                stack.push_back(c);
                ++pointer;
            }
        }
    }

    //Checking if the last three points are colinear and if so removing the middle one

    point a = stack[stack.size()-1];
    point b = stack[stack.size()-2];
    point c = stack[0];
    if(!convex(a, b, c)){
        stack.pop_back();
    }
    return stack;
}

signed main() {
    ios_base::sync_with_stdio(false);	//Remove these lines 
    cin.tie(0);							//when interactive

    cin >> n;
    vector<point> points;
    rep(n){
        int x, y;
        cin >> x >> y;
        point newpoint;
        newpoint.x = x;
        newpoint.y = y;
        points.push_back(newpoint);
    }
    vector<point> hull = convexhull(points);
    for(point p: hull){
        cout << p.x << " " << p.y << "\n";
    }
}