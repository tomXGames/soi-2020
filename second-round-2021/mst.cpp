#include <soi>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;


vector<vector<pair<int, int> > > graph;
vector<int> currentroute;
int n, m;

int mst(){
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>> pq;
    pq.emplace(make_pair(0, 0));
    int min = 0;
    while (!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(visited[cur.second]) continue;
        min += -cur.first;
        for (auto neighbour : graph[cur.second]) if(!visited[neighbour.second]) pq.emplace(make_pair(-neighbour.first, neighbour.second));
        visited[cur.second] = true;
    }
    return min;
}


signed main() {
    cin >> n >> m;
    graph = vector<vector<pair<int, int> > >(n);
    int totalweight = 0;
    rep(m){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back(make_pair(c, b-1));
        graph[b-1].push_back(make_pair(c, a-1));
        totalweight += c;
    }
    int out =  mst();
    print(totalweight - out);
} 