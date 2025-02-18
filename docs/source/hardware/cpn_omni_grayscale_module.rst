.. note:: 

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e giveaway festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


Modulo Omni Grayscale
============================

.. image:: img/omni_grayscale_front.png
    :width: 300

.. image:: img/omni_grayscale_back.png
    :width: 300

* **VREF**: Pin di ingresso della tensione di riferimento. Il valore di ciascun sensore viene confrontato con questa tensione di riferimento per determinare se deve emettere un segnale alto o basso.
* **Q7**: Uscita seriale dallo stadio finale.
* **PL**: Ingresso di caricamento parallelo asincrono (attivo a livello basso).
* **CP**: Ingresso di clock (attivato sul fronte di salita).
* **5V**: Alimentazione in corrente continua da 3.3V a 5V.
* **GND**: Massa.

Il modulo Omni Grayscale è progettato per il tracciamento di linee e la rilevazione dei bordi. "Omni" indica la sua capacità omnidirezionale, poiché integra otto sensori trasmettitori TCRT5000 disposti in cerchio, permettendo di rilevare linee nere in qualsiasi direzione.

Grazie a questo modulo, un robot come lo Zeus Car, dotato di ruote Mecanum, può seguire una linea da varie angolazioni senza dover necessariamente mantenere il muso rivolto in avanti.

La sensibilità del modulo può essere regolata modificando il valore di VREF, che è regolabile tramite il potenziometro blu sulla scheda Zeus Car Shield.


**Principio di funzionamento**

* |link_tcrt5000_datasheet|

Il modulo integra otto sensori TCRT5000, basati sulla riflessione ottica a infrarossi. Ogni sensore include un diodo emettitore a infrarossi e un fototransistor, coperti da un materiale schermante per bloccare la luce visibile.

.. image:: img/tcrt5000_pin.jpg
    :width: 400
    :align: center

Quando il modulo è in funzione, il diodo IR emette luce infrarossa (lunghezza d'onda: 950nm). Se la luce infrarossa non viene riflessa o l'intensità della riflessione è insufficiente, il fototransistor rimane inattivo. Se la luce viene riflessa con sufficiente intensità e rilevata dal fototransistor, questo si attiva e fornisce un'uscita.

* |link_lm339_datasheet|

Sul modulo sono presenti due chip LM339, contenenti otto comparatori differenziali. Questi comparatori confrontano il valore del sensore con un valore di riferimento per determinare se il segnale di uscita deve essere alto o basso, consentendo il rilevamento delle linee nere.

.. image:: img/lm339_chip.png

Schema di funzionamento di un canale:

.. image:: img/tcrt_lm339.png

* Impostare una tensione di riferimento sul pin VREF (questa tensione di riferimento viene regolata tramite un potenziometro presente sullo Zeus Car Shield) e applicarla all’ingresso invertente (-) del comparatore.
* Collegare il collettore del fototransistor del sensore TCRT5000 all’ingresso non invertente (+) del comparatore.
* Quando il raggio infrarosso emesso dal sensore TCRT5000 non viene riflesso o l’intensità della riflessione è insufficiente, il fototransistor rimane interdetto e il collettore è connesso alla resistenza di pull-up a 5V. In questo caso, l’ingresso non invertente (+) del comparatore ha un potenziale maggiore rispetto all’ingresso invertente (-).
* L’uscita del comparatore è alta e l’indicatore rimane spento. E viceversa.
* Poiché una superficie nera assorbe la luce e riflette meno raggi infrarossi, su una superficie nera l’uscita del comparatore resta alta e l’indicatore non si accende.
* Una superficie bianca, invece, riflette una quantità maggiore di raggi infrarossi, facendo condurre il fototransistor. In questo caso, il potenziale dell’ingresso non invertente diventa inferiore a quello dell’ingresso invertente, l’uscita del comparatore si porta a livello basso e l’indicatore si accende.


Le informazioni di questi 8 sensori vengono trasferite alla scheda Arduino tramite il 74HC165 (registro a scorrimento a ingresso parallelo e uscita seriale).

* |link_74hc165_datasheet|

Il 74HC165 è un registro a scorrimento a 8 bit con ingresso parallelo e uscita seriale, in grado di fornire uscite seriali mutuamente esclusive (Q0 e Q7) nello stadio finale. Quando l'ingresso di caricamento parallelo (PL) è basso, i dati paralleli forniti sulle porte D0-D7 vengono caricati nel registro in modo asincrono. Quando PL è alto, i dati vengono invece inseriti nel registro in modalità seriale tramite l'ingresso DS, spostandosi di un bit verso destra a ogni fronte di salita dell'impulso di clock (Q0 → Q1 → Q2, ecc.). Sfruttando questa caratteristica, è possibile ottenere un'espansione da parallelo a seriale collegando semplicemente l'uscita Q7 all'ingresso DS dello stadio successivo.

L'ingresso di clock del 74HC165 adotta una struttura "gated OR" che consente di utilizzare uno degli ingressi come abilitazione del clock attiva bassa (CE). I pin CP e CE sono assegnati in modo indipendente e possono essere intercambiati per facilitare il cablaggio, se necessario. Il segnale CE può passare dallo stato basso a quello alto solo quando CP è alto. Inoltre, per evitare il disallineamento dei dati durante lo stato attivo di PL, è necessario impostare CP o CE su livello alto prima del fronte di salita di PL.
.. image:: img/74hc165_con.png


**Caratteristiche Tecniche**

* Tensione di funzionamento: 3.3V ~ 5V
* Uscita: digitale (on/off)
* Caricamento parallelo asincrono a 8 bit
* Ingresso seriale sincrono
* Soglia di rilevamento: regolabile tramite pin VREF
* Sensore utilizzato: TCRT5000
* Connettore: ZH1.5-6P
* Temperatura operativa: -10 °C ~ +50 °C
* Dimensioni: 80mm x 80mm


**Calibrazione del Modulo**

    Poiché ogni pavimentazione ha diversi valori di scala di grigi, la soglia preimpostata in fabbrica potrebbe non essere adeguata per l'ambiente corrente. È quindi necessario calibrare il modulo prima dell'uso. Si consiglia di ripetere la calibrazione ogni volta che cambia il colore della superficie.

    * Posiziona lo Zeus Car su una superficie bianca e regola il potenziometro finché il LED del sensore di grigio non si illumina.

        .. image:: img/zeus_line_calibration.jpg

    * Ora posiziona i due sensori di grigio laterali esattamente tra la linea nera e la superficie bianca. Regola lentamente il potenziometro finché l'indicatore di segnale non si spegne.

        .. image:: img/zeus_line_calibration1.jpg

    * Muovi il modulo ripetutamente tra la linea nera e la superficie bianca per verificare che il LED del sensore di grigio si spegna sulla linea nera e si accende sulla superficie bianca, confermando che la calibrazione è riuscita.

