#include "stdafx.h"

#ifndef SORT_TRACER_STATIC_MEMBER_H
#define SORT_TRACER_STATIC_MEMBER_H
#include "Tracer.h"

long SortTracer::n_created = 0;
long SortTracer::n_assigned = 0;
long SortTracer::n_destroyed = 0;
long SortTracer::n_compared = 0;
long SortTracer::n_max_live = 0;

#endif//SORT_TRACER_STATIC_MEMBER_H
