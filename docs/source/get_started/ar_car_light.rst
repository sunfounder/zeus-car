6. Autolicht
==========================

In diesem Projekt können Sie die RGB-Lichtleisten am Unterboden des Autos mit der Fernbedienung steuern und ihnen unterschiedliche Farben anzeigen lassen.

.. raw:: html

   <video loop autoplay muted style="max-width:80%">
      <source src="../_static/video/car_light.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``6_car_light.ino`` im Pfad ``zeus-car-main\examples\6_car_light``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/79b6c0e5-a788-4d67-bb44-7e7122c521ab/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

#. Nun können Sie die Zahlen 1 bis 9 auf der Fernbedienung verwenden, um das Auto in verschiedenen Farben leuchten zu lassen. Drücken Sie 0, um das Licht auszuschalten, und drücken Sie |ir_return|, damit das Auto einen Farbzyklus durchführt. Die Tasten 1 bis 9 entsprechen den Farben: Rot, Orange, Gelb, Grün, Türkis, Blau, Violett, Pink, Weiß. 
