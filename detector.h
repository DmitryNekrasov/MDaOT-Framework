#ifndef DETECTOR_H
#define DETECTOR_H
#include "video.h"
#include "detectionmethod.h"


/*!
 * Контекст стратегии определения движения.
 * \brief The Detector class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class Detector
{
protected:

    DetectionMethod* detectionMethod;

public:

    /*!
     * Изменяет метод определения движения
     * \brief setDetectionMethod
     * \param detectionMethod Метод определения движения
     */
    void setDetectionMethod(DetectionMethod* detectionMethod);

    /*!
     * Возвращает метод определения движения
     * \brief getDetectionMethod
     * \return Метод определения движения
     */
    DetectionMethod* getDetectionMethod();

    /*!
     * Выполняет определение движения заданным методом
     * \brief execute
     * \param video Видео
     */
    void execute(Video video);

    /*!
     * Вызывает инициализацию метода определения движения
     * \brief startDetector
     * \param video Видео
     */
    void startDetector(Video video);

    /*!
     * Конструктор по умолчанию
     * \brief Detector
     */
    Detector();

    ~Detector();
};

#endif // DETECTOR_H
