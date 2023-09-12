.. _ar_app_control:

17. APP-Steuerung
=====================

Im vorherigen Projekt haben wir uns einfach die Aufnahmen der Kamera angesehen und die AI-Erkennungsfunktion im SunFounder Controller verwendet.

In diesem Projekt werden wir versuchen, die Bewegung und Richtung des Zeus Autos mit dem Joystick-Widget in der App zu steuern. Schauen wir uns also an, wie das funktioniert.


.. note::
    Bitte installieren Sie den `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ aus dem **APP Store(iOS)** oder **Google Play(Android)**.


**Wie geht das?**

#. Der ESP32-CAM und das Arduino-Board verwenden die gleichen RX (Empfang) und TX (Übertragung) Pins. Beim Hochladen des Codes müssen Sie daher zuerst den ESP32-CAM trennen, um Konflikte oder mögliche Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Öffnen Sie die Datei ``17_app_control.ino`` im Pfad ``zeus-car-main\examples\17_app_control``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/5d65d2b4-5ed7-4d21-ba3b-02529ee8dd6c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Nachdem der Code erfolgreich hochgeladen wurde, können Sie das ESP32-CAM einstecken und dann den Stromschalter auf EIN schieben, um das Zeus-Auto zu starten.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center

#. Wechseln Sie den Upload-Schalter auf die Seite "Run" (rechte Seite auf diesem Diagramm), um die ESP32 CAM zu starten. 

    .. image:: img/zeus_run.jpg

#. Drücken Sie die Reset-Taste, um das Programm des Arduino-Boards erneut zu starten.

    .. image:: img/zeus_reset_button.jpg

#. Verbinden Sie sich mit dem ``Zeus_Car`` WLAN.

    * Finden Sie ``Zeus_Car`` im WLAN Ihres Mobiltelefons (Tablet), geben Sie das Passwort ``12345678`` ein und stellen Sie die Verbindung her.

    .. image:: img/app_wlan.png

    * Der Standardverbindungsmodus ist der AP-Modus. Nach der Verbindung wird angezeigt, dass dieses WLAN-Netzwerk keinen Internetzugang hat. Wählen Sie weiterhin "Verbinden".

    .. image:: img/app_no_internet.png

#. Erstellen Sie einen Controller.

    * Um einen Controller im SunFounder Controller hinzuzufügen, klicken Sie auf das **+** Symbol.

        .. image:: img/app1.png

    * Einige Produkte haben im Abschnitt "Voreinstellungen" bereits vorgefertigte Controller. Wir wählen hier jedoch ein **Blanko** und **Dual Stick** Template.

        .. image:: img/app_blank.PNG

   * Klicken Sie im Bereich J auf das + Symbol und wählen Sie ein Schalter-Widget. Möglicherweise müssen Sie nach links wischen, um das Widget zu sehen.

        .. image:: img/app_switch_wid.png

        .. note::
            Wenn Sie denken, dass Sie das falsche Widget ausgewählt haben, können Sie darauf klicken und es mit der Löschtaste entfernen.

            .. image:: img/app_delete.png

    * Klicken Sie auf das Einstellungssymbol in der oberen rechten Ecke, um ihm einen Namen zu geben.

        .. image:: img/app_name_dirft.png

    * Wählen Sie im Bereich K und Q ein Joystick-Widget und benennen Sie beide Widgets. Nutzen Sie dann die |app_save| Taste, um den Controller zu speichern.

    .. image:: img/app_joystick_wid.png

    * Der nächste Schritt ist, das Zeus Auto über die |app_connect| Taste mit Ihrem Gerät zu verbinden. Warten Sie einige Sekunden, und ``Zeus_Car(IP)`` wird angezeigt. Klicken Sie darauf, um die Verbindung herzustellen.

        .. image:: img/app_connect.png

        .. note::
            Bitte stellen Sie sicher, dass Ihr WLAN mit ``Zeus_Car`` verbunden ist, wenn Sie die oben genannte Nachricht lange nicht sehen.


#. Starten Sie den Controller.

    Nachdem die Nachricht "Erfolgreich verbunden" erscheint, klicken Sie auf die |app_run| Taste. Die Kameraaufnahme wird in der App angezeigt und nun können Sie Ihr Zeus Auto mit diesen Widgets steuern.

    Die Funktionen der drei Widgets sind wie folgt:

    **In alle Richtungen bewegen(K)**

    Das Zeus Auto wird sich in die entsprechende Richtung bewegen, wenn Sie das |app_move_k| Widget wischen.

    .. image:: img/joystick_move.png
        :align: center

    Das Auto bewegt sich jedes Mal, wenn Sie wischen. Lassen Sie Ihre Hand nicht los, bewegt sich das Auto weiter.

    .. image:: img/zeus_move.jpg

    **Drift aktivieren(J)**

    Klicken Sie auf die |app_drift_j| Taste, um die Drift-Funktion zu aktivieren.

    * Wenn Sie das |app_rotate_q| Widget gegen den Uhrzeigersinn schieben, wird das Zeus Auto nach rechts driften. Beim Loslassen stoppt das Auto an seiner aktuellen Position.

        .. image:: img/zeus_drift_left.jpg
            :width: 600
            :align: center

    * Gleichermaßen wird das Zeus Auto nach links driften, wenn Sie das |app_rotate_q| Widget im Uhrzeigersinn schieben und an der aktuellen Position stoppen.

    .. image:: img/zeus_drift_right.jpg
        :width: 600
        :align: center

    **Die Richtung steuern(Q)**

    * Ist die |app_drift_j| Taste aktiviert, wird das |app_rotate_q| Widget verwendet, um das Zeus Auto links und rechts driften zu lassen.

    * Ist das |app_drift_j| Widget deaktiviert, steuert das |app_rotate_q| Widget die Richtung des Auto-Kopfes.

        * Beim Schieben des |app_rotate_q| Widgets gegen den Uhrzeigersinn wird das Auto ebenfalls gegen den Uhrzeigersinn drehen. Nach dem Loslassen kehrt der Kopf des Autos in die Ausgangsrichtung zurück.

        .. image:: img/zeus_turn_left.jpg
            :width: 600
            :align: center

        * Entsprechend dreht sich das Auto im Uhrzeigersinn mit dem |app_rotate_q| Widget und kehrt beim Loslassen in die Ausgangsrichtung zurück.

        .. image:: img/zeus_turn_right.jpg
            :width: 600
            :align: center
