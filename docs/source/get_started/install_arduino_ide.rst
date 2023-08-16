.. _install_arduino:

Download und Installation von Arduino IDE 2.0
============================================================

Die Arduino IDE, bekannt als Arduino Integrated Development Environment, bietet alle notwendigen Softwareunterstützungen, um ein Arduino-Projekt abzuschließen. Es handelt sich um eine speziell für Arduino entwickelte Programmiersoftware, die vom Arduino-Team bereitgestellt wird und mit der wir Programme schreiben und auf das Arduino-Board hochladen können.

Die Arduino IDE 2.0 ist ein Open-Source-Projekt. Sie stellt einen großen Schritt gegenüber ihrem soliden Vorgänger, der Arduino IDE 1.x, dar und bietet eine überarbeitete Benutzeroberfläche, verbesserten Board- & Library-Manager, Debugger, Autocomplete-Funktion und vieles mehr.

In diesem Tutorial zeigen wir, wie Sie die Arduino IDE 2.0 auf Ihrem Windows-, Mac- oder Linux-Computer herunterladen und installieren können.

Anforderungen
-------------------

* Windows - Win 10 und neuer, 64 Bit
* Linux - 64 Bit
* Mac OS X - Version 10.14: "Mojave" oder neuer, 64 Bit

Arduino IDE 2.0 herunterladen
-------------------------------

#. Besuchen Sie |link_download_arduino|.

#. Laden Sie die IDE für Ihre Betriebssystemversion herunter.

    .. image:: img/arduino/sp_001.png

Installation
------------------------------

* :ref:`ide_windows`
* :ref:`ide_macos`
* :ref:`ide_linux`

.. _ide_windows:

Windows
^^^^^^^^^^^^^

#. Doppelklicken Sie auf die Datei ``arduino-ide_xxxx.exe``, um die heruntergeladene Datei auszuführen.

#. Lesen Sie die Lizenzvereinbarung und akzeptieren Sie diese.

    .. image:: img/arduino/sp_002.png

#. Wählen Sie die Installationsoptionen.

    .. image:: img/arduino/sp_003.png

#. Wählen Sie den Installationsort. Es wird empfohlen, die Software auf einem anderen Laufwerk als dem Systemlaufwerk zu installieren.

    .. image:: img/arduino/sp_004.png

#. Dann beenden. 

    .. image:: img/arduino/sp_005.png

.. _ide_macos:

macOS
^^^^^^^^^^^^^^^^

Doppelklicken Sie auf die heruntergeladene Datei ``arduino_ide_xxxx.dmg`` und folgen Sie den Anweisungen, um die **Arduino IDE.app** in den **Anwendungen** Ordner zu kopieren. Nach wenigen Sekunden sehen Sie, dass die Arduino IDE erfolgreich installiert wurde.

.. image:: img/arduino/macos_install_ide.png
    :width: 800

.. _ide_linux:

Linux
^^^^^^^^^^^^

Für das Tutorial zur Installation der Arduino IDE 2.0 auf einem Linux-System besuchen Sie bitte: https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing#linux


Öffnen Sie die IDE
------------------------------

#. Wenn Sie die Arduino IDE 2.0 zum ersten Mal öffnen, installiert sie automatisch die Arduino AVR Boards, eingebaute Bibliotheken und andere erforderliche Dateien.

    .. image:: img/arduino/sp_901.png

#. Darüber hinaus könnte Ihr Firewall- oder Sicherheitscenter einige Male aufpoppen und Sie fragen, ob Sie einige Gerätetreiber installieren möchten. Bitte installieren Sie alle.

    .. image:: img/arduino/sp_104.png

#. Jetzt ist Ihre Arduino IDE einsatzbereit!

    .. note::
        Falls einige Installationen aufgrund von Netzwerkproblemen oder aus anderen Gründen nicht funktioniert haben, können Sie die Arduino IDE erneut öffnen und sie wird den Rest der Installation abschließen. Das Ausgabefenster wird nicht automatisch geöffnet, nachdem alle Installationen abgeschlossen sind, es sei denn, Sie klicken auf Überprüfen oder Hochladen.
