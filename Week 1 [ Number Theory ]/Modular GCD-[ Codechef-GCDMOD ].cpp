
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
const ll mod = 1000000007; // (int)1e9+7
const int maxn = 2000100;

ll bxp(ll x, ll n, ll m){
    ll res = 1;
    while(n){
        if(n%2==1){
            res= ((res%m) * (x%m))%m;
            //n--;
        }
        x = ((x%m) * (x%m))%m;
        n/=2;
    }
    return res;
}

ll solve(ll a, ll b, ll n){

    if(a==b){
        return ( bxp(a,n,mod)+bxp(b,n,mod) )%mod;
    }
    ll dif = abs(a-b);
    ll res = 1;
    for(ll i = 1; i*i<=dif; i++){
        if(dif%i==0){
            ll temp = (bxp(a,n,i) + bxp(b,n,i)) % i;
            if(temp==0){
                res  = max(res,i);
            }
            temp = (bxp(a,n,dif/i) + bxp(b,n,dif/i)) % (dif/i);
            if(temp==0){
                res  = max(res,dif/i);
            }
        }
    }
    return res;
}

int main(){
        _ios;

        int T; cin >> T;
        while(T--){
            ll a,b,n; cin >> a >> b >> n;
            cout<<solve(a,b,n)<<endl;
        }

return 0;
}
/*
2
10 1 1
9 1 5

*/
