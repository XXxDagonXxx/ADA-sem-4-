# Problem 1: Knapsack Problem

The knapsack problem is a classic optimization problem that seeks to maximize the value of items placed into a knapsack, subject to a weight constraint.Given a set of items, each with a weight and a value, determine the combination of items to include in a knapsack so that the total weight does not exceed a given limit, and the total value is maximized.

**Variations**
There are several variations of the knapsack problem, including:

1. 0/1 Knapsack Problem: Each item can either be selected (1) or not selected (0).
2. Fractional Knapsack Problem: Portions of items can be taken, leading to fractional values and weights.
3. Multiple Knapsack Problem: There are multiple knapsacks, each with its weight limit, and items can be assigned to any knapsack.
4. Bounded Knapsack Problem: There is a limited quantity of each item available.
5. Unbounded Knapsack Problem: There is an unlimited quantity of each item available.

**Pseudocode**
![knapsack](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/7b816262-cec1-41db-943a-ba175d16f705)


**Time Complexity:**

The time complexity for each 0/1 Knapsack variant is O(n * W), where "n" is the number of items and "W" is the capacity of the knapsack.

![knapsack](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/169ed5dc-ac84-4866-b104-d9e92e1b864d)

**Use Case:**

If the primary goal is to maximize the total value within the weight constraint.

# Problem 2: Activity Selector

The Activity Selection Problem involves selecting a maximum set of non-overlapping activities, each represented by a start and finish time, from a given set. The algorithm aims to maximize the number of activities performed.The provided C++ implementation offers a solution to the Activity Selection Problem. It employs a greedy algorithm to select activities based on their finish times, ensuring a maximum set of non-overlapping activities.


**Pseudocode**
![activityselector](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/f7db24de-449f-483e-971d-586ce18c8d3c)


**Time Complexity:**

The time complexity of the algorithm is O(n log n), where "n" is the number of activities. Sorting the activities based on finish times is the primary contributor to the time complexity.
![activity_selector](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/ee5c9a59-4a85-4603-ac17-32df39d68a46)


**Use Cases:**

-Event Scheduling: Useful for scheduling events or tasks with specific start and finish times, ensuring maximum utilization of available time.

-Resource Allocation: Applicable in scenarios where resources need to be allocated to activities with defined time constraints, optimizing resource usage.

-Project Management: Valuable for scheduling tasks in project management, maximizing the number of tasks completed within a given timeframe.

# Problem 3: Binary Search
Binary search is a powerful and efficient algorithm for finding a specific element in a sorted array. This algorithm follows the divide and conquer paradigm, reducing the search space by half in each step. This README provides a concise guide to understanding and implementing binary search. Binary search works by repeatedly dividing the search interval in half. It compares the middle element of the interval to the target value and eliminates half of the remaining elements from consideration.

**Pseudocode**
![binarysearch](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/627926f1-cbf7-4f03-9703-55b1a0f637e3)


**Time Complexity :** 
Binary search has a time complexity of O(log n), where n is the number of elements in the array. This efficiency makes it significantly faster than linear search algorithms, especially for large datasets.
![binarysearch](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/34da9b1b-71ad-441e-a2cb-774c0889815d)


Usage Binary search is suitable for situations where the data is sorted, and quick retrieval of a specific element is required. It is commonly used in various applications, such as searching in databases, spell checking, and in algorithms like merge sort.
