#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class rational {
  public:
    rational();
    ~rational();
    rational(int numerator);
    rational(int numerator, int denominator);

    void input();
    void output() const;
    int GetNumerator();
    int GetDenominator();
    void Add(const rational &other);
    void Subtract(const rational &other);
    void Multiply(const rational &other);
    void Divide(const rational &other);

  private:
    int numerator;
    int denominator;
};

int main() {
    char oper;
    rational result;
    rational operand;

    cout << "Enter op1 (in the format of p/q): ";
    result.input();

    do {
        cout << "\nEnter operator [+, -, /, *, =, c(lear), a(ccessors), "
                "q(uit)]: ";
        cin >> oper;
        if (oper == '+' || oper == '-' || oper == '*' || oper == '/') {
            cout << "\nEnter op2 (in the format of p/q): ";
            operand.input();
            switch (oper) {
            case '+':
                result.Add(operand);
                break;
            case '-':
                result.Subtract(operand);
                break;
            case '*':
                result.Multiply(operand);
                break;
            case '/':
                result.Divide(operand);
                break;
            }
        } else if (oper == '=') {
            cout << "result = ";
            result.output();
            cout << endl;
        } else if (oper == 'c') {
            cout << "Enter op1 (in the format of p/q): ";
            result.input();
        } else if (oper == 'a') {
            cout << "result's numerator: " << result.GetNumerator() << endl;
            cout << "result's denominator: " << result.GetDenominator() << endl;
        }
    } while (oper != 'q');
    return 0;
}

rational::rational() {
    numerator = 0;
    denominator = 1;
}

rational::~rational() {}

rational::rational(int numerator) : numerator(numerator) {}

rational::rational(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {}

void rational::input() {
    string s_numerator, s_denominator;
    getline(cin, s_numerator, '/');
    getline(cin, s_denominator);
    numerator = stoi(s_numerator);
    denominator = stoi(s_denominator);
}
void rational::output() const { cout << numerator << "/" << denominator; }

int rational::GetNumerator() { return numerator; }

int rational::GetDenominator() { return denominator; }

void rational::Add(const rational &other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
}

void rational::Subtract(const rational &other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
}

void rational::Multiply(const rational &other) {
    numerator *= other.numerator;
    denominator *= other.denominator;
}

void rational::Divide(const rational &other) {
    rational inverted(other.denominator, other.numerator);
    inverted.Multiply(*this);
    *this = inverted;
}
