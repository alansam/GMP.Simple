//
//  gmp-rationals.c
//  GMP.Simple
//
//  Created by Alan Sampson on 1/28/20.
//  Copyright © 2020 Alan @ FreeShell. All rights reserved.
//

#include "gmp-rationals.h"

//  MARK: - Implementation
/*
 *  MARK: rationals()
 */
int rationals(int argc, const char * argv[]) {
  int RC = EXIT_SUCCESS;
  printf("%s\n", __func__);

  mpq_t half, third, three;
  mpq_t r1, r2;
  mpz_t z3;

  mpq_init(half);
  mpq_init(third);
  mpq_init(three);
  mpq_inits(r1, r2, NULL);

  mpq_set_ui(half, 1, 2);
  mpq_canonicalize(half);

  mpq_set_ui(third, 1, 3);
  mpq_canonicalize(third);

  mpz_init_set_ui(z3, 3);
  mpq_set_z(three, z3);
  mpq_canonicalize(three);

  gmp_printf(" one half: %Qd\n", half);
  gmp_printf("one third: %Qd\n", third);
  gmp_printf("    three: %Qd\n", three);
  
  mpq_div(r1, half, three);
  mpq_canonicalize(r1);
  mpq_div(r2, third, three);
  mpq_canonicalize(r2);

  gmp_printf("%Qd / %Qd = %Qd\n", half, three, r1);
  gmp_printf("%Qd / %Qd = %Qd\n", third, three, r2);
  
  mpq_mul(r1, half, three);
  mpq_canonicalize(r1);
  mpq_mul(r2, third, three);
  mpq_canonicalize(r2);

  gmp_printf("%Qd x %Qd = %Qd\n", half, three, r1);
  gmp_printf("%Qd x %Qd = %Qd\n", third, three, r2);

  mpz_clear(z3);
  mpq_clears(r1, r2, NULL);
  mpq_clear(three);
  mpq_clear(third);
  mpq_clear(half);

  return RC;
}
