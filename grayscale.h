#ifndef __GRAYSCALE_H__
#define __GRAYSCALE_H__

class Grayscale{
  public:
    Grayscale(int pin1, int pin2, int pin3, int ref);
    Grayscale(int* pins, int ref);
    void begin();
    void readRawInto(int* data);
    void readInto(int* data);
    void readInto(int* data, int angle);
    void setRef(int ref);
  private:
    int pins[3];
    int ref;
};

#endif // __GRAYSCALE_H__