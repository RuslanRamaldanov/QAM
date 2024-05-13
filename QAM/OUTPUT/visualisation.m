data = load("CONSTELLATION.txt");

figure(1)
plot(data(1,:), data(2,:), 'ro');
title('Сигнальное созвездие')

data = load("SIGNALS.txt");
siglas_to_output = length(data(:, 1)) / 2;

figure(2)
hold on;
for i = 1:siglas_to_output
    plot(data(i, :));
end
title('Сигнальное множество')

data = load("QAM_ERRORS.txt");

figure(3)
semilogy(data)
grid on;
title("График вероятности ошибки")
ylabel("Вероятность ошибки")
xlabel("Шум, дБ")