9. IR Obstacle
==============================

In this project, you will learn how to use the IR obstacle avoidance modules on both sides of the Zeus Car.

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``9_hc165_and_ir_obstacle.ino`` file under the path of ``zeus-car-main\examples\9_hc165_and_ir_obstacle``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3486be01-6b0e-4e84-86f6-9bdadafa1f48/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

    .. note::
        Do not unplug the USB in this step, because you need to check the data of the two obstacle avoidance modules on your computer.

#. Open the serial monitor and make sure the current baud rate is set to 115200, then you can view the printed data.

   * If both obstacle avoidance modules do not detect an obstacle, the serial monitor will print ``0, 0``.
   * Put your hand in front of one of the obstacle avoidance modules, it will print ``1, 0`` or ``0, 1``.

    .. image:: img/ar_serial.png

#. Calibrate the IR obstacle avoidance module.

    * Place an obstacle about 15cm away from the IR obstacle avoidance module.
    * On the module are two potentiometers, one to adjust the sending power and one to adjust the sending frequency. By adjusting these two potentiometers, you can adjust the detection distance.
    * Then you can adjust a potentiometer, and if at 15cm, the signal light on the module illuminates, the adjustment is successful; if it doesn't, adjust another potentiometer.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibrate the other obstacle avoidance module in the same way.