#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m, counter;
vector<bool> visited;
vector<vector<int> > adj;

bool search(int n, vector<int> route){
    visited[n] = true;
    bool out;
    for (int j = 0; j < adj[n].size(); j++){
        auto it = find(route.begin(), route.end(), adj[n][j]);
        if(it != route.end()){
            int index = it - route.begin();
            out = ((route.size()-index)%2 != 0) ? false : true;
        }
        if(!visited[adj[n][j]]){
            route.push_back(adj[n][j]);
            out = search(adj[n][j], route);
        }
    }
    return out;
}

signed main(){
    cin >> n;
    cin >> m;
    adj = vector<vector<int> > (n);
    visited = vector<bool> (n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bool out = true;
    for (int i = 0; i < n; i ++){
        if (!visited[i]) {
            vector<int> route (1, i);
            if(search(i, route) == false) out = false;
        }
    }    
    if(out) cout << "YES";
    else cout << "NO";
}