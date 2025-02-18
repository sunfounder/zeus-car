.. note::

    Ciao, benvenuto nella Community di Appassionati di Raspberry Pi, Arduino e ESP32 di SunFounder su Facebook! Unisciti a noi per esplorare più a fondo il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri entusiasti.

    **Perché unirsi?**

    - **Supporto esperto**: Ottieni assistenza per problemi post-vendita e sfide tecniche grazie al supporto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e offerte speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti subito!

.. _cpn_uno:

SunFounder R3 Board
===========================

.. image:: img/uno_r3.jpg
    :width: 600
    :align: center

.. note::

    La scheda SunFounder R3 è una mainboard con funzionalità quasi identiche all’`Arduino Uno <https://store.arduino.cc/products/arduino-uno-rev3/>`_, e le due schede possono essere utilizzate in modo intercambiabile.

La SunFounder R3 è una scheda a microcontrollore basata su ATmega328P (`datasheet <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_). Dispone di 14 pin di input/output digitali (di cui 6 possono essere utilizzati come uscite PWM), 6 ingressi analogici, un risonatore ceramico da 16 MHz (CSTCE16M0V53-R0), una connessione USB, un jack di alimentazione, un’intestazione ICSP e un pulsante di reset. Contiene tutto il necessario per supportare il microcontrollore; basta collegarla a un computer tramite un cavo USB o alimentarla con un adattatore AC-DC o una batteria per iniziare a utilizzarla.

**Parametri Tecnici**

.. image:: img/uno.jpg
    :align: center

* MICROCONTROLLER: ATmega328P
* TENSIONE DI FUNZIONAMENTO: 5V
* TENSIONE DI INGRESSO (RACCOMANDATA): 7-12V
* TENSIONE DI INGRESSO (LIMITE): 6-20V
* PIN I/O DIGITALI: 14 (0-13, di cui 6 con uscita PWM (3, 5, 6, 9-11))
* PIN I/O DIGITALI PWM: 6 (3, 5, 6, 9-11)
* PIN DI INGRESSO ANALOGICO: 6 (A0-A5)
* CORRENTE DC PER PIN I/O: 20 mA
* CORRENTE DC PER PIN 3.3V: 50 mA
* MEMORIA FLASH: 32 KB (ATmega328P), di cui 0.5 KB utilizzati dal bootloader
* SRAM: 2 KB (ATmega328P)
* EEPROM: 1 KB (ATmega328P)
* VELOCITÀ DI CLOCK: 16 MHz
* LED_BUILTIN: 13
* LUNGHEZZA: 68.6 mm
* LARGHEZZA: 53.4 mm
* PESO: 25 g
* Porta I2C: A4 (SDA), A5 (SCL)

**Altro**

* `Arduino IDE <https://www.arduino.cc/en/software>`_
* `Riferimenti al Linguaggio di Programmazione Arduino <https://www.arduino.cc/reference/en/>`_
* :ref:`install_arduino_ide`
* `Datasheet ATmega328P <http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf>`_
