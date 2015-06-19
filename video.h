#ifndef VIDEO_H
#define VIDEO_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/opencv.hpp>
#include "frame.h"


/*!
 * Класс видеозахвата
 * \brief The Video class
 * \author Dmitry Nekrasov
 * \version 0.1
 * \date Июнь 2015
 */
class Video
{
private:
    cv::VideoCapture capture;
    bool isFileOpen;

public:

    /*!
     * Изменяет ширину кадра
     * \brief setWidth
     * \param width Ширина кадра
     */
    void setWidth(int width);

    /*!
     * Изменияет высоту кадра
     * \brief setHeight
     * \param height Высота кадра
     */
    void setHeight(int height);

    /*!
     * Проверяет видео на наличие следующего кадра
     * \brief hasNext
     * \return True, если в видео есть следующий кадр, иначе false
     */
    bool hasNext();

    /*!
     * Возвращает следующий кадр видео
     * \brief nextFrame
     * \return Следующий кадр
     */
    Frame nextFrame();

    /*!
     * Конструктор по умолчанию
     * \brief Video
     */
    Video();

    /*!
     * Конструктор
     * \brief Video
     * \param device Номер устройства ввода изображения
     */
    Video(int device);

    /*!
     * Конструктор
     * \brief Video
     * \param filePath Путь до видеофайла
     */
    Video(string filePath);

    ~Video();
};

#endif // VIDEO_H
