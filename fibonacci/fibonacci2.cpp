#include <iostream>
#include <vector>

using namespace std ;

int fibonacci( vector<int> v , int n ) {

	v[1] = 1 ;
	v[2] = 1 ;

	for ( int i = 3 ; i <= n ; i++ ) 
		v[i] = v[i-1] + v[i-2] ;

	return v[n] ;

}

int main( int argc , char** argv ) {

	vector<int> v(16) ;
	cout << fibonacci( v , 15 ) << endl  ;

	return 0 ;

}
