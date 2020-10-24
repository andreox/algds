#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std ;

//function object 
class maggiore {

	public :
		inline bool operator()(const int &a, const int &b ) { return a < b ; } 

};


void print( vector<int> v) {

	for ( const auto& x : v ) {

		cout << x << " " ;
	}

	cout << endl ;
}

int main() {


	maggiore M ;
	
	vector<int> v { 4 , 1 , 3 , 2 , 16 , 9 , 10, 14, 8 , 7};

	print(v) ;

	make_heap( v.begin(), v.end(), M) ;

	print(v) ;

	sort_heap( v.begin(), v.end() ) ;

	print(v) ;

	cout << endl ;

	return 0 ;


}