1. Basic Movements
========================

You will learn how to make the Zeus Car move in all directions in this project. 

    .. image:: img/zeus_move.jpg
        :width: 600


**How to do?**

#. First check that the **Upload** button is toggled to the side near the motor port.

        .. image:: img/zeus_upload.jpg

#. Connect the Zeus Car to your computer with the blue USB cable. When you plug in your Arduino board, the computer automatically recognizes it and assigns it a COM port, which you can view in Device Manager.

#. Open the ``1_basic_move.ino`` file under the path of ``zeus-car-main\examples\1_basic_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/cedd4eb2-3283-48ae-8851-c932eb2098ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. You can quickly select the board and port from this place.

    .. image:: img/ar_board.png
    
    .. note::
        In case COMxx doesn't appear, open the Board Manager from the left and make sure the "Arduino AVR Boards" core is installed.

        .. image:: img/ar_other_board.png

#. Now click the **Upload** button to upload the code to the Arduino board. When it is finished, a notification pops up in the bottom right of your IDE window. Of course, sometimes there are some complications when uploading, and these errors will be listed here as well.

    .. note::
        * If you get a "Compilation error: SoftPWM.h: No such file or directory" prompt, it means you don't have the ``SoftPWM`` library installed.
        * Please refer to :ref:`ar_install_library` to install the two required libraries ``SoftPWM`` and ``IRLremote``.

    .. image:: img/ar_upload.png

#. Let's start the Zeus Car.

    * When first used or when the battery cable is unplugged, Zeus Car Shield will activate its over-discharge protection circuitry.
    * When you toggle the power switch ON, the power indicator will not light up, so you'll need to plug in the Type-C cable for about 5 seconds.

            .. image:: img/zeus_charge.jpg

    * If the power indicator lights up, it means that the protection status has been released. At this time look at the battery indicators, if both battery indicators are off, please continue to plug in the Type-C cable to charge the battery.

        .. image:: img/zeus_power.jpg

#. You will now see the Zeus Car move for one second in each direction.

    .. image:: img/zeus_move.jpg
        :width: 600

**How it works?**

These movements are obtained by the 4 Mecanum Wheels cooperating together, for example, four wheels forward or backward at the same time can make the car also forward or backward, and two wheels forward and two wheels backward can cause the car to pan or rotate to the left or right.

Let's look at how these movements are specifically achieved.

* Moving forward and backward, panning left and right.

    .. image:: img/ar_fwlr.jpg
        :width: 600

* Diagonal panning

    .. image:: img/ar_fblr.jpg
        :width: 600

* Rotate left and right

    .. image:: img/ar_turn_lr.jpg
        :width: 600

