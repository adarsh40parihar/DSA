#include <bits/stdc++.h>
using namespace std;

struct Fenwick
{
    int n;
    vector<int> bit;

    Fenwick(int size)
    {
        n = size;
        bit.assign(n + 1, 0); // 1-based indexing
    }

    // Update: add 'val' at index 'k'
    void update(int k, int val)
    {
        while (k <= n)
        {
            bit[k] += val;
            k += (k & -k);
        }
    }

    // Prefix from [1..k]
    int query(int k)
    {
        int res = 0;
        while (k > 0)
        {
            res += bit[k];
            k -= (k & -k);
        }
        return res;
    }

    // Range query [l..r]
    int rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    // Build Fenwick Tree from array
    void build(const vector<int> &arr)
    {
        for (int i = 1; i <= n; i++)
        {
            update(i, arr[i]);
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1);

    Fenwick ft(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    ft.build(arr);

    // Example: query sum of range [l, r]
    int l, r;
    cin >> l >> r;
    cout << "Sum in range [" << l << ", " << r << "] = " << ft.rangeQuery(l, r) << "\n";

    return 0;
}
/*
Time complexity:
    Query: O(log2 n)
    Update: O(log2 n)
*/
