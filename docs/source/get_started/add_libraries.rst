.. note:: 

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti a noi per esplorare più a fondo Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anticipo agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a eventi speciali e concorsi con premi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_install_lib:

Installare le librerie richieste
===============================================

**Cos'è una libreria?**

Una libreria è un insieme di funzioni predefinite e intestazioni che semplificano e rendono più efficiente la programmazione. Generalmente, una libreria è composta da due file principali:

* **.h (Header File)**: Contiene dichiarazioni di funzioni, definizioni di macro e costruttori.
* **.cpp (Source File)**: Include l'implementazione delle funzioni, la definizione delle variabili e altri componenti eseguibili.

Includendo una libreria nel tuo progetto, puoi richiamare direttamente le funzioni fornite (ad esempio, ``#include <dht.h>``) invece di doverle definire da zero. Questo rende il codice più conciso e leggibile.

Anche se è possibile scrivere le definizioni delle funzioni autonomamente, l’uso di una libreria consente di risparmiare tempo e ridurre la complessità.

Alcune librerie sono già preinstallate nell'Arduino IDE, mentre altre devono essere installate manualmente. Ecco come installare le librerie necessarie per questo progetto.

**Come installare una libreria**

.. note::

    Le seguenti istruzioni si riferiscono a **Arduino IDE 2.0**. Se stai utilizzando Arduino IDE 1.x, consulta |link_install_library|.

Ecco i passaggi per installare una libreria:

1. Clicca sull'icona **Library Manager** nella colonna di sinistra dell’**Arduino IDE**.

   .. image:: img/arduino/ar_libr_manager.jpg

2. Cerca la libreria:

   * Apparirà un elenco di librerie disponibili. Utilizza la barra di ricerca per trovare la libreria che desideri installare.
   * Ad esempio, per installare la libreria ``SoftPWM``, digita il nome e clicca sul pulsante **INSTALL**.

   .. image:: img/arduino/ar_softpwm.png

3. Il processo di installazione richiede solitamente meno di un minuto. Una volta completato, la libreria verrà contrassegnata come **INSTALLED** nel Gestore Librerie.
   
   .. image:: img/arduino/ar_install_success.png

4. Ripeti gli stessi passaggi per installare la libreria ``IRLremote``, assicurandoti di scrivere correttamente il nome della libreria.

   .. image:: img/arduino/ar_irlremote.png

5. Installa la libreria ``ArduinoJson``.

   .. image:: img/arduino/ar_arduinojson.png

6. Infine, cerca e installa la libreria ``SunFounder AI Camera``, l'ultima necessaria per questo progetto.

   .. image:: img/arduino/ar_aicamera.png

Seguendo questi passaggi, avrai tutte le librerie necessarie installate e pronte all'uso per il tuo progetto.
