#include<bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define f(i, x, y) for (int i = x; i < y; i++)

// 0- based for all 
const int inf = 1e18;
struct SegmentTree
{
    int n;
    vector<int> segTree;

    // Initialize with size
    SegmentTree(int size)
    {
        n = size;
        segTree.assign(4 * n, 0); // segment tree size ~ 4*n
    }

    // Build tree from initial array
    void build(int idx, int l, int r, vi &v){
        if (l == r)
        {
            segTree[idx] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2 + 1, l, mid, v);
        build(idx * 2 + 2, mid + 1, r, v);
        segTree[idx] = min(segTree[idx * 2 + 1], segTree[idx * 2 + 2]);         // 1st change
    }

    // Point update: set v[pos] = new_val
    void update(int idx, int l, int r, int pos, int new_val, vi &v){
        if (l == r)
        {
            v[pos] = new_val;
            segTree[idx] = new_val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid)
        {
            update(idx * 2 + 1 , l, mid, pos, new_val, v);
        }
        else{
            update(idx * 2 + 2, mid+1,r, pos, new_val, v);
        }
        segTree[idx] = min(segTree[idx * 2 + 1], segTree[idx * 2 + 2]);         // 2nd change
    }

    // query for range [x -> y]
    int query(int idx, int l,int r,int x,int y){
        if(r<x || l>y)
        {
            return inf; // no overlap                                       // 3rd change
        }
        if(x<=l && y>=r){
            return segTree[idx]; // total overlap
        }
        int mid = (l + r) / 2;
        int p1 = query(idx * 2 + 1, l, mid, x, y);
        int p2 = query(idx * 2 + 2, mid+1,r, x, y);
        return min(p1, p2);                                                 // 4th change
    }
};
// tree is 0 based and other are 0 based indexing
void adarsh_parihar(){
    int n,q;
    cin>>n>>q;
    vi v(n);
    SegmentTree st(n);
    f(i, 0, n)
    {
        cin>>v[i];
    }
    st.build(0, 0, n - 1, v);
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            int pos, val;
            cin >> pos >> val;
            pos--;
            st.update(0, 0, n - 1, pos, val, v);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            cout << st.query(0, 0, n - 1, x, y) << endl;
        }
    }
}

int32_t main(){
     adarsh_parihar();
    return 0;
}

/*

Build: O(N)
Point Update: O(log N)
Query: O(log N)

*/

/*Node Segment Tree:
Problem : https://cses.fi/problemset/task/1190

*/
struct Node
{
    int sum, pref, suff, maxi;
    // sum(total), pref(best prefix), suff(best suffix), maxi(best subarray anywhere) for SUM.
    /*
    sum Total sum of the segment[L..R]
    pref Maximum prefix sum in[L..R](best subarray starting at L)
    suff Maximum suffix sum in[L..R](best subarray ending at R)
    maxi Maximum subarray sum anywhere inside[L..R]
    */
};
Node make_val(int val)
{
    Node res;
    res.sum = val;
    res.pref = res.suff = res.maxi = max(0LL, val);
    return res;
}
Node combine(Node l, Node r)
{
    Node res;
    res.sum = l.sum + r.sum;
    // Total sum of the combined segment = sum of both halves.

    res.pref = max(l.pref, l.sum + r.pref);
    /*➡️ Best prefix of the full segment is either :
        the left’s prefix
        or entire left + prefix of right (start from r). */

    res.suff = max(r.suff, r.sum + l.suff);
    /*➡️ Best suffix is either :
        the right’s suffix,
        or entire right + suffix of left. */

    res.maxi = max({l.maxi, r.maxi, r.pref + l.suff});
    /*Best subarray overall is one of :
        left’s best,
        right’s best,
        one that crosses the middle(left.suff + right.pref). */

    return res;
}

struct Segt
{
    int n;
    vector<Node> segt;
    Segt(int N)
    {
        n = N;
        segt.resize(4 * n);
    }
    void build(int i, int l, int r, vi &v)
    {
        if (l == r)
        {
            segt[i] = make_val(v[l]);
            return;
        }
        int mid = (l + r) / 2;
        build(2 * i + 1, l, mid, v);
        build(2 * i + 2, mid + 1, r, v);
        segt[i] = combine(segt[i * 2 + 1], segt[i * 2 + 2]);
    }
    void update(int i, int l, int r, int idx, int newval)
    {
        if (l == r)
        {
            segt[i] = make_val(newval);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
        {
            update(i * 2 + 1, l, mid, idx, newval);
        }
        else
            update(i * 2 + 2, mid + 1, r, idx, newval);
        segt[i] = combine(segt[i * 2 + 1], segt[i * 2 + 2]);
    }
    Node query(int i, int l, int r, int x, int y)
    {
        if (y < l || x > r)
        {
            return make_val(-1e18);
        }
        if (x <= l && r <= y)
        {
            return segt[i];
        }
        int mid = (l + r) / 2;
        Node left = query(i * 2 + 1, l, mid, x, y);
        Node right = query(i * 2 + 2, mid + 1, r, x, y);
        return combine(left, right);
    }
};
void adarsh_parihar()
{ // use int
    int n, q;
    cin >> n >> q;
    vi v(n);
    Segt st(n);
    f(i, 0, n)
    {
        cin >> v[i];
    }
    st.build(0, 0, n - 1, v);
    while (q--)
    {
        int k, x;
        cin >> k >> x;
        k--;
        st.update(0, 0, n - 1, k, x);
        Node res = st.query(0, 0, n - 1, 0, n - 1);
        cout << res.maxi << endl;
    }
}