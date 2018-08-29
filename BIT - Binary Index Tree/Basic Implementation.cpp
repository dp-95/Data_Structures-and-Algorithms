#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
const int MAX = 1000*100+100;
#define nl '\n'

ll BIT[MAX];

void update(ll pos, ll val)
{
    while( pos < MAX )
    {
        BIT[pos] += val;

        pos += (pos & -pos);
    }
}

ll query(ll pos)
{
    ll sum = 0;

    while ( pos > 0 )
    {
        sum += BIT[pos];

        pos -= (pos & -pos);
    } 
    return sum;
}

int main()
{
    timesaver;

    int n, x;

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> x;

        update( i, x );
    }

    cin >> n;

    while( n-- )
    {
        int left, right;

        cin >> left >> right;

        left++; right++; //for 0 index based queries

        int ans = query( right ) - query( left - 1);

        cout << ans << nl;

    }
}
