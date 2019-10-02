/*
* @Author: _dp95
* @Date:   2019-10-02 01:01:15
*/
#include "bits/stdc++.h"
using namespace std ;

#define timesaver ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll ;
typedef long double ldb ;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define nl '\n'

#define all( x ) x.begin(),x.end() 
#define sz( x ) ( int )( x ).size( )
#define mem( a, val ) memset(a, val, sizeof( a ) )
#define deci( x ) cout<<fixed<<setprecision( x );
#define bitcount( x ) __builtin_popcountll( x )

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

const int MAX = 1000*1000 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

vector< int > v ;
int n ;

void pre( ){
  for( int i = 0 ; i < n ; i++ ){
    for( int j = v[i] ; j < MAX ; j += v[i] ){
      v.pb(j);
    }
  }
  sort(all(v));
  unique(all(v));
}

void sol( ){
  ll req ;
  cin >> n >> req ;
  for(int i = 0 ; i < n ; i++ ){
    int x, y ;
    cin >> x ;
    v.pb(x);
  }
  pre( ) ;
  cout << v[ req -1 ] << nl ;
}

int main( ){
  timesaver ;
  ll t ;
  cin >> t ;
  while( t-- ){
    sol( ) ;
    v.clear( ) ;
  }
}