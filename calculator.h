// Created by kleymuner2131 on 26.03.25.

#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include <vector>
#include <algorithm>


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
    const char chars[6] = {'*', '/', '+', '-', '(', ')'};
    std::vector<std::string> result;
    std::string number;
    for (int i = 0; i < main.size(); i++)
    {
        if (std::find(chars, chars + 6, main[i]) == std::end(chars))
        {
            number += main[i];
        }
        else
        {
            if (number != ""){result.push_back(number); number = "";}
            else {result.push_back(std::string(1, main[i]));}
        }
    }
    return result;
}
//! Эта функция должна расставлять приоритеры подсчета, действие за действием решая их
float analitic_prioritet(std::vector<std::string> analized)
{
    float answer;
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
            for (int i = begin; i < end; i++)
            {
                if (analized[i] == "*")
                {
                    float currentInt = std::stoi(analized[i-1]) * std::stoi(analized[i]);
                    analized.erase(analized.begin() + i-1); // Так как все автоматически подгоняется
                    analized.erase(analized.begin() + i-1);
                    analized[i-1] = currentInt;
                }
                else if (analized[i] == "/")
                {
                    if (analized[i+1] != "0")
                    {
                        float currentInt = std::stoi(analized[i-1]) / std::stoi(analized[i]);
                        analized.erase(analized.begin() + i-1); // Так как размер автоматически уменьшается
                        analized.erase(analized.begin() + i-1);
                        analized[i-1] = currentInt;
                    }
                }
                else if (analized[i] == "+")
                {
                    float currentInt = std::stoi(analized[i-1]) + std::stoi(analized[i]);
                    analized.erase(analized.begin() + i-1);
                    analized.erase(analized.begin() + i-1);
                    analized[i-1] = currentInt;
                }
                else if (analized[i] == "-")
                {
                    float currentInt = std::stoi(analized[i-1]) - std::stoi(analized[i]);
                    analized.erase(analized.begin() + i-1);
                    analized.erase(analized.begin() + i-1);
                    analized[i-1] = currentInt;
                }
            }
            analized.erase(analized.begin()+ begin);
            analized.erase(analized.begin()+ begin);
        }
        else if (begin == end)// Если нет скобок - то проверка от начала -> до конца
        {
            for (int i = 0; i < analized.size(); i++)
            {
                if (analized[i] == "*")
                {
                    float currentInt = std::stoi(analized[i-1]) * std::stoi(analized[i]);
                    analized.erase(analized.begin() + i-1); // Так как все автоматически подгоняется
                    analized.erase(analized.begin() + i-1);
                    analized[i-1] = currentInt;
                }
                else if (analized[i] == "/")
                {
                    if (analized[i+1] != "0")
                    {
                        float currentInt = std::stoi(analized[i-1]) / std::stoi(analized[i]);
                        analized.erase(analized.begin() + i-1); // Так как размер автоматически уменьшается
                        analized.erase(analized.begin() + i-1);
                        analized[i-1] = currentInt;
                    }
                }
                else if (analized[i] == "+")
                {
                    float currentInt = std::stoi(analized[i-1]) + std::stoi(analized[i]);
                    analized.erase(analized.begin() + i-1);
                    analized.erase(analized.begin() + i-1);
                    analized[i-1] = currentInt;
                }
                else if (analized[i] == "-")
                {
                    float currentInt = std::stoi(analized[i-1]) - std::stoi(analized[i]);
                    analized.erase(analized.begin() + i-1);
                    analized.erase(analized.begin() + i-1);
                    analized[i-1] = currentInt;
                }
            }
        }

    }

    return answer;
}

float answer(std::string main)
{
    //* После этой строки у меня есть массив со всеми символами и числами
    std::vector<std::string> analized = analitic_make(main);
    float answer = analitic_prioritet(analized);

    return answer;
}



#endif //CALCULATOR_H
