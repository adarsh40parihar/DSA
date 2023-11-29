void solve()
    int n = 1e6;
    vi spf(n);
    f(i,0,n){
        spf[i]=i;
    }
    for(int i = 2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j)
                 spf[j]=i;
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        cout<<spf[k]<<endl;
    }
}
