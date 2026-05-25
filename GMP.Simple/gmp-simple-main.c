//
//  gmp-simple-main.c
//  GMP.Simple
//
//  @see: https://www.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html
//  @see: https://gmplib.org/manual/index.html#Top
//  @see: https://github.com/opencv/opencv/issues/15645
//  @see: https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
//
//  Created by Alan Sampson on 1/28/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//
//  TODO: - Build Setup
//  TODO: Build Settings -> Linking -> Other Linker Flags -> -lgmp
//  TODO: Build Settings -> Search Paths -> Header Search Paths -> /usr/local/include
//  TODO: Build Settings -> Search Paths -> Library Search Paths -> /usr/local/lib
//  TODO: Signing Capabilities -> Hardened Runtime -> Runtime Exceptions -> Disable Library Validations
//

//  MARK: - Definitions

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static
inline
void version_details(void);
#include "version_info.h"
#include "gmp-simple.h"
#include "gmp-rationals.h"

//  MARK: - Implementation
static
char const * dlm = "------------------------------------------------------------";

/*
 *  MARK: main()
 */
int main(int argc, const char * argv[]) {
  int RC = EXIT_SUCCESS;
  printf("GMP.Simple\n");

  version_details();

  puts(dlm);
  simple(argc, argv);
  puts("");
  
  puts(dlm);
  rationals(argc, argv);
  puts("");

  return RC;
}
