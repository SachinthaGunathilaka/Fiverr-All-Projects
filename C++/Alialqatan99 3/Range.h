#ifndef HW7_RANGE_H
#define HW7_RANGE_H

#include <algorithm>
#include <istream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>

template <class T> class Range {
  public:
    Range<T>() = default;
    ~Range<T>() = default;
    Range<T>(T val);
    Range<T>(T low, T high);
    Range<T>(const Range &other);
    Range<T> &operator=(const Range<T> &other);
    Range<T> &operator+=(const Range<T> &other);
    Range<T> &operator-=(const Range<T> &other);
    Range<T> &operator*=(const Range<T> &other);
    Range<T> &operator/=(const Range<T> &other);
    Range<T> operator+(const Range<T> &other) const;
    Range<T> operator-(const Range<T> &other) const;
    Range<T> operator*(const Range<T> &other) const;
    Range<T> operator/(const Range<T> &other) const;
    bool operator==(const Range<T> &other);
    bool operator!=(const Range<T> &other);
    template <class U>
    friend std::ostream &operator<<(std::ostream &out, const Range<U> &r);
    template <class U>
    friend std::istream &operator>>(std::istream &in, Range<U> &r);
    void assign(T low, T high);
    T min();
    T max();
    static std::string str(T low, T high);

  private:
    T low;
    T high;
};

template <class T> Range<T>::Range(T val) { assign(val, val); };
template <class T> Range<T>::Range(T low, T high) { assign(low, high); }
template <class T> Range<T>::Range(const Range &other) {
    assign(other.low, other.high);
}

template <class T> void Range<T>::assign(T low, T high) {
    if (low > high)
        throw std::runtime_error("out of order: " + str(low, high));
    this->low = low;
    this->high = high;
}

template <class T> T Range<T>::min() { return low; }
template <class T> T Range<T>::max() { return high; }

template <class T> Range<T> &Range<T>::operator=(const Range<T> &other) {
    low = other.low;
    high = other.high;
    return *this;
}

template <class T> Range<T> &Range<T>::operator+=(const Range<T> &other) {
    low += other.low;
    high += other.high;
    return *this;
}

template <class T> Range<T> &Range<T>::operator-=(const Range<T> &other) {
    low -= other.high;
    high -= other.low;
    return *this;
}

template <class T> Range<T> &Range<T>::operator*=(const Range<T> &other) {
    T a = low * other.low;
    T b = low * other.high;
    T c = high * other.low;
    T d = high * other.high;
    low = std::min({a, b, c, d});
    high = std::max({a, b, c, d});
    return *this;
}

template <class T> Range<T> &Range<T>::operator/=(const Range<T> &other) {
    if (!other.low || !other.high)
        throw std::runtime_error(
            "division by zero: " + Range<T>::str(low, high) + " " +
            Range<T>::str(other.low, other.high));
    low /= other.high;
    high /= other.low;
    return *this;
}

template <class T> Range<T> Range<T>::operator+(const Range<T> &other) const {
    Range<T> t(*this);
    t += other;
    return t;
}

template <class T> Range<T> Range<T>::operator-(const Range<T> &other) const {
    Range<T> t(*this);
    t -= other;
    return t;
}

template <class T> Range<T> Range<T>::operator*(const Range<T> &other) const {
    Range<T> t(*this);
    t *= other;
    return t;
}

template <class T> Range<T> Range<T>::operator/(const Range<T> &other) const {
    Range<T> t(*this);
    t /= other;
    return t;
}

template <class T> bool Range<T>::operator==(const Range<T> &other) {
    return low == other.low && high == other.high;
}

template <class T> bool Range<T>::operator!=(const Range<T> &other) {
    return !(this == other);
}

template <class T>
std::ostream &operator<<(std::ostream &out, const Range<T> &r) {
    out << "[" << r.low << "," << r.high << "]";
    return out;
}

template <class T> std::istream &operator>>(std::istream &in, Range<T> &r) {
    char c;
    std::string s, t;
    T a, b;
    while (c != ']') {
        in >> c;
        s += c;
    }
    try {
        if (s[0] != '[' || s[s.length() - 1] != ']')
            throw std::runtime_error("brackets");
        s = s.substr(1, s.length() - 2);
        s.replace(s.find(","), 1, " ");
        std::istringstream iss(s);
        iss >> a >> b;
        r.assign(a, b);
    } catch (...) {
        in.setstate(std::ios::failbit);
    }
    return in;
}

template <class T> std::string Range<T>::str(T low, T high) {
    return "[" + std::to_string(low) + "," + std::to_string(high) + "]";
}

#endif
