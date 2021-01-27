#include <iostream>
#include <vector>

using namespace std ;

int main( int argc, char** argv ) {

	vector<int> v; 
	v.push_back(0) ;
	v.push_back(1) ;
	v.push_back(6) ;
	v.push_back(0) ;
	v.push_back(12) ;
	v.push_back(0) ;

	int count_zeros = 0 ;
	int non_zeros_index = 0 ;
	int i ;

	for ( i = 0 ; i < v.size() ; i++ ) {

		if ( v[i] == 0 )
			 count_zeros++ ;
		else 
			v[non_zeros_index++] = v[i] ;

	}

	//cout << count_zeros << " " << non_zeros_index << endl ;
	i = non_zeros_index ;

	while ( count_zeros > 0 ) {

		v[i++] = 0 ;
		count_zeros-- ;

	}

	for ( const auto &elem : v) cout << elem << " " ;
		cout << endl ;
	return 0 ;
}
