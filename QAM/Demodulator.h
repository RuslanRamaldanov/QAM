#ifndef DEMODULATOR_H
#define MODULATOR_H
//Класс выполнят функционлан демодулятора QAM сигналов
//Мною был выбран алгоритм оптимального приема по минимуму расстояния принятой сигнальной точки и ближайшей сигнальной точкой в созвездии

#include "QAMbase.h"
#include <vector>

class Demodulator : QAMbase
{
private:
	std::vector<double> cos_vect; //базисная функция косинуса
	std::vector<double> sin_vect; //базисная функция синуса
public:
	Demodulator(const int& amp, const int& period, const int& freq, const int& num, const int& rate);
	int demodulation(const std::vector<double>& input_qam_signal);
	void get_info() override;
};

#endif