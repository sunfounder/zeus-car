.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Omni-Graustufenmodul
============================

.. image:: img/omni_grayscale_front.png
    :width: 300

.. image:: img/omni_grayscale_back.png
    :width: 300

* **VREF**: Referenzspannungseingangspin. Der Wert jedes Sensors wird mit dieser Referenzspannung verglichen, um zu bestimmen, ob ein hoher oder niedriger Wert ausgegeben wird.
* **Q7**: Serieller Ausgang aus der letzten Stufe
* **PL**: Asynchroner paralleler Ladeeingang (aktiv LOW)
* **CP**: Clock-Eingang (LOW-to-HIGH Flanken-gesteuert)
* **5V**: 3,3 bis 5V DC Spannungseingang
* **GND**: Masseanschluss

Dies ist ein Omni-Graustufenmodul zur Linienverfolgung und Kantenerkennung. "Omni" bedeutet omnidirektional, was bedeutet, dass das Modul über 8 TCRT5000 Sendesensoren verfügt, die im Kreis angeordnet sind, um schwarze Linien aus jeder Richtung zu erkennen.

Dies ermöglicht es einem Roboterwagen wie dem Zeus Car mit Mecanum-Rädern, der Linie in verschiedenen Winkeln zu folgen, ohne dass die Vorderseite des Autos nach vorne zeigt.

Die Empfindlichkeit des Moduls in der aktuellen Umgebung kann angepasst werden, indem der VREF-Wert geändert wird. Beim Zeus Car Shield wird das blaue Potentiometer verwendet, um den Wert des VREF-Pins einzustellen.

**Funktionsprinzip**

* |link_tcrt5000_datasheet|

Im Modul sind acht TCRT5000 Sendesensoren integriert, die auf der infraroten optischen Reflexion basieren und eine infrarote LED und einen Fototransistor enthalten, der mit einem Bleimaterial abgedeckt ist, um sichtbares Licht zu blockieren.

.. image:: img/tcrt5000_pin.jpg
    :width: 400
    :align: center

Bei der Arbeit sendet die infrarote LED des TCRT5000 kontinuierlich infrarotes Licht (unsichtbares Licht) mit einer Wellenlänge von 950nm aus. Wenn das emittierte infrarote Licht nicht von einem Hindernis zurück reflektiert wird oder die Reflexionsintensität unzureichend ist, arbeitet der Fototransistor nicht. Wenn das infrarote Licht mit ausreichender Intensität reflektiert und gleichzeitig vom Fototransistor empfangen wird, ist der Fototransistor in Betrieb und liefert einen Ausgang.

* |link_lm339_datasheet|

Auf diesem Omni-Graustufenmodul gibt es 2 LM339-Chips, die insgesamt 8 differentielle Komparatoren enthalten. Diese differentiellen Komparatoren werden verwendet, um den aktuellen Sensorwert mit einem Referenzwert zu vergleichen, um zu bestimmen, ob ein hoher oder niedriger Wert ausgegeben wird. So wissen Sie, ob eine schwarze Linie erkannt wird.

.. image:: img/lm339_chip.png

Nachfolgend finden Sie ein Schema eines der Kanäle.

.. image:: img/tcrt_lm339.png

* Legen Sie eine Referenzspannung am VREF-Pin an (diese Referenzspannung wird über ein Potentiometer am Zeus Car Shield eingestellt) und fügen Sie diese Referenzspannung dem invertierenden Eingang (-) des Komparators hinzu.
* Fügen Sie den Kollektor des Fototransistors des TCRT5000-Sensors dem in-Phasen-Eingang (+) des Komparators hinzu.
* Wenn der vom TCRT5000-Sensor ausgesendete Infrarotstrahl nicht zurückreflektiert wird oder die Reflexionsintensität unzureichend ist, funktioniert der lichtempfindliche Transistor nicht, und der Kollektor ist zu diesem Zeitpunkt mit dem Pull-up-Widerstand auf 5V verbunden. Daher ist der in-Phasen-Eingang (+) des Komparators größer als der invertierende Eingang (-).
* Der Komparatorausgang ist hoch und die Anzeige leuchtet nicht auf. Und umgekehrt.
* Da die schwarze Oberfläche Licht absorbiert, reflektiert sie weniger Infrarotlicht. Daher gibt der Komparator auf der schwarzen Oberfläche einen hohen Wert aus und die Anzeige leuchtet nicht auf.
* Die weiße Oberfläche reflektiert mehr Infrarotstrahlen, und der lichtempfindliche Transistor leitet, sodass der Wert des in-Phasen-Eingangs kleiner als der invertierte Eingang ist, und der Komparator gibt einen niedrigen Wert aus, und die Anzeige leuchtet auf.

Diese 8 Sensordaten werden über den 74HC165 (8-Bit-Parallel-Eingabe serieller Ausgangsschieberegister) an das Arduino-Board übertragen.

* |link_74hc165_datasheet|

Der 74HC165 ist ein 8-Bit paralleler Eingabe serieller Ausgangsschieberegister, der exklusive serielle Ausgänge (Q0 und Q7) in der Endstufe erhalten kann. Wenn der parallele Lese-Eingang (PL) niedrig ist, werden die parallelen Daten von D0 bis D7 asynchron in das Register eingelesen. Und wenn PL hoch ist, werden die Daten seriell vom DS-Eingang in das Register eingelesen, wobei sich ein Bit bei jeder aufsteigenden Flanke eines Taktimpulses nach rechts verschiebt (Q0 → Q1 → Q2 usw.). Mit dieser Funktion kann die Parallel-zu-Seriell-Erweiterung erreicht werden, indem einfach der Q7-Ausgang an den DS-Eingang der nächsten Stufe gebunden wird.

Der Takteingang des 74HC165 ist eine "gated or" Struktur, die es ermöglicht, einen der Eingänge als Clock Enable (CE) Eingang mit niedriger Aktivität zu verwenden. Die CP- und CE-Pinzuordnungen sind unabhängig und können bei Bedarf ausgetauscht werden. CE darf nur steigen, wenn CP hoch ist. CP oder CE sollten vor der steigenden Flanke von PL hochgesetzt werden, um eine Datenverschiebung im aktiven Zustand von PL zu verhindern.

.. image:: img/74hc165_con.png

**Merkmale**

* Betriebsspannung: 3,3 ~ 5V
* Ausgang: digital (an/aus)
* Asynchroner 8-Bit-Parallel-Ladevorgang
* Synchroner serieller Eingang
* Erkennungsschwelle: einstellbar über VREF-Pin
* Sensortyp：TCRT5000
* Steckermodell：ZH1.5-6P
* Betriebstemperatur: -10 °C bis +50 °C
* Abmessungen: 80mm x 80mm

**Kalibrierung des Moduls**

    Da jeder Untergrund unterschiedliche Grauwerte aufweist, ist der werkseitig eingestellte Grauschwellenwert möglicherweise nicht für Ihre aktuelle Umgebung geeignet. Daher müssen Sie dieses Modul vor der Verwendung kalibrieren. Es wird empfohlen, dass Sie es kalibrieren müssen, wann immer sich die Bodenfarbe stark ändert.

    * Platzieren Sie den Zeus Car auf einer weißen Fläche und drehen Sie das Potentiometer, bis das Licht des Grausensors gerade leuchtet.

        .. image:: img/zeus_line_calibration.jpg

    * Lassen Sie nun die beiden Grausensoren an der Seite genau zwischen der schwarzen Linie und der weißen Fläche liegen und drehen Sie das Potentiometer langsam, bis die Signalanzeige gerade erlischt.

        .. image:: img/zeus_line_calibration1.jpg

    * Sie können wiederholt über die schwarze Linie und die weiße Fläche fahren, um sicherzustellen, dass die Lichter des Grausensors aus sind, wenn sie zwischen der schwarzen Linie und der weißen Fläche liegen, und an sind, wenn sie auf der weißen Fläche sind, was darauf hinweist, dass das Modul erfolgreich kalibriert wurde.






