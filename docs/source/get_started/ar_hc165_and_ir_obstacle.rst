.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

9. Sensore a Infrarossi per Ostacoli
========================================

In questo progetto, imparerai a utilizzare i moduli di evitamento ostacoli a infrarossi posizionati su entrambi i lati della Zeus Car.

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Apri il file ``9_hc165_and_ir_obstacle.ino`` nel percorso ``zeus-car-main\examples\9_hc165_and_ir_obstacle``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/3486be01-6b0e-4e84-86f6-9bdadafa1f48/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

    .. note::
        Non scollegare il cavo USB in questo passaggio, poiché è necessario controllare i dati dei due moduli di evitamento ostacoli sul computer.

#. Apri il monitor seriale e assicurati che la velocità di trasmissione (baud rate) sia impostata su 115200, quindi osserva i dati stampati.

   * Se entrambi i moduli di evitamento ostacoli non rilevano alcun ostacolo, il monitor seriale stamperà ``0, 0``.
   * Se metti una mano davanti a uno dei moduli, vedrai stampato ``1, 0`` o ``0, 1``.

    .. image:: img/ar_serial.png

#. Calibrare il modulo di evitamento ostacoli a infrarossi.

    * Inizia regolando il modulo di evitamento ostacoli destro. Durante il trasporto, il trasmettitore e il ricevitore del modulo a infrarossi potrebbero essersi inclinati a causa di urti. Assicurati di raddrizzarli manualmente.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Posiziona un ostacolo a circa 15 cm dal modulo IR di evitamento ostacoli.
    * Sul modulo sono presenti due potenziometri: uno per regolare la potenza di trasmissione e uno per la frequenza di invio del segnale. Regolando questi due potenziometri, puoi modificare la distanza di rilevamento.
    * Regola un potenziometro e verifica che, a 15 cm di distanza, l’indicatore luminoso del modulo si accenda. Se non si illumina, prova a regolare l’altro potenziometro.

        .. image:: img/zeus_ir_avoid.jpg

    * Ripeti la calibrazione per l'altro modulo di evitamento ostacoli seguendo lo stesso procedimento.
