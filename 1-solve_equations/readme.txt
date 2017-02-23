This program takes a set of equations from an input file, solves the equations, and prints the values of variables in an output file. It's a good example on how to use abstract data types (ADTs) for object oriented programming.

For example, the input equation in input.txt are as follows:

Input Equation (1): a = 4 + c + b + 12
Input Equation (2): b= 18 +  d
Input Equation (3): c = 31 + 2
Input Equation (4): d = 100 


The results written in output.txt will be:

a = 167
b = 118
c = 33
d = 100

The output result should be sorted by variable name, as given above.


1) Overview of the code:
- The code is correct and example outputs are provided.
- The code is concise. All data types defined in the code are abstract data types (ADTs). Also using operator overloading, the code is easily readable.
- The code is efficient regarding the memory. This is mainly due to using the primary associative container type, “std::map”.
- There is no need to sort the list of equations because std::map container was used and the elements of std::map are ordered by default. This contributes to the time efficiency of the code.

2) Files and Classes:
- The main file to be compiled is “main.cpp”. This code is very concise.
- The code is implemented using a class ADT. The name of the class is “EquationList”.
- The interface of the ADT EquationList is “equiList.h”. This header file tells the programmer how to use the ADT EquationList.
- The implementation of the ADT EquationList is “equiList.cpp”. This implementation file tells how the interface is implemented.
- The output (solution for each equations) is recorded in “output.txt”.


3) Definitions, Variables, and Functions:
- “RHS” (rhs): right-hand side of the equation
- “LHS” (lhs): left-hand side of the equation
- “equationsMap”: A std::map that stores the initial equation as pairs. The first item of the pair is LHS and the second item of the pair is RHS, both is string format.
- “equationsMapSolved”: A std::map that stores the solved equation as pairs. The first item of the pair is LHS in string format. The second item of the pair is the solution of the equation in integer.
- The function EquationList::solveSum solves the list of equations. The challenge was to solve a equation that the values of its RHS variables were not available beforehand. A recursive approach was used to solve the list of equations.
