.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

IR Hinderniserkennungsmodul
=======================================

.. image:: img/ir_avoid.png

* **GND**: Erdanschluss
* **+**: 3,3 bis 5V DC Spannungseingang
* **Out**: Signalausgangspin, standardmäßig hoch und gibt ein niedriges Signal aus, wenn ein Hindernis erkannt wird.
* **EN**: Modulaktivierungspin. Wenn dieser niedrig ist, ist das Modul aktiv und standardmäßig mit einem Jumper verbunden.

Dies ist ein übliches IR Hinderniserkennungsmodul, das ein Paar aus IR sendenden und empfangenden Komponenten verwendet. Grundsätzlich sendet der Sender infrarotes Licht aus. Wenn in der Erfassungsrichtung ein Hindernis auftritt, wird das Infrarotlicht zurückgeworfen und vom Empfänger erfasst. Zu diesem Zeitpunkt leuchtet die Anzeige auf. Nach der Schaltkreisverarbeitung wird ein niedriges Signal ausgegeben.

Erfassungsentfernung liegt zwischen 2-40cm und besitzt eine hervorragende Störfestigkeit. Verschiedenfarbige Objekte haben unterschiedliche Reflektivitätsstufen, sodass dunklere Objekte eine kürzere Erkennungsentfernung haben. Dieser Sensor erkennt im Bereich von 2-30cm gegenüber einer weißen Wand.

Wenn der Aktivierungspin auf niedrigem Niveau ist, arbeitet das Modul. Sobald der Jumper gesteckt ist, wird der EN-Pin mit GND verbunden, und das Modul ist ständig in Betrieb. Wenn Sie den EN-Pin per Code steuern möchten, müssen Sie den Jumper entfernen.

.. image:: img/ir_avoid_cap.png

**Einstellen der Erkennungsentfernung**

Aufgrund verschiedener Lichtverhältnisse kann die werkseitig eingestellte Erkennungsentfernung unpassend sein, daher müssen Sie die tatsächliche Erkennungsentfernung vor Gebrauch anpassen.

Es gibt zwei Potentiometer auf dem Modul, eines zur Anpassung der Sendeleistung und eines zur Anpassung der Sendefrequenz. Durch die Einstellung dieser beiden Potentiometer können Sie die effektive Distanz anpassen.

Sie können ein weißes Hindernis in dem gewünschten Abstand vor das Modul stellen und eines der Potentiometer so einstellen, dass die Anzeigeleuchte gerade aufleuchtet. Bewegen Sie dann das Hindernis mehrmals, um zu sehen, ob die Anzeigeleuchte in dem gewünschten Abstand aufleuchtet.

Wenn die Anzeige an der gewünschten Stelle nicht aufleuchtet oder ständig leuchtet, können Sie das andere Potentiometer anpassen.

.. image:: ../get_started/img/zeus_ir_avoid.jpg

**Merkmale**

* Betriebsspannung: 3,3 V bis 5 V
* Ausgang: digital (ein/aus)
* Erkennungsschwelle: Einstellbar durch 2 Potentiometer
* Erfassungsbereich: 2 bis 40 cm
* Einstellung R5: Frequenzeinstellung 38 kHz (bereits optimiert)
* Einstellung R6: IR LED-Tastverhältniseinstellung (bereits optimiert)
* Betriebstemperatur: -10 °C bis +50 °C
* Effektiver Winkel: 35°
* I/O-Schnittstelle: 4-Draht-Schnittstelle (- / + / S / EN)
* Abmessungen: 45 x 16 x 10 mm
* Gewicht: 9 g
