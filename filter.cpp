#include "filter.h"


void Filter::performApplyFilter(Frame frame) {
    filterHandler->onApplyFilter(frame);
}

Filter::~Filter() {

}
