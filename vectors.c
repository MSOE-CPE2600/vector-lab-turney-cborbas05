/* Filename: vectors.c
 * Author: Cameron Borbas
 * Date: 10/9/2025
 * Description: All required functions are coded for
 *      each user input. (+, -, *, etc)
 */


#include <stdio.h>
#include <string.h>
#include "vectors.h"

static char vector_names[MAX_VECTORS][NAME_LEN];
static double vector_vals[MAX_VECTORS][3];
static int vector_active[MAX_VECTORS];


// Clears all vectors in memory
void clear_vectors() {
    for (int i = 0; i < MAX_VECTORS; i++) {
        vector_active[i] = 0;
    }
    printf("All vectors cleared.\n");
}

// Lists all vectors in memory
void list_vectors() {
    int any = 0;
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vector_active[i]) {
            printf("%s = %.3f %.3f %.3f\n", vector_names[i],
                   vector_vals[i][0], vector_vals[i][1], vector_vals[i][2]);
            any = 1;
        }
    }
    if (!any) printf("No stored vectors.\n");
}

// Finds any vector requested from memory
int find_vector(const char *name) {
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (vector_active[i] && strcmp(vector_names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

// Adds a calculated vector to memory
int add_vector(const char *name, double v[3]) {
    int idx = find_vector(name);
    if (idx != -1) {
        memcpy(vector_vals[idx], v, sizeof(double) * 3);
        return 1;
    }
    for (int i = 0; i < MAX_VECTORS; i++) {
        if (!vector_active[i]) {
            strncpy(vector_names[i], name, NAME_LEN - 1);
            vector_names[i][NAME_LEN - 1] = '\0';
            memcpy(vector_vals[i], v, sizeof(double) * 3);
            vector_active[i] = 1;
            return 1;
        }
    }
    printf("Error: vector storage full.\n");
    return 0;
}

// Gets a requested vector from memory
int get_vector(const char *name, double v[3]) {
    int idx = find_vector(name);
    if (idx == -1) return 0;
    memcpy(v, vector_vals[idx], sizeof(double) * 3);
    return 1;
}

// Adds 2 vectos
void add_vectors(double a[3], double b[3], double r[3]) {
    for (int i = 0; i < 3; i++) {
        r[i] = a[i] + b[i];
    }
}

// Subtracts 2 vectors
void sub_vectors(double a[3], double b[3], double r[3]) {
    for (int i = 0; i < 3; i++) {
        r[i] = a[i] - b[i];
    }
}

// Scalar mult a (Vector * value)
void scalar_mult_a(double a[3], double s, double r[3]) {
    for (int i = 0; i < 3; i++) {
        r[i] = a[i] * s;
    }
}

// Scalar mult b (value * Vector)
void scalar_mult_b(double a[3], double s, double r[3]) {
    for (int i = 0; i < 3; i++) {
        r[i] = s * a[i];
    }
}
