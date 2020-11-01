#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m, counter;
vector<bool> visited;
vector<int> values;
vector<vector<int> > adj;
vector<int> possiblevalues;
int currentval = 0;
void search(int n){
    visited[n] = true;
    currentval += values[n];
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
    values = vector<int> (n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i ++){
        if (!visited[i]) {
            search(i);
            possiblevalues.push_back(currentval);
            currentval = 0;
        }
    }    
    cout << *max_element(possiblevalues.begin(), possiblevalues.end());
}