#include "Show.h"
#include <stdexcept>
#include <string>

Show::Show(std::string name, std::string channel, int start, int length,
           bool adult) {
    if (name == "" || channel == "")
        throw std::runtime_error("Empty name or channel.");
    if (length < 0)
        throw std::runtime_error("Invalid length.");
    if (start < 0 || start * 15 >= 24 * 60 ||
        ((start * 15 + length * 15) % (24 * 60) < start * 15 + length * 15 &&
         (start * 15 + length * 15) % (24 * 60) != 0))
        throw std::runtime_error("Invalid start time.");
    name_ = name;
    channel_ = channel;
    start_ = start * 15;
    length_ = length * 15;
    adult_ = adult;
    id_ = ++id_counter;
}

Show::Show(const Show &obj) {
    name_ = obj.name_;
    channel_ = obj.channel_;
    start_ = obj.start_;
    length_ = obj.length_;
    adult_ = obj.adult_;
    id_ = obj.id_;
}

std::string Show::name() const { return name_; }

std::string Show::channel() const { return channel_; }

int Show::start() const { return start_; }

int Show::length() const { return length_; }

bool Show::adult() const { return adult_; }

int Show::id() const { return id_; }

int Show::id_counter = 0;

bool Show::operator<(const Show &other) const {
    if (start_ != other.start_)
        return start_ < other.start_;
    return channel_ < other.channel_;
}
