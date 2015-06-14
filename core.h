#ifndef CORE_H
#define CORE_H
#include "video.h"
#include "detector.h"
#include "detectionmethod.h"
#include "sequentialimages.h"
#include "backgroundsubtraction.h"
#include "movenmenthandler.h"
#include "mymovenmenthandler.h"


class Core
{
private:

    static Core* instance;

    Core();

public:

    static Core* getInstance();
    void start();

    ~Core();
};

#endif // CORE_H
