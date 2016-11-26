#ifndef CLIENT_H
#define CLIENT_H
#include "drawable.h"
#include "pageturner.h"

class Client : public PageTurner
{
public:
    Client(Drawable *drawable);
    void nextPage();



private:
    Drawable *drawable;
    void readsimp(const char * filepath);
    int lerp(int color1, int color2, int currentvalue, int finalvalue);
    void drawTriangleBresVersion2( int x0,  int y0, int z0,  int x1,  int y1, int z1, int x2, int y2, int z2, unsigned int r0, unsigned int g0, unsigned int b0,unsigned int r1, unsigned int g1, unsigned int b1,unsigned int r2, unsigned int g2, unsigned int b2);
    void wiremesh(const int p1x, const int p1y, const int p2x, const int p2y);
    void filledinmesh(const int p1x, const int p1y, const int p2x, const int p2y);
    void drawTriangleBres(const int x0, const int y0, const int x1, const int y1,const int x2, const int y2, unsigned int ri, unsigned int gi, unsigned int bi,unsigned int rf, unsigned int gf, unsigned int bf);
    void draw_rect(int x1, int y1, int x2, int y2, unsigned int color);
    void draw_lineDDA(int x1, int y1, int x2, int y2,unsigned int color);
    void draw_lineBres(int x1, int y1, int z1, int x2, int y2, int z2, unsigned int ri, unsigned int gi, unsigned int bi,unsigned int rf, unsigned int gf, unsigned int bf);
    void drawTriangleDDA(const int x0, const int y0, const int x1, const int y1,const int x2, const int y2, unsigned int color);
    void translate( float tx, float ty, float tz);
    void rotate( char axis, int angle);
    float* CalculateFaceNormal(float x0, float y0, float z0, float x1, float y1, float z1,float x2, float y2, float z2, float normal[]);


    float dot(float x1, float y1, float z1, float x2, float y2, float z2);


};

class char_stack

{
  public:
    char_stack();
    void push( char item );
    char pop();
    char top();
    bool empty();
    int size();

  private:

    static const int capacity = 256;
    int A[capacity];
    int top_index;
    int sizestack;
};

#endif // CLIENT_H
