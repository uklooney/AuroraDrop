/*
 * Aurora: https://github.com/pixelmatix/aurora
 * Copyright (c) 2014 Jason Coon
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */



#ifndef PatternAudioLines_H
#define PatternAudioLines_H

class PatternAudioLines : public Drawable {
  public:
    PatternAudioLines() {
      name = (char *)"Audio Lines";
      id = (char *)"L";
      enabled = true;
    }

    bool cycleColors;
    uint8_t color1 = 0;
    uint8_t color2 = 64;
    uint8_t color3 = 128;
    uint8_t color4 = 192;

    uint8_t caleidoscopeMode = 0;


    // #############
    // ### START ###
    // #############
    void start(uint8_t _pattern){
      cycleColors = random(0, 2);
      caleidoscopeMode = random(0, 2);
      //Serial.print("caleidoscopeMode="); Serial.println(caleidoscopeMode);
      //effects.ClearFrame();
    };



    // ##################
    // ### DRAW FRAME ###
    // ##################
    unsigned int drawFrame(uint8_t _pattern, uint8_t _total) {

    if (cycleColors) {
      color1++;
      color2++;
      color3++;
      color4++;
    }
    else {
      color1 = 0;
      color2 = 64;
      color3 = 128;
      color4 = 192;
    }

    int x1,y1,x2,y2,x3,y3;
    x1 = fftData.specData[05] / 3;
    y1 = fftData.specData[10] / 3;
    x2 = fftData.specData[15] / 3;
    y2 = fftData.specData[20] / 3;
    x3 = fftData.specData[25] / 3;
    y3 = fftData.specData[30] / 3;
    effects.BresenhamLine(x1, y1, x2, y2, effects.ColorFromCurrentPalette(color1,255)); //  dma_display->color444(15, 0, 0)); // red

    x1 = fftData.specData[25] / 3;
    y1 = fftData.specData[30] / 3;
    x2 = fftData.specData[35] / 3;
    y2 = fftData.specData[40] / 3;
    effects.BresenhamLine(x1, y1, x2, y2, effects.ColorFromCurrentPalette(color2,255)); // green

    x1 = fftData.specData[45] / 3;
    y1 = fftData.specData[50] / 3;
    x2 = fftData.specData[55] / 3;
    y2 = fftData.specData[60] / 3;
    effects.BresenhamLine(x1, y1, x2, y2, effects.ColorFromCurrentPalette(color3,255)); // green



/*

    switch (caleidoscopeMode) {
      case 0:
        effects.Caleidoscope1();
        break;
      case 1:
        effects.Caleidoscope2();  // 2 = good
        break;
      case 2:
        effects.Expand(31,31,16,250);  // 1 = good
        break;
      default:
        break;
    }

*/

    //effects.SpiralStream(31, 15, 64, 128);        // for 64 pixel wide matrix!



    //effects.DimAll(250);




      return 0;
    }
};

#endif
