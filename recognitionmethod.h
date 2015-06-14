#ifndef RECOGNITIONMETHOD_H
#define RECOGNITIONMETHOD_H
#include "frame.h"


class RecognitionMethod
{   
public:

    virtual void recognize(Frame frame) = 0;

    ~RecognitionMethod();
};

#endif // RECOGNITIONMETHOD_H
