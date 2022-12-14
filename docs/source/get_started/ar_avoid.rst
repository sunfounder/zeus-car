
11. Obstacle Avoidance
================================

In this project, the Zeus car will move forward automatically, and two obstacle avoidance modules and an ultrasonic module will prevent it from hitting obstacles.


**How to do?**

#. First check that the **Upload** button is toggled to the side near the motor port.

#. Open the ``11_obstacle_avoid.ino`` file under the path of ``zeus-car-main\examples\11_obstacle_avoid``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/520af1d6-4ef2-4804-a4a9-f6aa92985258/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

    * Zeus car will move forward.
    * An ultrasonic module detects obstacles in front, if detected, the car turns left.
    * When the left obstacle avoidance module detects an obstacle, the car turns right, and when the right obstacle avoidance module detects an obstacle, the car turns left.

.. note::
    Before use, you need to adjust the detection distance of the two obstacle avoidance modules to 15CM, the steps are as follows

    * Place an obstacle about 15cm away from the IR obstacle avoidance module.
    * On the module are two potentiometers, one to adjust the sending power and one to adjust the sending frequency. By adjusting these two potentiometers, you can adjust the detection distance.
    * Then you can adjust a potentiometer, and if at 15cm, the signal light on the module illuminates, the adjustment is successful; if it doesn't, adjust another potentiometer.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibrate the other obstacle avoidance module in the same way.