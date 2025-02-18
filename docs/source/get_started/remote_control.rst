.. note:: 

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci la tua conoscenza su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l’aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci sui nuovi prodotti e alle anteprime esclusive.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni speciali per le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _play_remote_control:

Controllo con il Telecomando
===============================

La Zeus Car può essere controllata direttamente tramite il telecomando: basta accendere l’auto e premere i pulsanti corrispondenti. Questo metodo è stabile e meno soggetto a interferenze esterne, anche se il controllo potrebbe risultare meno flessibile rispetto all’uso dell’APP.

Guida Rapida
-----------------------

Questo è un video tutorial rapido. Guarda prima il video, poi segui le istruzioni riportate di seguito.

.. raw:: html

   <video loop controls style = "max-width:90%">
      <source src="../_static/video/ir_control_quick_guide.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

#. Avviamo la Zeus Car.

    * Alla prima accensione o dopo aver scollegato il cavo della batteria, il circuito di protezione contro la scarica eccessiva della Zeus Car Shield si attiverà automaticamente.
    * Per sbloccare la protezione, collega il cavo Type-C per circa 5 secondi.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/activate_battery.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>

    .. raw:: html
        
        <br/>

    
    * Se l'indicatore di alimentazione si illumina, significa che la protezione è stata disattivata. Controlla gli indicatori della batteria: se entrambi sono spenti, continua a caricare la batteria collegando il cavo Type-C.

    .. image:: img/zeus_power.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    

    * Ora sposta l'interruttore più piccolo verso destra per stabilire la comunicazione tra la Zeus Car e l’ESP32 CAM. Successivamente, premi il pulsante Reset per riavviare il codice. A questo punto, noterai che le luci sotto il telaio cambieranno colore, passando dall’arancione a un azzurro chiaro.

    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/re_run_code.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>

    .. raw:: html
        
        <br/>

#. Premi i diversi tasti del telecomando per controllare l’auto.

    .. image:: img/remote_control.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * **Stop**: Arresta tutti i movimenti della Zeus Car.
    * :ref:`ir_compass_cali`: Attiva la calibrazione della bussola.
    * :ref:`ir_line_track`: Passa alla modalità di tracciamento della linea.
    * :ref:`ir_follow`: Attiva la modalità di inseguimento.
    * :ref:`ir_avoid`: Attiva la modalità di evitamento ostacoli.
    * :ref:`drift`: Effettua una derapata a sinistra/destra.
    * **Imposta Direzione**: Dopo aver posizionato l’auto in una determinata direzione, premi questo tasto per impostarla come direzione di marcia. In questo modo, puoi stabilire rapidamente una direzione senza dover ruotare l’auto manualmente.
    * :ref:`rotate_left/right`: Ruota a sinistra/destra.
    * :ref:`ir_move`: Controlla il movimento dell’auto in tutte le direzioni.
    * **Pausa**: Ha la stessa funzione dello Stop, ma se la parte frontale dell’auto non è orientata nella direzione impostata inizialmente, tornerà lentamente alla direzione predefinita.


.. _ir_compass_cali:

Calibrazione della Bussola
-----------------------------------

Attiva la calibrazione della bussola premendo il tasto |ir_mute|.

Posiziona la Zeus Car sul pavimento. Una volta avviata la calibrazione della bussola, l'auto inizierà a ruotare in senso antiorario e si fermerà dopo circa 1 minuto. Se continua a ruotare per più di 2 minuti, il campo magnetico in quella zona potrebbe essere complesso. Prova a cambiare posizione e ripeti la calibrazione.


.. _ir_line_track:

Tracciamento della Linea
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Premi il tasto |ir_play| per passare alla modalità di tracciamento della linea.

Sono disponibili due modalità di tracciamento della linea sulla Zeus Car: una in cui la testa dell’auto è sempre orientata nella direzione del movimento e una in cui rimane fissa in una direzione prestabilita. Qui viene selezionata la seconda modalità.

Prima di poter seguire la linea, è necessario calibrare il modulo Omni Grayscale e applicare la linea adesiva, come segue.

#. Applica una linea adesiva larga 3 cm

    Il modulo Omni Grayscale dispone di otto sensori, con una distanza tra loro compresa tra 2 e 3 cm. Affinché la linea nera venga rilevata correttamente, almeno due sensori devono essere attivati contemporaneamente. Pertanto, la linea adesiva deve essere larga almeno 3 cm e gli angoli di curvatura non devono essere inferiori a 90°.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

#. Calibrazione del modulo Omni Grayscale.

    Poiché ogni superficie ha valori di scala di grigi diversi, la soglia preimpostata di fabbrica potrebbe non essere adeguata all’ambiente corrente. È consigliabile calibrare il modulo prima dell’uso e ogni volta che il colore del pavimento cambia significativamente.

    * Posiziona la Zeus Car su una superficie bianca e regola il potenziometro fino a quando la luce del sensore di grigio si accende.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Ora posiziona i due sensori di scala di grigi ai lati, esattamente tra la linea nera e la superficie bianca, quindi regola lentamente il potenziometro finché l'indicatore del segnale non si spegne.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Muovi ripetutamente l'auto sopra la linea nera e la superficie bianca per verificare che le luci dei sensori si spengano quando sono tra i due colori e si accendano quando sono sulla superficie bianca, confermando così che il modulo è stato calibrato con successo.

#. Posiziona la Zeus Car sulla linea adesiva, premi il tasto |ir_play| e l’auto seguirà la linea.

#. A causa della sensibilità ambientale del modulo Omni Grayscale, se il tracciamento non è preciso (fuori pista), è consigliabile ripetere la calibrazione più volte.


.. _ir_follow:

Modalità Segui
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Premi il tasto |ir_backward| per attivare la modalità di inseguimento.

Il sensore a ultrasuoni rileva ostacoli fino a 20 cm di distanza e segue l'oggetto rilevato. I due moduli di evitamento ostacoli permettono all’auto di seguire l’oggetto a sinistra o a destra, ma devono essere calibrati prima dell’uso (a 15 cm).

#. Calibrazione del modulo di evitamento ostacoli IR.

    * Inizia regolando il modulo di evitamento ostacoli destro. Durante il trasporto, gli urti possono inclinare il trasmettitore e il ricevitore del modulo a infrarossi. Perciò è necessario riallinearli manualmente.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Posiziona un ostacolo a circa 15 cm di distanza dal modulo IR.
    * Sul modulo sono presenti due potenziometri: uno per regolare la potenza di trasmissione e uno per la frequenza di trasmissione. Regolandoli, puoi modificare la distanza di rilevamento.
    * Ruota un potenziometro: se a 15 cm la spia del segnale si accende, la calibrazione è riuscita. In caso contrario, regola l’altro potenziometro.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Ripeti la calibrazione per l’altro modulo di evitamento ostacoli.

#. Posiziona la Zeus Car su un tavolo o a terra e osservala mentre segue la tua mano o altri ostacoli.

.. _ir_avoid:

Evitamento Ostacoli
--------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Per attivare la modalità di evitamento ostacoli, premi il tasto |ir_forward|. Prima, però, fai riferimento alla sezione :ref:`ir_follow` per calibrare i due moduli di evitamento ostacoli.

* La Zeus Car avanzerà in linea retta.
* Il modulo a ultrasuoni rileverà eventuali ostacoli davanti e, in caso positivo, l'auto svolterà a sinistra.
* Se il modulo di evitamento ostacoli sinistro rileva un ostacolo, l’auto svolterà a destra; se il modulo destro rileva un ostacolo, l’auto svolterà a sinistra.


.. _drift:

Drift Sinistra/Destra
-------------------------------------------------

Utilizza i tasti |ir_minus| e |ir_plus| per far derapare l'auto rispettivamente a sinistra o a destra.

* Premi il tasto |ir_minus| per far derapare l’auto verso sinistra.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Premi il tasto |ir_plus| per far derapare l’auto verso destra.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>


* Se l'auto era ferma prima della derapata, premendo una sola volta il tasto |ir_minus| o |ir_plus|, la Zeus Car deraperà di 90° a sinistra o a destra.
* Se l’auto era in movimento prima della derapata, dopo aver premuto il tasto, la Zeus Car deraperà di 90° a sinistra o a destra e poi continuerà a muoversi lateralmente fino a quando non verrà premuto un altro tasto.


.. _ir_move:

Movimento in Tutte le Direzioni (1 ~ 9)
-----------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Utilizza i tasti numerici da 1 a 9 per far muovere la Zeus Car in 8 direzioni diverse.

.. image:: img/remote_control_move.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

.. _rotate_left/right:

Rotazione Sinistra/Destra (Tasto Cycle/USD)
-----------------------------------------------

* Premendo il tasto |ir_return| una volta, l'auto ruoterà di 45° verso sinistra con il corpo come punto di rotazione. A seconda dello stato precedente, continuerà a muoversi in avanti o si fermerà. Se l'auto era già ferma, si fermerà dopo aver ruotato di 45° a sinistra; se era in movimento, continuerà ad avanzare dopo la rotazione.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>


* Analogamente, premendo una volta il tasto |ir_usd|, l'auto ruoterà di 45° a destra e poi continuerà ad avanzare o si fermerà, a seconda dello stato precedente.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

