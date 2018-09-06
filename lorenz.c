/** Set initial values for x, y, and z
 * @param x,y,z: arrays of initial values for system
 * @param npts: number of initial values
 */
void initialize_system(double x[], double y[], double z[], int npts) {
  for (int ii = 0; ii < npts; ii++) {
    x[ii] = 1. + 1./(100.*npts)*ii;
    y[ii] = 1. + 1./(100.*npts)*ii;
    z[ii] = 1. + 1./(100.*npts)*ii;
  }
}

/** Step x, y, and z forward by an amount dt
 * @param x,y,z: arrays of values for system
 * @param npts: number of initial values
 * @param sigma, beta, rho: system parameters
 * @param dt: time step
 */
void step_system(double x[], double y[], double z[], int npts,
                 double sigma, double beta, double rho, double dt) {
  double dx;
  double dy;
  double dz;
  for (int ii = 0; ii < npts; ii++) {
    dx = dt * sigma * (y[ii] - x[ii]);
    dy = dt * (x[ii] * (rho - z[ii]) - y[ii]);
    dz = dt * (x[ii] * y[ii] - beta * z[ii]);
    x[ii] += dx;
    y[ii] += dy;
    z[ii] += dz;
  }
}
