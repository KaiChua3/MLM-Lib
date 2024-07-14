#include "MLMlib/elements.hpp"
#include "main.h"

void createBtn(lv_obj_t * parent, int32_t x, int32_t y, int32_t width, int32_t height, int id, const char * title) {
    lv_obj_t * btn = lv_btn_create(parent);
    lv_obj_set_pos(btn, x, y);
    lv_obj_set_size(btn, width, height);

    lv_obj_t * label = lv_label_create(btn);
    lv_label_set_text(label, title);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 5);
}