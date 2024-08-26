#include "MLMlib/elements.hpp"
#include "main.h"

void createBtn(lv_obj_t * window, lv_obj_t * btn, int32_t x, int32_t y, int32_t width, int32_t height, int id, const char * title) {
    btn = lv_btn_create(window);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_size(btn, width, height);

    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, title);
    lv_obj_center(label);
}

void createImage() {

}



void mainWindow() {

}

void testingWindow() {

}

void autonomousWindow() {

}

void hideElement(lv_obj_t * object) {
    lv_obj_add_flag(object, LV_OBJ_FLAG_HIDDEN);
}

void showElement(lv_obj_t * object) {
    lv_obj_clear_flag(object, LV_OBJ_FLAG_HIDDEN);
}
