.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

4. Driften
======================

In diesem Projekt lernen Sie, wie Sie das Zeus-Auto driften lassen können.

.. image:: img/zeus_drift_left.jpg

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``4_drift.ino`` im Pfad ``zeus-car-main\examples\4_drift``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/9ca66dad-7258-4868-a8a4-3bd512bacd72/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nach erfolgreichem Hochladen des Codes, schieben Sie den Ein-/Ausschalter auf ON, um das Zeus-Auto zu starten.
#. Das Zeus-Auto wird jetzt für 0,5 Sekunden vorwärts fahren und dann 90 Grad nach links driften und so weiter. Sie können versuchen, den Wert 45 (rot) durch eine andere Zahl oder eine negative Zahl zu ersetzen, um zu sehen, wie sich der Driftwinkel und die Richtung ändern.

**Wie funktioniert es?**

Das Driften des Zeus-Autos wird durch Hinzufügen des Drift-Parameters ``drift`` zur Bewegungsfunktion ``carMove()`` erreicht.

.. code-block::

    void carMove(int16_t angle, int8_t power, int8_t rot, bool drift)

* ``angle``: Die gewünschte Bewegungsrichtung des Autos. Nutzen Sie die Vorderseite des Autos als den 0-Grad-Punkt und erhöhen Sie den Winkel im Gegenuhrzeigersinn.
* ``power``: Die Bewegungskraft im Bereich von -100% bis 100%. Bei positiver ``power`` bewegt sich das Auto vorwärts, bei negativer rückwärts.
* ``rot``: Drehkraft im Bereich von -100% bis 100%. Bei positiver ``rot`` dreht sich das Auto im Gegenuhrzeigersinn, und umgekehrt.
* ``drift``: Standardmäßig ist dies auf false gesetzt. Wenn es auf true gesetzt wird, wird der Drift-Modus aktiviert.

So werden verschiedene ``power`` und ``rot`` Werte den Driftwinkel und die Richtung des Zeus-Autos verändern.
