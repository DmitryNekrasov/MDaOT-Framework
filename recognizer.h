#ifndef RECOGNIZER_H
#define RECOGNIZER_H
#include "frame.h"
#include "recognitionmethod.h"


class Recognizer
{
private:
    RecognitionMethod *recognitionMethod;

public:

    void setRecognitionMethod(RecognitionMethod *recognitionMethod);
    void execute(Frame frame);

    Recognizer();
    ~Recognizer();
};

#endif // RECOGNIZER_H
