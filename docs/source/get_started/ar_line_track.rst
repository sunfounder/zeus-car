.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_line_track:

14. Line Track
==============

In this project, you will learn how to use the Omni Grayscale Module for line tracking.

Before working on the project, you will need to use black electrical tape to stick out a line of track, which can be a circle, a straight line, or an irregular shape.

But there are two points to note.

1. This line should be 3cm wide (the thickness of a piece of electrical tape is 1.5cm).
2. The bend angle should not be less than 90°.

.. image:: img/map.png

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``14_line_track.ino`` file under the path of ``zeus-car-main\examples\14_line_track``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/f1bfb9ad-8bfa-417e-a4c0-10dbdcdc4298/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.


#. Next your Zeus Car will move along the line. If your Zeus Car goes off the line, it may mean that you need to recalibrate the :ref:`ar_grayscale`, or turn down its speed.

