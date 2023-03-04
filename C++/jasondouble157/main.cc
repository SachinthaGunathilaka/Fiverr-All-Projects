#include "a1-global.cc"
#include "Library.h"
#include "Date.h"

using namespace std;
int main(){
    cout << "\n===================Testing Dates===================" << endl;
    cout << "---------------------------------------------------" << endl;
    Date date1(2021, 10, 5 , 5 , 3);
    Date date2(2021, 11, 6 , 5 , 2);
    testDate(date1, date2, false);

    Date date3(2021, 10, 5 , 7 , 3);
    Date date4(2021, 10, 5 , 1 , 2);
    testDate(date3, date4, false);

    Date date5(2021, 10, 5 , 1 , 1);
    Date date6(2021, 10, 5 , 2 , 3);
    testDate(date5, date6, false);

    Date date7(2021, 10, 5 , 1 , 2);
    Date date8(2021, 10, 5 , 2 , 3);
    testDate(date7, date8, true);


    cout << "\n\n=======================Testing Library=======================" << endl;
    cout << "-------------------------------------------------------------" << endl;

    Library library;
    populate(library);
    testReservations(library);



    cout << "\n\n=======================Testing Bonus Part================" << endl;
    cout << "-------------------------------------------------------------\n" << endl;
    Date marginDate(2021,9,25,12,2);
    library.update(marginDate);
    library.printReservations();


    return 0;
}