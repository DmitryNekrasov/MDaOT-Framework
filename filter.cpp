#include "filter.h"


void Filter::performApplyFilter(Frame frame)
{
    filterHandler->onApplyFilter(frame);
}

FilterHandler *Filter::getFilterHandler() {
    return filterHandler;
}

void Filter::setFilterHandler(FilterHandler *handler) {
    filterHandler = handler;
}

Filter::~Filter() {

}
