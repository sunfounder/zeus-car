.. note:: 

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers de Raspberry Pi, Arduino et ESP32 avec d’autres passionnés et approfondissez vos connaissances.

    **Pourquoi nous rejoindre ?**

    - **Support d'experts** : Bénéficiez de l’aide de notre communauté et de notre équipe pour résoudre les problèmes après-vente et relever les défis techniques.
    - **Apprentissage et partage** : Échangez des conseils et des tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux exclusivités.
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos dernières innovations.
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres promotionnelles saisonnières.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

.. _ar_app_control_plus:

18. Contrôle avancé via l'APP
==================================

Ce projet intègre les fonctions de suivi de ligne, de suivi d’objet et d’évitement d’obstacles basées sur :ref:`ar_app_control`.

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/app_control.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>


.. note::
    Veuillez installer `SunFounder Controller <https://docs.sunfounder.com/projects/sf-controller/en/latest/>`_ depuis **l'App Store (iOS)** ou **Google Play (Android)**.


**Comment procéder ?**

#. La ESP32-CAM et la carte Arduino partagent les mêmes broches RX (réception) et TX (transmission). Par conséquent, lorsque vous téléversez du code, vous devez d'abord déconnecter la ESP32-CAM pour éviter tout conflit ou problème potentiel.

    .. image:: img/unplug_cam.png
        :width: 400
        :align: center


#. Ouvrez le fichier ``18_app_control_plus.ino`` sous le chemin ``zeus-car-main\examples\18_app_control_plus``.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/b67e7245-369b-4218-b12c-d73f95ac3b22/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Une fois le code téléversé avec succès, rebranchez la ESP32-CAM, puis mettez l'interrupteur d’alimentation sur ON pour démarrer le Zeus Car.

    .. image:: img/plug_esp32_cam.jpg
        :width: 300
        :align: center
        
#. Basculez le commutateur de téléversement sur Run (côté droit du schéma) pour lancer la ESP32-CAM. 

    .. image:: img/zeus_run.jpg

#. Appuyez sur le bouton de réinitialisation pour relancer le programme de la carte Arduino.

    .. image:: img/zeus_reset_button.jpg

#. Connectez-vous au réseau WLAN ``Zeus_Car``.

    Connectez maintenant votre appareil mobile au réseau local (LAN) diffusé par le Zeus Car. Ainsi, votre appareil mobile et le Zeus Car seront sur le même réseau, facilitant la communication entre l’application et le véhicule.


    * Recherchez ``Zeus_Car`` dans les paramètres Wi-Fi de votre téléphone ou tablette, entrez le mot de passe ``12345678``, puis connectez-vous.

    
    .. raw:: html

        <div style="text-align: center;">
            <video center loop autoplay muted style = "max-width:80%">
                <source src="../_static/video/connect_wifi.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>
        </div>

    .. raw:: html
        
        <br/>

    * Le mode de connexion par défaut est AP mode. Après la connexion, une notification vous informera qu’aucun accès Internet n’est disponible sur ce réseau Wi-Fi. Sélectionnez Continuer la connexion.

    .. image:: img/app_no_internet.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Créez un contrôleur.

    * Pour ajouter un contrôleur dans SunFounder Controller, cliquez sur l’icône **+**.

    .. image:: img/app1.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Certains produits disposent de contrôleurs prédéfinis. Ici, sélectionnez **Zeus Car**, donnez-lui un nom ou appuyez simplement sur **Confirm**.

    .. image:: img/app_preset.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

    * Une fois à l’intérieur, l’application recherchera automatiquement le Zeus Car. Après quelques secondes, un message "Connexion réussie" apparaîtra.

    .. image:: img/app_edit.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/> 

    * Maintenant, appuyez sur le bouton |app_run| pour afficher le flux vidéo en direct de la caméra et contrôler le véhicule à l'aide des widgets fournis. 

    .. image:: img/app_run123.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  

#. Fonctionnalités des widgets.

        * :ref:`app_compass_cali` : Active l’étalonnage du compas.
        * **Stop(F)** : Arrête tous les mouvements du véhicule.
        * **Reset Heading(G)** : Une fois la voiture orientée manuellement, cliquez sur ce widget pour enregistrer cette direction comme référence. Cela permet d’orienter rapidement la voiture sans avoir à la repositionner avec d’autres commandes.
        * :ref:`app_speech_control` : Active le mode de commande vocale.
        * :ref:`app_drift` : Active la fonction de drift.
        * :ref:`app_move` : Permet de déplacer la voiture dans toutes les directions.
        
        * :ref:`app_line_track` : Ces deux widgets permettent d’activer le mode suivi de ligne.
        
            * **Line no Mag(M)** : Active le suivi de ligne sans être influencé par le champ magnétique. L’orientation de la voiture changera continuellement.
            * **Line(N)** : Active le suivi de ligne avec alignement sur un champ magnétique, garantissant une orientation constante du véhicule.

        * :ref:`app_follow` : Active le mode suivi automatique.
        * :ref:`app_avoid` : Active le mode évitement d'obstacles.
        * :ref:`app_rotate_drift` : Permet de contrôler la direction de la tête du véhicule.

.. _app_compass_cali:

Calibration(E)
--------------------------

Activez l’étalonnage du compas en cliquant sur le bouton |app_cali_e|.

Placez le Zeus Car au sol. Une fois l’étalonnage activé, la voiture commencera à tourner dans le sens antihoraire et s’arrêtera au bout d’environ une minute. Si elle tourne pendant plus de deux minutes, cela signifie que le champ magnétique est trop complexe à cet endroit. Essayez de changer de lieu et relancez l’étalonnage.

.. _app_drift:

Drift Enable(J) 
---------------------


Cliquez sur le bouton |app_drift_j| pour activer la fonction de drift.

* En faisant glisser le widget |app_rotate_q| dans le sens antihoraire, vous verrez le Zeus Car drifter vers la droite. Lorsque vous relâchez, la voiture s’arrête à sa position actuelle.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
* De même, si vous faites glisser le widget |app_rotate_q| dans le sens horaire, le Zeus Car driftera vers la gauche et s’arrêtera à sa position actuelle.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
.. _app_move:

Move in All Directions(K)
----------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Le Zeus Car se déplacera dans la direction correspondante lorsque vous faites glisser le widget |app_move_k|.

.. image:: img/joystick_move.png
    :align: center

.. raw:: html
    
    <br/>  

Le véhicule effectue un déplacement à chaque fois que vous faites glisser le widget. Si vous maintenez votre doigt appuyé, la voiture continuera à se déplacer.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center


.. raw:: html
    
    <br/>  
 
.. _app_speech_control:

Speech(I)
-------------------

En appuyant sur le widget |app_speech_m|, vous activez la fonction STT (Speech to Text).

L’application SunFounder Controller s’intègre au moteur de reconnaissance vocale de votre appareil mobile. Ainsi, lorsque vous appuyez et maintenez le widget **Speech(I)** sur SunFounder Controller et que vous parlez dans votre appareil, celui-ci capture votre voix, la convertit en texte et l’envoie au Zeus Car. Si ce texte correspond aux commandes pré-enregistrées dans votre code, la voiture exécutera les actions correspondantes.

Voici les commandes actuellement pré-enregistrées dans le code. Prononcez l’une d’elles et observez la réaction du Zeus Car.

* ``stop`` : Arrête tous les mouvements du véhicule.
* ``pasue`` : Fonction similaire à Stop, mais si la tête du véhicule ne fait pas face à la direction initialement définie, elle s’ajustera lentement.
* ``forward``
* ``backward``
* ``left forward``
* ``left backward``
* ``right forward``
* ``right backward``
* ``move left``
* ``move right``

.. note::

    La fonction STT (Speech to Text) nécessite une connexion Internet et les services Google sur les appareils Android. Cependant, elle ne fonctionne pas avec le mode AP (Access Point) préconfiguré sur le Zeus Car.

    En mode AP, le Zeus Car crée un réseau Wi-Fi local auquel votre appareil mobile peut se connecter, mais qui ne fournit pas d’accès Internet.

    Pour utiliser la fonction STT sur Android, passez du mode AP au mode STA, comme expliqué dans :ref:`stt_android`.

.. note::

    Les appareils iOS, utilisant un moteur de reconnaissance vocale hors ligne, fonctionnent aussi bien en mode AP qu’en mode STA.

Une fois que la voiture reçoit l’une des huit commandes ci-dessus, elle continuera à se déplacer dans la direction correspondante jusqu’à ce qu’elle reçoive une commande ``stop`` ou ``pasue``.

.. image:: img/zeus_move.jpg
    :width: 500
    :align: center

* ``turn left`` : Cette commande fera tourner la voiture de 45° vers la gauche autour de son axe central, puis elle avancera ou s’arrêtera en fonction de son état précédent. Si elle était arrêtée, elle s’arrêtera après avoir tourné de 45° ; si elle avançait, elle poursuivra son mouvement après la rotation.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
* ``turn right`` : Cette commande fera tourner la voiture de 45° vers la droite autour de son axe central, puis elle avancera ou s’arrêtera en fonction de son état précédent.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>  
 
.. _app_line_track:

Line Track
--------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


Cliquez sur le widget |app_line_n| pour activer le mode suivi de ligne.

Deux modes de suivi de ligne sont disponibles sur le Zeus Car, l’un avec la tête toujours orientée dans la direction du déplacement et l’autre avec la tête dirigée vers une direction fixe. Ici, le second mode est sélectionné.


#. Collez une ligne de 3 cm de large

    Il y a huit capteurs sur le module Omni Grayscale, et la distance entre chaque capteur est comprise entre 2 et 3 cm. Au moins deux capteurs doivent détecter simultanément la ligne noire. Par conséquent, la ligne que vous collez doit avoir une largeur d’au moins 3 cm et un angle de courbure supérieur à 90°.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
 
#. Calibrez le module Omni Grayscale.

    Chaque surface de sol ayant des valeurs de gris différentes, le seuil de gris défini en usine peut ne pas être adapté à votre environnement actuel. Il est donc nécessaire de calibrer ce module avant utilisation. Il est recommandé d’effectuer une calibration chaque fois que la couleur du sol change considérablement.

    * Placez le Zeus Car sur une surface blanche et tournez le potentiomètre jusqu’à ce que le voyant du capteur de gris s’allume.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center
    

    .. raw:: html
        
        <br/>  
 
    * Placez ensuite les deux capteurs de gris latéraux juste entre la ligne noire et la surface blanche, et tournez lentement le potentiomètre jusqu’à ce que le voyant de signal s’éteigne.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
 
    * Déplacez le véhicule plusieurs fois sur la ligne noire et la surface blanche pour vérifier que les capteurs s’allument lorsqu’ils sont sur la surface blanche et s’éteignent lorsqu’ils sont entre la ligne noire et la surface blanche. Cela indique que le module est correctement calibré.


#. Placez le Zeus Car sur la ligne collée, cliquez sur le widget |app_line_n|, et il suivra la ligne.

#. En raison des exigences environnementales élevées du module Omni Grayscale, il est recommandé de calibrer plusieurs fois le capteur si le suivi n’est pas précis.

.. _app_follow:

Follow(O) 
------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Cliquez sur le widget |app_follow_o| pour activer le mode suivi.

Le capteur à ultrasons détecte les obstacles situés à 20 cm devant le véhicule et les suit en avançant. Ces deux modules d’évitement d’obstacles permettent au Zeus Car de suivre un objet vers la gauche ou vers la droite, mais ils doivent être calibrés à 15 cm avant utilisation.

#. Calibrer le module d’évitement d’obstacles infrarouge.

    * Commencez par ajuster le module de détection des obstacles droit. Lors du transport, des chocs peuvent incliner l’émetteur et le récepteur du module infrarouge. Vous devez donc les redresser manuellement.

        .. raw:: html

            <video loop autoplay muted style = "max-width:80%">
                <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>

        .. raw:: html
            
            <br/> <br/>  

    * Placez un obstacle à environ 15 cm du module d’évitement infrarouge.
    * Sur le module, il y a deux potentiomètres : l’un pour ajuster la puissance d’émission et l’autre pour régler la fréquence d’émission. En ajustant ces deux potentiomètres, vous pouvez modifier la distance de détection.
    * Ajustez un potentiomètre et si, à 15 cm, le voyant du module s’allume, l’ajustement est réussi ; sinon, ajustez l’autre potentiomètre.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 400
        :align: center

    .. raw:: html
        
        <br/>  
    
    * Calibrez l’autre module d’évitement d’obstacles de la même manière.

#. Placez le Zeus Car sur une table ou au sol et laissez-le suivre votre main ou d’autres objets.

.. _app_avoid:

Avoid(P)
------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Lorsque vous souhaitez activer le mode d’évitement d’obstacles, cliquez sur le widget |app_avoid_p|, mais référez-vous d’abord à :ref:`app_follow` pour calibrer les deux modules d’évitement d’obstacles.

* Le Zeus Car avance en ligne droite.
* Un module à ultrasons détecte les obstacles à l’avant. Si un obstacle est détecté, la voiture tourne à gauche.
* Lorsque le module d’évitement gauche détecte un obstacle, la voiture tourne à droite. Lorsque le module d’évitement droit détecte un obstacle, la voiture tourne à gauche.

.. _app_rotate_drift:

Control the Direction(Q)
-------------------------------

* Lorsque le bouton |app_drift_j| est activé, le widget |app_rotate_q| est utilisé pour faire drifter le Zeus Car vers la gauche et la droite.

* Lorsque le widget |app_drift_j| est désactivé, le widget |app_rotate_q| est utilisé pour contrôler l’orientation de la tête du véhicule.

    * En faisant glisser le widget |app_rotate_q| dans le sens antihoraire, la voiture tournera également dans le sens antihoraire. En relâchant le widget, la tête du véhicule reviendra à sa direction initiale.

    .. image:: img/zeus_turn_left.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  
    
    * De la même manière, en faisant glisser le widget |app_rotate_q| dans le sens horaire, la voiture tournera dans le sens horaire et reviendra à sa direction initiale lorsqu’elle sera relâchée.

    .. image:: img/zeus_turn_right.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>  