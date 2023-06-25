#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
//#define int ll
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<vii> vvii;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

// ------------------------------ Explanation ------------------------------ //
// dp[i] represents number of ways to make sum i
// For each i, we check if the last coin picked was the jth coin and then add
// the number of ways to make the sum i - c[j]
// Base condition is dp[0] = 1
// -------------------------------------------------------------------------- //

void solve(){
    int n,x;
    cin >> n >> x;
    vi c(n);
    rep(i,0,n) cin >> c[i];

    vi dp(x+1);
    dp[0] = 1;
    rep(i,1,x+1)
        rep(j,0,n)
            if (i - c[j] >= 0) {
                dp[i] += dp[i-c[j]];
                dp[i] %= MOD;
            }
    cout << dp[x] << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}