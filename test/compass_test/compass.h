
#define AVERAGE_FILTER_SIZE 30

class Compass {
  public:
    Compass();
    void begin();
    int read();
    int readRaw();
  private:
    int heading;
    int filterBuffer[AVERAGE_FILTER_SIZE];
    int filterBufferIndex = 0;
    void filterBufferAppend(int value);
};