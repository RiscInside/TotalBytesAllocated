#define _GNU_SOURCE
#include <stdio.h>
#include <stdatomic.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <stdbool.h>

typedef void* (*malloc_func_t)(size_t);

static malloc_func_t real_malloc;

void *malloc(size_t size) {
    static atomic_size_t total_memory = 0;

    void *result = real_malloc(size);
    if (result == NULL) {
        return NULL;
    }

    // malloc can be called from many threads, so atomics are a neccessity
    size_t new_total = atomic_fetch_add_explicit(&total_memory, size, memory_order_relaxed) + size;

    fprintf(stderr, "Total bytes allocated so far: %zu\n", new_total);
    return result;
}

__attribute__((constructor)) void init() {
    real_malloc = dlsym(RTLD_NEXT, "malloc");
    if (real_malloc == NULL) {
        fprintf(stderr, "Couldn't find real malloc function!");
        exit(-1);
    }
}

