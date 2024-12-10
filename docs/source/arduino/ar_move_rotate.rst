3. Move and Rotate
======================

In this project, the Zeus Car can increase the parameters of rotation so that it can spin in place or go out of arc.


**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: ../img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``3_rotate_and_move.ino`` file under the path of ``zeus-car-main\examples\3_rotate_and_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/bf0dfe1b-18c1-4a45-bd38-a9a8e671d66a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car. The Zeus Car will turn left and then right to return to its original position. Then the car will turn slowly in an outward arc and the turning angle will slowly decrease until it finally rotates on its own.



**How it works?**

Here is the addition of a rotational power parameter ``rot`` to the Zeus Car's move function ``carMove()``.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: The direction you want the car to move. use the head of the car as the 0 degree and increase the angle in counterclockwise direction.
* ``power``: The moving power, the range is -100% ~ 100%. When ``power`` is positive, the car moves forward, and vice versa, it moves backward.
* ``rot``: Rotation power, the range is -100% ~ 100%. When ``rot`` is positive, the car turn counterclockwise, and vice versa.

If ``power`` is 0 and ``rot`` is not 0, the Zeus Car will spin in place. The higher the rotational power, the faster the rotation speed. When ``rot`` is positive, the car will rotate counterclockwise, and vice versa.

If ``power`` is not 0, you will find that the Zeus Car will go out in an arc. The turning angle will increase as ``rot`` increases, and the Zeus Car will rotate itself when the value is large enough.