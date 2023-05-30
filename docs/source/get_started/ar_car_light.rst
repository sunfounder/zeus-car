6. Car Light
==========================


In this project, you will be able to use the remote control to control the RGB light strips on the bottom of the car, making them display different colors.


**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``6_car_light.ino`` file under the path of ``zeus-car-main\examples\6_car_light``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/79b6c0e5-a788-4d67-bb44-7e7122c521ab/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

#. Now you can use the numbers 1 to 9 on the remote control to control the car to light up different colors, press 0 to turn off, press |ir_return| to let the car perform a color cycle. Key 1 to 9 corresponding to the color is: red, orange, yellow, green, cyan, blue, purple, pink, white. 
