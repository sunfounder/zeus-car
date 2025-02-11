.. note::  

    Bonjour et bienvenue dans la communauté des passionnés de SunFounder Raspberry Pi, Arduino et ESP32 sur Facebook ! Plongez dans l’univers du Raspberry Pi, d’Arduino et de l’ESP32 avec d’autres passionnés.  

    **Pourquoi nous rejoindre ?**  

    - **Support d’experts** : Obtenez de l’aide pour résoudre vos problèmes après-vente et relevez vos défis techniques grâce à notre communauté et notre équipe.  
    - **Apprenez & partagez** : Échangez des conseils et tutoriels pour perfectionner vos compétences.  
    - **Aperçus exclusifs** : Bénéficiez d’un accès anticipé aux annonces de nouveaux produits et aux avant-premières exclusives.  
    - **Réductions spéciales** : Profitez d’offres exclusives sur nos derniers produits.  
    - **Promotions et cadeaux festifs** : Participez à des concours et à des offres spéciales à l’occasion des fêtes.  

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !  

.. _play_remote_control:  

Contrôle par Télécommande  
=============================

La Zeus Car peut être contrôlée via une télécommande en l’allumant, puis en appuyant directement sur les boutons. Cette méthode est stable et moins sujette aux interférences extérieures, mais elle offre un contrôle moins flexible.  

Guide rapide  
--------------------

Ce tutoriel vidéo vous montre comment utiliser rapidement la Zeus Car. Regardez d’abord la vidéo, puis suivez les instructions détaillées ci-dessous.  

.. raw:: html  

   <video loop controls style = "max-width:90%">  
      <source src="../_static/video/ir_control_quick_guide.mp4"  type="video/mp4">  
      Your browser does not support the video tag.
   </video>  

.. raw:: html  
    
    <br/> <br/>  

#. Démarrage de la Zeus Car  

    * Lors de la première utilisation ou si le câble de la batterie a été débranché, le Zeus Car Shield active son circuit de protection contre la décharge excessive.  
    * Vous devez alors brancher le câble Type-C pendant environ 5 secondes.  

    .. raw:: html  

        <div style="text-align: center;">  
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/activate_battery.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>  
        </div>  

    .. raw:: html  
        
        <br/>  

    * Si le voyant d’alimentation s’allume, cela signifie que la protection est désactivée. Vérifiez ensuite les indicateurs de batterie :  
        - Si les deux indicateurs de batterie sont éteints, continuez à charger la batterie via le câble Type-C.  

    .. image:: img/zeus_power.jpg  
        :width: 500  
        :align: center  

    .. raw:: html  
        
        <br/>  

    * Ensuite, basculez le petit interrupteur vers la droite pour établir la communication entre la voiture et l’**ESP32 CAM**. Puis, appuyez sur le bouton Reset pour redémarrer le programme. À ce moment-là, vous verrez les lumières sous le châssis passer du orange au bleu clair.  

    .. raw:: html  

        <div style="text-align: center;">  
            <video center loop autoplay muted style = "max-width:70%">
                <source src="../_static/video/re_run_code.mp4"  type="video/mp4">
                Your browser does not support the video tag.
            </video>  
        </div>  

    .. raw:: html  
        
        <br/>  

#. Utilisation de la télécommande 

    .. image:: img/remote_control.jpg  
        :width: 500  
        :align: center  

    .. raw:: html  
        
        <br/>  

    * **Stop** : Stoppe tous les mouvements de la voiture.  
    * :ref:`ir_compass_cali` : Active l’étalonnage de la boussole.  
    * :ref:`ir_line_track` : Active le mode suivi de ligne.  
    * :ref:`ir_follow` : Active le mode suivi d’objet.  
    * :ref:`ir_avoid` : Active le mode évitement d’obstacles.  
    * :ref:`drift` : Effectue un drift à gauche/droite.  
    * **Set Heading** : Oriente la voiture dans une direction spécifique et enregistre cette direction comme référence de déplacement.  
    * :ref:`rotate_left/right` : Fait pivoter la voiture vers la gauche/droite.  
    * :ref:`ir_move` : Permet de déplacer la voiture dans toutes les directions.  
    * **Pause** : Semblable à Arrêt, mais permet à la voiture de s’orienter progressivement vers sa direction initialement définie.  

.. _ir_compass_cali:  

Calibration de la Boussole
-----------------------------------

Activez l'étalonnage de la boussole en appuyant sur la touche |ir_mute|.

Placez la voiture Zeus au sol. Une fois l'étalonnage de la boussole activé, la voiture commencera à tourner dans le sens antihoraire et s'arrêtera au bout d'environ une minute. Si elle continue à tourner pendant plus de deux minutes, cela signifie que le champ magnétique à cet endroit est complexe. Essayez de changer d'emplacement et recommencez l'étalonnage.

.. _ir_line_track:

Suivi de Ligne
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/drift_based_line_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Appuyez sur la touche |ir_play| pour passer en mode suivi de ligne.

La voiture Zeus propose deux modes de suivi de ligne : l’un où l'avant du véhicule est toujours orienté dans la direction du déplacement et un autre où l'avant reste fixe dans une direction donnée. Ici, le second mode est sélectionné.

Avant de pouvoir suivre une ligne, vous devez calibrer le module Omni Grayscale et préparer la ligne, comme suit :

#. Coller une ligne de 3 cm de large

    Le module Omni Grayscale est équipé de huit capteurs, espacés de 2 à 3 cm. Deux capteurs doivent détecter la ligne noire simultanément. Par conséquent, la ligne collée doit avoir une largeur minimale de 3 cm et les virages ne doivent pas être inférieurs à un angle de 90°.

    .. image:: img/map.png
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

#. Calibrer le module Omni Grayscale.

    Chaque sol ayant des valeurs de gris différentes, le seuil de gris défini en usine peut ne pas être adapté à votre environnement actuel. Il est donc nécessaire de calibrer ce module avant utilisation. Il est recommandé de refaire la calibration à chaque changement important de couleur du sol.

    * Placez la voiture Zeus sur une surface blanche et ajustez le potentiomètre jusqu'à ce que la lumière du capteur de gris s’allume à peine.

    .. image:: img/zeus_line_calibration.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Ensuite, positionnez les deux capteurs de gris sur les côtés juste entre la ligne noire et la surface blanche, puis tournez lentement le potentiomètre jusqu'à ce que le voyant du signal s'éteigne.

    .. image:: img/zeus_line_calibration1.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Déplacez la voiture plusieurs fois entre la ligne noire et la surface blanche pour vérifier que les capteurs de gris s'éteignent lorsqu'ils se trouvent entre les deux et s'allument sur la surface blanche, indiquant ainsi une calibration réussie.

#. Placez la voiture Zeus sur la ligne collée, appuyez sur la touche |ir_play| et elle suivra la ligne.

#. En raison des exigences environnementales strictes du module Omni Grayscale, il est recommandé de refaire la calibration plusieurs fois si le suivi de ligne n'est pas satisfaisant (sortie de trajectoire).

.. _ir_follow:

Mode Suivi
---------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/object_following.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  


Appuyez sur la touche |ir_backward| pour activer le mode suivi.

Le capteur à ultrasons détecte les obstacles situés à l'avant (20 cm) et suit leur mouvement. Les deux modules d’évitement d’obstacles permettent à la voiture de suivre un objet vers la gauche ou la droite, mais ils doivent être calibrés (15 cm) avant utilisation.

#. Calibration du module d’évitement d’obstacles à infrarouge.

    * Commencez par ajuster le module d’évitement d’obstacles droit. Pendant le transport, des chocs peuvent incliner l’émetteur et le récepteur du module infrarouge. Il est donc nécessaire de les redresser manuellement.

            .. raw:: html

                <video loop autoplay muted style = "max-width:80%">
                    <source src="../_static/video/toggle_avoid.mp4"  type="video/mp4">
                    Your browser does not support the video tag.
                </video>

            .. raw:: html
                
                <br/> <br/>  

    * Placez un obstacle à environ 15 cm du module d’évitement d’obstacles IR.
    * Le module dispose de deux potentiomètres : l’un ajuste la puissance d’émission et l’autre la fréquence d’émission. En ajustant ces deux paramètres, vous pouvez modifier la distance de détection.
    * Réglez l'un des potentiomètres. Si, à 15 cm, le voyant du signal s'allume, l'ajustement est réussi. Sinon, ajustez l'autre potentiomètre.

    .. image:: img/zeus_ir_avoid.jpg
        :width: 500
        :align: center

    .. raw:: html
        
        <br/>

    * Calibrez l’autre module d’évitement d’obstacles de la même manière.

#. Placez la voiture Zeus sur une table ou au sol et laissez-la suivre votre main ou d'autres obstacles.

.. _ir_avoid:

Évitement d'Obstacles
--------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/obstacle_avoidance.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Pour activer le mode d’évitement d’obstacles, appuyez sur la touche |ir_forward|. Avant cela, référez-vous à :ref:`ir_follow` pour calibrer les deux modules d’évitement d’obstacles.

* La voiture Zeus avancera en ligne droite.
* Un module à ultrasons détecte les obstacles situés devant ; en cas de détection, la voiture tourne à gauche.
* Lorsque le module d’évitement d’obstacles gauche détecte un obstacle, la voiture tourne à droite ; lorsqu’il s’agit du module droit, elle tourne à gauche.

.. _drift:

Dérapage Gauche/Droite
-------------------------------------------------

Utilisez les touches |ir_minus| et |ir_plus| pour faire déraper la voiture à gauche ou à droite.

* En appuyant sur la touche |ir_minus|, la voiture dérapera vers la gauche.

.. image:: img/zeus_drift_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* En appuyant sur la touche |ir_plus|, la voiture dérapera vers la droite.

.. image:: img/zeus_drift_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* Si la voiture était à l'arrêt avant le dérapage, appuyer une fois sur |ir_minus| ou |ir_plus| entraînera un dérapage de 90° à gauche ou à droite.
* Si elle était en mouvement avant le dérapage, après avoir appuyé sur la touche, la voiture Zeus effectuera un dérapage de 90° à gauche ou à droite, puis poursuivra son mouvement latéral jusqu'à ce qu'une autre touche soit pressée.

.. _ir_move:

Déplacement dans Toutes les Directions (1 ~ 9)
--------------------------------------------------

.. raw:: html

   <video loop autoplay muted style = "max-width:80%">
      <source src="../_static/video/basic_movement.mp4"  type="video/mp4">
      Your browser does not support the video tag.
   </video>

.. raw:: html
    
    <br/> <br/>  

Utilisez les touches numériques 1 à 9 pour déplacer la voiture Zeus dans huit directions différentes.

.. image:: img/remote_control_move.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

.. _rotate_left/right:

Rotation Gauche/Droite (Cycle/Touche USD)
-----------------------------------------

* En appuyant une fois sur la touche |ir_return|, la voiture effectuera une rotation de 45° vers la gauche en prenant son châssis comme centre. Ensuite, elle avancera ou s'arrêtera en fonction de son état précédent. Si elle était à l'arrêt, elle s'immobilisera après la rotation de 45° ; si elle était en mouvement, elle continuera d'avancer après avoir tourné à gauche.

.. image:: img/zeus_turn_left.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

* De même, en appuyant une fois sur la touche |ir_usd|, la voiture effectuera une rotation de 45° vers la droite et continuera d’avancer ou de s’arrêter en fonction de son état précédent.

.. image:: img/zeus_turn_right.jpg
    :width: 500
    :align: center

.. raw:: html
    
    <br/>

