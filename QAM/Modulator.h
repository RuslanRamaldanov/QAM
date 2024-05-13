#ifndef MODULATOR_H
#define MODUALTOR_H
/*
	Класс выполняет функциональность QAM модулятора.
	Сигналы QPSK можно рассматривать как простейшую форму QAM.
*/

#include "QAMbase.h"
#include "BinarySignal.h"
class Modulator : public QAMbase
{
public:
	Modulator(const int& amp, const int& period, const int& freq, const int& num, const int& rate);
	std::vector<double> modulation(const int& binary_sequence, const BinarySignal& binary_signal);
	void get_info() override;
};

#endif