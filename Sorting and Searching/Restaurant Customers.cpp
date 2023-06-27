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

// -------------------Issue with this code-------------------
// Tries to find the maximum number of intervals which overlap
// with the ith interval. However, it doesn't check if these
// intervals overlap among themselves.
// ----------------------------------------------------------

void solve(){
    int n;
    cin >> n;
    vii v(n);
    rep(i,0,n){
        cin >> v[i].ff >> v[i].ss;
    }
    sort(all(v));
    int count = 0, ans = 0, j = 0;
    rep(i,0,n){
        while (j < n && v[j].ss <= v[i].ss)
        {
            count++;
            j++;
        }
        ans = max(ans, count);
        count--;
    }
    cout << ans << endl;
}
 
int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}