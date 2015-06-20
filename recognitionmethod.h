#ifndef RECOGNITIONMETHOD_H
#define RECOGNITIONMETHOD_H
#include "frame.h"


/*!
 * Абстрактный класс стратегии.
 * Метод распознавания объектов.
 * \brief The RecognitionMethod class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class RecognitionMethod
{   
public:

    /*!
     * Распознаёт объекты на кадре
     * \brief recognize
     * \param frame Кадр
     */
    virtual void recognize(Frame frame) = 0;

    ~RecognitionMethod();
};

#endif // RECOGNITIONMETHOD_H
