.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

5. Fernsteuerung
======================

In diesem Projekt lernen Sie, wie Sie das Zeus-Auto mit der Fernbedienung steuern können.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/ir_control.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Öffnen Sie die Datei ``5_remote_control.ino`` im Pfad ``zeus-car-main\examples\5_remote_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/8e74cf1b-9100-4e4d-ab63-f21ae40232a5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten. 

#. Verwenden Sie dann die Zahlen 1~9 auf der Fernbedienung, um das Auto in 8 Richtungen zu steuern. 

    .. image:: img/ar_remote_control.png
        :width: 600
        :align: center

#. Nachdem Sie eine Taste gedrückt haben, wird das Zeus-Auto weiterfahren, bis Sie |ir_power| oder die Zahlentaste 5 drücken.

    .. image:: img/zeus_move.jpg
        :width: 600
        :align: center

#. Wenn Sie einmal |ir_return| drücken, dreht sich das Auto gegen den Uhrzeigersinn um den Körper als Mittelpunkt und wird anhalten, bis Sie |ir_power| oder die Zahlentaste 5 drücken.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

#. Ebenso wird das Auto im Uhrzeigersinn drehen, wenn Sie einmal |ir_usd| drücken, und es wird anhalten, bis Sie |ir_power| oder die Zahlentaste 5 drücken.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center
