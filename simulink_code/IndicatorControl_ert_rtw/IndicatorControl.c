/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: IndicatorControl.c
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

#include "IndicatorControl.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_IndicatorControl_T IndicatorControl_DW;

/* External inputs (root inport signals with default storage) */
ExtU_IndicatorControl_T IndicatorControl_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_IndicatorControl_T IndicatorControl_Y;

/* Real-time model */
static RT_MODEL_IndicatorControl_T IndicatorControl_M_;
RT_MODEL_IndicatorControl_T *const IndicatorControl_M = &IndicatorControl_M_;

/* Model step function */
void IndicatorControl_step(void)
{
  int32_T rtb_PulseGenerator;
  boolean_T pressedL;
  boolean_T pressedR;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = ((IndicatorControl_DW.clockTickCounter < 3) &&
                        (IndicatorControl_DW.clockTickCounter >= 0));
  if (IndicatorControl_DW.clockTickCounter >= 5) {
    IndicatorControl_DW.clockTickCounter = 0;
  } else {
    IndicatorControl_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Outport: '<Root>/ledL' incorporates:
   *  MATLAB Function: '<Root>/IndicatorLogic'
   */
  IndicatorControl_Y.ledL = 0.0;

  /* Outport: '<Root>/ledR' incorporates:
   *  MATLAB Function: '<Root>/IndicatorLogic'
   */
  IndicatorControl_Y.ledR = 0.0;

  /* MATLAB Function: '<Root>/IndicatorLogic' incorporates:
   *  Inport: '<Root>/btnL'
   *  Inport: '<Root>/btnR'
   */
  if (IndicatorControl_U.btnL != 0.0) {
    IndicatorControl_DW.countL++;
  } else {
    IndicatorControl_DW.countL = 0.0;
  }

  if (IndicatorControl_U.btnR != 0.0) {
    IndicatorControl_DW.countR++;
  } else {
    IndicatorControl_DW.countR = 0.0;
  }

  pressedL = (IndicatorControl_DW.countL >= 10.0);
  pressedR = (IndicatorControl_DW.countR >= 10.0);
  if (pressedL && pressedR) {
    /* Outport: '<Root>/ledL' */
    IndicatorControl_Y.ledL = rtb_PulseGenerator;

    /* Outport: '<Root>/ledR' incorporates:
     *  Outport: '<Root>/ledL'
     */
    IndicatorControl_Y.ledR = rtb_PulseGenerator;
  } else if (pressedL) {
    /* Outport: '<Root>/ledL' */
    IndicatorControl_Y.ledL = rtb_PulseGenerator;
  } else if (pressedR) {
    /* Outport: '<Root>/ledR' */
    IndicatorControl_Y.ledR = rtb_PulseGenerator;
  }
}

/* Model initialize function */
void IndicatorControl_initialize(void)
{
  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  IndicatorControl_DW.clockTickCounter = -1;
}

/* Model terminate function */
void IndicatorControl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
