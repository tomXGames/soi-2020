#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <numeric>
#include <iostream>
#include <fstream>
#define int long long
using namespace std;

vector<int> mice;
struct segtree
{
    vector<int> data;
    int n;
    segtree(vector<int> v): 
    data(4*v.size())
    {
        n = v.size();
        for(int i = 0; i < n; i++){
            set_index(i, 1, v[i], 0, n);
        }
    }

    void update(int i){
        data[i] = (data[2*i] + data[2*i+1]);
    }
    
    void set_index(int i, int x, int v, int left, int right){
        if(right-left == 1) data[x] += v * mice[i];
        else{
            int mid = (left+right)/2;
            if(i < mid) set_index(i, 2*x, v, left, mid);
            else set_index(i, (2*x)+1, v, mid, right);
            update(x);
        }
    }

    int get(int beg, int ed, int x, int left, int right){    
        //complete
        if(beg <= left && right <= ed) return data[x];
        //none
        if(right <= beg || ed <= left) return 0; 
        //partial
        int mid = (left+right)/2;
        return (get(beg, ed, 2*x, left, mid)+ get(beg, ed, 2*x+1, mid, right));
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> trophies(n, 0);
    for(int i = 0; i < n; i++){
        int in;
        cin >> in;
        mice.push_back(in);
    }
    segtree t(trophies);
    for(int i = 0; i < m; i++){
        string querytype;
        cin >> querytype;
        if(querytype == "B"){
            int l, r;
            cin >> l >> r;
            int max = t.get(l,r+1, 1, 0, n);
            cout << max << "\n";
        }
        else {
            int a;
            cin >> a;
            t.set_index(a, 1, 1, 0, n);
        }
    }
}