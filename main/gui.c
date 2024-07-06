/*
 * gui.c
 *
 *  Created on: 29 трав. 2024 р.
 *      Author:
 */
#include "lvgl.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "main.h"

extern void table_event_cb(lv_event_t* e);
extern void table_widget_event_cb(lv_event_t* e);
extern void draw_event_cb(lv_event_t * e);
extern void table_settings_event_cb(lv_event_t* e);
extern void table_coef_event_cb(lv_event_t* e);
extern void tabview_cb(lv_event_t * e);

extern const char *TAG;

extern lv_group_t * g_menu;
extern lv_group_t* g_empty;
extern lv_group_t *g_widgets;
extern lv_group_t* g_settings;
extern lv_group_t* g_coef;
extern lv_group_t* g_tab;
extern lv_group_t* g_tab_btn;
extern lv_obj_t * scr1;
lv_obj_t * obj2;
static lv_style_t style2;
static lv_style_t style_bg;
static lv_style_t style_greek;
static lv_style_t style_unit;
extern char str_adc[10];
extern lv_obj_t * label_adc;
lv_obj_t * label_greek_alpha;
lv_obj_t * label_greek_beta;
lv_obj_t * label_greek_gamma;
extern lv_obj_t * label_alpha;
extern lv_obj_t * label_beta;
extern lv_obj_t * label_gamma;
extern lv_obj_t * label_neutron;
extern lv_obj_t * label_alpha_unit;
extern lv_obj_t * label_beta_unit;
extern lv_obj_t * label_gamma_unit;
extern lv_obj_t * label_neutron_unit;
extern lv_obj_t* chart;
extern lv_obj_t* chart_alpha;
extern lv_obj_t* chart_beta;
extern lv_obj_t* chart_gamma;
extern lv_obj_t* chart_neutron;
extern lv_chart_series_t * ser;
extern lv_chart_series_t * ser_alpha;
extern lv_chart_series_t * ser_beta;
extern lv_chart_series_t * ser_gamma;
extern lv_chart_series_t * ser_neutron;
extern lv_obj_t* table;
extern lv_obj_t* table_widgets;
extern lv_obj_t* table_settings;
extern lv_obj_t* table_coef;
extern lv_obj_t* screenMenu;
extern lv_obj_t* screenWidgets;
extern lv_obj_t* screenSettings;
extern lv_obj_t* screenCoef;
extern lv_obj_t* screenTab;
extern lv_obj_t* tabview;
//-----------------------------
char* str[7];
extern const char unit_arr[3][6];
extern const char theme_arr[3][6];
extern uint8_t unit_num, theme_num;
extern uint16_t a_coeff;
extern uint16_t b_coeff;
extern uint16_t g_coeff;
extern uint16_t n_coeff;
//extern widget_options options;
//extern const lv_font_t montserrat_55;

static void draw_event_cb_2(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_draw_part_dsc_t * dsc = lv_event_get_draw_part_dsc(e);
    /*If the cells are drawn...*/
    if(dsc->part == LV_PART_ITEMS) {
        bool chk = lv_table_has_cell_ctrl(obj, dsc->id, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);

        lv_draw_rect_dsc_t rect_dsc;
        lv_draw_rect_dsc_init(&rect_dsc);
        rect_dsc.bg_color = chk ? lv_theme_get_color_primary(obj) : lv_palette_lighten(LV_PALETTE_GREY, 2);
        rect_dsc.radius = LV_RADIUS_CIRCLE;

        lv_area_t sw_area;
        sw_area.x1 = dsc->draw_area->x2 - 50;
        sw_area.x2 = sw_area.x1 + 40;
        sw_area.y1 = dsc->draw_area->y1 + lv_area_get_height(dsc->draw_area) / 2 - 10;
        sw_area.y2 = sw_area.y1 + 20;
        lv_draw_rect(dsc->draw_ctx, &rect_dsc, &sw_area);

        rect_dsc.bg_color = lv_color_white();
        if(chk) {
            sw_area.x2 -= 2;
            sw_area.x1 = sw_area.x2 - 16;
        }
        else {
            sw_area.x1 += 2;
            sw_area.x2 = sw_area.x1 + 16;
        }
        sw_area.y1 += 2;
        sw_area.y2 -= 2;
        lv_draw_rect(dsc->draw_ctx, &rect_dsc, &sw_area);
    }
}

static void change_event_cb(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    uint16_t col;
    uint16_t row;
    lv_table_get_selected_cell(obj, &row, &col);
    bool chk = lv_table_has_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
    if(chk) lv_table_clear_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
    else lv_table_add_cell_ctrl(obj, row, 0, LV_TABLE_CELL_CTRL_CUSTOM_1);
}



void my_demo2(lv_disp_t *disp)
{
    lv_obj_t * obj1;

    lv_obj_t* scr_intro = lv_scr_act();
    scr1 = lv_obj_create(NULL);
    screenWidgets = lv_obj_create(NULL);

    static lv_style_t style;
    lv_style_init(&style);
    //lv_style_set_text_font(&style, &lv_font_montserrat_);  /*Set a larger font*/
    lv_style_set_text_color(&style, lv_color_white());


    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj1, lv_pct(103), lv_pct(103));
    lv_obj_set_scrollbar_mode(obj1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scrollbar_mode(lv_scr_act(), LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(obj1, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(obj1, lv_color_black(), LV_PART_MAIN);

    lv_obj_t* logo_img;
    LV_IMG_DECLARE(atom_scan_logo);
    logo_img = lv_img_create(lv_scr_act());
    lv_img_set_src(logo_img, &atom_scan_logo);
    lv_obj_align(logo_img, LV_ALIGN_CENTER, 0, -10);
    //lv_obj_set_size(logo_img, 50, 50);
    lv_obj_set_width(logo_img, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(logo_img, LV_SIZE_CONTENT);    /// 1

    lv_obj_t * label_site = lv_label_create(lv_scr_act());
	lv_obj_align(label_site, LV_ALIGN_CENTER, 10, 100);
	lv_obj_set_width(label_site, 150);
	lv_label_set_text(label_site, "ATOM-SCAN.com");
	lv_obj_add_style(label_site, &style, LV_PART_MAIN);

	// Label Styles
	//LV_FONT_DECLARE(montserrat_170);
	LV_FONT_DECLARE(montserrat_60);
	LV_FONT_DECLARE(montserrat_55);
	LV_FONT_DECLARE(montserrat_52);
	LV_FONT_DECLARE(montserrat_48);
	LV_FONT_DECLARE(greek);
	LV_FONT_DECLARE(lv_font_montserrat_16);
	LV_FONT_DECLARE(lv_font_montserrat_48);

    lv_style_init(&style2);
    lv_style_set_text_font(&style2, &montserrat_48);  /*Set a larger font*/
    lv_style_set_text_color(&style2, lv_color_white());

    lv_style_init(&style_greek);
    lv_style_set_text_font(&style_greek, &greek);  /*Set a larger font*/
    lv_style_set_text_color(&style_greek, lv_color_white());

    lv_style_init(&style_unit);
    lv_style_set_text_font(&style_unit, &lv_font_montserrat_14);
    lv_style_set_text_color(&style_unit, lv_color_white());

    lv_style_init(&style_bg);
    lv_style_set_bg_color(&style_bg, lv_color_black());


    //Home screen
    obj2 = lv_obj_create(scr1);
    lv_obj_set_size(obj2, lv_pct(103), lv_pct(103));
    lv_obj_set_scrollbar_mode(obj2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scrollbar_mode(scr1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(obj2, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_bg_color(obj2, lv_color_black(), LV_PART_MAIN);
    //lv_obj_add_style(obj2, &style_bg, LV_PART_MAIN);


    label_adc = lv_label_create(obj2);
    label_alpha = lv_label_create(obj2);
    label_beta = lv_label_create(obj2);
    label_gamma = lv_label_create(obj2);
    label_neutron = lv_label_create(obj2);
    lv_obj_add_flag(label_alpha, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(label_beta, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(label_gamma, LV_OBJ_FLAG_HIDDEN);
    lv_obj_add_flag(label_neutron, LV_OBJ_FLAG_HIDDEN);
	lv_obj_align(label_adc, LV_ALIGN_CENTER, 40, -50);
	lv_obj_set_width(label_adc, 400);
	lv_label_set_text(label_adc, "ATOM-SCAN.com");
	lv_obj_add_style(label_adc, &style2, LV_PART_MAIN);

	label_greek_alpha = lv_label_create(obj2);

	//Create a chart
    chart = lv_chart_create(obj2);
    lv_obj_set_size(chart, 300, 110);
    //lv_obj_set_style_bg_color(chart, lv_color_black(), LV_PART_MAIN);ff
    lv_obj_add_style(chart, &style_bg, LV_PART_MAIN);
    lv_chart_set_div_line_count(chart, 0, 0);
    lv_obj_align(chart, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
    lv_obj_set_style_size(chart, 0, LV_PART_INDICATOR);
    lv_chart_set_update_mode(chart, LV_CHART_UPDATE_MODE_SHIFT);


     ser = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_RED),
    		 LV_CHART_AXIS_PRIMARY_Y);

    lv_chart_set_point_count(chart, 60);
    lv_chart_set_all_value(chart, ser, 30);

    //table
    lv_group_set_default(g_menu);
    screenMenu = lv_obj_create(NULL);
    lv_obj_set_size(screenMenu, lv_pct(103), lv_pct(103));

    lv_obj_align(screenMenu, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_scrollbar_mode(screenMenu, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(screenMenu, lv_color_black(), LV_PART_MAIN);
    //lv_obj_add_style(screenMenu, &style_bg, LV_PART_MAIN);

	table = lv_table_create(screenMenu);
	lv_obj_clear_flag(table, LV_OBJ_FLAG_SCROLLABLE);
	//lv_obj_add_state(table, LV_STATE_EDITED);
	lv_table_set_cell_value(table, 0, 0, "Start");
	lv_table_set_cell_value(table, 0, 1, unit_arr[unit_num]);
    lv_table_set_cell_value(table, 1, 0, "Coeff");
    lv_table_add_cell_ctrl(table, 1, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);
    //lv_table_set_cell_value(table, 1, 1, "Finish");

    lv_table_set_cell_value(table, 2, 0, "Widgets");
    lv_table_add_cell_ctrl(table, 2, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);

    lv_table_set_cell_value(table, 3, 0, "Settings");
    lv_table_add_cell_ctrl(table, 3, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);

    lv_table_set_cell_value(table, 4, 0, "Tabview");
    lv_table_add_cell_ctrl(table, 4, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);

    //lv_obj_add_style(table, &style_bg, LV_PART_MAIN | LV_PART_ITEMS);

    //lv_obj_align(table, LV_ALIGN_CENTER, 3, 1);
    //lv_obj_set_style_width(table, 340, LV_PART_MAIN);
    //lv_obj_set_style_height(table, 175, LV_PART_MAIN);
    //lv_obj_set_height(table, 220);
    //lv_obj_set_width(table,  300);
    lv_obj_set_size(table, lv_pct(103), lv_pct(103));
    lv_table_set_col_width(table, 0, 163);
    lv_table_set_col_width(table, 1, 163);
    lv_obj_center(table);
    //lv_obj_set_style_bg_color(table, lv_color_black(), LV_PART_MAIN);
    //lv_obj_set_style_bg_color(table, lv_color_black(), LV_PART_ITEMS);
    lv_obj_add_style(table, &style_bg, LV_PART_ITEMS);
    lv_obj_add_style(table, &style_bg, LV_PART_MAIN);
    lv_obj_set_style_border_width(table, 0, LV_PART_ITEMS);
    lv_obj_set_style_border_width(table, 0, LV_PART_MAIN);
    lv_obj_set_style_text_font(table, &lv_font_montserrat_16, LV_PART_ITEMS);
    //temp_label_act = lv_label_create(lv_scr_act());
    //lv_label_set_text(temp_label_act, "The last button event:\nNone");
    lv_obj_add_event_cb(table, draw_event_cb, LV_EVENT_DRAW_PART_END, NULL);
    lv_obj_add_event_cb(table, table_event_cb, LV_EVENT_ALL, NULL);

    vTaskDelay(30);
    // table for widgets
    lv_group_set_default(g_widgets);

    lv_obj_set_scrollbar_mode(screenWidgets, LV_SCROLLBAR_MODE_OFF);
    //lv_obj_set_style_bg_color(screenWidgets, lv_color_black(), LV_PART_MAIN);ff
    lv_obj_add_style(screenWidgets, &style_bg, LV_PART_MAIN);
	table_widgets = lv_table_create(screenWidgets);
	lv_obj_clear_flag(table_widgets, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_center(table_widgets);
    lv_obj_set_size(table_widgets, lv_pct(103), lv_pct(103));
    lv_table_set_col_width(table_widgets, 0, 320);
    //lv_obj_set_style_bg_color(table_widgets, lv_color_black(), LV_PART_MAIN);ff
    //lv_obj_set_style_bg_color(table_widgets, lv_color_black(), LV_PART_ITEMS);ff
    lv_obj_add_style(table_widgets, &style_bg, LV_PART_ITEMS);
    lv_obj_add_style(table_widgets, &style_bg, LV_PART_MAIN);
    lv_obj_set_style_border_width(table_widgets, 0, LV_PART_ITEMS);
    lv_obj_set_style_border_width(table_widgets, 0, LV_PART_MAIN);

    lv_table_set_cell_value(table_widgets, 0, 0, "Alpha");
    lv_table_set_cell_value(table_widgets, 1, 0, "Beta");
    lv_table_set_cell_value(table_widgets, 2, 0, "Gamma");
    lv_table_set_cell_value(table_widgets, 3, 0, "Neutron");
    lv_table_set_cell_value(table_widgets, 4, 0, "Chart");

    lv_obj_add_state(table_widgets, LV_STATE_PRESSED);
    lv_event_send(table_widgets, LV_EVENT_PRESSED, NULL);
    lv_group_focus_obj(table_widgets);
    //lv_group_set_editing(g_widgets, true);
    vTaskDelay(15);
    lv_obj_add_event_cb(table_widgets, draw_event_cb_2, LV_EVENT_DRAW_PART_END, NULL);
    lv_obj_add_event_cb(table_widgets, table_widget_event_cb, LV_EVENT_ALL, NULL);

    // table for coeff
    lv_group_set_default(g_coef);
    screenCoef = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(screenCoef, LV_SCROLLBAR_MODE_OFF);
    //lv_obj_set_style_bg_color(screenCoef, lv_color_black(), LV_PART_MAIN);ff
    lv_obj_add_style(screenCoef, &style_bg, LV_PART_MAIN);
	table_coef = lv_table_create(screenCoef);
	lv_obj_clear_flag(table_coef, LV_OBJ_FLAG_SCROLLABLE);
	//lv_obj_add_state(table, LV_STATE_EDITED);
	lv_table_set_cell_value(table_coef, 0, 0, "C alpha");
    lv_table_set_cell_value(table_coef, 1, 0, "C beta");
    lv_table_set_cell_value(table_coef, 2, 0, "C gamma");
    lv_table_set_cell_value(table_coef, 3, 0, "C neutron");
    sprintf(str, "%d", a_coeff);
    lv_table_set_cell_value(table_coef, 0, 1, str);
    sprintf(str, "%d", b_coeff);
    lv_table_set_cell_value(table_coef, 1, 1, str);
    sprintf(str, "%d", g_coeff);
    lv_table_set_cell_value(table_coef, 2, 1, str);
    sprintf(str, "%d", n_coeff);
    lv_table_set_cell_value(table_coef, 3, 1, str);

    lv_obj_center(table_coef);
    //lv_obj_set_height(table, 220);
    //lv_obj_set_width(table,  300);
    lv_obj_set_size(table_coef, lv_pct(103), lv_pct(103));
    lv_table_set_col_width(table_coef, 0, 160);
    lv_table_set_col_width(table_coef, 1, 160);
    //lv_obj_set_style_bg_color(table_coef, lv_color_black(), LV_PART_MAIN);
    //lv_obj_set_style_bg_color(table_coef, lv_color_black(), LV_PART_ITEMS);
    lv_obj_add_style(table_coef, &style_bg, LV_PART_ITEMS);
    lv_obj_add_style(table_coef, &style_bg, LV_PART_MAIN);
    lv_obj_set_style_border_width(table_coef, 0, LV_PART_ITEMS);
    lv_obj_set_style_border_width(table_coef, 0, LV_PART_MAIN);
    lv_obj_set_style_text_font(table_coef, &lv_font_montserrat_16, LV_PART_ITEMS);
    lv_obj_add_event_cb(table_coef, table_coef_event_cb, LV_EVENT_ALL, NULL);

    //table for settings
    lv_group_set_default(g_settings);
    screenSettings = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(screenSettings, LV_SCROLLBAR_MODE_OFF);
    //lv_obj_set_style_bg_color(screenSettings, lv_color_black(), LV_PART_MAIN);ff
    lv_obj_add_style(screenSettings, &style_bg, LV_PART_MAIN);

	table_settings = lv_table_create(screenSettings);
	lv_obj_clear_flag(table_settings, LV_OBJ_FLAG_SCROLLABLE);
	//lv_obj_add_state(table, LV_STATE_EDITED);
	lv_table_set_cell_value(table_settings, 0, 0, "Theme");
    lv_table_set_cell_value(table_settings, 1, 0, "Language");
    lv_table_set_cell_value(table_settings, 2, 0, "Bluetooth");
    lv_table_set_cell_value(table_settings, 3, 0, "Sidebar");
    lv_table_set_cell_value(table_settings, 4, 0, "Threshold 1");
    lv_table_set_cell_value(table_settings, 5, 0, "Threshold 2");
    lv_table_set_cell_value(table_settings, 6, 0, "Threshold 3");
    lv_table_set_cell_value(table_settings, 0, 1, theme_arr[theme_num]);
    lv_table_set_cell_value(table_settings, 1, 1, theme_arr[theme_num]);
    lv_table_add_cell_ctrl(table_settings, 2, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);
    lv_table_add_cell_ctrl(table_settings, 3, 0, LV_TABLE_CELL_CTRL_MERGE_RIGHT);
    /*sprintf(str, "%d", a_coeff);
    lv_table_set_cell_value(table_settings, 0, 1, str);
    sprintf(str, "%d", b_coeff);
    lv_table_set_cell_value(table_settings, 1, 1, str);
    sprintf(str, "%d", g_coeff);
    lv_table_set_cell_value(table_settings, 2, 1, str);
    sprintf(str, "%d", n_coeff);
    lv_table_set_cell_value(table_settings, 3, 1, str);*/

    lv_obj_center(table_settings);
    //lv_obj_set_height(table, 220);
    //lv_obj_set_width(table,  300);
    lv_obj_set_size(table_settings, lv_pct(103), lv_pct(103));
    lv_table_set_col_width(table_settings, 0, 160);
    lv_table_set_col_width(table_settings, 1, 160);
    //lv_obj_set_style_bg_color(table_settings, lv_color_black(), LV_PART_MAIN);ff
    //lv_obj_set_style_bg_color(table_settings, lv_color_black(), LV_PART_ITEMS);ff
    lv_obj_add_style(table_settings, &style_bg, LV_PART_ITEMS);
    lv_obj_add_style(table_settings, &style_bg, LV_PART_MAIN);
    lv_obj_set_style_border_width(table_settings, 0, LV_PART_ITEMS);
    lv_obj_set_style_border_width(table_settings, 0, LV_PART_MAIN);
    lv_obj_set_style_text_font(table_settings, &lv_font_montserrat_16, LV_PART_ITEMS);
    lv_obj_add_event_cb(table_settings, table_settings_event_cb, LV_EVENT_ALL, NULL);

    //table for tab
    lv_group_set_default(g_tab);
    screenTab = lv_obj_create(NULL);
    lv_obj_set_scrollbar_mode(screenTab, LV_SCROLLBAR_MODE_OFF);
    //lv_obj_set_style_bg_color(screenSettings, lv_color_black(), LV_PART_MAIN);ff
    lv_obj_add_style(screenTab, &style_bg, LV_PART_MAIN);

    tabview = lv_tabview_create(screenTab, LV_DIR_LEFT, 80);
    lv_obj_set_style_bg_color(tabview, lv_palette_lighten(LV_PALETTE_RED, 2), 0);

    lv_obj_t * tab_btns = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(tab_btns, lv_palette_darken(LV_PALETTE_GREY, 3), 0);
    lv_obj_set_style_text_color(tab_btns, lv_palette_lighten(LV_PALETTE_GREY, 5), 0);
    lv_obj_set_style_border_side(tab_btns, LV_BORDER_SIDE_RIGHT, LV_PART_ITEMS | LV_STATE_CHECKED);

    /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
    lv_obj_t * tab1 = lv_tabview_add_tab(tabview, "Tab 1");
    lv_obj_t * tab2 = lv_tabview_add_tab(tabview, "Tab 2");
    lv_obj_t * tab3 = lv_tabview_add_tab(tabview, "Tab 3");
    lv_obj_t * tab4 = lv_tabview_add_tab(tabview, "Tab 4");
    lv_obj_t * tab5 = lv_tabview_add_tab(tabview, "Tab 5");

    lv_obj_set_style_bg_color(tab2, lv_palette_lighten(LV_PALETTE_AMBER, 3), 0);
    lv_obj_set_style_bg_opa(tab2, LV_OPA_COVER, 0);

    /*Add content to the tabs*/
    lv_obj_t * label = lv_label_create(tab1);
    lv_label_set_text(label, "First tab");


    label = lv_label_create(tab2);
    lv_label_set_text(label, "Second tab");

    label = lv_label_create(tab3);
    lv_label_set_text(label, "Third tab");

    label = lv_label_create(tab4);
    lv_label_set_text(label, "Forth tab");

    label = lv_label_create(tab5);
    lv_label_set_text(label, "Fifth tab");

    lv_obj_add_event_cb(tabview, tabview_cb, LV_EVENT_ALL, 0);
    lv_group_set_default(g_tab_btn);
    lv_obj_t* button_tab = lv_btn_create(tab1);
    //lv_obj_add_event_cb(table_widgets, change_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    //vTaskDelay(3000 / portTICK_PERIOD_MS);
	lv_scr_load_anim(scr1, LV_SCR_LOAD_ANIM_FADE_OUT, 500, 1000, true);
	////lv_obj_set_style_bg_color(obj1, lv_color_white(), LV_PART_MAIN);

}//my_demo2



void redraw_widgets(widget_options* opts){

	uint8_t counter = 0;
	uint8_t left = 0;

	counter += opts->alpha;
	counter += opts->beta;
	counter += opts->gamma;
	counter += opts->neutron;
	ESP_LOGI(TAG, "Umm what a sigma");
	ESP_LOGI(TAG, "Counter %d", counter);
	//clear screen scr1
	lv_obj_clean(obj2);
	/*lv_obj_del(obj2);
    obj2 = lv_obj_create(scr1);
    lv_obj_set_size(obj2, lv_pct(103), lv_pct(103));
    lv_obj_set_scrollbar_mode(obj2, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_scrollbar_mode(scr1, LV_SCROLLBAR_MODE_OFF);
    lv_obj_align(obj2, LV_ALIGN_CENTER, 0, 0);
    //lv_obj_set_style_bg_color(obj2, lv_color_black(), LV_PART_MAIN);*/
    opts->alpha_ready = 0;
    opts->beta_ready = 0;
    opts->gamma_ready = 0;
    opts->neutron_ready = 0;
    opts->chart_ready = 0;

	if(opts->alpha){
		//if chart place small digits and chart
		if(counter == 1){
			//label style big
			if(opts->chart == 0 && opts->speedo == 0){
				ESP_LOGI(TAG, "Rizz");
				label_alpha = lv_label_create(obj2);
				lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
				lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_alpha, 150);
				lv_label_set_text(label_alpha, "Alpha");
				lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);

			//if chart place chart
			}else if(opts->chart == 1 && opts->speedo == 0){
				label_alpha = lv_label_create(obj2);
				lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), -50);
				lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_alpha, 150);
				lv_label_set_text(label_alpha, "Alpha");
				lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);

				//Create a chart
				chart_alpha = lv_chart_create(obj2);
				lv_obj_set_size(chart_alpha, 300, 75);
				//lv_obj_set_style_bg_color(chart_alpha, lv_color_black(), LV_PART_MAIN);ff
				lv_obj_add_style(chart, &style_bg, LV_PART_MAIN);
				lv_chart_set_div_line_count(chart_alpha, 0, 0);
				lv_obj_align(chart_alpha, LV_ALIGN_BOTTOM_MID, 0, 0);
				lv_obj_set_style_border_width(chart_alpha, 1, LV_PART_MAIN);
				lv_chart_set_range(chart_alpha, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
				lv_obj_set_style_size(chart_alpha, 0, LV_PART_INDICATOR);
				lv_chart_set_update_mode(chart_alpha, LV_CHART_UPDATE_MODE_SHIFT);

				ser_alpha = lv_chart_add_series(chart_alpha, lv_palette_main(LV_PALETTE_RED),
							    		 LV_CHART_AXIS_PRIMARY_Y);
				lv_chart_set_point_count(chart_alpha, 60);
				lv_chart_set_all_value(chart_alpha, ser_alpha, 30);
				opts->chart_ready = 1;
			//else if speedo place speed
			}else if(opts->chart == 0 && opts->speedo == 1){

			//else if speedo n chart
			}else if(opts->chart == 1 && opts->speedo == 1){

			}///////////////////////
		}else if(counter == 2){
			if(left == 0){
				// place line 1
				if(opts->chart){
					label_alpha = lv_label_create(obj2);
					lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_alpha, 150);
					lv_label_set_text(label_alpha, "alpha");
					lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
					left++;

					chart_alpha = lv_chart_create(obj2);
					lv_obj_set_size(chart_alpha, 140, 70);
					//lv_obj_set_style_bg_color(ffchart_alpha, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_alpha, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_alpha, 0, 0);
					lv_obj_align(chart_alpha, LV_ALIGN_TOP_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_alpha, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_alpha, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_alpha, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_alpha, LV_CHART_UPDATE_MODE_SHIFT);

					ser_alpha = lv_chart_add_series(chart_alpha, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_alpha, 60);
					lv_chart_set_all_value(chart_alpha, ser_alpha, 30);
					opts->chart_ready = 1;
				}else{
					label_alpha = lv_label_create(obj2);
					lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_alpha, 150);
					lv_label_set_text(label_alpha, "Alpha");
					lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
					left++;
				}

			}else if(left == 1){
				//place line 2
				if(opts->chart){
					label_alpha = lv_label_create(obj2);
					lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_alpha, 150);
					lv_label_set_text(label_alpha, "alpha");
					lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);

					chart_alpha = lv_chart_create(obj2);
					lv_obj_set_size(chart_alpha, 140, 70);
					//lv_obj_set_style_bg_color(chart_alpha, lv_color_black(), LV_PART_MAIN);ff
					lv_obj_add_style(chart_alpha, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_alpha, 0, 0);
					lv_obj_align(chart_alpha, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_alpha, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_alpha, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_alpha, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_alpha, LV_CHART_UPDATE_MODE_SHIFT);

					ser_alpha = lv_chart_add_series(chart_alpha, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_alpha, 60);
					lv_chart_set_all_value(chart_alpha, ser_alpha, 30);
					opts->chart_ready = 1;


				}else{
					label_alpha = lv_label_create(obj2);
					lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_alpha, 150);
					lv_label_set_text(label_alpha, "Alpha");
					lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
				}
			}
		}else if(counter == 3){

			if(left == 0){
				// place line 1
				if(opts->chart){
					label_alpha = lv_label_create(obj2);
					lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-35));
					lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_alpha, 150);
					lv_label_set_text(label_alpha, "alpha");
					lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
					left++;

					chart_alpha = lv_chart_create(obj2);
					lv_obj_set_size(chart_alpha, 140, 53);
					//lv_obj_set_style_bg_color(fffchart_alpha, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_alpha, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_alpha, 0, 0);
					lv_obj_align(chart_alpha, LV_ALIGN_TOP_RIGHT, 0, -5);
					lv_obj_set_style_border_width(chart_alpha, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_alpha, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_alpha, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_alpha, LV_CHART_UPDATE_MODE_SHIFT);

					ser_alpha = lv_chart_add_series(chart_alpha, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_alpha, 60);
					lv_chart_set_all_value(chart_alpha, ser_alpha, 30);
					opts->chart_ready = 1;
				}else{
					label_alpha = lv_label_create(obj2);
					lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-30));
					lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_alpha, 150);
					lv_label_set_text(label_alpha, "Alpha");
					lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
					left++;
				}

			}else if(left == 1){
				//place line 2
				label_alpha = lv_label_create(obj2);
				lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
				lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_alpha, 150);
				lv_label_set_text(label_alpha, "Alpha");
				lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
				left++;
			}
		}else if(counter == 4){
			if(opts->chart){
				label_alpha = lv_label_create(obj2);
				lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-40));
				lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_alpha, 150);
				lv_label_set_text(label_alpha, "Alpha");
				lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
				left++;

				chart_alpha = lv_chart_create(obj2);
				lv_obj_set_size(chart_alpha, 140, 40);
				//lv_obj_set_style_bg_color(cffhart_alpha, lv_color_black(), LV_PART_MAIN);
				lv_obj_add_style(chart_alpha, &style_bg, LV_PART_MAIN);
				lv_chart_set_div_line_count(chart_alpha, 0, 0);
				lv_obj_align(chart_alpha, LV_ALIGN_TOP_RIGHT, 0, -8);
				lv_obj_set_style_border_width(chart_alpha, 1, LV_PART_MAIN);
				lv_chart_set_range(chart_alpha, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
				lv_obj_set_style_size(chart_alpha, 0, LV_PART_INDICATOR);
				lv_chart_set_update_mode(chart_alpha, LV_CHART_UPDATE_MODE_SHIFT);

				ser_alpha = lv_chart_add_series(chart_alpha, lv_palette_main(LV_PALETTE_RED),
							    		 LV_CHART_AXIS_PRIMARY_Y);

				lv_chart_set_point_count(chart_alpha, 60);
				lv_chart_set_all_value(chart_alpha, ser_alpha, 30);
			}else{
				label_alpha = lv_label_create(obj2);
				lv_obj_align(label_alpha, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-40));
				lv_obj_set_style_text_align(label_alpha, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_alpha, 150);
				lv_label_set_text(label_alpha, "Alpha");
				lv_obj_add_style(label_alpha, &style2, LV_PART_MAIN);
				left++;
			}
		}
		label_alpha_unit = lv_label_create(obj2);
		lv_obj_align_to(label_alpha_unit, label_alpha,
				LV_ALIGN_OUT_RIGHT_MID, 8, 15);
		lv_obj_set_width(label_alpha_unit, 400);
		lv_label_set_text(label_alpha_unit, unit_arr[unit_num]);
		lv_obj_add_style(label_alpha_unit, &style_unit, LV_PART_MAIN);

		label_greek_alpha = lv_label_create(obj2);
		lv_label_set_text(label_greek_alpha, "α");
		lv_obj_align_to(label_greek_alpha, label_alpha,
				LV_ALIGN_OUT_LEFT_MID, 50, 5);
		lv_obj_add_style(label_greek_alpha, &style_greek, LV_PART_MAIN);
		opts->alpha_ready = 1;
	}
	if(opts->beta){
		//if chart place small digits and chart
		if(counter == 1){
			if(opts->chart == 0){
				label_beta = lv_label_create(obj2);
				lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
				lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_beta, 150);
				lv_label_set_text(label_beta, "Beta");
				lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
			}else{
				label_beta = lv_label_create(obj2);
				lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), -50);
				lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_beta, 150);
				lv_label_set_text(label_beta, "Beta");
				lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);

				//Create a chart
				chart_beta = lv_chart_create(obj2);
				lv_obj_set_size(chart_beta, 300, 75);
				//lv_obj_set_style_bg_color(cffhart_beta, lv_color_black(), LV_PART_MAIN);
				lv_obj_add_style(chart_beta, &style_bg, LV_PART_MAIN);
				lv_chart_set_div_line_count(chart_beta, 0, 0);
				lv_obj_align(chart_beta, LV_ALIGN_BOTTOM_MID, 0, 0);
				lv_obj_set_style_border_width(chart_beta, 1, LV_PART_MAIN);
				lv_chart_set_range(chart_beta, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
				lv_obj_set_style_size(chart_beta, 0, LV_PART_INDICATOR);
				lv_chart_set_update_mode(chart_beta, LV_CHART_UPDATE_MODE_SHIFT);


				ser_beta = lv_chart_add_series(chart_beta, lv_palette_main(LV_PALETTE_RED),
							    		 LV_CHART_AXIS_PRIMARY_Y);

				lv_chart_set_point_count(chart_beta, 60);
				lv_chart_set_all_value(chart_beta, ser_beta, 30);
				opts->chart_ready = 1;
			}

		}else if(counter == 2){

			if(left == 0){
				if(opts->chart){

					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
					left++;

					chart_beta = lv_chart_create(obj2);
					lv_obj_set_size(chart_beta, 140, 70);
					//lv_obj_set_style_bg_color(chaffrt_beta, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_beta, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_beta, 0, 0);
					lv_obj_align(chart_beta, LV_ALIGN_TOP_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_beta, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_beta, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_beta, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_beta, LV_CHART_UPDATE_MODE_SHIFT);

					ser_beta = lv_chart_add_series(chart_beta, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_beta, 60);
					lv_chart_set_all_value(chart_beta, ser_beta, 30);
					opts->chart_ready = 1;
				}else{
				// place line 1
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
					left++;
				}
			}else if(left == 1){
				if(opts->chart){
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);

					chart_beta = lv_chart_create(obj2);
					lv_obj_set_size(chart_beta, 140, 70);
					//lv_obj_set_style_bg_color(chffart_beta, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_beta, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_beta, 0, 0);
					lv_obj_align(chart_beta, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_beta, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_beta, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_beta, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_beta, LV_CHART_UPDATE_MODE_SHIFT);

					ser_beta = lv_chart_add_series(chart_beta, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_beta, 60);
					lv_chart_set_all_value(chart_beta, ser_beta, 30);
					opts->chart_ready = 1;
				}else{
				//place line 2
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
				}
			}

		}else if(counter == 3){

			if(left == 0){
				// place line 1
				if(opts->chart){
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-35));
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
					left++;

					chart_beta = lv_chart_create(obj2);
					lv_obj_set_size(chart_beta, 140, 53);
					//lv_obj_set_style_bg_color(chaffrt_beta, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_beta, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_beta, 0, 0);
					lv_obj_align(chart_beta, LV_ALIGN_TOP_RIGHT, 0, -5);
					lv_obj_set_style_border_width(chart_beta, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_beta, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_beta, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_beta, LV_CHART_UPDATE_MODE_SHIFT);

					ser_beta = lv_chart_add_series(chart_beta, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_beta, 60);
					lv_chart_set_all_value(chart_beta, ser_beta, 30);
					opts->chart_ready = 1;
				}else{
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-30));
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
					left++;
				}
			}else if(left == 1){
				//place line 2
				if(opts->chart){
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
					left++;

					chart_beta = lv_chart_create(obj2);
					lv_obj_set_size(chart_beta, 140, 53);
					//lv_obj_set_style_bg_color(chaffrt_beta, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_beta, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_beta, 0, 0);
					lv_obj_align(chart_beta, LV_ALIGN_RIGHT_MID, 0, 0);
					lv_obj_set_style_border_width(chart_beta, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_beta, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_beta, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_beta, LV_CHART_UPDATE_MODE_SHIFT);

					ser_beta = lv_chart_add_series(chart_beta, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_beta, 60);
					lv_chart_set_all_value(chart_beta, ser_beta, 30);
					opts->chart_ready = 1;
				}else{
					label_beta = lv_label_create(obj2);
					lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
					lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_beta, 150);
					lv_label_set_text(label_beta, "Beta");
					lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
					left++;
				}
			}
		}else if(counter == 4){
			if(opts->chart){
				label_beta = lv_label_create(obj2);
				lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-15));
				lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_beta, 150);
				lv_label_set_text(label_beta, "Beta");
				lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
				left++;

				chart_beta = lv_chart_create(obj2);
				lv_obj_set_size(chart_beta, 140, 40);
				//lv_obj_set_style_bg_color(chffart_beta, lv_color_black(), LV_PART_MAIN);
				lv_obj_add_style(chart_beta, &style_bg, LV_PART_MAIN);
				lv_chart_set_div_line_count(chart_beta, 0, 0);
				lv_obj_align(chart_beta, LV_ALIGN_RIGHT_MID, 0, lv_pct(-14));
				lv_obj_set_style_border_width(chart_beta, 1, LV_PART_MAIN);
				lv_chart_set_range(chart_beta, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
				lv_obj_set_style_size(chart_beta, 0, LV_PART_INDICATOR);
				lv_chart_set_update_mode(chart_beta, LV_CHART_UPDATE_MODE_SHIFT);

				ser_beta = lv_chart_add_series(chart_beta, lv_palette_main(LV_PALETTE_RED),
							    		 LV_CHART_AXIS_PRIMARY_Y);

				lv_chart_set_point_count(chart_beta, 60);
				lv_chart_set_all_value(chart_beta, ser_beta, 30);
				opts->chart_ready = 1;
			}else{
				label_beta = lv_label_create(obj2);
				lv_obj_align(label_beta, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-15));
				lv_obj_set_width(label_beta, 150);
				lv_obj_set_style_text_align(label_beta, LV_TEXT_ALIGN_RIGHT, 0);
				lv_label_set_text(label_beta, "Beta");
				lv_obj_add_style(label_beta, &style2, LV_PART_MAIN);
				left++;
			}
		}
		label_beta_unit = lv_label_create(obj2);
		lv_obj_align_to(label_beta_unit, label_beta,
				LV_ALIGN_OUT_RIGHT_MID, 8, 15);
		lv_obj_set_width(label_beta_unit, 400);
		lv_label_set_text(label_beta_unit, unit_arr[unit_num]);
		lv_obj_add_style(label_beta_unit, &style_unit, LV_PART_MAIN);

		label_greek_beta = lv_label_create(obj2);
		lv_label_set_text(label_greek_beta, "β");
		lv_obj_align_to(label_greek_beta, label_beta,
				LV_ALIGN_OUT_LEFT_MID, 50, 5);
		lv_obj_add_style(label_greek_beta, &style_greek, LV_PART_MAIN);

		opts->beta_ready = 1;
	}
	if(opts->gamma){
		//if chart place small digits and chart
		if(counter == 1){
			if(opts->chart == 0){
			label_gamma = lv_label_create(obj2);
			lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
			lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
			lv_obj_set_width(label_gamma, 150);
			lv_label_set_text(label_gamma, "ATOM-SCAN.com");
			lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);

		}else{
		//Home screen
			label_gamma = lv_label_create(obj2);
			lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), -50);
			lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
			lv_obj_set_width(label_gamma, 150);
			lv_label_set_text(label_gamma, "Gamma");
			lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);

							//Create a chart
			chart_gamma = lv_chart_create(obj2);
			lv_obj_set_size(chart_gamma, 300, 75);
			//lv_obj_set_style_bg_color(chartff_gamma, lv_color_black(), LV_PART_MAIN);
			lv_obj_add_style(chart_gamma, &style_bg, LV_PART_MAIN);
			lv_chart_set_div_line_count(chart_gamma, 0, 0);
			lv_obj_align(chart_gamma, LV_ALIGN_BOTTOM_MID, 0, 0);
			lv_obj_set_style_border_width(chart_gamma, 1, LV_PART_MAIN);
			lv_chart_set_range(chart_gamma, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
			lv_obj_set_style_size(chart_gamma, 0, LV_PART_INDICATOR);
			lv_chart_set_update_mode(chart_gamma, LV_CHART_UPDATE_MODE_SHIFT);

			ser_gamma = lv_chart_add_series(chart_gamma, lv_palette_main(LV_PALETTE_RED),
						    		 LV_CHART_AXIS_PRIMARY_Y);
			lv_chart_set_point_count(chart_gamma, 60);
			lv_chart_set_all_value(chart_gamma, ser_gamma, 30);
			opts->chart_ready = 1;
		}

		}else if(counter == 2){

			if(left == 0){
				if(opts->chart){

					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_width(label_gamma, 150);
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_label_set_text(label_gamma, "gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
					left++;

					chart_gamma = lv_chart_create(obj2);
					lv_obj_set_size(chart_gamma, 140, 70);
					//lv_obj_set_style_bg_color(charfft_gamma, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_gamma, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_gamma, 0, 0);
					lv_obj_align(chart_gamma, LV_ALIGN_TOP_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_gamma, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_gamma, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_gamma, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_gamma, LV_CHART_UPDATE_MODE_SHIFT);

					ser_gamma = lv_chart_add_series(chart_gamma, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_gamma, 60);
					lv_chart_set_all_value(chart_gamma, ser_gamma, 30);
					opts->chart_ready = 1;
				}else{
				// place line 1
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_width(label_gamma, 150);
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_label_set_text(label_gamma, "gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
					left++;
				}
			}else if(left == 1){
				if(opts->chart){
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_width(label_gamma, 150);
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_label_set_text(label_gamma, "gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);

					chart_gamma = lv_chart_create(obj2);
					lv_obj_set_size(chart_gamma, 140, 70);
					//lv_obj_set_style_bg_color(chaffrt_gamma, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_gamma, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_gamma, 0, 0);
					lv_obj_align(chart_gamma, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_gamma, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_gamma, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_gamma, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_gamma, LV_CHART_UPDATE_MODE_SHIFT);

					ser_gamma = lv_chart_add_series(chart_gamma, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_gamma, 60);
					lv_chart_set_all_value(chart_gamma, ser_gamma, 30);
					opts->chart_ready = 1;
				}else{
				//place line 2
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_width(label_gamma, 150);
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_label_set_text(label_gamma, "gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
				}
			}

		}else if(counter == 3){

			if(left == 0){
				// place line 1
				label_gamma = lv_label_create(obj2);
				lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-35));
				lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_gamma, 150);
				lv_label_set_text(label_gamma, "Gamma");
				lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
				left++;
			}else if(left == 1){
				//place line 2
				if(opts->chart){
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_gamma, 150);
					lv_label_set_text(label_gamma, "Gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
					left++;

					chart_gamma = lv_chart_create(obj2);
					lv_obj_set_size(chart_gamma, 140, 53);
					//lv_obj_set_style_bg_color(chaffrt_gamma, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_gamma, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_gamma, 0, 0);
					lv_obj_align(chart_gamma, LV_ALIGN_RIGHT_MID, 0, 0);
					lv_obj_set_style_border_width(chart_gamma, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_gamma, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_gamma, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_gamma, LV_CHART_UPDATE_MODE_SHIFT);

					ser_gamma = lv_chart_add_series(chart_gamma, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);
					lv_chart_set_point_count(chart_gamma, 60);
					lv_chart_set_all_value(chart_gamma, ser_gamma, 30);
					opts->chart_ready = 1;
				}else{
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_gamma, 150);
					lv_label_set_text(label_gamma, "Gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
					left++;
				}
			}else if(left == 2){
				//place line 3
				if(opts->chart){
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(35));
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_gamma, 150);
					lv_label_set_text(label_gamma, "Gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);

					chart_gamma = lv_chart_create(obj2);
					lv_obj_set_size(chart_gamma, 140, 53);
					//lv_obj_set_style_bg_color(charfft_gamma, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_gamma, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_gamma, 0, 0);
					lv_obj_align(chart_gamma, LV_ALIGN_RIGHT_MID, 0, lv_pct(35));
					lv_obj_set_style_border_width(chart_gamma, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_gamma, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
					lv_obj_set_style_size(chart_gamma, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_gamma, LV_CHART_UPDATE_MODE_SHIFT);

					ser_gamma = lv_chart_add_series(chart_gamma, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);
					lv_chart_set_point_count(chart_gamma, 60);
					lv_chart_set_all_value(chart_gamma, ser_gamma, 30);
					opts->chart_ready = 1;
				}else{
					label_gamma = lv_label_create(obj2);
					lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(35));
					lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_gamma, 150);
					lv_label_set_text(label_gamma, "Gamma");
					lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
				}
			}

		}else if(counter == 4){
			if(opts->chart){
				label_gamma = lv_label_create(obj2);
				lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(15));
				lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_gamma, 150);
				lv_label_set_text(label_gamma, "Gamma");
				lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
				left++;

				chart_gamma = lv_chart_create(obj2);
				lv_obj_set_size(chart_gamma, 140, 40);
				//lv_obj_set_style_bg_color(chaffrt_gamma, lv_color_black(), LV_PART_MAIN);
				lv_obj_add_style(chart_gamma, &style_bg, LV_PART_MAIN);
				lv_chart_set_div_line_count(chart_gamma, 0, 0);
				lv_obj_align(chart_gamma, LV_ALIGN_RIGHT_MID, 0, lv_pct(14));
				lv_obj_set_style_border_width(chart_gamma, 1, LV_PART_MAIN);
				lv_chart_set_range(chart_gamma, LV_CHART_AXIS_PRIMARY_Y, 0, 4000);
				lv_obj_set_style_size(chart_gamma, 0, LV_PART_INDICATOR);
				lv_chart_set_update_mode(chart_gamma, LV_CHART_UPDATE_MODE_SHIFT);

				ser_gamma = lv_chart_add_series(chart_gamma, lv_palette_main(LV_PALETTE_RED),
							    		 LV_CHART_AXIS_PRIMARY_Y);
				lv_chart_set_point_count(chart_gamma, 60);
				lv_chart_set_all_value(chart_gamma, ser_gamma, 30);
				opts->chart_ready = 1;
			}else{
				label_gamma = lv_label_create(obj2);
				lv_obj_align(label_gamma, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(15));
				lv_obj_set_style_text_align(label_gamma, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_gamma, 150);
				lv_label_set_text(label_gamma, "Gamma");
				lv_obj_add_style(label_gamma, &style2, LV_PART_MAIN);
				left++;
			}
		}
		label_gamma_unit = lv_label_create(obj2);
		lv_obj_align_to(label_gamma_unit, label_gamma,
				LV_ALIGN_OUT_RIGHT_MID, 8, 15);
		lv_obj_set_width(label_gamma_unit, 400);
		lv_label_set_text(label_gamma_unit, unit_arr[unit_num]);
		lv_obj_add_style(label_gamma_unit, &style_unit, LV_PART_MAIN);

		label_greek_gamma = lv_label_create(obj2);
		lv_label_set_text(label_greek_gamma, "γ");
		lv_obj_align_to(label_greek_gamma, label_gamma,
				LV_ALIGN_OUT_LEFT_MID, 50, 5);
		lv_obj_add_style(label_greek_gamma, &style_greek, LV_PART_MAIN);

		opts->gamma_ready = 1;
	}
	if(opts->neutron){
		//if chart place small digits and chart
		if(counter == 1){

			if(opts->chart == 0){
				label_neutron = lv_label_create(obj2);
				lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
				lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_neutron, 150);
				lv_label_set_text(label_neutron, "Neutron");
				lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

			}else{	//chart
			    //Home screen
			    label_neutron = lv_label_create(obj2);
				lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), -50);
				lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_neutron, 150);
				lv_label_set_text(label_neutron, "Neutron");
				lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);


				//Create a chart
			    chart_neutron = lv_chart_create(obj2);
			    lv_obj_set_size(chart_neutron, 300, 75);
			    //lv_obj_set_style_bg_color(chaffrt_neutron, lv_color_black(), LV_PART_MAIN);
			    lv_obj_add_style(chart_neutron, &style_bg, LV_PART_MAIN);
			    lv_chart_set_div_line_count(chart_neutron, 0, 0);
			    lv_obj_align(chart_neutron, LV_ALIGN_BOTTOM_MID, 0, 0);
			    lv_obj_set_style_border_width(chart_neutron, 1, LV_PART_MAIN);
			    lv_chart_set_range(chart_neutron, LV_CHART_AXIS_PRIMARY_Y, 0, 400);
			    lv_obj_set_style_size(chart_neutron, 0, LV_PART_INDICATOR);
			    lv_chart_set_update_mode(chart_neutron, LV_CHART_UPDATE_MODE_SHIFT);


			     ser_neutron = lv_chart_add_series(chart_neutron, lv_palette_main(LV_PALETTE_RED),
			    		 LV_CHART_AXIS_PRIMARY_Y);

			    lv_chart_set_point_count(chart_neutron, 60);
			    lv_chart_set_all_value(chart_neutron, ser_neutron, 30);
			    opts->chart_ready = 1;
			}

		}else if(counter == 2){

			if(left == 0){
				if(opts->chart){

					label_neutron = lv_label_create(obj2);
					lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_neutron, 150);
					lv_label_set_text(label_neutron, "neutron");
					lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);
					left++;

					chart_neutron = lv_chart_create(obj2);
					lv_obj_set_size(chart_neutron, 140, 70);
					//lv_obj_set_style_bg_color(charfft_neutron, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_neutron, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_neutron, 0, 0);
					lv_obj_align(chart_neutron, LV_ALIGN_TOP_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_neutron, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_neutron, LV_CHART_AXIS_PRIMARY_Y, 0, 400);
					lv_obj_set_style_size(chart_neutron, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_neutron, LV_CHART_UPDATE_MODE_SHIFT);

					ser_neutron = lv_chart_add_series(chart_neutron, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_neutron, 60);
					lv_chart_set_all_value(chart_neutron, ser_neutron, 30);
					opts->chart_ready = 1;
				}else{
				// place line 1
					label_neutron = lv_label_create(obj2);
					lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-25));
					lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_neutron, 150);
					lv_label_set_text(label_neutron, "neutron");
					lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);
					left++;

				}
			}else if(left == 1){
				if(opts->chart){
					label_neutron = lv_label_create(obj2);
					lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_neutron, 150);
					lv_label_set_text(label_neutron, "neutron");
					lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

					chart_neutron = lv_chart_create(obj2);
					lv_obj_set_size(chart_neutron, 140, 70);
					//lv_obj_set_style_bg_color(charfft_neutron, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_neutron, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_neutron, 0, 0);
					lv_obj_align(chart_neutron, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
					lv_obj_set_style_border_width(chart_neutron, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_neutron, LV_CHART_AXIS_PRIMARY_Y, 0, 400);
					lv_obj_set_style_size(chart_neutron, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_neutron, LV_CHART_UPDATE_MODE_SHIFT);

					ser_neutron = lv_chart_add_series(chart_neutron, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_neutron, 60);
					lv_chart_set_all_value(chart_neutron, ser_neutron, 30);
					opts->chart_ready = 1;
				}else{
				//place line 2
					label_neutron = lv_label_create(obj2);
					lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(25));
					lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_neutron, 150);
					lv_label_set_text(label_neutron, "neutron");
					lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

				}
			}

		}else if(counter == 3){

			if(left == 0){
				// place line 1
				label_neutron = lv_label_create(obj2);
				lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(-30));
				lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_neutron, 150);
				lv_label_set_text(label_neutron, "Neutron");
				lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

				left++;
			}else if(left == 1){
				//place line 2
				label_neutron = lv_label_create(obj2);
				lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), 0);
				lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_neutron, 150);
				lv_label_set_text(label_neutron, "Neutron");
				lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

			}else if(left == 2){
				//place line 3
				if(opts->chart){

					label_neutron = lv_label_create(obj2);
					lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(35));
					lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_neutron, 150);
					lv_label_set_text(label_neutron, "neutron");
					lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);


					chart_neutron = lv_chart_create(obj2);
					lv_obj_set_size(chart_neutron, 140, 53);
					//lv_obj_set_style_bg_color(charfft_neutron, lv_color_black(), LV_PART_MAIN);
					lv_obj_add_style(chart_neutron, &style_bg, LV_PART_MAIN);
					lv_chart_set_div_line_count(chart_neutron, 0, 0);
					lv_obj_align(chart_neutron, LV_ALIGN_BOTTOM_RIGHT, 0, 5);
					lv_obj_set_style_border_width(chart_neutron, 1, LV_PART_MAIN);
					lv_chart_set_range(chart_neutron, LV_CHART_AXIS_PRIMARY_Y, 0, 400);
					lv_obj_set_style_size(chart_neutron, 0, LV_PART_INDICATOR);
					lv_chart_set_update_mode(chart_neutron, LV_CHART_UPDATE_MODE_SHIFT);

					ser_neutron = lv_chart_add_series(chart_neutron, lv_palette_main(LV_PALETTE_RED),
								    		 LV_CHART_AXIS_PRIMARY_Y);

					lv_chart_set_point_count(chart_neutron, 60);
					lv_chart_set_all_value(chart_neutron, ser_neutron, 30);
					opts->chart_ready = 1;
				}else{
					label_neutron = lv_label_create(obj2);
					lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(30));
					lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
					lv_obj_set_width(label_neutron, 150);
					lv_label_set_text(label_neutron, "Neutron");
					lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

				}
			}


		}else if(counter == 4){
			if(opts->chart){
				label_neutron = lv_label_create(obj2);
				lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-15), lv_pct(40));
				lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_neutron, 150);
				lv_label_set_text(label_neutron, "Neutron");
				lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

				left++;

				chart_neutron = lv_chart_create(obj2);
				lv_obj_set_size(chart_neutron, 140, 40);
				//lv_obj_set_style_bg_color(chaffrt_neutron, lv_color_black(), LV_PART_MAIN);
				lv_obj_add_style(chart_neutron, &style_bg, LV_PART_MAIN);
				lv_chart_set_div_line_count(chart_neutron, 0, 0);
				lv_obj_align(chart_neutron, LV_ALIGN_BOTTOM_RIGHT, 0, 7);
				lv_obj_set_style_border_width(chart_neutron, 1, LV_PART_MAIN);
				lv_chart_set_range(chart_neutron, LV_CHART_AXIS_PRIMARY_Y, 0, 400);
				lv_obj_set_style_size(chart_neutron, 0, LV_PART_INDICATOR);
				lv_chart_set_update_mode(chart_neutron, LV_CHART_UPDATE_MODE_SHIFT);

				ser_neutron = lv_chart_add_series(chart_neutron, lv_palette_main(LV_PALETTE_RED),
							    		 LV_CHART_AXIS_PRIMARY_Y);

				lv_chart_set_point_count(chart_neutron, 60);
				lv_chart_set_all_value(chart_neutron, ser_neutron, 30);
				opts->chart_ready = 1;
			}else{
				label_neutron = lv_label_create(obj2);
				lv_obj_align(label_neutron, LV_ALIGN_LEFT_MID, lv_pct(-20), lv_pct(40));
				lv_obj_set_style_text_align(label_neutron, LV_TEXT_ALIGN_RIGHT, 0);
				lv_obj_set_width(label_neutron, 150);
				lv_label_set_text(label_neutron, "Neutron");
				lv_obj_add_style(label_neutron, &style2, LV_PART_MAIN);

				left++;
			}
		}
		label_neutron_unit = lv_label_create(obj2);
		lv_obj_align_to(label_neutron_unit, label_neutron,
				LV_ALIGN_OUT_RIGHT_MID, 8, 15);
		lv_obj_set_width(label_neutron_unit, 400);
		lv_label_set_text(label_neutron_unit, unit_arr[unit_num]);
		lv_obj_add_style(label_neutron_unit, &style_unit, LV_PART_MAIN);
		opts->neutron_ready = 1;

	}

}
