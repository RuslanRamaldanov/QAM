#ifndef BINARYSIGNAL_H
#define BINARYSIGNAL_H
//Класс реализует произвольную битовую последовательность.
//Битовая последовательность хранится в переменной типа int.
//Например: число 53 соответствует битовой последовательности 110101.
//По сути происходт генерация номера передаваемого QAM сигнала из сигнального алфавита.
#include <string>
#include <vector>
class BinarySignal
{
private:
	int upper_limit; //верхняя граница для сигналов. Например, для QAM-16 максимальная битовая последовательность равна 1111, что равно 15 в десятичной системе счисления
public:
	BinarySignal(const int& qam_type);
	int generate_signal() const;
	int get_upper_limit() const;
	void reset_qam_type(const int& qam_type);
};

#endif