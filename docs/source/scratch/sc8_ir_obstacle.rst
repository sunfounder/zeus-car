
.. _ir_obstacle:

8. IR Obstacle Avoidance
===================================

In this lesson, we will explore how to use the Infrared (IR) Obstacle Avoidance Modules to help the Zeus Car navigate obstacles in its environment. By integrating these sensors into Scratch, we can program the Zeus Car to detect and avoid obstacles, making it more autonomous in real-world applications.

We will walk through the process of adjusting the IR sensors, reading their data, and applying it in Scratch to create interactive games like "Catch the Apple" and practical obstacle avoidance behaviors.


You Will Learn
-------------------------

* Adjust detection distances and read IR sensor statuses in Scratch.
* Use IR sensor data to control the Zeus Car's movement.
* Control a sprite in Scratch using the Zeus Car's IR sensors.
* Program the Zeus Car to avoid obstacles by rotating when detection occurs.

About IR Obstacle Avoidcance Module
------------------------------------------

.. image:: ../hardware/img/ir_avoid.png
   :width: 300
   :align: center

This is a common IR obstacle avoidance module that uses a pair of IR transmitting and receiving components. Basically, the transmitter emits infrared light, and when the detection direction encounters an obstacle, the infrared light is back and received by the receiver tube. At this time, the indicator lights up. After circuit processing, it outputs a low level signal.

Sensing distance 2-40cm, with excellent anti-interference ability. There are different reflectivity levels in different colors of objects, so the darker the object, the closer to black the detection distance is short. The 2-30cm range of this sensor is detected against a white wall.

* :ref:`cpn_ir`

Reading Detection Values
----------------------------------

#. Before use, you need to adjust the detection distance of the two obstacle avoidance modules to 15CM, the steps are as follows
    
   * Start by adjusting the right obstacle avoidance module. During transportation, collisions may cause the transmitter and receiver on the infrared module to tilt. Therefore, you need to manually straighten them.

       .. raw:: html

           <video loop autoplay muted style = "max-width:80%">
               <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
               Your browser does not support the video tag.
           </video>

       .. raw:: html
           
           <br/> <br/>  

   * Place an obstacle about 15cm away from the IR obstacle avoidance module.
   * On the module are two potentiometers, one to adjust the sending power and one to adjust the sending frequency. By adjusting these two potentiometers, you can adjust the detection distance.
   * Then you can adjust a potentiometer, and if at 15cm, the signal light on the module illuminates, the adjustment is successful; if it doesn't, adjust another potentiometer.
   
        .. image:: ../img/zeus_ir_avoid.jpg
   
   * Calibrate the other obstacle avoidance module in the same way.

4. In the **Zeus Car** category, find the **"left IR status"** and **"right IR status"** blocks. These store the detection results of the IR modules. Make sure to check the boxes next to these blocks.

   .. image:: img/8_code_irs.png

5. The values will now be displayed on the stage.

   .. image:: img/8_code_ir_status.png

6. Move your hand close to the infrared obstacle avoidance modules to trigger detection and observe the value changes on the stage.

   * If the IR modules detect an obstacle, the value will be **1**.
   * If no obstacle is detected, the value will be **0**.

7. Finally, remember to save this script.

Catch the Apple Game
------------------------------

Next, we'll use the Zeus Car's two infrared obstacle avoidance modules to play a "Catch the Apple" game.

* Choose an **Apple** sprite that will continuously fall from the top of the stage.
* Select a **Bowl** sprite, and use the Zeus Car's two infrared modules to control its left and right movement to catch the apples.
* When the **Bowl** sprite catches an apple, the apple will reappear at the top.
* If the **Bowl** sprite misses the apple, the game ends.

   .. image:: img/8_code_apple.png

**1. Add the Bowl Sprite and Write Scripts**

#. Delete the default sprite and click on **"Choose a Sprite"** to add a new one.

   .. image:: img/7_code_picture_choose.png

#. Choose the **Bowl** sprite.

   .. image:: img/8_code_bowl_choose.png

#. Set the Bowl sprite's size to **150**. Move it to the bottom center of the stage.

   .. image:: img/8_code_bowl_size.png

#. When the green flag is clicked, have the **Bowl** sprite go to the starting position.

   .. image:: img/8_code_bowl_click.png

#. From the **Zeus Car** category, drag out the **"when (left) IR is blocked"** block.

   .. image:: img/8_code_bowl_left.png

#. When the left IR sensor is blocked, decrease the Bowl sprite's **x** position by 10 to move it left.

   .. image:: img/8_code_bowl_x_decrease.png

#. Similarly, when the right IR sensor is blocked, increase the Bowl sprite's **x** position by 10 to move it right.

   .. image:: img/8_code_bowl_x_increase.png

#. Test the **Bowl** sprite:

   * Click the green flag to run the script.
   * Alternate blocking the left and right IR modules on the Zeus Car.
   * Observe if the **Bowl** sprite moves left and right accordingly.

**2. Add the Apple Sprite and Write Scripts**

#. Click **"Choose a Sprite"** and select the **Apple** sprite.

   .. image:: img/8_code_apple_choose.png

#. When the green flag is clicked, have the **Apple** sprite go to a position at the top of the stage.

   .. image:: img/8_code_apple_up.png

#. Use the **"pick random (1) to (10)"** block from the **Operators** category to set the **x** position of the Apple sprite to a random value between -200 and 200. This allows the apple to appear at a random position along the top of the stage.

   .. image:: img/8_code_apple_random.png

#. Change the **y** position of the **Apple** sprite to make it fall down the stage. If it falls too quickly, you can decrease the value from 10 to a smaller number.

   .. image:: img/8_code_apple_y.png

#. Use an **"if then"** block and the **"touching color ()"** block to detect when the **Apple** sprite is caught by the **Bowl** sprite.

   .. image:: img/8_code_apple_touch_color.png

6. Set the catching condition:

   * We will set it so that when the **Apple** sprite touches the dark brown color of the **Bowl** sprite, it means the apple has been caught.
   * Use the eyedropper tool to select the exact color from the **Bowl** sprite.

   .. image:: img/8_code_apple_touch.png

7. If the apple is caught, have the **Apple** sprite return to the top at a random **x** position.

   .. image:: img/8_code_apple_back.png

8. If the **Apple** sprite touches the edge (meaning it was not caught), stop the script to end the game.

   .. image:: img/8_code_apple_edge.png

9. Now that the scripts are complete, you can click the green flag to play the "Catch the Apple" game!

   .. image:: img/8_code_apple.png

10. Finally, remember to save this script.

.. _sc6_avoid_ir:

Using Two Infrared Modules for Obstacle Avoidance
----------------------------------------------------

Next, we'll use the two infrared modules to implement obstacle avoidance.

* When the left IR sensor detects an obstacle, the car turns right.
* When the right IR sensor detects an obstacle, the car turns left.
* If both sensors detect obstacles, the car moves backward and then tries a new direction.

Here are the steps to create the obstacle avoidance script:

#. When the green flag is clicked, set the Zeus Car's speed to **50%**.

   .. image:: img/8_code_avoid_move.png

#. Use a Forever loop to continuously check sensors.

   .. image:: img/8_code_avoid_forever.png

#. Inside the forever loop, add the following conditional statements to check the IR sensors and respond accordingly.

   * **If both left and right IR sensors detect obstacles**:

     * Stop moving.
     * Move backward for 1 second.
     * Turn clockwise (right) for 0.3 seconds.
     * Resume moving forward.

     .. image:: img/8_code_avoid_both_ir.png
         :width: 700

   * **If left IR sensor detects an obstacle**:

     * Stop moving.
     * Turn clockwise (right) until the left sensor no longer detects an obstacle.
     * Stop turning.
     * Resume moving forward.

     .. image:: img/8_code_avoid_left_ir.png
         :width: 700

   * **If right IR sensor detects an obstacle**:

     * Stop moving.
     * Turn counterclockwise (left) until the right sensor no longer detects an obstacle.
     * Stop turning.
     * Resume moving forward.

     .. image:: img/8_code_avoid_right_ir.png
   
   * **If no obstacles are detected**:

     * Continue moving forward.

     .. image:: img/8_code_avoid_else.png
   
#. Include a short wait time at the end of the forever loop to prevent the script from running too fast, which can cause issues with sensor readings and command processing.

   .. image:: img/8_code_avoid_wait.png

#. Now, you can run the script and place obstacles near the left and right infrared sensors to test the car's response. Ensure that the Zeus Car smoothly avoids obstacles on either side by rotating appropriately.

#. Finally, remember to save this script.

**Summary**

In this lesson, you:

* Adjusted the IR sensors for optimal obstacle detection.
* Read IR sensor data in Scratch to trigger events.
* Created a "Catch the Apple" game controlled by the Zeus Car's IR sensors.
* Programmed the Zeus Car to avoid obstacles by rotating until the path was clear.

With these skills, you're now equipped to create more complex behaviors and interactive projects using the Zeus Car and Scratch.





