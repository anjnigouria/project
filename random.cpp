#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <chrono>

int main() {
    // Size of the random number set
    size_t n = 1000000;  // 1 million numbers for example

    // Create a random number generator
    std::mt19937 rng(static_cast<unsigned int>(std::time(0)));  // Seed with current time
    std::uniform_int_distribution<int> dist(1, 1000000);  // Generate numbers between 1 and 1,000,000

    // Create a vector to store random numbers
    std::vector<int> numbers(n);

    // Generate the random numbers
    for (size_t i = 0; i < n; ++i) {
        numbers[i] = dist(rng);
    }

    // Measure the time before sorting
    auto start = std::chrono::high_resolution_clock::now();

    // Sort the vector using std::sort
    std::sort(numbers.begin(), numbers.end());

    // Measure the time after sorting
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    // Output time taken for sorting
    std::cout << "Sorting " << n << " random numbers took " 
              << duration.count() << " seconds." << std::endl;

    return 0;
}
