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
// dp[i][j] represents minimum number of cuts required to cut a rectangle of dimensions 
// i * j into squares
// We can either cut horizontally or vertically
// If we cut vertically, we need to check if we can cut the rectangle of dimensions
// i * j into rectangles of dimensions i * k and i * (j - k) where k ranges from 1 to j/2
// If we cut horizontally, we need to check if we can cut the rectangle of dimensions
// i * j into rectangles of dimensions k * j and (i - k) * j where k ranges from 1 to i/2
// For i * j, where i = j, we don't need to cut
// -------------------------------------------------------------------------- //

void solve(){
    int a, b;
    cin >> a >> b;
    vvi dp(a+1, vi(b+1, 0));
    rep(i,1,a+1) dp[i][1] = i-1;
    rep(i,1,b+1) dp[1][i] = i-1;
    rep(i,2,a+1){
        rep(j,2,b+1){
            if(i == j) dp[i][j] = 0;
            else{
                int ans = INT_MAX;
                rep(k,1,i/2+1){
                    ans = min(ans, 1 + dp[k][j] + dp[i-k][j]);
                }
                rep(k,1,j/2+1){
                    ans = min(ans, 1 + dp[i][k] + dp[i][j-k]);
                }
                dp[i][j] = ans;
            }
        }
    }
    cout << dp[a][b] << endl;
}
 
int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}