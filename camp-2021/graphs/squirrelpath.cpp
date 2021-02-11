
#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m, a, b, s, final;
vector<int> depth;
vector<bool> visited;
vector<vector<int> > adj;
vector<int> queue;
vector<string> type;
int smallestpathtotal = -1;

void bfs(int start){
    queue = vector<int>();
    depth = vector<int>(n);
    depth[start] = 0;
    queue.push_back(start);
    int distancetoroot = -1;
    int smallestdistancetohideout = -1;
    int smallestpath =-1;
    visited = vector<bool>(n, false);
    while(!queue.empty()){
        if(distancetoroot != -1 && smallestdistancetohideout != -1 && (smallestpath ==-1| smallestpath > distancetoroot+smallestdistancetohideout)) smallestpath > distancetoroot+smallestdistancetohideout; 
        int cur = queue.front();
        visited[cur] = true;
        for(int neighbour: adj[cur]){
            if(!visited[neighbour]) {
                depth[neighbour] = depth[cur] + 1;
                visited[neighbour] = true;
                if(neighbour == s && distancetoroot != -1) distancetoroot = depth[neighbour]; 
                else if(type[neighbour]=="hideout" && smallestdistancetohideout == -1 || smallestdistancetohideout > depth[neighbour]) smallestdistancetohideout = depth[neighbour]; 
                queue.push_back(neighbour);
            }
            else continue;
        }
        queue.erase(queue.begin());
    }
    if (smallestpathtotal > smallestpath || smallestpathtotal == -1) smallestpathtotal = smallestpath;
}

signed main(){
    cin >> n >> m >> a >> b >> s;
    adj = vector<vector<int> > (n);
    vector<int> trees = vector<int>();
    type = vector<string>(n);
    for (int i = 0; i < a; i++){
        int index;
        cin >> index;
        trees.push_back(index);
        type[index]= "tree";
    }
    for (int i = 0; i < b; i++){
        int index;
        cin >> index;
        type[index]= "hideout";
    }
    depth = vector<int> (n, -1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int tree: trees){
        bfs(tree);
    }
    cout << smallestpathtotal << endl;
}