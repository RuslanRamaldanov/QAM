#ifndef DEMODULATOR_H
#define MODULATOR_H
//����� �������� ����������� ������������ QAM ��������
//���� ��� ������ �������� ������������ ������ �� �������� ���������� �������� ���������� ����� � ��������� ���������� ������ � ���������

#include "QAMbase.h"
#include <vector>

class Demodulator : QAMbase
{
private:
	std::vector<double> cos_vect; //�������� ������� ��������
	std::vector<double> sin_vect; //�������� ������� ������
public:
	Demodulator(const int& amp, const int& period, const int& freq, const int& num, const int& rate);
	int demodulation(const std::vector<double>& input_qam_signal);
	void get_info() override;
};

#endif