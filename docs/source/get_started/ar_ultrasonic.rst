10. Ultraschall
==============================

In diesem Projekt lernen Sie, wie Sie die vom Ultraschallmodul erkannte Entfernung ablesen können.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Öffnen Sie die Datei ``10_ultrasonic.ino`` im Pfad ``zeus-car-main\examples\10_ultrasonic``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b3c702d7-2d4e-48fe-8d8d-7d20f70c9e45/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem der Code erfolgreich hochgeladen wurde, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

    .. note::
        Trennen Sie in diesem Schritt nicht das USB-Kabel, da Sie die Daten des Ultraschallmoduls auf Ihrem Computer überprüfen müssen.

#. Öffnen Sie den Seriellen Monitor und stellen Sie sicher, dass die aktuelle Baudrate auf 115200 eingestellt ist. Es wird empfohlen, auf das Icon **Automatisches Scrollen umschalten** zu klicken, damit Sie die neuesten gedruckten Daten sehen können.

   * Sie können die gedruckten Daten wie ``distance: 21.11  is_obstacle: 0`` anzeigen.
   * Wenn der Abstand des Hindernisses vorne innerhalb von 20 cm liegt, wird ``is_obstacle: 0`` zu ``is_obstacle: 1`` wechseln.

    .. image:: img/ar_ultrasonic.png
