HW #1 

Assignment: 


CSc 21200 – 2018 Fall Homework 1
Due September 17th, 2018
You will need to submit a written report with part of your codes and your source code via Blackboard. You also need to bring in a hard copy of the report with part of your codes to the class on the day that this is due.
Name your header file as LastName(3 to 5 letters)_FirstNameInitial_HW1.h and your implementation file as LastName(3 to 5 letters)_FirstNameInitial_HW1.cpp
Note: You can only use iostream, cassert, cmath and cstdio.
Create a class called Point with the following:
1. Private members: x, y and z as double.
2. Write a default constructor and set the point to (0, 0, 0).
3. Write a constructor and set the point to user input, if z is not inputted, set it to 0.
4. Write a copy constructor.
5. Write the set functions for each individual member, x and y together, and x, y, and z
together.
6. Write the get functions for each individual member.
7. Write a member function called print() that print out the point.
8. Write a member function called distance() that return the distance between the origin and
the point.
9. Write a member function called line(param) that return true if pt2 is on the same line as
the origin and the point. Otherwise, return false. Also return false if the origin and the
point do NOT make a line.
10. Write a member function called cross(param) that return a point that is the cross product
of a pt2 and the point.
11. Overload the addition (+) and the subtraction (-) operators.
12. Overload the output (<<) and input (>>) operators.
13. Write a non-member function called plane(param) that takes an array of three points
and a point. Return true if that point is on the plane created by the static array of three points. Otherwise, return false.
To find the plane
i. Find u and v where u is pt2-pt1 and v is pt3-pt1.
ii. Find the normal vector to the plane by using the cross product of u and v.
iii. Using the Point-Normal Form, the normal vector, and any of the three
points, the equation of the plane is a(x-x0) + b(y-y0) + (cz-z0) = 0, where <a, b, c> is the normal vector and P(x0, y0, z0) is one of the three points. Thus, any points P(x, y, z) that satisfy this equation is on the plane.
14. Write a non-member function called square(param) that takes a static array of unique points and the size of the array. Return true if the array of points can create at least one square. Otherwise return false.
15. Write a non-member function called centroid(param) that takes a static array of points and the size of the array and return the centroid of the array of points.



Your report should consist of, but not limited to:
• Briefly explain what this function does
• Briefly explain how this function works, if applicable
• Pre- and Post-condition, if applicable
• Worst case time complexity



Example structures of the report:
1. An overview of this class
2. Code for question 7
3. Explanation of question 7
4. Code for question 8
5. Explanation of question 8
6. ... other questions
7. Any improvements, problems, etc. of the class/functions
8. Code for header file
Code should be Consolas font size 8 to 10.
