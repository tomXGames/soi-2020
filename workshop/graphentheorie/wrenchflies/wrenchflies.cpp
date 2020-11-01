#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    int n, m, count;
    cin >> n;
    cin >> m;
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++){
        if (adj[i].size()== 2){
            if (adj[adj[i][0]].size() == 1 && adj[adj[i][1]].size() == 1) count++;
        }
    }
    cout << count << "\n";
}