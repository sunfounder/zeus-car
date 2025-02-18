.. note:: 

    Ciao, benvenuto nella Community di Appassionati di Raspberry Pi, Arduino e ESP32 di SunFounder su Facebook! Esplora più a fondo il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri entusiasti.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri ultimi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e offerte speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti subito!

Zeus Car Shield
=========================

.. image:: img/zeus_car_shield.png
    :width: 500
    :align: center

Questa è una scheda di espansione all-in-one progettata da SunFounder per Arduino. Include diversi connettori per moduli, tra cui motore, barra luminosa, evitamento ostacoli, sensore di scala di grigi, ESP32 CAM e modulo ultrasonico. Inoltre, è dotata di un ricevitore IR HS0038B per il controllo remoto.

La scheda dispone anche di un circuito di ricarica integrato, che permette di caricare la batteria tramite l'interfaccia PH2.0-5P, con un tempo di ricarica stimato di 130 minuti.

**Pinout dello Zeus Car Shield**

.. image:: img/zeus_car_shield_pinout.png

* Pulsante di reset
    * Premere questo pulsante per resettare il programma sulla scheda Arduino.

* Porta di ricarica
    * Collegando una porta USB-C da 5V/2A, è possibile ricaricare la batteria in circa 130 minuti.

* :ref:`shield_battry_pin`: 
    * Ingresso di alimentazione PH2.0-5P da 6.6V~8.4V.
    * Alimenta contemporaneamente lo Zeus Car Shield e la scheda Arduino.

* Interruttore di alimentazione
    * Spostare su "ON" per accendere lo Zeus Car Shield.

* Ricevitore IR
    * Ricevitore IR HS0038B, con il pin del segnale collegato al pin 2 della scheda Arduino.

* :ref:`shield_grayscale_pin`
    * Potenziometro per la regolazione della scala di grigi: utilizzato per impostare la tensione di riferimento per il modulo Omni Grayscale.
    * Porta scala di grigi: utilizzata per collegare il modulo Omni Grayscale.

* Indicatori LED
    * **Indicatore di ricarica**: si illumina di rosso durante la ricarica tramite la porta USB-C.
    * **Indicatore di alimentazione**: si illumina di verde quando l'interruttore di alimentazione è in posizione "ON".
    * **Indicatore batteria**: due LED arancioni rappresentano diversi livelli di carica. Lampeggiano durante la ricarica e si spengono quando la batteria necessita di essere ricaricata.

* :ref:`shield_ultrasonic_pin`
    * Per collegare il modulo ultrasonico, i pin Trig & Echo sono collegati al pin 10 della scheda Arduino.

* :ref:`shield_camera_pin`
    * Porta per la scheda adattatrice della fotocamera.

* :ref:`shield_avoid_pin`
    * Porta per il collegamento di due moduli IR di evitamento ostacoli. I pin di segnale delle due porte sono collegati ai pin Q0 e Q1 del chip 74HC165.

* :ref:`shield_strip_pin`
    * Porta per il collegamento di due strisce LED RGB, i cui tre pin sono rispettivamente collegati ai pin 12, 13 e 11.

* Interruttore di esecuzione
    * Per utilizzare la fotocamera, è necessario spostare questo interruttore per consentire la comunicazione tra l'ESP32-CAM e la scheda Arduino.

* :ref:`shield_motor_pin`
    * 4 gruppi di porte motore.


.. _shield_battry_pin:

Porta Batteria
------------------

Di seguito è riportato lo schema dei pin dell'interfaccia della batteria. Il tipo è PH2.0-5P e l'intervallo di alimentazione è 6.6V~8.4V.

.. image:: img/shield_battery_pin.png
    :width: 400
    :align: center

.. _shield_grayscale_pin:

Modulo Scala di Grigi
------------------------------

Un potenziometro blu presente sullo Zeus Car Shield consente di regolare la sensibilità del modulo scala di grigi in base all'ambiente, impostando la tensione di riferimento. Attraverso il pin VREF, il modulo scala di grigi riceve la tensione di riferimento impostata.

.. image:: img/shield_grayscale_pin.png

Di seguito è riportato lo schema elettrico. I valori del modulo scala di grigi vengono trasferiti dal chip 74HC165 alla scheda Arduino. Poiché il modulo scala di grigi è dotato di un chip 74HC165, la cascata di questi due chip trasferisce 16 bit di dati alla scheda Arduino: gli 8 bit iniziali rappresentano i dati del sensore di scala di grigi, mentre gli ultimi due rappresentano i dati del sensore di evitamento ostacoli IR.

.. image:: img/shield_grayscale1.png
.. image:: img/shield_grayscale2.png
    :width: 400

Mappatura dei pin sulla scheda Arduino:

.. list-table::
    :widths: 25 50

    * - Scheda Arduino
      - Zeus Car Shield
    * - 7
      - 74HC165 Q7
    * - 8
      - 74HC165 CP
    * - ~9
      - 74HC165 PL


.. _shield_ultrasonic_pin:

Porta Ultrasonica
----------------------

Schema dei pin per la porta ultrasonica ZH1.5-4P. I pin Trig & Echo sono collegati al pin 10 della scheda Arduino.

.. image:: img/shield_ultrasonic_pin.png

.. _shield_camera_pin:

Porta Adattatore Fotocamera
---------------------------------

Schema dei pin dell'interfaccia adattatrice della fotocamera. Il tipo è ZH1.5-7P.

* TX e RX sono utilizzati per ESP32-CAM.
* SDA e SCL sono per QMC6310.

.. image:: img/shield_camera_pin.png


.. _shield_avoid_pin:

Porta Evitamento Ostacoli
------------------------------

Di seguito è riportato lo schema dei pin delle due porte ZH1.5-3P per l'evitamento ostacoli.

.. image:: img/shield_avoid_pin.png

Come mostrato nel circuito, S1 e S0 si riferiscono a Q0 e Q1 sul chip 74HC165. La cascata di due chip 74HC165 trasferisce i dati dei due moduli IR di evitamento ostacoli e del sensore di scala di grigi alla scheda Arduino. Gli 8 bit iniziali rappresentano i dati del sensore di scala di grigi, mentre gli ultimi due bit indicano i dati di evitamento ostacoli IR.

.. image:: img/shield_avoid_sche.png
.. image:: img/shield_avoid_sche1.png

.. _shield_strip_pin:

Porta Striscia LED RGB
-------------------------

Di seguito è riportato lo schema dei pin delle due strisce LED RGB, che sono collegate in parallelo con la stessa configurazione di pin.

.. image:: img/shield_strip_pin.png

Schema del circuito:

.. image:: img/shield_strip_sche.png
.. image:: img/shield_strip_sche1.png

.. _shield_motor_pin:

Porta Motore
-----------------

Schema dei pin per i 4 set di porte motore.

.. image:: img/shield_motor_pin.png
    :width: 400
    :align: center

Questi 4 set di motori sono controllati da 2 chip TC1508S, un driver motore a doppio canale con una corrente di uscita continua massima di 1.8A per canale.

Schema del circuito:

.. image:: img/shield_motor_sche.png

Mappatura dei pin di controllo dei 4 motori:

.. list-table::
    :widths: 25 50

    * - Scheda Arduino
      - Zeus Car Shield
    * - ~3
      - OUTA1
    * - 4
      - OUTB1
    * - ~5
      - OUTA2
    * - ~6
      - OUTB2
    * - A0
      - OUTB4
    * - A1
      - OUTA4
    * - A2
      - OUTB3
    * - A3
      - OUTA3




