// Homework1_Khliustov_431.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#define EPS 0.00001

double* square_eq(double a, double b, double c);//Решает уравнение
void test_sq_eq();//Интерфейс для запуска функции
void derivative_of_exp();//Считает "производную"
void log_approx();//Считает "логарифм"

int main()
{
//    test_sq_eq();
//    derivative_of_exp();
//    log_approx();
    return 0;
}

double* square_eq(double a, double b, double c) {
    double* res;
    if (a<EPS && a>-EPS) {
        res = new double[1];
        res[0] = -c / b;
        return res;
    }
    res = new double[2];
    res[0] = (-b - sqrt(b*b - 4*a*c))/2;
    res[1] = (-b + sqrt(b * b - 4 * a * c)) / 2;
    return res;
}

void test_sq_eq() {
    double a, b, c;
    double* res;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    res = square_eq(a, b, c);
    std::cout << res[0] << "\n";
    std::cout << res[1];
    free(res);
}

void derivative_of_exp() {
    int k;
    double h;
    h = 1.;
    for (k = 0; k < 12; k++) {
        h /= 10;
        std::cout << k+1 << "   " << (exp(1. + h) - exp(1.))/h << "\n";
    }
}

void log_approx() {
    int i;
    double out1, out2, out3, sign;
    sign = -1.;
    out1 = 0.;
    out2 = 0.;
    out3 = 0.;
    for (i = 1; i < 10; i++) {
        sign *= (-1);
        out1 += sign * pow(0.1, i);
        out2 += sign * pow(10, i);
        out3 += sign * pow(100, i);
        std::cout << i << "   " << out1 << "   " << out2 << "   " << out3 << "\n";
    }
    std::cout << "library" << "   " << log(1.01) << "   " << log(11) << "   " << log(101) << "\n";
}