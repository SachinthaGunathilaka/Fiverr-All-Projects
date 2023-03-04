// String.cpp
//
// Implement all of your String member functions in this file.
//
// Note that the entire standard library -- both the C Standard
// Library and the C++ Standard Library -- is off-limits for this
// task, as the goal is to exercise your low-level implementation
// skills (pointers, memory management, and so on).

#include "String.hpp"


String::String() {
    value = new char[100];
    size = 0;
}

String::String(const char *chars) {
    size = 0;
    value = new char[100];

    while (chars[size] != '\0'){
        value[size] = chars[size];
        size++;
    }
    value[size] = '\0';
}

String::String(const String &s) {
    size = 0;
    value = new char[100];

    while (s.value[size] != '\0'){
        value[size] = s.value[size];
        size++;
    }
    value[size] = '\0';
}

String::~String() noexcept {
    delete value;
}

bool String::isEmpty() const noexcept {
    return size == 0;
}

unsigned int String::length() const noexcept {
    return size;
}

const char *String::toChars() const noexcept {
    static char result[100];
    for (int i = 0; i < size; ++i) {
        result[i] = value[i];
    }
    result[size] = '\0';
    return result;
}

String &String::operator=(const String &s) {

    for (int i = 0; i < s.size; ++i) {
        value[i] = s.value[i];
    }
    value[s.size] = '\0';
    size = s.size;

    return const_cast<String &>(s);


}

void String::append(const String &s) {
    for (int i = 0; i < s.size; ++i) {
        value[size + i] = s.value[i];
    }
    value[size + s.size] = '\0';
    size = size + s.size;
}

char String::at(unsigned int index) const {
    if(index >= size){
        throw OutOfBoundsException();
    }
    return value[index];
}

char &String::at(unsigned int index) {
    if(index >= size){
        throw OutOfBoundsException();
    }
    return value[index];
}

void String::clear() {
    size = 0;
    value[0] = '\0';

}

int String::compareTo(const String &s) const noexcept {
    for (int i = 0; i < size; ++i) {
        if(value[i] < s.value[i])
            return -1;
        else if(value[i] > s.value[i])
            return 1;
    }

    return 0;
}

String String::concatenate(const String &s) const {
    String con_string;
    for (int i = 0; i < size; ++i) {
        con_string.value[i] = value[i];
    }

    for (int i = 0; i < s.size; ++i) {
        con_string.value[size + i] = s.value[i];
    }
    con_string.value[size + s.size] = '\0';
    con_string.size = size + s.size;
    return con_string;
//    size = size + s.size;
}

bool String::contains(const String &substring) const noexcept {
    int match_pos = 0;
    for (int i = 0; i < size; ++i) {
        if(value[i] != substring.value[match_pos]){
            match_pos = 0;
        }
        else{
            match_pos++;
            if(match_pos == substring.size)
                return true;

        }
    }

    return false;
}

bool String::equals(const String &s) const noexcept {
    if(size != s.size)
        return false;

    for (int i = 0; i < size; ++i) {
        if(value[i] != s.value[i])
            return false;

    }
    return true;
}

int String::find(const String &substring) const noexcept {
    int match_pos = 0;
    for (int i = 0; i < size; ++i) {
        if(value[i] != substring.value[match_pos]){
            match_pos = 0;
        }
        else{
            match_pos++;
            if(match_pos == substring.size)
                return i + 1 - substring.size;

        }
    }

    return -1;
}

String String::substring(unsigned int startIndex, unsigned int endIndex) const {

    if((startIndex >= size) || (endIndex >= size))
        throw OutOfBoundsException();
    String substring;
    for (unsigned int i = 0; i < endIndex-startIndex; ++i) {
        substring.value[i] = value[i + startIndex];
    }

    substring.size = endIndex - startIndex;
    return substring;
}
