#include "filterchain.h"

void FilterChain::add(Filter *filter) {
    filters.push_back(filter);
}

void FilterChain::clear() {
    filters.clear();
}

Frame FilterChain::apply(Frame startFrame) {
    Filter* filter;
    for (vector<Filter*>::iterator it = filters.begin(); it != filters.end(); it++) {
        filter = *it;
        startFrame = filter->apply(startFrame);
    }
    return startFrame;
}

int FilterChain::getCount()
{
    return filters.size();
}

vector<QString> FilterChain::getNames()
{
    Filter* filter;
    vector<QString> names;
    for (vector<Filter*>::iterator it = filters.begin(); it != filters.end(); it++) {
        filter = *it;
        names.push_back(filter->getName());
    }
    return names;
}

FilterChain::FilterChain() {

}

FilterChain::~FilterChain() {

}

