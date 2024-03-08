#include "franklist.h"

using namespace vhuk;

int main () {
	// FrankList ml1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    FrankList ml1 = {1, 4, 6, 7, 8, 9, 12};
    FrankList ml2 = {7, 1, 2};
    FrankList<int>::iterator b = ml2.begin();
    ++b;
    ++b;
    // ++a;
    // ++a;
    FrankList<int>::size_type s = 4;
    FrankList<int>::const_reference r = 4;
    ml2.insert(b, s, r);
    
    //ml2.insert(ml2.begin(), ml1.begin(), b);
    //it = it2;
   //FrankList ml1 = {1, 2, 3, 4};
    // FrankList<int>::iterator it = ml1.begin();
    // ++it;
    // ++it;
    // ++it;
    //std::cout << ml1.remove_if([](int a){ return a % 2 == 0;}) << std::endl;
    ml2.print();
}