#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m, counter;
bool out = true, outputted = false;
vector<bool> visited, color;
vector<vector<int> > adj;


void search(int n){
    visited[n] = true;
    for (int j : adj[n]){
        if(!visited[j]){
            color[j] = !color[n];
            search(j);
        }
        if(color[j] == color[n]) out = false;
    }
}


signed main(){
    cin >> n;
    cin >> m;
    adj = vector<vector<int> > (n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    color = vector<bool> (n, true), visited = vector<bool> (n);
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            search(i);
        }
    }    
    if(out) cout << "YES";
    else cout << "NO";
}