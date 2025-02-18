.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

11. Evitamento Ostacoli
================================

In questo progetto, la Zeus Car avanzerà automaticamente, mentre due moduli di evitamento ostacoli e un modulo a ultrasuoni impediranno che colpisca eventuali ostacoli.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``11_obstacle_avoid.ino`` nel percorso ``zeus-car-main\examples\11_obstacle_avoid``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/520af1d6-4ef2-4804-a4a9-f6aa92985258/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver caricato con successo il codice, sposta l'interruttore di alimentazione su ON per avviare la Zeus Car.

    * La Zeus Car avanzerà.
    * Il modulo a ultrasuoni rileverà ostacoli di fronte: se ne rileva uno, l’auto svolterà a sinistra.
    * Se il modulo di evitamento ostacoli sinistro rileva un ostacolo, l’auto svolterà a destra; se lo rileva quello destro, l’auto svolterà a sinistra.

.. note::
    Prima dell’uso, è necessario regolare la distanza di rilevamento dei due moduli di evitamento ostacoli a 15 cm. Segui questi passaggi:

    * Inizia regolando il modulo di evitamento ostacoli destro. Durante il trasporto, il trasmettitore e il ricevitore del modulo a infrarossi potrebbero essersi inclinati a causa di urti. Assicurati di raddrizzarli manualmente.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Posiziona un ostacolo a circa 15 cm dal modulo IR di evitamento ostacoli.
    * Sul modulo sono presenti due potenziometri: uno regola la potenza di trasmissione e l’altro la frequenza di invio del segnale. Regolando questi due potenziometri, puoi impostare la distanza di rilevamento.
    * Regola un potenziometro e verifica che, a 15 cm di distanza, l’indicatore luminoso del modulo si accenda. Se non si illumina, prova a regolare l’altro potenziometro.

        .. image:: img/zeus_ir_avoid.jpg

    * Calibra anche l'altro modulo di evitamento ostacoli seguendo lo stesso procedimento.
