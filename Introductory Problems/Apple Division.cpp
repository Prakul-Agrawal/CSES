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

void min_diff(vll &p, int &n, ll &total, int pos, ll sum, ll &diff)
{
    if (pos == n)
    {
        diff = min(abs(total - 2 * sum), diff);
        return;
    }
    min_diff(p,n,total,pos+1,sum+p[pos],diff);
    min_diff(p,n,total,pos+1,sum,diff);
}

void solve(){
    int n; cin >> n;
    vll p(n);
    rep(i,0,n) cin >> p[i];
    ll total = accumulate(all(p),0LL);
    ll diff = total;
    min_diff(p,n,total,0,0LL,diff);
    cout << diff << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}