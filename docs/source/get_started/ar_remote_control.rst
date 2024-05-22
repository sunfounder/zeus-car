.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

5. Remote Control
======================

In this project, you will learn how to control the Zeus Car with the remote control.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/ir_control.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``5_remote_control.ino`` file under the path of ``zeus-car-main\examples\5_remote_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/8e74cf1b-9100-4e4d-ab63-f21ae40232a5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, turn the power switch to ON to start the Zeus Car. 

#. Then use the 1~9 on the remote control to control the car in 8 directions. 

    .. image:: img/ar_remote_control.png
        :width: 600
        :align: center

#. After pressing a key, the Zeus Car will keep moving until you press |ir_power| or the number key 5.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center


#. When you press |ir_return| once, the car will rotate counterclockwise with the body as the center and will stop until you press |ir_power| or the number key 5.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. Similarly, pressing |ir_usd| once will make the car rotate clockwise, and then it will stop until you press |ir_power| or the number key 5.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center 