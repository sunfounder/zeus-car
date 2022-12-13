#include "ir_obstacle.h"

void irObstacleBegin() {
  hc165Begin();
}

byte irObstacleRead() {
  return hc165Read();
}
