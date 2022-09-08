#include <list>
#include <algorithm>
typedef std::list<int> ListInt;


ListInt guysAloneFromGroup(const ListInt& men, const ListInt& women) {

    ListInt answer;
    ListInt theMen(men), theWomen(women);
    ListInt numberOfGirlfriends;
    numberOfGirlfriends.resize(theMen.size(), 1);
    theMen.sort(std::greater<int>());
    theWomen.sort(std::greater<int>());

    std::list<int>::iterator it1 = theMen.begin();
    std::list<int>::iterator it2 = numberOfGirlfriends.begin();

    while (it1 != theMen.end()) {
        if (*it1 >= 8) *it2 = 2;
        ++it1; ++it2;
    }


    it1 = theWomen.begin();
    it2 = theMen.begin();
    


    while (it1!= theWomen.end()) {
        
        if (theWomen.empty() || theMen.empty()) break;  //terminating conditions
        
        if (*it2 >= 8) { //chad
            if()
        }


        //if(theMen[0] theWomen[i])


        
    }
    return theMen;
    //    for (auto m : men) {
    //    if (m >= 8) { //we have a chad
    //        
    //    }
    //    else { //not a chad

    //    }
    //}

    
    //--- Both women and men try to get the best looking date(s) they can get
    //--- Women never date men below their own looks level
    //--- Women are content with one partner, and when they have it, they don't look for a second man (yeah, I know, but let's assume this for this kata)
    //--- Because women are hypergamous, they never settle for a man who's not at least 2 levels above their own, unless he's an 8 or above
    //    (but even then, the first rule applies)
    //--- Men of level 8 or above(aka Chads) try to get 2 women, men below that are content with one
    //--- When women have a choice between two equally glamorous Chads, they prefer the one without a girlfriend
    return answer;

}


int main() {

    ListInt result;

    result = guysAloneFromGroup(ListInt({ 1,2,3,1,5,6,10,9,5,2,5,2,4,10,10,9,8,3,4,5,6,7,8 }), ListInt({ 10,9,9,7,5,6,1,2,3,5,10,8,8,8,1,2,3,4,5 })); //Equals(ListInt({})));

        //It(No_women)
        
            result = guysAloneFromGroup(ListInt({ 2,3,4,5 }), ListInt({})); //Equals(ListInt({ 2,3,4,5 })));
        
        //It(No_men)
        
            result = guysAloneFromGroup(ListInt({}), ListInt({ 2,2,2,10 })); //Equals(ListInt({})));
        
        //It(Men_too_ugly)
        
            result = guysAloneFromGroup(ListInt({ 2,3,4,5 }), ListInt({ 8,9,10 })); //Equals(ListInt({ 2,3,4,5 })));
        
        //It(Men_too_ugly_and_women_hypergamous)
        
            result = guysAloneFromGroup(ListInt({ 2,3,4,5 }), ListInt({ 4,4,8 })); //Equals(ListInt({ 2,3,4,5 })));
        
        //It(Hot_women_date_hot_men)
        
            result = guysAloneFromGroup(ListInt({ 8,9,10,9 }), ListInt({ 10,10,10 })); //Equals(ListInt({ 8,9,9 })));
        
        //It(Chad_takes_2_chicks)
        
            // Chad takes 2 chicks; //Even if they're whales
            result = guysAloneFromGroup(ListInt({ 4,4,10 }), ListInt({ 2,2 })); //Equals(ListInt({ 4,4 })));
        
        //It(Better_looking_Chad_takes_the_chicks)
        
            result = guysAloneFromGroup(ListInt({ 9,9,10 }), ListInt({ 2,2 })); //Equals(ListInt({ 9,9 })));
        
        //It(Two_Chads_chop_down_on_two_hotties)
        
            result = guysAloneFromGroup(ListInt({ 9,9 }), ListInt({ 9,9 })); //Equals(ListInt({})));
        
        //It(Three_Chads_take_one_girl_each)
        
            result = guysAloneFromGroup(ListInt({ 10,10,10 }), ListInt({ 9,8,7 })); //Equals(ListInt({})));
        
        //It(Everybody_finds_a_date)
        
            // Chad takes 2 chicks as well
            result = guysAloneFromGroup(ListInt({ 3,4,5,6,7,8 }), ListInt({ 8,8,1,2,3,4,5 })); //Equals(ListInt({})));
        
        //It(Too_few_women_for_the_Chads)
        
            result = guysAloneFromGroup(ListInt({ 10,10,10 }), ListInt({ 9,8 })); //Equals(ListInt({ 10 })));
        
   
    return 0;
}