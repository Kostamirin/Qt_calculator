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
std::vector<std::string> analitic_prioritet(std::vector<std::string> analized)
{
    std::vector<std::string> result = analized;
    int begin = 0;
    int end = 0;
    char current = 0;
    char nextChar = 0;
    int currentInt = 0;
    while (analized.size() != 1)
    {
        //!Создать свой алгоритм для анализа
        //*возможно он остается у меня в голове к 28.мар
        for (int i = 0; i < analized.size(); i++)
        {
            if (analized[i] == "("){begin = i;}
            else if (analized[i] == ")"){end = i;}
            else if ((analized[i] == "*" || analized[i] == "/") && currentInt == 0)
            {
                currentInt = i;
            }
        }
        if (begin == end) // Если не нашлось скобок
        {

        }
        else
        {
            for (int i = begin; i < end; i++)
            {
                for (int j = begin; j < end; j++)
                {
                    if (analized[j] == "*")
                    {
                        int left = std::stoi(analized[j-1]);
                        int right = std::stoi(analized[j+1]);
                        *result.begin() = std::to_string(left * right);
                    }
                    else if (analized[j] == "/")
                    {
                        if (analized[j+1] != "0"){*result.begin() = std::to_string(std::stoi(analized[j-1]) / std::stoi(analized[j+1]));}
                    }
                }
            }
            for (int i = begin; i < end; i++) // Под конец функции
            {
                std::erase(analized, analized[i]);
            }
        }

    }

    return result;
}

float answer(std::string main)
{
    //* После этой строки у меня есть массив со всеми символами и числами
    std::vector<std::string> analized = analitic_make(main);

    return 0;
}



#endif //CALCULATOR_H
