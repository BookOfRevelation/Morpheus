#include "AdaptativeGaussianMorpher.h"
#include "PureCore.h"
#define TOLERANCE 0.01

AdaptativeGaussianMorpher::AdaptativeGaussianMorpher()
    : Morpher()
{

}


void AdaptativeGaussianMorpher::morph()
{

    for(int i = 0 ; i < currentImage.width() ; ++i)
    {
        for(int j =  0 ; j < currentImage.height() ; ++j)
        {
            QColor curCol = currentImage.pixelColor(i, j);
            QColor goalCol = goalImage.pixelColor(i, j);


            QColor newCol;
            float newRed;
            float newGreen;
            float newBlue;
            if(curCol.red() > goalCol.red()+TOLERANCE)
            {
               newRed = curCol.redF() - 0.002;
            }
            else if(curCol.red() < goalCol.red()-TOLERANCE)
            {
                newRed = curCol.redF() + 0.002;
            }


            if(curCol.green() > goalCol.green()+TOLERANCE)
            {
                newGreen = curCol.greenF() - 0.002;
            }
            else if(curCol.green() < goalCol.green()-TOLERANCE)
            {
                newGreen = curCol.greenF() + 0.002;
            }


            if(curCol.blue() > goalCol.blue()+TOLERANCE)
            {
                newBlue = curCol.blueF() - 0.002;
            }
            else if(curCol.blue() < goalCol.blue()-TOLERANCE)
            {
                newBlue = curCol.blueF() + 0.002;
            }

            if(newRed < 0)
            {
                newRed = 0;
            }
            if(newRed > 1)
            {
                newRed = 1;
            }
            if(newGreen < 0)
            {
                newGreen = 0;
            }
            if(newGreen > 1)
            {
                newGreen = 1;
            }
            if(newBlue < 0)
            {
                newBlue = 0;
            }
            if(newBlue > 1)
            {
                newBlue = 1;
            }
            newCol.setRgbF(newRed, newGreen, newBlue);
            currentImage.setPixelColor(i, j, newCol);
        }
    }

}
