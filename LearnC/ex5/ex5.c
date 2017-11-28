// ex5.c

// this is including the header file for function in
// standard IO
#include <stdio.h>

// this is a multiline commment
/* This is a comment. */

//this is the standard main function, with arguments
// that can get passed in on the command line
int main(int argc, char *argv[])
{
  // initialize a variable distance if type int to values 100
  int distance = 100;

  // this is also a comment
  printf("You are %d miles away.\n", distance);

  // return 0 for a non-error exit status
  return 0;
}
