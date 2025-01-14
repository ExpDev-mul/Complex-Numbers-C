#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "complex.h"
complex A,B,C,D,E,F; /* Declare our complex variables */

#define BUFFER_SIZE 30 /* The buffer size for our input lines */
typedef enum { false, true } bool;

char *trim_spaces(char *str){
  /*
    Returns a pointer to the first non-space character in a string
  */
  
  while (*str == ' '){
    str++;
  }
  
  return str;
}

bool is_valid_variable(char *name){
  if (!strcmp(name, "A") || !strcmp(name, "B") ||
      !strcmp(name, "C") || !strcmp(name, "D") ||
      !strcmp(name, "E") || !strcmp(name, "F")){
    return true;
  }
  
  return false;
}

void print_symbol(){
  printf("> ");
}

bool is_valid_number(char *name){
  char *endptr;
  strtod(name, &endptr);
  return (*name != '\0' && *endptr == '\0');
}

/* Declare our complex variables */

int main(){
  char buffer[BUFFER_SIZE]; /* Our buffer that holds the input lines */
  
  /* Initialize all our variables to 0 + 0i */
  set_comp(&A, 0.0, 0.0);
  set_comp(&B, 0.0, 0.0);
  set_comp(&C, 0.0, 0.0);
  set_comp(&D, 0.0, 0.0);
  set_comp(&E, 0.0, 0.0);
  set_comp(&F, 0.0, 0.0);
  
  printf("This program enables you to do computations with complex numbers.\n");
  printf("> ");
  
  /* Read user input */
  while (1){
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL){
      printf("EOF reaced, or an error has occured. Program terminated.");
      break; /* EOF has been reached, or an error has occured. */
    }
    
    /* Because fgets includes the new line charcter, we remove it from the end of the string. */
    buffer[strcspn(buffer, "\n")] = '\0';
    
    char *cmd = strtok(buffer, " "); /* The first continuous text in the line. */
    
    /* Handle read_comp */
    if (!strcmp(cmd, "read_comp")){
      /* read_comp arg1, arg2, arg3 */
      char *arg1 = strtok(NULL, ",");
      char *arg2 = strtok(NULL, ",");
      char *arg3 = strtok(NULL, ",");
      
      if (arg3 == NULL || arg2 == NULL || arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
      
      arg1 = trim_spaces(arg1);
      arg2 = trim_spaces(arg2);
      arg3 = trim_spaces(arg3);
      if (!is_valid_variable(arg1)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
    
      if (!is_valid_number(arg2)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
      
      if (!is_valid_number(arg3)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
    
      float r1 = atof(arg2);
      float r2 = atof(arg3);
      read_comp(arg1, r1, r2);
      print_symbol();
      continue;
    }
    
    /* Handle print_comp */
    if (!strcmp(cmd, "print_comp")){
      /* print_comp arg1 */
      char *arg1 = strtok(NULL, ",");
      
      if (arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
      
      complex *comp = get_comp(arg1);
      if (comp){
        printf("%.2f + (%.2f)i\n", comp->re, comp->im);
      }
      
      print_symbol();
      continue;
    }
    
    /* Handle add_comp */
    if (!strcmp(cmd, "add_comp")){
      /* read_comp arg1, arg2, arg3 */
      char *arg1 = strtok(NULL, ",");
      char *arg2 = strtok(NULL, ",");
      
      if (arg2 == NULL || arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
      
      complex *result = add_comp(arg1, arg2);
      if (result){
        printf("%.2f + (%.2f)i\n", result->re, result->im);
        free(result); 
        print_symbol();
      }

      continue;
    }
    
    /* Handle sub_comp */
    if (!strcmp(cmd, "sub_comp")){
      /* read_comp arg1, arg2, arg3 */
      char *arg1 = strtok(NULL, ",");
      char *arg2 = strtok(NULL, ",");
      
      if (arg2 == NULL || arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
      
      complex *result = sub_comp(arg1, arg2);
      if (result){
        printf("%.2f + (%.2f)i\n", result->re, result->im);
        free(result);
        print_symbol();
      }

      continue;
    }
    
    /* Handle mult_comp_real */
    if (!strcmp(cmd, "mult_comp_real")){
      /* read_comp arg1, arg2, arg3 */
      char *arg1 = strtok(NULL, ",");
      char *arg2 = strtok(NULL, ",");
      
      if (arg2 == NULL || arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
    
      float r2 = atof(arg2);
      complex *result = mult_comp_real(arg1, r2);
      printf("%.2f + (%.2f)i\n", result->re, result->im);
      free(result);
      print_symbol();
      continue;
    }
    
    /* Handle mult_comp_img */
    if (!strcmp(cmd, "mult_comp_img")){
      /* read_comp arg1, arg2, arg3 */
      char *arg1 = strtok(NULL, ",");
      char *arg2 = strtok(NULL, ",");
      
      if (arg2 == NULL || arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
      
      if (!is_valid_number(arg2)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
      

      float r2 = atof(arg2);
      complex *result = mult_comp_img(arg1, r2);
      printf("%.2f + (%.2f)i\n", result->re, result->im);
      free(result);
      print_symbol();
      continue;
    }
    
    /* Handle abs_comp */
    if (!strcmp(cmd, "abs_comp")){
      /* print_comp arg1 */
      char *arg1 = strtok(NULL, ",");
      
      if (arg1 == NULL){
        printf("Missing parameter\n");
        print_symbol();
        continue;
      }
      
      char *arg_extra = strtok(NULL, "");
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        print_symbol();
        continue;
      }
      
      if (!is_valid_variable(arg1)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
      
      double abs = abs_comp(arg1);
      printf("%.2f\n", abs);
      print_symbol();
      continue;
    }
    
    /* Handle stop */
    if (!strcmp(cmd, "stop")){
      char *arg_extra = strtok(NULL, ",");
      
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        continue;
      }
      
      break;
    }
    
    printf("Undefined command name.\n");
    print_symbol();
  }
  
  return 0;
}
