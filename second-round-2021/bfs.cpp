#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int n, m;
vector<int> depth;
vector<vector<int> > adj;
vector<int> queue;

signed main(){
    cin >> n;
    cin >> m;
    adj = vector<vector<int> > (n);
    depth = vector<int> (n, -1);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int start = 0, end = n-1;
    depth[start]= 0;
    queue.push_back(start);
    while (!queue.empty()){
        int cur = queue[0];
        for(int w: adj[cur]){
            if(depth[w] == -1){
                depth[w] = depth[cur] + 1;
                queue.push_back(w);
            }
            else continue;
        }
        queue.erase(queue.begin());
    }   
    cout << depth[end] << endl;
}