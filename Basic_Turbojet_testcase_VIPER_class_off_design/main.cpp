// This test case is the preliminary test case for a simple turbojet (single-spool) engine.
// The engine being considered and modelled is the Rolls-Royce Viper [Mark 601] turbojet engine.
// This program places the previous code into an inherited class structure.

// The data provided for this engine is at a DESIGN POINT for a sea-level test bed.
// F_G = 15167 (N)
// sfc = 0.993 (kg/h/kg)
// m_a = 23.81 (kg/s)
// m_f = 0.4267 (kg/s)
// OPR [P_03/P_02] = 5.5

#include <iostream>
#include "inlet.h"
#include "compressor.h"
#include "turbine.h"
#include "nozzle.h"

int main() {

    //std::cout << "Ta = " << Inlet().T_a << std::endl;
    //std::cout << "Pa = " << Inlet().P_a << std::endl;
    //std::cout << "T_02 = " << Inlet().T_02 << std::endl;
    //std::cout << "P_02 = " << Inlet().P_02 << std::endl;
    //std::cout << "T_03 = " << Compressor().T_03 << std::endl;
    std::cout << "Off-design: T_03 = " << Nozzle().T03_OD << std::endl;
    //std::cout << "P_03 = " << Compressor().P_03 << std::endl;
    //std::cout << "Off-design: P_03 = " << Nozzle().P03_OD << std::endl;
    std::cout << "T_04 = " << Turbine().T_04 << std::endl;
    std::cout << "Off-design: T_04 = " << Nozzle().T04_OD << std::endl;
    //std::cout << "P_04 = " << Turbine().P_04 << std::endl;
    //std::cout << "Off-design: P_03 = " << Nozzle().P03_OD << std::endl;
    //std::cout << "T_05 = " << Turbine().T_05 << std::endl;
    //std::cout << "Off-design: T_05 = " << Nozzle().T05_OD << std::endl;
    //std::cout << "P_05 = " << Turbine().P_05 << std::endl;
    //std::cout << "Off-design: P_05 = " << Nozzle().P05_OD << std::endl;
    std::cout << "T_09 = " << Nozzle().T_09 << std::endl;
    //std::cout << "Off-design: T_09 = " << Nozzle().T09_OD << std::endl;
    std::cout << "T_9 = " << Nozzle().T_9 << std::endl;
    //std::cout << "Off-design: T_9 = " << Nozzle().T9_OD << std::endl;
    //std::cout << "P_9 = " << Nozzle().P_9 << std::endl;
    //std::cout << "V_9 = " << Nozzle().V_9_calc << std::endl;          // Calculated jet velocity
    //std::cout << "mbar_choke_ge = " << Turbine().m_norm_ge << std::endl;
    std::cout << "Turbine nozzle area  (m^2) = " << Turbine().A_nozz_t << std::endl;
    std::cout << "Propulsive nozzle area  (m^2) = " << Turbine().A_nozz_p << std::endl;
    std::cout << "Off-design: Turbine nozzle area  (m^2) = " << Nozzle().A_nozz_t_OD << std::endl;
    std::cout << "Off-design: Propulsive nozzle area  (m^2) = " << Nozzle().A_nozz_p_OD << std::endl;
    std::cout << "Critical pressure ratio - TURBINE = " << Turbine().Pcrit << std::endl;
    std::cout << "Turbine pressure ratio = " << Turbine().x << std::endl;
    std::cout << "Off-design: Turbine pressure ratio = " << Nozzle().x_OD << std::endl;
    std::cout << "Off-design: Compressor pressure ratio = " << Nozzle().piC_OD << std::endl;
    std::cout << "Off-design: T_04/T_02 = " << Nozzle().z_OD << std::endl;
    std::cout << "Nozzle pressure ratio = " << Nozzle().y << std::endl;
    std::cout << "Off-design: Nozzle pressure ratio = " << Nozzle().y_OD << std::endl;
    //std::cout << "Flight speed = " << Inlet().V_f << std::endl;
    std::cout << "Thrust (F_T) = " << Nozzle().Ft << std::endl;
    std::cout << "Specific thrust (F_S) = " << Nozzle().Fs << std::endl;
    std::cout << "SFC = " << Nozzle().sfc << std::endl;
    std::cout << "========================================================== " << std::endl;
    std::cout << "Off-design: Thrust (F_T) = " << Nozzle().Ft_OD << std::endl;
    std::cout << "Off-design: Specific thrust (F_S) = " << Nozzle().Fs_OD << std::endl;
    std::cout << "Off-design: SFC = " << Nozzle().sfc_OD << std::endl;
    std::cout << "========================================================== " << std::endl;
    std::cout << "Off-design: Intake mass flow = " << Nozzle().mdot_a_OD << std::endl;
    std::cout << "Off-design: Fuel mass flow = " << Nozzle().mdot_f_OD << std::endl;
    std::cout << "Off-design: Total mass flow = " << Nozzle().mdot_tot_OD << std::endl;

    Turbine obj;
    obj.callmyCustomFunction();

    return 0;
}
