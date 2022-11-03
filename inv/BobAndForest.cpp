#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define infile() freopen("in12.txt", "r", stdin);
#define output() freopen("out12.txt", "w", stdout);
#define ll long long
#define sc(t) \
    ;         \
    scanf("%d", &t);
#define scl(t) \
    ;          \
    scanf("%lld", &t);
#define sc2(n, m) \
    ;             \
    scanf("%d%d", &n, &m);
#define scl2(n, m) \
    ;              \
    scanf("%lld%lld", &n, &m);
#define debug() \
    ;           \
    printf("tushar\n");
#define N 1001
#define mod 1000000007
#define printi(n) printf("%d", n);
#define inf ((1 << 29) - 1)
#define linf ((1LL << 60) - 1)
const double eps = 1e-9;
set<ll> s;
set<int> si;
set<ll>::iterator it;
vector<ll> v;
vector<int> vi;

int n, m, q, k;
char str[N][N];
int a[N][N] = {0};
int ans[N] = {0};
int main()
{
    int i, j, t;

    // infile();
    // output();
    sc2(n, m);

    for (i = 0; i < n; i++)
    {
        scanf("%s", str[i]);
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (str[i - 1][j - 1] == '*')
                a[i][j] = 1;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            a[i][j] = a[i][j - 1] + a[i][j];
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j];
        }
    }


    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            int low = 1;
            int high = min(n, m);
            int mid;
            int anss = 0;
            while (low <= high)
            {
                mid = (low + high) / 2;
                int x1 = i;
                int y1 = j;
                int x2 = x1 + mid - 1;
                int y2 = y1 + mid - 1;
                if (x2 > n || y2 > m)
                {
                    high = mid - 1;
                    continue;
                }
                int tmp = a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
                if (tmp == mid * mid)
                {
                    anss = mid;
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            ans[anss]++;
        }
    }

    for (i = min(n, m); i >= 1; i--)
    {
        ans[i] = ans[i] + ans[i + 1];
    }

    for (i = 2; i <= min(n, m); i++)
        ans[i] = ans[i - 1] + ans[i];
    ans[0] = 0;
    

    sc(q) ;
    while (q--)
    {
        sc(k);
        k = min(k, min(n, m));
        printf("%d\n", ans[k]);
    }
    return 0;
}