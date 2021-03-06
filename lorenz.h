/** Set initial values for x, y, and z
 * @param x,y,z: arrays of initial values for system
 * @param npts: number of initial values
 */
extern void initialize_system(double x[], double y[], double z[], int npts);

/** Step x, y, and z forward by an amount dt
 * @param x,y,z: arrays of values for system
 * @param npts: number of initial values
 * @param sigma, beta, rho: system parameters
 * @param dt: time step
 */
extern void step_system(double x[], double y[], double z[], int npts,
                 double sigma, double beta, double rho, double dt);
