#include "recognizer.h"

void Recognizer::setRecognitionMethod(RecognitionMethod *recognitionMethod) {
    this->recognitionMethod = recognitionMethod;
}

void Recognizer::execute(Frame frame) {
    recognitionMethod->recognize(frame);
}

Recognizer::Recognizer() {

}

Recognizer::~Recognizer() {

}

