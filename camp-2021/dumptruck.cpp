#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <set>
#include <math.h>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;


vector<vector<tuple<int, int, int> > > graph;
vector<int> currentroute;
int n, m,t, x, s;

int bfs(){
    vector<int> maxsand(n, -1);
    vector<tuple<int, int, int, set<int> > > queue;   //distance to node, node, maxsand, where it came from
    queue.push_back({0, s, 0, set<int>{0}});
    maxsand[0] = 0;
    while (!queue.empty()){
        auto [c,b , l, route] = queue[0];
        queue.erase(queue.begin());
        if(maxsand[b] <= l) maxsand[b] = l;
        route.insert(b);
        for (auto [nc, nb , nl] : graph[b]) if(c+nc<=x && route.find(nb) == route.end() && route.find(t) == route.end()) queue.push_back({nc+c, nb, min(l, nl), route});
    }
    return maxsand[t];
}


signed main() {
    cin >> n >> m >> x >> s >> t;
    graph = vector<vector<tuple<int, int, int> > >(n);
    rep(m){
        int a, b, c, l;
        cin >> a >> b >> c >> l;
        graph[a].push_back({c, b, l});
        graph[b].push_back({c, a, l});
    }
    int out =  bfs();
    if(out == -1) cout << "Impossible";
    else cout << out;
} 