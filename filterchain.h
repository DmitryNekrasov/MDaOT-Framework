#ifndef FILTERCHAIN_H
#define FILTERCHAIN_H
#include "filter.h"
#include "frame.h"


using namespace std;

class FilterChain
{
private:
    vector<Filter*> filters;

public:

    void add(Filter *filter);
    void clear();
    Frame apply(Frame startFrame);
    int getCount();
    vector<QString> getNames();
    Filter* getOnIndex(int index);
    void deleteOnIndex(int index);


    FilterChain();
    ~FilterChain();
};

#endif // FILTERCHAIN_H
