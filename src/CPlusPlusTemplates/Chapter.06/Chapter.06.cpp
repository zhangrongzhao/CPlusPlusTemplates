// Chapter.06.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include "basics\tracer.h"

int _tmain(int argc, _TCHAR* argv[])
{
	SortTracer inputs[] = {7,3,5,6,4,2,0,1,9,8};
	//SortTracer inputs[] = { 9,8,7,6,5,4,3,2,1,0};
	for (int i = 0; i < 10; ++i){
		std::cerr << inputs[i].val() << " ";
	}
	std::cerr << std::endl;

	//存取初始状态
	long created_at_start = SortTracer::creations();
	long max_live_at_start = SortTracer::max_live();
	long assigned_at_start = SortTracer::assignments();
	long compared_at_start = SortTracer::comparisons();

	//执行算法
	std::cerr << "------[Start std::sort()]----------\n";
	std::sort<>(&inputs[0],&inputs[9]+1);
	std::cerr << "------[End std::sort()]------------\n";

	for (int i = 0; i < 10; ++i){
		std::cerr << inputs[i].val() << " ";
	}
	std::cerr << "\n\n";

	//最后的输出报告
	std::cerr << "std::sort() of 10 SortTracer's "
		<< "was performed by:\n"
		<< SortTracer::creations() - created_at_start
		<< " temporary tracers\n"
		<< " up to "
		<< SortTracer::max_live()
		<< " tracers at the same time ("
		<< max_live_at_start << " before)\n"
		<< SortTracer::assignments() - assigned_at_start
		<< " assignments\n"
		<< SortTracer::comparisons() - compared_at_start
		<< " comparisons\n\n";
	return 0;
}

