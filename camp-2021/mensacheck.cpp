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
    int n, m;
    cin >> n >> m;
    vector<int> coins;
    rep(n){
        int in;
        cin >> in;
        coins.push_back(in);
    }
    vector<vector<bool> > sol (n, vector<bool>(m, false));

    for(int c_i = 0; c_i < n; c_i++){
        for(int i = 0; i < m; i++){
            if(i == 0) sol[c_i][i] = true;
            else if (m > i>= 0) {
                bool b1 =(c_i-1 >= 0 && i-coins[c_i] >= 0)? sol[c_i-1][i-coins[c_i]]: false;
                bool b2 =(c_i-1 >= 0)? sol[c_i-1][i]: false;
                sol[c_i][i] = b1 || b2;
            }
        }
    }
    if(!sol[n-1][m-1]) cout << "NO" << endl;
    else cout << "YES" << endl;
} 