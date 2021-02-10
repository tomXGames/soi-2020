#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long
#define rep(x) for(int i = 0; i<x; i++)
using namespace std;

vector<int> chefs_antike, visited;
vector< set<int> > chefs_modern;
int t, l, q;
bool modern;

int find_antike(int a){
    if(a == chefs_antike[a]){
        return a;
    }
    return chefs_antike[a] = find_antike(chefs_antike[a]);
}

set<int> find_modern(int a){
    set<int> s = chefs_modern[a];
    visited[a] = 1;
    for(int p : chefs_modern[a]){
        if(chefs_modern[a] != chefs_modern[p] && visited[p] != 1){
            set<int> other = find_modern(p);
            for(int a: other) s.insert(a);
        }
    }
    chefs_modern[a] = s;
    return chefs_modern[a];
}

void treaty_antike(pair<int, int> parties){
    int a = find_antike(parties.first);
    int b = find_antike(parties.second);
    chefs_antike[b] = a;
    for (int l = 0; l < chefs_antike.size(); l++){
        find_antike (l);
    }
}

void treaty_modern(pair<int, int> parties){
    int a = parties.first;
    int b = parties.second;
    chefs_modern[a].insert(b);
    chefs_modern[b].insert(a);
}

signed main(){
    cin >> t >> l >> q;
    modern = (t==0)? false: true;
    if(!modern) 
    {
        chefs_antike = vector<int>(l);
        for (int i = 0; i < l; i++){
            chefs_antike[i] = i;
        }
    }
    else 
    {
        chefs_modern = vector<set<int> > (l);
        for (int i = 0; i < l; i++){
            chefs_modern[i].insert(i);
        }  
    }
    for(int i = 0; i < q; i++){
        int in;
        cin >> in;
        if (in == -1) {
            if(!modern){
                for(int k = 0; k < chefs_antike.size(); k++){
                    cout << find_antike(k) + 1 << " ";
                }
            }
            else{
                for(int k = 0; k < chefs_modern.size(); k++){
                    visited = vector<int> (chefs_modern.size(), 0);
                    cout << *find_modern(k).begin() + 1 << " ";
                }
            }
            cout << endl;
        }
        else{
            int p2;
            cin >> p2;
            pair<int, int> parties = make_pair(in - 1, p2 -1);
            if(!modern) treaty_antike(parties);
            else treaty_modern(parties);
        }
    }
}