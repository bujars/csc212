HW #2 

Assignment: 

CSc 21200 – 2018 Fall Homework 2
Due September 26th, 2018
You will need to submit a written report with part of your codes and your source code via Blackboard. You also need to bring in a hard copy of the report with part of your codes to the class on the day that this is due.
Name your header file as LastName(3 to 5 letters)_FirstNameInitial_HW2.h and your implementation file as LastName(3 to 5 letters)_FirstNameInitial_HW2.cpp
Note: You can only use iostream, cassert, cctype, cmath, cstdio, and cstdlib.
1. Write a function that ask the user to enter up to a maxSize char static array. Input can be less than maxSize and is stopped by entering non-alphabet letter, using the isalpha([char]) function in the cctype library.
2. Assuming the user will only enter all lower-case letter, write a function that returns the highest number of occurrences in the user input array using Q1. If two or more characters have the same number of occurrences, return the one closest to a.
3. Write a function that ask the user the number of shift they want and shift the array according. Note: You CANNOT use any additional arrays. You should write a swap function.
For example, if the input characters are
abcadebca
and the number of spaces to shift is 3, the output will be:
bcaabcade
If the number of spaces is negative, the shift will be to the left.
4. Write a function that combine a sorted char static array ar1 with size n1 and a sorted char static array ar2 with size n2 and return one sorted char array of the combine of those two arrays.
For example:
ar1[n1] = {‘a’, ‘c’, ‘e’, ‘f’}; ar2[n2] = {‘b’, ‘d’, ‘g’}; newAr[n1+n2] = {‘a’, ‘b’, ‘c’, ‘d’, ‘e’, ‘f’, ‘g’};
5. Write a function that ask the user for m and n where m and n is the size of the m-x-n char matrix and lets them input into the matrix.
6. Write a function that ask the user the number of rotations they want and rotate the matrix 90 degree according. This can only be done with a square matrix. Note: You CANNOT use any additional arrays/matrix.
For example, if the input characters matrix is
ab
cd
and the number of rotations is 2, the output will be
dc ba
If the number of rotations is negative, the rotation will be clockwise.
7. Write a function that ask the user the size s of the enlarge they want and return a (s*m)-by- (s*n) matrix.
For example, the m-x-n array is:
abc def
and the size s is 2.
Then the matrix that will be returned is: aabbcc
aabbcc
ddeeff
ddeeff



Your report should consist of, but not limited to:
• Briefly explain what this function does
• Briefly explain how this function works, if applicable
• Pre- and Post-condition, if applicable
• Worst case time complexity


Example structures of the report:
1. An overview of this homework
2. Code for question 1
3. Explanation of question 1
4. Code for question 2
5. Explanation of question 2
6. ... other questions
7. Any improvements, problems, etc. of the class/functions
8. Code for header file
Code should be Consolas font size 8 to 10.
