#include <stack>
#include <string>

namespace calculator {
    /** tells whether string has balanced or unbalanced parenthesis
      // @param string we are checking
      // @return returns true if it does have unbalanced parenthesis, false if it doesn't
      // Example (9 + 10) is valid
      // Example ((21 + 0) is not valid, parenthesis are not balanced
      // MUST USE A STACK!
    */
    bool unbalanced_paranthesis(std::string postfix_expression) {
        std::stack<char> paranthesis;

        for (int i = 0; i < postfix_expression.size(); ++i) {
            if (postfix_expression[i] == '(') {
                paranthesis.push('(');
            } else if (postfix_expression[i] == ')') {
                if (!paranthesis.empty() && paranthesis.top() == '(') {
                    paranthesis.pop();
                } else {
                    return false;
                }
            }
        }

        if (!paranthesis.empty())
            return false;
        return true;
    }

    /** Helper function that tells whether the char is an operator
    // @param char we are checking
    // @return returns true if the char is an operator, and false if it isn't
    */
    bool isOperator(char sub_string) {
        if (sub_string == '+' || sub_string == '-' || sub_string == '*' || sub_string == '/') {
            return true;
        }
        return false;
    }

    /** Helper function that checks if char is an int
    // @param char we are checking
    // @return returns true if the char is an int, and false if it isn't
    */
    bool isInteger(char sub_string) {
        if (sub_string > 47 && sub_string < 58) {
            return true;
        }
        return false;
    }

    /** tells whether there is an illegal operator or not (such as ^ or factorial !)
      // @param string we checking, the infix expression
      // @return returns true if it doesn't have illegal operator
        An example of an illegal expression (you'll get the FBI on you):
        `( 2 + 3 ) ^ 2`
        An example of a legal expresion:
        (5 + 2 ) * 3 / 2 -    5
        ^Notice the extra white space, white space does NOT make it illegal
   */
    bool legalOperator(std::string s) {
        for (int i = 0; i < s.size(); ++i) {
            if (isInteger(s[i]) || isOperator(s[i]) || s[i] == '(' || s[i] == ')' || s[i] == ' ')
                continue;

            return false;
        }

        return true;
    }

    /**
      // check for precedence, multiplication and division return a higher number than addition and subtraction
      // Useful for PEMDAS
      @pre assumes op is either one of the following: *, /, +, -
      @return 2 if op == "*" or "/", 1 if op == "+" or "-"
    */
    int precedence(char op) {
        if (op == '*' || op == '/')
            return 2;

        else if (op == '+' || op == '-')
            return 1;
        return 0;
    }

    /** Converts infix expression to postfix expression
   // @param string to convert
   // @return returns the correct postfix expression if its a valid infix expression
   // @return "Not a valid expression!" if it is not a valid infix expression (has illegal characters or unbalanced paranthesis)
   // Example: input: â€œ3 - (134 + 76)"  output: "3 134 76 + -"
   */
    std::string convertToPostfix(std::string infix_expression) {
        if (!unbalanced_paranthesis(infix_expression) || !legalOperator(infix_expression))
            return "Not a valid expression!";

        std::string result;
        std::stack<char> operator_stack;

        std::string number;
        bool checkingNumber = false;

        for (int i = 0; i < infix_expression.size(); ++i) {

            if (checkingNumber && (!isInteger(infix_expression[i]))) {
                result += number + " ";
                number = "";
                checkingNumber = false;
            }
            if (infix_expression[i] == ' ')
                continue;

            if (isInteger(infix_expression[i])) {
                checkingNumber = true;
                number += infix_expression[i];
            } else if (infix_expression[i] == '(') {
                operator_stack.push('(');
            } else if (infix_expression[i] == ')') {
                while (operator_stack.top() != '(') {
                    result += operator_stack.top();
                    result += " ";
                    operator_stack.pop();
                }
                operator_stack.pop();
            } else {
                while (!operator_stack.empty() &&
                       (precedence(infix_expression[i]) <= precedence(operator_stack.top()))) {
                    result += operator_stack.top();
                    result += " ";

                    operator_stack.pop();
                }
                operator_stack.push(infix_expression[i]);
            }
        }

        if (!number.empty()) {
            result += number + " ";
        }
        while (!operator_stack.empty()) {
            result += operator_stack.top();
            result += " ";
            operator_stack.pop();
        }


        return result;

    }

    /** calculates post fix expression
      // @param post fix expression
      // @return result (as a string) if valid expression
      // @return "Not a valid expression" if the parameter postfix_expression is "Not A valid expression!"
   */

    std::stack<double> values;

    std::string calculatePostfix(std::string postfix_expression) {
        double result;


        std::string number;
        bool checkingNumber = false;
        if (postfix_expression == "Not a valid expression!") {
            return "Not a valid expression!";
        }
        for (int i = 0; i < postfix_expression.size(); ++i) {

            if (checkingNumber && (!isInteger(postfix_expression[i]))) {
                values.push(std::stoi(number));
                number = "";
                checkingNumber = false;
            }

            if (postfix_expression[i] == ' ')
                continue;

            if (isInteger(postfix_expression[i])) {
                checkingNumber = true;
                number += postfix_expression[i];
            } else {
                double value1 = values.top();
                values.pop();
                double value2 = values.top();
                values.pop();
                if (postfix_expression[i] == '+') {
                    result = value2 + value1;
                } else if (postfix_expression[i] == '-') {
                    result = value2 - value1;
                } else if (postfix_expression[i] == '*') {
                    result = value2 * value1;
                } else if (postfix_expression[i] == '/') {
                    result = value2 / value1;
                }
                values.push(result);
            }
        }

        return std::to_string(result);
    }
}


int main(){
    return 0;
}