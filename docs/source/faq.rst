.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

FAQ  
================ 

So ändern Sie den Wi-Fi-Kanal  
----------------------------------  

Das 2,4-GHz-Wi-Fi-Band hat Kanäle von 1 bis 13. Der ESP32 unterstützt die Kanäle 1 bis 11. Andere Geräte, die denselben Kanal verwenden, können Störungen verursachen, was zu Verbindungsproblemen führen kann. Um dies zu vermeiden, können Sie den Kanal ändern. Standardmäßig ist der Kanal auf 1 eingestellt. Es wird empfohlen, beim Wechsel des Kanals 1-2 Kanäle gleichzeitig zu überspringen. Zum Beispiel, wenn der aktuelle Kanal 1 ist, versuchen Sie zuerst Kanal 3 und bei weiterhin schlechtem Signal Kanal 5.

.. note::

   Für das Ändern des WLAN-Kanals ist die ESP32 CAM-Firmware-Version **1.4.1 oder höher** erforderlich. Weitere Informationen finden Sie unter :ref:`update_firmware`.

#. Lassen Sie den ESP32 CAM im Adapter eingesteckt und schalten Sie das Zeus Car ein.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Schalten Sie den ESP32 CAM ein, indem Sie den Modusschalter in die **Run**-Position bewegen und die **Reset**-Taste drücken, um die R3-Platine neu zu starten.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Suchen Sie auf Ihrem Mobilgerät (Tablet oder Smartphone) in der Liste der verfügbaren Netzwerke nach ``Zeus_Car-XXXXXX``, geben Sie das Passwort ``12345678`` ein und verbinden Sie sich damit. ``XXXXXX`` sind die letzten sechs Zeichen der MAC-Adresse des ESP32 CAM, der Hotspot-Name ist also bei jedem Fahrzeug anders.

   .. note::

        * Die aktuelle Verbindung erfolgt über den Hotspot des Zeus Cars, daher besteht kein Internetzugang. Wenn Sie aufgefordert werden, das Netzwerk zu wechseln, wählen Sie bitte "Verbunden bleiben".

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Öffnen Sie einen Webbrowser auf Ihrem Mobilgerät und rufen Sie ``http://192.168.4.1`` auf, um die Einstellungsseite des ESP32 CAM zu öffnen.

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: Die Einstellungsseite sieht je nach Firmware-Version des ESP32 CAM unterschiedlich aus. Version A (Firmware 1.4.x) ist eine einzelne Seite, auf der die WLAN- und OTA-Optionen zusammen liegen, während Version B (Firmware 1.5.x und höher) die Tabs **Base**, **AP**, **WIFI**, **Camera** und **OTA** hat. Befolgen Sie die Schritte, die zur angezeigten Oberfläche passen.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**Version A** (Firmware 1.4.x)

   5. Wählen Sie im Abschnitt **Wi-Fi AP Channel** einen anderen Kanal aus und klicken Sie dann auf die Schaltfläche **Bestätigen**.

      * Der Standardkanal ist 1. Überspringen Sie beim Wechsel 1-2 Kanäle gleichzeitig (z. B. von Kanal 1 zu 3 und, falls erforderlich, zu 5).

      .. image:: img/faq_cam_ota_channel.png
         :width: 400

   #. Ein Bestätigungs-Popup wird angezeigt, das Sie auffordert, das Gerät zurückzusetzen. Klicken Sie auf **Bestätigen**.

      .. image:: img/faq_cam_ota_reset.jpg
         :width: 400

   #. Drücken Sie die **Reset**-Taste auf der R3-Platine, um den ESP32 CAM neu zu starten. Das Zeus Car ist jetzt bereit für den normalen Betrieb.

      .. image:: img/zeus_run123.jpg
         :width: 600

**Version B** (Firmware 1.5.x und höher)

   5. Klicken Sie im Seitenmenü auf **AP** (oder tippen Sie unten auf den Tab **AP**) und wählen Sie in der Liste **AP Channel** einen anderen Kanal aus.

      * Der Standardkanal ist 1. Überspringen Sie beim Wechsel 1-2 Kanäle gleichzeitig (z. B. von Kanal 1 zu 3 und, falls erforderlich, zu 5).

      .. image:: img/faq_change_channel.jpg
         :width: 400

   #. Wenn oben auf der Seite das Banner "Reboot to take effect." erscheint, klicken Sie auf **REBOOT**. Das Zeus Car ist jetzt bereit für den normalen Betrieb.

.. _update_firmware:  

So aktualisieren Sie die Firmware für ESP32 CAM  
-----------------------------------------------------------  

Der ESP32 CAM stellt den WLAN-Hotspot bereit und liefert das Kamerabild für das Zeus Car.
Ist die Firmware veraltet, funktionieren diese Funktionen möglicherweise nicht richtig. Befolgen Sie die folgenden Schritte, um die Firmware zu aktualisieren.

#. Lassen Sie den ESP32 CAM im Adapter eingesteckt und schalten Sie das Zeus Car ein.

   .. image:: img/plug_esp32_cam.jpg
      :width: 400

#. Schalten Sie den ESP32 CAM ein, indem Sie den Modusschalter in die **Run**-Position bewegen und die **Reset**-Taste drücken, um die R3-Platine neu zu starten.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Laden Sie die Firmware-Datei herunter.

   * Öffnen Sie `das neueste ESP32 CAM-Firmware-Release <https://github.com/sunfounder/ai-camera-firmware/releases/latest>`_ — die Versionsnummer der aktuellen Firmware steht oben auf der Seite.
   * Laden Sie in der Liste **Assets** die Datei ``ai-camera-firmware.vX.X.X-ota.bin`` herunter. Die Datei ``-factory.bin`` in derselben Liste ist zum Flashen des Moduls mit einem Programmer gedacht und wird für dieses Update nicht verwendet.

   .. image:: img/faq_firm_download.png
      :width: 600

#. Verbinden Sie Ihr Mobilgerät mit dem WLAN des Zeus Cars.

   * Der Netzwerkname (SSID) ist ``Zeus_Car-XXXXXX``, wobei ``XXXXXX`` die letzten sechs Zeichen der MAC-Adresse des ESP32 CAM sind, und das Passwort ist ``12345678``.
   * Wenn eine Warnung "Kein Internetzugang" erscheint, wählen Sie die Option **"Verbunden bleiben"**.

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Öffnen Sie einen Webbrowser auf Ihrem Mobilgerät und rufen Sie ``http://192.168.4.1`` auf, um die Einstellungsseite des ESP32 CAM zu öffnen.

   .. image:: img/faq_ota_home.jpg
      :width: 400

.. note:: Auf dieser Seite sehen Sie die OTA-Upgrade-Optionen in einer von zwei Oberflächen. Version A (die erste) und Version B (die zweite) erscheinen je nach Firmware-Version. Wählen Sie die Schritte, die zu der Oberfläche passen, die Sie sehen.

   .. image:: img/firmware_access_ab.png
      :width: 80%
      :align: center

**Version A** (Firmware 1.4.x)

   6. Wählen Sie auf der OTA-Seite die Firmware-Datei aus und starten Sie das Update:

      * Wählen Sie die zuvor heruntergeladene Datei ``ai-camera-firmware.vX.X.X-ota.bin`` von Ihrem Gerät aus und klicken Sie auf **Add**.
      * Klicken Sie auf die Schaltfläche **Update**, um das Firmware-Update zu starten, und warten Sie, bis es abgeschlossen ist.

      .. image:: img/faq_ota_a.png
         :width: 700

   #. Nach Abschluss des Updates ändert sich der Hotspot-Name des Zeus Cars in ``AI Camera-XXXXXX``, das Passwort bleibt ``12345678``. Drücken Sie die **Reset**-Taste auf der R3-Platine, damit sich das Fahrzeug wieder mit seinem Namen registriert; der Hotspot heißt dann wieder ``Zeus_Car-XXXXXX``.

**Version B** (Firmware 1.5.x und höher)

   6. Prüfen Sie auf der Seite **OTA** die dort angezeigte aktuelle Firmware-Version.

      .. image:: img/faq_upgrade.jpg
         :width: 400
         :align: center

   #. Tippen Sie auf **Upgrade Firmware**, wählen Sie die Firmware-Datei aus und warten Sie, bis das Update abgeschlossen ist:

      * Tippen Sie auf die Schaltfläche **Upgrade Firmware** und wählen Sie die zuvor heruntergeladene Datei ``ai-camera-firmware.vX.X.X-ota.bin`` von Ihrem Gerät aus.
      * Das Update startet sofort und dauert normalerweise 1-2 Minuten. Wählen Sie nach Abschluss **CONFIRM**, um das Zeus Car neu zu starten.

      .. image:: img/faq_ota_b.png
         :width: 700

   #. Nach Abschluss des Updates ändert sich der Hotspot-Name des Zeus Cars in ``AI Camera-XXXXXX``, das Passwort bleibt ``12345678``. Drücken Sie die **Reset**-Taste auf der R3-Platine, damit sich das Fahrzeug wieder mit seinem Namen registriert; der Hotspot heißt dann wieder ``Zeus_Car-XXXXXX``.

.. _upload_zeus_code:

Wie lädt man den ``zeus-car.ino``-Code hoch?  
-----------------------------------------------  

Standardmäßig ist die Uno R3-Platine des Zeus Cars mit der notwendigen Firmware vorinstalliert, sodass Sie es über die APP steuern können. Wenn Ihre R3-Platine mit anderem Code überschrieben wurde und Sie zur Standard-Firmware zurückkehren und mit dem :ref:`quick_start`-Prozess fortfahren möchten, folgen Sie diesen Schritten, um den Code erneut auf Ihre R3-Platine hochzuladen:  

#. Verbinden Sie das Arduino mit einem USB-Kabel mit Ihrem Computer. Der ESP32-CAM und die Arduino-Platine teilen sich dieselben RX- (Empfangs-) und TX- (Sende-) Pins. Daher müssen Sie den ESP32-CAM zunächst trennen, um Konflikte oder mögliche Probleme zu vermeiden.  

   .. image:: img/unplug_cam.png  
        :width: 400  

#. Laden Sie die erforderliche Firmware über den folgenden Link herunter:  

   * :download:`R3 Board Firmware File <https://github.com/sunfounder/zeus-car/releases/download/1.4.5/zeus-car-1.4.5.zip>`  

#. Entpacken Sie die heruntergeladene ZIP-Datei und doppelklicken Sie auf die Datei ``update-arduino-firmware.bat``, um sie auszuführen.  

   .. image:: img/faq_firmware_file.png  

#. Geben Sie die entsprechende Nummer für das Arduino Uno Ihres Zeus Cars ein (z. B. ``1``) und drücken Sie **Enter**, um das Update zu starten.  

   .. note::  

     * Wenn der richtige COM-Port nicht angezeigt wird oder Sie unsicher sind, welcher es ist, trennen Sie andere USB-Geräte von Ihrem Computer und lassen nur den Rover angeschlossen.  
     * Wenn ein Fehler wie ``avrdude.exe: stk500_getsync() attempt 1 of 10: not in sync: resp=0xXX`` auftritt, stellen Sie sicher, dass der ESP32-CAM im ersten Schritt getrennt wurde.  

   .. image:: img/faq_firmware_port.png  

#. Nach kurzer Zeit wird der neue Code erfolgreich auf die Uno R3-Platine des Zeus Cars hochgeladen. Wenn das Hochladen nach mehreren Versuchen fehlschlägt, können Sie ``update-arduino-firmware-with-bootloader.bat`` ausführen.  

   .. image:: img/faq_firmware_finish.png  

.. _ap_to_sta:  

Wie steuert man das Zeus Car über das Heim-WiFi?  
-------------------------------------------------  
Standardmäßig ist der Uno R3 mit Code im APP-Modus vorinstalliert. Das bedeutet, dass das Zeus Car einen Hotspot sendet, sodass Sie Ihr Mobilgerät verbinden können, um es über die SunFounder Controller APP zu steuern.  

Wenn Sie das Fahrzeug lieber über Ihr Heim-WLAN steuern möchten, können Sie den ESP32 CAM mit Ihrem Heimnetzwerk verbinden. Die Kamera arbeitet weiterhin im AP + STA-Dualmodus, der Hotspot des Zeus Cars bleibt also ebenfalls verfügbar:

#. Schalten Sie das Zeus Car ein. Schalten Sie den ESP32 CAM ein, indem Sie den Modusschalter in die **Run**-Position bewegen und die **Reset**-Taste drücken, um die R3-Platine neu zu starten.

   .. image:: img/zeus_run123.jpg
      :width: 600

#. Verbinden Sie Ihr Mobilgerät mit dem WLAN des Zeus Cars.

   * Der Netzwerkname (SSID) ist ``Zeus_Car-XXXXXX``, wobei ``XXXXXX`` die letzten sechs Zeichen der MAC-Adresse des ESP32 CAM sind, und das Passwort ist ``12345678``.
   * Wenn eine Warnung "Kein Internetzugang" erscheint, wählen Sie die Option **"Verbunden bleiben"**.

   .. image:: img/faq_connect_zeuscar.jpg
        :width: 400

#. Öffnen Sie einen Webbrowser auf Ihrem Mobilgerät und rufen Sie ``http://192.168.4.1`` auf, um die Einstellungsseite des ESP32 CAM zu öffnen.

   .. image:: img/faq_ota_home.jpg
      :width: 400

#. Klicken Sie im Seitenmenü auf **WIFI** (oder tippen Sie unten auf den Tab **WIFI**) und geben Sie dann den Namen und das Passwort Ihres Heim-WLAN-Netzwerks ein.

   * Tragen Sie den Namen Ihres Heim-WLAN in **STA SSID** ein — Sie können ihn auch aus der gescannten Liste auswählen — und das Passwort in **STA password**.
   * Tippen Sie auf **CONFIRM**, um die Einstellungen zu speichern. Danach zeigt die Seite "Success, Restart to apply." an.
   * Nach dem Neustart zeigt die Seite **Base** unter **IP Address** die IP-Adresse an, die Ihr Router der Kamera zugewiesen hat.

   .. image:: img/faq_set_sta.jpg
      :width: 400

#. Starten Sie den ESP32 CAM neu: Klicken Sie auf der Seite auf **Reboot** oder drücken Sie die **Reset**-Taste auf der R3-Platine. Der ESP32 CAM verbindet sich nun mit Ihrem Heim-WLAN und behält gleichzeitig den Hotspot des Zeus Cars.

   .. note::

      Mit der ESP32 CAM-Firmware **1.5.4** und höher arbeitet die Kamera im AP + STA-Dualmodus, und der serielle Befehl ``MODE`` wird ignoriert. Das Ändern von ``WIFI_MODE``, ``SSID`` und ``PASSWORD`` im R3-Sketch schaltet die Kamera daher nicht mehr in den STA-Modus — konfigurieren Sie das Heim-WLAN wie oben beschrieben.

#. Stellen Sie sicher, dass Ihr Mobilgerät (Tablet oder Smartphone) mit Ihrem Heim-WiFi-Netzwerk verbunden ist.  

   .. image:: img/faq_connect_wifi.jpg  
        :width: 400  
        :align: center  

#. Öffnen Sie die SunFounder Controller App, tippen Sie auf das "+"-Symbol, um einen neuen Controller zu erstellen, wählen Sie die "Zeus Car"-Voreinstellung aus, geben Sie einen Namen ein oder tippen Sie auf "Bestätigen", um fortzufahren.  

   .. image:: img/app_preset.jpg  
        :width: 600  

#. Die App sucht automatisch nach dem Zeus Car. Nach kurzer Zeit erscheint eine Meldung mit der Aussage "Erfolgreich verbunden."  

   .. image:: img/app_edit.jpg  
        :width: 600  

#. Tippen Sie nun auf die |app_run|-Schaltfläche, um den Live-Video-Feed von der Kamera anzusehen und den Rover mit den bereitgestellten Widgets zu steuern.  

   .. image:: img/app_run123.png  
        :width: 600  

Wie dreht man die Kamera um?  
------------------------------  

Wenn das Kamerabild in der SunFounder Controller-App auf dem Kopf steht, können Sie es leicht über die App korrigieren. Gehen Sie wie folgt vor:  

1. Tippen Sie auf die |app_edit|-Schaltfläche in der oberen rechten Ecke.  

   .. image:: img/faq_edit.png  
        :width: 500  

2. Klicken Sie auf die **Kamera**-Schaltfläche, um ein Popup zu öffnen. Schalten Sie den **Invertiert**-Schalter ein.  

   .. image:: img/faq_inverted.png  
        :width: 500  

3. Speichern Sie Ihre Einstellungen.  

   .. image:: img/faq_save.png  
        :width: 500  

4. Kehren Sie zur Steueroberfläche zurück und klicken Sie auf die |app_run|-Schaltfläche.  

   .. note::  

        Gelegentlich erscheint das Kamerabild nicht. Sollte dies passieren, pausieren Sie den Controller und klicken Sie erneut auf die Starttaste.  

   .. image:: img/faq_run.png  
        :width: 500  


Alternativ können Sie die Kamera auch auf der Einstellungsseite des ESP32 CAM spiegeln: Verbinden Sie Ihr Mobilgerät mit dem WLAN des Zeus Cars, rufen Sie ``http://192.168.4.1`` auf und aktivieren Sie auf der Seite **Camera** die Option **Horizontal flip** oder **Vertical flip**.

.. image:: img/faq_camera.jpg
     :width: 400

Kompilierungsfehler: SoftPWM.h: Datei oder Verzeichnis nicht gefunden？
-----------------------------------------------------------------------------------------------------------------

Wenn die Meldung "Kompilierungsfehler: SoftPWM.h: Datei oder Verzeichnis nicht gefunden" erscheint, bedeutet dies, dass die ``SoftPWM`` Bibliothek nicht installiert ist.

Bitte beziehen Sie sich auf :ref:`ar_install_lib`.


avrdude: stk500_getsync() Versuch 10 von 10: nicht synchronisiert: resp=0x6e?
--------------------------------------------------------------------------------------------

Wenn die folgende Meldung immer wieder erscheint, nachdem Sie auf den Hochladen-Button geklickt haben und das Board und den Port korrekt ausgewählt haben:

.. code-block::

    avrdude: stk500_recv(): Programmierer antwortet nicht
    avrdude: stk500_getsync() Versuch 1 von 10: nicht synchronisiert: resp=0x00
    avrdude: stk500_recv(): Programmierer antwortet nicht
    avrdude: stk500_getsync() Versuch 2 von 10: nicht synchronisiert: resp=0x00
    avrdude: stk500_recv(): Programmierer antwortet nicht
    avrdude: stk500_getsync() Versuch 3 von 10: nicht synchronisiert: resp=0x00

Zu diesem Zeitpunkt sollten Sie sicherstellen, dass die ESP32 CAM nicht angeschlossen ist.

Die ESP32-CAM und das Arduino-Board teilen sich die gleichen RX (Empfang) und TX (Senden) Pins. Deshalb sollten Sie die ESP32-CAM vor dem Hochladen des Codes trennen, um mögliche Konflikte oder Probleme zu vermeiden.

.. image:: img/unplug_cam.png
    :width: 400
    :align: center

.. _stt_android:

Wie kann ich die STT-Funktion auf meinem Android-Gerät nutzen?
------------------------------------------------------------------------

Für die STT-Funktion muss das Android-Mobilgerät mit dem Internet verbunden sein und die **Google-Dienstkomponente** installiert haben.

Befolgen Sie nun die untenstehenden Schritte.

#. Verbinden Sie das Zeus Car mit Ihrem Heim-WLAN, damit sowohl das Fahrzeug als auch Ihr Mobilgerät Internetzugang haben. Befolgen Sie :ref:`ap_to_sta`, um das Heim-WLAN auf der Einstellungsseite des ESP32 CAM zu speichern — Sie müssen den Code ``Zeus_Car.ino`` nicht ändern oder erneut hochladen.

#. Suchen Sie in Google Play nach ``google`` und installieren Sie die unten gezeigte App.

    .. image:: img/google_voice.png

#. Verbinden Sie Ihr Mobilgerät mit demselben Heim-WLAN-Netzwerk.

    .. image:: img/sta_wifi.png
        :width: 400
        :align: center

    #. Öffnen Sie den zuvor in SunFounder Controller erstellten Controller und verbinden Sie ihn über die Schaltfläche |app_connect| mit dem Zeus Car.

    .. image:: img/app_connect.png
        :width: 500
        :align: center

#. Tippen und halten Sie das |app_speech_m| Widget gedrückt, nachdem Sie die Schaltfläche |app_run| angeklickt haben. Ein Hinweis wird angezeigt, dass zugehört wird. Sagen Sie den folgenden Befehl, um das Auto zu bewegen.

    * ``stop``: Alle Bewegungen des Autos können gestoppt werden.
    * ``pause``: Die Funktion ähnelt der von Stop, aber wenn die Vorderseite des Autos nicht in die ursprünglich eingestellte Richtung zeigt, wird es sich langsam in die eingestellte Richtung bewegen.
    * ``forward``
    * ``backward``
    * ``left forward``
    * ``left backward``
    * ``right forward``
    * ``right backward``
    * ``move left``
    * ``move right``
