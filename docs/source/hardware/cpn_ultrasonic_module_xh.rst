.. note:: 

    Ciao, benvenuto nella Community di Appassionati di Raspberry Pi, Arduino e ESP32 di SunFounder su Facebook! Esplora più a fondo il mondo di Raspberry Pi, Arduino ed ESP32 insieme ad altri entusiasti.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri ultimi prodotti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e offerte speciali durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti subito!

Ultrasonic Module
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Ingresso impulso di trigger
* **ECHO**: Uscita impulso di eco
* **GND**: Massa
* **VCC**: Alimentazione 5V

Questo è il sensore di distanza ultrasonico HC-SR04, in grado di effettuare misurazioni senza contatto in un intervallo compreso tra 2 cm e 400 cm, con una precisione fino a 3 mm. Il modulo include un trasmettitore ultrasonico, un ricevitore e un circuito di controllo.

È sufficiente collegare 4 pin: VCC (alimentazione), Trig (trigger), Echo (ricezione) e GND (massa) per poterlo utilizzare facilmente nei tuoi progetti di misurazione.

**Caratteristiche**

* Tensione di funzionamento: DC 5V
* Corrente di funzionamento: 16mA
* Frequenza di lavoro: 40Hz
* Distanza massima: 500 cm
* Distanza minima: 2 cm
* Segnale di trigger in ingresso: impulso TTL di 10μs
* Segnale di uscita Echo: segnale TTL proporzionale alla distanza rilevata
* Connettore: XH2.54-4P
* Dimensioni: 46 x 20.5 x 15 mm

**Principio di funzionamento**

I principi di funzionamento di base sono i seguenti:

* Utilizzare un segnale di trigger IO con livello alto di almeno 10μs.
* Il modulo invia un impulso ultrasonico di 8 cicli a 40 kHz e rileva se viene ricevuto un segnale di ritorno.
* Se il segnale di ritorno viene rilevato, l'uscita Echo diventa alta; la durata del livello alto corrisponde al tempo trascorso tra l'emissione e il ritorno del segnale.
* Distanza = (tempo del livello alto x velocità del suono (340 m/s)) / 2

    .. image:: img/ultrasonic_prin.jpg
        :width: 800

Formula: 

* μs / 58 = distanza in centimetri
* μs / 148 = distanza in pollici
* distanza = tempo del livello alto x velocità del suono (340 m/s) / 2

**Note applicative**

* Questo modulo non deve essere collegato all'alimentazione mentre è sotto tensione; se necessario, collegare prima il GND del modulo per evitare malfunzionamenti.
* L'area dell'oggetto da misurare dovrebbe essere di almeno 0.5 metri quadrati e il più piatta possibile per garantire misurazioni affidabili.
