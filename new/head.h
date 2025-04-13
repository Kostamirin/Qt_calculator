#ifndef QT_CALCULATOR_HEAD_H
#define QT_CALCULATOR_HEAD_H

#include <string>
#include <vector>

bool is_this_balanced(std::string main);
std::vector<std::string> chars_make(std::string main);
// Изменяем тип возвращаемого значения на double
double answer_maker(std::vector<std::string> cooked);
double answer_function(std::string main);

#endif //QT_CALCULATOR_HEAD_H
