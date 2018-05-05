/*
 * findRepeatedNumber.h
 *
 *  Created on: 05-May-2018
 *      Author: abhinema
 */

#ifndef FINDREPEATEDNUMBER_H_
#define FINDREPEATEDNUMBER_H_

#include <iostream>
#include <cstdlib>
#include <map>

template<class T>
T findRepeateNumber(vector<T> & data){
	T val = 0;
	std::map<T, int> num;

	for(const auto& e: data){
		++num[e];
	}
	for(const auto& e: num){
		if(e.second == 2){
			val = e.first;
			break;
		}
	}
return val;
}

string findRepeateNumber(vector<string> & data){
	string val;
	std::map<string, int> num;

	for(const auto& e: data){
		++num[e];
	}
	for(const auto& e: num){
		if(e.second == 2){
			val = e.first;
			break;
		}
	}
return val;
}

#endif  /* FINDREPEATEDNUMBER_H_ */
/* End of File */
