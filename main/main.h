/*
 * main.h
 *
 *  Created on: 30 трав. 2024 р.
 *      Author: dereb
 */
#include <stdio.h>
#include "esp_log.h"
#ifndef MAIN_MAIN_H_
#define MAIN_MAIN_H_

#define EXAMPLE_LCD_PIXEL_CLOCK_HZ (10 * 1000 * 1000)

#define EXAMPLE_LCD_BK_LIGHT_ON_LEVEL 1
#define EXAMPLE_LCD_BK_LIGHT_OFF_LEVEL !EXAMPLE_LCD_BK_LIGHT_ON_LEVEL
#define EXAMPLE_PIN_NUM_DATA0 39    // 6
#define EXAMPLE_PIN_NUM_DATA1 40    // 7
#define EXAMPLE_PIN_NUM_DATA2 41    // 8
#define EXAMPLE_PIN_NUM_DATA3 42    // 9
#define EXAMPLE_PIN_NUM_DATA4 45    // 10
#define EXAMPLE_PIN_NUM_DATA5 46    // 11
#define EXAMPLE_PIN_NUM_DATA6 47    // 12
#define EXAMPLE_PIN_NUM_DATA7 48    // 13
#define EXAMPLE_PIN_NUM_PCLK 8      // 5
#define EXAMPLE_PIN_NUM_CS 6        // 3
#define EXAMPLE_PIN_NUM_DC 7        // 4
#define EXAMPLE_PIN_NUM_RST 5       // 2
#define EXAMPLE_PIN_NUM_BK_LIGHT 38 // 1
#define EXAMPLE_PIN_NUM_POWER 15
#define PIN_LCD_RD 9

#define ST7789_NOP      0x00
#define ST7789_SWRESET  0x01
#define ST7789_RDDID    0x04
#define ST7789_RDDST    0x09

#define ST7789_RDDPM        0x0A    // Read display power mode
#define ST7789_RDD_MADCTL   0x0B    // Read display MADCTL
#define ST7789_RDD_COLMOD   0x0C    // Read display pixel format
#define ST7789_RDDIM        0x0D    // Read display image mode
#define ST7789_RDDSM        0x0E    // Read display signal mode
#define ST7789_RDDSR        0x0F    // Read display self-diagnostic result (ST7789V)

#define ST7789_SLPIN        0x10
#define ST7789_SLPOUT       0x11
#define ST7789_PTLON        0x12
#define ST7789_NORON        0x13

#define ST7789_INVOFF       0x20
#define ST7789_INVON        0x21
#define ST7789_GAMSET       0x26    // Gamma set
#define ST7789_DISPOFF      0x28
#define ST7789_DISPON       0x29
#define ST7789_CASET        0x2A
#define ST7789_RASET        0x2B
#define ST7789_RAMWR        0x2C
#define ST7789_RGBSET       0x2D    // Color setting for 4096, 64K and 262K colors
#define ST7789_RAMRD        0x2E

#define ST7789_PTLAR        0x30
#define ST7789_VSCRDEF      0x33    // Vertical scrolling definition (ST7789V)
#define ST7789_TEOFF        0x34    // Tearing effect line off
#define ST7789_TEON         0x35    // Tearing effect line on
#define ST7789_MADCTL       0x36    // Memory data access control
#define ST7789_IDMOFF       0x38    // Idle mode off
#define ST7789_IDMON        0x39    // Idle mode on
#define ST7789_RAMWRC       0x3C    // Memory write continue (ST7789V)
#define ST7789_RAMRDC       0x3E    // Memory read continue (ST7789V)
#define ST7789_COLMOD       0x3A

#define ST7789_RAMCTRL      0xB0    // RAM control
#define ST7789_RGBCTRL      0xB1    // RGB control
#define ST7789_PORCTRL      0xB2    // Porch control
#define ST7789_FRCTRL1      0xB3    // Frame rate control
#define ST7789_PARCTRL      0xB5    // Partial mode control
#define ST7789_GCTRL        0xB7    // Gate control
#define ST7789_GTADJ        0xB8    // Gate on timing adjustment
#define ST7789_DGMEN        0xBA    // Digital gamma enable
#define ST7789_VCOMS        0xBB    // VCOMS setting
#define ST7789_LCMCTRL      0xC0    // LCM control
#define ST7789_IDSET        0xC1    // ID setting
#define ST7789_VDVVRHEN     0xC2    // VDV and VRH command enable
#define ST7789_VRHS         0xC3    // VRH set
#define ST7789_VDVSET       0xC4    // VDV setting
#define ST7789_VCMOFSET     0xC5    // VCOMS offset set
#define ST7789_FRCTR2       0xC6    // FR Control 2
#define ST7789_CABCCTRL     0xC7    // CABC control
#define ST7789_REGSEL1      0xC8    // Register value section 1
#define ST7789_REGSEL2      0xCA    // Register value section 2
#define ST7789_PWMFRSEL     0xCC    // PWM frequency selection
#define ST7789_PWCTRL1      0xD0    // Power control 1
#define ST7789_VAPVANEN     0xD2    // Enable VAP/VAN signal output
#define ST7789_CMD2EN       0xDF    // Command 2 enable
#define ST7789_PVGAMCTRL    0xE0    // Positive voltage gamma control
#define ST7789_NVGAMCTRL    0xE1    // Negative voltage gamma control
#define ST7789_DGMLUTR      0xE2    // Digital gamma look-up table for red
#define ST7789_DGMLUTB      0xE3    // Digital gamma look-up table for blue
#define ST7789_GATECTRL     0xE4    // Gate control
#define ST7789_SPI2EN       0xE7    // SPI2 enable
#define ST7789_PWCTRL2      0xE8    // Power control 2
#define ST7789_EQCTRL       0xE9    // Equalize time control
#define ST7789_PROMCTRL     0xEC    // Program control
#define ST7789_PROMEN       0xFA    // Program mode enable
#define ST7789_NVMSET       0xFC    // NVM setting
#define ST7789_PROMACT      0xFE    // Program action


// The pixel number in horizontal and vertical
#define EXAMPLE_LCD_H_RES 320
#define EXAMPLE_LCD_V_RES 170
#define LVGL_LCD_BUF_SIZE            (EXAMPLE_LCD_H_RES * EXAMPLE_LCD_V_RES)
// Bit number used to represent command and parameter
#define EXAMPLE_LCD_CMD_BITS 8
#define EXAMPLE_LCD_PARAM_BITS 8

#define DEBOUNCE_TIME_MS 			50
#define LONG_PRESS_THRESHOLD 		1000   // milliseconds
#define SLOW_INCREMENT_INTERVAL 	250 // milliseconds
#define FAST_INCREMENT_INTERVAL 	100 // milliseconds

#define SENSOR_PIN					GPIO_NUM_18
#define BUZZER_PIN					GPIO_NUM_12	//12
#define GPIO_UP						0	//10
#define GPIO_DOWN					3
#define GPIO_ENTER					14

#define EDIT_NONE					0
#define EDIT_UNIT					1
#define EDIT_THEME					2
#define EDIT_LANG					3
#define EDIT_TAB					4

static void nvs_load(void);
static void options_redraw(void);
static void timer_init(void);
void lvgl_setup();
void ble_app_advertise(void);
void connect_ble(void);

typedef struct {
	uint8_t alpha;
	uint8_t beta;
	uint8_t gamma;
	uint8_t neutron;
	uint8_t alpha_ready;
	uint8_t beta_ready;
	uint8_t gamma_ready;
	uint8_t neutron_ready;
	uint8_t chart;
	uint8_t chart_ready;
	uint8_t speedo;
}widget_options;

#endif /* MAIN_MAIN_H_ */
