#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m, counter;
vector<bool> visited;
vector<vector<int> > adj;

void search(int n){
    visited[n] = true;
    for (int j = 0; j < adj[n].size(); j++){
        if(!visited[adj[n][j]]){
            search(adj[n][j]);
        }
    }
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
    for (int i = 0; i < n; i ++){
        if (!visited[i]) {
            search(i);
            counter++;
        }
    }    
    cout << counter;
}