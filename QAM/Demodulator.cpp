#include "Demodulator.h"
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
Demodulator::Demodulator(const int& amp, const int& period, const int& freq, const int& num, const int& rate) :
	QAMbase(amp, period, freq, num, rate)
{
	sin_cos_basis_vector(cos_vect, sin_vect);
}

void Demodulator::get_info()
{
	cout << "QAM-" << number_of_signals << " demodulator" << endl;
	cout << "Amplitude: " << amplitude << endl;
	cout << "Frequency: " << frequency << endl;
	cout << "Signal period: " << signal_period << endl;
	cout << "Sampling rate: " << sampling_rate << endl;
}
int Demodulator::demodulation(const std::vector<double>& input_qam_signal)
{
	if (input_qam_signal.size() != cos_vect.size())
		throw runtime_error("Input QAM signal must be same length with basis vectors");

	double dt = 1.0 / frequency / sampling_rate; //шаг интегрирования по времени
	double x_coord = 0.0;
	double y_coord = 0.0;
	for (int i = 0; i < input_qam_signal.size(); i++)
	{
		x_coord += cos_vect[i] * input_qam_signal[i];
		y_coord += sin_vect[i] * input_qam_signal[i];
	}
	x_coord *= dt;
	y_coord *= dt;
	
	double min_distance = 1000.0;
	double distance = 0;
	int index_of_demodulated_signal = -1;

	for (int i = 0; i < amp_component_x.size(); i++)
	{
		distance = sqrt(pow(x_coord - amp_component_x[i], 2) + pow(y_coord - amp_component_y[i], 2));
		if (distance < min_distance)
		{
			min_distance = distance;
			index_of_demodulated_signal = i;
		}
	}
	return index_of_demodulated_signal;
}