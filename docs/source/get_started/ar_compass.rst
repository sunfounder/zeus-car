7. Kompass
=====================================

In diesem Projekt wird das Zeus-Auto zu einem Kompass.
Sie müssen ihm eine bestimmte Richtung vorgeben, und egal, wie Sie es drehen, es wird in diese Richtung zeigen.

.. note::
    Wenn elektrische Leitungen in der Nähe des Zeus-Autos vorhanden sind, kann das elektromagnetische Feld den Betrieb des qmc6310-Moduls stören und somit die vorgegebene Richtung des Autos verändern.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``7_compass.ino`` im Pfad ``zeus-car-main\examples\7_compass``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/672af146-1b45-46f6-b1d9-8ad9ecdcf8c0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

#. Zuerst kalibrieren wir das qmc6310-Modul.

    * Stellen Sie das Auto auf den Boden (achten Sie darauf, nicht in der Nähe von Bereichen mit vielen Kabeln zu sein).
    * Drücken Sie |ir_mute| und das Auto wird sich am Platz drehen.
    * Und stoppen, sobald das Magnetfeld an diesem Ort vollständig erfasst ist.
    * Wenn es nach mehr als 2 Minuten nicht stoppt, können Sie |ir_power| drücken, um es anzuhalten und dann an einem anderen Ort fortzusetzen.

#. Drehen Sie das Auto in die gewünschte Richtung und drücken Sie |ir_play|. Danach wird das Auto, egal in welche Richtung Sie es drehen, langsam in die voreingestellte Richtung zurückdrehen.

#. Die Magnetfelder am Boden und auf dem Tisch sind nicht identisch und müssen neu kalibriert werden.
