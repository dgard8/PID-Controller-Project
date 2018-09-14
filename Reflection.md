# PID Controller Project
Self-Driving Car Engineer Nanodegree Program

---

[PController]: ./reflection_images/Pcontroller.png "PControl"
[PDController]: ./reflection_images/PDcontroller.png "PDControl"
[PDControllerOffset]: ./reflection_images/PDcontrollerOffset.png "PDControlOffset"
[PIDController]: ./reflection_images/PIDcontroller.png "PIDControl"

## Proportional

The P part of the PID controller adds to the steering angle based on the value of the cross-track error. This means when we are farther away from the target the car turns sharper towards it. However, this tends to overshoot and then oscillate around the target, as seen below.

![P Controller][PController]

## Derivative

The D part of the PID controller adds to the steering angle based on how the cross-track error is changing. If the cross-track error is changing quickly, then this term makes the car turn less sharply. The benefit of this term is that it reduces oscillations and allows the car to actually stay at the target location, as seen below.

![PD Controller][PDController]

This controller appears to work well, and it does as long as there isn't any bias in the steering controlls. But, many cars have misalignment in the tires which make it so the steering angle of the wheel doesn't move the car exactly as expected. The result is that the car settles on a location that is offset from the actual desired location, as seen below.

![PD Controller Offset][PDControllerOffset]

## Integral

To account for this potential bias we introduce the I part of the PID controller. This term adds to the steering angle based on the sum of all the previous cross-track errors. This means that if the car is consistently above or below the target location the car will steer towards the target. The cost of this benefit is that when there isn't a steering bias the car will take longer to settle to the target location, as seen below.

![PID Controller][PIDController]

## Determing the values

The key to a successful PID controller is combining the P, I, and D terms in the right ratio to get the desired results. If P or I are too large then the car will oscillate unnecessarily, if they are too small they won't reach the target location. If D is too large it can dampen the turn too quickly.

To choose the correct values for this project I started with the values we found via twiddle in the preceding lesson. The car models are different, so the values aren't the best for this project, but they provided a good starting point. I then manually played with the values to get the desired result. I noticed the car was oscillating a lot, so I increased the D term and decreased the P term. This produced a result that makes it sucessfully around the track. The car does still oscillate a little, but not as much as before.


