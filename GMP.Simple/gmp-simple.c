//
//  main.c
//  GMP.Simple
//
//  @see: https://www.cs.colorado.edu/~srirams/courses/csci2824-spr14/gmpTutorial.html
//
//  Created by Alan Sampson on 1/27/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//
//  TODO: - Build Setup
//  TODO: Build Settings -> Linking -> Other Linker Flags -> -lgmp
//  TODO: Build Settings -> Search Paths -> Header Search Paths -> /usr/local/include
//  TODO: Build Settings -> Search Paths -> Library Search Paths -> /usr/local/lib
//  TODO: Signing Capabilities -> Hardened Runtime -> Runtime Exceptions -> Disable Library Validations

//  MARK: - Definitions

#include "gmp-simple.h"

//  MARK: - Implementation
/*
 *  MARK: simple()
 */
int simple(int argc, const char * argv[]) {
  int RC = EXIT_SUCCESS;
  printf("%s\n", __func__);

  char inputStr[1024];
  /*
    mpz_t is the type defined for GMP integers.
    It is a pointer to the internals of the GMP integer data structure
  */
  mpz_t nr;
  int flag;

#ifndef NO_INTERACTIVE
  printf("Enter your number: ");
  /*
   * NOTE: never every write a call scanf ("%s", inputStr);
   * You are leaving a security hole in your code.
   */
  scanf("%1023s", inputStr);
#else
  char const * samples[] = {
    "18446744073709551615", "19753086419753086424691358024691358025",
    "198109830985109285019285102958102958120958109258120958120"
      "9581029581209581209856120856120958120958120958120958",
    "2222222222222222222221",
  };
  size_t samples_l = sizeof(samples) / sizeof(samples[0]);
  size_t r_lower = 0;
  size_t r_upper = samples_l;
  size_t ix = (arc4random() % (r_upper - r_lower + 1)) + r_lower;
  strcpy(inputStr, samples[ix]);
#endif

  /* 1. Initialize the number */
  mpz_init(nr);
  mpz_set_ui(nr, 0);

  /* 2. Parse the input string as a base 10 number */
  flag = mpz_set_str(nr, inputStr, 10);
  assert(flag == 0); /* If flag is not 0 then the operation failed */

  printf(" ULLONG_MAX = %1$llu [%1$0llx]\n", ULLONG_MAX);

  /* Print nr */
  printf("          n = ");
  mpz_out_str(stdout, 10, nr);
  printf("\n");

  /* 3. Add one to the number */
  mpz_add_ui(nr ,nr, 1); /* nr = nr + 1 */

  /* 4. Print the result */
  printf("     nr + 1 = ");
  mpz_out_str(stdout, 10, nr);
  printf("\n");

  /* 5. Square nr+1 */
  mpz_mul(nr, nr, nr); /* nr = nr * nr */

  printf("  (n + 1)^2 = ");
  mpz_out_str(stdout, 10, nr);
  printf("\n");

  /* 6. Clean up the mpz_t handles or else we will leak memory */
  mpz_clear(nr);

  return RC;
}
