#pragma once
#include <stdbool.h>

enum v5_ControllerId {
	v5_ControllerId_Primary = 0,
	v5_ControllerId_Secondary,
};

enum v5_ControllerButton {
	v5_ControllerButton_L1 = 6,
	v5_ControllerButton_L2,
	v5_ControllerButton_R1,
	v5_ControllerButton_R2,
	v5_ControllerButton_Up,
	v5_ControllerButton_Down,
	v5_ControllerButton_Left,
	v5_ControllerButton_Right,
	v5_ControllerButton_X,
	v5_ControllerButton_B,
	v5_ControllerButton_Y,
	v5_ControllerButton_A,
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

void v5_display_print_slice(int line, char const* base, unsigned int size);

int v5_system_version(void);

int v5_stdlib_version(void);
