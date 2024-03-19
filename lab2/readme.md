# Problem 1: Power of Number Calculator

The Power of Number Calculator is a program that calculates the power of a given number using two different methods: iterative and recursive (divide and conquer) techniques. It compares the execution time of both methods for a range of input values.
The program calculates the power of a given number using both iterative and recursive methods. It then measures the execution time for each method and writes the data to a file.

**Pseducode**

![power](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/6f3b5315-aa54-4658-907d-47f98e22523e)


**Time complexity**

_Iterative Method:_
The iterative method calculates the power of a number by performing a loop a specified number of times. In this case, the loop runs i times, where i is the exponent. Therefore, the time complexity of the iterative method is O(i), where i is the exponent.

_Recursive (Divide and Conquer) Method:_
The recursive method uses a divide and conquer approach to calculate the power of a number. It splits the problem into subproblems of smaller size and combines the results. In this case, the function is recursively called log(i) times, where i is the exponent. This is because the exponent is divided by 2 at each recursive call until it reaches 0. Therefore, the time complexity of the recursive method is O(log(i)), where i is the exponent.

![power_of_num](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/b76b1ca9-7921-4d0c-84ca-1cb0eecbcdf6)

# Problem 2: Actual Position of the random number:

-Find correct position of first number present in the array.Such that all numbers smaller that the given number is to its left and all greater number to its right.

**Pseudocode:**
![actual_pos](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/e7cbf0b5-2a50-4ed4-9e18-2c7618ae3320)


**Time Complexity:**
![actual_position](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/ff5fe282-dad7-488a-9ad8-572a74c65e2f)

# Problem 3: Merge 2 sorted list in sorted order:
This C++ program demonstrates the merging of two sorted lists into a single sorted list.The program generates two sorted lists of integers, list1 and list2, with random values. It then merges these two lists into a single sorted list, list3, using a merging algorithm. The merging process involves iterating through both lists simultaneously and selecting the smaller element from each list to populate list3.

**Pseudocode:**
![merge](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/3b48164b-059c-4263-9bce-920d8b5c022b)


**Time Complexity:**
Time Complexity to find actual position is:- O(n*n)
![sort 2 sorted list](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/3d7f909f-f3a1-4c56-87e9-88f7a5deb9e5)
