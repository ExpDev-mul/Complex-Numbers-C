/* Include headers */
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Include internal headers */
#include "complex.h"
#include "utils.h"

/*
  Here we define extremely useful functions for handling complex instances.
*/

complex *get_comp(char *name){
  /* Iterate through all the matching names and return the respective complex instance reference. */
  if (!strcmp(name, "A")){
    return &A;
  } else if (!strcmp(name, "B")){
    return &B;
  } else if (!strcmp(name, "C")){
    return &C;
  } else if (!strcmp(name, "D")){
    return &D;
  } else if (!strcmp(name, "E")){
    return &E;
  } else if (!strcmp(name, "F")){
    return &F;
  } else {
    return NULL;
  }
}

void assign_comp(complex *complex_num, double re, double im){
  /* Assign the respective values */
  complex_num->re = re;
  complex_num->im = im;
}

void display_comp(complex *complex_num){
  if (complex_num == NULL){
    return;
  }

  /* Displays the complex number */
  printf("%.2f + (%.2f)i\n", complex_num->re, complex_num->im);
}

/*
  We now begin to define the actual command-handling functions.
*/

void read_comp(char *name, double r1, double r2){
  complex *comp = get_comp(name);
  assign_comp(comp, r1, r2);
}

complex *add_comp(char *name1, char *name2){
  complex *comp1 = get_comp(name1);
  complex *comp2 = get_comp(name2);
  
  double a = comp1->re, b = comp1->im;
  double c = comp2->re, d = comp2->im;
  
  complex *result = (complex *) malloc(sizeof(complex));
  assign_comp(result, a + c, b + d);
  return result;
}

complex *sub_comp(char *name1, char *name2){
  complex *comp1 = get_comp(name1);
  complex *comp2 = get_comp(name2);
  
  double a = comp1->re, b = comp1->im;
  double c = comp2->re, d = comp2->im;
  
  complex *result = (complex *) malloc(sizeof(complex));
  assign_comp(result, a - c, b - d);
  return result;
}

complex *mult_comp_real(char *name, double m){
  complex *comp = get_comp(name);
  
  double a = comp->re, b = comp->im;
  
  complex *result = (complex *) malloc(sizeof(complex));
  assign_comp(result, m*a, m*b);
  return result;
}

complex *mult_comp_img(char *name, double m){
  complex *comp = get_comp(name);
  
  double a = comp->re, b = comp->im;
  
  complex *result = (complex *) malloc(sizeof(complex));
  assign_comp(result, -m*b, m*a);
  return result;
}

complex *mult_comp_comp(char *name1, char *name2){
  complex *comp1 = get_comp(name1);
  complex *comp2 = get_comp(name2);
  
  double a = comp1->re, b = comp1->im;
  double c = comp2->re, d = comp2->im;
  
  complex *result = (complex *) malloc(sizeof(complex));
  assign_comp(result, a*c - b*d, a*d + b*c);
  return result;
}

double abs_comp(char *name){
  complex *comp = get_comp(name);
  
  double a = comp->re, b = comp->im;

  return sqrt(pow(a, 2) + pow(b, 2));
}
