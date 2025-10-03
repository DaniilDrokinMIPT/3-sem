#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct game {
    char title[50];
    int count;
    int scores[100];
    double average;
};

typedef struct game Game;

int compare(const void* a, const void* b) {
    Game* g1 = (Game*)a;
    Game* g2 = (Game*)b;
    if (g1->average < g2->average) return 1;
    if (g1->average > g2->average) return -1;
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    Game* games = malloc(n * sizeof(Game));

    for (int i = 0; i < n; i++) {
        scanf("%49[^:]:", games[i].title);
        char colon;
        scanf("%c", &colon);
        scanf("%d", &games[i].count);
        double sum = 0;
        for (int j = 0; j < games[i].count; j++) {
            scanf("%d", &games[i].scores[j]);
            sum += games[i].scores[j];
        }
        games[i].average = sum / games[i].count;
        scanf("%c", &colon);
    }

    qsort(games, n, sizeof(Game), compare);

    for (int i = 0; i < n; i++) {
        printf("%s, %.3f\n", games[i].title, games[i].average);
    }

    free(games);
    return 0;
}
