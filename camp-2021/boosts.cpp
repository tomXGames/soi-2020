#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#include <fstream>
#include <functional>
#include <set>
#include <numeric>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

vector<vector<pair<int, int> > > graph;
vector<int> currentroute;
int n, m, k, s, g;

int djikstra(){
    vector<vector<int> > distance(n, vector<int> (k +1, -1));
    priority_queue< vector<int>, vector<vector<int>>, greater<vector<int> > > pq;
    vector< vector<bool>> visited (n, vector<bool>(k +1, false));
    pq.emplace(vector<int> {0, s, k});
    distance[0][0] = 0;
    for(int i = 0; i <= k; i ++){
        visited[0][i] = true;
        distance[0][i] = 0;
    }
    while (!pq.empty()){
        auto cur = pq.top();    //cur[0]  = distance to start, cur[1] = 
        pq.pop();
        distance[cur[1]][cur[2]] = (distance[cur[1]][cur[2]] == -1)?  cur[0]: distance[cur[1]][cur[2]];
        for (auto neighbour : graph[cur[1]]){
            if(!visited[neighbour.first][cur[2]]) {
                if(cur[2] > 0) pq.emplace(vector<int> {neighbour.second + cur[0], neighbour.first, cur[2]-1});
                pq.emplace(vector<int> {(neighbour.second*2) + cur[0], neighbour.first, cur[2]}); 
            } 
        }
        visited[cur[1]][cur[2]] = true;
    }
    return *min_element(distance[g].begin(), distance[g].end());
}



signed main() {
    cin >> n >> m >>  k >> s >> g;
    graph = vector<vector<pair<int, int> > >(n);
    rep(m){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    auto gotback = djikstra();
    cout << gotback << endl;
}


// Bidirectional search could be helpful. I don't know how to implement it.
//tried dfs, not working