10. Ultrasonic
==============================

In this project, you will learn how to read the distance detected by the ultrasonic module.

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``10_ultrasonic.ino`` file under the path of ``zeus-car-main\examples\10_ultrasonic``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b3c702d7-2d4e-48fe-8d8d-7d20f70c9e45/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

    .. note::
        Do not unplug the USB in this step, because you need to check the data of the Ultrasonic module on your computer.

#. Open the serial monitor and make sure the current baud rate is set to 115200. It is recommended to click on the **Toggle Autoscroll** icon so that you can see the latest printed data.

   * You can view the printed data like ``distance: 21.11  is_obstacle: 0``.
   * If the distance of the obstacle ahead is within 20cm, ``is_obstacle: 0`` will become ``is_obstacle: 1``.

    .. image:: img/ar_ultrasonic.png

