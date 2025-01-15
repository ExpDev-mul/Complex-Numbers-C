/* Include external headers */
#include <stdio.h>
#include <string.h>

/* Include internal headers */
#include "utils.h"
#include "complex.h"

void print_symbol(){
  printf("> ");
}

/* 
  Strings manipulation methods ahead, for dealing with strings.
*/

char *remove_spaces_overload(char str[]){
    /* Remove leading spaces */
    while (*str == ' ') {
        str++;
    }

    /* Remove ending spaces */
    char *end = str + strlen(str) - 1;

    while (end >= str && *end == ' ') {
        *end = '\0';
        end--;
    }

    return str;
}

char *remove_spaces(char *str){
    /*
      Converts the pointer-string into a temporary buffer.
      Then returns the result where spaces have been removed.
    */
    char *bufferptr = (char *)malloc(strlen(str) + 1);
    if (!bufferptr) {
        return NULL;
    }

    strcpy(bufferptr, str);
    char *updated = remove_spaces_overload(bufferptr);
    char *result = (char *)malloc(strlen(updated) + 1);
    if (!result) {
        free(bufferptr);
        return NULL;
    }

    strcpy(result, updated);
    free(bufferptr);
    return result;
}

bool is_variable(char *name){
  if (!strcmp(name, "A") || !strcmp(name, "B") ||
      !strcmp(name, "C") || !strcmp(name, "D") ||
      !strcmp(name, "E") || !strcmp(name, "F")){
    return true;
  }
  
  return false;
}

bool is_number(char *name){
  char *endptr;
  strtod(name, &endptr);
  return (*name != '\0' && *endptr == '\0');
}

bool repeated_commas(char *args){
  if (!args){
    return false;
  }

  bool prev_comma = false;
  char *c = args;
  
  while (*c != '\0'){
    if (*c == ','){
      if (prev_comma){
        return true;
      }
      
      prev_comma = true;
    } else {
      prev_comma = false;
    }
    
    c++;
  }
  
  return false;
}
