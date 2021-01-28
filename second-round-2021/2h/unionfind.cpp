#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define rep(x) for(int i = 0; i<x; i++)
using namespace std;

vector<int> chefs;
int t, l, q;

int find(int a){
    if(a == chefs[a]){
        return a;
    }
    return find(chefs[a]);
}

void treaty(pair<int, int> parties){
    int a = find(parties.first);
    int b = find(parties.second);
    chefs[a] = b;
}

signed main(){
    cin >> t >> l >> q;
    vector<int> chefs = vector<int>(l);
    for (int i = 0; i < l; i++){
        chefs[i] = i + 1;
    }
    rep(q){
        int in;
        cin >> in;
        if (in == -1) {
            rep(chefs.size()){
                int j = find(i);
                cout << j << " ";
            }
            cout << endl;
        }
        else{
            int p2;
            cin >> p2;
            pair<int, int> parties = make_pair(in, p2);
            treaty(parties);
        }
    }
}