#include <iostream>
#include <vector>
#define int long long
using namespace std;

vector<int> chache (1e5, -1);

int f (int n){
    if (n <= 1) return 1;
    if (chache[n] != -1) return chache[n];
    return chache[n] = f(n-1) + f(n-2);
}

signed main(){
    int n;
    cin >> n;
    cout << f(n);
}

