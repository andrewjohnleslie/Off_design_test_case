//
// Created by Andrew on 19/04/2023.
//

#ifndef BASIC_TURBOJET_TESTCASE_VIPER_CLASS_TURBINE_H
#define BASIC_TURBOJET_TESTCASE_VIPER_CLASS_TURBINE_H

#include <iostream>
#include <cmath>
#include "compressor.h"

class Turbine : public Compressor {

private:

    void myCustomFunction() {
       /* if (choke_t >= 1.832){
            std::cout << std::endl;
            std::cout << "Turbine is choked!" << std::endl;
        }else{
            std::cout << std::endl;
            std::cout << "Turbine is not choked!" << std::endl;

            // double m_norm_ge = pow(gamma_e, (gamma_e - 1)) * pow(2*(pow(P_a/P_05, 2/gamma_e) - pow(P_a/P_05, (gamma_e + 1)/gamma_e)) , 0.5);     pg 77, 177
        }
        */
    }

public:
    Turbine() = default;
    ~Turbine() = default;

    double e_t = 0.85;
    double mdot_a = 23.81;
    double mdot_f = 0.4267;
    double mdot_tot = mdot_a + mdot_f;
    double LCV = 43100000;

    double energy_rel = mdot_f * LCV;
    // double sp_energy_rel = energy_rel/mdot_a                             [per kg of air-flow]

    double T_04 = ((energy_rel + (mdot_a * cp * (T_03 - 298))) / ((mdot_a + mdot_f) * cpe)) + 298;
    double P_04 = P_03;                          // Pressure loss in the combustor is neglected: P_04 = (1 - delP_c) * P_03

    double T_05 = T_04 - DelT_t;
    double P_05 = P_04 * pow((T_05/T_04), (gamma_e / (e_t * (gamma_e-1))));

    double x = P_04/P_05;

    double Pcrit = pow(((gamma_e + 1)/2), ((gamma_e)/(gamma_e - 1)));

    double m_norm_ge = (gamma_e / pow((gamma_e - 1), 0.5)) * pow(((gamma_e + 1) / 2), ((-1 * (gamma_e + 1)) / (2 * (gamma_e - 1))));      // norm_mf = 1.389 for gamma = 1.3
    // m_norm_4 == m_norm_9

    double A_nozz_t =  ((mdot_tot * pow((cpe * T_04), 0.5)) / (P_04 * m_norm_ge));
    double A_nozz_p =  ((mdot_tot * pow((cpe * T_05), 0.5)) / (P_05 * m_norm_ge));     // THIS COULD BE USED TO WORK OUT K_H

    double k_H = (T_04 - T_05) / T_04;

    // This is a method to bypass the private function.
    // Within the class, a public custom function 'callmyCustomFunction' will call the private custom function 'myCustomFunction'.
    void callmyCustomFunction(){
        myCustomFunction();
    }

    double choke_t = P_04/Pcrit;        // If P_04/P* >= 1.832, the engine is choked for gamma values = 1.3!  pg 177

    double SigT = (2 * e_t * (gamma_e - 1)) / ((2 * gamma_e) - (e_t * (gamma_e - 1)));        // pg 180
    double SigP = (2 * gamma_e) / ((2 * gamma_e) - (e_t * (gamma_e - 1)));                    // pg 180

    double pi_t = pow((A_nozz_t/A_nozz_p), SigP);
    double tau_t = pow((A_nozz_t/A_nozz_p), SigT);
};

#endif //BASIC_TURBOJET_TESTCASE_VIPER_CLASS_TURBINE_H
