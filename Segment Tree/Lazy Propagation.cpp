#include "bits/stdc++.h"
using namespace std;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
#define nl '\n'
#define mem(a,val) memset(a,val,sizeof(a))

const int MAX = 1000*100+1;

ll seg[4*MAX],lazy[4*MAX];

void update(ll l, ll r, ll left, ll right, ll node, ll val)
{
    if( lazy[node] )
    {
        seg[node] += ( right - left + 1 ) * lazy[node];

        if( left != right )
        {
            lazy[2*node] += lazy[node];

            lazy[2*node+1] += lazy[node];

        }

        lazy[node]=0;
    }

    if( l > right or r < left )
        return;

    if( l <= left and r >= right )
    {
        seg[node] += ( right - left + 1 ) * val;

        if( left != right )
        {
            lazy[2*node] += val;

            lazy[2*node+1] += val;

        }

        return;
    }

    ll mid = left + right >> 1;

    update( l, r, left, mid, 2*node, val );

    update( l, r, mid+1, right, 2*node+1, val );

    seg[node] = seg[2*node] + seg[2*node+1];
}

ll query(ll l, ll r, ll left, ll right, ll node)
{
    if(lazy[node])
    {
        seg[node] += ( right - left + 1 ) * lazy[node];

        if( left != right )
        {
            lazy[2*node] += lazy[node];

            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0;
    }

    if( l > right or r < left )
        return 0;

    if( l <= left and r >= right)
        return seg[node];

    ll mid = left + right >>1;

    ll q1 = query( l, r, left, mid, 2*node );

    ll q2 = query(l, r, mid+1, right, 2*node+1 );

    return q1 + q2 ;

}

int main()
{
    timesaver;
    
    int t;

    cin>>t;

    while( t-- )
    {
        ll n, q;

        cin >> n >> q;

        mem( seg , 0 );

        mem( lazy , 0 );

        while(q--)
        {
            int z, x, y, val;

            cin >> z;

            if( !z )
            {
                cin >> x >> y >> val;                
                update( x, y, 1, n, 1, val );
            }
            else
            {
                cin >> x >> y;
                cout << query( x, y, 1, n, 1 ) << nl;
            }
        }

    }
}
