#include <iostream>
#include <string>

using namespace std ;

int anagram( string s) {

    if ( s.length() % 2 != 0 ) return -1 ;

    int count = 0 ;
    int med = s.length()/2 ;
    bool tr = false ;

    for ( int i = 0 ; i < med ; i++ ) {
        
        for ( int j = med ; j < s.length() ; j++ ) {

            if ( s[i] == s[j] && s[j] != '0' ) {
                s[j] = '0' ;
                tr = true ;
                continue ;
            }
        }

        if ( !tr ) count++ ;
        tr = false ;
    }

    return count ;

}

int main() {

    string s ;
    cin >> s ;
    cout << anagram(s) << endl ;

    return 0 ;
}

//not working, bug fixing needed
//there is room for improvement for time complexity which is O(n^2/2)