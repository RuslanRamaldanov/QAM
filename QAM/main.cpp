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
	for (int noise_value = 0; noise_value < 20; noise_value++) //проходимя по значениям шума. Класс GaussianNoise переведет их в дБ
	{
		int error_counter = 0; // количество ошибок
		int max_error = 20;   // максимальное количество ошибок
		int test_counter = 0;  // количество проведенных тестов
		cout << noise_value << endl;
		while (error_counter < max_error)
		{
			int bit_sequence = binary_signal.generate_signal();						   //генерируем битовую последовательность
			vector<double> signal = modulator.modulation(bit_sequence, binary_signal); //модулируем сигнал
			GaussianNoise::add_noise(signal, noise_value, QAM_TYPE, energy);		   //добавляем шум к сигналу
			int answer = demodulator.demodulation(signal);							   //демодулируем сигнал
			if (answer != bit_sequence)
				error_counter += 1;
			test_counter += 1;
		}
		error_values.push_back(static_cast<double>(error_counter) / test_counter);
	}
	#endif

	//Сохранение данных в файлы для последующего импорта в Matlab
	if(error_values.size() != 0)
		Saver::save_vector(error_values, "OUTPUT/QAM_ERRORS.txt");
	Saver::save_double_vector(modulator.get_signals(), "OUTPUT/SIGNALS.txt");
	Saver::save_double_vector(modulator.get_constellation(), "OUTPUT/CONSTELLATION.txt");
	
	
	return 0;
}