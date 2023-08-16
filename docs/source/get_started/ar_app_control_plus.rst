.. _ar_app_control_plus:

18. APP Control Plus
=====================

Dieses Projekt integriert die Funktionen Linienverfolgung, Folgen und Vermeiden basierend auf :ref:`ar_app_control`.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/app_control.mp4"  type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>

.. note::
    Bitte installieren Sie den `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ aus dem **APP Store(iOS)** oder **Google Play(Android)**.

**Wie funktioniert das?**

#. Der ESP32-CAM und das Arduino-Board teilen sich die gleichen RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes müssen Sie zuerst den ESP32-CAM trennen, um Konflikte oder potenzielle Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``18_app_control_plus.ino`` im Pfad ``zeus-car-main\examples\18_app_control_plus``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b67e7245-369b-4218-b12c-d73f95ac3b22/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem der Code erfolgreich hochgeladen wurde, schieben Sie den Ein-/Ausschalter auf EIN, um das Zeus-Auto zu starten.

#. Schalten Sie den Upload-Schalter auf die Seite von "Run" (rechte Seite in dieser Darstellung), um die ESP32 CAM zu starten.

    .. image:: img/zeus_run.jpg

#. Drücken Sie die Reset-Taste, um das Programm des Arduino-Boards erneut zu starten.

    .. image:: img/zeus_reset_button.jpg

#. Verbinden Sie sich mit dem ``Zeus_Car`` WLAN.

    * Finden Sie ``Zeus_Car`` im WLAN Ihres Handys (Tablet), geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit.

    .. image:: img/app_wlan.png

    * Der Standardverbindungsmodus ist der AP-Modus. Nach der Verbindung wird eine Meldung angezeigt, die besagt, dass dieses WLAN-Netzwerk keinen Internetzugang hat. Wählen Sie weiterhin Verbinden.

    .. image:: img/app_no_internet.png

#. Erstellen Sie einen Controller.

    * Um einen Controller im SunFounder Controller hinzuzufügen, klicken Sie auf das **+** Symbol.

        .. image:: img/app1.png

    * Voreingestellte Controller sind für einige Produkte verfügbar, hier wählen wir **Zeus Car**.

        .. image:: img/app_preset.png

    * Geben Sie ihm einen Namen und klicken Sie auf Bestätigen.

    .. image:: img/app_name.png
    
    * Sie befinden sich nun im Controller, der bereits einige Widgets eingerichtet hat. Klicken Sie auf die Schaltfläche |app_save| in der oberen rechten Ecke.

        .. image:: img/app_edit.png

    * Der nächste Schritt besteht darin, das Zeus-Auto über die |app_connect| Schaltfläche mit Ihrem Gerät zu verbinden. Warten Sie ein paar Sekunden und ``Zeus_Car(IP)`` wird angezeigt. Klicken Sie darauf, um die Verbindung herzustellen.

        .. image:: img/app_auto_connect.png

        .. note::
            Stellen Sie sicher, dass Ihr WLAN mit ``Zeus_Car`` verbunden ist, wenn Sie die obige Nachricht lange nicht sehen.

#. Starten Sie den Controller.

    Nachdem die Meldung "Erfolgreich verbunden" erscheint, klicken Sie auf die |app_run| Schaltfläche. Anschließend wird das Kamerabild in der App angezeigt, und Sie können Ihr Zeus-Auto mit diesen Widgets steuern.

    .. image:: img/app_run.png

    Hier sind die Funktionen der Widgets.

    * :ref:`ar_app_compass_cali`: Kompasskalibrierung aktivieren.
    * **Stopp(F)**: Alle Bewegungen des Autos anhalten.
    * **Richtung festlegen(I)**: Nachdem Sie das Auto mit Ihrer Hand in eine Richtung gesetzt haben, klicken Sie auf dieses Widget, um diese Richtung als Vorderseite der Autobewegung festzulegen. Dadurch können Sie schnell eine Richtung festlegen, anstatt das Auto mit anderen Widgets langsam in diese Richtung zu drehen.
    * :ref:`ar_app_drift`: Driftfunktion aktivieren.
    * :ref:`ar_app_move`: Steuern Sie das Auto in alle Richtungen.
    * Sprache(M): Dieses Widget ist in diesem Projekt nicht verfügbar, da dafür kein Code geschrieben wurde.
    * :ref:`ar_app_line_track`: Wechseln in den Linienverfolgungsmodus.
    * :ref:`ar_app_follow`: Wechsel in den Verfolgungsmodus.
    * :ref:`ar_app_avoid`: Wechsel in den Hindernisvermeidungsmodus.
    * :ref:`ar_app_rotate_drift`: Wird verwendet, um die Kopfrichtung zu steuern.


.. _ar_app_compass_cali:

Kalibrierung(E)
--------------------------

Aktivieren Sie die Kompasskalibrierung, indem Sie auf die Schaltfläche |app_cali_e| klicken.

Stellen Sie das Zeus-Auto auf den Boden. Nach dem Aktivieren der Kompasskalibrierung beginnt das Auto, sich gegen den Uhrzeigersinn zu drehen und stoppt nach etwa 1 Minute. Wenn es länger als 2 Minuten dreht, ist das Magnetfeld hier kompliziert. Versuchen Sie, den Standort zu wechseln und erneut zu kalibrieren.


.. _ar_app_drift:

Drift aktivieren(J)
---------------------

Klicken Sie auf die Schaltfläche |app_drift_j|, um die Drift-Funktion zu aktivieren.

* Wenn Sie das Widget |app_rotate_q| gegen den Uhrzeigersinn verschieben, wird das Zeus-Auto nach rechts driften. Beim Loslassen der Hand wird das Auto an seiner aktuellen Position anhalten.

    .. image:: img/zeus_drift_left.jpg
        :width: 600
        :align: center

* Ähnlich wird das Zeus-Auto nach links driften, wenn Sie das Widget |app_rotate_q| im Uhrzeigersinn verschieben und an der aktuellen Position anhalten.

.. image:: img/zeus_drift_right.jpg
    :width: 600
    :align: center


.. _ar_app_move:

In alle Richtungen bewegen(K)
----------------------------------

Das Zeus-Auto bewegt sich in die entsprechende Richtung, wenn Sie das Widget |app_move_k| wischen.

.. image:: img/joystick_move.png
    :align: center

Das Auto bewegt sich jedes Mal, wenn Sie wischen. Wenn Sie Ihre Hand die ganze Zeit nicht loslassen, bleibt das Auto in Bewegung.

.. image:: img/zeus_move.jpg


.. _ar_app_line_track:

Linie(N)
--------------

Klicken Sie auf das Widget |app_line_n|, um in den Linienverfolgungsmodus zu wechseln.

Es stehen zwei Modi der Linienverfolgung im Zeus-Auto zur Verfügung: Ein Modus, bei dem der Kopf stets in Bewegungsrichtung zeigt, und ein Modus, bei dem der Kopf in eine feste Richtung zeigt. Hier wird der zweite Modus ausgewählt.

1. Legen Sie eine 3 cm breite Linie an.

    Es gibt acht Sensoren am Omni-Graustufen-Modul und der Abstand zwischen jedem Sensor liegt zwischen 2 und 3 cm. Mindestens zwei Sensoren müssen die schwarze Linie gleichzeitig erkennen. Daher muss die von Ihnen angelegte Linie mindestens 3 cm breit sein und der Biegungswinkel darf nicht kleiner als 90° sein.

    .. image:: img/map.png
        :width: 800

2. Kalibrieren Sie das Omni-Graustufen-Modul.

    Da jeder Untergrund unterschiedliche Graustufenwerte hat, ist der werkseitig eingestellte Graustufen-Schwellenwert möglicherweise nicht für Ihre aktuelle Umgebung geeignet. Daher müssen Sie dieses Modul vor der Verwendung kalibrieren. Es wird empfohlen, dies bei jeder wesentlichen Bodenfarbänderung erneut durchzuführen.

    * Stellen Sie das Zeus-Auto auf eine weiße Oberfläche und drehen Sie das Potentiometer so, dass das graue Sensorsignal gerade aufleuchtet.

        .. image:: img/zeus_line_calibration.jpg

    * Lassen Sie die beiden Graustufensensoren an der Seite genau zwischen der schwarzen Linie und der weißen Oberfläche positionieren und drehen Sie das Potentiometer langsam, bis die Signalanzeige gerade erlischt.

        .. image:: img/zeus_line_calibration1.jpg

    * Sie können mehrfach über die schwarze Linie und die weiße Oberfläche fahren, um sicherzustellen, dass die Lichter des Graustufensensors aus sind, wenn sie sich zwischen der schwarzen Linie und der weißen Oberfläche befinden, und an, wenn sie sich auf der weißen Oberfläche befinden. Dies zeigt an, dass das Modul erfolgreich kalibriert wurde.

3. Platzieren Sie das Zeus-Auto auf Ihrer angebrachten Linie, klicken Sie auf das Widget |app_line_n| und es wird der Linie folgen.

4. Aufgrund der hohen Umgebungsanforderungen des Omni-Graustufen-Moduls wird empfohlen, es mehrmals zu kalibrieren, wenn der Verfolgungseffekt nicht zufriedenstellend ist (Abweichen von der Linie).

.. _ar_app_follow:

Folgen(O)
------------

Klicken Sie auf das Widget |app_follow_o|, um in den Folgemodus zu wechseln.

Der Ultraschallsensor erkennt Hindernisse vorne (20 cm) und folgt ihnen. Diese beiden Hindernisvermeidungsmodule ermöglichen es dem Auto, nach links oder rechts zu folgen, müssen jedoch vor der Verwendung kalibriert werden (15cm).

1. Kalibrieren Sie das IR-Hindernisvermeidungsmodul.

    * Platzieren Sie ein Hindernis etwa 15 cm vom IR-Hindernisvermeidungsmodul entfernt.
    * Am Modul befinden sich zwei Potentiometer, eines zur Anpassung der Sendeleistung und eines zur Anpassung der Sendefrequenz. Durch Anpassen dieser beiden Potentiometer können Sie den Erfassungsabstand einstellen.
    * Dann können Sie ein Potentiometer einstellen und wenn bei 15cm das Signallicht am Modul aufleuchtet, ist die Einstellung erfolgreich; wenn nicht, stellen Sie das andere Potentiometer ein.

        .. image:: img/zeus_ir_avoid.jpg

    * Kalibrieren Sie das andere Hindernisvermeidungsmodul auf die gleiche Weise.

2. Stellen Sie das Zeus-Auto auf einen Tisch oder den Boden und lassen Sie es Ihrer Hand oder anderen Hindernissen folgen.

.. _ar_app_avoid:

Vermeiden(p)
------------------------

Wenn Sie in den Hindernisvermeidungsmodus wechseln möchten, klicken Sie auf das Widget |app_avoid_p|. Beachten Sie jedoch zuerst die Referenz :ref:`app_follow`, um die beiden Hindernisvermeidungsmodule zu kalibrieren.

* Das Zeus-Auto fährt vorwärts.
* Ein Ultraschallmodul erkennt Hindernisse vorne. Wenn ein Hindernis erkannt wird, dreht sich das Auto nach links.
* Wenn das linke Hindernisvermeidungsmodul ein Hindernis erkennt, dreht sich das Auto nach rechts und wenn das rechte Hindernisvermeidungsmodul ein Hindernis erkennt, dreht sich das Auto nach links.

.. _ar_app_rotate_drift:

Die Richtung steuern(Q)
-------------------------------

* Wenn die Schaltfläche |app_drift_j| aktiviert ist, wird das Widget |app_rotate_q| verwendet, um das Zeus-Auto links und rechts driften zu lassen.

* Wenn das Widget |app_drift_j| deaktiviert ist, wird das Widget |app_rotate_q| verwendet, um die Richtung des Auto-Kopfes zu steuern.

    * Wenn Sie das Widget |app_rotate_q| gegen den Uhrzeigersinn verschieben, wird das Auto ebenfalls gegen den Uhrzeigersinn drehen. Wenn Sie die Hand loslassen, kehrt der Kopf des Autos in die ursprüngliche Richtung zurück.

    .. image:: img/zeus_turn_left.jpg
        :width: 600
        :align: center

    * Ebenso wird das Auto mit dem Widget |app_rotate_q| im Uhrzeigersinn drehen und bei Loslassen in die ursprüngliche Richtung zurückkehren.

    .. image:: img/zeus_turn_right.jpg
        :width: 600
        :align: center
