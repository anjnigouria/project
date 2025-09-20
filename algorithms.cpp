#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

// Utility: Generate random integers
std::vector<int> generateRandomArray(int size, int min = 0, int max = 999) {
    std::mt19937 rng(static_cast<unsigned int>(std::time(0)));
    std::uniform_int_distribution<int> dist(min, max);
    std::vector<int> arr(size);
    for (int& x : arr)
        x = dist(rng);
    return arr;
}

// Utility: Print the array
void printArray(const std::vector<int>& arr) {
    for (int x : arr)
        std::cout << x << " ";
    std::cout << "\n";
}

// 1. Bubble Sort
void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i)
        for (int j = 0; j < n-i-1; ++j)
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
}

// 2. Selection Sort
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; ++i) {
        int minIdx = i;
        for (int j = i+1; j < n; ++j)
            if (arr[j] < arr[minIdx])
                minIdx = j;
        std::swap(arr[i], arr[minIdx]);
    }
}

// 3. Insertion Sort
void insertionSort(std::vector<int>& arr) {
    for (int i = 1; i < arr.size(); ++i) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key)
            arr[j + 1] = arr[j--];
        arr[j + 1] = key;
    }
}

// 4. Merge Sort
void merge(std::vector<int>& arr, int l, int m, int r) {
    std::vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    std::vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size())
        arr[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(std::vector<int>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low - 1;
    for (int j = low; j < high; ++j)
        if (arr[j] <= pivot)
            std::swap(arr[++i], arr[j]);
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. Heap Sort
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n/2 - 1; i >= 0; --i)
        heapify(arr, n, i);
    for (int i = n-1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Radix Sort (non-negative integers only)
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

void countingSortForRadix(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; ++i)
        count[(arr[i]/exp)%10]++;
    for (int i = 1; i < 10; ++i)
        count[i] += count[i-1];
    for (int i = n-1; i >= 0; --i) {
        int digit = (arr[i]/exp)%10;
        output[count[digit]-1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; ++i)
        arr[i] = output[i];
}

void radixSort(std::vector<int>& arr) {
    int maxVal = getMax(arr);
    for (int exp = 1; maxVal/exp > 0; exp *= 10)
        countingSortForRadix(arr, exp);
}

// Main Program
int main() {
    int size, choice;

    std::cout << "Enter size of array: ";
    std::cin >> size;

    std::vector<int> arr = generateRandomArray(size);

    std::cout << "\nOriginal array:\n";
    printArray(arr);

    std::cout << "\nChoose sorting algorithm:\n";
    std::cout << "1. Bubble Sort\n";
    std::cout << "2. Selection Sort\n";
    std::cout << "3. Insertion Sort\n";
    std::cout << "4. Merge Sort\n";
    std::cout << "5. Quick Sort\n";
    std::cout << "6. Heap Sort\n";
    std::cout << "7. Radix Sort (only non-negative integers)\n";
    std::cout << "Enter your choice (1-7): ";
    std::cin >> choice;

    std::vector<int> sortedArr = arr;  // Make a copy for sorting

    switch (choice) {
        case 1: bubbleSort(sortedArr); break;
        case 2: selectionSort(sortedArr); break;
        case 3: insertionSort(sortedArr); break;
        case 4: mergeSort(sortedArr, 0, sortedArr.size() - 1); break;
        case 5: quickSort(sortedArr, 0, sortedArr.size() - 1); break;
        case 6: heapSort(sortedArr); break;
        case 7: radixSort(sortedArr); break;
        default: std::cout << "Invalid choice!\n"; return 1;
    }

    std::cout << "\nSorted array:\n";
    printArray(sortedArr);

    return 0;
}
