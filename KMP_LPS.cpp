void solve(){
    string s,p; cin>>s>>p;

    //LPS
    int n=p.length();
    vector<int> lps(n);
    lps[0]=0;
    for(int i=1; i<n; i++)
    {
        int j=lps[i-1];
        while(j>0 && s[i]!=s[j] )
        {
          j=lps[ j-1 ];
        }
        if(p[i] == p[j])
        {
            j++;
        }
        lps[i]=j;
    }

    //KMP
    int m=s.length();
    int i=0,j=0, f=0;
    while(i<m){
        if(s[i]==p[j]){
            i++;
            j++;
            if(j==n){
                cout<<i-j<<' ';  //0-based 
                f=1;
                j=lps[j-1];
            }
        }
        else{
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    if(f==0) cout<<-1;
    cout<<"\n";

}