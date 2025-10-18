#include <stdio.h>

#ifdef DEBUG
#define LOG(msg) fprintf(stderr, "[DEBUG] %s:%d: %s\n", __FILE__, __LINE__, msg)
#else
#define LOG(msg)
#endif

int main() {
    LOG("Start");
    printf("Hello\n");
    LOG("Finish");
    return 0;
}
