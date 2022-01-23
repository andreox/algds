#include <iostream>

using namespace std ;

int libraryFine(int d1, int m1, int y1, int d2, int m2, int y2) {

    int total_fine = 0 ;
    
    if ( y1 > y2 ) total_fine = 10000 ;
    else if ( !(y1 < y2 ) && m1 > m2 ) total_fine = 500 * ( m1 - m2 ) ;
    else if ( !(y1 < y2) && !(m1 < m2)  && d1 > d2 ) total_fine = 15 * ( d1 - d2 ) ;

    return total_fine ;

}

//easy O(1) solution