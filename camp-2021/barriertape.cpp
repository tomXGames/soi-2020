#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#include <iostream>
#define rep(x) for(int i = 0; i <x; i++)
using namespace std;
vector<vector<int> > pos;
int n;
void possibilities(int height){
    int path = 1;
    for(int i = height; i <(height+n-1); i++){
        path *= i;
        path /= (i-n+1);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);	 
    cin.tie(0);							
    cin >> n;
    pos = vector<vector<int> > (n, vector<int>(3, -1));
}
    