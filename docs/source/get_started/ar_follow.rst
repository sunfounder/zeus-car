12. Folgen
====================

In diesem Projekt werden dieselben zwei Hindernisvermeidungsmodule und ein Ultraschallmodul verwendet. Allerdings nicht zur Hindernisvermeidung, sondern um Ihnen zu folgen.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``12_follow.ino`` im Pfad ``zeus-car-main\examples\12_follow``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3fd83bdc-5457-4532-9da1-126fb7092a11/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

#. In diesem Fall wird das Zeus-Auto nicht fahren, wenn sich nichts vor ihm befindet. Sobald Sie sich nach vorne bewegen und etwa 20 cm von ihm entfernt stehen, wird es Ihnen folgen.
