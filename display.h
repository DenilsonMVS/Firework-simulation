
#ifndef DENILSON_DISPLAY_LIBRARY
#define DENILSON_DISPLAY_LIBRARY

#include "vector.h"

extern void initiateWindow(int argc, char **argv, int width, int height, const char *windowName);
extern float pixelToFloatWidth(int x);
extern float pixelToFloatHeight(int y);
extern int floatToPixelWidth(float x);
extern int floatToPixelHeight(float y);

#endif
