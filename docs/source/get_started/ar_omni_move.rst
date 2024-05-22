.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

2. Omni-Bewegung
==========================

In diesem Projekt lernen Sie, das Zeus-Auto auf 0, 45, 90, 135, 180, 225, 270 und 315 Grad zu bewegen.

Wenn Sie die Reibung am Boden und die strukturellen Toleranzen ignorieren, sollte sein Pfad ein Achteck sein und schließlich zum Ursprung zurückkehren.

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Öffnen Sie die Datei ``2_omni_move.ino`` im Pfad ``zeus-car-main\examples\2_omni_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/2425f280-5bd4-4e49-bb2e-220d1f4f867b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Wählen Sie das korrekte Board und den Port aus und klicken Sie dann auf den **Hochladen**-Button.

    .. note::
        * Wenn Sie eine "Compilation error: SoftPWM.h: Datei oder Verzeichnis nicht gefunden" Meldung erhalten, bedeutet dies, dass Sie die ``SoftPWM`` Bibliothek nicht installiert haben.
        * Befolgen Sie die Anweisungen unter :ref:`ar_install_library`, um die beiden benötigten Bibliotheken ``SoftPWM`` und ``IRLremote`` zu installieren.

    .. image:: img/ar_board_upload.png

#. Schalten Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.

    .. image:: img/zeus_power.jpg

#. Zu diesem Zeitpunkt wird das Zeus-Auto auf 0, 45, 90, 135, 180, 225, 270 und 315 Grad fahren.

**Wie funktioniert es?**

Die Bewegung des Zeus-Autos wird hauptsächlich durch diese Funktion realisiert.

.. code-block::

    void carMove(int16_t angle, int8_t power)

* ``angle``: Die Richtung, in die Sie das Auto bewegen möchten. Verwenden Sie die Vorderseite des Autos als den 0-Grad-Winkel und erhöhen Sie den Winkel im Gegenuhrzeigersinn.
* ``power``: Die Bewegungskraft, der Bereich liegt zwischen -100% und 100%. Wenn ``power`` positiv ist, fährt das Auto vorwärts, andernfalls rückwärts.
