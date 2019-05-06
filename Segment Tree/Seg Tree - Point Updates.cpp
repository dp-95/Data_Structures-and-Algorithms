/*
* @Author: _dp95
* @Date:   2019-05-06 23:38:19
*/
/*
* SEGMENT TREE WITH POINT UPDATES : MINIMUM IN A RANGE
*/
#include "bits/stdc++.h"
using namespace std ;

const int MAX = 1e5 + 10 ;

struct NODE{

    int val ;

    NODE( int temp = 1e6 ){
        val = temp ;
    }

    NODE operator + ( NODE &t ){
        NODE temp ;
        temp.val = min( val , t.val ) ;
        return temp ;
    }

} ;

int ar[ MAX ], n, q ;
NODE seg[ 4 * MAX ] ;

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

void update( int left, int right, int node, int pos, int val ){
    if( left == right ){
        ar[ left ] = val ;
        seg[ node ] = NODE( ar[ left ] ) ;
        return ;
    }
    int mid = left + right >> 1 ;
    if( left <= pos and pos <= mid ){
        update( left, mid, 2 * node, pos, val ) ;
    }
    else{
        update( mid + 1, right, 2 * node + 1, pos, val ) ;
    }
    seg[ node ] = seg[ 2 * node ] + seg[ 2 * node + 1 ] ;
}

int main( ){
    cin >> n >> q ;
    for( int i = 1 ; i <= n ; i++ ){
        cin >> ar[ i ] ;
    }
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
            int pos, val ;
            cin >> pos >> val ;
            update( 1, n, 1, pos, val ) ;
        }
    }
}
