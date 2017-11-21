#ifndef ADAPTATIVEGAUSSIANMORPHER_H
#define ADAPTATIVEGAUSSIANMORPHER_H

#include "Morpher.h"

class AdaptativeGaussianMorpher : public Morpher
{
public:
    AdaptativeGaussianMorpher();

protected:
    void morph() override;


};

#endif // ADAPTATIVEGAUSSIANMORPHER_H
