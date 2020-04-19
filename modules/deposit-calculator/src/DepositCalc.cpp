// Copyright 2020 Mikhail Zakharov

#include "include/DepositCalc.h"
#include <iostream>

DepositCalc::DepositCalc(int _depositAmount, int _period, int _rate)
    :depositAmount(_depositAmount), period(_period), rate(_rate) {}

int DepositCalc::getDepositAmount()const {
    return depositAmount;
}

int DepositCalc::getPeriod() {
    return period;
}

int DepositCalc::getRate()const {
    return rate;
}

int DepositCalc::getDepositWithRate()const {
    return depositWithRate;
}

int DepositCalc::getInterestCharges()const {
    return interestCharges;
}

void DepositCalc::setDepositAmount(const int& depositAmount) {
    this->depositAmount = depositAmount;
}

void DepositCalc::setPeriod(const int& period) {
    if (period == 0)
        throw "PeriodIsZero";
    if (period > 1826)
        throw "PeriodMoreThan1826";
    this->period = period;
}

void DepositCalc::setRate(const int& rate) {
    this->rate = rate;
}

void DepositCalc::calc() {
    depositWithRate = depositAmount + ((depositAmount * rate * period)
        / (366 * 100));
    interestCharges = depositWithRate - depositAmount;
}