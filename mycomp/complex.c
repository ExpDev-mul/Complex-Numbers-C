#include <string.h>
#include <math.h>
#include "complex.h"

complex *get_comp(char *name){
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

void set_comp(complex *complex_num, float r1, float r2){
  complex_num->re = r1;
  complex_num->im = r2;
}

void read_comp(char *name, float r1, float r2){
  complex *comp = get_comp(name);
  set_comp(comp, r1, r2);
}

complex *add_comp(char *name1, char *name2){
  complex *comp1 = get_comp(name1);
  complex *comp2 = get_comp(name2);
  
  complex *result = (complex *) malloc(sizeof(complex));
  set_comp(result, comp1->re + comp2->re, comp1->im + comp2->im);
  return result;
}

complex *sub_comp(char *name1, char *name2){
  complex *comp1 = get_comp(name1);
  complex *comp2 = get_comp(name2);
  
  complex *result = (complex *) malloc(sizeof(complex));
  set_comp(result, comp1->re - comp2->re, comp1->im - comp2->im);
  return result;
}

complex *mult_comp_real(char *name, float r2){
  complex *comp = get_comp(name);
  
  complex *result = (complex *) malloc(sizeof(complex));
  set_comp(result, r2*comp->re, r2*comp->im);
  return result;
}

complex *mult_comp_img(char *name, float r2){
  complex *comp = get_comp(name);
  
  complex *result = (complex *) malloc(sizeof(complex));
  set_comp(result, -comp->im*r2, comp->re*r2);
  return result;
}

double abs_comp(char *name){
  complex *comp = get_comp(name);
  return sqrt(pow(comp->re, 2) + pow(comp->im, 2));
}
