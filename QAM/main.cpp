#include <iostream>
#include "Modulator.h"
#include "BinarySignal.h"
#include "Demodulator.h"
#include "GaussianNoise.h"
#include "Saver.h"

using namespace std;

#define AMPLITUDE     2
#define SIGNAL_PERIOD 33
#define FREQUENCY     1180
#define QAM_TYPE      64 //4, 16, 64
#define SAMPLING_RATE 100

#define DONT_CALCULATE_ERROR

int main()
{
	Modulator modulator(AMPLITUDE, SIGNAL_PERIOD, FREQUENCY, QAM_TYPE, SAMPLING_RATE);
	Demodulator demodulator(AMPLITUDE, SIGNAL_PERIOD, FREQUENCY, QAM_TYPE, SAMPLING_RATE);
	BinarySignal binary_signal(QAM_TYPE);
	vector<double> error_values;

	double energy = modulator.get_energy_of_signals();
	
	#ifndef DONT_CALCULATE_ERROR
	for (int noise_value = 0; noise_value < 20; noise_value++) //��������� �� ��������� ����. ����� GaussianNoise ��������� �� � ��
	{
		int error_counter = 0; // ���������� ������
		int max_error = 20;   // ������������ ���������� ������
		int test_counter = 0;  // ���������� ����������� ������
		cout << noise_value << endl;
		while (error_counter < max_error)
		{
			int bit_sequence = binary_signal.generate_signal();						   //���������� ������� ������������������
			vector<double> signal = modulator.modulation(bit_sequence, binary_signal); //���������� ������
			GaussianNoise::add_noise(signal, noise_value, QAM_TYPE, energy);		   //��������� ��� � �������
			int answer = demodulator.demodulation(signal);							   //������������ ������
			if (answer != bit_sequence)
				error_counter += 1;
			test_counter += 1;
		}
		error_values.push_back(static_cast<double>(error_counter) / test_counter);
	}
	#endif

	//���������� ������ � ����� ��� ������������ ������� � Matlab
	if(error_values.size() != 0)
		Saver::save_vector(error_values, "OUTPUT/QAM_ERRORS.txt");
	Saver::save_double_vector(modulator.get_signals(), "OUTPUT/SIGNALS.txt");
	Saver::save_double_vector(modulator.get_constellation(), "OUTPUT/CONSTELLATION.txt");
	
	
	return 0;
}