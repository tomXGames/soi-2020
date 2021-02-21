#include <soi>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;


vector<vector<pair<int, int> > > graph;
vector<int> currentroute;
int n, m;

int djikstra(){
    vector<int> distance(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int,int> > > pq;
    pq.emplace(make_pair(0, 0));
    distance[0] = 0;
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(cur.second == n-1) return cur.first;
        distance[cur.second] = cur.first;
        for (auto neighbour : graph[cur.second]) if(distance[neighbour.second] == -1) pq.emplace(make_pair(neighbour.first+cur.first, neighbour.second));
    }
    return -1;
}


signed main() {
    cin >> n >> m;
    graph = vector<vector<pair<int, int> > >(n);
    rep(m){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back(make_pair(c, b-1));
        graph[b-1].push_back(make_pair(c, a-1));
    }
    int out =  djikstra();
    if(out == -1) cout << "Impossible";
    else cout << out;
} 