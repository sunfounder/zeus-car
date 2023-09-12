16. KI-Erkennung von der APP
===================================================

In diesem Projekt verwenden wir eine App - SunFounder Controller - um Echtzeit-Video-Streaming zu betrachten und die KI-Erkennungsfunktionen auf Ihrem mobilen Gerät, wie Gesichts- und Pose-Erkennung, zu nutzen.

Der SunFounder Controller ist eine Anwendung, die es Benutzern ermöglicht, den Controller für die Steuerung ihres Roboters oder als IoT-Plattform anzupassen. Diese App integriert 11 verschiedene Anzeige- und Steuerungs-Widgets, wie Button, Joystick, Anzeigeinstrument und Radar. Die Controller-Seite verfügt über 17 Bereiche von A~Q, in denen Sie unterschiedliche Widgets platzieren können, um Ihren eigenen Controller zu gestalten.

Sehen Sie sich nun an, wie Sie die App auf einfache Weise nutzen können.

**Wie geht das?**

#. Das ESP32-CAM und das Arduino-Board verwenden dieselben RX (Empfang) und TX (Senden) Pins. Wenn Sie also Code hochladen, müssen Sie zuerst das ESP32-CAM trennen, um Konflikte oder mögliche Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``16_ai_detection_from_app.ino`` unter dem Pfad ``zeus-car-main\examples\16_ai_detection_from_app``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/c14c46e7-2e43-4b31-b7e6-b7718e501e96/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem der Code erfolgreich hochgeladen wurde, können Sie das ESP32-CAM einstecken und dann den Stromschalter auf EIN schieben, um das Zeus-Auto zu starten.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center

#. Schalten Sie den Upload-Schalter zur Seite "Run" (auf diesem Diagramm die rechte Seite), um das ESP32 CAM zu starten. 

    .. image:: img/zeus_run.jpg

#. Drücken Sie die Reset-Taste, um das Programm des Arduino-Boards erneut zu starten.

    .. image:: img/zeus_reset_button.jpg

#. Installieren Sie nun `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ aus dem **APP Store(iOS)** oder **Google Play(Android)** auf Ihrem mobilen Gerät.

#. Verbinden Sie sich mit dem WLAN ``Zeus_Car``.

    * Finden Sie ``Zeus_Car`` im WLAN Ihres Mobiltelefons (Tablet), geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit.

    .. image:: img/app_wlan.png

    * Der Standardverbindungsmodus ist der AP-Modus. Nach der Verbindung erhalten Sie eine Meldung, dass dieses WLAN-Netzwerk keinen Internetzugang bietet. Bitte wählen Sie "Trotzdem verbinden".

    .. image:: img/app_no_internet.png

#. Öffnen Sie anschließend die App und erstellen Sie einen Controller.

    * Um einen Controller im SunFounder Controller hinzuzufügen, klicken Sie auf das **+** Symbol.

        .. image:: img/app1.png

    * Wählen Sie das **Blank** und **Dual Stick** Template und geben Sie ihm einen Namen.

        .. image:: img/view_app1.jpg

    * Wenn Sie sich nun im Controller befinden, klicken Sie auf das |app_camera| Symbol, um die KI-Erkennungsfunktion zu aktivieren. Sie finden Optionen sowohl für die Gesichtserkennung als auch für die Pose-Erkennung.

        .. image:: img/view_app6.jpg

    * Speichern Sie alle Einstellungen, indem Sie auf den |app_save| Button klicken. Da keine Widgets ausgewählt wurden, ist der Bildschirm komplett schwarz.

        .. image:: img/view_app3.jpg

    * Der nächste Schritt ist, das Zeus Car mit Ihrem Gerät über den |app_connect| Button zu verbinden. Warten Sie ein paar Sekunden und ``Zeus_Car(IP)`` wird angezeigt, klicken Sie darauf, um die Verbindung herzustellen.

        .. image:: img/view_app4.jpg

        .. note::
            Bitte stellen Sie sicher, dass Ihr WLAN mit ``Zeus_Car`` verbunden ist, falls Sie die obige Nachricht längere Zeit nicht sehen.

#. Starten Sie den Controller.

    Nachdem die Nachricht "Connected Successfully" erscheint, klicken Sie auf den |app_run| Button, dann wird das Kamerabild in der App angezeigt.

    Wenn Sie die Gesichtserkennung aktiviert haben, wird das im Bildschirm erscheinende Gesicht umrahmt.

    .. image:: img/view_app7.jpg

    Ist die Pose-Erkennung aktiviert, wird die Pose dargestellt.

    .. image:: img/view_app8.jpg

    .. note::

        Wenn Sie zu einer anderen KI-Erkennung wechseln möchten, klicken Sie auf das |app_edit| Symbol und wiederholen Sie die oben genannten Schritte.
