3. Bewegen und Rotieren
=======================================

In diesem Projekt kann das Zeus-Auto die Rotationsparameter erhöhen, sodass es sich an Ort und Stelle drehen oder in einem Bogen fahren kann.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``3_rotate_and_move.ino`` im Pfad ``zeus-car-main\examples\3_rotate_and_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/bf0dfe1b-18c1-4a45-bd38-a9a8e671d66a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten. Das Zeus-Auto wird zuerst nach links und dann nach rechts drehen, um in seine Ausgangsposition zurückzukehren. Anschließend wird das Auto langsam in einem Bogen nach außen drehen, wobei der Drehwinkel stetig abnimmt, bis es sich schließlich von selbst dreht.

**Wie funktioniert es?**

Hier wird ein Rotationskraftparameter ``rot`` zur Bewegungsfunktion ``carMove()`` des Zeus-Autos hinzugefügt.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot)

* ``angle``: Die gewünschte Bewegungsrichtung des Autos. Verwenden Sie die Vorderseite des Autos als 0 Grad und erhöhen Sie den Winkel in entgegen dem Uhrzeigersinn.
* ``power``: Die Bewegungskraft, der Bereich liegt zwischen -100% ~ 100%. Wenn ``power`` positiv ist, fährt das Auto vorwärts und umgekehrt rückwärts.
* ``rot``: Rotationskraft, der Bereich liegt zwischen -100% ~ 100%. Bei positivem ``rot`` dreht sich das Auto gegen den Uhrzeigersinn und umgekehrt.

Wenn ``power`` 0 ist und ``rot`` nicht 0 ist, wird sich das Zeus-Auto an Ort und Stelle drehen. Je höher die Rotationskraft, desto schneller die Drehgeschwindigkeit. Bei positivem ``rot`` wird das Auto gegen den Uhrzeigersinn rotieren und umgekehrt.

Ist ``power`` nicht 0, wird das Zeus-Auto in einem Bogen fahren. Der Drehwinkel wird mit zunehmendem ``rot`` größer, und das Zeus-Auto wird sich drehen, wenn der Wert groß genug ist.
