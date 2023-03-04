#include "Schedule.h"
#include <algorithm>
#include <stdexcept>

Schedule::Schedule() {}

Schedule::Schedule(const Schedule &other) { shows_ = other.shows_; }

void Schedule::operator=(const Schedule &other) { shows_ = other.shows_; }

Schedule Schedule::operator+=(const Show &show) {
    for (auto s : shows_) {
        if (overlaps(show, s))
            throw std::runtime_error("Show overlaps with existing show.");
    }
    shows_.push_back(show);
    return *this;
}

Schedule Schedule::operator+=(const Schedule &other) {
    for (auto show : other.shows_) {
        for (auto s : shows_) {
            if (overlaps(show, s))
                throw std::runtime_error("Show overlaps with existing show.");
        }
    }
    std::copy(other.shows_.begin(), other.shows_.end(),
              std::back_inserter(shows_));
    return *this;
}

Schedule Schedule::operator+(const Schedule &other) {
    Schedule schedule(*this);
    schedule += other;
    return schedule;
}

Schedule Schedule::operator-=(const int id) {
    int index = -1;
    for (size_t i = 0; i < shows_.size(); i++) {
        if (shows_[i].id() == id)
            index = i;
    }
    if (index == -1)
        throw std::runtime_error("No such show in schedule.");
    shows_.erase(shows_.begin() + index);
    return *this;
}

std::size_t Schedule::size() const { return shows_.size(); }

Show &Schedule::operator[](int index) {
    if (index >= (int)shows_.size() || index < 0)
        throw std::range_error(
            "Invalid index: " + std::to_string(index) +
            ". Number of available shows: " + std::to_string(size()));
    return shows_[index];
}

std::string formatTime(int t) {
    std::string s = "";
    int h = t / 60;
    int m = t % 60;
    if (h < 10)
        s += '0';
    s += std::to_string(h);
    s += ':';
    if (m < 10)
        s += '0';
    s += std::to_string(m);
    return s;
}

std::ostream &operator<<(std::ostream &os, const Schedule &schedule) {
    for (std::size_t i = 0; i < schedule.size(); i++) {
        Show s = schedule.shows_[i];
        os << formatTime(s.start()) << " " << formatTime(s.start() + s.length())
           << " " << s.channel() << " " << s.name() << (s.adult() ? "*" : "")
           << "\n";
    }
    return os;
}

bool Schedule::overlaps(Show s1, Show s2) {
    int a0 = s1.start();
    int a1 = s1.start() + s1.length();
    int b0 = s2.start();
    int b1 = s2.start() + s2.length();
    return s1.channel() == s2.channel() &&
           std::max(0, std::min(a1, b1) - std::max(a0, b0));
}
