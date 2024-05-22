.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

9. IR Hindernisvermeidung
==============================

In diesem Projekt werden Sie lernen, wie Sie die IR-Hindernisvermeidungsmodule an beiden Seiten des Zeus-Autos verwenden können.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``9_hc165_and_ir_obstacle.ino`` im Pfad ``zeus-car-main\examples\9_hc165_and_ir_obstacle``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3486be01-6b0e-4e84-86f6-9bdadafa1f48/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

    .. note::
        Ziehen Sie in diesem Schritt nicht das USB-Kabel ab, da Sie die Daten der beiden Hindernisvermeidungsmodule auf Ihrem Computer überprüfen müssen.

#. Öffnen Sie den seriellen Monitor und stellen Sie sicher, dass die aktuelle Baudrate auf 115200 eingestellt ist. Dann können Sie die ausgegebenen Daten betrachten.

   * Wenn beide Hindernisvermeidungsmodule kein Hindernis erkennen, wird der serielle Monitor ``0, 0`` ausgeben.
   * Halten Sie Ihre Hand vor eines der Hindernisvermeidungsmodule, wird es ``1, 0`` oder ``0, 1`` ausgeben.

    .. image:: img/ar_serial.png

#. Kalibrieren Sie das IR-Hindernisvermeidungsmodul.

    * Beginnen Sie mit der Einstellung des rechten Hindernisvermeidungsmoduls. Während des Transports können Kollisionen dazu führen, dass der Sender und Empfänger im Infrarotmodul kippen. Daher müssen Sie sie manuell begradigen.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Ihr Browser unterstützt das Video-Tag nicht.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Platzieren Sie ein Hindernis etwa 15cm vom IR-Hindernisvermeidungsmodul entfernt.
    * Auf dem Modul befinden sich zwei Potentiometer, eines zur Einstellung der Sendeleistung und eines zur Einstellung der Sendefrequenz. Durch das Verstellen dieser beiden Potentiometer können Sie die Erkennungsdistanz einstellen.
    * Danach können Sie ein Potentiometer verstellen, und wenn bei 15cm das Signallicht auf dem Modul leuchtet, ist die Einstellung erfolgreich. Wenn nicht, stellen Sie das andere Potentiometer ein.

        .. image:: img/zeus_ir_avoid.jpg

    * Kalibrieren Sie das andere Hindernisvermeidungsmodul auf die gleiche Weise.
