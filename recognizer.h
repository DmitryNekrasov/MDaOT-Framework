#ifndef RECOGNIZER_H
#define RECOGNIZER_H
#include "frame.h"
#include "recognitionmethod.h"


/*!
 * Контекст стратегии распознавания объектов.
 * \brief The Recognizer class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class Recognizer
{
private:

    RecognitionMethod *recognitionMethod;

public:

    /*!
     * Изменяет метод распознавания объектов
     * \brief setRecognitionMethod
     * \param recognitionMethod Метод распознавания объектов
     */
    void setRecognitionMethod(RecognitionMethod *recognitionMethod);

    /*!
     * Выполняет распознавание объектов на кадре заданным методом
     * \brief execute
     * \param frame Кадр
     */
    void execute(Frame frame);

    /*!
     * Конструктор по умолчанию
     * \brief Recognizer
     */
    Recognizer();

    ~Recognizer();
};

#endif // RECOGNIZER_H
