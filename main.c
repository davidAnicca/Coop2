#include "tests.h"
#include "cons.h"
#include <stdio.h>
#include <malloc.h>
int main() {
    run_all_tests();
    Console* console = run();
    end_cons(console);
    return 0;
}
