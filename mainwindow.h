#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QInputDialog>

#include "video.h"
#include "detector.h"
#include "movenmenthandler.h"
#include "mymovenmenthandler.h"
#include "detectionmethod.h";
#include "sequentialimages.h"
#include "mybackgroundsubtraction.h"
#include "filterdialog.h"

#define BINARY_CODE 1
#define BLUR_CODE 2
#define MEDIAN_CODE 3
#define GRAYSCALE_CODE 4

#define BINARY_NAME "Binary"
#define BLUR_NAME "Blur"
#define MEDIAN_NAME "Median"
#define GRAYSCALE_NAME "Grayscale"


namespace Ui {
class MainWindow;
}


/*!
 * Главное окно приложения
 * \brief The MainWindow class
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*!
     * Конструктор
     * \brief MainWindow
     * \param parent Родительский виджет
     */
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    /*!
     * Изменяет изображение, выводимое на форму
     * \brief setQimg
     * \param img Изображение
     */
    void setQimg(QImage *img);

    /*!
     * Проверяет, нужно ли отображать контуры обнаруженных объектов
     * \brief isOutMask
     * \return True, если нужно отображать контуры обнаруженных объектов, иначе false
     */
    bool isOutMask();

    /*!
     * Проверяет, нужно ли выделять обнаруженные объекты прямоугольником
     * \brief isOutRect
     * \return  True, если нужно ли выделять обнаруженные объекты прямоугольником, иначе false
     */
    bool isOutRect();

protected:

    /*!
     * Событие на отрисовку изображения на форме
     * \brief paintEvent
     */
    void paintEvent(QPaintEvent *);

private:

    Ui::MainWindow *ui;
    QImage *qimg;
    Video video;
    Detector detector;
    MovenmentHandler *myMH;
    DetectionMethod *si, *bs;
    QTimer *timer;
    QString pathToPreset = "/Users/ScanNorOne/Desktop/preset.fchain";
    vector<FilterChain> preset;
    bool outRect = false;
    bool outMask = false;

    /*!
     * Обновляет содержимое списка filterNames, который содержит имена фильтров
     * \brief refreshList
     */
    void refreshList();

    /*!
     * Загружает из файла пресеты цепочек фильтров
     * \brief loadPreset
     */
    void loadPreset();

    /*!
     * Обновляет список пресетов цепочек фильтров
     * \brief refreshPresetList
     */
    void refreshPresetList();

    /*!
     * Записывает пресеты в файл
     * \brief writeChainInFile
     */
    void writeChainInFile();

signals:

    /*!
     * Сигнал на переисовку изображения
     * \brief repaintSignal
     */
    void repaintSignal();

private slots:

    /*!
     * Запускает детектор на выполнение
     * \brief sl
     */
    void sl();

    /*!
     * При нажатии на кнопку старт/пауза ставит видео на паузу, если оно воспроизводится,
     * иначе продолжает воспроизведение.
     * \brief on_startPauseButton_clicked
     */
    void on_startPauseButton_clicked();

    /*!
     * При двойном клике по фильтру в списке фильтров открывает окно DialogFilter,
     * в котором отображается кадр после применения цепочки до текущего фильтра,
     * а также интерфейс для редактирования фильтра.
     * \brief on_listName_doubleClicked
     * \param index Индекс выделенной строки
     */
    void on_listName_doubleClicked(const QModelIndex &index);

    /*!
     * При нажатии на кнопку "Закрыть" закрывает приложение
     * \brief on_closeButton_clicked
     */
    void on_closeButton_clicked();

    /*!
     * При смене выделенной строки в списке фильтров меняет доступность к кнопкам
     * перемещения фильтров в зависимости от индекса строки.
     * \brief on_listName_currentRowChanged
     * \param currentRow Индекс выделенной строки
     */
    void on_listName_currentRowChanged(int currentRow);

    /*!
     * При нажатии на кнопку добавления фильтра в список фильтров добавляется новый фильтр,
     * указанный в filterCombo
     * \brief on_addFilterButton_clicked
     */
    void on_addFilterButton_clicked();

    /*!
     * При нажатии на кнопку удаления фильтра из списка фильтров удаляется выбранный.
     * \brief on_deleteFilterButton_clicked
     */
    void on_deleteFilterButton_clicked();

    /*!
     * При нажатии на кнопку с изображением стрелочки вниз выделенный фильтр в списке фильтров
     * меняется местами с нижестоящим фильтром. Если выделенный фильтр является последним
     * в цепочке, то кнопка не доступна для нажатия.
     * \brief on_bottomButton_clicked
     */
    void on_bottomButton_clicked();

    /*!
     * При нажатии на кнопку с изображением стрелочки вверх выделенный фильтр в списке фильтров
     * меняется местами с вышестоящим фильтром. Если выделенный фильтр является первым
     * в цепочке, то кнопка не доступна для нажатия.
     * \brief on_topButton_clicked
     */
    void on_topButton_clicked();

    /*!
     * При нажатии на recCheckBox выводит прямоугольники, ограничивающие обнаруженные объекты,
     * если recCheckBox is checked, иначе прекращает выводить прямоугольники.
     * \brief on_recCheckBox_clicked
     */
    void on_recCheckBox_clicked();

    /*!
     * При нажатии на pixelCheckBox выводит контуры обнаруженных объектов, если
     * pixelCheckBox is checked, иначе прекращает выводить контуры
     * \brief on_pixelCheckBox_clicked
     */
    void on_pixelCheckBox_clicked();

    /*!
     * При нажатии на bsRadio изменяет метод обнаружения движения на метод вычитания фона
     * \brief on_bsRadio_clicked
     */
    void on_bsRadio_clicked();

    /*!
     * При нажатии на siRadio изменяет метод обнаружения движения на метод
     * последовательных изображений
     * \brief on_siRadio_clicked
     */
    void on_siRadio_clicked();

    /*!
     * При нажатии на кнопку "Очистить цепочку" очищается цепочка фильтров у текущего
     * метода обнаружения движения.
     * \brief on_clearChainButton_clicked
     */
    void on_clearChainButton_clicked();

    /*!
     * При нажатии на кнопку "Применить" в блоке пресетов, выбранная в chainCombo цепочка
     * применяется для текущего метода обнаружения движения.
     * \brief on_applyChainButton_clicked
     */
    void on_applyChainButton_clicked();

    /*!
     * При нажатии на кнопку удаления в блоке пресетов, выбранная в chainCombo цепочка удаляется
     * \brief on_deleteChainButton_clicked
     */
    void on_deleteChainButton_clicked();

    /*!
     * Вызывается при смене текущего индекса в chainCombo.
     * Если количество цепочек в пресетах == 0, то индекс текущей строки
     * становится < 0, и кнопки применения и удаления цепочки становятся
     * недоступными.
     * \brief on_chainCombo_currentIndexChanged
     * \param index
     */
    void on_chainCombo_currentIndexChanged(int index);

    /*!
     * При нажатии на кнопку добавления цепочки в пресеты вызывается диалоговое окно,
     * в котором предлагается ввести имя новой цепочки. При нажатии на кнопку OK в диалоговом
     * окне цепочка сохраняется с этим именем в пресетах.
     * \brief on_addChainButton_clicked
     */
    void on_addChainButton_clicked();

};


#endif // MAINWINDOW_H
