
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a,b) memset(a, b, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define unq(v) sort(all(v)),(v).erase(unique(all(v)),(v).end())
#define _ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define sqr(a) ((a)*(a))
#define sz(a) int(a.size())
#define ff first
#define ss second
#define pb push_back

const double pi = acos(-1.0);
const int mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

int a[maxn];
int dp[maxn];

int main(){
        _ios;
        int n,k; cin >> n >> k;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i = 0;i<=n; i++){
            dp[i] = mod;
        }
        dp[0] = 0;

        for(int i = 0; i<n; i++){
            for(int j = 1; j<=k; j++){
                if(i+j<n)dp[i+j] = min(dp[i+j],dp[i]+abs(a[i]-a[i+j]));
            }
        }
        cout<<dp[n-1]<<endl;


return 0;
}
/*
    this is the same problem as the previous one, 
    in the previous problem we did at most i+1 and i+2 jump
    but in this problem we can jump at most i+k jump
    means , i+1, i+2.....i+k jump
    
    
    k <=100
    
    so we can just simply traverse 1 to k, and minimize the cost


*/
