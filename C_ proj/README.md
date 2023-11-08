# Projects
# 7 questions
# The project includes lists, strings, array, allocation and more...

# Question 1:
Writing an efficient function called powerArray that accepts an integer n and returns a pointer to an array of size and type unsigned int, which is an edge or dynamic within the function.
Each cell in the array should contain 2 to the power of the remainder of the division of the index by 32. That is, the value of a cell in the i place will be 2i mod 32.

# Question 2:
We define the neighbors of element a[i][j] of matrix A as elements a[i+1][j], a[i-1][j], a[i][j+1], a[i] [j-1]. If a[i][j] is in the first/last row/column of A then the number of its neighbors will be less accordingly.
Writing a function called matrixMaxNeighbor that receives a matrix A implemented as a dynamic two-dimensional array and its size.
The function must assign a new two-dimensional array implementing a matrix B with the same dimensions as A so that each element b[i][j] of it is equal to the maximum between its neighbors a[i][j].

# Question 3:
Writing a function called createArrayAndList that receives a matrix as a dynamic two-dimensional array and its size. The function finds each of the elements of the matrix whose value is less than or equal to all its neighbors (see the definition of the neighbors of the matrix element in question 2).
The function must construct a one-dimensional dynamic array of triples, as well as a linked list of triples. Each triple in the array or list will contain the value of the element of the matrix that meets the above conditions, and the coordinates i and j (row number and column number) of that element in the matrix. The function will return the size of the array (which is equal to the length of the list), and transfer ( by reference) the array and the list.
To implement the triples, a struct type with three numeric fields must be used.


# Question 4:
Writing a function called createList that accepts a linked list (without a dummy member) of non-negative integers.
The function must remove from the list each member that is greater than the previous member and also greater than the next member. A new list must be constructed (without a dummy member) consisting of the numbers deleted from the original list. The order of the members in which they appeared in the original list must be maintained in the new list.

# Example
The original list containing 3, 6, 1, 9, 8, 4, 5 (from left to right) will be updated to a list consisting of numbers 3, 1, 8, 4 (from left to right). The members of the new list will be 6, 9, 5 (from left to right).

# Question 5:
Writing a function called createList2 that performs the same task as the function from question 4, but unlike the function from question 4, the current function will not use freeing and allocating memory. The function must change the links in the original list, disconnect the elements that should be deleted from it and link them in the new list.

# Question 6:
Writing a function called removeDupArrayLists which receives an array of linked lists (without dummy members) of characters and its size.
The function must delete members from each of the array lists, so that no duplicate members remain.

# Question 7:
Writing a function named disassemblyList which receives a linked list (without a dummy member) of characters.
The function must break the list into four separate lists so that the first list contains only lowercase letters, the second list - only uppercase letters, the third list - only digits, and the fourth list - other characters.



