#ifndef SAVER_H
#define SAVER_H
#include <vector>
class Saver {
public:
    // Сохранение вектора в файл
    static void save_vector(const std::vector<double>& vec, const char* filename);
    // Сохранение вектора векторов в файл
    static void save_double_vector(const std::vector<std::vector<double>>& vecOfVecs, const char* filename);
};
#endif