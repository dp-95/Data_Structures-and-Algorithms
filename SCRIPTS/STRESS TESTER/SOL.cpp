/*
* @Author: _dp95
* @Date:   2019-10-02 02:29:44
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

const int MAX = 2*1000*1000 + 10 ;
const ll INF = 1e18 ;
const int MOD = 1e9 + 7 ;

ll ar[ 11 ], n, factors = 0, l ;

void sol( ll i, ll mask ){
  if( i == n ){
    if( !mask )
      return ;
    vector< ll > nums ;
    ll fac = __builtin_popcountll(mask)&1?1:-1;
    for( ll i = 0 ; i < 11 ; i++ ){
      if( mask&(1LL<<i) ){
        nums.pb( ar[i]);
      }
    }
    ll lcm = nums[0];
    for( ll i = 1 ; i < sz(nums);i++ )
      lcm = (lcm*nums[i])/__gcd(lcm,nums[i]);
    factors += (l/lcm)*fac ;
  }
  else{
    sol( i +1, mask ) ;
    sol( i + 1, mask |(1LL<<i));
  }
}

void sol( ){
  ll req ;
  cin >> n >> req ;
  for( ll i = 0; i < n ; i++ )
    cin >> ar[i] ;
  sol( 0,0 );
  ll lo =1, hi = 1e18, ans=-1;
  while(lo<=hi){
    ll mid=lo+hi>>1;
    l = mid ;
    factors = 0 ;
    sol( 0, 0 ) ;
    if( factors >= req ){
      ans = mid ;
      hi = mid -1;
    }
    else
      lo = mid+1;
  }
  ll tmp = 0 ;
  for( ll i = 0 ; i < n ; i++ )
    tmp = max( tmp,( ans/ar[i] )* ar[ i ] ) ;
  cout << tmp << nl ; 
}

int main( ){
  timesaver ;
  int t ;
  cin >> t ;
  while( t-- ){
    factors = 0 ;
    sol( ) ;
  }
}