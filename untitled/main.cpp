#include <iostream>
#include <vector>

using namespace std;

// Функція для обчислення базисного полінома Лагранжа
double lagrangeBasis(const vector<double>& x, int i, double point) {
    double result = 1.0;
    for (int j = 0; j < x.size(); ++j) {
        if (j != i) {
            result *= (point - x[j]) / (x[i] - x[j]);
        }
    }
    return result;
}

// Функція для обчислення інтерполяції Лагранжа
double lagrangeInterpolation(const vector<double>& x, const vector<double>& y, double point) {
    double result = 0.0;
    for (int i = 0; i < x.size(); ++i) {
        result += y[i] * lagrangeBasis(x, i, point);
    }
    return result;
}

int main() {
    // Дані точки
    vector<double> x = {1.0, 2.0, 3.0};
    vector<double> y = {3.0, 8.0, 15.0};

    // Точка для оцінки
    double point = 1.5;

    // Результат інтерполяції
    double result = lagrangeInterpolation(x, y, point);

    cout << "Оцінене значення y при x = " << point << " дорівнює " << result << endl;

    return 0;
}
