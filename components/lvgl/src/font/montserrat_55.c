/*******************************************************************************
 * Size: 55 px
 * Bpp: 2
 * Opts: --bpp 2 --size 55 --no-compress --font Montserrat-Regular.ttf --range 44-57 --format lvgl -o montserrat_55.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#include <stdio.h>
#endif

#ifndef MONTSERRAT_55
#define MONTSERRAT_55 1
#endif

#if MONTSERRAT_55

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+002C "," */
    0xb, 0xd0, 0xbf, 0xd3, 0xff, 0x8f, 0xfe, 0x2f,
    0xf8, 0x2f, 0xd0, 0x3f, 0x1, 0xf8, 0xb, 0xd0,
    0x3f, 0x0, 0xfc, 0x7, 0xd0, 0x2f, 0x0, 0xfc,
    0x0,

    /* U+002D "-" */
    0x55, 0x55, 0x55, 0x56, 0xff, 0xff, 0xff, 0xeb,
    0xff, 0xff, 0xff, 0xaf, 0xff, 0xff, 0xfe,

    /* U+002E "." */
    0xb, 0xd0, 0xbf, 0xd3, 0xff, 0x8f, 0xfe, 0x2f,
    0xf4, 0x2f, 0x40,

    /* U+002F "/" */
    0x0, 0x0, 0x0, 0x0, 0x2, 0xa0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x7, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xc0, 0x0, 0x0, 0x0,
    0x0, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x7, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0xb, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0x80, 0x0, 0x0, 0x0, 0x0, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0xb, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0x80, 0x0, 0x0, 0x0, 0x1, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0xb, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x1, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xb, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x1,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0xb, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0x40, 0x0, 0x0, 0x0,
    0x1, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0, 0x0,
    0x0, 0x2, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x40, 0x0,
    0x0, 0x0, 0x2, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0x40,
    0x0, 0x0, 0x0, 0x2, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0x40, 0x0, 0x0, 0x0, 0x2, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xd0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0xf, 0xd0, 0x0,
    0x0, 0x0, 0x0,

    /* U+0030 "0" */
    0x0, 0x0, 0x1, 0xbf, 0xfe, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x7, 0xff, 0xfa, 0xaf, 0xff, 0xe0, 0x0,
    0x0, 0x1f, 0xfe, 0x40, 0x0, 0x7f, 0xf8, 0x0,
    0x0, 0x3f, 0xf4, 0x0, 0x0, 0xb, 0xfe, 0x0,
    0x0, 0xff, 0xc0, 0x0, 0x0, 0x2, 0xff, 0x40,
    0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xc0,
    0x3, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xd0,
    0x7, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf0,
    0xf, 0xf4, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf4,
    0xf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xf8,
    0x1f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xfc,
    0x2f, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfc,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfd,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfd,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xfe,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xfe,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfd,
    0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfd,
    0x2f, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xfc,
    0x1f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xfc,
    0xf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xf8,
    0xf, 0xf4, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf4,
    0x7, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf0,
    0x3, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xd0,
    0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xc0,
    0x0, 0xff, 0xc0, 0x0, 0x0, 0x2, 0xff, 0x40,
    0x0, 0x3f, 0xf4, 0x0, 0x0, 0xb, 0xfe, 0x0,
    0x0, 0x1f, 0xfe, 0x40, 0x0, 0x7f, 0xf8, 0x0,
    0x0, 0x7, 0xff, 0xfa, 0xaf, 0xff, 0xe0, 0x0,
    0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x1f, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xbf, 0xfe, 0x40, 0x0, 0x0,

    /* U+0031 "1" */
    0xbf, 0xff, 0xff, 0xeb, 0xff, 0xff, 0xfe, 0xbf,
    0xff, 0xff, 0xe6, 0xaa, 0xaa, 0xfe, 0x0, 0x0,
    0x1f, 0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0, 0x1f,
    0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0, 0x1f, 0xe0,
    0x0, 0x1, 0xfe, 0x0, 0x0, 0x1f, 0xe0, 0x0,
    0x1, 0xfe, 0x0, 0x0, 0x1f, 0xe0, 0x0, 0x1,
    0xfe, 0x0, 0x0, 0x1f, 0xe0, 0x0, 0x1, 0xfe,
    0x0, 0x0, 0x1f, 0xe0, 0x0, 0x1, 0xfe, 0x0,
    0x0, 0x1f, 0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0,
    0x1f, 0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0, 0x1f,
    0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0, 0x1f, 0xe0,
    0x0, 0x1, 0xfe, 0x0, 0x0, 0x1f, 0xe0, 0x0,
    0x1, 0xfe, 0x0, 0x0, 0x1f, 0xe0, 0x0, 0x1,
    0xfe, 0x0, 0x0, 0x1f, 0xe0, 0x0, 0x1, 0xfe,
    0x0, 0x0, 0x1f, 0xe0, 0x0, 0x1, 0xfe, 0x0,
    0x0, 0x1f, 0xe0, 0x0, 0x1, 0xfe, 0x0, 0x0,
    0x1f, 0xe0, 0x0, 0x1, 0xfe,

    /* U+0032 "2" */
    0x0, 0x0, 0x1b, 0xff, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x3f,
    0xff, 0xfa, 0xaf, 0xff, 0xfc, 0x0, 0xf, 0xff,
    0x80, 0x0, 0x2, 0xff, 0xe0, 0x2, 0xff, 0x80,
    0x0, 0x0, 0x3, 0xff, 0x40, 0xb, 0xc0, 0x0,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x20, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7f, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xb, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xd0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xf4, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x80, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+0033 "3" */
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1a, 0xaa,
    0xaa, 0xaa, 0xaa, 0xff, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xd0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf4, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xb, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0x40, 0x0, 0x0, 0x0, 0x3f, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xf4,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7f, 0xc0, 0xc0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0xe0, 0xbd, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf4,
    0x3f, 0xf4, 0x0, 0x0, 0x0, 0x2f, 0xf8, 0xf,
    0xff, 0xe0, 0x0, 0x0, 0x7f, 0xfc, 0x0, 0xbf,
    0xff, 0xfa, 0xab, 0xff, 0xfc, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x1b, 0xff,
    0xff, 0xff, 0xf4, 0x0, 0x0, 0x0, 0x1a, 0xff,
    0xfe, 0x40, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xb, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x0, 0x0, 0x55, 0x0, 0x0,
    0x0, 0x3, 0xfe, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0xbf, 0xc0, 0x0, 0x0, 0xff, 0x0,
    0x0, 0x0, 0x1f, 0xf0, 0x0, 0x0, 0xf, 0xf0,
    0x0, 0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0xff,
    0x0, 0x0, 0x0, 0xff, 0x80, 0x0, 0x0, 0xf,
    0xf0, 0x0, 0x0, 0x3f, 0xe0, 0x0, 0x0, 0x0,
    0xff, 0x0, 0x0, 0xb, 0xfc, 0x0, 0x0, 0x0,
    0xf, 0xf0, 0x0, 0x1, 0xff, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x0, 0x0, 0x7f, 0xea, 0xaa, 0xaa,
    0xaa, 0xaf, 0xfa, 0xaa, 0x9f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xff, 0x0, 0x0,

    /* U+0035 "5" */
    0x0, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x7f, 0xaa,
    0xaa, 0xaa, 0xaa, 0x90, 0x0, 0xbf, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xbf, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xfd, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xfc, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xff, 0xff, 0xa4, 0x0, 0x0,
    0x3, 0xff, 0xff, 0xff, 0xff, 0xd0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x2, 0xaa,
    0xaa, 0xab, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0xfe, 0x8, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfd, 0x3f, 0x0, 0x0, 0x0, 0x0, 0xf, 0xfc,
    0x7f, 0xe0, 0x0, 0x0, 0x0, 0x3f, 0xf4, 0x7f,
    0xfe, 0x40, 0x0, 0x2, 0xff, 0xe0, 0xf, 0xff,
    0xff, 0xaa, 0xff, 0xff, 0x80, 0x1, 0xff, 0xff,
    0xff, 0xff, 0xfd, 0x0, 0x0, 0x1f, 0xff, 0xff,
    0xff, 0xe0, 0x0, 0x0, 0x0, 0x6b, 0xff, 0xf9,
    0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0x0, 0x1b, 0xff, 0xf9, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xff, 0xff, 0xff, 0x40, 0x0,
    0x0, 0x7f, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x0,
    0x2f, 0xff, 0xe9, 0x5a, 0xff, 0xc0, 0x0, 0xf,
    0xff, 0x80, 0x0, 0x0, 0x74, 0x0, 0x3, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xd0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x3, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xb, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xe0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0xc0, 0x0, 0x1, 0x54, 0x0, 0x0,
    0x3, 0xfc, 0x0, 0x1f, 0xff, 0xfe, 0x40, 0x0,
    0x3f, 0xc0, 0x2f, 0xff, 0xff, 0xff, 0x40, 0x3,
    0xfc, 0xf, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x3f,
    0xc3, 0xff, 0x90, 0x1, 0xbf, 0xfc, 0x3, 0xfc,
    0xff, 0x40, 0x0, 0x0, 0xbf, 0xe0, 0x3f, 0xef,
    0xc0, 0x0, 0x0, 0x1, 0xff, 0x43, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0xb, 0xfc, 0x3f, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xd3, 0xff, 0xc0, 0x0,
    0x0, 0x0, 0x2, 0xfe, 0x2f, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x1f, 0xe2, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0xff, 0x1f, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf0, 0xff, 0x40, 0x0, 0x0, 0x0,
    0x0, 0xfe, 0xb, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xe0, 0x7f, 0xc0, 0x0, 0x0, 0x0, 0x2,
    0xfd, 0x3, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xc0, 0xf, 0xf4, 0x0, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0xbf, 0xd0, 0x0, 0x0, 0x3, 0xff, 0x0,
    0x2, 0xff, 0x90, 0x0, 0x1, 0xff, 0xd0, 0x0,
    0xb, 0xff, 0xe5, 0x56, 0xff, 0xf4, 0x0, 0x0,
    0x1f, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0x0,
    0x2f, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x1b, 0xff, 0xf9, 0x0, 0x0,

    /* U+0037 "7" */
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x3f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xfe,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaf, 0xf8, 0x3f, 0x80,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x3, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xf0, 0x3f, 0x80, 0x0,
    0x0, 0x0, 0x3, 0xfd, 0x3, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xc0, 0x3f, 0x80, 0x0, 0x0,
    0x0, 0xf, 0xf4, 0x3, 0xf8, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x0, 0x2a, 0x40, 0x0, 0x0, 0x0,
    0x3f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xc0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xb, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf,
    0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3f, 0xd0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xfc, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xf0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7f, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x0, 0x6, 0xff, 0xfe, 0x40, 0x0, 0x0,
    0x0, 0x7, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x1, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x0, 0x0,
    0x1f, 0xff, 0xe5, 0x56, 0xff, 0xfe, 0x0, 0x1,
    0xff, 0xd0, 0x0, 0x0, 0x2f, 0xfd, 0x0, 0xf,
    0xfc, 0x0, 0x0, 0x0, 0xf, 0xfc, 0x0, 0x7f,
    0xc0, 0x0, 0x0, 0x0, 0xf, 0xf8, 0x3, 0xfd,
    0x0, 0x0, 0x0, 0x0, 0x1f, 0xf0, 0xf, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x3f, 0xc0, 0x3f, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x0, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xfc, 0x2, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xf0, 0x7, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xff, 0x80, 0xf, 0xf8, 0x0,
    0x0, 0x0, 0xb, 0xfc, 0x0, 0x1f, 0xfc, 0x0,
    0x0, 0x0, 0xff, 0xd0, 0x0, 0x1f, 0xff, 0x90,
    0x1, 0xbf, 0xfd, 0x0, 0x0, 0xb, 0xff, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x0, 0xb, 0xff, 0xff,
    0xff, 0xf8, 0x0, 0x0, 0x2, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x0, 0x0, 0x3f, 0xfe, 0x40, 0x0,
    0x6f, 0xff, 0x0, 0x3, 0xff, 0x40, 0x0, 0x0,
    0x7, 0xff, 0x0, 0x3f, 0xf0, 0x0, 0x0, 0x0,
    0x3, 0xff, 0x1, 0xff, 0x0, 0x0, 0x0, 0x0,
    0x3, 0xfd, 0xf, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xfc, 0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xf1, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xd7, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbf, 0x5f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xfd, 0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xf4, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xc3, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0x7, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf4,
    0xf, 0xfd, 0x0, 0x0, 0x0, 0x1, 0xff, 0xc0,
    0xf, 0xff, 0x40, 0x0, 0x0, 0x7f, 0xfc, 0x0,
    0xf, 0xff, 0xe9, 0x55, 0xbf, 0xff, 0xc0, 0x0,
    0xb, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x2, 0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x6b, 0xff, 0xfa, 0x40, 0x0, 0x0,

    /* U+0039 "9" */
    0x0, 0x0, 0x1b, 0xff, 0xe4, 0x0, 0x0, 0x0,
    0x0, 0x7f, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0x2f, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0, 0xf,
    0xff, 0xe5, 0x5a, 0xff, 0xf0, 0x0, 0x3, 0xff,
    0x80, 0x0, 0x1, 0xff, 0xc0, 0x0, 0xbf, 0xd0,
    0x0, 0x0, 0x2, 0xff, 0x0, 0x1f, 0xf4, 0x0,
    0x0, 0x0, 0xb, 0xf8, 0x2, 0xfe, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xd0, 0x3f, 0xc0, 0x0, 0x0,
    0x0, 0x1, 0xff, 0x3, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf0, 0x7f, 0x80, 0x0, 0x0, 0x0,
    0x0, 0xff, 0x87, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xfc, 0x3f, 0x80, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xc3, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xfc, 0x3f, 0xd0, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xd2, 0xff, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xfd,
    0xf, 0xfc, 0x0, 0x0, 0x0, 0x1f, 0xef, 0xe0,
    0x7f, 0xf4, 0x0, 0x0, 0xb, 0xf9, 0xfe, 0x2,
    0xff, 0xf4, 0x0, 0x1b, 0xfe, 0x1f, 0xe0, 0x7,
    0xff, 0xff, 0xff, 0xff, 0x81, 0xfe, 0x0, 0xb,
    0xff, 0xff, 0xff, 0xd0, 0x1f, 0xe0, 0x0, 0xb,
    0xff, 0xff, 0x90, 0x1, 0xfe, 0x0, 0x0, 0x0,
    0x54, 0x0, 0x0, 0x2f, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x3f, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xbf, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3f,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xd0, 0x0,
    0xe, 0x40, 0x0, 0x1, 0xff, 0xf4, 0x0, 0x1,
    0xff, 0xe9, 0x6b, 0xff, 0xfd, 0x0, 0x0, 0x3f,
    0xff, 0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0xbf,
    0xff, 0xff, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x6b,
    0xff, 0xe9, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 187, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = -8},
    {.bitmap_index = 25, .adv_w = 336, .box_w = 15, .box_h = 4, .ofs_x = 3, .ofs_y = 13},
    {.bitmap_index = 40, .adv_w = 187, .box_w = 7, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 295, .box_w = 23, .box_h = 52, .ofs_x = -2, .ofs_y = -5},
    {.bitmap_index = 350, .adv_w = 583, .box_w = 32, .box_h = 38, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 318, .box_w = 14, .box_h = 38, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 787, .adv_w = 500, .box_w = 30, .box_h = 38, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1072, .adv_w = 496, .box_w = 29, .box_h = 38, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1348, .adv_w = 582, .box_w = 34, .box_h = 38, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1671, .adv_w = 498, .box_w = 28, .box_h = 38, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1937, .adv_w = 536, .box_w = 30, .box_h = 38, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2222, .adv_w = 518, .box_w = 30, .box_h = 38, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 2507, .adv_w = 561, .box_w = 31, .box_h = 38, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2802, .adv_w = 536, .box_w = 30, .box_h = 38, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 44, .range_length = 14, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

//extern const lv_font_t montserrat_55;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t montserrat_55 = {
#else
lv_font_t montserrat_55 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 55,          /*The maximum line height required by the font*/
    .base_line = 8,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 3,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if MONTSERRAT_55*/
