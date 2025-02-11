.. note:: 

    Bonjour et bienvenue dans la communauté SunFounder Raspberry Pi & Arduino & ESP32 sur Facebook ! Rejoignez des passionnés pour approfondir vos connaissances sur Raspberry Pi, Arduino et ESP32.

    **Pourquoi nous rejoindre ?**

    - **Support d’experts** : Obtenez de l’aide pour résoudre les problèmes après-vente et relever les défis techniques grâce à notre communauté et notre équipe.
    - **Apprenez & Partagez** : Échangez des astuces et tutoriels pour perfectionner vos compétences.
    - **Aperçus exclusifs** : Accédez en avant-première aux annonces de nouveaux produits et aux coulisses du développement.
    - **Remises spéciales** : Bénéficiez d’offres exclusives sur nos derniers produits.
    - **Promotions festives et cadeaux** : Participez à des concours et offres spéciales à l’occasion des fêtes.

    👉 Prêt à explorer et à créer avec nous ? Cliquez sur [|link_sf_facebook|] et rejoignez-nous dès aujourd’hui !

Zeus Car Shield
=========================

.. image:: img/zeus_car_shield.png
    :width: 500
    :align: center

Il s'agit d'une carte d'extension tout-en-un conçue par SunFounder pour Arduino, intégrant divers ports pour modules tels que moteur, barre lumineuse, évitement d’obstacles, capteur de gris, ESP32 CAM et module ultrasonique. Elle intègre également un récepteur IR HS0038B pour le contrôle à distance.

Cette carte d’extension dispose également d’un circuit de charge intégré, permettant de recharger une batterie via une interface PH2.0-5P, avec un temps de charge estimé à 130 minutes.


**Schéma des broches du Zeus Car Shield**

.. image:: img/zeus_car_shield_pinout.png

* Bouton de réinitialisation
    * Appuyez sur ce bouton pour réinitialiser le programme sur la carte Arduino.

* Port de charge
    * Une fois branché sur un port USB-C 5V/2A, il permet de charger la batterie en 130 minutes.

* :ref:`shield_battry_pin`: 
    * Entrée d'alimentation PH2.0-5P (6.6V~8.4V).
    * Alimente à la fois le Zeus Car Shield et la carte Arduino.

* Interrupteur d’alimentation
    * Faites glisser sur ON pour allumer le Zeus Car Shield.

* Récepteur IR
    * Récepteur infrarouge HS0038B, dont la broche de signal est connectée à la broche 2 de l'Arduino.

* :ref:`shield_grayscale_pin`
    * Potentiomètre de réglage du capteur de gris : permet d’ajuster la tension de référence du module Omni Grayscale.
    * Port du capteur de gris : utilisé pour connecter le module Omni Grayscale.

* Indicateurs
    * Indicateur de charge : s'allume en rouge lorsque la charge via USB-C est en cours.
    * Indicateur d'alimentation : s'allume en vert lorsque l'interrupteur est en position ON.
    * Indicateurs de batterie : deux voyants orange affichent différents niveaux de batterie. Ils clignotent pendant la charge et s’éteignent lorsque la batterie doit être rechargée.

* :ref:`shield_ultrasonic_pin`
    * Port de connexion pour le module ultrasonique, avec les broches Trig et Echo connectées à la broche 10 de l'Arduino.

* :ref:`shield_camera_pin`
    * Port pour carte adaptatrice de caméra.

* :ref:`shield_avoid_pin`
    * Port pour deux modules IR d’évitement d’obstacles, dont les broches de signal sont connectées aux Q0 et Q1 du 74HC165.

* :ref:`shield_strip_pin`
    * Port pour 2 bandes LED RGB, dont les trois broches sont respectivement connectées aux broches 12, 13 et 11.

* Interrupteur Run
   * Lors de l’utilisation de la caméra, ce commutateur doit être activé pour que l’**ESP32-CAM** puisse communiquer avec l’Arduino.

* :ref:`shield_motor_pin`
    * 4 groupes de ports moteur.


.. _shield_battry_pin:

Port de Batterie
------------------

Schéma des broches du port batterie (PH2.0-5P), avec une plage de tension d’entrée de 6.6V~8.4V.

.. image:: img/shield_battery_pin.png
    :width: 400
    :align: center

.. _shield_grayscale_pin:

Module Grayscale
-----------------------------

Un potentiomètre bleu sur le Zeus Car Shield permet d’ajuster la sensibilité du module Grayscale aux variations d’environnement en modifiant la tension de référence VREF.

.. image:: img/shield_grayscale_pin.png

Schéma de connexion : les données du module Grayscale sont transmises via le 74HC165 à la carte Arduino. Le module intègre déjà un 74HC165, et le chaînage de ces deux composants permet de transmettre 16 bits de données à l’Arduino : les 8 premiers bits correspondent aux capteurs de gris, et les 2 derniers aux capteurs IR d’évitement d’obstacles.

.. image:: img/shield_grayscale1.png
.. image:: img/shield_grayscale2.png
    :width: 400

Attribution des broches sur l’Arduino :

.. list-table::
    :widths: 25 50

    * - Carte Arduino
      - Zeus Car Shield
    * - 7
      - 74HC165 Q7
    * - 8
      - 74HC165 CP
    * - ~9
      - 74HC165 PL

.. _shield_ultrasonic_pin:

Port Ultrasonique
----------------------

Schéma des broches du port ZH1.5-4P pour le module ultrasonique, avec Trig & Echo connectés à la broche 10 de l’Arduino.

.. image:: img/shield_ultrasonic_pin.png

.. _shield_camera_pin:

Port Adaptateur Caméra
-------------------------

Schéma des broches du port adaptateur caméra (ZH1.5-7P).

* TX et RX : utilisés pour ESP32-CAM.
* SDA et SCL : utilisés pour QMC6310.

.. image:: img/shield_camera_pin.png

.. _shield_avoid_pin:

Port Évitement d'Obstacles
----------------------------

Schéma des broches des deux ports ZH1.5-3P pour les modules IR d’évitement d’obstacles.

.. image:: img/shield_avoid_pin.png

Schéma électrique : S1 et S0 correspondent à Q0 et Q1 du 74HC165. Les données des modules IR et du capteur de gris sont envoyées à l’Arduino via deux 74HC165 en cascade. Les 8 premiers bits sont les données des capteurs de gris, et les 2 derniers correspondent aux modules IR d’évitement d’obstacles.

.. image:: img/shield_avoid_sche.png
.. image:: img/shield_avoid_sche1.png

.. _shield_strip_pin:

Port Bande LED RGB
-------------------------

Schéma des broches des 2 bandes LED RGB, connectées en parallèle avec la même configuration de broches.

.. image:: img/shield_strip_pin.png

Schéma électrique :

.. image:: img/shield_strip_sche.png
.. image:: img/shield_strip_sche1.png

.. _shield_motor_pin:

Port Moteur
---------------

Schéma des 4 ports moteur.

.. image:: img/shield_motor_pin.png
    :width: 400
    :align: center

Ces 4 moteurs sont pilotés par 2 puces TC1508S, des pilotes de moteur double canal avec un courant de sortie continu maximal de 1.8A par canal.

Schéma électrique :

.. image:: img/shield_motor_sche.png

Attribution des broches sur l’**Arduino** :

.. list-table::
    :widths: 25 50

    * - Carte Arduino
      - Zeus Car Shield
    * - ~3
      - OUTA1
    * - 4
      - OUTB1
    * - ~5
      - OUTA2
    * - ~6
      - OUTB2
    * - A0
      - OUTB4
    * - A1
      - OUTA4
    * - A2
      - OUTB3
    * - A3
      - OUTA3




