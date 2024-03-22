const int N=1e6+2;
vi isPrime, primes;
void sieve(){
    isPrime.assign(N+1,1);
    isPrime[0]=0; isPrime[1]=0;
    for(int i=2; i*i<=N; i++) if(isPrime[i]) for(int j=i*i; j<=N; j+=i) isPrime[j]=0;
    f(i,2,N+1) if(isPrime[i]) primes.pb(i);
}
//for spf
const int N=1e6+2;
vi spf(N+1);
void sieve(){
    spf[0]=-1; spf[1]=-1;
    for(int i=2;i<=N;i++){
        spf[i]=i;
    }
    for(int i=2; i*i<=N; i++) 
        if(spf[i]==i)
             for(int j=i*i; j<=N; j+=i)
                if(spf[j]==j)
                    spf[j]=i;
}
