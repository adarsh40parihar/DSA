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