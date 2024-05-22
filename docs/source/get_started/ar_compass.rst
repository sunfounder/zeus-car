.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

7. Compass
==========

In this project, Zeus Car will become a compass.
You will need to set a heading direction for it, and then no matter how you turn it, it will be facing there.

.. note::
    If electrical wires are present near the Zeus Car, the electromagnetic field will interfere with the operation of the qmc6310 module, thus changing the heading direction of the car.

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``7_compass.ino`` file under the path of ``zeus-car-main\examples\7_compass``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/672af146-1b45-46f6-b1d9-8ad9ecdcf8c0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

#. First let's calibrate the qmc6310 module.

    * Place the car on the ground (take care to stay away from ground with dense wires).
    * Press |ir_mute| and the car will rotate in place.
    * And stop until the magnetic field at that place is fully recorded. 
    * If it doesn't stop after more than 2 minutes, you can press |ir_power| to stop and then continue elsewhere.

#. Turn the car to the direction you want it to face and press |ir_play|. After that, whatever direction you turn it, it will slowly turn back to the set direction.

#. The magnetic fields on the ground and on the table are not the same and need to be recalibrated.