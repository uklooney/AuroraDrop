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

#ifndef PatternStaticBounce_H

class PatternStaticBounce : public Drawable {
private:
    static const int count = AVAILABLE_BOID_COUNT;
    PVector gravity = PVector(0, 0.0125);
    //PVector gravity = PVector(0, 0.125);

    float startVelocityScale;

public:
    PatternStaticBounce() {
      name = (char *)"Bounce";
      id = "B";
      enabled = true;
    }

    // ------------------------ START ------------------------
    void start(uint8_t _pattern) {
        startVelocityScale = (float)random(10,20) / 1000.0;

        unsigned int colorWidth = 256 / count;
        for (int i = 0; i < count; i++) {
            Boid boid = Boid(i, 0);
            boid.velocity.x = 0;
            boid.velocity.y = i * -startVelocityScale;  // was -0.01, now random betwee -0.01 and -0.02
            boid.colorIndex = colorWidth * i;
            boid.maxforce = 10;
            boid.maxspeed = 10;
            staticBoids[_pattern][i] = boid;
        }
    }

    // -------------------------- DRAW FRAME -------------------
    unsigned int drawFrame(uint8_t _pattern, uint8_t _total) {
        // dim all pixels on the display

        //effects.DimAll(250);

        //effects.DimAll(170); effects.ShowFrame();

        for (int i = 0; i < count; i++) {
            Boid boid = staticBoids[_pattern][i];

            boid.applyForce(gravity);

            boid.update();

            //if (!serialData.noAudio)
                effects.drawBackgroundFastLEDPixelCRGB(boid.location.x, boid.location.y, effects.ColorFromCurrentPalette(boid.colorIndex));

            if (boid.location.y >= MATRIX_HEIGHT - 1) {
                boid.location.y = MATRIX_HEIGHT - 1;
                boid.velocity.y *= -1.0;
            }

            staticBoids[_pattern][i] = boid;
        }

        return 0;  // 15
    }
};

#endif
