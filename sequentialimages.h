#ifndef SEQUENTIALIMAGES_H
#define SEQUENTIALIMAGES_H
#include "detectionmethod.h"


/*!
 * Реализация метода определения движения.
 * Метод последовательных изображений.
 * \brief The SequentialImages class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class SequentialImages: public DetectionMethod
{
private:

    Filter *grayscaleFilter;
    void processingFrame(Video &video);

public:

    /*!
     * Находит движущиеся объекты на видео
     * \brief detect
     * \param video Видео
     */
    virtual void detect(Video video);

    /*!
     * Инициализирует метод последовательных изображений (цепочка фильтров)
     * \brief init
     * \param video Видео
     */
    virtual void init(Video video);

    /*!
     * Конструктор по умолчанию
     * \brief SequentialImages
     */
    SequentialImages();

    /*!
     * Конструктор
     * \brief SequentialImages
     * \param handler Обработчик двидения
     */
    SequentialImages(MovenmentHandler *handler);

    ~SequentialImages();
};

#endif // SEQUENTIALIMAGES_H
