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
 
void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> parent(n+1);
    vector<int> size(n+1, 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }
    function<int(int)> find = [&](int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    };
    function<void(int, int)> merge = [&](int a, int b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    };

    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }

    set <int> s;
    rep(i, 1, n+1){
        s.insert(find(i));
    }
    cout << sz(s) - 1 << endl;
    
    vi final;
    for(auto i : s){
        final.pb(i);
    }

    rep(i, 0, sz(final)-1){
        cout << final[i] << " " << final[i+1] << endl;
    }
}
 
int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}