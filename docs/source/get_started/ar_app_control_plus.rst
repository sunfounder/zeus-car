.. _ar_app_control_plus:

17. APP Control Plus
=====================


This project integrates Line Track, Follow, Avoid functions based on :ref:`ar_app_control`.


.. note::
    Please install `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ from **APP Store(iOS)** or **Google Play(Android)**.


**How to do?**

#. First check that the **Upload** button is toggled to the side near the motor port.

#. Open the ``17_app_control_plus.ino`` file under the path of ``zeus-car-main\examples\17_app_control_plus``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b67e7245-369b-4218-b12c-d73f95ac3b22/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

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

    * Preset controllers are available for some products, here we choose **Zeus Car**.

        .. image:: img/app_preset.png

    * Give it a name and click Confirm.

    .. image:: img/app_name.png
    
    * You are now inside the controller, which already has several widgets set up. Click the |app_save| button in the upper right corner.

        .. image:: img/app_edit.png

    * The next step is to connect the Zeus Car to your device via the |app_connect| button. Wait a few seconds and ``Zeus_Car(IP)`` will appear, click on it to connect.

        .. image:: img/app_auto_connect.png

        .. note::
            Please make sure your Wi-Fi is connected to ``Zeus_Car``, if you are not seeing the above message for a long time.

#. Run the Controller.

    After the "Connected Successfully" message appears, click the |app_run| button, then the camera footage will appear on the app, and now you can control your Zeus Car with these widgets.

    .. image:: img/app_run.png

    Here are the functions of the widgets.

    * :ref:`ar_app_compass_cali`: Turn on compass calibration.
    * **Stop(F)**: Stop all movements of the car.
    * **Set Heading(I)**: After placing the car in one direction with your hand, click on this widget to make this direction as the front of the car movement. This allows you to quickly specify a direction instead of slowly rotating the car to that direction with other widgets.
    * :ref:`ar_app_drift`: Activate the drift function.
    * :ref:`ar_app_move`: Control the car to move in all directions.
    * Speech(M): This widget is not available in this project because no code has been written for it.
    * :ref:`ar_app_line_track`: Switching to line track mode.
    * :ref:`ar_app_follow`: Switching to follow mode.
    * :ref:`ar_app_avoid`: Switch to obstacle avoidance mode.
    * :ref:`ar_app_rotate_drift`: Used to control the head direction.


.. _ar_app_compass_cali:

Calibration(E)
--------------------------

Turn on compass calibration by clicking the |app_cali_e| button.

Place the Zeus car on the ground. Upon turning on the compass calibration, the car will start rotating counterclockwise and will stop in about 1 minute. If it rotates longer than 2 minutes, the magnetic field here is complicated. Try changing the location and calibrating again.


.. _ar_app_drift:

Drift Enable(J)
---------------------

Click the |app_drift_j| button to enable the drift function.

* By sliding the |app_rotate_q| widget counterclockwise, you will see Zeus Car drift to the right. Upon releasing the hand, the car will stop at its current position.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

* Similarly, if you slide the |app_rotate_q| widget clockwise, the Zeus Car will drift to the left and stop in the current position.

.. image:: img/zeus_drift_right.jpg
    :width: 600
    :align: center


.. _ar_app_move:

Move in All Directions(K)
----------------------------------

The Zeus Car will move in the appropriate direction when you swipe the |app_move_k| widget.

.. image:: img/joystick_move.png
    :align: center

The car moves once every time you slide, so if you don't release your hand all the time, the car keeps moving.

.. image:: img/zeus_move.jpg


.. _ar_app_line_track:

Line(N)
--------------

Click on the |app_line_n| widget to switch to the line track mode.

Two modes of line track are available on the Zeus Car, one with its head always facing the direction of movement and one with its head facing a fixed direction. Here, the second mode is selected.


#. Stick a 3cm wide line

    There are eight sensors on the Omni grayscale module, and the distance between each sensor is between 2 and 3 cm. There must be two sensors to detect the black line simultaneously. Therefore, the line you stick must be at least 3cm wide and the bend angle should not be less than 90°.

    .. image:: img/map.png
        :width: 800

#. Calibrate the Omni Grayscale module.

    Since each subfloor has different grayscale values, the factory-set grayscale threshold may not be appropriate for your current environment, so you will need to calibrate this module before use. It is recommended that you need to calibrate it whenever the floor color changes a lot.

    * Place the Zeus Car on white surface and turn the potentiometer until the gray sensor light is just illuminated.

        .. image:: img/zeus_line_calibration.jpg

    * Now let the two greyscale sensors on the side be located just between the black line and white surface, and slowly turn the potentiometer until the signal indicator just goes off.

        .. image:: img/zeus_line_calibration1.jpg

    * You can move repeatedly over the the black line and white surface to make sure that the lights of the greyscale sensor are off when they are between the the black line and white surface and on when they are on the white surface, indicating that the module is successfully calibrated.


#. Place the Zeus Car on your stickied line, click the |app_line_n| widget, and it will track the line.

#. Due to the high environmental requirements of the Omni grayscale module, it is recommended to calibrate it a few more times if the tracking effect is not satisfactory (off-track).

.. _ar_app_follow:

Follow(O)
------------

Click the |app_follow_o| widget to switch to follow mode.

The ultrasonic sensor detects obstacles in front (20 cm) and follows them forward. These two obstacle avoidance modules allow the car to follow left or right, but they need to be calibrated (15cm) before use.

#. Calibrate the IR obstacle avoidance module.

    * Place an obstacle about 15cm away from the IR obstacle avoidance module.
    * On the module are two potentiometers, one to adjust the sending power and one to adjust the sending frequency. By adjusting these two potentiometers, you can adjust the detection distance.
    * Then you can adjust a potentiometer, and if at 15cm, the signal light on the module illuminates, the adjustment is successful; if it doesn't, adjust another potentiometer.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibrate the other obstacle avoidance module in the same way.

#. Place Zeus car on a table or the ground and let it follow your hand or other obstacles.

.. _ar_app_avoid:

Avoid(p)
------------------------

When you want to go into obstacle avoidance mode, click the |app_avoid_p| widget, but first reference the :ref:`app_follow` to calibrate the two obstacle avoidance modules.

* Zeus car will move forward.
* An ultrasonic module detects obstacles in front, if detected, the car turns left.
* When the left obstacle avoidance module detects an obstacle, the car turns right, and when the right obstacle avoidance module detects an obstacle, the car turns left.



.. _ar_app_rotate_drift:

Control the Drection(Q)
-------------------------------

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