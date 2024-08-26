#include "main.h"
#include "MLMlib/api.hpp"

// Declare all cortex screen elements here i.e buttons, images, etc

lv_obj_t * screen;

lv_obj_t * auton_screen_btn;
lv_obj_t * testing_screen_btn;
lv_obj_t * match_screen_btn;
lv_obj_t * window;
lv_obj_t * main_screen;
lv_obj_t * main_image;

lv_obj_t * match_screen;

lv_obj_t * autonomous_screen;

lv_obj_t * bot_testing_screen;

lv_style_t main_window_background;

void on_center_button() {}

/**
 * Runs initialization code. This occurs as soon as the progzram is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

LV_IMG_DECLARE(main_image_file);

void initializeMainScreen() {
    showElement(main_screen);
    hideElement(autonomous_screen);
    hideElement(bot_testing_screen);
    hideElement(match_screen);
}

void showMainScreen(lv_event_t * event) {
    showElement(main_screen);
    hideElement(autonomous_screen);
    hideElement(bot_testing_screen);
    hideElement(match_screen);
}

void showMatchScreen(lv_event_t * event) {
    hideElement(main_screen);
    hideElement(autonomous_screen);
    hideElement(bot_testing_screen);
    showElement(match_screen);
}

void showAutonScreen(lv_event_t * event) {
    hideElement(main_screen);
    showElement(autonomous_screen);
    hideElement(bot_testing_screen);
    hideElement(match_screen);
}

void showTestingScreen(lv_event_t * event) {
    hideElement(main_screen);
    hideElement(autonomous_screen);
    showElement(bot_testing_screen);
    hideElement(match_screen);
}

void nothing (lv_event_t * event) {

}

void initialize() {
    screen = lv_scr_act();
    lv_obj_clear_flag(screen, LV_OBJ_FLAG_SCROLLABLE);

    main_screen = lv_obj_create(screen);
    lv_obj_clear_flag(main_screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_size(main_screen, 480, 272);
    lv_obj_center(main_screen);
    lv_obj_set_pos(main_screen, -10, 0);
    main_image = lv_img_create(main_screen);
    lv_img_set_src(main_image, &main_image_file);

    // createBtn(main_screen, btn1, 0, 0, 120, 50, 0, "testing button");
    match_screen_btn = lv_btn_create(main_screen);
    lv_obj_set_pos(match_screen_btn, 20, 50);
    lv_obj_set_size(match_screen_btn, 200, 50);

    lv_obj_t * label = lv_label_create(match_screen_btn);
    lv_label_set_text(label, "Match Screen");
    lv_obj_center(label);
    lv_obj_add_event_cb(match_screen_btn, showMatchScreen, LV_EVENT_PRESSED, NULL);

    // createBtn(main_screen, btn2, 100, 0, 120, 50, 0, "hidden");
    auton_screen_btn = lv_btn_create(main_screen);
    lv_obj_set_pos(auton_screen_btn, 20, 100);
    lv_obj_set_size(auton_screen_btn, 200, 50);

    lv_obj_t * label1 = lv_label_create(auton_screen_btn);
    lv_label_set_text(label1, "Autonomous Screen");
    lv_obj_center(label1);
    lv_obj_add_event_cb(auton_screen_btn, showAutonScreen, LV_EVENT_PRESSED, NULL);

    testing_screen_btn = lv_btn_create(main_screen);
    lv_obj_set_pos(testing_screen_btn, 20, 150);
    lv_obj_set_size(testing_screen_btn, 200, 50);

    lv_obj_t * label2 = lv_label_create(testing_screen_btn);
    lv_label_set_text(label2, "Testing Screen");
    lv_obj_center(label2);
    lv_obj_add_event_cb(testing_screen_btn, showTestingScreen, LV_EVENT_PRESSED, NULL);

    
    autonomous_screen = lv_obj_create(screen);
    lv_obj_clear_flag(autonomous_screen, LV_OBJ_FLAG_SCROLLABLE);

    bot_testing_screen = lv_obj_create(screen);
    lv_obj_clear_flag(bot_testing_screen, LV_OBJ_FLAG_SCROLLABLE);

    match_screen = lv_obj_create(screen);
    lv_obj_clear_flag(match_screen, LV_OBJ_FLAG_SCROLLABLE);

    main_image = lv_img_create(match_screen);
    lv_obj_set_size(match_screen, 480, 272);
    lv_obj_center(match_screen);
    lv_obj_set_pos(match_screen, -10, 0);
    lv_img_set_src(main_image, &main_image_file);
    lv_obj_add_flag(match_screen, LV_OBJ_FLAG_HIDDEN);

    initializeMainScreen();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {}