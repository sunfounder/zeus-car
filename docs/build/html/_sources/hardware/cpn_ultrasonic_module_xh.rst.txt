.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Ultraschallmodul
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Triggerimpulseingang
* **ECHO**: Echoimpulsausgang
* **GND**: Masse
* **VCC**: 5V Versorgung

Hierbei handelt es sich um den HC-SR04 Ultraschalldistanzsensor, der eine berührungslose Messung von 2 cm bis 400 cm mit einer Reichweitengenauigkeit von bis zu 3 mm bietet. Das Modul ist mit einem Ultraschallsender, einem Empfänger und einer Steuerschaltung ausgestattet.

Für Ihre Messprojekte müssen Sie nur 4 Pins anschließen: VCC (Stromversorgung), Trig (Trigger), Echo (Empfang) und GND (Masse).

**Eigenschaften**

* Betriebsspannung: DC5V
* Arbeitsstrom: 16mA
* Arbeitsfrequenz: 40Hz
* Max. Reichweite: 500cm
* Min. Reichweite: 2cm
* Trigger-Eingangssignal: 10uS TTL-Impuls
* Echo-Ausgangssignal: TTL-Pegel-Eingangssignal und Reichweite proportional
* Steckverbinder: XH2.54-4P
* Abmessungen: 46x20,5x15 mm

**Prinzip**

Die grundlegenden Prinzipien sind:

* Mindestens 10us hohes Pegelsignal mit IO auslösen.
* Das Modul sendet einen 8-Zyklus-Ultraschallburst mit 40 kHz und erkennt, ob ein Pulssignal empfangen wird.
* Echo gibt ein hohes Pegelsignal aus, wenn ein Signal zurückkommt; die Dauer des hohen Pegels ist die Zeit von der Emission bis zur Rückkehr.
* Entfernung = (High-Level-Zeit x Schallgeschwindigkeit (340M/S)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800

Formel:

* us / 58 = Entfernung in Zentimetern
* us / 148 = Entfernung in Zoll
* Entfernung = High-Level-Zeit x Geschwindigkeit (340M/S) / 2

**Anwendungshinweise**

* Dieses Modul sollte nicht beim Einschalten verbunden werden. Falls notwendig, sollte zuerst die GND des Moduls verbunden werden. Andernfalls wird es die Arbeit des Moduls beeinflussen.
* Die Fläche des zu messenden Objekts sollte mindestens 0,5 Quadratmeter betragen und möglichst flach sein. Andernfalls beeinflusst dies die Ergebnisse.
