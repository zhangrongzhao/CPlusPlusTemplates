#include "../stdafx.h"

#ifndef FILE_FUNCTION_H
#define FILE_FUNCTION_H

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void file_it(ostream& outputStream,double fo,const double fe[],int n);
const int LIMIT = 5;

void file_it(ostream& outputStream,double fo,const double fe[],int n){
	ios_base::fmtflags initial;
	initial = outputStream.setf(ios_base::fixed);//save initial formatting state.
	outputStream.precision(0);
	outputStream << "Focal length of objective:" << fo << "mm\n";
	outputStream.setf(ios::showpoint);
	outputStream.precision(1);
	outputStream.width(12);
	outputStream << "f.1.yeypiece";
	outputStream.width(15);
	outputStream << "manification" << endl;
	for (int i = 0; i < n;i++){
		outputStream.width(12);
		outputStream << fe[i];
		outputStream.width(15);
		outputStream << int(fo / fe[i] + 0.5) << endl;
	}
	outputStream.setf(initial);//restore initial formatting state.
}

void test_file_it(){
	ofstream outputFileStream;
	const char* fileName = "ep-data.txt";
	outputFileStream.open(fileName);
	if (!outputFileStream.is_open()){
		cout << "Can't open " << fileName << ". Bye.\n";
		exit(EXIT_FAILURE);
	}

	double objective; 
	cout << "Enter the focal length of your telescope objective in mm:";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal lengths,in mm,of " << LIMIT << "eyepieces:\n";
	for (int i = 0; i < LIMIT;i++){
		cout << "Eyepiece #" << i + 1 << ":";
		cin >> eps[i];
	}

	file_it(outputFileStream,objective,eps,LIMIT);
	file_it(cout,objective,eps,LIMIT);
	cout << "Done\n";
}
#endif//FILE_FUNCTION_H