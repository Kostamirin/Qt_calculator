// Created by kleymuner2131 on 12.04.25.
#include <string>
#include <vector>
#include <stdexcept> // Для исключений
#include <QString>
#include <limits>  // Для std::numeric_limits
#include <cmath>   // Для std::isnan

bool is_this_balanced(std::string main)
{
    int balance = 0;
    for (char ch : main)
    {
        if (ch == '('){balance ++;}
        else if (ch == ')'){balance --;}
    }
    if (balance == 0){return true;}
    else{return false;}
}

bool is_this_real(std::vector<std::string> cooked)
{
    int dots = 0;
    for (int i = 0; i < cooked.size(); i++)
    {
        if (cooked[i] != "*" && cooked[i] != "/" && cooked[i] != "+"
            &&cooked[i] != "-" && cooked[i] != "(" && cooked[i] != ")")
        {
            if (cooked[i][0] == '.'){return false;}
            for (int j = 0; j < cooked[i].size(); j++)
            {
                if (cooked[i][j] == '.')
                {
                    dots++;
                    if (dots>1){return false;}
                }
            }
            dots = 0;
        }
    }
    return true;
}

std::vector<std::string> chars_make(std::string main)
{
    std::vector<std::string> cooked = {};
    for (int i = 0; i < main.size(); i++)
    {
        if (main[i] >= '0' && main[i] <='9')
        {
            std::string number = "";
            while (main[i] >= '0' && main[i] <='9' || main[i] == '.')
            {
                number += main[i];
                i++;
            }
            cooked.push_back(number);
            i--; //Чтобы не пропустить следующий
        }
        else
        {
            cooked.push_back(std::string(1, main[i])); //*cooked.push_back(std::string(main[i]));
        }
    }
    return cooked;
}

double answer_maker (std::vector<std::string> cooked)
{
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
                    double currentInt = QString::fromStdString(cooked[i-1]).toDouble() * QString::fromStdString(cooked[i+1]).toDouble();
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    // Контролируем точность при преобразовании в строку
                    cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (cooked[i] == "/")
                {
                    if (cooked[i+1] != "0" && QString::fromStdString(cooked[i+1]).toDouble() != 0.0)
                    {
                        double currentInt = QString::fromStdString(cooked[i-1]).toDouble() / QString::fromStdString(cooked[i+1]).toDouble();
                        cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                        cooked.erase(cooked.begin() + i); // Удаляем оператор
                        // Контролируем точность при преобразовании в строку
                        cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                        i--; // Чтобы не пропустить следующий элемент
                    }
                    else
                    {
                        // Вместо QMessageBox и NaN, выбрасываем исключение
                        throw std::runtime_error("Division by zero");
                    }
                }
            }
            for (int i = begin+1; i < end; i++)
            {
                if (cooked[i] == "+")
                {
                    double currentInt = QString::fromStdString(cooked[i-1]).toDouble() + QString::fromStdString(cooked[i+1]).toDouble();
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    // Контролируем точность при преобразовании в строку
                    cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (cooked[i] == "-")
                {
                    double currentInt = QString::fromStdString(cooked[i-1]).toDouble() - QString::fromStdString(cooked[i+1]).toDouble();
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    // Контролируем точность при преобразовании в строку
                    cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                    i--; // Чтобы не пропустить следующий элемент
                }
            }
            cooked.erase(cooked.begin()+begin+2);
            cooked.erase(cooked.begin()+begin);
            begin = 0; end = 0;
        }
        else
        {
            for (int i = 0; i < cooked.size(); i++)
            {
                if (cooked[i] == "*")
                {
                    double currentInt = QString::fromStdString(cooked[i-1]).toDouble() * QString::fromStdString(cooked[i+1]).toDouble();
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    // Контролируем точность при преобразовании в строку
                    cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (cooked[i] == "/")
                {
                    if (cooked[i+1] != "0" && QString::fromStdString(cooked[i+1]).toDouble() != 0.0)
                    {
                        double currentInt = QString::fromStdString(cooked[i-1]).toDouble() / QString::fromStdString(cooked[i+1]).toDouble();
                        cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                        cooked.erase(cooked.begin() + i); // Удаляем оператор
                        // Контролируем точность при преобразовании в строку
                        cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                        i--; // Чтобы не пропустить следующий элемент
                    }
                    else
                    {
                        // Вместо QMessageBox и NaN, выбрасываем исключение
                        throw std::runtime_error("Division by zero");
                    }
                }
            }
            for (int i= 0; i < cooked.size(); i++)
            {
                if (cooked[i] == "+")
                {
                    double currentInt = QString::fromStdString(cooked[i-1]).toDouble() + QString::fromStdString(cooked[i+1]).toDouble();
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    // Контролируем точность при преобразовании в строку
                    cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                    i--; // Чтобы не пропустить следующий элемент
                }
                else if (cooked[i] == "-")
                {
                    double currentInt = QString::fromStdString(cooked[i-1]).toDouble() - QString::fromStdString(cooked[i+1]).toDouble();
                    cooked.erase(cooked.begin() + i + 1); // Удаляем операнд
                    cooked.erase(cooked.begin() + i); // Удаляем оператор
                    // Контролируем точность при преобразовании в строку
                    cooked[i-1] = QString::number(currentInt, 'g', 15).toStdString(); // Используем 'g' формат
                    i--; // Чтобы не пропустить следующий элемент
                }
            }
        }

    }

    double answer = QString::fromStdString(cooked[0]).toDouble();

    return answer;
}

double answer_function(std::string main)
{
    if (main.empty()) {
        return 0.0; // Или другое значение по умолчанию для пустого ввода
    }
    if (!is_this_balanced(main))
    {
        throw std::runtime_error("Unbalanced parentheses");
    }

    std::vector<std::string> cooked = chars_make(main);
    if (!is_this_real(cooked))
    {
        throw std::runtime_error("Invalid number format (e.g., multiple decimal points)");
    }

    double answer = answer_maker(cooked); // answer_maker теперь может выбросить исключение

    return answer;
}
