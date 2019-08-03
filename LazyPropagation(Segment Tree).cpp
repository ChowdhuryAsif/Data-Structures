#include <bits/stdc++.h>
using namespace std;

#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)

#define si(a)               scanf("%d", &a)
#define sii(a,b)            scanf("%d %d", &a, &b)
#define siii(a,b,c)         scanf("%d %d %d", &a, &b, &c)

#define sl(a)               scanf("%lld", &a)
#define sll(a,b)            scanf("%lld %lld", &a, &b)
#define slll(a,b,c)         scanf("%lld %lld %lld", &a, &b, &c)

#define CLR(a)              memset(a, 0, sizeof(a))
#define SET(a)              memset(a, -1, sizeof(a))

#define PI                  acos(-1.0)

#define pb                  push_back
#define mp                  make_pair
#define SORT(v)             sort(v.begin(), v.end())
#define REV(v)              reverse(v.begin(), v.end())
#define FOR(i, n)           for(int i=0; i<n; i++)
#define FOR1(i, n)          for(int i=1; i<=n; i++)
#define ROF(i, n)           for(int i=n-1; i>=0; i--)
#define ROF1(i, n)          for(int i=n; i>=1; i--)
#define LOOP(i, x, y)       for(int i=x; i<=y; i++)
#define fastIO()            ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


typedef long long              LL;
typedef unsigned long long     ULL;
typedef vector<int>            VI;
typedef pair<int, int>         PII;
typedef pair<string, int>      PSI;
typedef pair<char, int>        PCI;

const int MAX = 100005;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;

class Node{
public:
    LL sum;
};

int arr[MAX];
LL tree[4*MAX];
LL lazy[4*MAX];

LL combineNode(LL A, LL B)
{
    return A+B;
}

void updateLazy(int node, int st, int en)
{
    if(lazy[node] != 0){
        tree[node] += (en-st+1) * lazy[node];
        if(st != en){
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int st, int en, int l, int r, int val)
{
    updateLazy(node, st, en);

    if(st > r or en < l) return;

    int mid = (st+en) >> 1;
    int left = node << 1;
    int right = node << 1 | 1;

    if(st >= l and en <= r){
        lazy[node] += val;
        updateLazy(node, st, en);
        return;
    }

    update(left, st, mid, l, r, val);
    update(right, mid+1, en, l, r, val);

    tree[node] = combineNode(tree[left], tree[right]);
}

LL query(int node, int st, int en, int l, int r)
{
    updateLazy(node, st, en);

    if(st > r or en < l) return 0;

    if(st >= l and en <= r)
        return tree[node];

    int mid = (st+en) >> 1;
    int left = node << 1;
    int right = node << 1 | 1;

    LL p = query(left, st, mid, l, r);
    LL q = query(right, mid+1, en, l, r);

    return p+q;
}


int main()
{
    //READ;

    int t; si(t);
    FOR1(cs, t){
        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);

        int n, q; sii(n, q);
        printf("Case %d:\n", cs);
        while(q--){
            int d; si(d);

            if(d){
                int a, b; sii(a, b);
                LL res = query(1, 1, n, a+1, b+1);
                printf("%lld\n", res);
            }
            else{
                int a, b, val;
                siii(a, b, val);

                update(1, 1, n, a+1, b+1, val);
            }
        }
    }
    return 0;
}

