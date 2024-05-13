#include "BinarySignal.h"
#include <cmath>
#include <iostream>
#include <random>
using namespace std;
void BinarySignal::reset_qam_type(const int& qam_type)
{
	if (qam_type != 4 && qam_type != 16 && qam_type != 64)
		throw runtime_error("Unsupported type of QAM modulation.");
	upper_limit = qam_type - 1;
}
BinarySignal::BinarySignal(const int& qam_type)
{
	reset_qam_type(qam_type);
}
int BinarySignal::get_upper_limit() const
{
	return upper_limit;
}
int BinarySignal::generate_signal() const
{
	// Равномерно распределенное случайное число от 0 до верхней границы. Генерация номера передаваемого сигнала
	random_device random_device;
	mt19937 generator(random_device());
	uniform_int_distribution<> distribution(0, upper_limit);
	return distribution(generator);
}

