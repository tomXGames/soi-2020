#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <fstream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

vector<vector<int> > graph;
vector<int> currentroute;
int n, m;

bool dfs(vector<bool>& currentsearchpath, vector<bool>& visited, int v, vector<int>& currentroute, int parent){
    currentsearchpath[v] = true;
    currentroute.push_back(v);
    visited[v] = true;
    for(auto neighbour: graph[v]){
        if(neighbour == parent) continue;
        if(currentsearchpath[neighbour] ){
            currentroute.push_back(neighbour);
            return true;
        }   //found cycle
        if(visited[neighbour])  //already visited, skip
            continue;
        if(dfs(currentsearchpath, visited, neighbour, currentroute, v)) //recursively check
            return true;
    }
    currentsearchpath[v] = false;
    currentroute.pop_back();
    return false;
}

bool findcycle(){       
    vector<bool> visited (n, false);
    vector<bool> currentsearchpath (n, false);
    rep(n){
        if(!visited[i]){
            currentroute = vector<int>();
            if(dfs(currentsearchpath, visited, i, currentroute, 0)) return true;
        } 
    }
    return false;
}

signed main() {
    cin >> n >> m;
    graph = vector<vector<int> >(n, vector<int>());
    rep(m){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool sol = findcycle();
    if(sol) {
        auto it = find(currentroute.begin(), currentroute.end(), currentroute.back());
        vector<int> cycle = vector<int>(currentroute.begin() + (it- currentroute.begin()), currentroute.end());
        cycle.pop_back();
        cout << cycle.size() << endl;
        for(int i: cycle){
            cout << i << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;
}