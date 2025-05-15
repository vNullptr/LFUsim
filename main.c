#include "cache.h"


int main() {

    int T[10] = {2, 1, 3, 4, 6, 7, 8, 8, 2, 10};
    Cache C = createCache(4);

    for (int i = 0; i < 10; i++){

        put(&C, T[i]);
        show(&C);
    }


    return 0;
}