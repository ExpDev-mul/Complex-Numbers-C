typedef struct {
  float re; /* The real part */
  float im; /* The imaginary part */
}  complex;

extern complex A,B,C,D,E,F;

complex *get_comp(char *name);
void set_comp(complex *complex_num, float r1, float r2);

void read_comp(char *name, float r1, float r2);
complex *add_comp(char *name1, char *name2);
complex *sub_comp(char *name1, char *name2);
complex *mult_comp_real(char *name, float r2);
complex *mult_comp_img(char *name, float r2);
double abs_comp(char *name);
