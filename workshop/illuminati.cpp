#include <iostream>
#include <vector>
#include <set>
#define int long long
using namespace std;

vector<vector<int> > adj;
bool out = false;
void add_to_passport(int n, int depth, int start){
    if (depth < 3){
        for (int i = 0; i < adj[n].size(); i++){
            add_to_passport(adj[n][i], depth+ 1, start);
        }
    }
    else{
        if(n == start && !out){
            out = true;
            cout << "Illuminati confirmed!";
        }
    }
}
signed main(){
    int n, m;
    cin >> n;
    cin >> m;
    adj = vector<vector<int> > (n);
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i ++){
        if(!out) add_to_passport(i, 0, i);
    }
    if(!out) cout << "That is too far fetched.";
}