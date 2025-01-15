#define BUFFER_SIZE 60 /* The buffer size for our input lines */

/* Include external headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Include internal headers */
#include "complex.h"
#include "utils.h"

complex A,B,C,D,E,F; /* Declare our complex variables */

int main(){
  /* Initialize all our variables to 0 + 0i */
  assign_comp(&A, 0.0, 0.0);
  assign_comp(&B, 0.0, 0.0);
  assign_comp(&C, 0.0, 0.0);
  assign_comp(&D, 0.0, 0.0);
  assign_comp(&E, 0.0, 0.0);
  assign_comp(&F, 0.0, 0.0);

  char buffer[BUFFER_SIZE]; /* Our buffer that holds the input lines */
  /* Welcome message for the user. */
  printf("---------------------------------\nWelcome to this Complex Numbers Calculator.\nThis calculator lets you store complex numbers and do computations on them.\nIt provides responsive and helpful feedback when encountering issues.\n---------------------------------\n");
  print_symbol();
  
  /* This loop handles user input. */
  while (true){
    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL){
      printf("EOF has been reached, or potentially an error occurred.\n");
      break; /* EOF has been reached, or an error has occured. */
    }
    
    /* Because fgets includes the new line charcter, we remove it from the end of the string. */
    buffer[strcspn(buffer, "\n")] = '\0';
    
    if (repeated_commas(buffer)){
      /* 
        In the case of multiple consecutive commas, we must throw a feedback and dismiss.
      */
      printf("Multiple consecutive commas\n");
      print_symbol();
      continue;
    }
    
    printf("%s\n", buffer); /* Resend the original line, to deal with input files clarity. */
    
    char *command = strtok(buffer, " "); /* The first token separated by a comma is our actual command. */
    
    if (command == NULL){
      /*
        Handle when our line is empty/external errors.
      */
      print_symbol();
      continue;
    }
    
    if (strchr(command, ',')){
      /* 
        strchr returns true whether the string ends with a ','
        This handles the scenario where an illegally placed comma exists in the first token.
      */
      printf("Illegal comma\n");
      print_symbol();
      continue;
    }
    
    /*
      
      Up ahead handles everything to do with serializing and identifying commands.
      The general structure would be:
      cmd arg(1), arg(2), ..., arg(n)
      
      The structure of error-checks generally looks as follows:
      #1) Check for missing parameters
      #2) Check for extraneous text
      #3) Trim spaces off of arguments
      #4) Validate argument types (valid complex variables, numbers...)

      This architecture ensures proper program flow as error-avoidance.
      Additionally, when providing user feedback, we repeat calling print_symbol.
      This ensures we have unique case-checking for individual feedbacks to allow for good program flow.
    */
    
    /* Handle read_comp */
    if (!strcmp(command, "read_comp")){
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
      
      arg1 = remove_spaces(arg1);
      arg2 = remove_spaces(arg2);
      arg3 = remove_spaces(arg3);
      
      if (!is_variable(arg1)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
    
      if (!is_number(arg2)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
      
      if (!is_number(arg3)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
    
      /*  
        Cast our arguments r1, r2 from strings into real numbers (double) using atof.
      */
      double r1 = atof(arg2);
      double r2 = atof(arg3);
      read_comp(arg1, r1, r2); /* Use the read_comp method to perform the calculations. */
      print_symbol();
      continue;
    }
    
    /* Handle print_comp */
    if (!strcmp(command, "print_comp")){
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
      
      arg1 = remove_spaces(arg1);
      
      complex *comp = get_comp(arg1);
      if (comp){
        display_comp(comp);
      }
      
      print_symbol();
      continue;
    }
    
    /* Handle add_comp */
    if (!strcmp(command, "add_comp")){
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
      
      arg1 = remove_spaces(arg1);
      arg2 = remove_spaces(arg2);
      
      if (!is_variable(arg1) || !is_variable(arg2)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
      
      complex *result = add_comp(arg1, arg2);
      if (result){
        display_comp(result);
        
        free(result); 
        print_symbol();
      }

      continue;
    }
    
    /* Handle sub_comp */
    if (!strcmp(command, "sub_comp")){
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
      
      arg1 = remove_spaces(arg1);
      arg2 = remove_spaces(arg2);
      
      if (!is_variable(arg1) || !is_variable(arg2)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
      
      complex *result = sub_comp(arg1, arg2);
      if (result){
        display_comp(result);
        free(result);
        print_symbol();
      }

      continue;
    }
    
    /* Handle mult_comp_real */
    if (!strcmp(command, "mult_comp_real")){
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
      
      arg1 = remove_spaces(arg1);
      arg2 = remove_spaces(arg2);
      
      if (!is_variable(arg1)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
      
      if (!is_number(arg2)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
    
      float r2 = atof(arg2);
      complex *result = mult_comp_real(arg1, r2);
      display_comp(result);
      
      free(result);
      print_symbol();
      continue;
    }
    
    /* Handle mult_comp_img */
    if (!strcmp(command, "mult_comp_img")){
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
      
      arg1 = remove_spaces(arg1);
      arg2 = remove_spaces(arg2);
      
      if (!is_variable(arg1)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
      
      if (!is_number(arg2)){
        printf("Invalid parameter - not a number\n");
        print_symbol();
        continue;
      }
      
      float r2 = atof(arg2);
      complex *result = mult_comp_img(arg1, r2);
      display_comp(result);
      
      free(result);
      print_symbol();
      continue;
    }
    
    /* Handle mult_comp_comp */
    if (!strcmp(command, "mult_comp_comp")){
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
      
      arg1 = remove_spaces(arg1);
      arg2 = remove_spaces(arg2);
      
      if (!is_variable(arg1) || !is_variable(arg2)){
        printf("Undefined complex variable\n");
        print_symbol();
        continue;
      }
      
      complex *result = mult_comp_comp(arg1, arg2);
      display_comp(result);
      
      free(result);
      print_symbol();
      continue;
    }
    
    /* Handle abs_comp */
    if (!strcmp(command, "abs_comp")){
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
      
      arg1 = remove_spaces(arg1);
      
      if (!is_variable(arg1)){
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
    if (!strcmp(command, "stop")){
      char *arg_extra = strtok(NULL, ",");
      
      if (arg_extra != NULL && strlen(arg_extra) != 0){
        printf("Extraneous text after end of command\n");
        continue;
      }
      
      break;
    }
    
    /*
      If thus far no command has been skipped on, we must have landed on a wrong command name.
    */
    printf("Undefined command name.\n");
    print_symbol();
  }
  
  return 0;
}
