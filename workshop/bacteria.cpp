#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n;
    cin >> m;
    bool stoflococcus = true;
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i <n ; i++){
        if (adj[i].size() == 2 || adj[i].size() == 1) continue;
        else stoflococcus =false;
    }
    if (stoflococcus) cout << "stoflococcus";
    else cout << "other"; 
}