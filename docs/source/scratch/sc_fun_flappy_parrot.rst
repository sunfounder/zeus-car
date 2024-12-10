.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _sc_parrot:

2. Flappy Parrot
==============================

In this project, we utilize an ultrasonic module to play a flappy parrot game.

After starting the script, the green bamboo (Paddle) will move from right to left at a random height. To control the parrot, place your hand above the ultrasonic module. If the distance between your hand and the module is less than 10cm, the parrot will ascend; otherwise, it will descend. You must manage this distance carefully to help the Parrot navigate past the green bamboo. Contact with the bamboo ends the game.

.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_flappy_parrot.mp4" type="video/mp4">
      Your browser does not support the video tag.
   </video>

Below are the steps for implementing the project. It is recommended to follow these steps initially, and once familiar, you may alter the effects as desired.

1. Add Sprites
---------------------------

* Delete the default sprite and use the **Choose a Sprite** button to add the **Parrot** sprite. Set its size to 50% and position it on the bottom left corner.

  .. image:: img/parrot_choose_parrot.png

* Add the **Paddle** sprite, set its size to 150%, rotate it to 180 degrees, and position it in the top right corner.

  .. image:: img/parrot_choose_paddle.png
 
* Navigate to the **Costumes** page of the **Paddle** sprite, select the **Paddle** on the canvas, and then click the **Outline** tool.

  .. image:: img/parrot_set_parrot1.png
    :width: 90%

* Change the outline effect to full fill mode and use the removal tool to eliminate it.

  .. image:: img/parrot_set_parrot2.png
    :width: 90%

2. Scripting for the **Parrot** Sprite
---------------------------------------------

Script the **Parrot** sprite to simulate its flight, with altitude adjustments based on the ultrasonic module's detection distance.

* When the green flag is clicked, switch the costume every 0.2 seconds to maintain the appearance of flight.

  .. image:: img/parrot_script_parrot1.png

* If the ultrasonic detection distance is less than 10cm, increase the y-coordinate by 50, causing the **Parrot** to ascend. Otherwise, decrease the y-coordinate by 40, causing the **Parrot** to descend.

  .. image:: img/parrot_script_parrot3.png

* If the **Parrot** sprite makes contact with the **Paddle** sprite, the game ends, and the script ceases execution.

  .. image:: img/parrot_script_parrot4.png

3. Scripting for the **Paddle** Sprite
-----------------------------------------------

Script the **Paddle** sprite to appear randomly on stage.

* Hide the **Paddle** sprite when the green flag is clicked and simultaneously create a clone of itself. The [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] block controls this cloning process.

  .. image:: img/parrot_script_paddle1.png

* Set the clone's position with the x-coordinate at 220 (rightmost) and the y-coordinate randomly between (-125 to 125).

  .. image:: img/parrot_script_paddle2.png

* Use the [repeat] block to gradually decrease its x-coordinate, making the clone move slowly from right to left until it disappears.

  .. image:: img/parrot_script_paddle3.png

* Re-clone a new **Paddle** sprite and delete the previous clone.

  .. image:: img/parrot_script_paddle4.png

Programming is complete. You can now click the green flag to run the script and see if it achieves the desired effect.


.. raw:: html

   <video loop autoplay muted style = "max-width:70%">
      <source src="../_static/video/sc_flappy_parrot.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>