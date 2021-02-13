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

vector<vector<pair<int, int> > > graph;
vector<int> currentroute;
int n, m;

int djikstra(){
    vector<int> distance(n, -1);
    priority_queue<pair<int, int>> pq;
    pq.emplace(make_pair(0, 0));
    distance[0] = 0;
    while (!pq.empty()){
        auto cur = pq.top();
        distance[cur.second] = cur.first;
        pq.pop();
        if(cur.second == n-1) return cur.first;
        for (auto neighbour : graph[cur.second]) pq.emplace(make_pair(neighbour.first+cur.first, neighbour.second));
    }
    return -1;
}


signed main() {
    cin >> n >> m;
    graph = vector<vector<pair<int, int> > >(n);
    rep(m){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }
    cout << djikstra();
}
