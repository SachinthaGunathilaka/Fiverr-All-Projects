#include "Show.h"
#include <ostream>
#include <string>
#include <vector>

class Schedule {
  public:
    Schedule();
    Schedule(const Schedule &other);
    Schedule operator+=(const Show &show);
    Schedule operator+=(const Schedule &other);
    Schedule operator+(const Schedule &other);
    Schedule operator-=(const int id);
    void operator=(const Schedule &other);
    std::size_t size() const;
    Show &operator[](int index);
    friend std::ostream &operator<<(std::ostream &os, const Schedule &schedule);

  private:
    std::vector<Show> shows_;
    bool overlaps(Show s1, Show s2);
};
