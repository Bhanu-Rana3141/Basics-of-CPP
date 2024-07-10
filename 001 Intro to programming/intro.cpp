/*
-> Programming - set of instructions given to computer to perform a specific task
-> Computer understands binary 
    source code -> compiler -> binary code

-> Flow charts - diagrammatic representation of a approach for a problem
-> Pseudocode - generic way of representing logic/code for a problem
-> Data Structures - structure to store data in efficient manner
-> Algorithm - step by step instruction to solve a problem


/* 
Q .HOW DOES THE CODE EXECUTES ? 

The execution of C++ code involves several steps, including compilation, linking, and execution. Here's an overview of the process:

1. Source Code: 
The process begins with the creation of C++ source code files. These files contain the human-readable code written by the programmer.

2. Preprocessing:
Before compilation, the source code undergoes a preprocessing phase. The preprocessor handles tasks such as including header files, macro expansions, and conditional compilation.

3. Compilation:
The preprocessed code is then fed into the compiler. The compiler translates the C++ source code into low-level machine code or an intermediate code (such as assembly language or object code). This compiled code is often referred to as object code.

4. Object Files:
The compiler generates one or more object files (.obj or .o files) from the compiled code. These files contain the machine code specific to each source code file.

5. Linking:
If your program consists of multiple source code files or includes external libraries, the linker combines all the necessary object files into a single executable file. The linker resolves references to functions and variables, ensuring that everything is connected correctly.

6. Executable File:
The result of the linking process is an executable file (e.g., .exe on Windows or with no extension on Unix-like systems). This file contains the binary code that the computer's hardware can execute.

7. Loading and Execution:
When you run your C++ program, the operating system's loader loads the executable file into memory. The program's code and data are placed in the appropriate sections of memory.
The operating system transfers control to the starting point of the program, typically the main function.
The program's instructions are executed sequentially, performing the actions specified in the C++ code.

8. Runtime:
During runtime, the program interacts with the operating system, hardware, and external resources. Input and output operations, memory allocation, and other dynamic aspects of the program occur at runtime.

9. Termination:
The program continues to execute until it reaches the end or encounters a specific exit condition. At this point, the program terminates, and the operating system reclaims the resources allocated to the program.

*/

#include<iostream>
using namespace std;

int main()
{
    cout << "hello world";
    return 0;
}