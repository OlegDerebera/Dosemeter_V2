/*******************************************************************************
 * Size: 20 px
 * Bpp: 4
 * Opts: --bpp 4 --size 20 --no-compress --font Roboto-Regular.ttf --range 945-947 --format lvgl -o greek.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef GREEK
#define GREEK 1
#endif

#if GREEK

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+03B1 "α" */
    0x0, 0x1a, 0xef, 0xb2, 0xcd, 0x0, 0x0, 0xcf,
    0xc8, 0xbe, 0xed, 0x0, 0x6, 0xf9, 0x0, 0x8,
    0xfd, 0x0, 0xc, 0xf1, 0x0, 0x0, 0xfd, 0x0,
    0xf, 0xd0, 0x0, 0x0, 0xfd, 0x0, 0xf, 0xc0,
    0x0, 0x0, 0xfd, 0x0, 0xf, 0xd0, 0x0, 0x0,
    0xfd, 0x0, 0xd, 0xf1, 0x0, 0x0, 0xfd, 0x0,
    0x8, 0xfa, 0x0, 0x9, 0xfe, 0x0, 0x1, 0xef,
    0xeb, 0xde, 0xdf, 0xb0, 0x0, 0x1a, 0xff, 0xb2,
    0x4e, 0xe1,

    /* U+03B2 "β" */
    0x0, 0x3b, 0xff, 0xb3, 0x0, 0x6, 0xfe, 0x9a,
    0xff, 0x30, 0x1f, 0xe1, 0x0, 0x4f, 0xc0, 0x5f,
    0x70, 0x0, 0xd, 0xf0, 0x6f, 0x60, 0x0, 0xc,
    0xf0, 0x7f, 0x60, 0x0, 0x2f, 0xc0, 0x7f, 0x60,
    0x8a, 0xfe, 0x20, 0x7f, 0x60, 0xff, 0xfc, 0x20,
    0x7f, 0x60, 0x0, 0x4e, 0xe1, 0x7f, 0x60, 0x0,
    0x5, 0xf8, 0x7f, 0x60, 0x0, 0x1, 0xfb, 0x7f,
    0x60, 0x0, 0x3, 0xfa, 0x7f, 0x90, 0x0, 0xa,
    0xf6, 0x7f, 0xfd, 0x99, 0xdf, 0xc0, 0x7f, 0x8a,
    0xef, 0xd8, 0x0, 0x7f, 0x60, 0x0, 0x0, 0x0,
    0x7f, 0x60, 0x0, 0x0, 0x0, 0x7f, 0x60, 0x0,
    0x0, 0x0, 0x7f, 0x60, 0x0, 0x0, 0x0,

    /* U+03B3 "γ" */
    0x5f, 0x70, 0x0, 0x5, 0xf7, 0xf, 0xd0, 0x0,
    0xa, 0xf2, 0xa, 0xf2, 0x0, 0xf, 0xc0, 0x4,
    0xf8, 0x0, 0x5f, 0x60, 0x0, 0xed, 0x0, 0xbf,
    0x10, 0x0, 0x8f, 0x31, 0xfb, 0x0, 0x0, 0x2f,
    0x86, 0xf5, 0x0, 0x0, 0xd, 0xeb, 0xf0, 0x0,
    0x0, 0x7, 0xff, 0x90, 0x0, 0x0, 0x1, 0xff,
    0x40, 0x0, 0x0, 0x0, 0xdf, 0x0, 0x0, 0x0,
    0x0, 0xdf, 0x0, 0x0, 0x0, 0x0, 0xdf, 0x0,
    0x0, 0x0, 0x0, 0xdf, 0x0, 0x0, 0x0, 0x0,
    0xdf, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 181, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 66, .adv_w = 190, .box_w = 10, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 161, .adv_w = 160, .box_w = 10, .box_h = 15, .ofs_x = 0, .ofs_y = -4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 945, .range_length = 3, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 1
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -2
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 1,
    .glyph_ids_size = 0
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
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t greek = {
#else
lv_font_t greek = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if GREEK*/

