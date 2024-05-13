#include "Modulator.h"
#include <iostream>
#include <vector>
using namespace std;

Modulator::Modulator(const int& amp, const int& period, const int& freq, const int& num, const int& rate) : QAMbase(amp, period, freq, num, rate)
{}

void Modulator::get_info()
{
	cout << "QAM-" << number_of_signals << " modulator" << endl;
	cout << "Amplitude: " << amplitude << endl;
	cout << "Frequency: " << frequency << endl;
	cout << "Signal period: " << signal_period << endl;
	cout << "Sampling rate: " << sampling_rate << endl;
}

vector<double> Modulator::modulation(const int& binary_sequence, const BinarySignal& binary_signal)
{
	if (binary_signal.get_upper_limit() >= number_of_signals)
		throw runtime_error("The bit sequence is not compatible with the selected QAM modulation");
	make_qam_signals(); //создаем QAM сигналы
	return signals[binary_sequence];
}

