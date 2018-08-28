#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0).cout.tie(0);

typedef long long ll;
const int MAX = 1000*100+10;
#define nl '\n';

ll BIT[MAX];

void update(ll pos, ll val)
{
    while ( pos < MAX )
    {
        BIT[pos] += val;

        pos += ( pos & -pos );

    }
}

ll query(ll pos)
{
    ll sum=0;

    while( pos > 0 )
    {
        sum += BIT[pos];

        pos -= ( pos & -pos );
    }

    return sum;
}

int main()
{
    int n, x, z, q;

    cin >> n;

    for(int i=1;i<=n;i++)
    {
        cin >> x;

        update(i,x);
    }

    cin>>q;

    while( q-- )
    {
        cin >> z;

        if(z)
        {
            int pos, val;

            cin >> pos >> val;

            update( pos, val);
        }
        else
        {
            int left, right;

            cin >> left >> right;

            int ans = query( right ) - query( left - 1);

            cout << ans << nl;
        }
    }
}
