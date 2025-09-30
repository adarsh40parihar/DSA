#include <bits/stdc++.h>
using namespace std;
// node of the tree
struct node
{
    int freq;
    node *child[26]; // array of pointers to children
    node()           // constructor
    {
        freq = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

// main function code
int main()
{
    int n;
    cin >> n;
    node *root = new node(); // pointer to a new node
    node *tmp;
    while (n--)
    {
        string s;
        cin >> s;
        tmp = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (tmp->child[(s[i] - 'a')] == NULL)
            {
                node *z = new node();         // child create
                tmp->child[(s[i] - 'a')] = z; // linking to pre node
            }
            tmp = tmp->child[(s[i] - 'a')];
            tmp->freq++;
        }

        tmp = root;
        //s->input..
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (tmp->child[(s[i] - 'a')] == NULL)
                break;
            tmp = tmp->child[(s[i] - 'a')];
            if (i == (s.size() - 1))
                res = tmp->freq;
        }
        cout << res;
    }
    return 0;
}
