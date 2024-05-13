#ifndef QAMBASE_H
#define QAMBASE_H
#include <vector>
class QAMbase
{
private:

protected:
	int amplitude;								//амплитуда
	double signal_period;						//перио следования сигнала в микросекндах
	int frequency;								//несущая частота сигнала
	int number_of_signals;						//количество сигналов: 4, 16 или 64
	int sampling_rate;							//частота дискретизации
	bool is_calculated;							//переменная - флаг. Указывает, были ли уже просчитаны сигналы КАМ, чтобы не пересчитывать их повторно

	std::vector<std::vector<double> > signals;  //модулированные сигналы
	std::vector<double> amp_component_x;		//координата x сигнала в сигнальном созвездии
	std::vector<double> amp_component_y;		//координата y сигнала в сигнальном созвездии

	

	std::vector<double> make_time_intervals() const;
	void make_qam_signals();					//создание qam сигналов.
	void sin_cos_basis_vector(std::vector<double>& cos_vect, std::vector<double>& sin_vect) const;
	
public:
	QAMbase(const int& amp, const int& period, const int& freq, const int& num, const int& rate);
	std::vector<std::vector<double> > get_signals();
	std::vector<std::vector<double> > get_constellation();
	double get_energy_of_signals();
	virtual void get_info() = 0;
};

#endif