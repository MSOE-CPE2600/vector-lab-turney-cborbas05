/* Filename: vectors.c
 * Author: Cameron Borbas
 * Date: 10/27/2025
 * Description: All required functions are coded for
 *      each user input. (+, -, *, etc.)
 *      Updated for dynamic memory and file I/O
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vectors.h"

#define INITIAL_CAPACITY 4

static Vector *vectors = NULL;
static int vector_count = 0;
static int vector_capacity = 0;


// Helper function to make sure there is enough space
static void ensure_capacity() {
    if (vector_count >= vector_capacity) {
        int new_capacity;
 
        if (vector_capacity == 0) {
            new_capacity = INITIAL_CAPACITY;
        } else {
            new_capacity = vector_capacity * 2;
        }

        Vector *temp = realloc(vectors, new_capacity * sizeof(Vector));
        if (temp == NULL) {
            printf("Error: memory allocation failed.\n");
            exit(1); // Exits pgrm if there is an error that occurs
        }

        vectors = temp;
        vector_capacity = new_capacity;
    }
}



// Clears all vectors in memory
void clear_vectors() {
    free(vectors);
    vectors = NULL;
    vector_count = 0;
    vector_capacity = 0;
    printf("All vectors cleared.\n");
}


// Lists all vectors in memory
void list_vectors() {
    if (vector_count == 0) {
        printf("No stored vectors.\n");
        return;
    }

    for (int i = 0; i < vector_count; i++) {
        printf("%s = %.3f %.3f %.3f\n",
               vectors[i].name,
               vectors[i].val[0],
               vectors[i].val[1],
               vectors[i].val[2]);
    }
}


// Finds any vector requested from memory
int find_vector(const char *name) {
    for (int i = 0; i < vector_count; i++) {
        if (strcmp(vectors[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}


// Adds a calculated vector to memory
int add_vector(const char *name, double v[3]) {
    int idx = find_vector(name);
    if (idx != -1) {
        memcpy(vectors[idx].val, v, sizeof(double) * 3);
        return 1;
    }

    ensure_capacity();

    strncpy(vectors[vector_count].name, name, NAME_LEN - 1);

    vectors[vector_count].name[NAME_LEN - 1] = '\0';

    memcpy(vectors[vector_count].val, v, sizeof(double) * 3);

    vector_count++;
    return 1;
}


// Gets a requested vector from memory
int get_vector(const char *name, double v[3]) {
    int idx = find_vector(name);
    if (idx == -1) return 0;
    memcpy(v, vectors[idx].val, sizeof(double) * 3);
    return 1;
}


// Adds 2 vectors
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


// Loads vectors from a CSV file
void load_vectors(const char *fname) {
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: could not open file '%s'\n", fname);
        return;
    }

    printf("Loading vectors from '%s'...\n", fname);

    char line[128];
    int loaded = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strlen(line) < 3) continue; // skip empty lines

        char name[NAME_LEN];
        double x, y, z;

        if (sscanf(line, " %[^,],%lf,%lf,%lf", name, &x, &y, &z) == 4) {
            double v[3] = {x, y, z};
            add_vector(name, v);
            loaded++;
        } else {
            printf("Warning: skipped malformed line: %s", line);
        }
    }

    fclose(fp);
    printf("Loaded %d vectors.\n", loaded);
}


// Saves all current vectors to a CSV file
void save_vectors(const char *fname) {
    FILE *fp = fopen(fname, "w");
    if (!fp) {
        printf("Error: could not open file '%s' for writing.\n", fname);
        return;
    }

    for (int i = 0; i < vector_count; i++) {
        fprintf(fp, "%s,%.3f,%.3f,%.3f\n",
                vectors[i].name,
                vectors[i].val[0],
                vectors[i].val[1],
                vectors[i].val[2]);
    }

    fclose(fp);
    printf("Saved %d vectors to '%s'\n", vector_count, fname);
}
