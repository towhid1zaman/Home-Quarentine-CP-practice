
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
const int maxn = 200010;

int a[maxn];
int dp[maxn];

int main(){
        _ios;

        int n; cin >> n;
        for(int i = 0; i<n; i++){
            cin >> a[i];
        }
        for(int i= 0; i<=n; i++){
            dp[i] = mod;
        }
        dp[0]=0;
        for(int i = 0; i<n; i++){
            if(i+1<n) dp[i+1] = min(dp[i+1], dp[i]+abs(a[i]-a[i+1]));
            if(i+2<n) dp[i+2] = min(dp[i+2], dp[i]+abs(a[i]-a[i+2]));
        }
        cout<<dp[n-1]<<endl;

return 0;
}
/*
    so there are N stones, a1,a2,a3...an
    there is a frog initially on stone 1
    frog can jump i+1 or i+2
    every jump cost will be summation of abs(ai-aj)

    we have to check two condition i+1 and i+2
    when they both are less than n

    firstly , initialize ap as maximum value

    we understand that first value , means dp[0]=0
    because , if the frog dont jump the cost will be zero, simple.

    so our , task will be in every position i we will check
    if x< n then dp[x] = min(dp[x], dp[i]+abs(a[i] - a[x])
    where x = i+1 or x = i+2

    ans will be store in the bottom(n-1)


*/

