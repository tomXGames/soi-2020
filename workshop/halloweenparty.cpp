#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m;
vector<bool> visited;
vector<vector<int> > adj;

int dfs(int n, int depth){
    int curmax;
    for (int w: adj[n]){
        curmax = max(dfs(w, depth+1), curmax);
    }
    return curmax;
}

signed main(){
    adj = vector<vector<int> > (n);
    for (int i = 0; i < m; i++){
        int n;
        for (int m = 1; m <= n; m++) {
            int boss;
            cin >> boss;
            adj[m].push_back(boss);
            adj[boss].push_back(m);
        }
    }
    // for (vector<int> m : adj){
    //     for (int n: m) cout << n << " ";
    //     cout << "\n";
    // }
    cout << dfs(0, 0);
}