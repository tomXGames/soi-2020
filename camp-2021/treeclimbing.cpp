#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;
    int maxheight = 0;
    vector<int> trees (n);
    rep(n){
        int in;
        cin >> in;
        trees[i] = in;
        maxheight = max(in, maxheight);
    }
    rep(m){
        string type;
        cin >> type;
        if (type == "C"){
            int index, h;
            cin >> index >> h;
            if(h > maxheight){
                cout << "Too high!" << "\n";
                continue;
            }
            else{
                int min_distance = n;
                bool ran = false;
                for(int j= 0; j< trees.size(); j++){
                    ran = true;
                    if(trees[j]>=h){
                        min_distance = min(abs(index-j), min_distance);
                    }
                    if(abs(index-j) > min_distance) break;
                }
                if(ran) cout << abs(min_distance) << "\n";
                else cout << "Too High!";
            }
        }
        else{
            int x, y;
            cin >> x >> y;
            trees[x] = y;
            maxheight = max(y, maxheight);
        }
    }
}
