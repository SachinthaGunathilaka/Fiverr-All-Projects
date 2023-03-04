#include "WaterPet.h"

WaterPet::WaterPet(string name, string color, double baseAdoptionFee, string water_type) : VirtualPet(name, color,
                                                                                                      baseAdoptionFee >=
                                                                                                      0
                                                                                                      ? baseAdoptionFee
                                                                                                      : 25) {
    if (water_type == "fresh" || water_type == "salt") {
        this->waterType = water_type;
    } else {
        this->waterType = "fresh";
    }
}

string WaterPet::getWaterType() {
    return waterType;
}


void WaterPet::printInfo() const {
    VirtualPet::printInfo();
    cout << "Water Type: " << waterType << endl;
};


#include <bits/stdc++.h>

using namespace std;

#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vector <int>, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.first << " " << x.second << endl
#define print2(a, x, y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl


template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }

template<typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

void solve() {

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double) (clock() - z) / CLOCKS_PER_SEC);

    return 0;
}