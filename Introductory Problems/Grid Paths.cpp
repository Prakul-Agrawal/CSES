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

vvi grid(7, vi(7));
int cnt = 0;
string s;

bool valid(int x, int y)
{
    if (x == -1 || x == 7 || y == -1 || y == 7 || grid[x][y]) return false;
    return true;
}

void dfs(int x, int y, int move)
{
    // prune if bottom left reached before all moves complete
    // prune if cannot go forward but can go both left and right

    if (x == 6 && y == 0)
    {
        if (move == 48) cnt++;
        return;        
    }

    if (move == 48) return;

    grid[x][y] = 1;

    if (s[move] == '?' || s[move] == 'R')
    {
        if (valid(x,y+1) && (valid(x,y+2) || !valid(x+1,y+1) || !valid(x-1,y+1)))
            dfs(x,y+1,move+1);
    }
    if (s[move] == '?' || s[move] == 'L')
    {
        if (valid(x,y-1) && (valid(x,y-2) || !valid(x+1,y-1) || !valid(x-1,y-1)))
            dfs(x,y-1,move+1);
    }
    if (s[move] == '?' || s[move] == 'U')
    {
        if (valid(x-1,y) && (valid(x-2,y) || !valid(x-1,y+1) || !valid(x-1,y-1)))
            dfs(x-1,y,move+1);
    }
    if (s[move] == '?' || s[move] == 'D')
    {
        if (valid(x+1,y) && (valid(x+2,y) || !valid(x+1,y+1) || !valid(x+1,y-1)))
            dfs(x+1,y,move+1);
    }

    grid[x][y] = 0;
}

void solve(){
    cin >> s;
    dfs(0,0,0);
    cout << cnt << endl;
}

int main() 
{
    ios::sync_with_stdio(0); // To increase input-output speed
    cin.tie(0);
    // tc
    solve();
}