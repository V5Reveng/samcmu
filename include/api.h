#pragma once
#include <stdbool.h>

enum v5_ControllerId {
	ControllerId_Primary = 0,
	ControllerId_Secondary,
};

enum v5_ControllerButton {
	ControllerButton_L1 = 6,
	ControllerButton_L2,
	ControllerButton_R1,
	ControllerButton_R2,
	ControllerButton_Up,
	ControllerButton_Down,
	ControllerButton_Left,
	ControllerButton_Right,
	ControllerButton_X,
	ControllerButton_B,
	ControllerButton_Y,
	ControllerButton_A,
};

#define V5_SCREEN_HEADER_HEIGHT 32

void v5_exit(void) __attribute__((noreturn));

int v5_controller_get(enum v5_ControllerId id, enum v5_ControllerButton button);

int v5_controller_connection_status(enum v5_ControllerId id);

int v5_get_system_millis(void);

void v5_display_rect_clear(int x0, int y0, int x1, int y1);

void v5_display_rect_fill(int x0, int y0, int x1, int y1);

void v5_display_erase(void);

void v5_display_printf(int line, char const* fmt, ...) __attribute__((format(printf, 2, 3)));

void v5_display_print_rust_str(int line, char const* base, unsigned int size);
