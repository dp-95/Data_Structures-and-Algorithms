/*
* @Author: _dp95
* @Date:   2019-10-02 00:58:33
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

const int MAX = 1000*100 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll t_no ;
ll n, t, k ;
ll nlo, nhi ;
ll vlo, vhi ;
ll tlo, thi ;
ll klo, khi ;

void getn( ){
  t_no = 5 ;
  if( t_no < 5 ){
    nlo = 1, nhi = 5 ;
    vlo = 1, vhi = 30 ;
    tlo = 1, thi = 10 ;
  }
  else if( t_no < 12 ){
    nlo = 4, nhi = 6 ;
    vlo = 1, vhi = 30 ;
    tlo = 1, thi = 20 ;
  }
  else if( t_no < 15 ){
    nlo = 5, nhi = 10 ;
    vlo = 1, vhi = 30 ;
    tlo = 40, thi = 50 ;
  }
  else{
    nlo = 10, nhi = 10 ;
    vlo = 1, vhi = 30 ;
    tlo = 50, thi = 50 ;
  }

  uniform_int_distribution< ll >tgen( tlo, thi ) ;
  t = tgen( rng ) ;

}

int main( ){
  timesaver ;
  getn();
  uniform_int_distribution< ll >vgen( vlo, vhi ) ;
  uniform_int_distribution< ll >ngen( nlo, nhi ) ; 
  cout << t << nl ;
  while( t-- ){
    n = ngen( rng ) ;
    for( int i = 0 ; i < n ; i++ ){
      ar[ i ] = vgen( rng ) ;
    }
    cout << n <<  nl ;
    for( int i = 0 ; i < n ; i++ )
      cout << ar[ i ] << " " ;
    cout << nl ;
  }
}
