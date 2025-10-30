# Vector Calculator (Labs 5-8)


## What Is This Lab?
>	- This lab allows for the user to add vectors to a list
>	- It allows the user to do mathamatical expressions with the vectors
>	- In version 1.0, the user could only add 10 vectors
>	- In version 2.0, the user could add as many vectors as wanted due to dynamic memory
>	- The in version 2.0, the user can load and save .csv files of their vectors
>	- In all versions, user can list and clear vectors, print help menu
>	- They can also do basic vector math and quit the program
>	- In version 2.0, program uses dynamic memory. Description on how at very end of README.md file


## How to run program
 Compiling
>	- run the command: **gcc -o calc calc.c vectors.c**
>	- or run the make file with the command: **make**

 Running the program
>	- W/o valgrind: **./calc**
>	- W/ vagrind: **valgrind ./calc** 
>	- Program starts with an option to print the help menu

## Lab 5 Implementations:
 Create a program that can be used to do the following: 
>	- Add a vector to a list of set size (10)
>	- Add two vectors
>	- Subtract two vectors
>	- Use scalar multiplication on a vector
>	- List out the vecrors
>	- Clear the vectors
>	- Print out a help menu
>	- Quit the program
>	- Create a Makefile for the program


## Lab 6 Implementations:
 Github
>	- Install and learn to use GitHub in Linux
>	- Push our code to GitHub


## Lab 7/8 Implementations:
 Dynamic Memory 
>	- Implement our code using dynamic memory for the list of vectors
>	- File IO (Reading and writing .csv files)
>	- Incorperate tags to your commit
>	- Incorperate a README.md file to your commit


## How the PRogram uses Dynamic Memory
 realloc
>	- Lab starts at a capacity of 4
>	- If at any point the number of vectors goes past, capacity is doubled
>	- If the vectors in the list is 0, returns to original capacity
> 	- When the user clears the vectors, memory gets freed
>	- If the user enters a vector again, memory gets used again.
