# This is the Inmportant Stuff
```
#include<bits/stdc++.h>
using namespace std;

#define fastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);cout.precision(numeric_limits<double>::max_digits10);
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define mii map<ll, ll>
#define pii pair<ll, ll>
#define vi vector<ll>
#define vvi vector<vi>
#define ff first
#define take(v,n) for(ll i=0;i<n;i++) cin>>v[i];
#define ss second
#define endl "\n"
#define f(i,x,y) for(ll i=x; i<y; i++)
#define setbitsll(n)  __builtin_popcountll(n)
#define setbits(n)  __builtin_popcount(n)

#define yn(f) f?cout<<"YES"<<endl:cout<<"NO"<<endl
#define dbg(x) cout<<#x<<"=" << x << "\n"
const ll M=1000000007;

ll lcm(ll a, ll b){ll g=__gcd(a, b); return a/g*b;}

ll fact(ll n){n%=M; if(n<=1) return 1; return n*fact(n-1)%M;}

ll powm(ll x,ll n){
    x%=M;
    if(n==0)return 1; if(n==1)return x;
    ll p= powm(x*x,n/2);
    if(n%2) return p*x%M; return p;
}

ll mod_div(ll p, ll q){ return p*powm(q,M-2)%M;}

ll bitsize(ll n){if(n==0) return 0; return 1+bitsize(n>>1);}

const double eps = 0.000001;

const ll N=1e6+2;
vi isPrime, primes;
void sieve(){
    isPrime.assign(N+1,1);
    isPrime[0]=0; isPrime[1]=0;
    for(ll i=2; i*i<=N; i++) if(isPrime[i]) for(ll j=i*i; j<=N; j+=i) isPrime[j]=0;
    f(i,2,N+1) if(isPrime[i]) primes.pb(i);
}
/*-------------------------------------------------------------------------------------------------------------------------------------*/

void adarsh_parihar(){   	//use ll
    ll n;
    cin>>n;
    vi v(n); f(i,0,n) cin>>v[i]; 
    

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    f(i,1,t+1)
//cout<<"Case #"<<i<<": ";
         adarsh_parihar();
    return 0;
}
```
