typedef struct {
  double re; /* The real part */
  double im; /* The imaginary part */
}  complex;

/* Globally declare our complex numbers */
extern complex A,B,C,D,E,F;

complex *get_comp(char *name);
/* 
  Receives a string, returns a reference to the corresponding complex number. 
*/

void assign_comp(complex *complex_num, double re, double im);
/* 
  Receives a string, and the real and imaginary parts. 
  Updates the corresponding complex number to the string with the new real and imaginary parts.
*/


/* Ahead we define all of our command functions. */
void read_comp(char *name, double r1, double r2);
complex *add_comp(char *name1, char *name2);
complex *sub_comp(char *name1, char *name2);
complex *mult_comp_real(char *name, double m);
complex *mult_comp_img(char *name, double m);
complex *mult_comp_comp(char *name1, char *name2);
double abs_comp(char *name);
