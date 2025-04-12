// Created by kleymuner2131 on 12.04.25.
#include <string>
#include <vector>

bool is_this_balanced(std::string main)
{
    int balance;
    for (char ch : main)
    {
        if (ch == '('){balance ++;}
        else if (ch == ')'){balance --;}
    }
    if (balance == 0){return true;}
    else{return false;}
}

std::vector<std::string> chars_make(std::string main)
{
    std::vector<std::string> cooked = {};
    for (int i = 0; i < main.size(); i++)
    {
        if (main[i] >= '0' && main[i] <='9')
        {
            std::string number = "";
            while (main[i] >= '0' && main[i] <='9')
            {
                number += main[i];
                i++;
            }
            cooked.push_back(number);
            i--;
        }
        else
        {
            //! todo: Важная состовляющая
            cooked.push_back(std::string(1, main[i])); //*cooked.push_back(std::string(main[i]));
        }
    }
    return cooked;
}

float answer_maker (std::vector<std::string> cooked)
{
    float answer;
    int begin = 0; int end = 0;
    while (cooked.size() != 1)
    {
        if (begin == 0){
            for (int i = 0; i < cooked.size(); i++)
            {
                if (cooked[i] == "("){begin = i;}
                else if (cooked[i] == ")"){end = i;}
            }
        }
        if (begin != end) // Если есть скобки + начало с самых внутренних
        {
            // todo: Учесть что возможно более и менее приоритетное действие внутри скобок
            for (int i = begin + 1; i < end; i++)
            {
                if (cooked[i] == "*")
                {
                    float currentInt = std::stof(cooked[i-1]) * std::stof(cooked[i+1]);
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    cooked[i-1] = std::to_string(currentInt);
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (cooked[i] == "/")
                {
                    if (cooked[i+1] != "0")
                    {
                        float currentInt = std::stof(cooked[i-1]) / std::stof(cooked[i+1]);
                        cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                        cooked.erase(cooked.begin() + i); // Удаляем оператор
                        cooked[i-1] = std::to_string(currentInt);
                        i--; // Чтобы не пропустить следующий элемент
                    }
                }
            }
            cooked.erase(cooked.begin()+begin+1);
            cooked.erase(cooked.begin()+begin);
            begin = 0; end = 0;
        }
        else
        {
            for (int i = 0; i < cooked.size(); i++)
            {
                if (cooked[i] == "*")
                {
                    float currentInt = std::stof(cooked[i-1]) * std::stof(cooked[i+1]);
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    cooked[i-1] = std::to_string(currentInt);
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (cooked[i] == "/")
                {
                    if (cooked[i+1] != "0")
                    {
                        float currentInt = std::stof(cooked[i-1]) / std::stof(cooked[i+1]);
                        cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                        cooked.erase(cooked.begin() + i); // Удаляем оператор
                        cooked[i-1] = std::to_string(currentInt);
                        i--; // Чтобы не пропустить следующий элемент
                    }
                }
            }
        }

    }
}

double answer_function(std::string main)
{
    std::vector<std::string> cooked = chars_make(main);
    float answer = answer_maker(cooked);

    return 0;
}
