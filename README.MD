# Pyramid Programming Language 

A Low Level Language Compiler written in C Language 
For Learning Purpose only 
Uses a Stack Data Structure to Perform Operations like :
* Addition
* Substraction
* Multiplication
* Incrementation

Sample Programs:
* basic_program.pyrd
```sh
  push #30
  push #10
  push #20
  add
  add
  hlt
```
* program_one.pyrd
```sh
push #10
push #40
sub
incr
incr
hlt
```

Grammer:
* add - Addition of Two Numbers on Top of the Stack 
* sub - Substraction of Two Numbers on Top of the Stack 
* mul - Multiplication of Two Numbers on Top of the Stack 
* incr - Increament the Number on Top of the Stack 
* push #D - Push a Number D on the Top of the Stack 
* hlt - Stop the Execution or Mark the End of the Program 

Commands :
* Compile (Creates a Binary Byte Code of the Program)
```sh
./pyramid --compile file_name.pyrd
```
* Run (Outputs the Number on Top of the Stack after Operations are Performed)
```sh
./pyramid --run out.pyrdb  
```

Demo:

Using Sample Program program_one.pyrd
* Compile the Program
```sh
./pyramid --compile tests/program_one.pyrd

````
* View the Binary Byte Code 
```sh 
xxd out.pyrdb

Output :
00000000: 0100 0000 0a01 0000 0028 0305 05ff 
```
* Run the Binary Byte Code 
```sh 
./pyramid --run out.pyrdb 

Output:
Output 32  
```

