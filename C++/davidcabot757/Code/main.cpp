#include <iostream>
#include <cmath>

using namespace std;
int main() {
    int length;
    int width;
    int sq_feet_for_quart;
    int cost_per_quart;

    cout << "\nEnter length(feet) : ";
    cin >> width;

    cout << "Enter width(feet) : ";
    cin >> length;

    cout << "Enter number of square feet each quart of paint covers(square feet) : ";
    cin >> sq_feet_for_quart;

    cout << "Enter cost per quarts : $";
    cin >> cost_per_quart;

    int surface_area = length * width;
    float num_of_quarts_float = ceil(surface_area * 1.0 / sq_feet_for_quart);
    int num_of_quarts = num_of_quarts_float;

    if(num_of_quarts_float > num_of_quarts)
        num_of_quarts++;

    int cost = num_of_quarts * cost_per_quart;

    cout << "\nSurface area : " << surface_area << " feet" << endl;
    cout << "Number of quarts : " << num_of_quarts << " feet" << endl;
    cout << "Total cost : $" << cost << endl;


    return 0;
}
