.. note:: 

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Unisciti a noi per approfondire la conoscenza di Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anticipo agli annunci dei nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a eventi speciali e concorsi con premi.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _play_app_control:

Controllo tramite APP
=========================

Per controllare Zeus Car dal tuo dispositivo mobile, devi scaricare l'APP **SunFounder Controller**, connetterti alla rete LAN del Zeus Car e creare il tuo controller personalizzato all'interno dell'APP.

.. raw:: html

    <div style="text-align: center;">
        <video center loop autoplay muted style = "max-width:70%">
            <source src="../_static/video/app_control.mp4"  type="video/mp4">
            Your browser does not support the video tag.
        </video>
    </div>

.. raw:: html
    
    <br/> <br/>


Guida Rapida
---------------------

Ecco un breve tutorial video. Guarda prima il video e poi segui le istruzioni qui sotto.

.. raw:: html

    <div style="text-align: center;">
        <video loop controls style = "max-width:90%">
            <source src="../_static/video/app_control_quick_guide.mp4"  type="video/mp4">
            Your browser does not support the video tag.
        </video>
    </div>

.. raw:: html
    
    <br/> <br/>

#. Accendi Zeus Car.

   * Al primo utilizzo o quando il cavo della batteria è scollegato, il circuito di protezione da sovrascarica dello Zeus Car Shield si attiva.
   * Quindi, è necessario collegare il cavo Type-C per circa 5 secondi.

     .. raw:: html
     
         <div style="text-align: center;">
             <video center loop autoplay muted style = "max-width:70%">
                 <source src="../_static/video/activate_battery.mp4"  type="video/mp4">
                 Your browser does not support the video tag.
             </video>
         </div>
     
     .. raw:: html
         
         <br/>

   * Se l'indicatore di alimentazione si accende, significa che la protezione è stata disattivata. Controlla gli indicatori della batteria: se entrambi sono spenti, collega nuovamente il cavo Type-C per ricaricare la batteria.

     .. image:: img/zeus_power.jpg
         :width: 500
         :align: center
     
     .. raw:: html
         
         <br/>  

   * Ora sposta il piccolo interruttore a destra per stabilire la comunicazione tra Zeus Car e l'ESP32 CAM. Successivamente, premi il pulsante Reset per riavviare il codice. A questo punto, noterai che le luci del telaio passano dall'arancione a un blu chiaro.

     .. raw:: html
     
         <div style="text-align: center;">
             <video center loop autoplay muted style = "max-width:70%">
                 <source src="../_static/video/re_run_code.mp4"  type="video/mp4">
                 Your browser does not support the video tag.
             </video>
         </div>
     
     .. raw:: html
         
         <br/>

#. Installa `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ da **APP Store(iOS)** o **Google Play(Android)**.


#. Connettiti alla rete WLAN ``Zeus_Car``.

   Ora collega il tuo dispositivo mobile alla rete locale (LAN) trasmessa da Zeus Car. In questo modo, il tuo dispositivo e Zeus Car saranno sulla stessa rete, facilitando la comunicazione tra l'app e il veicolo.

   * Trova ``Zeus_Car`` nella lista delle reti WLAN del tuo smartphone o tablet, inserisci la password ``12345678`` e connettiti.

     .. note::

       * La connessione attuale è all'hotspot di Zeus Car, quindi non ci sarà accesso a Internet. Se viene richiesto di cambiare rete, seleziona Rimani connesso.
       * :ref:`ap_to_sta`
   
     .. raw:: html
   
       <div style="text-align: center;">
           <video center loop autoplay muted style = "max-width:80%">
               <source src="../_static/video/connect_wifi.mp4"  type="video/mp4">
               Your browser does not support the video tag.
           </video>
       </div>
   
     .. raw:: html
         
         <br/>

#. Crea un controller.

   * Per aggiungere un controller in SunFounder Controller, clicca sull'icona **+**.

     .. image:: img/app1.png
         :width: 500
         :align: center
     
     .. raw:: html
         
         <br/>  

   * Sono disponibili controller preimpostati per alcuni prodotti, seleziona **Zeus Car**, assegna un nome oppure premi **Confirm**.

     .. image:: img/app_preset.jpg
         :width: 500
         :align: center
     
     .. raw:: html
         
         <br/>  

   * Una volta all'interno, l'app cercherà automaticamente Zeus Car. Dopo pochi secondi, apparirà un messaggio che indica Connessione riuscita.

     .. image:: img/app_edit.jpg
         :width: 500
         :align: center
     
     .. raw:: html
         
         <br/> 

   * Ora, tocca il pulsante |app_run| per visualizzare il feed video in tempo reale della telecamera e controllare Zeus Car utilizzando i widget disponibili.

     .. image:: img/app_run123.png
         :width: 500
         :align: center
     
     .. raw:: html
         
         <br/>  

#. Funzioni dei widget.

    * :ref:`app_compass_cali`: Attiva la calibrazione della bussola.
    * **Stop(F)**: Ferma tutti i movimenti del veicolo.
    * **Reset Heading(G)**: Dopo aver posizionato il veicolo nella direzione desiderata, premi questo widget per impostare quella direzione come anteriore del movimento del veicolo. Ciò consente di specificare rapidamente un orientamento senza dover ruotare lentamente il veicolo.
    * :ref:`app_speech_control`: Passa alla modalità di controllo vocale.
    * :ref:`app_drift`: Attiva la funzione di drift.
    * :ref:`app_move`: Controlla il movimento del veicolo in tutte le direzioni.
        
    * :ref:`app_line_track`: I seguenti due widget consentono di attivare la modalità di tracciamento delle linee.

        * **Line no Mag(M)**: Passa alla modalità di tracciamento delle linee senza essere influenzato dal campo magnetico. Durante il tracciamento, l’orientamento di Zeus Car cambierà continuamente.
        * **Line(N)**: Attiva la modalità di tracciamento delle linee, mantenendo un orientamento fisso grazie alla presenza del campo magnetico.

    * :ref:`app_follow`: Attiva la modalità di inseguimento.
    * :ref:`app_avoid`: Passa alla modalità di evitamento ostacoli.
    * :ref:`app_rotate_drift`: Controlla l'orientamento della testata.

.. _app_compass_cali:

Calibrazione (E)
--------------------------

Attiva la calibrazione della bussola cliccando sul pulsante |app_cali_e|.

Posiziona Zeus Car a terra. Una volta avviata la calibrazione della bussola, il veicolo inizierà a ruotare in senso antiorario e si fermerà dopo circa 1 minuto. Se la rotazione dura più di 2 minuti, significa che il campo magnetico nell'area è complesso. Prova a cambiare posizione e ripeti la calibrazione.


.. _app_drift:

Abilita Drift (J)
---------------------


Clicca sul pulsante |app_drift_j| per attivare la funzione di drift.

* Scorrendo il widget |app_rotate_q| in senso antiorario, vedrai Zeus Car effettuare un drift verso destra. Rilasciando il dito, il veicolo si fermerà nella posizione attuale.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
* Allo stesso modo, scorrendo il widget |app_rotate_q| in senso orario, Zeus Car effettuerà un drift verso sinistra e si fermerà nella posizione attuale.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
.. _app_move:

Movimento in tutte le direzioni (K)
--------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Zeus Car si muoverà nella direzione desiderata quando scorri il widget |app_move_k|.

.. image:: img/joystick_move.png
    :align: center

.. raw:: html
    
    <br/>  

Il veicolo si muove ogni volta che scorri il widget. Se tieni premuto senza rilasciare, Zeus Car continuerà a muoversi.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center


.. raw:: html
    
    <br/>  
 
.. _app_speech_control:

Controllo vocale (I)
----------------------

Premendo il widget |app_speech_m| puoi attivare la funzione STT (Speech to Text).

L'app SunFounder Controller utilizza il motore di riconoscimento vocale del tuo dispositivo mobile. Quando tieni premuto il widget **Speech(I)** e pronunci un comando nel microfono del tuo dispositivo mobile, il sistema convertirà la tua voce in testo e invierà il comando a Zeus Car. Se il comando corrisponde a quelli predefiniti nel codice, il veicolo eseguirà l'azione corrispondente.

Ecco i comandi attualmente disponibili. Pronuncia uno dei seguenti comandi per vedere Zeus Car rispondere:



* ``stop``: Ferma tutti i movimenti del veicolo.
* ``pasue``: Funziona in modo simile a stop, ma se la testata del veicolo non è allineata alla direzione originaria, si muoverà lentamente fino a orientarsi nella direzione corretta.
* ``forward`` (avanti)
* ``backward`` (indietro)
* ``left forward`` (avanti sinistra)
* ``left backward`` (indietro sinistra)
* ``right forward`` (avanti destra)
* ``right backward`` (indietro destra)
* ``move left`` (sposta a sinistra)
* ``move right`` (sposta a destra)

.. note::

    La funzione STT (Speech to Text) richiede una connessione a Internet e i servizi Google sui dispositivi Android. Tuttavia, questa funzione non è compatibile con la modalità AP (Access Point) predefinita di Zeus Car.

    In modalità AP, Zeus Car crea una rete Wi-Fi locale alla quale il tuo dispositivo mobile può connettersi, ma senza accesso a Internet.

    Per utilizzare STT su Android, cambia il codice del veicolo da modalità AP a modalità STA come descritto in :ref:`stt_android`.

.. note::

    I dispositivi iOS, che utilizzano un motore di riconoscimento vocale offline, funzionano correttamente sia in modalità AP che STA.

Dopo aver ricevuto uno degli otto comandi sopra, Zeus Car continuerà a muoversi nella direzione specificata finché non riceverà il comando ``stop`` o ``pause``.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center

* ``turn left``: Questo comando farà ruotare Zeus Car di 45° a sinistra rispetto al proprio asse centrale, poi continuerà a muoversi in avanti o si fermerà in base allo stato precedente. Se era fermo, si fermerà dopo la rotazione di 45°; se era in movimento, continuerà a muoversi dopo la rotazione.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
   
* ``turn right``: Questo comando farà ruotare Zeus Car di 45° a destra rispetto al proprio asse centrale, poi continuerà a muoversi in avanti o si fermerà in base allo stato precedente.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
.. _app_line_track:

Tracciamento della Linea
----------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


Clicca sul widget |app_line_n| per attivare la modalità di tracciamento della linea.

Zeus Car offre due modalità di tracciamento: una in cui la testata è sempre orientata nella direzione di movimento e un'altra in cui rimane fissa in un'unica direzione. Qui è stata selezionata la seconda modalità.


#. Applica una linea larga 3 cm

    Il modulo Omni Grayscale ha otto sensori con una distanza tra loro compresa tra 2 e 3 cm. Per garantire il rilevamento corretto, almeno due sensori devono intercettare la linea nera contemporaneamente. Pertanto, la linea deve avere una larghezza minima di 3 cm e un angolo di curvatura non inferiore a 90°.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Calibrazione del modulo Omni Grayscale

    Poiché i valori di scala di grigi del pavimento possono variare, la soglia preimpostata in fabbrica potrebbe non essere adatta all'ambiente corrente. Si consiglia di calibrare il modulo ogni volta che il colore del pavimento cambia in modo significativo.

    * Posiziona Zeus Car su una superficie bianca e ruota il potenziometro fino a quando la luce del sensore di grigi si accende appena.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center

    
    .. raw:: html
        
        <br/>  

    * Ora posiziona i due sensori di grigi laterali tra la linea nera e la superficie bianca e ruota lentamente il potenziometro fino a quando l'indicatore del segnale si spegne.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Sposta ripetutamente Zeus Car sopra la linea nera e la superficie bianca per assicurarti che i sensori di grigi si spengano quando si trovano tra la linea nera e la superficie bianca, e si accendano quando sono sulla superficie bianca. Questo indica che il modulo è stato calibrato correttamente.


#. Posiziona Zeus Car sulla linea adesiva, clicca sul widget |app_line_n| e il veicolo seguirà la linea.

#. Poiché il modulo Omni Grayscale è sensibile alle condizioni ambientali, si consiglia di ripetere la calibrazione se il tracciamento non è preciso o si verificano deviazioni.

.. _app_follow:

Modalità Segui (O)
-------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Clicca sul widget |app_follow_o| per attivare la modalità di inseguimento.

Il sensore ad ultrasuoni rileva ostacoli a una distanza di 20 cm e li segue. I due moduli di evitamento ostacoli consentono al veicolo di seguire oggetti a sinistra o a destra, ma devono essere calibrati prima dell'uso (15 cm).

#. Calibrazione del modulo IR di evitamento ostacoli.

    * Inizia regolando il modulo di evitamento ostacoli destro. Durante il trasporto, il trasmettitore e il ricevitore del modulo IR possono inclinarsi a causa di urti. Pertanto, è necessario raddrizzarli manualmente.

        .. raw:: html

            <video loop autoplay muted style = "max-width:80%">
                <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>

        .. raw:: html
            
            <br/> <br/>  

    * Posiziona un ostacolo a circa 15 cm dal modulo di evitamento ostacoli IR.
    * Sul modulo sono presenti due potenziometri: uno per regolare la potenza di trasmissione e uno per la frequenza di trasmissione. Regolandoli, puoi modificare la distanza di rilevamento.
    * Ruota un potenziometro e, se a 15 cm la luce del segnale sul modulo si accende, la regolazione è completata; in caso contrario, prova a regolare l'altro potenziometro.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 400
        :align: center

    .. raw:: html
        
        <br/>  

    * Ripeti la calibrazione per l'altro modulo di evitamento ostacoli.

#. Posiziona Zeus Car su un tavolo o a terra e fallo seguire la tua mano o altri ostacoli.

.. _app_avoid:

Evitamento Ostacoli (P)
--------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Per attivare la modalità di evitamento ostacoli, clicca sul widget |app_avoid_p|, ma prima consulta :ref:`app_follow` per calibrare i due moduli di evitamento ostacoli.

* Zeus Car avanzerà in avanti.
* Se il modulo a ultrasuoni rileva un ostacolo davanti, il veicolo girerà a sinistra.
* Se il modulo di evitamento ostacoli sinistro rileva un ostacolo, il veicolo girerà a destra, mentre se il modulo destro rileva un ostacolo, il veicolo girerà a sinistra.

.. _app_rotate_drift:

Controllo della Direzione (Q)
-------------------------------

* Quando il pulsante |app_drift_j| è attivo, il widget |app_rotate_q| viene utilizzato per far derapare Zeus Car a sinistra e a destra.

* Quando il widget |app_drift_j| è disattivato, il widget |app_rotate_q| viene utilizzato per controllare l'orientamento della testata del veicolo.

    * Scorrendo il widget |app_rotate_q| in senso antiorario, Zeus Car ruoterà anch'esso in senso antiorario. Rilasciando il dito, il veicolo tornerà alla sua direzione originale.

    .. image:: img/zeus_turn_left.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Allo stesso modo, scorrendo il widget |app_rotate_q| in senso orario, il veicolo ruoterà in senso orario e tornerà alla direzione originale una volta rilasciato.

    .. image:: img/zeus_turn_right.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  



