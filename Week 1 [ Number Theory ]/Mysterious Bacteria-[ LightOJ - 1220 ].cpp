
// </> : towhid1zaman

#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;typedef vector<ll> vll;
#define fill(a) memset(a, 0, sizeof (a))
#define all(v) (v).begin(),(v).end()
#define sp(k) cout<<setprecision(k)<<fixed;
#define rep(i,a) for(int i=0; i<a;i++)
#define rep1(i,a,b) for(int i=(a);i<=(b);++i)
#define irep(i,b,a) for(int i=(b);i>=(a);--i)
#define minv(v) *min_element(all(v))
#define maxv(v) *max_element(all(v))
#define each(it,s) for(auto it = s.begin(); it != s.end(); ++it)
#define unq(v) sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
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

int main(){
        _ios;

        int T; cin >> T;
        int cs = 0;
        while(T--){
            ll x; cin >>x;

            bool neg = false;
            if(x<0){
                    neg = true;
                    x = abs(x);
            }

            ll gcd = 0;
            for(ll i = 2; i*i<=x; i++){
                ll cnt = 0;
                while(x%i==0){
                    cnt++;
                    x/=i;
                }
                gcd = __gcd(gcd,cnt);
            }
            if(x>1){
                gcd = __gcd(gcd,1ll);
            }
            if(neg){
                while(gcd%2==0){
                    gcd/=2;
                }
            }
            cout<<"Case "<<++cs<<": "<<gcd<<endl;
        }


return 0;
}
/*

    ei problem e bolche ekta number ke maximum koto power e prokash korte pari !

    let x = 8
    so, we can write 8 = 2^3
    so 3 is the ans.

    another , x = 64
    so, 64 = 8^2 = 4^3 = 2 ^ 6



    approach : amra x er prime factor ber korbo, and tader
    gcd e hobe amader ans.

    ekhn jodi number ta negative hoi, tahole amaderke gcd(ans) theke
    2 er multiple gula bad diye dibo.
    reason ,
     let x =  -64
     we can write this, -64 = -2^6
     but power even hoile seta positive hoye jabe, so
     we can write -64 = (-4)^3
     
     just gcd theke 2 er multiple gula bad
    
*/
