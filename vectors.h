/* Filename: vectors.h
 * Author: Cameron Borbas
 * Date: 10/9/2025
 * Description: Header file for vectors.c,
 *      creates required functions/variables
 */

#ifndef VECTORS_H
#define VECTORS_H

#define MAX_VECTORS 10 // Max number of vectors
#define NAME_LEN 32 // Max length of vector name


// declaring all basic functions
void clear_vectors();
void list_vectors();
int add_vector(const char *name, double v[3]);
int find_vector(const char *name);
int get_vector(const char *name, double v[3]);

void add_vectors(double a[3], double b[3], double result[3]);
void sub_vectors(double a[3], double b[3], double result[3]);
void scalar_mult_a(double a[3], double scalar, double result[3]);
void scalar_mult_b(double a[3], double scalar, double result[3]);

#endif
