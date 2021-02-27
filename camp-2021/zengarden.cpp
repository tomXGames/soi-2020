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
    ios_base::sync_with_stdio(false);	//Remove these lines 
    cin.tie(0);							//when interactive
    int n;
    cin >> n;
    if(n <= 4){
        cout << "Impossible" << "\n";
        return 0;
    }
    else{
        cout << 0 << " ";
        for(int i = n-1; i > 0; i -= 2){
            cout << i << " ";
        }
        for(int i = n-2; i > 0; i -= 2){
            cout << i << " ";
        }
    }
}
