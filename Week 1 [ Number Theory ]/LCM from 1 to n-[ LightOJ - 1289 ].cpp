
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
const int  maxn = 6000000;
const int  N = 100000005;

vector<bool>isp(N,true);
int  prime[maxn];
unsigned int product[maxn];
int  cnt = 0;
void sieve(){
        for(int  i = 2; i*i<N; i++){
            if(isp[i]){
                for(int j = i*i; j<N; j+=i){
                    isp[j] = false;
                }
            }
        }

        // prefix for fast calculation of product after sqrt(n) primes

        product[0] = 1;
        for(int  i = 2; i<N; i++){
            if(isp[i]){
                prime[cnt++] = i;
                product[cnt] = product[cnt-1]*i;
            }
        }
}

int main(){
        //_ios;
        sieve();
        int T; cin >> T;
        int cs  = 1;
        while(T--){
            int  n; cin >> n;
            unsigned ans = 1;
            for(auto p : prime){
                if(p*p > n) break;
                ll cnt = 0,cur = n;
                while(cur/=p)cnt++;
                cnt--;
                while(cnt--){
                    ans*=p;
                }
            }
            int  idx = upper_bound(prime,prime+cnt,n) - prime;
            ans*=product[idx];

            cout<<"Case "<<cs++<<": "<<ans<<endl;
        }


return 0;
}
/*
        ekhane bola hoiche 1 theke n er LCM ber korte hobe,

        Let, N=6;
        tahole amader calculate korte hobe LCM(1,2,3,4,5,6) = 60;

        ekhn amra dekhi kivabe calculate kora jai !

        LCM means Least common multiple,
        mane sobcheye choto multiple jeta kina jegular LCM ber korte bola hoiche tader dara
        nissehse bivajjo, kmne ?

        LCM(1,2,3,4,5,6) = 60;

        ekhane 60 ke sob gula number dara vag kora jai


        ekhn amra jani amra GCD diye LCM ber korte pari, but amra ekhane Prime Factor diye
        LCM ber korbo

        if N is 6
        then,
        2 = 2^1
        3 = 3^1
        4 = 2^2
        5 = 5^1
        6 = 2^1*3^1

        ekhn N projonto jotogula prime ache , tader sob cheye boro power jar amra take choose korbo
        so,
        LCM(1,2,3,4,5,6) = 2^2 * 3^1 * 5^1 = 60

        ekhane amra aro ekta jinis clear hoichi, seta hocche , sqrt(N) er pore joto gula prime
        thakbe tara ans e exactly ekbar e thakbe,
        see, sqrt(6) = 2, so 2 er pore joto gula prime number ache tara ekbar e thakbe
        so amaderke sqrt(N) er agee joto gula prime ache , tader hisab ta bruteforce korei
        korte pari,
        and sqrt(N) er pore ja ache , oigula amra o(1) pete pari prefix er maddhome.

*/

