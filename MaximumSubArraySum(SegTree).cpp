#include <bits/stdc++.h>
using namespace std;

#define READ                freopen("in.txt", "r", stdin)
#define WRITE               freopen("out.txt", "w", stdout)

#define MAX                 100005

class Node{
public:
    int sum;
    int prefixSum;
    int suffixSum;
    int res;
};

int n, m;
int arr[MAX];
Node tree[4*MAX];

Node buildNode(int val)
{
    Node node;
    node.sum = val;
    node.prefixSum = node.suffixSum = node.res = max(INT_MIN, val);
    return node;
}

Node combineNode(Node A, Node B)
{
    Node node;
    node.sum = A.sum + B.sum;
    node.prefixSum = max(A.prefixSum, A.sum + B.prefixSum);
    node.suffixSum = max(B.suffixSum, B.sum + A.suffixSum);
    node.res = max(max(A.res, B.res), A.suffixSum + B.prefixSum);

    return node;
}

void buildTree(int node, int st, int en)
{
    if(st == en)
        tree[node] = buildNode(arr[st]);
    else{
        int mid = (st+en) >> 1;
        int left = node << 1;
        int right = node << 1 | 1;

        buildTree(left, st, mid);
        buildTree(right, mid+1, en);

        tree[node] = combineNode(tree[left], tree[right]);
    }
}

Node query(int node, int st, int en, int l, int r)
{
    if(st == l and en == r)
        return tree[node];

    int mid = (st+en) >> 1;
    int left = node << 1;
    int right = node << 1 | 1;

    if(r <= mid)
        return query(left, st, mid, l, min(r, mid));
    if(l > mid)
        return query(right, mid+1, en, max(l, mid), r);

    return combineNode(query(left, st, mid, l, mid), query(right, mid+1, en, mid+1, r));
}

int main()
{
    //READ;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    buildTree(1, 1, n);

    scanf("%d", &m);
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);

        Node res = query(1, 1, n, a, b);

        printf("%d\n", res.res);
    }

    return 0;
}
