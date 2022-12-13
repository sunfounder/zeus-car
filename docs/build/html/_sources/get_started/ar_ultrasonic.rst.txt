10. Ultrasonic
==============================

In this project, you will learn how to read the distance detected by the ultrasonic module.

**How to do?**

#. First check that the **Upload** button is toggled to the side near the motor port.

#. Open the ``10_ultrasonic.ino`` file under the path of ``zeus-car-main\examples\10_ultrasonic``. Or copy this code into Arduino IDE.

    <代码>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

    .. note::
        Do not unplug the USB in this step, because you need to check the data of the Ultrasonic module on your computer.

#. Open the serial monitor and make sure the current baud rate is set to 115200. It is recommended to click on the **Toggle Autoscroll** icon so that you can see the latest printed data.

   * You can view the printed data like ``distance: 21.11  is_obstacle: 0``.
   * If the distance of the obstacle ahead is within 20cm, ``is_obstacle: 0`` will become ``is_obstacle: 1``.

    .. image:: img/ar_ultrasonic.png

