.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Kamera-Adapterplatine
=====================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Zum Zurücksetzen des ESP32-CAM verwendet.
* **SCL**: Serieller Daten-Pin für QMC6310.
* **SDA**: Serieller Uhr-Pin des QMC6310.
* **RXD**: Der RXD des ESP32-CAM. Über diese beiden seriellen Pins, RXD und TXD, muss der Code auf den ESP32-CAM hochgeladen werden.
* **TXD**: TXD des ESP32-CAM.
* **5V**: 5V DC Versorgungseingang.
* **GND**: Erdungseingang.

Wie der Name schon sagt, ist die Kamera-Adapterplatine eine Erweiterungsplatine für den ESP-32 CAM. Sie dient dazu, den ESP32-CAM zu erweitern, damit er am Roboter befestigt werden kann und einfach verdrahtet werden kann.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Da der geomagnetische Chip QMC6310 anfällig für Störungen von Motoren ist, haben wir ihn auf diese Kamera-Adapterplatine gelegt, um ihn so weit wie möglich von den Motoren entfernt zu halten.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center

**Merkmale**

* Betriebsspannung: 5V.
* Schnittstellenmodell: ZH1.5, 7P.
* Abmessungen: 40mm x 27mm x 15mm.
* Kommunikationsprotokoll: UART und I2C.

**Dokumente**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Schaltplan

.. image:: img/cam_adapter_sche.png

**Über QMC6310**

Der QMC6310 ist ein Drei-Achsen-Magnetsensor, der Magnetsensoren und Signalzustands-ASIC in einem Siliziumchip integriert. Dieses Land Grid Array-Paket (LGA) richtet sich an Anwendungen wie E-Kompass, Kartenrotation, Spiele und persönliche Navigation in mobilen und tragbaren Geräten.

Der QMC6310 basiert auf modernster, hochauflösender, magnetoresistiver Technologie. Zusammen mit dem eigens entwickelten 16-Bit-ADC-ASIC bietet er Vorteile wie geringes Rauschen, hohe Genauigkeit, geringen Stromverbrauch, Offset-Aufhebung und Temperaturkompensationen. QMC6310 ermöglicht eine Kompasskopfgenauigkeit von 1° bis 2°. Der I²C-Seriellbus ermöglicht eine einfache Schnittstelle.

Der QMC6310 befindet sich in einem 1,2x1,2x0,53mm3 Oberflächenmontage-8-Pin-LGA-Gehäuse.

* |link_qmc6310_datasheet|
