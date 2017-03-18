#include <moocow_alloc.h>

void* moocow_alloc(size_t bytes) {
    return malloc(bytes);
}
