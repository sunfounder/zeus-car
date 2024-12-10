9. Advanced Obstacle Avoidance and Following
============================================================

In previous lessons, we learned how to use the ultrasonic sensor for obstacle avoidance (Lesson 5) and how to use two infrared (IR) sensors to detect side obstacles (Lesson 6). However, each method alone has limitations: the ultrasonic sensor can only detect obstacles directly in front of the Zeus Car, and the IR sensors can only detect obstacles on the sides.

In this lesson, we will combine the ultrasonic sensor with the two IR sensors to achieve all-around obstacle avoidance. Additionally, we'll enable the Zeus Car to follow an object or person, like a robotic pet that moves with you.

You Will Learn
------------------------

* How to integrate the ultrasonic sensor with two IR sensors for comprehensive obstacle avoidance.
* How to program the Zeus Car to follow an object using sensor data.
* How to modify and optimize existing scripts to implement new functionalities.

Advanced Obstacle Avoidance
--------------------------------

By combining the ultrasonic sensor and the two IR sensors, your Zeus Car can intelligently avoid obstacles in all directions.

* **Ultrasonic Sensor**: Detects obstacles in front of the car. If an obstacle is detected within a set distance (e.g., less than 20 cm), the car will stop, move backward for a short distance, and then turn to avoid the obstacle.
* **Left IR Sensor**: Detects obstacles on the left side. If an obstacle is detected on the left, the car will turn right to avoid it.
* **Right IR Sensor**: Detects obstacles on the right side. If an obstacle is detected on the right, the car will turn left to avoid it.

Here are the steps to implement advanced obstacle avoidance:

1. Open the script you saved in Lesson 6, :ref:`sc6_avoid_ir` part. Rename the script to something like ``7. Advanced Obstacle Avoidance`` and save it.

   .. image:: img/9_code_avoid_new_name.png
        :width: 700

2. Modify the script to use the ultrasonic sensor:

   * Remove the conditions that check for obstacles using the IR sensors.
   * Add a new condition using the ultrasonic sensor to detect obstacles directly in front of the car.
   * Set the detection distance to 20 cm. If an obstacle is detected within this range, perform the following actions:
     
     * **Stop moving**.
     * **Move backward** for 1 second.
     * **Turn clockwise** (right) for 0.3 seconds.
     * **Resume moving forward**.

   .. image:: img/9_code_avoid_ultrasonic.png

3. Keep the existing script for the left IR sensor.

   .. image:: img/8_code_avoid_left_ir.png
         :width: 700


4. Similarly, keep the existing script for the right IR sensor.

   .. image:: img/8_code_avoid_right_ir.png

5. Keep the script that moves the Zeus Car forward when no obstacles are detected. Include a small delay to prevent the script from running too quickly, which can cause performance issues.

   .. image:: img/7_code_avoid_wait.png

6. Test the script:

   * Run the script and place obstacles in front of and on the sides of the Zeus Car.
   * Observe whether the car avoids obstacles as expected.
   * Make adjustments to sensor thresholds or timing if necessary.

Implementing the Following Function
--------------------------------------------

In addition to obstacle avoidance, you can enhance your Zeus Car by enabling it to follow an object or person using the ultrasonic and IR sensors. This feature allows the car to maintain a set distance from a target, creating interactive and dynamic behaviors.

Here are the steps to implement the following function:

#. When the green flag is clicked, set the Zeus Car's speed to **50%**.

   .. image:: img/7_code_avoid_move.png

#. Use a Forever loop to continuously check sensors.

   .. image:: img/8_code_avoid_forever.png

#. Using the ultrasonic sensor to detect the target in front of the car. If the ultrasonic sensor detects the target within the range between 5 cm and 20 cm, perform the following action:
     
   * Move forward at 0 degrees direction.

   .. image:: img/9_code_follow_move.png
      :width: 700

#. If the left IR sensor detects the target (status equals 1):

   * Stop moving forward.
   * Turn counterclockwise (left) to adjust direction toward the target.
   * Until the right sensor no longer detects an obstacle.
   * Stop turning.

   .. image:: img/9_code_follow_left_ir.png

#. If the right IR sensor detects the target (status equals 1):

   * Stop moving forward.
   * Turn clockwise (right) to adjust direction toward the target.
   * Until the right sensor no longer detects an obstacle.
   * Stop turning.

   .. image:: img/9_code_follow_right.png

#. If neither the ultrasonic sensor detects the target within the specified range nor the IR sensors detect the target, perform the following action:
     
   * Stop moving.

   .. image:: img/9_code_follow_else.png

#. Include a short wait time at the end of the forever loop to prevent the script from running too fast, which can cause issues with sensor readings and command processing.

   .. image:: img/9_code_follow_wait.png
   
#. Test the script:

   * Run the script and move in front of the Zeus Car.
   * Observe whether the car follows you, adjusting its direction as you move left or right.
   * Make adjustments to sensor thresholds or turning speeds if necessary.


**Summary**

In this lesson, you learned how to:

* **Integrate multiple sensors**: Combining the ultrasonic sensor with two IR sensors to achieve comprehensive obstacle avoidance.
* **Implement advanced obstacle avoidance**: Program the Zeus Car to intelligently avoid obstacles in all directions.
* **Create a following behavior**: Enable the Zeus Car to follow an object or person by maintaining a set distance and adjusting direction.

By enhancing your Zeus Car with these features, you've taken a significant step toward creating more interactive and autonomous robotic behaviors. Continue experimenting with different sensor configurations and programming techniques to further improve your projects.

