// Created by kleymuner2131 on 12.04.25.
#include <string>
#include <vector>
#include <sstream>

class Calculator
{
public:
    float evaluateExpression(const std::string& expression);

private:
    std::vector<std::string> tokenize(const std::string& expression);
    float parseTokens(std::vector<std::string>& tokens);
    float applyOperator(float left, float right, const std::string& op);
};

std::vector<std::string> Calculator::tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(expression);

    // Split the expression into tokens
    while (ss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

float Calculator::applyOperator(float left, float right, const std::string& op) {
    // Apply the operator to the left and right operands
    if (op == "+") return left + right;
    if (op == "-") return left - right;
    if (op == "*") return left * right;
    if (op == "/" && right != 0) return left / right;
    return 0.0;
}

float Calculator::parseTokens(std::vector<std::string>& tokens) {
    // Evaluate the expression by applying operators in the correct order
    while (tokens.size() > 1) {
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            // Check for multiplication and division operators
            if (*it == "*" || *it == "/") {
                float left = std::stof(*(it - 1));
                float right = std::stof(*(it + 1));
                float result = applyOperator(left, right, *it);
                it = tokens.erase(it - 1, it + 2);
                tokens.insert(it, std::to_string(result));
                break;
            }
        }
        for (auto it = tokens.begin(); it != tokens.end(); ++it) {
            // Check for addition and subtraction operators
            if (*it == "+" || *it == "-") {
                float left = std::stof(*(it - 1));
                float right = std::stof(*(it + 1));
                float result = applyOperator(left, right, *it);
                it = tokens.erase(it - 1, it + 2);
                tokens.insert(it, std::to_string(result));
                break;
            }
        }
    }
    // Return the final result
    return std::stof(tokens.front());
}

float Calculator::evaluateExpression(const std::string& expression) {
    // Tokenize the expression and evaluate it
    std::vector<std::string> tokens = tokenize(expression);
    return parseTokens(tokens);
}