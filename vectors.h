/* Filename: vectors.h
 * Author: Cameron Borbas
 * Date: 10/27/2025
 * Description: Header file for vectors.c,
 *      updated to support dynamic memory and file I/O
 */

#ifndef VECTORS_H
#define VECTORS_H

#define NAME_LEN 32 // Max length of vector name

// Structure for vector data
typedef struct {
    char name[NAME_LEN];
    double val[3];
} Vector;

// Declaring all basic functions
void clear_vectors();
void list_vectors();
int add_vector(const char *name, double v[3]);
int find_vector(const char *name);
int get_vector(const char *name, double v[3]);

void add_vectors(double a[3], double b[3], double result[3]);
void sub_vectors(double a[3], double b[3], double result[3]);
void scalar_mult_a(double a[3], double scalar, double result[3]);
void scalar_mult_b(double a[3], double scalar, double result[3]);

// Loading and Saving vectors to/from files
void load_vectors(const char *fname);
void save_vectors(const char *fname);

#endif
