//
// Created by Prakul Agrawal on 6/13/24.
//

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector <ll> vll;
typedef vector <vi> vvi;
typedef vector <pii> vii;
typedef vector <vii> vvii;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)(x).size()
#define tc int t; cin>>t; while(t--)
#define printcase int t; cin>>t; for(int i=1;i<=t;i++){cout<<"Case #"<<i<<": ";solve();}
#define max_heap(x) priority_queue<x>
#define min_heap(x) priority_queue<x, vector<x>, greater<x>>

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vll> dist(n+1, vll(n+1, LLONG_MAX));
    rep(i,1,n+1){
        dist[i][i] = 0;
    }
    rep(i,0,m){
        ll a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    rep(i,0,q){
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == LLONG_MAX){
            cout << -1 << endl;
        }
        else {
            cout << dist[a][b] << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // printcase
    solve();
}