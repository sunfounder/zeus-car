10. Line Tracking with the Zeus Car
================================================
In this lesson, we will learn how to use the 8-way Omni Grayscale module located at the bottom of the Zeus Car to implement line-following functionality.

You Will Learn
------------------------
* The working principles of the Omni Grayscale module.
* How to calibrate the Omni Grayscale module for your environment.
* How to use Scratch to visualize sensor values from the Omni Grayscale module.

About the Omni Grayscale Module
------------------------------------
The Omni Grayscale module is designed for line following and edge detection. Its unique design features eight TCRT5000 infrared sensors arranged in a circular pattern, enabling it to detect black lines from any direction.

This omnidirectional capability allows the Zeus Car, equipped with Mecanum wheels, to follow lines without needing its front to always face forward. 

To achieve accurate results, you can adjust the sensitivity of the module to suit the current environment by modifying the **VREF value**. The blue potentiometer on the Zeus Car Shield is used to make this adjustment.

.. image:: ../hardware/img/omni_grayscale_back.png
    :width: 400
    :align: center

Preparing to Use the Omni Grayscale Module
------------------------------------------
Before using this module, you need to prepare a track and calibrate the module for optimal performance.

**1. Create a 3cm-wide track**

The Omni Grayscale module's eight sensors are spaced 2 to 3 cm apart. To ensure the car can detect the line, at least two sensors must be over the black line simultaneously. The track must meet these criteria:

* The line width should be at least 3 cm.
* The bend angles of the line should not exceed 90°.

.. image:: ../img/map.png
    :width: 500
    :align: center

**2. Calibrate the Omni Grayscale Module**

Each floor surface may have different grayscale values, so the factory settings may not suit your current environment. Follow these steps to calibrate the module:

1. Turn the potentiometer until the grayscale sensor lights are just illuminated.

   .. image:: ../img/zeus_line_calibration.jpg
      :width: 500
      :align: center

2. Slowly turn the potentiometer until the signal indicator turns off.

   .. image:: ../img/zeus_line_calibration1.jpg
      :width: 500
      :align: center

3. Move the Zeus Car back and forth over the black line and white surface. The grayscale sensor lights should:
   * Turn **off** when positioned between the black line and white surface.
   * Turn **on** when over the white surface.

4. If the tracking performance is unsatisfactory, repeat the calibration process.

Visualizing Grayscale Sensor Values
------------------------------------
The Omni Grayscale module has eight sensors. You can use Scratch to visualize the values detected by these sensors:

* The sensor outputs **1** when it detects a black line.
* The sensor outputs **0** when it detects a white surface.

Follow these steps to create a visualization:

**1. Add and Modify the Ball Sprite**

1. Delete the default sprite and select the **Ball** sprite.

   .. image:: img/10_code_ball_choose.png

2. Go to the **Costumes** tab for the **Ball** sprite:

   * select the **ball-a** costume and add a number "1" using the **Text Tool** with any color except yellow.
   
     .. image:: img/10_code_ball_number.png

   * Modify the **ball-c** costume in the same way.

     .. image:: img/10_code_ball_c.png

**2. Write the Script**

1. When the green flag is clicked, create a **forever** loop.

   .. image:: img/10_code_ball_forever.png

2. Drag the **"(1) grayscale sensor status"** block from the Zeus Car category to monitor a specific sensor's status. This block outputs:
   
   * **1** when the sensor detects a black line.
   * **0** when it detects a white surface.

   .. image:: img/10_code_ball_status.png

3. Use the **"="** block from the **Operators** category to compare the sensor value with **1**.
   
   .. image:: img/10_code_ball_equal.png

4. If the sensor detects a black line, switch the Ball sprite's costume to **ball-c**. Otherwise, keep it as **ball-a**.
   
   .. image:: img/10_code_ball_ac.png

5. Duplicate the Ball sprite seven times, modifying the costume numbers and sensor indices accordingly.
   
   .. image:: img/10_code_ball_number2.png

**3. Test Your Project**

1. Place the Zeus Car on the prepared track.
2. Run the script and observe the Ball sprites on the stage:
   * A sprite turns pink when its corresponding sensor detects the black line.
   * The sprites remain unchanged when the sensors detect the white surface.
   .. image:: img/10_code_ball.png

3. Test thoroughly and make adjustments if necessary.
4. Save your script after testing.

**Summary**

In this lesson, you learned how to use the Omni Grayscale module for line tracking. By calibrating the sensors and visualizing their outputs in Scratch, you can ensure the Zeus Car accurately follows a track. This exercise not only enhances your understanding of robotics but also introduces practical programming concepts.









