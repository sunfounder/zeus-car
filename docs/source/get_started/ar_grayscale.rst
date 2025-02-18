.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _ar_grayscale:

13. Sensore di Scala di Grigi
===============================

In questo progetto, imparerai a leggere e calibrare il modulo Omni Grayscale posizionato sul fondo della Zeus Car.

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Apri il file ``13_hc165_and_grayscale.ino`` nel percorso ``zeus-car-main\examples\13_hc165_and_grayscale``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1c34354c-dd61-4e86-9b99-eccc93e9293f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

    .. note::
        Non scollegare il cavo USB in questo passaggio, poiché è necessario controllare i dati del modulo Omni Grayscale sul computer.

#. Apri il monitor seriale e assicurati che la velocità di trasmissione (baud rate) sia impostata su 115200. Si consiglia di cliccare sull'icona **Toggle Autoscroll** per visualizzare sempre i dati più recenti.

    .. image:: img/ar_grayscale.png

    * Capovolgi l’auto e osserva i dati stampati sul monitor seriale. Dovresti vedere ``data: 11111111``.
    * Coprendo uno dei sensori sul modulo con la mano, vedrai il valore nella posizione corrispondente cambiare in ``0``.
    * Ad esempio, coprendo il sensore ``U11``, il monitor seriale mostrerà ``data: 01111111``. 

#. Calibrare il modulo Omni Grayscale.

    Poiché il valore della scala di grigi può variare a seconda del tipo di pavimentazione, la soglia preimpostata in fabbrica potrebbe non essere adeguata per il tuo ambiente. Per questo motivo, è necessario calibrare il modulo prima dell’uso. Si consiglia di eseguire una nuova calibrazione ogni volta che il colore del pavimento cambia significativamente.

    * Posiziona la Zeus Car su una superficie bianca e regola il potenziometro finché il LED del sensore di grigio si illumina appena.

        .. image:: img/zeus_line_calibration.jpg

    * Ora posiziona i due sensori di grigio laterali tra la linea nera e la superficie bianca e regola lentamente il potenziometro finché l’indicatore del segnale non si spegne.

        .. image:: img/zeus_line_calibration1.jpg

    * Muovi ripetutamente il veicolo tra la linea nera e la superficie bianca per verificare che il LED del sensore si spenga quando è tra le due aree e si illumini quando è sulla superficie bianca. Se il comportamento è corretto, la calibrazione è stata eseguita con successo.
