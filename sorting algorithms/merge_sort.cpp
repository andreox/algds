#include <iostream>
#include <vector>

using namespace std ;

void merge( vector<int> &A , int p, int q, int r ) {

	int i,j ;
	int n1 = q - p + 1 ;
	int n2 = r - q ;

	vector<int> L ;
	vector<int> R ;

	for ( i = 0 ; i < n1 ; i++ ) {
		L.push_back(A[p+i]) ;
	}


	for ( j = 0 ; j < n2 ; j++ ) {
		R.push_back(A[q+j+1]) ;
	}



	i = 0 ;
	j = 0 ;
	int k ;
	for ( k = p ; k < r && i < n1 && j < n2 ; k++ ) {

		if ( L[i] <= R[j] ) {

			A[k] = L[i] ;
			i++ ;
		}

		else {

			A[k] = R[j] ;
			j++ ;
		}
	}

	//sentinella
	while (i < n1) { 
        A[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        A[k] = R[j]; 
        j++; 
        k++; 
    } 

}

void merge_sort( vector<int> &A, int p, int r) {

	if ( p < r ) {

		int q = (p+(r-1))/2 ;
		merge_sort( A, p, q) ;
		merge_sort( A, q+1, r) ;
		merge( A, p, q, r) ;
	}
}

int main( int argc, char** argv ) {

	vector<int> A ;
	A.push_back(7);
	A.push_back(5);
	A.push_back(4);
	A.push_back(2);
	A.push_back(6);
	A.push_back(3);
	A.push_back(2);
	A.push_back(1);

	int p = 0 ;
	int r = A.size()  ;
	merge_sort( A, p, r-1 ) ;

	for ( int i = 0 ; i < A.size() ; i++ ) cout << A[i] << " " ;
		cout << endl ;

	return 0 ;
}