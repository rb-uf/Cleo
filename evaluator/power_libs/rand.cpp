#include <stdint.h>
#include <stdio.h>
#include <assert.h>

static FILE *urandom; 
void initialize_rng(void)
{
    urandom = fopen("/dev/urandom", "r");
}

char random_char(void)
{
    char c;
    assert(fread(&c, sizeof(char), 1, urandom));
    return c;
}

uint64_t random_uint64(void)
{
    uint64_t x;
    assert(fread(&x, sizeof(uint64_t), 1, urandom));
    return x;
}

uint64_t random_uint64_of_weight(size_t weight)
{
    assert(weight && weight < 64);
    uint64_t result = random_uint64();
    int scale = __builtin_popcountll(result) - weight;
    do
    {
        int coin = 1uL<<(random_char() % 64);
        result = scale < 1 
            ? result |  coin
            : result & ~coin;
    } while ((scale = __builtin_popcountll(result) - weight));
    return result;
}

uint64_t random_uint64_balanced(void)
{
    return random_uint64_of_weight(sizeof(uint64_t)<<2);
}

void close_rng(void)
{
    fclose(urandom);
}