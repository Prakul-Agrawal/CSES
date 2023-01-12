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

void solve(){
    int n; cin >> n;
    if (n % 4 == 0 || n % 4 == 3)
    {
        cout << "YES" << endl;
        ll temp = (ll) n * (n+1) / 4;
        vi x,y;
        for(int i = n; i > 0; --i)
        {
            if (temp >= i)
            {
                temp -= i;
                x.pb(i);
            }
            else y.pb(i);
        }
        cout << x.size() << endl;
        for (auto i: x) cout << i << ' ';
        cout << endl << y.size() << endl;
        for (auto i: y) cout << i << ' ';
        cout << endl;
    }
    else cout << "NO" << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}