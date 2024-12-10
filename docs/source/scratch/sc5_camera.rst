
5. Seeing Through the Eyes of Zeus Car
================================================
Ever wondered what it's like to explore the world from a robot's perspective? In this lesson, we'll step into the "eyes" of the Zeus Car and discover how to see the world just as it does. Get ready to unlock a whole new dimension of interactive robotics!


You will Learn
-------------------------

* How to control the ESP32 CAM module using Scratch blocks.
* How to integrate camera controls into your Zeus Car projects.
* How to remotely control the Zeus Car while viewing its camera feed.


Introduction to ESP32 CAM
-------------------------------------------------------

The ESP32-CAM is a very small camera module with the ESP32-S chip that costs approximately $10. Besides the OV2640 camera, and several GPIOs to connect peripherals, it also features a microSD card slot that can be useful to store images taken with the camera or to store files to serve to clients.

.. image:: ../hardware/img/esp32_cam.png
    :width: 400
    :align: center


The module can work independently as the smallest system, with a size of only 27*40.5*4.5mm, and a deep sleep current as low as 6mA.

ESP32-CAM can be widely used in various IoT applications, suitable for home smart devices, industrial wireless control, wireless monitoring, QR wireless identification, wireless positioning system signals and other IoT applications. It is an ideal solution for IoT applications.

* :ref:`cpn_camera`

Controlling the Camera
--------------------------------

Let's learn how to control the camera module using the Scratch blocks in the **Zeus Car** category.

**Turn On the Camera**:

  * Drag the **"turn camera ON"** block from the **Zeus Car** category.
  * Click it, and you'll see the background of the stage display the camera's feed.

  .. image:: img/5_code_camera_on.png

**Correct the Camera Orientation**:

  * If you see the camera feed inverted, use the **"set camera image orientation to (normal)"** block to correct it.
  * You can choose between **normal** and **inverted** orientations.

  .. image:: img/5_code_camera_inverted.png

**Adjust the Camera Transparency**:

  * While controlling the Zeus Car and watching the camera feed, you might want to adjust the transparency of the video overlay.
  * Use the **"set video transparency to (0)%"** block.
  * A value of **0%** means fully opaque (no transparency), and **100%** means fully transparent (you won't see the camera feed).

  .. image:: img/5_code_camera_trans.png

**Turn On the Camera LED**:

  * If you're operating the Zeus Car in low-light conditions, you can turn on the LED on the ESP32 CAM module for illumination.
  * Use the **"turn camera LED on"** block.

  .. image:: img/5_code_camera_led.png

Toggling the Camera and Controlling the Zeus Car
-----------------------------------------------------

Now let's write a script using the Mammoth Coding App to control the Zeus Car's movement while viewing the camera feed to see the environment as it moves.

#. Delete the default sprite to start fresh. Click on **"Choose a Sprite"** and select **"Button2"**.

   .. image:: img/5_code_move_button2.png

#. When the green flag is clicked:

   * Set the Zeus Car's movement speed to **80%**.
   * Turn on the camera using the **"turn camera ON"** block.
   * If the camera feed is inverted, use the **"set camera image orientation to (inverted)"** block to correct it.
   * Set the initial costume of **Button2** to **"button2-a"**.


   .. image:: img/5_code_move_buttona.png

#. When the **Button2** sprite is clicked, it will switch costumes between **"button2-a"** and **"button2-b"**.

   .. image:: img/5_code_camera_switch.png

#. Use an **"if...else"** block to check the **"costume number"**.
   
   * If the **"costume number"** is **1** (which corresponds to **"button2-a"**), turn the camera **ON**.
   * If the **"costume number"** is **2** (which corresponds to **"button2-b"**), turn the camera **OFF**.

   .. image:: img/5_code_move_turn_off.png

#. Add scripts to control the Zeus Car using the arrow keys:

   * **Up Arrow Key**: Move in the **0-degree** direction (forward).
   * **Down Arrow Key**: Move in the **180-degree** direction (backward).
   * **Left Arrow Key**: Move in the **-90-degree** direction (left).
   * **Right Arrow Key**: Move in the **90-degree** direction (right).

   .. image:: img/5_code_move_car.png
      :width: 700

#. After completing the scripts, you can expand the stage for a better view by clicking the full-screen button.

   .. image:: img/2_code_expand.png

#. Test your project:

   * Now, you can use the **Button2** sprite to toggle the camera on and off while remotely controlling the Zeus Car with the arrow keys.
   * Observe the camera feed as you navigate the car.

   .. image:: img/5_code_move_camera.png

**Summary**

In this lesson, you learned how to:

* **Control the ESP32 CAM module** using Scratch blocks.
* **Integrate camera controls** into your Zeus Car projects.
* **Remotely control** the Zeus Car while viewing its camera feed in real-time.
* **Create interactive interfaces** using sprites to toggle the camera and LED.

By utilizing the camera module, you can enhance your projects, making the Zeus Car more interactive and engaging.
