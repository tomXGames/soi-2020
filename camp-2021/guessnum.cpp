#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

signed main() {
    int left = 1, right = 1e6, iterations = 0; //both inclusive
    bool found = false;
    cout << (int)1e9;
    string answer;
    cin >> answer;
    if (answer == "=") {
        return 0;
    }
    cout << 1;
    cin >> answer;
    if (answer == "=") {
        return 0;
    }
    while (!found){
        int mid = left + (right-left)/2;
        cout << mid << "\n";
        string answer;
        cin >> answer;
        if(answer == "=") {
            return 0;
        }
        else if(answer == "<"){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
}
