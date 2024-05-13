#ifndef SAVER_H
#define SAVER_H
#include <vector>
class Saver {
public:
    // ���������� ������� � ����
    static void save_vector(const std::vector<double>& vec, const char* filename);
    // ���������� ������� �������� � ����
    static void save_double_vector(const std::vector<std::vector<double>>& vecOfVecs, const char* filename);
};
#endif