8. Feldzentrische Bewegung
===================================================

Dieses Projekt baut auf dem vorherigen Projekt auf und kombiniert die Kompassfunktion mit der Bewegung des Zeus Autos. Wenn Sie die Bewegung des Zeus Autos mit der Fernbedienung steuern und es durch eine äußere Kraft (z.B. durch einen Hundestoß) abgelenkt wird, wird es automatisch in die ursprüngliche Richtung zurücklenken.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``8_move_field_centric.ino`` im Pfad ``zeus-car-main\examples\8_move_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a0ac96b3-47a9-4eab-8d8a-d1ca16c7fcda/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

#. Verwenden Sie dann die Zahlen 1 ~ 9 auf der Fernbedienung, um das Auto in 8 Richtungen zu steuern. Nachdem Sie eine Taste gedrückt haben, wird das Zeus-Auto weiterfahren, bis Sie |ir_power| oder die Nummerntaste 5 drücken.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. Wenn Sie |ir_return| einmal drücken, wird das Auto gegen den Uhrzeigersinn um den eigenen Körper rotieren und erst stoppen, wenn Sie |ir_power| oder die Nummerntaste 5 drücken.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. Ebenso wird das Auto im Uhrzeigersinn rotieren, wenn Sie |ir_usd| einmal drücken und dann stoppen, bis Sie |ir_power| oder die Nummerntaste 5 drücken.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center

#. Wenn Sie die |ir_minus| Taste drücken, wird das Auto nach links driften.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

#. Drücken Sie die |ir_plus| Taste, driftet das Auto nach rechts.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center

.. note::

    * Falls das Zeus-Auto nicht ordnungsgemäß fährt, ist der Kompass möglicherweise nicht richtig kalibriert. Drücken Sie |ir_mute| zur Neukalibrierung.
    * Wenn Sie das Auto vom Boden auf einen Tisch heben, ändert sich das Magnetfeld und es muss neu kalibriert werden.
