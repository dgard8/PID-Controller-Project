#include "PID.h"

#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  
  prev_cte = 0;
  total_cte = 0;
}

double PID::get_steer_value(double cte){
  total_cte += cte;
  double steer = -Kp * cte - Kd * (cte - prev_cte) - Ki * total_cte;
  prev_cte = cte;
  return steer;
}