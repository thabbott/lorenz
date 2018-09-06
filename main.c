#include <stdlib.h>
#include <stdio.h>
#include "lorenz.h"

#define NPTS 100
#define NSTEP 10000
#define NPRINT 1

void write_arr(const char *s, double arr[], int n);

/**
 * Program entry point
 */
int main() {
  
  /* Pointers to system coordinates */
  double x[NPTS];
  double y[NPTS];
  double z[NPTS];
  
  /* System parameters 
   * The "const" modifier indicates to the compiler that the values of these
   * parameters should not change */
  const double sigma = 10.;
  const double beta = 8./3.;
  const double rho = 28.;
  const double dt = 0.01;
  const int npt = 1000;

  /* Initialize system
   * This function is in lorenz.c and has to be implemented */
  initialize_system(x, y, z, NPTS);

  /* Run system forward
   * Each time step calls step_system, which is in lorenz.c and has to be
   * implemented */
  for (int ii = 0; ii < NSTEP; ii++) {
    if (ii % NPRINT == 0) {
      write_arr("lorenz_x.out", x, NPTS);
      write_arr("lorenz_y.out", y, NPTS);
      write_arr("lorenz_z.out", z, NPTS);
    }
    step_system(x, y, z, NPTS, sigma, beta, rho, dt);
  }
}

void write_arr(const char *s, double arr[], int n) {
  FILE *fp;
  fp = fopen(s, "a");
  for (int ii = 0; ii < n; ii++) {
    fprintf(fp, "%.5f ", arr[ii]);
  }
  fprintf(fp, "\n");
  fclose(fp);
}
