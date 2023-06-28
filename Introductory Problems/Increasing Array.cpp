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
// As you iterate through the array, you ensure that no element is less than
// the previous element. If it is, you add the difference to the count and
// make the current element equal to the previous element.
// -------------------------------------------------------------------------- //

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i,0,n) cin >> a[i];
    ll count = 0;
    rep(i,1,n)
        if (a[i] < a[i-1])
        {
            count += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    cout << count << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    //tc
    solve();
}