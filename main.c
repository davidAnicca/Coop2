#define _CRTDBG_MAP_ALLOC
#include "tests.h"
#include "cons.h"
#include <crtdbg.h>
#include <stdio.h>
#include <malloc.h>
int main() {
    run_all_tests();
    Console* console = run();
    end_cons(console);
    int *b = malloc(sizeof (int));

    _CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_DEBUG );
    int a =  _CrtDumpMemoryLeaks();
    printf("%d", a);
    return 0;
}
