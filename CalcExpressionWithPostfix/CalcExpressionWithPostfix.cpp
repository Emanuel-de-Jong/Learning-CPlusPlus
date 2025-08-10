#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <vector>
#include <sstream>

using std::cin;
using std::cout;
using std::string;

void removeUnwantedChars(string& expr) {
    int end = expr.size();
    char c;
    char wantedChars[] = { '(', ')', '{', '}', '[', ']', '+', '-', '*', '/' };
    for (int i = 0; i < end; i++) {
        char c = expr[i];
        if (!std::isdigit(c) && std::find(std::begin(wantedChars), std::end(wantedChars), c) == std::end(wantedChars)) {
            expr.erase(i, 1);
            i--;
            end--;
        }
    }
}

void addParentheses(string& expr) {
    char c;
    for (int i = 0; i < expr.size(); i++) {
        c = expr[i];
        if (c == '*' || c == '/') {

        }
    }
}

void infixToPostfix(string& expr) {
    char c;
    char oper = NULL;
    for (int i = 0; i < expr.size(); i++) {
        c = expr[i];

        if (c == '*' || c == '/') {
            oper = c;
            expr[i] = ',';
            i++;
        }
        else if (c == ')') {
            expr.insert(i, string(1, oper));
            i += 3;
        }
    }
}

void removeParentheses(string& expr) {
    int end = expr.size();
    char parentheses[] = { '(', ')', '{', '}', '[', ']' };
    for (int i = 0; i < end; i++) {
        if (std::find(std::begin(parentheses), std::end(parentheses), expr[i]) != std::end(parentheses)) {
            expr.erase(i, 1);
            i--;
            end--;
        }
    }
}

string calcPostfix(string& operand1, string& operand2, char oper) {
    string sum;
    if (oper == '*') {
        sum = std::to_string(stoi(operand1) * stoi(operand2));
    }
    else if (oper == '/') {
        sum = std::to_string(stoi(operand1) / stoi(operand2));
    }

    return sum;
}

int calcExpression(string& originalExpr) {
    string expr = originalExpr;
    string operand1;
    string operand2;
    char c;
    int i = 0;
    int prevI = 0;
    while (i != expr.size()) {
        for (i = 0; i < expr.size(); i++) {
            c = expr[i];

            if (c == ',') {
                operand1 = operand2;
                operand2 = "";
            }
            else if (c == '*' || c == '/') {
                break;
            }
            else {
                operand2.push_back(c);
            }
        }

        cout << operand1 << "\t"
            << operand2 << "\t"
            << c << "\t"
            << expr << "\n";

        if (i != expr.size()) {
            cout << prevI << "\t"
                << ((i - prevI) + 1) << "\t"
                << (i - 1) << "\t"
                << calcPostfix(operand1, operand2, c) << "\n\n";

            expr.erase(prevI, ((i - prevI) + 1));
            prevI = (i - 1);

            expr.insert(0, ",");
            expr.insert(0, calcPostfix(operand1, operand2, c));
        }
    }

    expr.pop_back();

    int total = 0;
    std::stringstream exprStream(expr);
    string numb;
    while (exprStream.good())
    {
        getline(exprStream, numb, ',');
        cout << numb << " ";
        total += stoi(numb);
    }

    cout << "\n\n";

    return total;
}

int main()
{
    clock_t time = clock();

    string expr = "(15 * 52)(1655 / 5)(13 * 5)(2 * 5)(4 / 4)";
    removeUnwantedChars(expr);
    addParentheses(expr);
    infixToPostfix(expr);
    removeParentheses(expr);
    int total = calcExpression(expr);

    cout << expr << "\n"
        << total << "\n"
        << clock() - time << "\n";
}