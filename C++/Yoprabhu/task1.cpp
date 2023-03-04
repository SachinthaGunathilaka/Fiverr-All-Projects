#include <iostream>
#include <sstream>
#include <vector>

class LispExpression {
private:
    std::vector<std::string> expressions;
public:
    friend std::istream &operator>>(std::istream &data, LispExpression &l) {
        std::string expression;
        int open_brackets = 0, close_brackets = 0;
        while (data >> expression) {
            if(expression == "(")
                open_brackets++;

            else if(expression == ")")
                close_brackets++;
            l.expressions.push_back(expression);

            if((open_brackets != 0) && (open_brackets == close_brackets))
                return data;
        }
        return data;
    }

    friend std::ostream &operator<<(std::ostream &output, const LispExpression &l) {
        int spaces = 0;
        for (int i = 0; i < l.expressions.size(); ++i) {
            if (l.expressions[i] == ")")
                spaces--;

            output << std::string(spaces, ' ') << l.expressions[i] << "\n";

            if (l.expressions[i] == "(")
                spaces++;

        }
        return output;
    }
};

int main() {
//    std::istringstream iss(" (  one two ( three )   ) ");
//    LispExpression le;
//    iss >> le;
//    std::cout << le;


    std::istringstream iss(" ( ) ( 2 3 ( 2 ) ( ) )");
    LispExpression le1;
    LispExpression le2;
    iss >> le1 >> le2;
    LispExpression const le3 = le2;
    std::ostringstream oss;
    oss << "le1: " << le1 << "le3: " << le3;
    std::cout << "le1: " << le1 << "le3: " << le3;
//    ASSERT_EQ(oss.str(), "le1: (\n)\nle3: (\n 2\n 3\n (\n  2\n )\n (\n )\n)\n");

    return 0;
}
