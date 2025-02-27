#include<stdio.h>
#include<math.h>

#define DELD 20.0     // Distance dispersion (Mpc)
#define SIGV 150.0    // Velocity dispersion (km/s)
#define DELV 5.0      // Small velocity perturbation (km/s)
#define H0 70.0       // Hubble constant (km/s/Mpc)
#define MAX_GAL 1000  // Max total galaxies

double draw() {
    return (double)rand()/RAND_MAX;
}

double gauss_cos(double r1, double r2) {
    return sqrt(-2.0*log(r1))*cos(2*M_PI*r2);
}

double gauss_sin(double r1, double r2) {
    return sqrt(-2.0*log(r1))*sin(2*M_PI*r2);
}

int main() {
    int i, j, k = 0, NCL = 10;
    int n = 10, N = 60, ngal[NCL];
    double d = 50, D = 300, distgal[NCL];
    double dpl[MAX_GAL];  // Perturbed galaxy distances (Mpc)
    double vg[MAX_GAL];   // Galaxy velocity (km/s)
    double hpl[MAX_GAL];   // Local Hubble parameter (km/s/Mpc)

    for (i=0;i<NCL;i++) {
        distgal[i] = d + draw()*(D-d);
        ngal[i] = n+(int)(draw()*(N-n));
    }

    for (i = 0; i < NCL; i++) {
        for (j = 0; j < ngal[i]; j++, k++) {
            double r1 = draw();
            double r2 = draw();
            dpl[k] = distgal[i] + gauss_cos(r1, r2) * DELD;
            vg[k] = H0 * dpl[k] + gauss_cos(r1, r2) * SIGV + gauss_sin(r1, r2) * DELV;
            hpl[k] = vg[k] / dpl[k];

            printf("Cluster %d, Galaxy %d: Distance = %.2f Mpc, Velocity = %.2f km/s, H = %.2f km/s/Mpc\n",
                i + 1, j + 1, dpl[k], vg[k], hpl[k]);
        }
    }

}
