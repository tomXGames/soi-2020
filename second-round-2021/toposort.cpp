#include <soi>
#define rep(x) for(int i = 0; i < x; i++)
using namespace std;

bool dfs(const vector<vector<int> >& graph, vector<int>& order, vector<bool>& visited, vector<bool>& currentsearchpath, int v){
    visited[v] = true;
    currentsearchpath[v] = true;
    for(int next: graph[v]){
        if(currentsearchpath[next])
            return true;
        if(visited[next])
            continue;
        if(dfs(graph, order, visited, currentsearchpath, next))
            return true;
    }
    order.push_back(v);
    currentsearchpath[v] = false;
    return false;
}

vector<int> toposort(const vector<vector<int> >& graph){
    int n = graph.size();
    vector<int> order;
    vector<bool> visited (n, false), currentsearchpath (n, false) ;
    rep(n){
        if(visited[i])
            continue;
        else if (dfs(graph, order, visited, currentsearchpath, i))
            return vector<int>();
    }
    return order;
}

signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > graph (n);

    rep(m){
        int a, b;
        cin >> a >> b;
        graph[b].push_back(a);
    }

    vector<int> order = toposort(graph);
    if(n != 0 && order.size() <= 0)
        cout<< "IMPOSSIBLE";
    else{
        cout << "POSSIBLE"<< "\n";
        for(int i: order) cout << i << " ";
        cout << "\n";
    }
}
