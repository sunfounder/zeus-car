.. _ar_play_mode:

Spielmodus
======================

Im Spielmodus wird der Code bereits im Werk auf das Arduino-Board hochgeladen, und der Zeus Car kann per APP oder Fernbedienung ferngesteuert werden, sobald er eingeschaltet ist.

* :ref:`play_app_control`: Sie müssen den SunFounder Controller auf Ihrem Mobiltelefon oder Tablet installieren, mit dem Sie den Zeus Car mit einem Joystick-Widget in alle Richtungen steuern können, sowie über Sprachsteuerung. Am wichtigsten ist, dass Sie das Echtzeit-Videostreaming, das vom Zeus Car aufgenommen wird, auf der APP sehen können.

* :ref:`play_remote_control`: Wir haben eine einfache Fernbedienung beigelegt, schalten Sie einfach den Zeus Car ein und Sie können ihn mit der Fernbedienung steuern. Dies ist eine gute Wahl für Benutzer, die so schnell wie möglich den Spaß am Steuern des Zeus Car erleben möchten.

.. note::

    Hier ist das Code-Paket für dieses Kit.

    * :download:`SunFounder Zeus Car Kit für Arduino <https://github.com/sunfounder/zeus-car/archive/refs/heads/main.zip>`

    Wenn Sie nach dem Hochladen anderer Codes auf Ihr Arduino wieder in den Spielmodus zurückkehren möchten, müssen Sie lediglich die Datei ``zeus_car.ino`` unter dem Pfad ``zeus-car-main\zeus_car`` auf das Arduino-Board hochladen.

.. toctree::
    :maxdepth: 2

    app_control
    remote_control
