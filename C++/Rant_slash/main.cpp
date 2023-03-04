#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class robot {
private:
    int x;
    int y;
    int total_distance;

public:
    robot() {
        x = 0;
        y = 0;
        total_distance = 0;
    }

    void move_north() {
        y--;
        total_distance++;
    }

    void move_east() {
        x++;
        total_distance++;

    }

    void move_south() {
        y++;
        total_distance++;

    }

    void move_west() {
        x--;
        total_distance++;

    }

    int north() const {
        return y;
    }

    int east() const {
        return x;
    }

    int travelled() const {
        return total_distance;
    }


};

int distance(const robot &r);


class game {
private:

    map<string, robot *> robots;
    int total_robots;

    static bool comparator(pair<string, robot *> &a,
                           pair<string, robot *> &b) {
        return distance(*a.second) < distance(*b.second);
    }

public:
    game() {
        total_robots = 0;
    }

    int num_robots() const {
        return total_robots;
    }

    void move(const string &name, int dir) {
        if (robots.find(name) == robots.end()) {
            robots[name] = new robot();
        }

        if (dir == 0)
            robots[name]->move_north();

        else if (dir == 1)
            robots[name]->move_east();

        else if (dir == 2)
            robots[name]->move_south();

        else
            robots[name]->move_west();


    }

    int num_within(int n) const {
        int result = 0;
        for (const auto &p: robots) {
            if (distance(*p.second) <= n) {
                result++;
            }
        }

        return result;
    }

    int max_travelled() const {
        int max_distance = 0;
        for (const auto &p: robots) {
            if (max_distance < p.second->travelled()) {
                max_distance = p.second->travelled();
            }
        }


        return max_distance;
    }

    vector<string> robots_by_distance() const {
        vector<pair<string, robot *> > robots_vector;
//        string, robot *
        vector<string> robots_names;

        for (auto &it: robots) {
            robots_vector.emplace_back(it);
        }

        sort(robots_vector.begin(), robots_vector.end(), comparator);

        for (auto &it: robots_vector) {
            robots_names.push_back(it.first);
        }

        return robots_names;
    }


    void display() {

        for (auto &it: robots) {
            cout << it.second->north() << " " << it.second->east() << " " << it.second->travelled() << " "
                 << distance(*it.second) << endl;
        }

    }

};

int distance(const robot &r) {
    return abs(r.east()) + abs(r.north());
}


// For testing
//int main() {
//
//    game game1;
//    game1.display();
//    game1.move("robot1", 0);
//    game1.move("robot1", 1);
//    game1.move("robot1", 1);
//    game1.move("robot1", 1);
//    game1.move("robot1", 2);
//    game1.move("robot2", 2);
//    game1.move("robot2", 3);
//    game1.move("robot3", 3);
//    game1.display();
//    cout << game1.num_within(0) << endl;
//    cout << game1.num_within(1) << endl;
//    cout << game1.num_within(2) << endl;
//    cout << game1.max_travelled() << endl;
//
//    vector<string> result = game1.robots_by_distance();
//    for (auto &it: result) {
//        cout << it << endl;
//    }
//
//    return 0;
//}
