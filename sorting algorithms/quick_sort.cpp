#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

int partition( vector<int> &v, int p, int r ) ;

void swap( int *a , int *b ) {

	int tmp ;
	tmp = *a ;
	*a = *b ;
	*b = tmp ;

}


void quicksort( vector<int> &v , int p, int r ) {

	int q ;
	if ( p < r ) {

		q = partition( v, p, r) ;
		quicksort( v, p, q-1) ;
		quicksort( v, q+1, r) ;
	}
}

int partition( vector<int> &v, int p, int r ) {

	int x = v[r] ;
	int i = p-1 ;
	for ( int j = p ; j < r ; j++ ) {

		if ( v[j] <= x ) {

			i++ ;
			swap( &v[i], &v[j] ) ;

		}
	}

	swap( &v[i+1], &v[r]) ;

	return i+1 ;

}

int main( int argc, char** argv ) {

	vector<int> v ;

	v.push_back(2) ;
	v.push_back(8) ;
	v.push_back(7) ;
	v.push_back(1) ;
	v.push_back(3) ;
	v.push_back(5) ;
	v.push_back(6) ;
	v.push_back(4) ;


	quicksort( v, 0, v.size()-1 ) ;

	for ( auto &i : v ) cout << i << " " ;
		cout << endl ;

	return 0 ;
}