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

const int MAX = 30010;
const double eps = 1e-9;
const int INF = 0x3f3f3f3f;

class Node{
public:
    int val, pos;
};

int LEFT[MAX];
int RIGHT[MAX];
stack <Node> st;
Node arr[MAX];



int main()
{
    //READ;
    int t; si(t);
    FOR1(cs, t){

        int n; si(n);
        FOR1(i, n){
            int p; si(p);
            arr[i].val = p;
            arr[i].pos = i;
        }
        arr[n+1].val = 0;
        arr[n+1].pos = n+1;
        arr[0].val = 0;
        arr[0].pos = 0;

        // for right segment calculation
        FOR1(i, n+1)
        {
            if(st.empty() or st.top().val <= arr[i].val){
                st.push(arr[i]);
            }
            else{
                int k = st.top().val, sz = st.size();
                while(k > arr[i].val and sz > 0){
                    RIGHT[st.top().pos] = arr[i].pos-1;
                    st.pop();
                    sz--;
                    if(sz)
                        k = st.top().val;
                }
                if(i != n+1)
                    st.push(arr[i]);
            }
        }

        // for left segment calculation
        for(int i=n; i>=0; i--){
            if(st.empty() or st.top().val < arr[i].val){
                st.push(arr[i]);
            }
            else{
                int k = st.top().val, sz = st.size();

                while(k > arr[i].val and sz > 0){
                    LEFT[st.top().pos] = arr[i].pos+1;
                    st.pop();
                    sz--;
                    if(sz)
                        k = st.top().val;
                }
                if(i != 0)
                    st.push(arr[i]);
            }
        }

        LL ans = INT_MIN;
        FOR1(i, n){
            //cout << arr[i].val << " Left: " << arr[i].pos - LEFT[arr[i].pos] << " Right: " << RIGHT[arr[i].pos] - arr[i].pos + 1 << endl;
            LL area = ((arr[i].pos - LEFT[arr[i].pos]) + (RIGHT[arr[i].pos] - arr[i].pos + 1)) * arr[i].val;
            ans = max(ans, area);
        }
        printf("Case %d: %lld\n", cs, ans);

    }
    return 0;
}

