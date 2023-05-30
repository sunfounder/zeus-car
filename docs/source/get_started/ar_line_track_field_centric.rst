15. Line Track Field Centric
==============================


A different type of tracer mode will be explored in this project - tracer movement with compass.

The experimental result is almost the same as :ref:`ar_line_track`, however the head of the Zeus Car is always facing a fixed direction; in the previous project it changed with the line direction.

**How to do?**

#. The ESP32-CAM and the Arduino board share the same RX (receive) and TX (transmit) pins. So, when you're uploading code, you'll need to first disconnect the ESP32-CAM to avoid any conflicts or potential issues.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Open the ``15_line_track_field_centric.ino`` file under the path of ``zeus-car-main\examples\15_line_track_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/6b6734cb-38c9-4a5b-81b7-3decced20326/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. After the code is uploaded successfully, slide the power switch to ON to start the Zeus Car.


#. Next, your Zeus car will move along the line, but with its head facing in one direction. If your Zeus Car goes off the line, it may mean that you need to recalibrate the :ref:`ar_grayscale`, or turn down its speed.
