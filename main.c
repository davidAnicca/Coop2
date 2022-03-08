#include <stdio.h>
#include "tests.h"
#include "cons.h"

int main() {
    run_all_tests();
    Console* console = run();
    end_cons(console);
    return 0;
}
