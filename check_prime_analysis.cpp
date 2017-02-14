#include <iostream>

using namespace std ;

bool checkPrime( int p ) {

	int d = 2 ;

	while ( d < p && p % d != 0 ) d++ ;

	if ( d < p ) return false ;

	else return true ;

}

int main( int argc , char** argv ) {

	int n ;
	cin >> n ;

	bool tr = checkPrime( n ) ;

	cout << tr << endl ;

	return 0 ;
}

//O Notation
//If prime : 1 + ( p - 3 ) + 1 = O(p)
//If not prime : 1 + d + 1 = O(d)

