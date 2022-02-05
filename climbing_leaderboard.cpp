#include <iostream>
#include <vector>

using namespace std ;

void print_vec( vector<int> vec ) {
    for ( int v : vec ) {
        cout << v << " " ;
    }

    cout << endl ;
}

bool is_last_value( vector<int> v, int to_insert ) {
    if ( v[v.size()-1] != to_insert ) return false ;
    return true ;
}
//this is a simple array in order merging. ( with duplicates deletion )
//this doesn't solve the problem still
vector<int> climbingLeaderboard( vector<int> ranked, vector<int> player) {

    vector<int> mergedArray ;
    vector<int> playersPosition ;

    int r_index = 0 ;
    int p_index = player.size() - 1;
    int position = 1 ;

    while ( r_index < ranked.size() && p_index >= 0 ) {

        if ( player[p_index] > ranked[r_index] ) {

            if ( mergedArray.size() != 0 && mergedArray[mergedArray.size()-1] != player[p_index] ) playersPosition.push_back( position++ ) ;
            else playersPosition.push_back(position) ;
            mergedArray.push_back(player[p_index]) ;
            //playersPosition.push_back( position ) ;           
            p_index-- ;

        }

        else if ( player[p_index] == ranked[r_index] ) {
            
            if ( mergedArray.size() != 0 && mergedArray[mergedArray.size()-1] != player[p_index] ) playersPosition.push_back( position++ ) ;
            else playersPosition.push_back(position) ;
            mergedArray.push_back(player[p_index]) ;
            r_index++ ;
            p_index-- ;
        }

        else {

            if ( mergedArray.size() != 0 && mergedArray[mergedArray.size()-1] != ranked[r_index] ) position++ ;
            mergedArray.push_back( ranked[r_index] ) ;
            r_index++ ;
        }
    }

    if ( r_index != ranked.size() ) {
        while ( r_index < ranked.size() ) {
            mergedArray.push_back( ranked[r_index++]) ;
        }
    }

    else {
        while ( p_index >= 0 ) {

            if ( mergedArray.size() != 0 && mergedArray[mergedArray.size()-1] != player[p_index] ) playersPosition.push_back( position++ ) ;
            else playersPosition.push_back(position) ;
            mergedArray.push_back( player[p_index--]) ;
            
        }
    }

    print_vec(mergedArray) ;
    cout << endl << endl << "Positions : " << endl ;
    print_vec(playersPosition) ;

    return playersPosition ;
}

int main( int argc, char** argv ) {


    vector<int> ranked ;
    vector<int> player ;
    ranked.push_back(100) ;
    ranked.push_back(100) ;
    ranked.push_back(50) ;
    ranked.push_back(40) ;
    ranked.push_back(40) ;
    ranked.push_back(20) ;
    ranked.push_back(10) ;

    player.push_back(5) ;
    player.push_back(25) ;
    player.push_back(50) ;
    player.push_back(120) ;

    climbingLeaderboard(ranked, player) ;

    return 0 ;

}