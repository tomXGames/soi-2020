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

struct segtree
{
    vector<int> data;
    int n;
    segtree(vector<int> v): 
    data(4*v.size())
    {
        n = v.size();
        for(int i = 0; i < n; i++){
            set(i,v[i]);
        }
    }
    private:
    void update(int i){
        data[i] = max(data[2*i], data[2*i+1]);
    }
    
    void set(int i, int x, int v, int left, int right){
        if(left+1 == right) data[x] = v;
        else{
            int mid = (left+right)/2;
            if(i < mid) set(i, 2*x, v, left, mid);
            else set(i, 2*x+1, v, mid, right);
            update(x);
        }
    }

    int get(int beg, int ed, int x, int left, int right){    
        //complete
        if(beg<=left && right <= ed) return data[x];
        //none
        if(right <= beg || ed <= left) return -1e18; 
        //partial
        int mid = (left+right)/2;
        return max(get(beg, ed, 2*x, left, mid), get(beg, ed, 2*x+1, mid, right));
    }
    public:
    void set(int i, int v) {
        set(i, 1, v, 0, n);
    }
    int get(int l, int r){
        return get(l, r, 1, 0, n);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> nums;
    for(int i = 0; i < n; i++){
        int in;
        cin >> in;
        nums.push_back(in);
    }
    segtree t(nums);
    for(int i = 0; i < m; i++){
        string querytype;
        cin >> querytype;
        if(querytype == "max"){
            int l, r;
            cin >> l >> r;
            int max = t.get(l,r+1);
            cout << max << "\n";
        }
        else {
            int a, b;
            cin >> a >> b;
            t.set(a, b);
        }
    }
}