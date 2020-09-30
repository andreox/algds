#include <vector>
#include <iostream>

using namespace std ;

void InsertionSort ( vector<int> &A ) {


	int key,j,i ; 
	for ( j = 1 ; j < A.size() ; j++ ) {

		key = A[j] ;

		for ( i = j-1 ; i >= 0 && A[i] > key ; i-- ) 
			A[i+1] = A[i] ;

		A[i+1] = key ;
		
	}


}

int main ( int argc, char** argv ) {

	vector<int> A ;
	A.push_back(5);
	A.push_back(2);
	A.push_back(4);
	A.push_back(6);
	A.push_back(1);
	A.push_back(3);

	InsertionSort(A) ;

	for ( int i = 0 ; i < A.size() ; i++ ) cout << A[i] << " " ;
	cout << endl ;

	return 0 ;
}

