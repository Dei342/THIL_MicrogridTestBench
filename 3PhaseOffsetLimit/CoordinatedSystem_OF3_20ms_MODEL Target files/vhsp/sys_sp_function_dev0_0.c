// generated using template: cop_main.template---------------------------------------------
/******************************************************************************************
**
**  Module Name: cop_main.c
**  NOTE: Automatically generated file. DO NOT MODIFY!
**  Description:
**            Main file
**
******************************************************************************************/
// generated using template: arm/custom_include.template-----------------------------------


#ifdef __cplusplus
#include <limits>

extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <complex.h>
#include <time.h>
#include <stdarg.h>

// x86 libraries:
#include "../include/sp_functions_dev0.h"


#ifdef __cplusplus
}
#endif


// ----------------------------------------------------------------------------------------                // generated using template:generic_macros.template-----------------------------------------
/*********************** Macros (Inline Functions) Definitions ***************************/

// ----------------------------------------------------------------------------------------

#ifndef MAX
#define MAX(value, limit) (((value) > (limit)) ? (value) : (limit))
#endif
#ifndef MIN
#define MIN(value, limit) (((value) < (limit)) ? (value) : (limit))
#endif

// generated using template: VirtualHIL/custom_defines.template----------------------------

typedef unsigned char X_UnInt8;
typedef char X_Int8;
typedef signed short X_Int16;
typedef unsigned short X_UnInt16;
typedef int X_Int32;
typedef unsigned int X_UnInt32;
typedef unsigned int uint;
typedef double real;

// ----------------------------------------------------------------------------------------
// generated using template: custom_consts.template----------------------------------------

// arithmetic constants
#define C_SQRT_2                    1.4142135623730950488016887242097f
#define C_SQRT_3                    1.7320508075688772935274463415059f
#define C_PI                        3.1415926535897932384626433832795f
#define C_E                         2.7182818284590452353602874713527f
#define C_2PI                       6.283185307179586476925286766559f

//@cmp.def.start
//component defines












//@cmp.def.end


//-----------------------------------------------------------------------------------------
// generated using template: common_variables.template-------------------------------------
// true global variables





// const variables
static const int _ieut_meas_instantaneous__n_rd_as = 13107200;
static const unsigned int _ieut_meas_instantaneous__p_addr = 65;
static const char* _ieut_meas_instantaneous__p_sig_output = "True";


static const unsigned int _ieut_meas_rt1_output__p_addr = 792723460;
static const unsigned char _ieut_meas_rt1_output__p_rate_transition_as_cpu_transition = 0;


static const unsigned int _ieut_meas_rt2_output__p_addr = 792723464;
static const unsigned char _ieut_meas_rt2_output__p_rate_transition_as_cpu_transition = 0;

static const int _ieut_meas_rms_calc_fast__n_period = 200;
static const int _ieut_meas_rms_calc_fast__n_period_timeout = 5000;
static const real _ieut_meas_rms_calc_fast__p_curr_f_coef_1 = 0.909;
static const real _ieut_meas_rms_calc_fast__p_curr_f_coef_2 = 0.0909;
static const char* _ieut_meas_rms_calc_fast__p_op_mode = "PLL based";








static const unsigned int _ieut_meas_rt1_input__p_addr = 792723460;
static const real _ieut_meas_rt1_input__p_init_value = 0.0;
static const unsigned char _ieut_meas_rt1_input__p_rate_transition_as_cpu_transition = 0;


static const unsigned int _ieut_meas_rt2_input__p_addr = 792723464;
static const real _ieut_meas_rt2_input__p_init_value = 0.0;
static const unsigned char _ieut_meas_rt2_input__p_rate_transition_as_cpu_transition = 0;




static const unsigned char _ieut_meas_cpu_trans_input__n_real_time = 1;
static const unsigned char _ieut_meas_cpu_trans_input__n_export_c = 0;
static const unsigned int _ieut_meas_cpu_trans_input__p_addr = 792723456;

static const int _ieut_meas_rms__n_out_size = 1;
static const unsigned int _ieut_meas_rms__p_addr = 32768;





//@cmp.var.start
// variables
real _ieut_meas_instantaneous__out;
real _ieut_meas_rt1_output__out;
real _ieut_meas_rt2_output__out;
static real _ieut_meas_rms_calc_fast__var_filt;
static real _ieut_meas_rms_calc_fast__period;
static real _ieut_meas_rms_calc_fast__var_eff_s;

static real _ieut_meas_rms_calc_slow__var_rms;








//@cmp.var.end

//@cmp.svar.start
// state variables









real _ieut_meas_rms_calc_fast__v_sq_sum_state;
unsigned int _ieut_meas_rms_calc_fast__pc_cnt_1_state;
real _ieut_meas_rms_calc_fast__var_eff_s_state;
real _ieut_meas_rms_calc_fast__var_filt_state;
real _ieut_meas_rms_calc_fast__period_state;
unsigned char _ieut_meas_rms_calc_fast__var_zc;


























//@cmp.svar.end

// IO shared variables
volatile float shared__ieut_meas_rt1_0;
volatile float shared__ieut_meas_rt2_0;

//
// Tunable parameters
//
static struct Tunable_params {
} __attribute__((__packed__)) tunable_params;

void *tunable_params_dev0_cpu2_ptr = &tunable_params;

// Dll function pointers
#if defined(_WIN64)
#else
// Define handles for loading dlls
#endif





// generated using template: \templates\virtual_hil\fmi_custom_logger_fncs.template---------------------------------
#include <stdarg.h>



//
// DMA buffers
//

























































// generated using template: virtual_hil/custom_functions.template---------------------------------
void ReInit_sys_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rReInitTimer");
#endif
    //@cmp.init.block.start
    {
        _ieut_meas_rms_calc_fast__v_sq_sum_state = 0.0;
        _ieut_meas_rms_calc_fast__pc_cnt_1_state = 0;
        _ieut_meas_rms_calc_fast__var_eff_s_state = 0.0;
        _ieut_meas_rms_calc_fast__var_filt_state = 0.0;
        _ieut_meas_rms_calc_fast__period_state = 0.0;
        _ieut_meas_rms_calc_fast__var_zc = 0;
    }
    {
        shared__ieut_meas_rt1_0 = _ieut_meas_rt1_input__p_init_value;
    }
    {
        shared__ieut_meas_rt2_0 = _ieut_meas_rt2_input__p_init_value;
    }
    {
        XIo_OutFloat(0x2f400000, 0);
    }
    {
        HIL_OutAO(0x8000, 0);
    }
    //@cmp.init.block.end
}


// Dll function pointers and dll reload function
#if defined(_WIN64)
// Define method for reloading dll functions
void ReloadDllFunctions_sys_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_sys_sp_cpu0_dev0(void) {
}

#else
// Define method for reloading dll functions
void ReloadDllFunctions_sys_sp_cpu0_dev0(void) {
    // Load each library and setup function pointers
}

void FreeDllFunctions_sys_sp_cpu0_dev0(void) {
}
#endif

void load_fmi_libraries_sys_sp_cpu0_dev0(void) {
#if defined(_WIN64)
#else
#endif
}


void ReInit_sp_scope_sys_sp_cpu0_dev0() {
    // initialise SP Scope buffer pointer
}


// generated using template: virtual_hil/common_timer_counter_handler.template-------------------------

/*****************************************************************************************/
/**
* This function is the handler which performs processing for the timer counter.
* It is called from an interrupt context such that the amount of processing
* performed should be minimized.  It is called when the timer counter expires
* if interrupts are enabled.
*
*
* @param    None
*
* @return   None
*
* @note     None
*
*****************************************************************************************/

void TimerCounterHandler_0_sys_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_0");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Ieut_meas.instantaneous
    {
        real tac_tmp1;
        tac_tmp1 = HIL_InFloat(0xc80041);
        _ieut_meas_instantaneous__out = tac_tmp1;
    }
    // Generated from the component: Ieut_meas.rms_calc_fast
    {
        _ieut_meas_rms_calc_fast__v_sq_sum_state = (_ieut_meas_rms_calc_fast__v_sq_sum_state + (_ieut_meas_instantaneous__out * _ieut_meas_instantaneous__out));
        if((1)) {
            _ieut_meas_rms_calc_fast__var_filt = ((_ieut_meas_rms_calc_fast__var_filt_state * _ieut_meas_rms_calc_fast__p_curr_f_coef_1) + (_ieut_meas_instantaneous__out * _ieut_meas_rms_calc_fast__p_curr_f_coef_2));
            _ieut_meas_rms_calc_fast__var_zc = (((_ieut_meas_rms_calc_fast__var_filt >= 0.0)) && ((_ieut_meas_rms_calc_fast__var_filt_state < 0.0)));
            if(((((_ieut_meas_rms_calc_fast__var_zc == 1)) || ((_ieut_meas_rms_calc_fast__n_period_timeout == _ieut_meas_rms_calc_fast__pc_cnt_1_state))))) {
                _ieut_meas_rms_calc_fast__var_eff_s_state = _ieut_meas_rms_calc_fast__v_sq_sum_state;
                _ieut_meas_rms_calc_fast__period_state = ((real) _ieut_meas_rms_calc_fast__pc_cnt_1_state);
                _ieut_meas_rms_calc_fast__v_sq_sum_state = 0.0;
            }
        }
        else {
            if((_ieut_meas_rms_calc_fast__n_period == _ieut_meas_rms_calc_fast__pc_cnt_1_state)) {
                _ieut_meas_rms_calc_fast__var_eff_s_state = _ieut_meas_rms_calc_fast__v_sq_sum_state;
                _ieut_meas_rms_calc_fast__period_state = ((real) _ieut_meas_rms_calc_fast__n_period);
                _ieut_meas_rms_calc_fast__v_sq_sum_state = 0.0;
            }
            _ieut_meas_rms_calc_fast__var_filt = 0.0;
        }
        _ieut_meas_rms_calc_fast__var_eff_s = _ieut_meas_rms_calc_fast__var_eff_s_state;
        _ieut_meas_rms_calc_fast__period = _ieut_meas_rms_calc_fast__period_state;
    }
    // Generated from the component: Ieut_meas.sys1
    {
    }
    // Generated from the component: Ieut_meas.rt1.Input
    {
        shared__ieut_meas_rt1_0 = _ieut_meas_rms_calc_fast__var_eff_s;
    }
    // Generated from the component: Ieut_meas.rt2.Input
    {
        shared__ieut_meas_rt2_0 = _ieut_meas_rms_calc_fast__period;
    }
    // Generated from the component: Ieut_meas.t1
    {
    }
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Ieut_meas.instantaneous
    // Generated from the component: Ieut_meas.rms_calc_fast
    {
        if((1)) {
            if(((((_ieut_meas_rms_calc_fast__var_zc == 1)) || ((_ieut_meas_rms_calc_fast__n_period_timeout == _ieut_meas_rms_calc_fast__pc_cnt_1_state))))) {
                _ieut_meas_rms_calc_fast__pc_cnt_1_state = 0;
            }
            _ieut_meas_rms_calc_fast__var_filt_state = _ieut_meas_rms_calc_fast__var_filt;
        }
        else {
            if(((_ieut_meas_rms_calc_fast__n_period == _ieut_meas_rms_calc_fast__pc_cnt_1_state))) {
                _ieut_meas_rms_calc_fast__pc_cnt_1_state = 0;
            }
        }
        _ieut_meas_rms_calc_fast__pc_cnt_1_state += 1;
    }
    // Generated from the component: Ieut_meas.sys1
    // Generated from the component: Ieut_meas.rt1.Input
    // Generated from the component: Ieut_meas.rt2.Input
    // Generated from the component: Ieut_meas.t1
    //@cmp.update.block.end
}
void TimerCounterHandler_1_sys_sp_cpu0_dev0() {
#if DEBUG_MODE
    printf("\n\rTimerCounterHandler_1");
#endif
    //////////////////////////////////////////////////////////////////////////
    // Output block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.out.block.start
    // Generated from the component: Ieut_meas.rt1.Output
    {
        _ieut_meas_rt1_output__out = shared__ieut_meas_rt1_0;
    }
    // Generated from the component: Ieut_meas.rt2.Output
    {
        _ieut_meas_rt2_output__out = shared__ieut_meas_rt2_0;
    }
    // Generated from the component: Ieut_meas.rms_calc_slow
    {
        if((_ieut_meas_rt2_output__out > 0.0)) {
            _ieut_meas_rms_calc_slow__var_rms = sqrt((_ieut_meas_rt1_output__out / _ieut_meas_rt2_output__out));
        }
        else {
            _ieut_meas_rms_calc_slow__var_rms = 0.0;
        }
    }
    // Generated from the component: Ieut_meas.cpu_trans.Input
    {
        XIo_OutFloat(0x2f400000, _ieut_meas_rms_calc_slow__var_rms);
    }
    // Generated from the component: Ieut_meas.rms
    {
        HIL_OutAO(0x8000, _ieut_meas_rms_calc_slow__var_rms);
    }
    // Generated from the component: Ieut_meas.sys2
    {
    }
//@cmp.out.block.end
    //////////////////////////////////////////////////////////////////////////
    // Update block
    //////////////////////////////////////////////////////////////////////////
    //@cmp.update.block.start
    // Generated from the component: Ieut_meas.rt1.Output
    // Generated from the component: Ieut_meas.rt2.Output
    // Generated from the component: Ieut_meas.rms_calc_slow
    // Generated from the component: Ieut_meas.cpu_trans.Input
    // Generated from the component: Ieut_meas.rms
    // Generated from the component: Ieut_meas.sys2
    //@cmp.update.block.end
}
// ----------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------