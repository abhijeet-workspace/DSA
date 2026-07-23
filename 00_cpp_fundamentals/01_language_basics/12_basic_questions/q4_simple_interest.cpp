// Q4 Simple Interest — basic practice
// SI = (P * R * T_months) / (100 * 12); time is in months.
#include <iostream>

double simpleInterest(double principal, double rate, double time);

int main() {
    double principal = 0.0;
    double rate = 0.0;
    double time = 0.0;

    std::cout << "Enter Principal amount: ";
    std::cin >> principal;
    std::cout << "Enter Rate of interest: ";
    std::cin >> rate;
    std::cout << "Enter Time (in month): ";
    std::cin >> time; // months, not years

    double interest = simpleInterest(principal, rate, time);
    std::cout << "Simple Interest is: " << interest << std::endl;
    return 0;
}

double simpleInterest(double principal, double rate, double time) {
    return (principal * rate * time) / (100.0 * 12.0); // monthly time base
}
