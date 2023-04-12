//
// Created by stani on 05.04.2023.
//

#ifndef PROJECT_TIME_H
#define PROJECT_TIME_H

#include "iostream"
#include "chrono"
using namespace  std;
using namespace std::chrono;

class Time {
public:

    high_resolution_clock::time_point startPoint;

    high_resolution_clock::time_point stopPoint;

    void start();
    void stop();
    long long returnTime();
};

#endif //PROJECT_TIME_H
