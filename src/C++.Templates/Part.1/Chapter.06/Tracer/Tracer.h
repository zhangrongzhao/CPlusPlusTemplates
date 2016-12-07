#include "../stdafx.h"

#ifndef SORT_TRACER_H
#define SORT_TRACER_H
class SortTracer{
private:
	int value;
	int generation;
	static long n_created;
	static long n_destroyed;
	static long n_assigned;
	static long n_compared;
	static long n_max_live;
	static void update_max_live(){
		if (n_created-n_destroyed>n_max_live){
			n_max_live = n_created - n_destroyed;
		}
	}
public:
	static long creation(){ return n_created; }
	static long destructions(){ return n_destroyed; }
	static long assignments(){ return n_assigned; }
	static long comparisons(){ return n_compared; }
	static long max_live(){ return n_max_live; }
public:
	SortTracer(int v):value(0),generation(1){
		n_created++;
		update_max_live();
		value = v;
	}

	SortTracer(SortTracer const& b):value(b.value),generation(b.generation+1){
		n_created++;
		update_max_live();
	}

	~SortTracer(){
		n_destroyed++;
		update_max_live();
	}

	SortTracer& operator=(SortTracer const& b){
		n_assigned++;
		value = b.value;
		return *this;
	}

	friend bool operator<(SortTracer const& a, SortTracer const& b){
		n_compared++;
        return a.val() < b.val();
	}

	int val() const{
		return value;
	}
};




#endif//SORT_TRACER_H