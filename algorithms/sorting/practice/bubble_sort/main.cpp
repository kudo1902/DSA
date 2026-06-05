#include <iostream>
#include <vector>
#include <cassert>

// Forward declaration of the bubbleSort function
void bubbleSort(std::vector<int>& arr);

void printVector(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void testBubbleSort() {
    // Test Case 1: Unsorted array
    std::vector<int> arr1 = {5, 1, 4, 2, 8};
    std::vector<int> expected1 = {1, 2, 4, 5, 8};
    bubbleSort(arr1);
    assert(arr1 == expected1);
    std::cout << "Test Case 1 Passed!\n";

    // Test Case 2: Already sorted
    std::vector<int> arr2 = {1, 2, 3, 4, 5};
    std::vector<int> expected2 = {1, 2, 3, 4, 5};
    bubbleSort(arr2);
    assert(arr2 == expected2);
    std::cout << "Test Case 2 Passed!\n";

    // Test Case 3: Empty array
    std::vector<int> arr3 = {};
    std::vector<int> expected3 = {};
    bubbleSort(arr3);
    assert(arr3 == expected3);
    std::cout << "Test Case 3 Passed!\n";

    // Test Case 4: Reverse sorted array
    std::vector<int> arr4 = {10, 9, 8, 7, 6};
    std::vector<int> expected4 = {6, 7, 8, 9, 10};
    bubbleSort(arr4);
    assert(arr4 == expected4);
    std::cout << "Test Case 4 Passed!\n";
}

int main() {
    std::cout << "Running Bubble Sort Tests...\n";
    testBubbleSort();
    std::cout << "All tests passed successfully!\n";
    return 0;
}
