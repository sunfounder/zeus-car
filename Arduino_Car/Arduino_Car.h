#ifndef __ARDUINO_CAR_H__
#define __ARDUINO_CAR_H__

#define MODE_NONE                    0
#define MODE_LINE_FOLLOWING 1
#define MODE_ROTATE_LINE_FOLLOWING   2
#define MODE_OBSTACLE_FOLLOWING      3
#define MODE_OBSTACLE_AVOIDANCE      4
#define MODE_REMOTE_CONTROL          5
#define MODE_APP_CONTROL             6
#define MODE_COMPASS_CALIBRATION     7

#define RED           pixels.Color(255,  10,  10)
#define ORANGE        pixels.Color(255, 165,  10)
#define YELLOW        pixels.Color(255, 255,  10)
#define YELLOW_GREEN  pixels.Color(165, 255,  10)
#define GREEN         pixels.Color( 10, 255,  10)
#define GREEN_CYAN    pixels.Color( 10, 255, 165)
#define CYAN          pixels.Color( 10, 255, 255)
#define CYAN_BLUE     pixels.Color( 10, 165, 255)
#define BLUE          pixels.Color( 10,  10, 255)
#define PURPLE        pixels.Color(165,  10, 255)
#define VOILET        pixels.Color(255,  10, 255)
#define MAGENTA       pixels.Color(255,  10, 165)

#define MODE_NONE_COLOR                     GREEN_CYAN
#define MODE_LINE_FOLLOWING_COLOR           CYAN
#define MODE_ROTATE_LINE_FOLLOWING_COLOR    CYAN_BLUE
#define MODE_OBSTACLE_FOLLOWING_COLOR       BLUE
#define MODE_OBSTACLE_AVOIDANCE_COLOR       PURPLE
#define MODE_REMOTE_CONTROL_COLOR           VOILET
#define MODE_APP_CONTROL_COLOR              MAGENTA

#endif // __ARDUINO_CAR_H__