#include "calculatorfactory.h"

#include "../exceptions/calculatorexceptions.h"

Calculator * CalculatorFactory::createCalculator(DataStorage * storage) {
    QString calculatorName = storage->value<QString>("CURRENT_CALCULATOR");
    if (calculatorName == "HEAT_CAPACITY")
        return new HeatCapacityCalculator(storage);
    if (calculatorName == "HEATING_VALUE")
        return new HeatingValueCalculator(storage);
    if (calculatorName == "EXCESS_AIR_RATIO")
        return new ExcessAirRatioCalculator(storage);
    throw CalculatorNotFoundException(nullptr, calculatorName);
}
