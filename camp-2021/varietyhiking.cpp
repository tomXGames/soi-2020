#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <set>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

vector<vector<pair<int, int> > > graph;
vector<int> currentroute;
vector<vector<bool> > visited_dfs;
int n, m, k;

bool solve(){
    vector<pair<int, int> > q;
    vector<bool> visited(n, false), hikeable(n, false);
    hikeable[0] = true;
    q.push_back(make_pair(0, 2));
    while (!q.empty()){
        auto cur = q[0];
        q.erase(q.begin());
        hikeable[cur.first] = true;
        if(cur.first == n-1) return hikeable[cur.first];
        for(auto way: graph[cur.first]){
            if(way.second != cur.second) {
                if(way.first == n-1) return true;
                q.push_back(make_pair(way.first, way.second));
            }
        }
    }
    return hikeable[n-1];
}

bool dfs(int v, int type, int parent, int length){
    if(type==2){
        visited_dfs[v][0] = true;
        visited_dfs[v][1] = true;
        visited_dfs[v][2] = true;
    }
    else visited_dfs[v][type] = true;
    auto cur = graph[v];
    for(auto way: graph[v]){    //way.second = type; way.first = destination_node
        if(way.second != type && !visited_dfs[way.first][way.second] && way.first != parent) {
            if(dfs(way.first, way.second, v, length+1) || (way.first == n-1 && length >= 2)) 
                return true;
        }
    }
    return false;
}

signed main() {
    cin >> n >> m >>  k;
    graph = vector<vector<pair<int, int> > >(n);
    visited_dfs = vector<vector<bool>>(n, vector<bool> (3, false));
    rep(m){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 0));
        graph[b].push_back(make_pair(a, 0));
    }
    rep(k){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(make_pair(b, 1));
        graph[b].push_back(make_pair(a, 1));
    }
    bool hikeable = false;
    if(n>= 3){
        if(dfs(0, 2, 0, 0)) hikeable = true;
    }
    else if(n == 0) hikeable = false;
    else hikeable = true;

    if(hikeable) cout<< "Time to hike!" << endl;
    else cout << "Never mind." << endl;
}
