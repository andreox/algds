#include <iostream>

using namespace std ;

int R ;

int pow_with_repeated_squares( int N , int x ) {

	if ( x <= 1 ) R = N ;

	else {

		R = pow_with_repeated_squares(N, x/2) ;
		R = R*R ;

	}

	if ( x % 2 != 0 && x != 1 ) R = R*N ;

	return R ;
}

int main( int argc , char** argv ) {

	cout << pow_with_repeated_squares( 3 , 8 ) << endl ;
	return 0 ;

}
