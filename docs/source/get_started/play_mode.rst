.. _ar_play_mode:

Play Mode
======================

The play mode is where we pre-upload the code to the Arduino board at the factory, and the Zeus Car can be remotely controlled by APP or remote control once it is turned on.

* :ref:`play_app_control`: You need to install the SunFounder Controller on your mobile or tablet, which allows you to control the Zeus Car in all directions with a joystick widget, as well as speech control, and most importantly, you can see the real-time video streaming taken by the Zeus Car on the APP.

* :ref:`play_remote_control`: We have equipped a simple remote control, just turn on the Zeus Car and you can control it by remote control, which is a good choice for users who want to experience the fun of controlling Zeus Car as soon as possible.

.. note::

    Here is the code package for this kit.

    * :download:`SunFounder Zeus Car Kit for Arduino <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

    If you want to go back to Play Mode after uploading other code to your Arduino, then you just need to upload the ``zeus_car.ino`` under the path of ``zeus-car-main\zeus_car`` to the Arduino board.

.. toctree::
    :maxdepth: 3

    app_control
    remote_control
