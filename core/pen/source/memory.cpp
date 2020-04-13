// memory.cpp
// Copyright 2014 - 2019 Alex Dixon.
// License: https://github.com/polymonster/pmtech/blob/master/license.md

#include "memory.h"

// C++ standard says these must be in cpp file and not inline in header ;_;

using namespace pen;

void* operator new(std::size_t n, const std::nothrow_t& nothrow_value) THROW_NO_EXCEPT
{
    return memory_alloc(n);
}

void* operator new(size_t n) THROW_BAD_ALLOC
{
    return memory_alloc(n);
}

void operator delete(void* p)THROW_NO_EXCEPT
{
    memory_free(p);
}

void* operator new[](size_t n) THROW_BAD_ALLOC
{
    return memory_alloc(n);
}
void operator delete[](void* p) THROW_NO_EXCEPT
{
    memory_free(p);
}
