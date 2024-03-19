# Problem 1: Permutation Generator:-
This program generates all permutations of a given set of numbers or characters.

Recurrance tree and its pseudocode that is to be followed in order to create solution for this problem is as follows:
![permutationgenerator](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/5f0b5632-d8e4-4d3a-9256-4a190e1fbf4a)

**Time Complexity**
The time complexity of the permutations generator is O(n!), where n is the number of elements in the set. This is because there are n! (n factorial) possible permutations to generate.

**Graph of Time Complexity:-**
![permutation_generator](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/e15182f8-ab8f-4990-b7c1-9228e28c883c)

**Application in Daily Life:-**
The Permutations Generator is useful in various applications, including:
1. Password Generation
2. Randomized Testing and Simulation
3. Statistical Sampling and Analysis

# Problem 2: Selection Sort:-
Selection sort is a simple sorting algorithm that repeatedly finds the minimum element from the unsorted part of the array and moves it to the beginning.

**Pseducode**
![selectionsort](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/f4b3e02d-ff69-44f9-ac36-fcbef62fc105)


**Time Complexity: The time complexity of Selection Sort is O(N2) as there are two nested loops:**

One loop to select an element of Array one by one = O(N)
Another loop to compare that element with every other Array element = O(N)
Therefore overall complexity = O(N) * O(N) = O(N*N) = O(N2)
![selection_sort](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/20d2295f-755e-4168-97bf-dfc16442952c)


**Advantages of Selection Sort Algorithm**
1. Simple and easy to understand.
2. Works well with small datasets.

**Disadvantages of the Selection Sort Algorithm**
1. Selection sort has a time complexity of O(n^2) in the worst and average case.
2. Does not work well on large datasets.
3. Does not preserve the relative order of items with equal keys which means it is not stable.

# **Problem 3: Sum of numbers:-**
This program calculates the sum of N numbers entered/present in the array.

**Pseudocode**
![sum](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/c6559754-5a72-4cfa-b3f9-850b9d4068d3)



**Time Complexity**
Generating Random Numbers (gen_numbers function):

O(n), where n is the size of the array.
Calculating the Sum (sum_of_numbers function):

O(n), where n is the size of the array.
![sum of n num](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/f467b414-b874-4d0b-be26-f30649efa7d6)

# Problem 4: Tower of Hanoi

**Overview:**
The Tower of Hanoi is a classic problem in computer science and mathematics that involves moving a stack of discs from one rod to another, subject to the following constraints:

1. Only one disc can be moved at a time.

2. Each move consists of taking the upper disc from one of the stacks and placing it on top of another stack or on an empty rod.

3. No disc may be placed on top of a smaller disc.

**Problem Statement :**

Given three rods and a number of discs of different sizes, the task is to move all the discs from one rod to another rod, following the rules mentioned above.

**Pseudocode**
![toh](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/985404bc-a149-4a88-a453-e9860e4a9614)

**Time Complexity**

The time complexity of the Tower of Hanoi algorithm is O(2^n), where n is the number of discs. This is an exponential time complexity, and the number of moves required doubles with each additional disc.

![tower_of_hanoi](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/0a2cab14-22c0-427b-a65e-8bb8e4c8ce71)

**Usage :**

The Tower of Hanoi problem is often used to demonstrate the principles of recursion and algorithmic design. It also has applications in algorithm analysis and teaching computational thinking.


# Problem 5: Possible Combinations of true false for n tries

The True False Generator is a program that generates all possible combinations of true (T) and false (F) values for a given number of elements.


**Pseudocode And Recurrsion tree**
![truefalse](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/3b8d316d-c975-48ff-9fde-9201c6302f37)


**Time Complexity**
The time complexity of the boolean True/false problem is O(2^n), where n is the number of trials.
![truefalse](https://github.com/chitwan6804/AnalysisAndDesign/assets/128251060/c2631bdb-f697-4846-b6ac-cadd9517caf7)
