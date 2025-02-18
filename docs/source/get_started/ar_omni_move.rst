.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

2. Movimento Omnidirezionale
================================

In questo progetto imparerai a muovere la Zeus Car in direzioni di 0°, 45°, 90°, 135°, 180°, 225°, 270° e 315°.

Se si ignorano l’attrito con il suolo e le tolleranze strutturali, il percorso della Zeus Car dovrebbe essere un ottagono e tornare infine al punto di partenza.

**Come fare?**

#. La ESP32-CAM e la scheda Arduino condividono gli stessi pin RX (ricezione) e TX (trasmissione). Pertanto, prima di caricare il codice, scollega la ESP32-CAM per evitare conflitti o problemi.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center

#. Apri il file ``2_omni_move.ino`` nel percorso ``zeus-car-main\examples\2_omni_move``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/2425f280-5bd4-4e49-bb2e-220d1f4f867b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Seleziona la scheda e la porta corrette, quindi clicca sul pulsante **Upload**.

    .. note::
        * Se ricevi il messaggio di errore "Compilation error: SoftPWM.h: No such file or directory", significa che la libreria ``SoftPWM`` non è installata.
        * Consulta :ref:`ar_install_lib` per installare le due librerie necessarie ``SoftPWM`` e ``IRLremote``.

    .. image:: img/ar_board_upload.png

#. Sposta l’interruttore di alimentazione su ON per avviare la Zeus Car.

    .. image:: img/zeus_power.jpg

#. A questo punto, la Zeus Car si muoverà nelle direzioni di 0°, 45°, 90°, 135°, 180°, 225°, 270° e 315°.


**Come funziona?**

Il movimento della Zeus Car viene implementato principalmente attraverso questa funzione.

.. code-block::

    void carMove(int16_t angle, int8_t power)

* ``angle``: La direzione in cui vuoi muovere l’auto. La testa della Zeus Car corrisponde a 0° e l’angolo aumenta in senso antiorario.
* ``power``: La potenza di movimento, con un intervallo compreso tra -100% e 100%. Se ``power`` è positivo, l’auto si muove in avanti; se negativo, si muove all’indietro.
