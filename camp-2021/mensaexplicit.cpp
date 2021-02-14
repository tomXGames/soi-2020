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
    vector<vector<bool> > sol (n+1, vector<bool>(m+1, false));
    sol[0][0] = true;
    for(int c_i = 1; c_i <= n; c_i++){
        for(int i = 0; i <= m; i++){
            bool b1 =(i-coins[c_i-1] >= 0)? sol[c_i-1][i-coins[c_i-1]]: false;
            bool b2 =sol[c_i-1][i];
            sol[c_i][i] = b1 || b2;        
        }
    }
    if(!sol[n][m]) cout << "NO" << endl;
    else cout << "YES" << endl;
} 