The Problem
Complete the function isValid that is an advanced verision of the one you finished in lab_quack last week.

The function isValid takes a string as input, which may contain three kinds of brackets: '(', ')', '{', '}', '[', ']'. A valid input should not contain any unmatched, extra or hanging brackets of any kind. And they must close in the correct order. Your function should ignore any characters other than these three types of brackets.

Example
"()[]{}!" // valid
"([cs225)]" // invalid
Testing Your Code
A main.cpp has been provided to you with very limited test cases. You are encouraged to add your own!

Motivation
There has been some discussions for the function isBalanced in lab_quack. Some of you may have solved the problem without using a stack and think that using a stack in that case is overcomplicated.

In order to let you understand our intention of using a stack in isBalanced, we decided to let you try on this problem, where (hopefully) using a stack makes more sense.

Can I also solve this problem without using a stack as well?
Yes! We encourage you to think of different solutions and compare them in terms of time, space complexity and code elegancy. If you come up with an algorithm that does not require a stack, feel free to share it on Piazza with your peers! (general algorithm, not your code)

Graded files
The only file that will be submitted for grading on this problem is isValid.cpp
