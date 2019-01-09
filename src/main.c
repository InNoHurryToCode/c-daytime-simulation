#include <stdio.h>
#include <stdlib.h>
#include "daytime.h"

int main(void) {
    Daytime *manager = daytime_ctor();

    while (1) {
        printf("%d-%d-%dT%d-%d-%d+00:00\n", manager->year, manager->month, manager->day, manager->hour, manager->minute, manager->second);
        daytime_update(manager);

        if (manager->year > 4) {
            break;
        }
    }

    return EXIT_SUCCESS;
}
