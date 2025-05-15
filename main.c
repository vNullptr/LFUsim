#include "cache.h"


int main() {

    int T[10] = {2, 1, 3, 4, 6, 6, 6, 2, 12, 10};
    Cache C = createCache(4);

    for (int i = 0; i < 10; i++){

        put(&C, T[i]);
        show(&C);
    }


    return 0;
}