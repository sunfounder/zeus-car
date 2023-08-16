1. Grundbewegungen
========================

In diesem Projekt lernen Sie, wie Sie das Zeus-Auto in alle Richtungen bewegen können.

.. raw:: html

   <video loop autoplay muted style="max-width:80%">
      <source src="../_static/video/basic_movement.mp4" type="video/mp4">
      Ihr Browser unterstützt das Video-Tag nicht.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Wie geht das?**

#. ESP32-CAM und das Arduino-Board nutzen dieselben RX (Empfang) und TX (Senden) Pins. Beim Hochladen des Codes sollten Sie daher zunächst den ESP32-CAM trennen, um mögliche Konflikte oder Probleme zu vermeiden.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Verbinden Sie das Zeus-Auto über das blaue USB-Kabel mit Ihrem Computer. Wenn Sie Ihr Arduino-Board anschließen, erkennt der Computer es automatisch und weist ihm einen COM-Port zu, den Sie im Geräte-Manager einsehen können.

#. Öffnen Sie die Datei ``1_basic_move.ino`` im Pfad ``zeus-car-main\examples\1_basic_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/cedd4eb2-3283-48ae-8851-c932eb2098ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Hier können Sie schnell das Board und den Port auswählen.

    .. image:: img/ar_board.png

    .. note::
        Falls COMxx nicht erscheint, öffnen Sie den Board Manager links und stellen Sie sicher, dass der Core "Arduino AVR Boards" installiert ist.

        .. image:: img/ar_other_board.png

#. Klicken Sie nun auf den **Hochladen**-Button, um den Code auf das Arduino-Board zu übertragen. Wenn dies abgeschlossen ist, wird eine Benachrichtigung im unteren rechten Bereich Ihres IDE-Fensters angezeigt. Natürlich können beim Hochladen manchmal Fehler auftreten, die dann hier ebenfalls aufgelistet werden.

    .. note::
        * Wenn Sie eine "Compilation error: SoftPWM.h: Datei oder Verzeichnis nicht gefunden" Meldung erhalten, bedeutet dies, dass Sie die ``SoftPWM`` Bibliothek nicht installiert haben.
        * Befolgen Sie die Anweisungen unter :ref:`ar_install_library`, um die beiden benötigten Bibliotheken ``SoftPWM`` und ``IRLremote`` zu installieren.

    .. image:: img/ar_upload.png

#. Starten wir das Zeus-Auto.

    * Bei der ersten Verwendung oder wenn das Batteriekabel getrennt ist, aktiviert das Zeus Car Shield seinen Überentladungsschutz.
    * Daher müssen Sie das Type-C-Kabel für etwa 5 Sekunden einstecken.

            .. image:: img/zeus_charge.jpg

    * Wenn die Stromanzeige leuchtet, bedeutet dies, dass der Schutzstatus aufgehoben wurde. Schauen Sie zu diesem Zeitpunkt auf die Batterieanzeigen; wenn beide Batterieanzeigen aus sind, stecken Sie das Type-C-Kabel weiterhin ein, um die Batterie aufzuladen.

        .. image:: img/zeus_power.jpg

#. Das Zeus-Auto wird nun eine Sekunde lang in jede Richtung fahren.

    .. image:: img/zeus_move.jpg
        :width: 600

**Wie funktioniert es?**

Diese Bewegungen werden durch die Zusammenarbeit der 4 Mecanum-Räder erzielt. Wenn beispielsweise alle vier Räder gleichzeitig vorwärts oder rückwärts fahren, fährt auch das Auto vorwärts oder rückwärts. Zwei Räder vorwärts und zwei Räder rückwärts können das Auto zum Schwenken oder Drehen nach links oder rechts veranlassen.

Schauen wir uns an, wie diese Bewegungen genau erreicht werden.

* Vorwärts und rückwärts bewegen, links und rechts schwenken.

    .. image:: img/ar_fwlr.jpg
        :width: 600

* Diagonal schwenken

    .. image:: img/ar_fblr.jpg
        :width: 600

* Links und rechts drehen

    .. image:: img/ar_turn_lr.jpg
        :width: 600
