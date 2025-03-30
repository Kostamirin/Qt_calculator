// Created by kleymuner2131 on 25.03.25.
#ifndef HELPER_H
#define HELPER_H
class alalitic
{
    public:
    float first(std::string main)
    {
        int to_left= 1;
        int to_right=1;
        std::vector<int> numbers;
        int first=0, last=0;
        const char chars[4] = {'*', '/', '+', '-'};
        for (int i = 0; i < main.size(); i++)
        {
            if (std::find(chars, chars + 4, main[i]) != std::end(chars))
            {
                std::vector<int> some;
                to_left=1;
                while (true)
                {
                    if (std::find(chars, chars + 4, main[i-to_left]) != std::end(chars))
                    {
                        break;
                    }
                    else
                    {
                        some.insert(some.begin(), main[i - to_left]);
                        to_left++;
                    }
                }
                for (int s = 0; s < some.size(); s++){if (s>0){first+=some[s] * pow(10,some.size()-s-1);}
                    else{first+=some[s] * pow(10,some.size()-s);}}
                to_right=1;
                while (true)
                {
                    if (std::find(chars, chars + 4, main[i+to_right]) != std::end(chars))
                    {
                        break;
                    }
                    else
                    {
                        some.push_back(main[i + to_right]);
                    }
                }

            }
        }
    }
};
#include <string>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <cmath>

// Функция обработки строки
double evaluateMathExpression(const std::string& expression) {
    std::stack<double> values; // Стек для чисел
    std::stack<char> operators; // Стек для операторов

    auto applyOperation = [](double a, double b, char op) -> double {
        switch (op) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/':
                if (b == 0) throw std::runtime_error("Divide by zero error");
                return a / b;
            default: throw std::runtime_error("Unknown operator");
        }
    };

    for (size_t i = 0; i < expression.size(); ++i) {
        char current = expression[i];

        // Пропускаем пробелы
        if (std::isspace(current)) {
            continue;
        }

        // Если это число
        if (std::isdigit(current)) {
            double value = 0.0;
            size_t j = i;
            while (j < expression.length() && (std::isdigit(expression[j]) || expression[j] == '.')) {
                ++j;
            }
            value = std::stod(expression.substr(i, j - i));
            values.push(value);
            i = j - 1; // Сдвинуть индекс
        }
        // Если это оператор
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            while (!operators.empty() &&
                   ((current == '+' || current == '-') ||
                    (current == '*' || current == '/'))) {
                double b = values.top(); values.pop();
                double a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(current);
        }
        else {
            throw std::runtime_error("Invalid character in expression");
        }
    }

    while (!operators.empty()) {
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

#endif //HELPER_H
