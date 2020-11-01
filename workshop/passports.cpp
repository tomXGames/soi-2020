#include <iostream>
#include <vector>
#include <set>
#define int long long
using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> passport1;
vector<int> passport2;
bool out = false;
void add_to_passport(int n, int depth){
    visited[n] = true;
    
    depth += 1;
    if (depth == 0) {
        depth = 1;
        passport1.push_back(n);
    }
    else{
        depth = 1;
        passport2.push_back(n);
    }        
    for (int i = 0; i < adj[n].size(); i++){
            
        add_to_passport(adj[n][i], depth);
    }
}
signed main(){
    int n, m;
    cin >> n;
    cin >> m;
    adj = vector<vector<int> > (n);
    visited = vector<bool>(m);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++){
        if(!visited[i]) add_to_passport(i, 0);
    }
    for (int i = 0; i < passport1.size(); i++){
        cout << passport1[i] << " ";
    }
    for (int i = 0; i < passport2.size(); i++){
        cout << passport2[i] << " ";
    }
}