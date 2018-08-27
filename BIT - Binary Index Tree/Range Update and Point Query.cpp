#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;

const int MAX = 1000 * 10 + 5 ;

#define nl '\n'
#define mem(a,val) memset(a,val,sizeof(a)) 

ll BIT[MAX];

void update(ll pos,ll val)
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

    while ( pos > 0)
    {
        sum += BIT[pos];

        pos -= (pos & -pos);
    }

    return sum;
}


int main()
{

    timesaver;

    int t;

    cin >> t;

    while( t-- )
    {
        int n, q;

        cin >> n >> q;

        mem(BIT,0);

        while(q--)
        {
            int x, y, val;

            cin >> x >> y >> val;

            x++; y++;

            update( x , val );

            update( y + 1 , -val );

        }

        cin >> q;

        while( q-- )
        {
            int x;

            cin >> x;

            x++;

            cout << query( x ) << nl;
        }

    }
}
