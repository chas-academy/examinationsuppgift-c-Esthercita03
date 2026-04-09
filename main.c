//Write your code in this file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_TESTS 13
#define NUM_STUDENTS 5
#define NAME_MAX 11 // Max 10 chars + null terminator

typedef struct {
    char name[NAME_MAX];
    int total_score;
} Student;

static Student g_students[NUM_STUDENTS];

static void format_name(char* name) {
    // 1. Convert whole name to lowercase
    for (int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }
    // 2. Capitalize the first letter
    if (name[0] != '\0') {
        name[0] = toupper(name[0]);
    }
}

static float find_mean() {
    float sum = 0;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        sum += (float)g_students[i].total_score;
    }
    return sum / NUM_STUDENTS;
}

static int find_best_index() {
    int best_idx = 0;
    for (int i = 1; i < NUM_STUDENTS; ++i) {
        if (g_students[i].total_score > g_students[best_idx].total_score) {
            best_idx = i;
        }
    }
    return best_idx;
}

int main() {
    // Input loop
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        // Read name
        if (scanf("%s", g_students[i].name) != 1) break;
        format_name(g_students[i].name);

        // Read all 13 test scores
        g_students[i].total_score = 0;
        for (int j = 0; j < NUM_TESTS; ++j) {
            int score;
            scanf("%d", &score);
            g_students[i].total_score += score;
        }
    }

    // 1. Print the best student
    int best = find_best_index();
    printf("%s\n", g_students[best].name);

    // 2. Print students below the group mean
    float mean = find_mean();
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        if ((float)g_students[i].total_score < mean) {
            printf("%s\n", g_students[i].name);
        }
    }

    return 0;
}
