#include <iostream>
#include <iomanip>
#include <chrono>

void computePi(double& pi, unsigned long int numIterations) {
    double term = 0.0;
    pi = 0.0;
    int sign = 1;

    for (unsigned long int i = 0; i < numIterations; i++) {
        term = sign / (2.0 * i + 1.0);
        pi += term;
        sign = -sign;
    }

    pi *= 4.0;
}

int main() {
    unsigned long int numIterations;
    std::cout << "Enter the number of iterations: ";
    std::cin >> numIterations;

    double result;

    // Start the timer
    auto startTime = std::chrono::steady_clock::now();

    computePi(result, numIterations);

    // Stop the timer
    auto endTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);

    std::cout << std::fixed;
    std::cout << std::setprecision(100) << "Approximation of pi: " << result << std::endl;

    std::cout << "Computation time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
}
