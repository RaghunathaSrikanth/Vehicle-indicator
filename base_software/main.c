#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h> // for usleep on UNIX systems. On Windows use Sleep(milliseconds)

// Global states
bool left_button = false;
bool right_button = false;
bool left_led = false;
bool right_led = false;
bool hazard_mode = false;

void uart_log(const char* msg) {
    FILE* log = fopen("../uart_logs/log.txt", "a");  // Relative path to uart_logs
    if (log != NULL) {
        fprintf(log, "[UART]: %s\n", msg);
        fclose(log);
    }
}

void toggle_leds() {
    if (hazard_mode) {
        left_led = !left_led;
        right_led = left_led;
        uart_log("Hazard toggling both LEDs");
    }

    printf("\nLeft LED: %s | Right LED: %s\n", left_led ? "ON" : "OFF", right_led ? "ON" : "OFF");
}

void simulate_button_input() {
    char input;
    printf("\nPress button [l = left, r = right, b = both, q = quit]: ");
    scanf(" %c", &input);

    if (input == 'l') {
        left_button = true;
        right_button = false;
    } else if (input == 'r') {
        right_button = true;
        left_button = false;
    } else if (input == 'b') {
        left_button = true;
        right_button = true;
    } else if (input == 'q') {
        exit(0);
    } else {
        left_button = right_button = false;
    }
}

void process_logic() {
    if (left_button && right_button) {
        hazard_mode = true;
        uart_log("Hazard mode activated");
    } else if (left_button) {
        if (hazard_mode) uart_log("Hazard mode deactivated by Left Button");
        hazard_mode = false;
        right_led = false;
        left_led = !left_led;
        uart_log("Left indicator toggled");
    } else if (right_button) {
        if (hazard_mode) uart_log("Hazard mode deactivated by Right Button");
        hazard_mode = false;
        left_led = false;
        right_led = !right_led;
        uart_log("Right indicator toggled");
    }

    left_button = right_button = false;
}

int main() {
    uart_log("System started");

    while (1) {
        simulate_button_input();
        process_logic();
        toggle_leds();

        // Simulate 300ms toggle delay
        #ifdef _WIN32
            sleep(300);  // Windows
        #else
            usleep(300000);  // Linux/Mac
        #endif
    }

    return 0;
}
