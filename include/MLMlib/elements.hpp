#pragma once

#include "main.h"
#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void createBtn(lv_obj_t * window, lv_obj_t * btn, int32_t x, int32_t y, int32_t width, int32_t height, int id, const char * title);
void createImage();

void mainWindow();

void testingWindow();

void autonomousWindow();

void hideElement(lv_obj_t * object);

void showElement(lv_obj_t * object);

#endif