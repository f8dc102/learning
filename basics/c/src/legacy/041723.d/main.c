#include <stdio.h>
#include "isprime.h"

int main() {
    for (int i = 2; i <= 100; i++){
        if (isprime(i))
            printf("%d ", i);
    }

    return 0;
}
