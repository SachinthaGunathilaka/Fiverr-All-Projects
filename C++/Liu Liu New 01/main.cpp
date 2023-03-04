
#include<iostream>
#include "String.hpp"
#include<cstring>

using namespace std;

int main() {

//    String word;
//    cout << word.isEmpty() << endl;
//    cout << word.length() << endl;
//    cout << strcmp(word.toChars(), "") << endl;

//    const char* chars = "Boo is snoring";
//
//    String s(chars);
//    s.print();
//    cout << s.isEmpty() << endl;
//    cout << s.length() << endl;
//    cout << strcmp(s.toChars(), "") << endl;
//    cout << strcmp(s.toChars(), "Boo is snoring") << endl;


//    const char* chars = "Boo wants to know what's over there";
//
//    String s{chars};
//    String t{s};
//
//    cout << (t.length() == 35) << endl;
//    cout << (strcmp(chars, t.toChars()) == 0) << endl;


//    const char *chars = "Boo is perfect";
//
//    String s{chars};
//    String t{"Hello"};
//
//    t = s;
//
//    t.print();
//
//    cout << (14 == t.length()) << endl;
//    cout << (strcmp(chars, t.toChars()) == 0) << endl;



//    const char* chars = "Boo is";
//    const char* moreChars = " the very best";
//
//    String s{chars};
//    String more{moreChars};
//    s.append(more);
//
//    cout << (20 == s.length()) << endl;
//    cout << (strcmp("Boo is the very best", s.toChars()) == 0) << endl;



//    const char *chars = "Boo!";
//
//    const String s{chars};
//
//    cout << (s.at(0) == 'B') << endl;
//    cout << (s.at(1) == 'o') << endl;
//    cout << (s.at(2) == 'o') << endl;
//    cout << (s.at(3) == '!') << endl;


//    const char* chars = "Boo is happy";
//
//    String s{chars};
//
//    s.at(7) = 'g';
//    s.at(8) = 'r';
//    s.at(9) = 'e';
//    s.at(10) = 'a';
//    s.at(11) = 't';
//
//    cout << (strcmp("Boo is great", s.toChars()) == 0) << endl;


//    const char* chars = "Boo!";
//
//    const String s{chars};
//    s.at(4);


//    const char* chars = "Boo!";
//
//    String s{chars};
//    s.at(4);
//    EXPECT_THROW({ s.at(4); }, OutOfBoundsException);


//    String s{"Boo is asleep"};
//    s.clear();
//
//    cout << (0 == s.length()) << endl;
//    cout << (strcmp("", s.toChars()) == 0) << endl;

//    String s{"Where is Boo?"};
//    String t{"Where is Boo?"};

//    cout << (0 == s.compareTo(t)) << endl;



//    String s{"earlier"};
//    String t{"later"};
//
//    cout << (-1 == s.compareTo(t)) << endl;


//    String s{"later"};
//    String t{"earlier"};
//
//    cout << (1 == s.compareTo(t)) << endl;



//    String s{"It is"};
//    String t{" great to see Boo"};
//    String c = s.concatenate(t);
//
//    cout << (22 == c.length()) << endl;
//    cout << (strcmp("It is great to see Boo", c.toChars()) == 0) << endl;


//    String s{"Is Boo great today?"};
//    String t{"Boo"};

//    cout << (s.contains(t)) << endl;

//    String s{"Boo is definitely great today"};
//    String t{"absolutely"};
//
//    cout << (s.contains(t)) << endl;



//    const char* chars = "Boo looks hungry";
//
//    String s{chars};
//    String t{chars};
//
//    cout << (s.equals(t)) << endl;
//
//    String s1{"Hello"};
//    String t1{"Boo"};
//
//    cout << (s1.equals(t1)) << endl;


//    String s{"Is Boo great today?"};
//    String t{"Boo"};
//
//    cout << (3 == s.find(t)) << endl;

//    String s{"Boo is definitely great today"};
//    String t{"absolutely"};
//
//    cout << (-1 == s.find(t)) << endl;


//    String s{""};
//
//    cout << (1 == s.isEmpty()) << endl;

//    String s{"Boo"};
//
//    cout << (0 == s.isEmpty()) << endl;

//    String s{"This is Boo's day"};
//
//    cout << (17 == s.length());


//
//    String s{"Every day is Boo's day"};
//    String t = s.substring(13, 16);
//
//    cout << (3 == t.length()) << endl;
//    cout << (strcmp("Boo", t.toChars()) == 0) << endl;


//    String s{"Boo's eyes are closed"};
//
//    s.substring(15, 100);

    const char* chars = "Boo is sleeping";

    String s{chars};

    cout << (strcmp(chars, s.toChars()) == 0) << endl;


    return 0;
}