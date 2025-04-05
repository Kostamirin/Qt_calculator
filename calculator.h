// Created by kleymuner2131 on 26.03.25.

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <format>


bool bracketsBalanced(const std::string& input)
{
    int balance = 0;

    for (char ch : input)
    {
        if (ch == '(')
        {
            ++balance;
        }
        else if (ch == ')')
        {
            --balance;
            if (balance < 0)
            {
                return false; // Encountered a closing bracket without a matching opening bracket
            }
        }
    }

    return balance == 0; // True if all brackets are balanced
}

std::vector<std::string> analitic_make(std::string main)
{
    constexpr char chars[] = {'+', '-', '*', '/', '(', ')'};
    std::vector<std::string> result = {};
    std::string number = "";
    for (char ch : main)
    {
        // Если символ не нашелся, то:
        if (std::find(std::begin(chars), std::end(chars), ch) == std::end(chars))
        {
            number += ch;
        }
        else
        {
            result.push_back(number);
            number = "";
            result.push_back(std::string(1, ch));
        }
    }
    return result;
}
//! Эта функция решает текст, расставляя приоритеты в тексте, удаляя решенные примеры
float analitic_prioritet(std::vector<std::string> analized)
{
    float answer = 0.0;
    int begin = 0;
    int end = 0;

    while (analized.size() != 1)
    {
        for (int i = 0; i < analized.size(); i++)
        {
            if (analized[i] == "("){begin = i;}
            else if (analized[i] == ")"){end = i;}
        }
        if (begin != end) // Если есть скобки + начало с самых внутренних
        {
            for (int i = begin + 1; i < end; i++)
            {
                if (analized[i] == "*")
                {
                    float currentInt = std::stof(analized[i-1]) * std::stof(analized[i+1]);
                    analized.erase(analized.begin() + i + 1); // Удаляем операнд
                    analized.erase(analized.begin() + i); // Удаляем оператор
                    analized[i-1] = std::to_string(currentInt);
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (analized[i] == "/")
                {
                    if (analized[i+1] != "0")
                    {
                        float currentInt = std::stof(analized[i-1]) / std::stof(analized[i+1]);
                        analized.erase(analized.begin() + i + 1); // Удаляем операнд
                        analized.erase(analized.begin() + i); // Удаляем оператор
                        analized[i-1] = std::to_string(currentInt);
                        i--; // Чтобы не пропустить следующий элемент
                    }
                }
                else if (analized[i] == "+")
                {
                    float currentInt = std::stof(analized[i-1]) + std::stof(analized[i+1]);
                    analized.erase(analized.begin() + i + 1); // Удаляем операнд
                    analized.erase(analized.begin() + i); // Удаляем оператор
                    analized[i-1] = std::to_string(currentInt);
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (analized[i] == "-")
                {
                    float currentInt = std::stof(analized[i-1]) - std::stof(analized[i+1]);
                    analized.erase(analized.begin() + i + 1); // Удаляем операнд
                    analized.erase(analized.begin() + i); // Удаляем оператор
                    analized[i-1] = std::to_string(currentInt);
                    i--; // Чтобы не пропустить следующий элемент
                }
            }
        }
    }

    return std::stof(analized[0]);
}
float answer(std::string main)
{
    //* После этой строки у меня есть массив со всеми символами и числами
    std::vector<std::string> analized = analitic_make(main);
    float answer = analitic_prioritet(analized);

    return answer;
}



#endif //CALCULATOR_H
