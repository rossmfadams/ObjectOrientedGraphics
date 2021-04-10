#ifndef GENPOINT_H
#define GENPOINT_H

class GenPoint
{
  private:
    int x;
    int y;
  
  public:
    GenPoint();
    GenPoint(int x, int y);
    void setPoint(int x, int y);
    int getX();
    int getY();
};

#endif