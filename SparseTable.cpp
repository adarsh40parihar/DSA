const int MAXK = 25;
void sparse_table()
{ // use int
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int st[n + 1][MAXK + 1];
    for (int i = 0; i < n; i++)
    {
        st[i][0] = v[i];
    }
    for (int k = 1; k <= MAXK; k++)
    {
        for (int i = 0; (i + (1 << (k - 1)) < n); i++)
        {
            // st[i][k] = fun(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            //for min: st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            //for sum: st[i][k] = st[i][k - 1] + st[i + (1 << (k - 1))][k - 1];
        }
    }
    
    // Idempotent (time - O(1)) (for: min(), max(), __gcd(), lcm(), & (bitwise and), | (bitwise or))
    //pre-compute log
    int log[n + 1];
    log[1] = 0;
    for (int i = 2, i <= n; i++)
    log[i] = log[i / 2] + 1;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int len = (r - l + 1);
        int lg = log[len];
        int ans = min(st[l][lg], st[r - (1 << lg) + 1][lg]);
        cout << ans << endl;
    }
    
    // Non - idempotent (time- O(logN)) for (sum,xor)
    int q;
    cin >> q;
    while (q--)
    {
        int L, R;
        cin >> L >> R;
        int sum = 0;
        int len = R - L + 1;
        for (int k = MAXK; k >= 0; k--)
        {
            if ((1 << k) <= len)
            {
                sum += st[L][k];
                L += 1 << k;
            }
        }
    }
}