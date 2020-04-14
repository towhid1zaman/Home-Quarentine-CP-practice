
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
const int maxn = 2000100;

vi prime;
int  status[101];
void sieve(){
    fill(status);
    prime.push_back(2);
    for(ll i = 3; i<=100; i+=2){
        if(status[i]==0){
            prime.push_back(i);
            for(ll j = i*i; j<=100;j+=i*2){
                status[j] = 1;
            }
        }
    }
}

int main(){
        //_ios;
        sieve();
        int T; cin >> T;
        int cs = 1;
        while(T--){
            int n; cin >> n;
            cout<<"Case "<<cs++<<": "<<n;
            bool first = true;
            for(auto p: prime){
                    if(p>n)break;
                    int cnt = 0;
                    int x = n;
                    while(x) x/=p,cnt+=x;
                    if(first) cout<<" = "<<p<<" ("<<cnt<<")";
                    else cout<<" * "<<p<<" ("<<cnt<<")";
                    first = false;

            }cout<<endl;
        }


return 0;
}
/*

    ei problem e bola hoiche N! ke prime factor  er power er maddhome prokash koro

    let N = 6;
    so, N ! = 6! = 720

    ei 720 ke prime er power er maddhome prokash korte hobe

    so 720 = 2^(4) * 3^(2) * 5^(1)

    Approach: ekta number N! e prime er power koita ache , seta ber korte parlei solved !!

    Eta ber korar jonno amader ekta formula ache,

    its Called Legendre's Formula: <-----

    let a function v(n!,2)

    means N er moddhe 2 er power koto

    V(n!,2) = floor(n/2) + floor(n/(2*2))+floor(n/(2*2*2))+.............+(hor er value lob er theke beshi hoile then sob zero)

    let n = 10

    amra 10! er moddhe 2 er power koto ache khujbo

    so V(n!,2) = V(10!,2)
                   = 10/2 + 10/4 + 10/8 + ...+( all zero)
                   = 5+ 2 +1
                   = 8
    so 10 ! er moddhe 2 power ache 8 ta , means 2^8

    so eivabe amra N er theke choto sob gula prime er ber kore felbo

    ekhane, amra same Formula r kaj tai ektu different vabe korechi

    v(n!,p) = n/p + n/(p*p)+.....all zero
   eta lekha jai, v(n!,p) = n/p + n/p + n/p.....all zero
   means v(10!,2)= 10/2 + 10/4 + 10/8 + ...+( all zero)
    v(10!,2)= 10/2 + 5/2 + 5/2 + ...+( all zero) same jinis.

    then amra protita prime er power ber kore cnt print kore dichi






*/

