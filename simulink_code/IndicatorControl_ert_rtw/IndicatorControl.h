/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IndicatorControl.h
 *
 * Code generated for Simulink model 'IndicatorControl'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 25.1 (R2025a) 21-Nov-2024
 * C/C++ source code generated on : Sun Jul 20 22:49:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef IndicatorControl_h_
#define IndicatorControl_h_
#ifndef IndicatorControl_COMMON_INCLUDES_
#define IndicatorControl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* IndicatorControl_COMMON_INCLUDES_ */

#include "IndicatorControl_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T countL;                       /* '<Root>/IndicatorLogic' */
  real_T countR;                       /* '<Root>/IndicatorLogic' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_IndicatorControl_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T btnL;                         /* '<Root>/btnL' */
  real_T btnR;                         /* '<Root>/btnR' */
} ExtU_IndicatorControl_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T ledL;                         /* '<Root>/ledL' */
  real_T ledR;                         /* '<Root>/ledR' */
} ExtY_IndicatorControl_T;

/* Real-time Model Data Structure */
struct tag_RTM_IndicatorControl_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_IndicatorControl_T IndicatorControl_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_IndicatorControl_T IndicatorControl_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_IndicatorControl_T IndicatorControl_Y;

/* Model entry point functions */
extern void IndicatorControl_initialize(void);
extern void IndicatorControl_step(void);
extern void IndicatorControl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IndicatorControl_T *const IndicatorControl_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'IndicatorControl'
 * '<S1>'   : 'IndicatorControl/IndicatorLogic'
 */
#endif                                 /* IndicatorControl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
