#include <stdlib.h>
#include "daytime.h"

int main(void) {
    Daytime *daytimeManager = daytime_ctor();

    while (1) {
        daytime_update(daytimeManager);

        if (daytimeManager->year > 4) {
            break;
        }
    }

    return EXIT_SUCCESS;
}
