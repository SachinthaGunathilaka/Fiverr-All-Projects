#include "Schedule.h"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    Schedule s;
    Show a("Secret Agent XN-13770164", "Spy Television", 0, 7);
    const Schedule s2(s);
    const Show b("War War War", "War", 7, 24 * 4 - 7, true);
    assert(b.name() == "War War War");
    assert(b.channel() == "War");
    assert(b.start() == 105);
    assert(b.length() == 1335);
    assert(!a.adult());
    assert(b.adult());
    assert(!(a.id() < 0));
    assert(!(b.id() < 0));
    assert(a.id() != b.id());
    s += a;
    s += b;
    std::cout << s << "---\n";
    assert(s.size() == 2);
    bool caught = false;
    try {
        s -= -16;
    } catch (const std::runtime_error &) {
        caught = true;
    }
    assert(caught);
    assert(s.size() == 2);
    s -= a.id();
    assert(s.size() == 1);
    std::cout << s << "---\n";
    s -= b.id();
    assert(s.size() == 0);
    std::cout << s << "---\n";

    Schedule love;
    love += Show("Love Isthmus", "LUV", 0, 7, true);
    Schedule war;
    war += Show("Trek Wars: Spock vs. Vader", "SyFi", 0, 7, false);
    Schedule life;
    life = s2; // will soon be overwritten
    life += a; // will soon be overwritten
    life = love + war;
    assert(life.size() == 2);
    std::cout << life << "---\n";
    assert(life[0].channel() == "LUV" || life[1].channel() == "LUV");
    assert(life[0].channel() == "SyFi" || life[1].channel() == "SyFi");

    caught = false;
    try {
        std::cout << life[987].name();
    } catch (const std::range_error &r) {
        caught = true;
        const std::string message = r.what();
        assert(message.find("987") != std::string::npos); // bad index
        assert(message.find("2") != std::string::npos);   // current size
    }
    assert(caught);
    return 0;
}
