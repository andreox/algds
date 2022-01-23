#include <iostream>
#include <vector>

using namespace std ;

void reverse( vector<int>&v , int first, int last ) {

    int j = last ;
    for ( int i = first ; i <= (last+first)/2 ; i++ ) {

        int tmp = v[i] ;
        v[i] = v[j] ;
        v[j] = tmp ;
        j-- ;
    }

}

bool check_if_sorted_ascend( vector<int> v ) {

    for ( int i = 0 ; i < v.size()-1 ; i++ ) {
        if ( v[i] > v[i+1]) return false ;
    }

    return true ;
}

void print(vector<int> v ) {

    for ( int i = 0 ; i < v.size() ; i++ ) {

        cout << v[i] << " " ;

    }

    cout << endl ;
}
int almost_sorted( vector<int>& v) {

    int count_number_of_not_sorted = 0 ;
    int first_occurence_of_unsort = -1 ;
    int last_occurence_of_unsort = -1 ;

    for ( int i = 0 ; i < v.size()-1 ; i++ ) {

        if ( v[i] > v[i+1] && first_occurence_of_unsort == -1) {
            count_number_of_not_sorted++ ;
            first_occurence_of_unsort = i ;
            last_occurence_of_unsort = i ;
        }

        else if ( v[i] > v[i+1] && first_occurence_of_unsort != -1 ) {
            count_number_of_not_sorted++ ;
            last_occurence_of_unsort = i+1 ;
        }

    }

    cout << "Count : " << count_number_of_not_sorted << endl ;
    cout << "First it : " << first_occurence_of_unsort << endl ;
    cout << "Second it : " << last_occurence_of_unsort << endl ;

    if ( count_number_of_not_sorted > 2 ) {
        //reverse and check if sorted, if not, return no, else return "reverse i+1 j+1"
        reverse( v, first_occurence_of_unsort, last_occurence_of_unsort) ;
        print(v) ;

        if ( check_if_sorted_ascend(v) ) cout << "yes" << endl << "reverse " << first_occurence_of_unsort+1 << " " << last_occurence_of_unsort+1 << endl ;
        else cout << "no" ;

    }

    else if ( count_number_of_not_sorted == 1 ) {
        //swap and check if sorted, if not, return no, else return "swap i+1 i+2"
        int tmp = v[first_occurence_of_unsort] ;
        v[first_occurence_of_unsort] = v[first_occurence_of_unsort+1] ;
        v[first_occurence_of_unsort+1] = tmp ;
        print(v) ;
        if ( check_if_sorted_ascend(v) ) cout << "yes" << endl << "swap " << first_occurence_of_unsort+1 << " " << first_occurence_of_unsort+2 << endl ;
        else cout << "no" << endl ; 
    }

    else if ( count_number_of_not_sorted == 2 ) {

        int tmp = v[first_occurence_of_unsort] ;
        v[first_occurence_of_unsort] = v[last_occurence_of_unsort] ;
        v[last_occurence_of_unsort] = tmp ;
        print(v) ;
        if ( check_if_sorted_ascend(v)) cout << "yes" << endl << "swap" << first_occurence_of_unsort+1 << " " << last_occurence_of_unsort+1 << endl ;
        else cout << "no" << endl ;
    }
    else cout << "no" << endl ;
    return 0 ;
}

int main() {

    vector<int> v ;
    
    v.push_back(1) ;
    v.push_back(5) ;
    v.push_back(3) ;
    v.push_back(4) ;
    v.push_back(2) ;
    v.push_back(6) ;
    
    // { 1 , 5 , 4 , 3 , 2 , 6 } ;
    almost_sorted(v) ;

    return 0 ;
}

//It is always an O(n) solution because of the sorting check, the reverse algorithm is an 0(n/2) solution
