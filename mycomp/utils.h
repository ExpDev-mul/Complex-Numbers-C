/* Define a custom bool type to replicate behavior in other languages. */
typedef enum { false, true } bool;

void print_symbol(); /* The function resposible for displaying the user input line. */

char *remove_spaces_overload(char str[]); /* An overloading function of trim_spaces */
char *remove_spaces(char *str); /* A function that trims spaces of a pointer string */

bool is_variable(char *name); /* Returns whether the pointer string is a valid variable (A,B...) */
bool is_number(char *name); /* Returns whether the pointer string is a valid number */
bool repeated_commas(char *args); /* Returns whether the pointer strings contains at least 2 consecutive commas */

