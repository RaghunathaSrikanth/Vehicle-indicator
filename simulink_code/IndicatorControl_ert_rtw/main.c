#include <stdio.h>
#include <windows.h> // for Sleep() on Windows
#include "IndicatorControl.h"

int main() {
    // Initialize model
    IndicatorControl_initialize();

    // Simulate 100 time steps
    for (int i = 0; i < 100; ++i) {
        // Simulate button press
        if (i >= 10 && i < 30) {
            IndicatorControl_U.btnL = 1.0;  // Left button pressed for 20 steps
        } else {
            IndicatorControl_U.btnL = 0.0;
        }

        if (i >= 40 && i < 70) {
            IndicatorControl_U.btnR = 1.0;  // Right button pressed for 30 steps
        } else {
            IndicatorControl_U.btnR = 0.0;
        }

        // Step model logic
        IndicatorControl_step();

        // Output LED status
        printf("Step %d: ledL = %.0f, ledR = %.0f\n",
               i, IndicatorControl_Y.ledL, IndicatorControl_Y.ledR);

        Sleep(100); // Wait for 100 ms
    }

    // Terminate model (not needed but for completion)
    IndicatorControl_terminate();

    return 0;
}
