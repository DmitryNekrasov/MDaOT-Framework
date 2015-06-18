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

Filter *FilterChain::getOnIndex(int index)
{
    return filters.at(index);
}

void FilterChain::setOnIndex(int index, Filter *filter)
{
    filters.at(index) = filter;
}

void FilterChain::deleteOnIndex(int index)
{
    filters.erase(filters.begin() + index);
}

void FilterChain::swapFilters(int i, int j)
{
    Filter *tmp = filters.at(i);
    filters.at(i) = filters.at(j);
    filters.at(j) = tmp;
}

FilterChain::FilterChain() {

}

FilterChain::~FilterChain() {

}

