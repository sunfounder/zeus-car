.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

15. Feldzentrisches Linienverfolgen
====================================================

In diesem Projekt wird eine andere Art des Tracer-Modus untersucht - die Tracer-Bewegung mit Kompass.

Das experimentelle Ergebnis ähnelt fast dem :ref:`ar_line_track`, jedoch zeigt der Kopf des Zeus-Autos immer in eine feste Richtung; im vorherigen Projekt änderte er sich mit der Linienrichtung.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/> 

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``15_line_track_field_centric.ino`` im Pfad ``zeus-car-main\examples\15_line_track_field_centric``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/6b6734cb-38c9-4a5b-81b7-3decced20326/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

#. Als Nächstes wird Ihr Zeus-Auto der Linie folgen, allerdings mit seinem Kopf in einer Richtung ausgerichtet. Wenn Ihr Zeus-Auto von der Linie abkommt, könnte dies bedeuten, dass Sie das :ref:`ar_grayscale` neu kalibrieren müssen oder die Geschwindigkeit verringern sollten.
