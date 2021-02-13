#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

const int INF = 1e18;

int n, m, a, b, s, final;
vector<int> depth;
vector<bool> visited;
vector<vector<int> > adj;
vector<int> queue;
vector<string> type;
int smallestpathtotal = INF;

void xmin(int& x, int val) {
  if (val < x)
    x = val;
}

void bfs(int start){
    queue = vector<int>();
    depth = vector<int>(n);
    depth[start] = 0;
    queue.push_back(start);
    int distancetoroot = INF;
    int smallestdistancetohideout = INF;
    int smallestpath = INF;
    visited = vector<bool>(n, false);
    bool necessary = true;
    if(type[s] == "treehideout"){
        necessary = false;
        smallestpath = 0;
    }
    if(type[start]=="hideout")
      xmin(smallestdistancetohideout, 0);
    if(type[start] =="treehideout")
      xmin(smallestdistancetohideout, 0);
    if(necessary){
        while(!queue.empty()){
            int cur = queue.front();
            visited[cur] = true;
            for(int neighbour: adj[cur]){
                if(!visited[neighbour]) {
                    depth[neighbour] = depth[cur] + 1;
                    visited[neighbour] = true;
                    if(neighbour == s)
                      distancetoroot = depth[neighbour]; 
                    if(type[neighbour]=="hideout")
                      xmin(smallestdistancetohideout, depth[neighbour]);
                    if(type[neighbour] =="treehideout")
                      xmin(smallestdistancetohideout, depth[neighbour]);
                    queue.push_back(neighbour);
                }
                else continue;
            }
            xmin(smallestpath, distancetoroot+smallestdistancetohideout);
            queue.erase(queue.begin());
        }
    }

    xmin(smallestpathtotal, smallestpath);
}

signed main(){
    cin >> n >> m >> a >> b >> s;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    adj = vector<vector<int> > (n);
    vector<int> trees = vector<int>();
    type = vector<string>(n);
    for (int i = 0; i < a; i++){
        int index;
        cin >> index;
        trees.push_back(index);
        type[index] += "tree";
    }
    for (int i = 0; i < b; i++){
        int index;
        cin >> index;
        type[index] += "hideout";
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int tree: trees){
        if(smallestpathtotal !=0) bfs(tree);
    }
    cout << smallestpathtotal << endl;
}