#ifndef _RNG_H_
#define _RNG_H_

#include <stdint.h>
#include <stdio.h>

void initialize_rng(void);
char random_char(void);
uint64_t random_uint64(void);
uint64_t random_uint64_of_weight(size_t weight);
uint64_t random_uint64_balanced(void);
void close_rng(void);

#endif