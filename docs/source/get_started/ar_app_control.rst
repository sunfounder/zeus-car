.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_app_control:

17. APP Control
=====================

In the previous project we simply viewed the footage taken by the camera and used the AI detection function in the SunFounder Controller.

In this project, we will try to control the movement and direction of the Zeus Car using the joystick widget in the app, so now let's see how it works.


.. note::
    Please install `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ from **APP Store(iOS)** or **Google Play(Android)**.


**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``17_app_control.ino`` file under the path of ``zeus-car-main\examples\17_app_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5d65d2b4-5ed7-4d21-ba3b-02529ee8dd6c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, you can plug in the ESP32-CAM and then slide the power switch to ON to start the Zeus Car.

    .. image:: img/plug_esp32_cam.jpg

#. Toggle the Upload Switch to the side of Run (right side on this diagram) to start the ESP32 CAM. 

    .. image:: img/zeus_run.jpg

#. Press the reset button to get the Arduino board's program running again.

    .. image:: img/zeus_reset_button.jpg

#. Connect to ``Zeus_Car`` WLAN.

    * Find ``Zeus_Car`` on the WLAN of the mobile phone (tablet), enter the password ``12345678`` and connect to it.

    .. image:: img/app_wlan.png

    * The default connection mode is AP mode. So after you connect, there will be a prompt telling you that there is no Internet access on this WLAN network, please choose to continue connecting.

    .. image:: img/app_no_internet.png

#. Create a controller.

    * To add a controller on SunFounder Controller, click the **+** icon.

        .. image:: img/app1.png

    * There are preset controllers for some products in the Preset section. But here we choose a **Blank** and **Dual Stick** template.

        .. image:: img/app_blank.PNG

   * Click the + icon in the J area and select a Switch widget. You may need to slide to the left to see the widget.

        .. image:: img/app_switch_wid.png

        .. note::
            If you think you selected the wrong widget, you can click on it again and use the Delete button to remove it.

            .. image:: img/app_delete.png

    * Click the Settings icon in the upper right corner to give it a name.

        .. image:: img/app_name_dirft.png

    * Select a Joystick widget in the K and Q area and give name to both widgets. Then use the |app_save| button to save the controller.

    .. image:: img/app_joystick_wid.png

    * The next step is to connect the Zeus Car to your device via the |app_connect| button. Wait a few seconds and ``Zeus_Car(IP)`` will appear, click on it to connect.

        .. image:: img/app_connect.png

        .. note::
            Please make sure your Wi-Fi is connected to ``Zeus_Car``, if you are not seeing the above message for a long time.


#. Run the Controller.

    After the "Connected Successfully" message appears, click the |app_run| button, then the camera footage will appear on the app, and now you can control your Zeus Car with these widgets.

    The functions of the three widgets are referenced as follows


    **Move in All Directions(K)**

    The Zeus Car will move in the appropriate direction when you swipe the |app_move_k| widget.

    .. image:: img/joystick_move.png
        :align: center

    The car moves once every time you slide, so if you don't release your hand all the time, the car keeps moving.

    .. image:: img/zeus_move.jpg


    **Drift Enable(J)**

    Click the |app_drift_j| button to enable the drift function.

    * By sliding the |app_rotate_q| widget counterclockwise, you will see Zeus Car drift to the right. Upon releasing the hand, the car will stop at its current position.

        .. image:: img/zeus_drift_left.jpg
            :width: 600
            :align: center

    * Similarly, if you slide the |app_rotate_q| widget clockwise, the Zeus Car will drift to the left and stop in the current position.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center


    **Control the Drection(Q)**

    * When the |app_drift_j| button is on, the |app_rotate_q| widget is used to make the Zeus Car drift left and right.

    * When the |app_drift_j| widget is off, the |app_rotate_q| widget is used to control the direction of the car's head.

        * By sliding the |app_rotate_q| widget counterclockwise, the car will also rotate counterclockwise. Upon releasing the hand, the head of the car will back to the original direction.

        .. image:: img/zeus_turn_left.jpg
            :width: 600
            :align: center

        * Similarly the car will rotate clockwise with the |app_rotate_q| widget and return to the original direction when released.

        .. image:: img/zeus_turn_right.jpg
            :width: 600
            :align: center

