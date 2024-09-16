CS300/CS500
Advanced Object-Oriented Programming with C++
Lab #3: Makefiles
Background: You and some friends have decided to go to Nashville next weekend.
Everyone has agreed to share the expenses equally, but it’s not practical to share every
expense as it occurs. Thus each individual will pay for particular things, such as gas,
meals, hotels, and Uber rides. After the trip all expenses will be tallied and money will
be exchanged to ensure the net cost of the trip will be the same for every person,
within a cent.
You’ve been tasked to create a program to compute the minimum amount of
money that needs to change hands in order to equalize each person's costs. Assume
the number of people in the group does not exceed 100, and the total expenses of the
trip does not exceed $100,000.00
Examples:
Input: 10.00, 20.00, 30.00
Output: 10.00
Input: 15.00, 15.01, 3.00, 3.01
Output: 11.99
1. Create a main.cpp file (this will not be submitted), a trip.h file and trip.cpp file.
2. In the trip.h file include this function prototype:
float moneyEqualizer(std::vector<float> expenses);
3. In your trip.cpp file, include a definition to this function. An automated grading
system will pass a vector to this function specifying the expenses each person
has made during the trip. The function should return the amount of money that
needs to change hands such that everyone spent an equal amount of money on
the trip. 5 points
Note: Do not include a main function in your trip.cpp file
Make sure your function is written exactly as it is above
4. Create a Makefile with a default target that compiles this project into an
executable. The main.cpp and trip.cpp files should only be compiled if changes
have been made to the source code since the last compilation. 5 points
5. Include a run target in your Makefile that compiles your program then runs it.
6. Include a clean target in your Makefile that deletes the executable, as well as all
object files in the current directory.
7. Submit your Makefile, trip.h file, and your trip.cpp files to canvas.
Note: For grading, I have created a main.cpp file that will pass test cases into your
function, and check for accurate outputs. I will also use the make file you’ve provided
to compile the project.