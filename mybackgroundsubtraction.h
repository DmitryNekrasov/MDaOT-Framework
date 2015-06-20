#ifndef MYBACKGROUNDSUBTRACTION_H
#define MYBACKGROUNDSUBTRACTION_H

#include "detectionmethod.h"


/*!
 * Реализация метода определения движения.
 * Метод вычитания фона.
 * \brief The MyBackgroundSubtraction class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class MyBackgroundSubtraction : public DetectionMethod
{
private:

    Frame background;
    Filter *grayscaleFilter;

public:

    /*!
     * Находит движущиеся объекты на видео
     * \brief detect
     * \param video Видео
     */
    virtual void detect(Video video);

    /*!
     * Инициализирует метод вычитания фона (цепочка фильтров, фон)
     * \brief init
     * \param video Видео
     */
    virtual void init(Video video);

    /*!
     * Конструктор по умолчанию
     * \brief MyBackgroundSubtraction
     */
    MyBackgroundSubtraction();

    /*!
     * Конструктор
     * \brief MyBackgroundSubtraction
     * \param handler Обработчик движения
     */
    MyBackgroundSubtraction(MovenmentHandler *handler);

    ~MyBackgroundSubtraction();
};

#endif // MYBACKGROUNDSUBTRACTION_H
