#ifndef OBSERVER_H
#define OBSERVER_H

#include "adapter.h"

#include "../Structures/log_signal.h"

class Observer
{
public:
    template <typename T>
    void submit(T* sender, LogSignal ev)
    {
        adapter.convert(sender, ev);
    }
private:
    Adapter adapter;
};

#endif // OBSERVER_H
