#include <stdio.h>
#include <math.h>
#include "funcs.h"

#define PI 3.14159265358979323846

/* =============================
   MENU ITEM 1 — Voltage Divider
   ============================= */
void menu_item_1(void)
{
    double Vin, R1, R2;
    printf("\n--- Voltage Divider ---\n");

    printf("Vin (V): "); scanf("%lf", &Vin);
    printf("R1 (ohms): "); scanf("%lf", &R1);
    printf("R2 (ohms): "); scanf("%lf", &R2);

    if (R1 + R2 == 0) {
        printf("Error: R1 + R2 = 0\n");
        return;
    }

    double Vout = Vin * (R2 / (R1 + R2));
    printf("Vout = %.6f V\n", Vout);
}

/* =============================
   MENU ITEM 2 — Series/Parallel
   ============================= */
void menu_item_2(void)
{
    int mode;
    printf("\n--- Resistor Tools ---\n");
    printf("1) Series total\n");
    printf("2) Parallel total (2 resistors)\n");
    printf("Select: ");
    scanf("%d", &mode);

    if (mode == 1) {
        int n;
        printf("How many resistors? ");
        scanf("%d", &n);

        double sum = 0, r;
        for (int i = 1; i <= n; i++) {
            printf("R%d: ", i);
            scanf("%lf", &r);
            sum += r;
        }
        printf("R_total(series) = %.6f ohms\n", sum);
    }

    else if (mode == 2) {
        double R1, R2;
        printf("R1: "); scanf("%lf", &R1);
        printf("R2: "); scanf("%lf", &R2);

        if (R1 == 0 || R2 == 0) {
            printf("Parallel with 0 ohms -> Req = 0\n");
            return;
        }

        double Req = (R1 * R2) / (R1 + R2);
        printf("R_eq = %.6f ohms\n", Req);
    }
}

/* =============================
   MENU ITEM 3 — AC Reactance
   ============================= */
void menu_item_3(void)
{
    int m;
    printf("\n--- AC Reactance ---\n");
    printf("1) Inductive Reactance (X_L)\n");
    printf("2) Capacitive Reactance (X_C)\n");
    printf("3) Resonant Frequency (f0)\n");
    printf("Select: ");
    scanf("%d", &m);

    if (m == 1) {
        double f, L;
        printf("f (Hz): "); scanf("%lf", &f);
        printf("L (H): "); scanf("%lf", &L);
        double XL = 2 * PI * f * L;
        printf("X_L = %.6f ohms\n", XL);
    }

    else if (m == 2) {
        double f, C;
        printf("f (Hz): "); scanf("%lf", &f);
        printf("C (F): "); scanf("%lf", &C);
        double XC = 1.0 / (2 * PI * f * C);
        printf("X_C = %.6f ohms\n", XC);
    }

    else if (m == 3) {
        double L, C;
        printf("L (H): "); scanf("%lf", &L);
        printf("C (F): "); scanf("%lf", &C);
        double f0 = 1.0 / (2 * PI * sqrt(L * C));
        printf("f0 = %.6f Hz\n", f0);
    }
}

/* =============================
   MENU ITEM 4 — RC Transient
   ============================= */
void menu_item_4(void)
{
    double R, C, t;
    printf("\n--- RC Transient ---\n");

    printf("R (ohms): "); scanf("%lf", &R);
    printf("C (F): "); scanf("%lf", &C);
    printf("t (s): "); scanf("%lf", &t);

    double tau = R * C;
    double charge     = 100.0 * (1 - exp(-t / tau));
    double discharge  = 100.0 * exp(-t / tau);

    printf("Tau = %.6f s\n", tau);
    printf("Charge(t) ≈ %.2f%%\n", charge);
    printf("Discharge(t) ≈ %.2f%%\n", discharge);
}
