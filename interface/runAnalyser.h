/*
 * runAnalyser.h
 *
 *  Created on: 24 Aug 2016
 *      Author: jkiesele
 */

#ifndef runAnalyser_H_
#define runAnalyser_H_

#include "interface/basicAnalyzer.h"
#include "interface/sampleCollection.h"
#include "classes/DelphesClasses.h"


class runAnalyser: public d_ana::basicAnalyzer{
public:
	runAnalyser():d_ana::basicAnalyzer(){}
	~runAnalyser(){}


private:
	void analyze(size_t id);

	void postProcess();
};





#endif /* runAnalyser_H_ */
