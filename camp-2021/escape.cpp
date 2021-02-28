#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
#define int long long
using namespace std;

vector<vector<pair<int, int> > > graph;
vector<pair<bool, int> > exits;
int n, m, e, q;

signed main() {
    ios_base::sync_with_stdio(false);	//Remove these lines 
    cin.tie(0);							//when interactive
    cin >> n >> m >> e >> q;
    graph = vector<vector<pair<int, int> > >(n);
    exits = vector<pair<bool, int> > (n, {false, 1e9});
    rep(m){
        int a, b, l;
        cin >> a >> b  >> l;
        graph[a].push_back(make_pair(b, l));
        graph[b].push_back(make_pair(a, l));
    }
    rep(e){
        int ei, pi;
        cin >> ei >> pi;
        exits[ei] = {true, min(exits[ei].second, pi)};
    }
    rep(q){
        int c, r;
        cin >> c >> r;
        bool possible = false;
        int mincost = 1e18;
        vector<bool> visited(n, false);
        vector<int > q;
        q.push_back(c);
        while (!q.empty()){
            auto current = q[0];
            q.erase(q.begin());
            visited[current] = true;
            if(exits[current].first){
                possible = true;
                mincost = min(mincost, exits[current].second);
            }
            for(auto [cell, level_required]: graph[current]){
                if(!visited[cell] && level_required <= r){
                    q.push_back(cell);
                }
            }
        }
        if(possible) cout << mincost << "\n";
        else cout << "IMPOSSIBLE\n";
    }
}