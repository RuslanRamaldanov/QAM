#include "QAMbase.h"
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

QAMbase::QAMbase(const int& amp, const int& period, const int& freq, const int& num, const int& rate) :
																								amplitude(amp),
																								signal_period(period / 10000.0),
																								frequency(freq),
																								number_of_signals(num),
																								sampling_rate(rate)																						
{
	is_calculated = false;
	const int sqrt_number_of_signals = sqrt(static_cast<double>(number_of_signals));
	for (int i = 0; i < sqrt_number_of_signals; i++)
	{
		for (int j = 0; j < sqrt_number_of_signals; j++)
		{
			amp_component_x.push_back(amplitude * (1.0 - (i * 2) / (sqrt_number_of_signals - 1.0)));
			amp_component_y.push_back(amplitude * (1.0 - (j * 2) / (sqrt_number_of_signals - 1.0)));
		}
	}
}

std::vector<std::vector<double>> QAMbase::get_signals()
{
	make_qam_signals();
	return signals;
}

std::vector<std::vector<double>> QAMbase::get_constellation()
{
	return vector <vector<double> >({ amp_component_x, amp_component_y });
}

double QAMbase::get_energy_of_signals()
{
	double energy = 0.0;
	for (int i = 0; i < amp_component_x.size(); i++)
		energy += ((amp_component_x[i] * amp_component_x[i]) + (amp_component_y[i] * amp_component_y[i]));
	return energy / number_of_signals;
}

//сформируем вектор временных интервалов, в которые мы набляюдаем значение сигнала
std::vector<double> QAMbase::make_time_intervals() const
{
	vector<double> time_counts;
	double dt = 1.0 / frequency / sampling_rate; //шаг интегрирования по времени
	time_counts.push_back(0);
	while (time_counts.back() <= signal_period)
		time_counts.push_back(time_counts.back() + dt);
	return time_counts;
}

void QAMbase::sin_cos_basis_vector(std::vector<double>& cos_vect, std::vector<double>& sin_vect) const
{
	const double angular_freq = 2.0 * 3.14159265358979323846 * frequency; //угловая частота 2пf
	const double amplitude_const = sqrt(2.0 / signal_period);

	cos_vect = make_time_intervals();
	sin_vect = make_time_intervals();
	for_each(cos_vect.begin(), cos_vect.end(), [&](double& val) {val = amplitude_const * cos(val * angular_freq); });
	for_each(sin_vect.begin(), sin_vect.end(), [&](double& val) {val = amplitude_const * sin(val * angular_freq); });
}

void QAMbase::make_qam_signals()
{
	if (number_of_signals != 4 && number_of_signals != 16 && number_of_signals != 64)
		throw runtime_error("Unsupported type of QAM modulation");
	if (!is_calculated)
	{
		is_calculated = true;
		//формироание сигналов КАМ
		vector<double> cos_vect;
		vector<double> sin_vect;
		sin_cos_basis_vector(cos_vect, sin_vect);

		signals.resize(number_of_signals);

		for (int i = 0; i < number_of_signals; i++)
		{
			vector<double> signal1(cos_vect);
			vector<double> signal2(sin_vect);
			for_each(signal1.begin(), signal1.end(), [&](double& val) {val = amp_component_x[i] * val; });
			for_each(signal2.begin(), signal2.end(), [&](double& val) {val = amp_component_y[i] * val; });
			transform(make_move_iterator(signal1.begin()), make_move_iterator(signal1.end()),
				make_move_iterator(signal2.begin()), back_inserter(signals[i]),
				[](double&& a, double&& b) { return a + b; });
		}
	}
}
