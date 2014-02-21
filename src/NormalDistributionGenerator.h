/**
 * @file NormalDistributionGenerator.h
 * @author Antoine Colmard
 * @author Nicolas Prugne
 * @brief Contient la déclaration de la classe NormalDistributionGenerator
 */

#ifndef NORMALDISTRIBUTIONGENERATOR_H_
#define NORMALDISTRIBUTIONGENERATOR_H_

#include <utility>
#define _USE_MATH_DEFINES
#include <cmath>
#include "MersenneTwister.h"

/**
 * @brief Classe permettant de simuler une distribution normale
 */
class NormalDistributionGenerator {
private:
	double expectation_;
	double standard_deviation_;
	MersenneTwister mt_;
public:

	NormalDistributionGenerator(double,double,unsigned int);
	~NormalDistributionGenerator();

	void setExpectation(double);
	void setStandardDeviation(double);
	void setSeed(unsigned int);
	double getValue(void);
	std::pair<double,double> getPair(void);
};

#endif /* NORMALDISTRIBUTIONGENERATOR_H_ */
