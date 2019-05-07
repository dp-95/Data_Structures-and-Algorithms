/*
* @Author: _dp95
* @Date:   2019-05-07 16:14:32
*/
/*
*       SEGMENT TREE WITH RANGE UPDATES : ( SUM IN A RANGE )
*/
#include "bits/stdc++.h"
using namespace std ;

const int MAX = 1e5 + 10 ;

struct NODE{

    int val, lazy ;

    NODE( int temp = 0 ){
        val = temp ;
        lazy = 0 ;
    }

    NODE operator + ( NODE &t ){
        NODE temp ;
        temp.val = val + t.val ;
        temp.lazy = 0 ;
        return temp ;
    }

} ;

int ar[ MAX ], n, q ;
NODE seg[ 4 * MAX ] ;

void lazydown( int left, int right, int node ){
    seg[ node ].val += ( right - left + 1 ) * seg[ node ].lazy ;
    if( left != right ){
        seg[ 2 * node ].lazy += seg[ node ].lazy ;
        seg[ 2 * node + 1 ].lazy += seg[ node ].lazy ;
    }
    seg[ node ].lazy = 0 ;
}

void build( int left, int right, int node ){
    if( left == right ){
        seg[ node ] = NODE( ar[ left ] ) ;
        return ;
    }
    int mid = left + right >> 1 ;
    build( left, mid, 2 * node ) ;
    build( mid + 1, right, 2 * node + 1 ) ;
    seg[ node ] = seg[ 2 * node ] + seg[ 2 * node + 1 ] ;
}

NODE query( int l, int r, int left, int right, int node ){
    if( seg[ node ].lazy ){
        lazydown( left, right, node ) ;
    }
    NODE temp ;
    if( l > right or r < left ){
        return temp ;
    }
    if( l <= left and r >= right ){
        return seg[ node ] ;
    }
    int mid = left + right >> 1 ;
    NODE q1 = query( l, r, left, mid, 2 * node ) ;
    NODE q2 = query( l, r, mid + 1, right, 2 * node + 1 ) ;
    return q1 + q2 ;
}

void update( int l, int r, int left, int right, int node, int val ){
    if( seg[ node ].lazy ){
        lazydown( left, right, node ) ;
    }
    if( r < left or l > right ){
        return ;
    }
    if( l <= left and r >= right ){
        seg[ node ].val += ( right - left + 1 ) * val ;
        if( left != right ){
            seg[ 2 * node ].lazy += val ;
            seg[ 2 * node + 1 ].lazy += val ;
        }
        return ;
    }
    int mid = left + right >> 1 ;
    update( l, r, left, mid, 2 * node, val ) ;
    update( l, r, mid + 1, right, 2 * node + 1, val ) ;
    seg[ node ] = seg[ 2 * node ] + seg[ 2 * node + 1 ] ;
}

int main( ){
    cin >> n >> q ;
    build( 1, n, 1 ) ;
    while( q-- ){
        int t ;
        cin >> t ;
        if( t == 1 ){
            int l, r ;
            cin >> l >> r ;
            NODE ans = query( l, r, 1, n, 1 ) ;
            cout << ans.val << "\n" ;
        }
        else{
            int l, r, val ;
            cin >> l >> r >> val ;
            update( l, r, 1, n, 1, val ) ;
        }
    }
}
