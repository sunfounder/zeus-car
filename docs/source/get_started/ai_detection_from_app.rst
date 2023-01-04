16. AI Detection from APP
===========================

In this project, we will use an app - SunFounder Controller to view real-time video streaming, as well as use the AI detection features on your mobile device, such as face and pose detection.

SunFounder Controller is an application that allows users to customize the controller for controlling their robot or as an IoT platform. 11 kinds of show and control widgets are integrated in this APP, such as Button, Joystick, Gauge, and Radar. The controller page has 17 areas from A~Q, you can place different widgets to customize your own controller.

Now take a look at how to use the APP in a simple way.


**How to do?**

#. First check that the **Upload** button is toggled to the side near the motor port.

#. Open the ``16_ai_detection_from_app.ino`` file under the path of ``zeus-car-main\examples\16_ai_detection_from_app``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/c14c46e7-2e43-4b31-b7e6-b7718e501e96/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

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

#. Now, install `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ from **APP Store(iOS)** or **Google Play(Android)** to your mobile device.


#. Then open the APP and create a controller.

    * To add a controller on SunFounder Controller, click the **+** icon.

        .. image:: img/app1.png

    * Select the **Blank** and **Dual Stick** template and give it a name.

        .. image:: img/view_app1.jpg

    * As you are now inside the controller, click the |app_camera| icon to enable the AI detection feature. You will find both Face Detection and Pose Detection options.

        .. image:: img/view_app6.jpg

    * Save all settings by clicking on the |app_save| button. As no widgets have been selected, the screen is completely black.

        .. image:: img/view_app3.jpg

    * The next step is to connect the Zeus Car to your device via the |app_connect| button. Wait a few seconds and ``Zeus_Car(IP)`` will appear, click on it to connect.

        .. image:: img/view_app4.jpg

        .. note::
            Please make sure your Wi-Fi is connected to ``Zeus_Car``, if you are not seeing the above message for a long time.

#. Run the Controller.

    After the "Connected Successfully" message appears, click the |app_run| button, then the camera footage will appear on the app.

    If you have Face Detection turned on, then the face that appears in the screen will be framed.

    .. image:: img/view_app7.jpg

    If you have Pose Detection on, then the pose will be depicted.

    .. image:: img/view_app8.jpg

    .. note::

        If you want to switch to another AI detection, you can click on the |app_edit| icon and repeat the above steps.