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

#. Nachdem der Code erfolgreich hochgeladen wurde, können Sie das ESP32-CAM einstecken und dann den Stromschalter auf EIN schieben, um das Zeus-Auto zu starten.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center

#. Schalten Sie den Upload-Schalter auf die Seite von "Run" (rechte Seite in dieser Darstellung), um die ESP32 CAM zu starten.

    .. image:: img/zeus_run.jpg

#. Drücken Sie die Reset-Taste, um das Programm des Arduino-Boards erneut zu starten.

    .. image:: img/zeus_reset_button.jpg

#. Verbinden Sie sich mit dem ``Zeus_Car`` WLAN.

    Verbinden Sie nun Ihr Mobilgerät mit dem lokalen Netzwerk (LAN), das vom Zeus Car bereitgestellt wird. Auf diese Weise befinden sich Ihr Mobilgerät und der Zeus Car im selben Netzwerk, was die Kommunikation zwischen den Anwendungen auf Ihrem Mobilgerät und dem Zeus Car erleichtert.
    

    * Finden Sie ``Zeus_Car`` im WLAN Ihres Mobiltelefons (Tablet), geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit.


    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:80%">
                <source src="../_static/video/connect_wifi.mp4"  type="video/mp4">
                Ihr Browser unterstützt das Video-Tag nicht.
            </video>
        </div>

    .. raw:: html
        
        <br/>

    * Der Standardverbindungsmodus ist der AP-Modus. Nach der Verbindung erhalten Sie daher eine Meldung, dass dieses WLAN-Netzwerk keinen Internetzugang hat. Bitte wählen Sie "Weiter verbinden".

    .. image:: img/app_no_internet.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Erstellen Sie einen Controller.

    * Um auf dem SunFounder Controller einen Controller hinzuzufügen, klicken Sie auf das **+** Symbol.

    .. image:: img/app1.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Voreingestellte Controller sind für einige Produkte verfügbar. Hier wählen wir **Zeus Car**. Geben Sie ihm einen Namen oder tippen Sie einfach auf **Confirm**.

    .. image:: img/app_preset.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Einmal drinnen, wird die App automatisch nach dem Zeus Car suchen. Nach einer Weile erscheint eine Meldung, die besagt "Connected Successfully".

    .. image:: img/app_edit.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/> 

    * Tippen Sie nun auf die |app_run| Schaltfläche. Dadurch können Sie das Live-Video von der Kamera anzeigen und das Auto mit den bereitgestellten Widgets steuern.
    
    .. image:: img/app_run123.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Hier sind die Funktionen der Widgets.

        * :ref:`app_compass_cali`: Kompasskalibrierung einschalten.
        * **Stop(F)**: Stoppen Sie alle Bewegungen des Autos.
        * **Reset Heading(G)**: Nachdem Sie das Auto manuell in eine Richtung ausgerichtet haben, klicken Sie auf dieses Widget, um diese Richtung als Vorderseite der Autobewegung festzulegen. Damit können Sie schnell eine Richtung angeben, anstatt das Auto langsam mit anderen Widgets in diese Richtung zu drehen.
        * :ref:`app_speech_control`: Wechseln Sie in den Sprachsteuerungsmodus.
        * :ref:`app_drift`: Aktivieren Sie die Drift-Funktion.
        * :ref:`app_move`: Steuern Sie das Auto in alle Richtungen.
        
        * :ref:`app_line_track`: Die folgenden beiden Widgets können beide in den Linienverfolgungsmodus wechseln.
        
            * **Linie ohne Mag(M)**: Wechseln Sie in den Linienverfolgungsmodus, der nicht vom Magnetfeld beeinflusst wird. Während des Linienverfolgungsvorgangs wird sich die Ausrichtung des Zeus Car ständig ändern.
            * **Linie(N)**: Wechseln Sie in den Linienverfolgungsmodus. Aufgrund des Vorhandenseins eines Magnetfelds wird sich die Ausrichtung des Zeus Car während der Linienverfolgung in eine bestimmte Richtung orientieren.

        * :ref:`app_follow`: Wechseln in den Verfolgungsmodus.
        * :ref:`app_avoid`: Wechseln in den Hindernisvermeidungsmodus.
        * :ref:`app_rotate_drift`: Dient zur Steuerung der Kopfrichtung.


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
