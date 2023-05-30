

12. Follow
====================

In this project, the same two obstacle avoidance modules and an ultrasonic module will be used, but not for obstacle avoidance, but to follow you.

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``12_follow.ino`` file under the path of ``zeus-car-main\examples\12_follow``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3fd83bdc-5457-4532-9da1-126fb7092a11/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

#. In this case, the Zeus Car will not move if there is nothing in front of it. Whenever you move forward, it will follow you if you stand about 20cm away from it.