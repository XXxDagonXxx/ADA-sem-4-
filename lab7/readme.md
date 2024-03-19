## Problem 1: Assembly Line Scheduling Algorithm

__Aim:__  

The aim of this program is to implement the assembly line scheduling algorithm to determine the minimum time required to complete a product assembly on two parallel assembly lines.

__Problem Statement:__

The algorithm aims to minimize the total time taken to complete all tasks by efficiently allocating tasks to two assembly lines. It considers the time taken for each task on both assembly lines, as well as the time required to switch lines between tasks.

__Algorithm:__
1.	Initialize arrays to store the following:
   
   •	f1[]: Minimum time to reach station i on the first assembly line.

   •	f2[]: Minimum time to reach station i on the second assembly line.

   •	l1[]: Path for the first assembly line.

   •	l2[]: Path for the second assembly line.

2.	Calculate the minimum time to reach each station on both assembly lines, considering the entry times, processing times, and transfer times.
3.	Determine the optimal path through the assembly lines by comparing the times calculated for each station.
4.	Calculate the total time required for assembly by considering the exit times and selecting the minimum time between the two assembly lines.
5.	Print the total minimum time required for assembly.

__Time Complexity:__
The time complexity of this algorithm is O(n), where n is the number of stations on each assembly line. This is because the algorithm iterates through each station once to calculate the minimum time to reach each station and determine the optimal path. Therefore, the overall time complexity is linear with respect to the number of stations.

## Problem 2: Matrix Chain Multiplication

__Aim:__

The aim of this program is to find the optimal way to multiply a sequence of matrices in order to minimize the total number of scalar multiplications required.


__Problem Statement:__

Given a sequence of matrices with dimensions represented by an array arr[], where the ith matrix has dimensions arr[i-1] x arr[i], the task is to find the minimum number of scalar multiplications needed to multiply these matrices together in an optimal way, along with the order in which the matrices should be multiplied.


__Algorithm:__

Matrix_Chain Function:
1.	Base Case: If i == j, return 0 as there is only one matrix.
2.	Initialize minresult to a large value.
3.	Iterate k from i to j-1:
    •	Recursively calculate the number of scalar multiplications needed to multiply the matrices from i to k and from k+1 to j.
    •	Add the number of scalar multiplications for these two subproblems along with the cost of multiplying the resulting matrices.
    •	Update minresult if the current count is less than minresult.
    •	Store the value of k at S[i][j] for the optimal split.
4.	Return minresult.
Print Function:
    •	Base Case: If i == j, print the matrix A followed by its index.
    •	Recursively print the optimal parenthesization for multiplying the matrices from i to S[i][j] and from S[i][j]+1 to j.
    •	Print parentheses around the two subexpressions.

__Time Complexity:__

•	The time complexity of the algorithm is O(n^3), where n is the number of matrices in the sequence.
•	This is because there are three nested loops in the Matrix_Chain function, each iterating over n elements.
•	Therefore, the overall time complexity is cubic in terms of the number of matrices, making it efficient for moderately sized inputs but less efficient for very large sequences of matrices.


