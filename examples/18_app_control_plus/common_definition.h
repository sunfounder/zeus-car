#ifndef __ARDUINO_CAR_H__
#define __ARDUINO_CAR_H__

/** 
 * @name Mode Value Definition
 */
#define MODE_NONE                    0
#define MODE_LINE_TRACK          1
#define MODE_ROTATE_LINE_FOLLOWING   2
#define MODE_OBSTACLE_FOLLOWING      3
#define MODE_OBSTACLE_AVOIDANCE      4
#define MODE_REMOTE_CONTROL          5
#define MODE_APP_CONTROL             6
#define MODE_COMPASS_CALIBRATION     7

/**
 *@name Defines the hexadecimal value of the color
 */
#define RED           0xFF0A0A
#define ORANGE        0xFF2500  //0xFFA500
#define YELLOW        0xFFFF0A
#define YELLOW_GREEN  0xA5FF0A
#define GREEN         0x0AFF0A
#define GREEN_CYAN    0x0AFFA5
#define CYAN          0x0AFFFF
#define CYAN_BLUE     0x0AA5FF
#define BLUE          0x0A0AFF
#define PURPLE        0xA50AFF
#define VOILET        0xFF0AFF
#define MAGENTA       0xFF0AA5

/**
 * @name Set the color to match the mode
 */
#define MODE_NONE_COLOR                     GREEN_CYAN
#define MODE_LINE_TRACK_COLOR               CYAN
#define MODE_ROTATE_LINE_FOLLOWING_COLOR    CYAN_BLUE
#define MODE_OBSTACLE_FOLLOWING_COLOR       BLUE
#define MODE_OBSTACLE_AVOIDANCE_COLOR       PURPLE
#define MODE_REMOTE_CONTROL_COLOR           VOILET
#define MODE_APP_CONTROL_COLOR              MAGENTA

#endif // __ARDUINO_CAR_H__
