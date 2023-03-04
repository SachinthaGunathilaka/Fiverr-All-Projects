#include <string>

class Show {
  public:
    Show() = delete;
    Show(std::string name, std::string channel, int start, int length,
         bool adult = false);
    Show(const Show &obj);

    std::string name() const;
    std::string channel() const;
    int start() const;
    int length() const;
    bool adult() const;
    int id() const;
    bool operator<(const Show &other) const;

  private:
    static int id_counter;
    std::string name_;
    std::string channel_;
    int start_;
    int length_;
    bool adult_;
    int id_;
};
