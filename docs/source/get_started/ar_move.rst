.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

1. Movimenti di Base
========================

In questo progetto imparerai a far muovere la Zeus Car in tutte le direzioni.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

   
#. Collega la Zeus Car al computer utilizzando il cavo USB blu. Una volta collegata la scheda Arduino, il computer la riconoscerà automaticamente e le assegnerà una porta COM, visibile in Gestione dispositivi.

#. Apri il file ``1_basic_move.ino`` nel percorso ``zeus-car-main\examples\1_basic_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/cedd4eb2-3283-48ae-8851-c932eb2098ea/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Puoi selezionare rapidamente la scheda e la porta da questa sezione.

    .. image:: img/ar_board.png
    
    .. note::
        Se la porta COMxx non appare, apri il Board Manager dalla barra laterale e assicurati che il core "Arduino AVR Boards" sia installato.

        .. image:: img/ar_other_board.png

#. Ora clicca sul pulsante **Upload** per caricare il codice sulla scheda Arduino. Una volta completato il caricamento, comparirà una notifica nell'angolo in basso a destra della finestra dell'IDE. Se dovessero verificarsi errori, verranno elencati in questa sezione.

    .. note::
        * Se ricevi un messaggio di errore "Compilation error: SoftPWM.h: No such file or directory", significa che la libreria ``SoftPWM`` non è installata.
        * Consulta :ref:`ar_install_lib` per installare le due librerie necessarie ``SoftPWM`` e ``IRLremote``.

    .. image:: img/ar_upload.png

#. Avviamo la Zeus Car.

    * Quando la Zeus Car viene utilizzata per la prima volta o il cavo della batteria viene scollegato, il circuito di protezione da sovra-scarica dello Shield si attiva.
    * Per sbloccare questa protezione, collega il cavo Type-C per circa 5 secondi.

            .. image:: img/zeus_charge.jpg

    * Se l’indicatore di alimentazione si accende, significa che la protezione è stata disattivata. Controlla anche gli indicatori della batteria: se entrambi sono spenti, continua a caricare la batteria collegando il cavo Type-C.

        .. image:: img/zeus_power.jpg

#. Ora vedrai la Zeus Car muoversi per un secondo in ogni direzione.

    .. image:: img/zeus_move.jpg
        :width: 600

**Come funziona?**

Questi movimenti vengono ottenuti grazie alla combinazione delle quattro ruote Mecanum. Ad esempio, quando tutte e quattro le ruote si muovono avanti o indietro contemporaneamente, la Zeus Car si muove nella stessa direzione. Se due ruote si muovono in avanti e le altre due all’indietro, la Zeus Car eseguirà una traslazione laterale o una rotazione.

Vediamo più nel dettaglio come si realizzano questi movimenti.

* Movimento avanti e indietro, traslazione laterale.

    .. image:: img/ar_fwlr.jpg
        :width: 600

* Traslazione diagonale.

    .. image:: img/ar_fblr.jpg
        :width: 600

* Rotazione a sinistra e a destra.

    .. image:: img/ar_turn_lr.jpg
        :width: 600

