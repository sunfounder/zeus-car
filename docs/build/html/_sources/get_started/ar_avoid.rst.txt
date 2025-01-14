.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

11. Hindernisvermeidung
================================

In diesem Projekt wird das Zeus-Auto automatisch vorwärts fahren. Zwei Hindernisvermeidungsmodule und ein Ultraschallmodul verhindern, dass es gegen Hindernisse stößt.

.. raw:: html

   <video loop autoplay muted style="max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``11_obstacle_avoid.ino`` im Pfad ``zeus-car-main\examples\11_obstacle_avoid``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/520af1d6-4ef2-4804-a4a9-f6aa92985258/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

    * Das Zeus-Auto fährt vorwärts.
    * Ein Ultraschallmodul erkennt Hindernisse vorne. Wenn ein Hindernis erkannt wird, dreht das Auto nach links.
    * Wenn das linke Hindernisvermeidungsmodul ein Hindernis erkennt, dreht das Auto nach rechts. Erkennt das rechte Modul ein Hindernis, dreht das Auto nach links.

.. note::
    Vor der Benutzung müssen Sie den Erkennungsabstand der beiden Hindernisvermeidungsmodule auf 15CM einstellen. Die Schritte sind wie folgt:

    * Beginnen Sie mit der Einstellung des rechten Hindernisvermeidungsmoduls. Während des Transports können Kollisionen dazu führen, dass der Sender und Empfänger im Infrarotmodul kippen. Daher müssen Sie sie manuell begradigen.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Ihr Browser unterstützt das Video-Tag nicht.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Stellen Sie ein Hindernis in etwa 15 cm Entfernung vom IR-Hindernisvermeidungsmodul auf.
    * Am Modul gibt es zwei Potentiometer. Eines reguliert die Sendeleistung, das andere die Sendefrequenz. Durch das Einstellen dieser beiden Potentiometer können Sie den Erkennungsabstand anpassen.
    * Dann können Sie ein Potentiometer einstellen. Wenn bei 15 cm die Signalleuchte auf dem Modul aufleuchtet, ist die Einstellung erfolgreich. Wenn nicht, stellen Sie das andere Potentiometer ein.

        .. image:: img/zeus_ir_avoid.jpg

    * Kalibrieren Sie das andere Hindernisvermeidungsmodul auf dieselbe Weise.
