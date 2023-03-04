#include "../Time.h"

using namespace std;

int main()
{
//    Time time();
//    cout << "Time with default constructor: " << time << endl;

    Time myTime(11,45);
    cout << "Time with parameterized constructor : " << myTime << endl;

    myTime.SetHours(5);
    cout << "After setting hours: " << myTime << endl;

    myTime.SetMinutes(15);
    cout << "Time: " << myTime << endl;

    cout << "The hour shows " << myTime.GetHours() << endl;

//    cout << "The minute shows " << myTime.GetMinutes() << endl;

    return 0;
}
