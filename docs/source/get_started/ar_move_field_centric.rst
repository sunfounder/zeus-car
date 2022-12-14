8. Move Field Centric
=====================


This project is based on the previous project to combine the compass function to the movement of Zeus Car.
While you control the Zeus Car movement with the remote control, if it is deflected by an external force (e.g. kicked by a dog), it will automatically deflect back to the original direction.


**How to do?**

#. First check that the **Upload** button is toggled to the side near the motor port.

#. Open the ``8_move_field_centric.ino`` file under the path of ``zeus-car-main\examples\8_move_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a0ac96b3-47a9-4eab-8d8a-d1ca16c7fcda/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.

#. Then use the number 1 ~ 9 on the remote control to control the car in 8 directions. After pressing a key, the Zeus Car will keep moving until you press |ir_power| or the number key 5.

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

#. Press the |ir_minus| key, the car will drift to the left.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

#. Press the |ir_plus| key, the car will drift to the right.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center


.. note::

    * If the Zeus Car does not move well, the compass may not be calibrated properly, you need to press |ir_mute| to calibrate it.
    * If you pick up the car from the ground to the table, the magnetic field will change and you need to recalibrate it.