#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
    
int w, h, n, counter;
vector<vector<int> > matrix;


pair<int, int> binarysearch(int l, int r, int o,int u, int x){
    if(l<= r && (o <= u || h == 1)){
        int midx = l+ (r-l) /2;
        int midy = o+(u-o)/2;
        midy = (h == 1)? 0: midy;
        midx = (w == 1)? 0: midx;
        int num;
        // cout << "q " << midx <<" "<< midy << endl;
        // cin >> num;
        num = matrix[midy][midx];
        if(num == x){
            return make_pair(midx, midy);
        }
        else if(num < x){
            return binarysearch(l, midx-1, midy+1, u,  x);
        }
        else if(num > x){
            return binarysearch(midx+1, r, o, midy-1, x);
        }
    }
    else{
        return make_pair(-1, -1);
    }
}


signed main(){
    cin >> w >> h >> n;
    matrix = vector<vector<int> > (h, vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            int in;
            cin >> in;
            matrix[i][j] = in;
        }
    }
    pair<int, int> solution = binarysearch(0, w-1, 0, h-1, 1337);
    pair <int, int> impossible = make_pair(-1, -1);
    if(solution == impossible){
        cout << "no solution";
    }
    else{
        cout << "s " << solution.first << " " << solution.second << endl;
    }
}