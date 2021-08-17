# Calculator compiler

This is a project of mine to get better at making compilers and assembly.<br>
This uses no external library other than the built in ones, everything is done myself.

# Documentation

The syntax is pretty simple:

-   Adding:

```py
1 + 1
```

-   Subtracting:

```py
1 - 1
```

-   Multiplying

```py
1 * 1
```

-   Dividing

```py
1 / 1
```

-   Long equation

```py
1 + 2 - 3 * 4 / 5
```

-   ## Notes:
-   There are no order of operations
-   There are no floats
-   White space characters are ignored

```py
1 +
1 - 2      +3
*6
```

-   The above is valid

# Building

-   ## Warning
    -   This is linux only
-   ## Requirements
    -   g++
    -   nasm
    -   ld
-   ## Building the compiler
    -   `sh make.sh` - To build the compiler
    -   Result should be in out/build
-   ## Assembling the output assembly
    -   `sh make-asm.sh`- To build the assembly
    -   Result should be in out/calc

# How to use

-   Go into inputs/input.calc
-   Write the code you want
-   `./out/build inputs/input.calc` - This tells the compiler to compile the file in the inputs directory
-   The compiler should write to the file: `out/input.calc.asm`
-   Follow the "Assembling the output assembly" in the Building section to assemble the compiled assembly
-   `./out/calc` - To run the assembled assembly
