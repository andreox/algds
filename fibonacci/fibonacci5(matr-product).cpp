//Algorithm to calculate the n-th number of Fibonacci's sequence. It uses Matrix Product to calculate every number

#include <iostream>
#include <vector>

using namespace std ;

#define M 1
#define N 1
#define P 1

int main( int argc , char** argv ) {

	vector<vector<int>> Matr(2 , vector<int>(2)) ;

	Matr[0][0] = 1 ;
	Matr[0][1] = 0 ;
	Matr[1][0] = 0 ;
	Matr[1][1] = 1 ;

	vector< vector<int> > Const( 2 , vector<int>(2)) ;

	Const[0][0] = 1 ;
	Const[0][1] = 1 ;
	Const[1][0] = 1 ;
	Const[1][1] = 0 ;

	int n ;

	cout << "Insert n to determine n-th number of Fibonacci's sequence : " ;
	cin >> n ;

	vector< vector<int> > Tmp( 2 , vector<int>(2)) ;

	//Matrix product begins
	for ( int t = 0 ; t < n-1 ; t++ ) {

		for ( int i = 0 ; i <= N ; i++ ) {

			for ( int j = 0 ; j <= M ; j++ ) {

				Tmp[i][j] = 0 ;

				for ( int k = 0 ; k <= P ; k++ ) {

					Tmp[i][j] += ( Matr[i][k] * Const[k][j] ) ;

				}
			}
		}

		Matr = Tmp ;
	}
	//Matrix product ends
	
	cout << Matr[0][0] << endl ;

	return 0 ;

}
