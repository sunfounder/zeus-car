.. note:: 

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e giveaway festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


Scheda Adattatore per Fotocamera
====================================

.. image:: img/cam_adapter_board.jpg
    :width: 500
    :align: center

* **RST**: Utilizzato per resettare l'ESP32-CAM.
* **SCL**: Pin dati seriali per il QMC6310.
* **SDA**: Pin del clock seriale del QMC6310.
* **RXD**: RXD dell'ESP32-CAM, necessario per caricare il codice sull'ESP32-CAM attraverso questi due pin seriali, RXD e TXD.
* **TXD**: TXD dell'ESP32-CAM.
* **5V**: Ingresso di alimentazione DC 5V.
* **GND**: Ingresso di massa.

La Scheda Adattatore per Fotocamera, come suggerisce il nome, è una scheda di espansione per l’ESP32-CAM. Viene utilizzata per fissare l’ESP32-CAM al robot e facilitare il cablaggio.

.. image:: img/cam_adapter_esp32cam.png
    :width: 400
    :align: center

Poiché il chip geomagnetico QMC6310 è sensibile alle interferenze dei motori, lo abbiamo posizionato su questa scheda adattatore per fotocamera per mantenerlo il più lontano possibile dai motori.

.. image:: img/cam_adapter_qmc6310.png
    :width: 400
    :align: center


**Caratteristiche**

* Tensione di funzionamento: 5V
* Modello di interfaccia: ZH1.5, 7P
* Dimensioni: 40mm x 27mm x 15mm
* Protocollo di comunicazione: UART e I2C


**Documentazione**

* PCB

.. image:: img/cam_adap_pcb_bottom.png
    :width: 300

.. image:: img/cam_adap_pcb_top.png
    :width: 300

* Schema elettrico

.. image:: img/cam_adapter_sche.png


**Informazioni sul QMC6310**

Il QMC6310 è un sensore magnetico triassiale che integra sensori magnetici e un ASIC di condizionamento del segnale in un unico chip di silicio. Questo package Land Grid Array (LGA) è progettato per applicazioni come e-compass, rotazione di mappe, gaming e navigazione personale in dispositivi mobili e indossabili.

Il QMC6310 si basa su una tecnologia magneto-resistiva ad alta risoluzione all'avanguardia. Insieme all'ASIC ADC personalizzato a 16 bit, offre vantaggi come basso rumore, alta precisione, basso consumo energetico, cancellazione dell'offset e compensazione della temperatura. Il QMC6310 consente una precisione di orientamento della bussola da 1° a 2°. Il bus seriale I²C permette una facile interfaccia.

Il QMC6310 è disponibile in un package LGA a montaggio superficiale a 8 pin di dimensioni 1.2x1.2x0.53mm³.

* |link_qmc6310_datasheet|