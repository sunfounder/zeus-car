.. note:: 

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e giveaway festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!


Modulo di evitamento ostacoli IR
=======================================

.. image:: img/ir_avoid.png

* **GND**: Ingresso di terra
* **+**: Alimentazione in corrente continua da 3,3V a 5V
* **Out**: Pin di uscita del segnale, predefinito alto, passa a basso quando viene rilevato un ostacolo
* **EN**: Pin di abilitazione del modulo. Quando è basso, il modulo è attivo ed è collegato a GND tramite un ponticello di default.


Si tratta di un comune modulo IR per l'evitamento degli ostacoli, che utilizza una coppia di componenti di trasmissione e ricezione a infrarossi. Il trasmettitore emette luce infrarossa e, quando rileva un ostacolo nella direzione di rilevamento, la luce viene riflessa e ricevuta dal tubo del ricevitore. In quel momento, l'indicatore si accende e, dopo l'elaborazione del circuito, viene emesso un segnale a livello basso.

Ha una distanza di rilevamento compresa tra 2 e 40 cm e una notevole capacità di resistenza alle interferenze. La riflettività varia in base al colore dell'oggetto: più l'oggetto è scuro, minore sarà la distanza di rilevamento. Contro una parete bianca, il sensore rileva gli ostacoli in un intervallo di 2-30 cm.

Quando il pin di abilitazione è a livello basso, il modulo è attivo. Se il ponticello è inserito, il pin EN è collegato a GND e il modulo funziona sempre. Per controllare il pin EN tramite codice, è necessario rimuovere il ponticello.

.. image:: img/ir_avoid_cap.png

**Regolazione della distanza di rilevamento**

A causa delle diverse condizioni di illuminazione, la distanza di rilevamento preimpostata in fabbrica potrebbe non essere ottimale, quindi è consigliabile regolarla prima dell'uso.

Sul modulo sono presenti due potenziometri: uno per regolare la potenza di trasmissione e l'altro per regolare la frequenza di trasmissione. Agendo su questi due potenziometri è possibile regolare la distanza di rilevamento effettiva.

Per calibrare il modulo, posiziona un ostacolo bianco alla distanza desiderata e regola uno dei potenziometri finché l'indicatore luminoso si accende. Successivamente, sposta ripetutamente l'ostacolo per verificare se la luce dell'indicatore si accende alla distanza necessaria.

Se l'indicatore non si accende o rimane sempre acceso, prova a regolare l'altro potenziometro.

.. image:: ../get_started/img/zeus_ir_avoid.jpg

**Caratteristiche Tecniche**

* Tensione operativa: 3,3V - 5V
* Uscita: digitale (on/off)
* Soglia di rilevamento: regolabile tramite due potenziometri
* Distanza di rilevamento: da 2 a 40 cm
* Regolazione R5: regolazione della frequenza (38 kHz, già ottimizzata)
* Regolazione R6: regolazione del ciclo di lavoro del LED IR (già ottimizzata)
* Temperatura di esercizio: -10°C ~ +50°C
* Angolo di rilevamento: 35°
* Interfaccia I/O: 4 fili (- / + / S / EN)
* Dimensioni: 45 x 16 x 10 mm
* Peso: 9 g
