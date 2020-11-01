#include <iostream>
#include <vector>
#define int long long
using namespace std;

signed main(){
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int> > adj(n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool out = true;
    int center = -1;
    for(int i = 0; i < n; i ++){
        if (adj[i].size() == n-1) center = i;
    }
    if (center == -1) {
        cout << "other";
        return 0;
    }
    for(int i = 0; i < n; i ++){
        if (i != center){
            if(adj[i].size() == 1 && adj[i][0] == center){
                continue;
            }
            else out = false;
        }
    }
    if(out) cout << "star";
    else cout << "other";
}