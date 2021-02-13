#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <numeric>
#include <iostream>
#include <fstream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

signed main() {
    int n;
    cin >> n;
    vector<int> bottles;
    rep(n){
        int in;
        cin >> in;
        bottles.push_back(in);
    }
    vector<int> sol (n);
    sol[0] = bottles[0];
    sol[1] = max(bottles[0], bottles[1]);
    for(int i = 2; i < n; i++){
        sol[i] = max(sol[i-1], sol[i-2]+bottles[i]);
    }
    cout << sol[n-1] << "\n";

}