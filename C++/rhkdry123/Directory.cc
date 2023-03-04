#include "Directory.h"

#include <iomanip>
#include <sstream>

//DO NOT MODIFY THIS START
Entry *Directory::clone() const {
    return new Directory(*this);
}

Directory::Directory(const std::string &name) {
    this->name_ = name;
    this->count_ = 0;
}

Directory::Directory(const Directory &o) {
    this->name_ = o.name_;
    this->count_ = o.count_;
    for (int i = 0; i < count_; ++i) {
        this->entries_[i] = o.entries_[i];
    }
}

Directory::~Directory() {
    for (int i = 0; i < maxcount_; ++i) {
        delete this->entries_[i];
    }
}

const std::string &Directory::name() const {
    return name_;
}

void Directory::print(std::ostream &os, size_t indent) const {

    os <<  std::string (indent, ' ')  << "* " << name_ << std::endl;
    indent += 3;

    for (int i = 0; i < count_; ++i) {
        entries_[i]->print(os, indent);
    }
}

std::string Directory::content() const {
    std::string result = "";
    for (int i = 0; i < count_; ++i) {
        result += entries_[i]->name() + "\n";
    }
    return result;
}

size_t Directory::count() const {
    return this->count_;
}

Entry *Directory::find(const std::string &name) {
    for (int i = 0; i < count_; ++i) {
        if (entries_[i]->name() == name) {
            return entries_[i];
        }
    }

    return nullptr;
}

bool Directory::add(Entry *entry) {
    for (int i = 0; i < count_; ++i) {
        if (entries_[i]->name() == entry->name()) {
            return false;
        }
    }

    entries_[count_++] = entry;
    return true;
}

Entry *Directory::remove(const std::string &name) {
    int i;
    for (i = 0; i < count_; ++i) {
        if (entries_[i]->name() == name) {
            break;
        }
    }

    if (i == count_)
        return nullptr;

    Entry * entry_ = entries_[i];
    for (int j = i; j < count_-1; ++j) {
        entries_[j] = entries_[j+1];
    }

    entries_[count_-1] = nullptr;
    count_--;
    return entry_;

}

//DO NOT MODIFY THIS END

//Implement constructor, destructor, member functions of the Directory class.
//...
