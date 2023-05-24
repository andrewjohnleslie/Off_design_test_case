//
// Created by Andrew on 19/04/2023.
//

#ifndef BASIC_TURBOJET_TESTCASE_VIPER_CLASS_NOZZLE_H
#define BASIC_TURBOJET_TESTCASE_VIPER_CLASS_NOZZLE_H

#include <cmath>
#include "turbine.h"

class Nozzle : public Turbine{

public:
    double T_9 = T_05 * pow((P_a/P_05), ((gamma_e-1)/gamma_e));
    double P_9 = P_a;     //Assume the nozzle fully expands the flow so that the core jet stream exits at ambient pressure
    double T_09 = T_05;
    // P_09 = P_05;     pg 182

// DESIGN POINT table
    double F_g = 15167;
    double V_9_dp = F_g/mdot_a;                                         // V_9_dp = V_j

// Calculated thermodynamic cycle
    double V_9_calc = pow((2 * cpe * (T_09 - T_9)), 0.5);        // V_9_calc = V_j

// Discrepancy of V_j values is likely due to neglecting the combustor pressure loss, and the simplifying assumptions
    // made for the gas properties (i.e. constant gamma).

// double A_nozz_p =  ((mdot_tot * pow((cpe * T_05), 0.5)) / (P_05 * m_norm_ge));

    double y = P_05/P_a;

    double Ft = (mdot_tot * V_9_calc) - (mdot_a * V_f) + (A_nozz_p * (P_05 - P_a));
    double sfc = mdot_f / Ft;
    double Fs = Ft / mdot_a;


// OFF DESIGN CALCULATION
// =====================================

    //double T04_OD = T_05 * (1 + ((gama - 1) / 2) * pow(M_f, 2));
    double T04_OD = 950;
    double T03_OD = T_02 + ((cpe/cp) * k_H * T04_OD);
    double T05_OD = T04_OD * (1 - k_H);

    //double piC_OD = pow((T03_OD / T_02), (e_c * (gama/(gama - 1))));
    double piC_OD = 4.9;
    double z_OD = T04_OD/T_02;
    double P03_OD = piC_OD * P_02;
    double P04_OD = P03_OD;
    double P05_OD = P04_OD * pow((T05_OD / T04_OD), (gamma_e / (e_t * (gamma_e - 1))));

    double T09_OD = T05_OD;
    double T9_OD = T05_OD * pow((P_a /P05_OD), ((gamma_e - 1)/ gamma_e));
    double V9_OD = pow((2 * cpe * (T09_OD - T9_OD)), 0.5);

    double x_OD = P04_OD/P05_OD;
    double y_OD = P05_OD/P_a;

    double mdot_a_OD = ((mdot_a * pow((T_03 - T_02), 0.5)) / P_03) * (P03_OD / pow((T03_OD - T_02), 0.5));
    double mdot_f_OD = (mdot_a_OD * ((cpe * (T04_OD - 298)) - (cp * (T03_OD -298)))) / (LCV - (cp * (T04_OD - 298)));
    double mdot_tot_OD = mdot_a_OD + mdot_f_OD;

    double A_nozz_t_OD =  ((mdot_tot_OD * pow((cpe * T04_OD), 0.5)) / (P04_OD * m_norm_ge));
    double A_nozz_p_OD =  ((mdot_tot_OD * pow((cpe * T05_OD), 0.5)) / (P05_OD * m_norm_ge));

    double Ft_OD = (mdot_tot_OD * V9_OD) - (mdot_a_OD * V_f) + (A_nozz_p_OD * (P05_OD - P_a));
    double sfc_OD = mdot_f_OD / Ft_OD;
    double Fs_OD = Ft_OD / mdot_a_OD;

    Nozzle() = default;
    ~Nozzle() = default;
};
#endif //BASIC_TURBOJET_TESTCASE_VIPER_CLASS_NOZZLE_H
