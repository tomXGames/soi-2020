#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <tuple>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

vector<vector<tuple<int, int, int> > > graph;
int n;
vector<pair<int, int> > nodes;


int mst(){
    int sum = 0;
    int time = 0;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;
    vector<bool> visited (n+1, false);
    pq.emplace(tuple<int, int, int> {0,0, 0});
    while (!pq.empty()){
        auto [cost, node, distance] = pq.top();
        pq.pop();
        if(visited[node]){
            continue;
        }
        visited[node] = true;
        time += distance;
        sum += time * nodes[node].second;
        pq = priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > >();
        for(auto [ncost, neighbour, ndistance]: graph[node]){
            if(!visited[neighbour]){
                pq.emplace(tuple<int, int, int> {ncost + time, neighbour, ndistance});
            }
        }
    }
    return sum;
}

signed main() {
    ios_base::sync_with_stdio(false);	
    cin.tie(0);							
    cin >> n;
    graph = vector<vector<tuple<int, int, int> > >(n+1);
    nodes.push_back(make_pair(0,0));
    rep(n){
        int a, b;
        cin >> a >> b ;
        nodes.push_back(make_pair(a,b));
    }
    for(int i = 0; i < nodes.size(); i++){
        auto [d_house, no_dvds] = nodes[i];
        for(int j = 0; j < nodes.size(); j++){
            auto [o_d_house, o_no_dvds] = nodes[j];
            if(i != j && j != 0){
                int cost = abs(d_house-o_d_house) * o_no_dvds;
                int dis = abs(d_house-o_d_house);
                graph[i].push_back(tuple<int, int, int> {cost, j, dis});
            }
        }
    }
    int result = mst();
    cout << result;
}
