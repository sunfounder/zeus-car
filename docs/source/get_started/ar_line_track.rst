.. _ar_line_track:

14. Linienverfolgung
======================================

In diesem Projekt lernen Sie, das Omni-Grayscale-Modul zur Linienverfolgung zu verwenden.

Bevor Sie mit dem Projekt beginnen, sollten Sie mit schwarzem Isolierband eine Linie aufkleben. Dies kann ein Kreis, eine gerade Linie oder eine unregelmäßige Form sein.

Dabei gibt es jedoch zwei Dinge zu beachten:

1. Diese Linie sollte 3cm breit sein (die Dicke eines Stücks Isolierband beträgt 1,5cm).
2. Der Biege-Winkel sollte nicht kleiner als 90° sein.

.. image:: img/map.png

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``14_line_track.ino`` im Pfad ``zeus-car-main\examples\14_line_track``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/f1bfb9ad-8bfa-417e-a4c0-10dbdcdc4298/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

#. Anschließend wird Ihr Zeus-Auto der Linie folgen. Wenn Ihr Zeus-Auto von der Linie abkommt, könnte dies bedeuten, dass Sie das :ref:`ar_grayscale` neu kalibrieren müssen oder die Geschwindigkeit verringern sollten.
