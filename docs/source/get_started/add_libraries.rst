.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_install_library:

Bibliotheken installieren (Arduino IDE 2)
===============================================

**Was ist eine Bibliothek?**

Eine Bibliothek, die einige Funktionsdefinitionen und Header-Dateien enthält, besteht normalerweise aus zwei Dateien: .h (Header-Datei, enthält Funktionsdeklarationen, Makrodefinitionen, Konstruktordefinitionen usw.) und .cpp (Ausführungsdatei, mit Funktionsimplementierung, Variablendefinition usw.). 

Wenn Sie eine Funktion aus einer bestimmten Bibliothek verwenden möchten, müssen Sie lediglich eine Header-Datei hinzufügen (z.B. #include <dht.h>) und dann diese Funktion aufrufen. Dies macht Ihren Code übersichtlicher.

Wenn Sie die Bibliothek nicht verwenden möchten, können Sie diese Funktionsdefinition auch direkt schreiben. Dies führt jedoch dazu, dass der Code lang und schwer lesbar wird.

Einige Bibliotheken sind bereits in der Arduino IDE enthalten, während andere installiert werden müssen. Schauen wir uns jetzt an, wie man eine solche installiert.

**Wie installiert man?**

.. note::

    Ich verwende Arduino IDE 2.0. Wenn Sie Arduino IDE 1.x verwenden, können Sie sich auf |link_install_library| beziehen.

#. Um eine neue Bibliothek in Ihrer Arduino IDE zu installieren, können Sie den **Library Manager** verwenden, den Sie in der linken Spalte öffnen können.

    .. image:: img/arduino/ar_libr_manager.jpg

#. Es erscheint nun eine Liste aller verfügbaren Bibliotheken, in der wir auch nach der gewünschten Bibliothek suchen können. Hier werden wir die ``SoftPWM`` Bibliothek installieren. Klicken Sie auf den **INSTALLIEREN**-Button, um die Bibliothek zu installieren.

    .. image:: img/arduino/ar_softpwm.png

#. Dieser Prozess sollte nicht allzu lange dauern, geben Sie ihm jedoch bis zu einer Minute Zeit für die Installation. Wenn es fertig ist, können wir uns die Bibliothek im Library Manager ansehen, wo **INSTALLIERT** stehen sollte.

    .. image:: img/arduino/ar_install_success.png

#. Installieren Sie die ``IRLremote`` Bibliothek auf die gleiche Weise, aber achten Sie darauf, den Namen nicht falsch zu schreiben.

    .. image:: img/arduino/ar_irlremote.png

#. Installieren Sie abschließend die ``ArduinoJson`` Bibliothek.

    .. image:: img/arduino/ar_arduinojson.png