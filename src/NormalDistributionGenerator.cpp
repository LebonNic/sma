/**
 * @file NormalDistributionGenerator.cpp
 * @author Antoine Colmard
 * @author Nicolas Prugne
 * @brief Contient le code source lié à la classe NormalDistributionGenerator
 */

#include "NormalDistributionGenerator.h"

/**
 * @brief NormalDistributionGenerator::NormalDistributionGenerator Constructeur de classe
 * @param expectation Espérance de la loi normale
 * @param standard_deviation Ecart-type de la loi normale
 * @param seed Germe pour le générateur aléatoire
 */
NormalDistributionGenerator::NormalDistributionGenerator(double expectation, double standard_deviation, unsigned int seed) :
	expectation_(expectation), standard_deviation_(standard_deviation) {
	mt_.init_genrand(seed);
}

/**
 * @brief NormalDistributionGenerator::~NormalDistributionGenerator Destructeur
 */
NormalDistributionGenerator::~NormalDistributionGenerator() {}

/**
 * @brief NormalDistributionGenerator::setExpectation Change l'espérance de la loi normale
 * @param expectation Espérance de la loi normale
 */
void NormalDistributionGenerator::setExpectation(double expectation) {
	expectation_ = expectation;
}

/**
 * @brief NormalDistributionGenerator::setStandardDeviation Change l'écart-type de la loi normale
 * @param standard_deviation Ecart-type de la loi normale
 */
void NormalDistributionGenerator::setStandardDeviation(double standard_deviation) {
	standard_deviation_ = standard_deviation;
}

/**
 * @brief NormalDistributionGenerator::setSeed Change le germe du générateur de la loi normale
 * @param seed Germe du générateur aléatoire de la loi normale
 */
void NormalDistributionGenerator::setSeed(unsigned int seed) {
	mt_.init_genrand(seed);
}

/**
 * @brief NormalDistributionGenerator::getValue Obtient une valeur générée selon la loi normale
 * @return Valeur générée selon la loi normale
 */
double NormalDistributionGenerator::getValue (void) {
	double u = mt_.genrand_real1();
	double v = mt_.genrand_real1();
	double x = sqrt(-2.0*log(u))*cos(2*M_PI*v);

	return x*standard_deviation_ + expectation_;
}

/**
 * @brief NormalDistributionGenerator::getPair Obtient une paire de valeur générée selon la loi normale
 * @return Paire de valeur générée selon la loi normale
 */
std::pair<double,double> NormalDistributionGenerator::getPair(void) {
	double u = mt_.genrand_real1();
	double v = mt_.genrand_real1();
	double x = (sqrt(-2.0*log(u))*cos(2*M_PI*v))*standard_deviation_ + expectation_;
	double y = (sqrt(-2.0*log(u))*sin(2*M_PI*v))*standard_deviation_ + expectation_;

	return std::pair<double,double>(x,y);

}
