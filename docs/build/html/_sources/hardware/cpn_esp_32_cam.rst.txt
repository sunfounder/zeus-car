.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

ESP32 CAM
=================

.. image:: img/esp32_cam.png
    :width: 500
    :align: center

Das ESP32-CAM ist ein sehr kleines Kameramodul mit dem ESP32-S-Chip, das etwa $10 kostet. Neben der OV2640-Kamera und mehreren GPIOs zum Anschluss von Peripheriegeräten verfügt es auch über einen microSD-Kartensteckplatz, der nützlich sein kann, um Bilder, die mit der Kamera aufgenommen wurden, zu speichern oder um Dateien für Clients bereitzustellen.

Das Modul kann als kleinstes System selbstständig arbeiten, mit einer Größe von nur 27*40,5*4,5mm und einem Tiefschlafstrom von nur 6mA.

ESP32-CAM kann in verschiedenen IoT-Anwendungen weit verbreitet eingesetzt werden und eignet sich für Heim-Smart-Geräte, industrielle drahtlose Steuerung, drahtlose Überwachung, QR-drahtlose Identifizierung, drahtlose Positionierungssystemsignale und andere IoT-Anwendungen. Es ist eine ideale Lösung für IoT-Anwendungen.

**Technische Daten**

.. list-table::
    :widths: 25 50

    * - Modulmodell
      - ESP32-CAM
    * - Gehäuse
      - DIP-16
    * - Größe
      - 27*40,5*4,5(±0,2)mm
    * - SPI Flash
      - standardmäßig 32Mbit
    * - RAM
      - Intern 520KB + Extern 8MB PSRAM
    * - Bluetooth
      - Bluetooth 4.2 BR/EDR und BLE-Standards
    * - Wi-Fi
      - 802.11 b/g/n/e/i
    * - Unterstützte Schnittstellen
      - UART, SPI, I2C, PWM
    * - Unterstützung TF-Karte
      - bis zu 4G
    * - IO Pins
      - 9
    * - Serielle Ports Geschwindigkeit
      - standardmäßig 115200 bps
    * - Bildausgabeformat
      - JPEG(nur OV2640 unterstützt), BMP, GRAUSTUFEN
    * - Frequenzbereich
      - 2400 ~2483,5MHz
    * - Antennentyp
      - On-board PCB-Antenne, Gewinn 2dBi
    * - Sendeleistung
      - 802.11b: 17±2 dBm (@11Mbps)
    * - 
      - 802.11g: 14±2 dBm (@54Mbps)
    * - 
      - 802.11n: 13±2 dBm (@MCS7)
    * - Empfangsempfindlichkeit
      - CCK, 1 Mbps: -90dBm,
    * - 
      - CCK, 11 Mbps: -85 dBm
    * - 
      - 6 Mbps (1/2 BPSK): -88 dBm
    * - 
      - 54 Mbps (3/4 64-QAM): -70dBm
    * - 
      - MCS7 (65 Mbps, 72.2 Mbps): -67dBm
    * - Stromverbrauch
      - Flash aus: 180mA@5V,
    * - 
      - Flash an und Helligkeit auf Maximum: 310mA@5V
    * - 
      - Tiefschlaf: der niedrigste Stromverbrauch kann 6mA@5V erreichen
    * - 
      - Modemschlaf: mindestens 20mA@5V
    * - 
      - Lichtschlaf: mindestens 6,7mA@5V
    * - Sicherheit
      - WPA/WPA2/WPA2-Enterprise/WPS
    * - Spannungsbereich
      - 4,75-5,25V
    * - Betriebstemperatur
      - -20 ℃ ~ 70 ℃
    * - Lagerungsumgebung
      - -40 ℃ ~ 125 ℃, < 90%RH

**ESP32-CAM Pinbelegung**

Das folgende Bild zeigt die Pinbelegung des ESP32-CAM (AI-Thinker Modul).

.. image:: img/esp32_cam_pinout.png
    :width: 800

* Es gibt drei **GND** Pins und drei Pins für die Stromversorgung: 3,3V, 5V und entweder 3,3V oder 5V.
* **GPIO 1** und **GPIO 3** sind die seriellen Pins. Diese Pins werden benötigt, um Code auf Ihr Board hochzuladen.
* Außerdem spielt **GPIO 0** eine wichtige Rolle, da er bestimmt, ob das ESP32 im Flash-Modus ist oder nicht. Wenn **GPIO 0** mit **GND** verbunden ist, befindet sich das ESP32 im Flash-Modus.

* Die folgenden Pins sind intern mit dem microSD-Kartenleser verbunden:

* GPIO 14: CLK
* GPIO 15: CMD
* GPIO 2: Daten 0
* GPIO 4: Daten 1 (auch mit der Onboard-LED verbunden)
* GPIO 12: Daten 2
* GPIO 13: Daten 3

**Hinweis**

* Bitte stellen Sie sicher, dass die Eingangsleistung des Moduls mindestens 5V 2A beträgt, sonst können Wasserlinien im Bild auftreten.
* Der ESP32 GPIO32 Pin steuert die Kamerastromversorgung. Wenn die Kamera arbeitet, ziehen Sie GPIO32 auf niedrig.
* Da GPIO0 mit dem Kamera XCLK verbunden ist, lassen Sie GPIO0 in der Luft, wenn Sie ihn verwenden, und verbinden Sie ihn nicht mit hohem oder niedrigem Level.
* Die Standard-Firmware ist bereits ab Werk enthalten und es wird kein zusätzlicher Download bereitgestellt. Bitte seien Sie vorsichtig, wenn Sie andere Firmware neu brennen müssen.

**Dokument**

* Schaltplan: |link_esp32cam_schematic|
* Kamera-Spezifikation (Englische Version): |link_cam_ov2640|

.. note::
    Alle oben genannten Informationen stammen von |link_aithiner|
