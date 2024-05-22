.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

2. Omni Move
==========================
In this project, you will learn how to move the Zeus Car to 0, 45, 90, 135, 180, 225, 270, and 315 degrees.

If you ignore the friction on the ground and the structural tolerances, its path should be an octagon and eventually return to the origin.

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``2_omni_move.ino`` file under the path of ``zeus-car-main\examples\2_omni_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/2425f280-5bd4-4e49-bb2e-220d1f4f867b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Select the correct board and port, then click the **Upload** button.

    .. note::
        * If you get a "Compilation error: SoftPWM.h: No such file or directory" prompt, it means you don't have the ``SoftPWM`` library installed.
        * Please refer to :ref:`ar_install_library` to install the two required libraries ``SoftPWM`` and ``IRLremote``.

    .. image:: img/ar_board_upload.png

#. Turn the power switch to ON to start the Zeus Car.

    .. image:: img/zeus_power.jpg

#. At this point the Zeus Car will move to 0, 45, 90, 135, 180, 225, 270, and 315 degrees.


**How it works?**

The movement of the Zeus Car is mainly implemented by this function.

.. code-block::

    void carMove(int16_t angle, int8_t power)

* ``angle``: The direction you want the car to move. use the head of the car as the 0 degree and increase the angle in counterclockwise direction.
* ``power``: The moving power, the range is -100% ~ 100%. When ``power`` is positive, the car moves forward, and vice versa, it moves backward.