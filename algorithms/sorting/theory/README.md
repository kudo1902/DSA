# Sorting Algorithms Theory

Sorting is the process of arranging a collection of data in a specific order (ascending or descending).

## Key Classification Criteria

1. **Time Complexity**: The number of operations required (Best, Average, and Worst-case).
2. **Space Complexity**: Extra memory required by the algorithm.
   - **In-place**: O(1) auxiliary space (e.g., Bubble Sort, Insertion Sort, Heap Sort).
   - **Out-of-place**: Requires O(N) auxiliary space (e.g., Merge Sort).
3. **Stability**: A sorting algorithm is stable if it preserves the relative order of equal keys/elements.
   - **Stable**: Bubble Sort, Insertion Sort, Merge Sort.
   - **Unstable**: Quick Sort, Heap Sort, Selection Sort.

## Summary of Common Sorting Algorithms

| Algorithm | Best Time | Average Time | Worst Time | Space | Stable? | In-Place? |
| :--- | :--- | :--- | :--- | :--- | :--- | :--- |
| **Bubble Sort** | O(N) | O(N²) | O(N²) | O(1) | Yes | Yes |
| **Selection Sort**| O(N²) | O(N²) | O(N²) | O(1) | No | Yes |
| **Insertion Sort**| O(N) | O(N²) | O(N²) | O(1) | Yes | Yes |
| **Merge Sort** | O(N log N) | O(N log N) | O(N log N) | O(N) | Yes | No |
| **Quick Sort** | O(N log N) | O(N log N) | O(N²) | O(log N)| No | Yes |
| **Heap Sort** | O(N log N) | O(N log N) | O(N log N) | O(1) | No | Yes |
