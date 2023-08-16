FAQ
================

Kompilierungsfehler: SoftPWM.h: Datei oder Verzeichnis nicht gefunden？
-----------------------------------------------------------------------------------------------------------------

Wenn die Meldung "Kompilierungsfehler: SoftPWM.h: Datei oder Verzeichnis nicht gefunden" erscheint, bedeutet dies, dass die ``SoftPWM`` Bibliothek nicht installiert ist.

Bitte beziehen Sie sich auf :ref:`ar_install_library`, um die beiden erforderlichen Bibliotheken ``SoftPWM`` und ``IRLremote`` zu installieren.


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
