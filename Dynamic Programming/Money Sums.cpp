#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
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
// dp[i][j] represents whether sum i can be made using first j elements
// We can either include the jth element or not
// If we include the jth element, we need to check if sum i - a[j] can be made using first j - 1 elements
// If we don't include the jth element, we need to check if sum i can be made using first j - 1 elements
// -------------------------------------------------------------------------- //
 
void solve(){
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    int sum = 0;
    rep(i,0,n) sum += a[i];
    vvi dp(sum+1, vi(n+1, 0));
    rep(i,0,n+1) dp[0][i] = 1;
    rep(i,1,sum+1){
        rep(j,1,n+1){
            dp[i][j] = dp[i][j-1] | (i >= a[j-1] ? dp[i-a[j-1]][j-1] : 0);
        }
    }
    int ans = 0;
    rep(i,1,sum+1) ans += dp[i][n];
    cout<<ans<<endl;
    rep(i,1,sum+1){
        if(dp[i][n]) cout<<i<<" ";
    }
    cout<<endl;
}
 
int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}