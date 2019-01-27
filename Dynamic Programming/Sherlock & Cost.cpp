/*
* @Author: _dp95
* @Date:   2019-01-28 02:09:22
*/

/*
*     Q :- https://www.hackerrank.com/challenges/sherlock-and-cost
*/

#include "bits/stdc++.h"
using namespace std ;

#define nl '\n'
const int MAX = 1000 * 1000 + 10 ;

int dp[ MAX ][ 2 ], ar[ MAX ] ;

void sol( ){
    int n ;
    
    cin >> n ;
    
    for( int i = 0 ; i < n ; i++ ){
        cin >> ar[ i ] ;
    }
    
    dp[ 0 ][ 0 ] = dp[ 0 ][ 1 ] = 0 ;
    // IN THIS BASE CASE, DOES NOT AFFECTS THE ANSWER
    // dp[ i ][ 0 ] means S when a[ i ] is selected to be 1 
    // dp[ i ][ 1 ] means S when a[ i ] is selected to be ar[ i ]

    for( int i = 1 ; i < n ; i++ ){
        dp[ i ][ 0 ] = max(                                                  // Choosing a[ i ] as 1
                            dp[ i - 1 ][ 0 ] + abs( 1 - 1 ),                 // a[ i - 1 ] was 1  
                            dp[ i - 1 ][ 1 ] + abs( 1 - ar[ i - 1 ] )        // a[ i - 1 ] was ar[ i - 1 ]
                          ) ;
        dp[ i ][ 1 ] = max(                                                  // Choosing a[ i ] as ar[ i ]
                            dp[ i - 1 ][ 0 ] + abs( 1 - ar[ i ] ),           // a[ i - 1 ] was 1
                            dp[ i - 1 ][ 1 ] + abs( ar[ i ] - ar[ i - 1 ] )  // a[ i - 1 ] was ar[ i - 1 ]
                          ) ; 
    }
    cout << max( dp[ n - 1 ][ 0 ], dp[ n - 1 ][ 1 ] ) << nl ; 
}

int main( ){
    int t ;
    cin >> t ;
    while( t-- ){
        sol( ) ;
    }
}
