.. _ar_grayscale:

13. Graustufen
==============================

In diesem Projekt lernen Sie, wie Sie das Omni Graustufen-Modul auf der Unterseite des Zeus-Autos lesen und kalibrieren.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``13_hc165_and_grayscale.ino`` im Pfad ``zeus-car-main\examples\13_hc165_and_grayscale``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c34354c-dd61-4e86-9b99-eccc93e9293f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

    .. note::
        Ziehen Sie in diesem Schritt nicht das USB-Kabel ab, da Sie die Daten des Omni Graustufen-Moduls auf Ihrem Computer überprüfen müssen.

#. Öffnen Sie den seriellen Monitor und stellen Sie sicher, dass die aktuelle Baudrate auf 115200 eingestellt ist. Es wird empfohlen, auf das **Automatisches Scrollen umschalten** Symbol zu klicken, damit Sie die neuesten Daten sehen können.

    .. image:: img/ar_grayscale.png

    * Drehen Sie das Auto um und im seriellen Monitor wird ``data: 11111111`` angezeigt.
    * Wenn Sie einen der Sensoren auf dem Modul mit der Hand abdecken, wird der Wert an der entsprechenden Position zu ``0``.
    * Zum Beispiel, wenn Sie den ``U11`` Sensor abdecken, sehen Sie ``data: 01111111``.

#. Kalibrieren Sie das Omni Graustufen-Modul.

    Da jeder Untergrund unterschiedliche Graustufenwerte hat, ist die werkseitig eingestellte Graustufenschwelle möglicherweise nicht für Ihre aktuelle Umgebung geeignet. Daher müssen Sie dieses Modul vor der Verwendung kalibrieren. Es wird empfohlen, die Kalibrierung durchzuführen, wenn sich die Bodenfarbe stark ändert.

    * Stellen Sie das Zeus-Auto auf eine weiße Oberfläche und drehen Sie das Potentiometer, bis das Licht des Grausensors gerade leuchtet.

        .. image:: img/zeus_line_calibration.jpg

    * Lassen Sie nun die beiden Grausensoren an der Seite genau zwischen der schwarzen Linie und der weißen Oberfläche positionieren und drehen Sie das Potentiometer langsam, bis die Signalanzeige gerade erlischt.

        .. image:: img/zeus_line_calibration1.jpg

    * Bewegen Sie das Auto wiederholt über die schwarze Linie und die weiße Oberfläche, um sicherzustellen, dass die Lichter des Grausensors aus sind, wenn sie zwischen der schwarzen Linie und der weißen Oberfläche liegen, und leuchten, wenn sie auf der weißen Oberfläche sind. Das zeigt, dass das Modul erfolgreich kalibriert wurde.
