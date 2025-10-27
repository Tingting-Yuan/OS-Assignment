# Operating Systems examples and exercises in C

## Exercises

1. Write a C program that swaps the two integer values passed as parameters (Hint: both parameters have to be passed by reference).
   note: “Pass by reference” means passing the address of a variable instead of directly switching its value.

2. Modify the program ``posix/pthreads_example.c`` to accept the number of threads to create as a command line parameter.
   
   note: Creating threads with pthread_create may fail. 
   This is usually due to system resource limits (too many threads or insufficient memory) or invalid parameters. Always check the return value to handle errors safely.
   Some test example:
   > ./pthreads_example 5
      Result:
      Hello from thread 0
      Hello from thread 1
      Hello from thread 2
      Hello from thread 3
      Hello from thread 4
      All threads completed.
   > ./pthreads_example
      Results:
      Error: Wrong number of parameters.
   > ./pthreads_example 0
      Results:
      Too few threads. Please specify a number greater than zero.

