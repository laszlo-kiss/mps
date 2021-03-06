/* 
TEST_HEADER
 id = $Id$
 summary = create a format in an uncreated arena
 language = c
 link = testlib.o
OUTPUT_SPEC
 assert = true
 assertfile P= global.c
 assertcond = TESTT(Arena, arena)
END_HEADER
*/

#include "testlib.h"

static void test(void *stack_pointer)
{
 mps_arena_t arena;
 mps_fmt_t format;

 arena=malloc(4096);

 cdie(mps_fmt_create_k(&format, arena, mps_args_none), "create format");

 mps_arena_destroy(arena);
 comment("Destroy arena.");
}

int main(void)
{
 run_test(test);
 return 0;
}
